/****************************************************************************
 *
 * Copyright 2017 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/fs_blockproxy.c
 *
 *   Copyright (C) 2015-2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <tinyara/config.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>

#if !defined(CONFIG_DISABLE_MOUNTPOINT) && \
	!defined(CONFIG_DISABLE_PSEUDOFS_OPERATIONS)

/****************************************************************************
 * Private Data
 ****************************************************************************/

static uint32_t g_devno;
static sem_t g_devno_sem = SEM_INITIALIZER(1);

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: unique_chardev
 *
 * Description:
 *   Create a unique temporary device name in the /dev/ directory of the
 *   psuedo-file system.  We cannot use mktemp for this because it will
 *   attempt to open() the file.
 *
 * Input parameters:
 *   None
 *
 * Returned Value:
 *   The allocated path to the device.  This must be released by the caller
 *   to prevent memory links.  NULL will be returned only the case where
 *   we fail to allocate memory.
 *
 ****************************************************************************/
static FAR char *unique_chardev(void)
{
	struct stat statbuf;
	char devbuf[16];
	uint32_t devno;
	int ret;

	/* Loop until we get a unique device name */
	for (; ; ) {
		/* Get the semaphore protecting the path number */
		while (sem_wait(&g_devno_sem) < 0) {
			DEBUGASSERT(errno == EINTR);
		}

		/* Get the next device number and release the semaphore */
		devno = ++g_devno;
		sem_post(&g_devno_sem);

		/* Construct the full device number */
		devno &= 0xffffff;
		snprintf(devbuf, 16, "/dev/tmp%06lx", (unsigned long)devno);

		/* Make sure that file name is not in use */
		ret = stat(devbuf, &statbuf);
		if (ret < 0) {
			DEBUGASSERT(errno == ENOENT);
			return strdup(devbuf);
		}

		/* It is in use, try again */
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: block_proxy
 *
 * Description:
 *   Create a temporary char driver using drivers/bch to mediate character
 *   oriented accessed to the block driver.
 *
 * Input parameters:
 *   blkdev - The path to the block driver
 *   oflags - Character driver open flags
 *
 * Returned Value:
 *   If positive, non-zero file descriptor is returned on success.  This
 *   is the file descriptor of the nameless character driver that mediates
 *   accesses to the block driver.
 *
 *   Errors that may be returned:
 *
 *     ENOMEM - Failed to create a temporay path name.
 *
 *   Plus:
 *
 *     - Errors reported from bchdev_register()
 *     - Errors reported from open() or unlink()
 *
 ****************************************************************************/
int block_proxy(FAR const char *blkdev, int oflags)
{
	FAR char *chardev;
	bool readonly;
	int ret;
	int fd;

	DEBUGASSERT(blkdev);
	DEBUGASSERT((oflags & (O_CREAT | O_EXCL | O_APPEND | O_TRUNC)) == 0);

	/* Create a unique temporary file name for the character device */
	chardev = unique_chardev();
	if (chardev == NULL) {
		fdbg("ERROR: Failed to create temporary device name\n");
		return -ENOMEM;
	}

	/* Should this character driver be read-only? */
	readonly = ((oflags & O_WROK) == 0);

	/* Wrap the block driver with an instance of the BCH driver */
	ret = bchdev_register(blkdev, chardev, readonly);
	if (ret < 0) {
		fdbg("ERROR: bchdev_register(%s, %s) failed: %d\n",
				blkdev, chardev, ret);

		goto errout_with_chardev;
	}

	/* Open the newly created character driver */
	oflags &= ~(O_CREAT | O_EXCL | O_APPEND | O_TRUNC);
	fd = open(chardev, oflags);
	if (fd < 0) {
		ret = -errno;
		fdbg("ERROR: Failed to open %s: %d\n", chardev, ret);
		goto errout_with_bchdev;
	}

	/*
	 * Unlink the character device name.  The driver instance will persist,
	 * provided that CONFIG_DISABLE_PSEUDOFS_OPERATIONS=y (otherwise, we have
	 * a problem here!)
	 */
	ret = unlink(chardev);
	if (ret < 0) {
		ret = -errno;
		fdbg("ERROR: Failed to unlink %s: %d\n", chardev, ret);
	}

	/*
	 * Free the allocate character driver name and return the open file
	 * descriptor.
	 */
	kmm_free(chardev);
	return fd;

errout_with_bchdev:
	(void)unlink(chardev);

errout_with_chardev:
	kmm_free(chardev);
	return ret;
}
#endif /* !CONFIG_DISABLE_MOUNTPOINT && !CONFIG_DISABLE_PSEUDOFS_OPERATIONS */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/block/fs_closeblockdriver.c
 *
 *   Copyright (C) 2008-2009 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in pathname and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of pathname code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <debug.h>
#include <errno.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: close_blockdriver
 *
 * Description:
 *   Call the close method and release the inode
 *
 * Inputs:
 *   inode - reference to the inode of a block driver opened by open_blockdriver
 *
 * Return:
 *   Returns zero on success or a negated errno on failure:
 *
 *   EINVAL  - inode is NULL
 *   ENOTBLK - The inode is not a block driver
 *
 ****************************************************************************/

int close_blockdriver(FAR struct inode *inode)
{
	int ret = 0;				/* Assume success */

	/* Sanity checks */

#ifdef CONFIG_DEBUG
	if (!inode || !inode->u.i_bops) {
		ret = -EINVAL;
		goto errout;
	}
#endif

	/* Verify that the inode is a block driver. */

	if (!INODE_IS_BLOCK(inode)) {
		fdbg("inode is not a block driver\n");
		ret = -ENOTBLK;
		goto errout;
	}

	/* Close the block driver.  Not that no mutually exclusive access
	 * to the driver is enforced here.  That must be done in the driver
	 * if needed.
	 */

	if (inode->u.i_bops->close) {
		ret = inode->u.i_bops->close(inode);
	}

	/* Then release the reference on the inode */

	inode_release(inode);

errout:
	return ret;
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/block/fs_devsyslog.c
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <errno.h>
#include <assert.h>

#include <tinyara/fs/fs.h>
#include <tinyara/arch.h>
#include <tinyara/syslog/syslog.h>

#include "inode/inode.h"

#if defined(CONFIG_SYSLOG) && defined(CONFIG_SYSLOG_CHAR)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Open the device/file write-only, try to create (file) it if it doesn't
 * exist, if the file that already exists, then append the new log data to
 * end of the file.
 */

#define SYSLOG_OFLAGS (O_WRONLY | O_CREAT | O_APPEND)

/* An invalid thread ID */

#define NO_HOLDER     ((pid_t)-1)

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This enumeration represents the state of the SYSLOG device interface */

enum syslog_state_e {
	SYSLOG_UNINITIALIZED = 0,	/* SYSLOG has not been initialized */
	SYSLOG_INITIALIZING,		/* SYSLOG is being initialized */
	SYSLOG_REOPEN,				/* SYSLOG open failed... try again later */
	SYSLOG_FAILURE,				/* SYSLOG open failed... don't try again */
	SYSLOG_OPENED,				/* SYSLOG device is open and ready to use */
};

/* This structure contains all SYSLOGing state information */

struct syslog_dev_s {
	uint8_t sl_state;			/* See enum syslog_state_e */
	sem_t sl_sem;				/* Enforces mutually exclusive access */
	pid_t sl_holder;			/* PID of the thread that holds the semaphore */
	struct file sl_file;		/* The syslog file structure */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This is the device structure for the console or syslogging function. */

static struct syslog_dev_s g_sysdev;
static const uint8_t g_syscrlf[2] = { '\r', '\n' };

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_takesem
 *
 * Description:
 *   Write to the syslog device
 *
 ****************************************************************************/

static inline int syslog_takesem(void)
{
	pid_t me = getpid();
	int ret;

	/* Does this thread already hold the semaphore?  That could happen if
	 * we wer called recursively, i.e., if the logic kicked off by
	 * syslog_write() where to generate more debug output.  Return an error
	 * in that case.
	 */

	if (g_sysdev.sl_holder == me) {
		/* Return an error (instead of deadlocking) */

		return -EWOULDBLOCK;
	}

	/* Either the semaphore is available or is currently held by another
	 * thread.  Wait for it to become available.
	 */

	ret = sem_wait(&g_sysdev.sl_sem);
	if (ret < 0) {
		return -get_errno();
	}

	/* We hold the semaphore.  We can safely mark ourself as the holder
	 * of the semaphore.
	 */

	g_sysdev.sl_holder = me;
	return OK;
}

/****************************************************************************
 * Name: syslog_givesem
 *
 * Description:
 *   Write to the syslog device
 *
 ****************************************************************************/

static inline void syslog_givesem(void)
{
#ifdef CONFIG_DEBUG
	pid_t me = getpid();
	DEBUGASSERT(g_sysdev.sl_holder == me);
#endif

	/* Relinquish the semaphore */

	g_sysdev.sl_holder = NO_HOLDER;
	sem_post(&g_sysdev.sl_sem);
}

/****************************************************************************
 * Name: syslog_write
 *
 * Description:
 *   Write to the syslog device
 *
 ****************************************************************************/

static inline ssize_t syslog_write(FAR const void *buf, size_t nbytes)
{
	FAR struct inode *inode;

	/* Let the driver perform the write */

	inode = g_sysdev.sl_file.f_inode;
	return inode->u.i_ops->write(&g_sysdev.sl_file, buf, nbytes);
}

/****************************************************************************
 * Name: syslog_flush
 *
 * Description:
 *   Flush any buffer data in the file system to media.
 *
 ****************************************************************************/

#ifndef CONFIG_DISABLE_MOUNTPOINT
static inline void syslog_flush(void)
{
	FAR struct inode *inode = g_sysdev.sl_file.f_inode;

	/* Is this a mountpoint? Does it support the sync method? */

	if (INODE_IS_MOUNTPT(inode) && inode->u.i_mops->sync) {
		/* Yes... synchronize to the stream */

		(void)inode->u.i_mops->sync(&g_sysdev.sl_file);
	}
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_initialize
 *
 * Description:
 *   Initialize to use the character device (or file) at
 *   CONFIG_SYSLOG_DEVPATH as the SYSLOG sink.
 *
 *   NOTE that this implementation excludes using a network connection as
 *   SYSLOG device.  That would be a good extension.
 *
 ****************************************************************************/

int syslog_initialize(void)
{
	FAR struct inode *inode;
	FAR const char *relpath = NULL;
	int ret;

	/* At this point, the only expected states are SYSLOG_UNINITIALIZED or
	 * SYSLOG_REOPEN..  Not SYSLOG_INITIALIZING, SYSLOG_FAILURE, SYSLOG_OPENED.
	 */

	DEBUGASSERT(g_sysdev.sl_state == SYSLOG_UNINITIALIZED || g_sysdev.sl_state == SYSLOG_REOPEN);

	g_sysdev.sl_state = SYSLOG_INITIALIZING;

	/* Try to open the device.
	 *
	 * Note that we cannot just call open.  The syslog device must work on all
	 * threads.  Open returns a file descriptor that is valid only for the
	 * task that opened the device (and its pthread children).  Instead, we
	 * essentially re-implement the guts of open() here so that we can get to
	 * the thread-independent structures of the inode.
	 */

	/* Get an inode for this file/device */

	inode = inode_find(CONFIG_SYSLOG_DEVPATH, &relpath);
	if (!inode) {
		/* The inode was not found.  In this case, we will attempt to re-open
		 * the device repeatedly.  The assumption is that the device path is
		 * valid but that the driver has not yet been registered.
		 */

		g_sysdev.sl_state = SYSLOG_REOPEN;
		return -ENOENT;
	}

	/* Verify that the inode is valid and either a character driver or a
	 * mountpoint.
	 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	if ((!INODE_IS_DRIVER(inode) && !INODE_IS_MOUNTPT(inode)))
#else
	if (!INODE_IS_DRIVER(inode))
#endif
	{
		ret = -ENXIO;
		goto errout_with_inode;
	}

	/* Make sure that the "entity" at this inode supports write access */

	if (!inode->u.i_ops || !inode->u.i_ops->write) {
		ret = -EACCES;
		goto errout_with_inode;
	}

	/* Initialize the file structure */

	g_sysdev.sl_file.f_oflags = SYSLOG_OFLAGS;
	g_sysdev.sl_file.f_pos = 0;
	g_sysdev.sl_file.f_inode = inode;

	/* Perform the low-level open operation. */

	ret = OK;
	if (inode->u.i_ops->open) {
		/* Is the inode a mountpoint? */

#ifndef CONFIG_DISABLE_MOUNTPOINT
		if (INODE_IS_MOUNTPT(inode)) {
			/* Yes.  Open the device write-only, try to create it if it
			 * doesn't exist, if the file that already exists, then append the
			 * new log data to end of the file.
			 */

			ret = inode->u.i_mops->open(&g_sysdev.sl_file, relpath, SYSLOG_OFLAGS, 0666);
		}

		/* No... then it must be a character driver in the TinyAra pseudo-
		 * file system.
		 */

		else
#endif
		{
			ret = inode->u.i_ops->open(&g_sysdev.sl_file);
		}
	}

	/* Was the file/device successfully opened? */

	if (ret < 0) {
		ret = -ret;
		goto errout_with_inode;
	}

	/* The SYSLOG device is open and ready for writing. */

	sem_init(&g_sysdev.sl_sem, 0, 1);
	g_sysdev.sl_holder = NO_HOLDER;
	g_sysdev.sl_state = SYSLOG_OPENED;
	return OK;

errout_with_inode:
	inode_release(inode);
	g_sysdev.sl_state = SYSLOG_FAILURE;
	return ret;
}

/****************************************************************************
 * Name: syslog_putc
 *
 * Description:
 *   This is the low-level system logging interface.  The debugging/syslogging
 *   interfaces are syslog() and lowsyslog().  The difference is is that
 *   the syslog() function writes to syslogging device (usually fd=1, stdout)
 *   whereas lowsyslog() uses a lower level interface that works from
 *   interrupt handlers.  This function is a a low-level interface used to
 *   implement lowsyslog().
 *
 ****************************************************************************/

int syslog_putc(int ch)
{
	ssize_t nbytes;
	uint8_t uch;
	int errcode;
	int ret;

	/* Ignore any output:
	 *
	 * (1) Before the SYSLOG device has been initialized.  This could happen
	 *     from debug output that occurs early in the boot sequence before
	 *     syslog_initialize() is called (SYSLOG_UNINITIALIZED).
	 * (2) While the device is being initialized.  The case could happen if
	 *     debug output is generated while syslog_initialize() executes
	 *     (SYSLOG_INITIALIZING).
	 * (3) While we are generating SYSLOG output.  The case could happen if
	 *     debug output is generated while syslog_putc() executes
	 *     (This case is actually handled inside of syslog_semtake()).
	 * (4) Any debug output generated from interrupt handlers.  A disadvantage
	 *     of using the generic character device for the SYSLOG is that it
	 *     cannot handle debug output generated from interrupt level handlers.
	 * (5) Any debug output generated from the IDLE loop.  The character
	 *     driver interface is blocking and the IDLE thread is not permitted
	 *     to block.
	 * (6) If an irrecoverable failure occurred during initialization.  In
	 *     this case, we won't ever bother to try again (ever).
	 *
	 * NOTE: That the third case is different.  It applies only to the thread
	 * that currently holds the sl_sem sempaphore.  Other threads should wait.
	 * that is why that case is handled in syslog_semtake().
	 */

	/* Cases (4) and (5) */

	if (up_interrupt_context() || getpid() == 0) {
		errcode = ENOSYS;
		goto errout_with_errcode;
	}

	/* We can save checks in the usual case:  That after the SYSLOG device
	 * has been successfully opened.
	 */

	if (g_sysdev.sl_state != SYSLOG_OPENED) {
		/* Case (1) and (2) */

		if (g_sysdev.sl_state == SYSLOG_UNINITIALIZED || g_sysdev.sl_state == SYSLOG_INITIALIZING) {
			errcode = EAGAIN;	/* Can't access the SYSLOG now... maybe next time? */
			goto errout_with_errcode;
		}

		/* Case (6) */

		if (g_sysdev.sl_state == SYSLOG_FAILURE) {
			errcode = ENXIO;	/* There is no SYSLOG device */
			goto errout_with_errcode;
		}

		/* syslog_initialize() is called as soon as enough of the operating
		 * system is in place to support the open operation... but it is
		 * possible that the SYSLOG device is not yet registered at that time.
		 * In this case, we know that the system is sufficiently initialized
		 * to support an attempt to re-open the SYSLOG device.
		 *
		 * NOTE that the scheduler is locked.  That is because we do not have
		 * fully initialized semaphore capability until the SYSLOG device is
		 * successfully initialized
		 */

		sched_lock();
		if (g_sysdev.sl_state == SYSLOG_REOPEN) {
			/* Try again to initialize the device.  We may do this repeatedly
			 * because the log device might be something that was not ready
			 * the first time that syslog_initializee() was called (such as a
			 * USB serial device that has not yet been connected or a file in
			 * an NFS mounted file system that has not yet been mounted).
			 */

			ret = syslog_initialize();
			if (ret < 0) {
				sched_unlock();
				errcode = -ret;
				goto errout_with_errcode;
			}
		}

		sched_unlock();
		DEBUGASSERT(g_sysdev.sl_state == SYSLOG_OPENED);
	}

	/* Ignore carriage returns */

	if (ch == '\r') {
		return ch;
	}

	/* The syslog device is ready for writing and we have something of
	 * value to write.
	 */

	ret = syslog_takesem();
	if (ret < 0) {
		/* We probably already hold the semaphore and were probably
		 * re-entered by the logic kicked off by syslog_write().
		 * We might also have been interrupted by a signal.  Either
		 * way, we are outta here.
		 */

		errcode = -ret;
		goto errout_with_errcode;
	}

	/* Pre-pend a newline with a carriage return. */

	if (ch == '\n') {
		/* Write the CR-LF sequence */

		nbytes = syslog_write(g_syscrlf, 2);

		/* Synchronize the file when each CR-LF is encountered (i.e.,
		 * implements line buffering always).
		 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
		if (nbytes > 0) {
			syslog_flush();
		}
#endif
	} else {
		/* Write the non-newline character (and don't flush) */

		uch = (uint8_t)ch;
		nbytes = syslog_write(&uch, 1);
	}

	syslog_givesem();

	/* Check if the write was successful.  If not, nbytes will be
	 * a negated errno value.
	 */

	if (nbytes < 0) {
		errcode = -ret;
		goto errout_with_errcode;
	}

	return ch;

errout_with_errcode:
	set_errno(errcode);
	return EOF;
}

#endif							/* CONFIG_SYSLOG && CONFIG_SYSLOG_CHAR */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/block/fs_openblockdriver.c
 *
 *   Copyright (C) 2008 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in pathname and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of pathname code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <sys/mount.h>
#include <debug.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "inode/inode.h"
#include "driver.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: find_blockdriver
 *
 * Description:
 *   Return the inode of the block driver specified by 'pathname'
 *
 * Inputs:
 *   pathname - the full path to the block driver to be located
 *   mountflags - if MS_RDONLY is not set, then driver must support write
 *     operations (see include/sys/mount.h)
 *   ppinode - address of the location to return the inode reference
 *
 * Return:
 *   Returns zero on success or a negated errno on failure:
 *
 *   EINVAL  - pathname or pinode is NULL
 *   ENOENT  - No block driver of this name is registered
 *   ENOTBLK - The inode associated with the pathname is not a block driver
 *   EACCESS - The MS_RDONLY option was not set but this driver does not
 *     support write access
 *
 ****************************************************************************/

int find_blockdriver(FAR const char *pathname, int mountflags, FAR struct inode **ppinode)
{
	FAR struct inode *inode;
	int ret = 0;				/* Assume success */

	/* Sanity checks */

#ifdef CONFIG_DEBUG
	if (!pathname || !ppinode) {
		ret = -EINVAL;
		goto errout;
	}
#endif

	/* Find the inode registered with this pathname */

	inode = inode_find(pathname, NULL);
	if (!inode) {
		fdbg("Failed to find %s\n", pathname);
		ret = -ENOENT;
		goto errout;
	}

	/* Verify that the inode is a block driver. */

	if (!INODE_IS_BLOCK(inode)) {
		fdbg("%s is not a block driver\n", pathname);
		ret = -ENOTBLK;
		goto errout_with_inode;
	}

	/* Make sure that the inode supports the requested access */

	if (!inode->u.i_bops || !inode->u.i_bops->read || (!inode->u.i_bops->write && (mountflags & MS_RDONLY) == 0)) {
		fdbg("%s does not support requested access\n", pathname);
		ret = -EACCES;
		goto errout_with_inode;
	}

	*ppinode = inode;
	return OK;

errout_with_inode:
	inode_release(inode);
errout:
	return ret;
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/block/fs_openblockdriver.c
 *
 *   Copyright (C) 2008-2009 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in pathname and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of pathname code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <debug.h>
#include <errno.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"
#include "driver.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: open_blockdriver
 *
 * Description:
 *   Return the inode of the block driver specified by 'pathname'
 *
 * Inputs:
 *   pathname - the full path to the block driver to be opened
 *   mountflags - if MS_RDONLY is not set, then driver must support write
 *     operations (see include/sys/mount.h)
 *   ppinode - address of the location to return the inode reference
 *
 * Return:
 *   Returns zero on success or a negated errno on failure:
 *
 *   EINVAL  - pathname or pinode is NULL
 *   ENOENT  - No block driver of this name is registered
 *   ENOTBLK - The inode associated with the pathname is not a block driver
 *   EACCESS - The MS_RDONLY option was not set but this driver does not
 *     support write access
 *
 ****************************************************************************/

int open_blockdriver(FAR const char *pathname, int mountflags, FAR struct inode **ppinode)
{
	FAR struct inode *inode;
	int ret;

	/* Minimal sanity checks */

#ifdef CONFIG_DEBUG
	if (!ppinode) {
		ret = -EINVAL;
		goto errout;
	}
#endif

	/* Find the inode associated with this block driver name.  find_blockdriver
	 * will perform all additional error checking.
	 */

	ret = find_blockdriver(pathname, mountflags, &inode);
	if (ret < 0) {
		fdbg("Failed to file %s block driver\n", pathname);
		goto errout;
	}

	/* Open the block driver.  Note that no mutually exclusive access
	 * to the driver is enforced here.  That must be done in the driver
	 * if needed.
	 */

	if (inode->u.i_bops->open) {
		ret = inode->u.i_bops->open(inode);
		if (ret < 0) {
			fdbg("%s driver open failed\n", pathname);
			goto errout_with_inode;
		}
	}

	*ppinode = inode;
	return OK;

errout_with_inode:
	inode_release(inode);
errout:
	return ret;
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/block/fs_registerblockdriver.c
 *
 *   Copyright (C) 2007-2009, 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "inode/inode.h"

#ifndef CONFIG_DISABLE_MOUNTPOINT

/****************************************************************************
 * Pre-processor oDefinitions
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: register_blockdriver
 *
 * Description:
 *   Register a block driver inode the pseudo file system.
 *
 * Input parameters:
 *   path - The path to the inode to create
 *   bops - The block driver operations structure
 *   mode - inmode priviledges (not used)
 *   priv - Private, user data that will be associated with the inode.
 *
 * Returned Value:
 *   Zero on success (with the inode point in 'inode'); A negated errno
 *   value is returned on a failure (all error values returned by
 *   inode_reserve):
 *
 *   EINVAL - 'path' is invalid for this operation
 *   EEXIST - An inode already exists at 'path'
 *   ENOMEM - Failed to allocate in-memory resources for the operation
 *
 ****************************************************************************/

int register_blockdriver(FAR const char *path, FAR const struct block_operations *bops, mode_t mode, FAR void *priv)
{
	FAR struct inode *node;
	int ret;

	/* Insert an inode for the device driver -- we need to hold the inode
	 * semaphore to prevent access to the tree while we this.  This is because
	 * we will have a momentarily bad true until we populate the inode with
	 * valid data.
	 */

	inode_semtake();
	ret = inode_reserve(path, &node);
	if (ret >= 0) {
		/* We have it, now populate it with block driver specific information. */

		INODE_SET_BLOCK(node);

		node->u.i_bops = bops;
#ifdef CONFIG_FILE_MODE
		node->i_mode = mode;
#endif
		node->i_private = priv;
		ret = OK;
	}

	inode_semgive();
	return ret;
}

#endif							/* !CONFIG_DISABLE_MOUNTPOINT */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/block/fs_registerdriver.c
 *
 *   Copyright (C) 2007-2009, 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: register_driver
 *
 * Description:
 *   Register a character driver inode the pseudo file system.
 *
 * Input parameters:
 *   path - The path to the inode to create
 *   fops - The file operations structure
 *   mode - inmode priviledges (not used)
 *   priv - Private, user data that will be associated with the inode.
 *
 * Returned Value:
 *   Zero on success (with the inode point in 'inode'); A negated errno
 *   value is returned on a failure (all error values returned by
 *   inode_reserve):
 *
 *   EINVAL - 'path' is invalid for this operation
 *   EEXIST - An inode already exists at 'path'
 *   ENOMEM - Failed to allocate in-memory resources for the operation
 *
 ****************************************************************************/

int register_driver(FAR const char *path, FAR const struct file_operations *fops, mode_t mode, FAR void *priv)
{
	FAR struct inode *node;
	int ret;

	/* Insert a dummy node -- we need to hold the inode semaphore because we
	 * will have a momentarily bad structure.
	 */

	inode_semtake();
	ret = inode_reserve(path, &node);
	if (ret >= 0) {
		/* We have it, now populate it with driver specific information. */

		INODE_SET_DRIVER(node);

		node->u.i_ops = fops;
#ifdef CONFIG_FILE_MODE
		node->i_mode = mode;
#endif
		node->i_private = priv;
		ret = OK;
	}

	inode_semgive();
	return ret;
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/block/fs_unregisterblockdriver.c
 *
 *   Copyright (C) 2007-2009 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: unregister_blockdriver
 *
 * Description:
 *   Remove the block driver inode at 'path' from the pseudo-file system
 *
 ****************************************************************************/

int unregister_blockdriver(const char *path)
{
	int ret;

	inode_semtake();
	ret = inode_remove(path);
	inode_semgive();
	return ret;
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * fs/driver/block/fs_unregisterdriver.c
 *
 *   Copyright (C) 2007-2009, 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: unregister_driver
 *
 * Description:
 *   Remove the character driver inode at 'path' from the pseudo-file system
 *
 ****************************************************************************/

int unregister_driver(FAR const char *path)
{
	int ret;

	inode_semtake();
	ret = inode_remove(path);
	inode_semgive();
	return ret;
}
