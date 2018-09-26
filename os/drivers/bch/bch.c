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
 * drivers/bch/bchdev_driver.c
 *
 *   Copyright (C) 2008-2009, 2014-2016 Gregory Nutt. All rights reserved.
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
#include <sys/ioctl.h>

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sched.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/fs/fs.h>
#include <tinyara/fs/ioctl.h>

#include "bch.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/
static int     bch_open(FAR struct file *filep);
static int     bch_close(FAR struct file *filep);
static off_t   bch_seek(FAR struct file *filep, off_t offset, int whence);
static ssize_t bch_read(FAR struct file *filep, FAR char *buffer,
						size_t buflen);
static ssize_t bch_write(FAR struct file *filep, FAR const char *buffer,
						 size_t buflen);
static int     bch_ioctl(FAR struct file *filep, int cmd,
						 unsigned long arg);
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
static int     bch_unlink(FAR struct inode *inode);
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/
const struct file_operations bch_fops = {
	bch_open,	/* open */
	bch_close,	/* close */
	bch_read,	/* read */
	bch_write,	/* write */
	bch_seek,	/* seek */
	bch_ioctl,	/* ioctl */
#ifndef CONFIG_DISABLE_POLL
	0,			/* poll */
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
	bch_unlink,	/* unlink */
#endif
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/
/****************************************************************************
 * Name: bch_open
 *
 * Description: Open the block device
 *
 ****************************************************************************/
static int bch_open(FAR struct file *filep)
{
	FAR struct inode *inode = filep->f_inode;
	FAR struct bchlib_s *bch;

	DEBUGASSERT(inode && inode->i_private);
	bch = (FAR struct bchlib_s *)inode->i_private;

	/* Increment the reference count */

	bchlib_semtake(bch);
	if (bch->refs == MAX_OPENCNT) {
		return -EMFILE;
	} else {
		bch->refs++;
	}

	bchlib_semgive(bch);
	return OK;
}

/****************************************************************************
 * Name: bch_close
 *
 * Description: close the block device
 *
 ****************************************************************************/
static int bch_close(FAR struct file *filep)
{
	FAR struct inode *inode = filep->f_inode;
	FAR struct bchlib_s *bch;
	int ret = OK;

	DEBUGASSERT(inode && inode->i_private);
	bch = (FAR struct bchlib_s *)inode->i_private;

	/* Flush any dirty pages remaining in the cache */
	bchlib_semtake(bch);
	(void)bchlib_flushsector(bch);

	/*
	 * Decrement the reference count (I don't use bchlib_decref() because I
	 * want the entire close operation to be atomic wrt other driver
	 * operations.
	 */
	if (bch->refs == 0) {
		ret = -EIO;
	} else {
		bch->refs--;

		/*
		 * If the reference count decremented to zero AND if the character
		 * driver has been unlinked, then teardown the BCH device now.
		 */
		if (bch->refs == 0 && bch->unlinked) {
			/* Tear the driver down now. */
			ret = bchlib_teardown((FAR void *)bch);

			/*
			 * bchlib_teardown() would only fail if there are outstanding
			 * references on the device.  Since we know that is not true, it
			 * should not fail at all.
			 */
			DEBUGASSERT(ret >= 0);
			if (ret >= 0) {
				/* Return without releasing the stale semaphore */
				return OK;
			}
		}
	}

	bchlib_semgive(bch);
	return ret;
}

/****************************************************************************
 * Name: bch_seek
 ****************************************************************************/
static off_t bch_seek(FAR struct file *filep, off_t offset, int whence)
{
	FAR struct inode *inode = filep->f_inode;
	FAR struct bchlib_s *bch;
	off_t newpos;
	int ret;

	DEBUGASSERT(inode && inode->i_private);

	bch = (FAR struct bchlib_s *)inode->i_private;
	bchlib_semtake(bch);

	/* Determine the new, requested file position */
	switch (whence) {
	case SEEK_CUR:
		newpos = filep->f_pos + offset;
		break;

	case SEEK_SET:
		newpos = offset;
		break;

	case SEEK_END:
		newpos = bch->sectsize * bch->nsectors + offset;
		break;

	default:
		/* Return EINVAL if the whence argument is invalid */
		bchlib_semgive(bch);
		return -EINVAL;
	}

	/*
	 * Opengroup.org:
	 *
	 *  "The lseek() function shall allow the file offset to be set beyond the
	 *  end of the existing data in the file. If data is later written at this
	 *  point, subsequent reads of data in the gap shall return bytes with the
	 *  value 0 until data is actually written into the gap."
	 *
	 * We can conform to the first part, but not the second. But return EINVAL
	 * if
	 *
	 *  "...the resulting file offset would be negative for a regular file,
	 *  block special file, or directory."
	 */
	if (newpos >= 0) {
		filep->f_pos = newpos;
		ret = newpos;
	} else {
		ret = -EINVAL;
	}

	bchlib_semgive(bch);
	return ret;
}

/****************************************************************************
 * Name: bch_read
 ****************************************************************************/
static ssize_t bch_read(FAR struct file *filep, FAR char *buffer, size_t len)
{
	FAR struct inode *inode = filep->f_inode;
	FAR struct bchlib_s *bch;
	int ret;

	DEBUGASSERT(inode && inode->i_private);
	bch = (FAR struct bchlib_s *)inode->i_private;

	bchlib_semtake(bch);
	ret = bchlib_read(bch, buffer, filep->f_pos, len);
	if (ret > 0) {
		filep->f_pos += len;
	}

	bchlib_semgive(bch);
	return ret;
}

/****************************************************************************
 * Name:bch_write
 ****************************************************************************/
static ssize_t bch_write(FAR struct file *filep, FAR const char *buffer, size_t len)
{
	FAR struct inode *inode = filep->f_inode;
	FAR struct bchlib_s *bch;
	int ret = -EACCES;

	DEBUGASSERT(inode && inode->i_private);
	bch = (FAR struct bchlib_s *)inode->i_private;

	if (!bch->readonly) {
		bchlib_semtake(bch);
		ret = bchlib_write(bch, buffer, filep->f_pos, len);
		if (ret > 0) {
			filep->f_pos += len;
		}

		bchlib_semgive(bch);
	}

	return ret;
}

/****************************************************************************
 * Name: bch_ioctl
 *
 * Description: Return device geometry
 *
 ****************************************************************************/
static int bch_ioctl(FAR struct file *filep, int cmd, unsigned long arg)
{
	FAR struct inode *inode = filep->f_inode;
	FAR struct bchlib_s *bch;
	int ret = -ENOTTY;

	DEBUGASSERT(inode && inode->i_private);
	bch = (FAR struct bchlib_s *)inode->i_private;

	/* Is this a request to get the private data structure */
	if (cmd == DIOC_GETPRIV) {
		FAR struct bchlib_s **bchr = (FAR struct bchlib_s **)((uintptr_t)arg);

		bchlib_semtake(bch);
		if (!bchr || bch->refs == MAX_OPENCNT) {
			ret = -EINVAL;
		} else {
			bch->refs++;
			*bchr = bch;
			ret = OK;
		}

		bchlib_semgive(bch);
	}
#ifdef CONFIG_BCH_ENCRYPTION
	/* Is this a request to set the encryption key? */
	else if (cmd == DIOC_SETKEY) {
			memcpy(bch->key, (FAR void *)arg, CONFIG_BCH_ENCRYPTION_KEY_SIZE);
			ret = OK;
	}
#endif
	/* Otherwise, pass the IOCTL command on to the contained block driver */
	else {
		FAR struct inode *bchinode = bch->inode;

		/* Does the block driver support the ioctl method? */
		if (bchinode->u.i_bops->ioctl != NULL) {
			ret = bchinode->u.i_bops->ioctl(bchinode, cmd, arg);
		}
	}

	return ret;
}

/****************************************************************************
 * Name: bch_unlink
 *
 * Handle unlinking of the BCH device
 *
 ****************************************************************************/
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
static int bch_unlink(FAR struct inode *inode)
{
	FAR struct bchlib_s *bch;
	int ret = OK;

	DEBUGASSERT(inode && inode->i_private);
	bch = (FAR struct bchlib_s *)inode->i_private;

	/* Get exclusive access to the BCH device */
	bchlib_semtake(bch);

	/* Indicate that the driver has been unlinked */
	bch->unlinked = true;

	/*
	 * If there are no open references to the drvier then teardown the BCH
	 * device now.
	 */
	if (bch->refs == 0) {
		/* Tear the driver down now. */
		ret = bchlib_teardown((FAR void *)bch);

		/*
		 * bchlib_teardown() would only fail if there are outstanding
		 * references on the device.  Since we know that is not true, it
		 * should not fail at all.
		 */
		DEBUGASSERT(ret >= 0);
		if (ret >= 0) {
			/* Return without releasing the stale semaphore */
			return OK;
		}
	}

	bchlib_semgive(bch);
	return ret;
}
#endif
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
 * drivers/bch/bchdev_register.c
 *
 *   Copyright (C) 2008-2009, 2012, 2016 Gregory Nutt. All rights reserved.
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

#include <stdbool.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/fs/fs.h>

#include "bch.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: bchdev_register
 *
 * Description:
 *   Setup so that it exports the block driver referenced by 'blkdev' as a
 *   character device 'chardev'
 *
 ****************************************************************************/
int bchdev_register(FAR const char *blkdev, FAR const char *chardev, bool readonly)
{
	FAR void *handle;
	int ret;

	/* Setup the BCH lib functions */
	ret = bchlib_setup(blkdev, readonly, &handle);
	if (ret < 0) {
		fdbg("ERROR: bchlib_setup failed: %d\n", -ret);
		return ret;
	}

	/* Then setup the character device */
	ret = register_driver(chardev, &bch_fops, 0666, handle);
	if (ret < 0) {
		fdbg("ERROR: register_driver failed: %d\n", -ret);
		bchlib_teardown(handle);
		handle = NULL;
	}

	return ret;
}
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
 * drivers/bch/bchdev_unregister.c
 *
 *   Copyright (C) 2008-2009, 2012, 2016 Gregory Nutt. All rights reserved.
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

#include <sys/stat.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <fcntl.h>
#include <sched.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/fs/fs.h>
#include <tinyara/fs/ioctl.h>

#include "bch.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: bchdev_unregister
 *
 * Description:
 *   Unregister character driver access to a block device that was created
 *   by a previous call to bchdev_register().
 *
 ****************************************************************************/
int bchdev_unregister(FAR const char *chardev)
{
	FAR struct bchlib_s *bch;
	int fd;
	int ret;

	/* Sanity check */
#ifdef CONFIG_DEBUG_FEATURES
	if (!chardev) {
		return -EINVAL;
	}
#endif

	/* Open the character driver associated with chardev */
	fd = open(chardev, O_RDONLY);
	if (fd < 0) {
		fdbg("ERROR: Failed to open %s: %d\n", chardev, errno);
		return -errno;
	}

	/*
	 * Get a reference to the internal data structure.  On success, we
	 * will hold a reference count on the state structure.
	 */
	ret = ioctl(fd, DIOC_GETPRIV, (unsigned long)((uintptr_t)&bch));
	(void)close(fd);

	if (ret < 0) {
		fdbg("ERROR: ioctl failed: %d\n", errno);
		return -errno;
	}

	/*
	 * Lock out context switches.  If there are no other references
	 * and no context switches, then we can assume that we can safely
	 * teardown the driver.
	 */
	sched_lock();

	/* Check if the internal structure is non-busy (we hold one reference). */
	if (bch->refs > 1) {
		ret = -EBUSY;
		goto errout_with_lock;
	}

	/*
	 * Unregister the driver (this cannot suspend or we lose our non-preemptive
	 * state!).  Once the driver is successfully unregistered, we can assume
	 * we have exclusive access to the state instance.
	 */
	ret = unregister_driver(chardev);
	if (ret < 0) {
		goto errout_with_lock;
	}

	sched_unlock();

	/* Release the internal structure */
	bch->refs = 0;
	return bchlib_teardown(bch);

errout_with_lock:
	bch->refs--;
	sched_unlock();
	return ret;
}
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
 * drivers/bch/bchlib_cache.c
 *
 *   Copyright (C) 2008-2009, 2014, 2016 Gregory Nutt. All rights reserved.
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
#include <stdbool.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include "bch.h"

#if defined(CONFIG_BCH_ENCRYPTION)
#  include <crypto/crypto.h>
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bch_xor
 ****************************************************************************/
#if defined(CONFIG_BCH_ENCRYPTION)
static void bch_xor(uint32_t *R, uint32_t *A, uint32_t *B)
{
	R[0] = A[0] ^ B[0];
	R[1] = A[1] ^ B[1];
	R[2] = A[2] ^ B[2];
	R[3] = A[3] ^ B[3];
}
#endif

/****************************************************************************
 * Name: bch_cypher
 ****************************************************************************/
#if defined(CONFIG_BCH_ENCRYPTION)
static int bch_cypher(FAR struct bchlib_s *bch, int encrypt)
{
	int blocks = bch->sectsize / 16;
	FAR uint32_t *buffer = (FAR uint32_t *)bch->buffer;
	int i;

	for (i = 0; i < blocks; i++, buffer += 16 / sizeof(uint32_t)) {
		uint32_t T[4];
		uint32_t X[4] = {
			bch->sector, 0, 0, i
		};

		aes_cypher(X, X, 16, NULL, bch->key, CONFIG_BCH_ENCRYPTION_KEY_SIZE,
						AES_MODE_ECB, CYPHER_ENCRYPT);

		/* Xor-Encrypt-Xor */
		bch_xor(T, X, buffer);
		aes_cypher(T, T, 16, NULL, bch->key, CONFIG_BCH_ENCRYPTION_KEY_SIZE,
						AES_MODE_ECB, encrypt);
		bch_xor(buffer, X, T);
	}

	return OK;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: bchlib_flushsector
 *
 * Description:
 *   Flush the current contents of the sector buffer (if dirty)
 *
 * Assumptions:
 *   Caller must assume mutual exclusion
 *
 ****************************************************************************/
int bchlib_flushsector(FAR struct bchlib_s *bch)
{
	FAR struct inode *inode;
	ssize_t ret = OK;

	/*
	 * Check if the sector has been modified and is out of synch with the
	 * media.
	 */
	if (bch->dirty) {
		inode = bch->inode;

#if defined(CONFIG_BCH_ENCRYPTION)
		/* Encrypt data as necessary */
		bch_cypher(bch, CYPHER_ENCRYPT);
#endif

		/* Write the sector to the media */
		ret = inode->u.i_bops->write(inode, bch->buffer, bch->sector, 1);
		if (ret < 0) {
			fdbg("Write failed: %d\n");
		}

#if defined(CONFIG_BCH_ENCRYPTION)
		/*
		 * Computation overhead to save memory for extra sector buffer
		 * TODO: Add configuration switch for extra sector buffer
		 */
		bch_cypher(bch, CYPHER_DECRYPT);
#endif

		/* The sector is now in sync with the media */
		bch->dirty = false;
	}

	return (int)ret;
}

/****************************************************************************
 * Name: bchlib_readsector
 *
 * Description:
 *   Flush the current contents of the sector buffer (if dirty)
 *
 * Assumptions:
 *   Caller must assume mutual exclusion
 *
 ****************************************************************************/
int bchlib_readsector(FAR struct bchlib_s *bch, size_t sector)
{
	FAR struct inode *inode;
	ssize_t ret = OK;

	if (bch->sector != sector) {
		inode = bch->inode;

		(void)bchlib_flushsector(bch);
		bch->sector = (size_t)-1;

		ret = inode->u.i_bops->read(inode, bch->buffer, sector, 1);
		if (ret < 0) {
			fdbg("Read failed: %d\n");
		}
		bch->sector = sector;
#if defined(CONFIG_BCH_ENCRYPTION)
		bch_cypher(bch, CYPHER_DECRYPT);
#endif
	}
	return (int)ret;
}

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
 * drivers/bch/bchlib_read.c
 *
 *   Copyright (C) 2008-2009, 2016 Gregory Nutt. All rights reserved.
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
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include "bch.h"

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bchlib_read
 *
 * Description:
 *   Read from the block device set-up by bchlib_setup as if it were a
 *   character device.
 *
 ****************************************************************************/
ssize_t bchlib_read(FAR void *handle, FAR char *buffer, size_t offset, size_t len)
{
	FAR struct bchlib_s *bch = (FAR struct bchlib_s *)handle;
	size_t		nsectors;
	size_t		sector;
	uint16_t	sectoffset;
	size_t		nbytes;
	size_t		bytesread;
	int			ret;

	/* Get rid of this special case right away */
	if (len < 1) {
		return 0;
	}

	/* Convert the file position into a sector number an offset. */
	sector     = offset / bch->sectsize;
	sectoffset = offset - sector * bch->sectsize;

	if (sector >= bch->nsectors) {
		/* Return end-of-file */
		return 0;
	}

	/* Read the initial partial sector */

	bytesread = 0;
	if (sectoffset > 0) {
		/* Read the sector into the sector buffer */
		bchlib_readsector(bch, sector);

		/* Copy the tail end of the sector to the user buffer */
		if (sectoffset + len > bch->sectsize) {
			nbytes = bch->sectsize - sectoffset;
		} else {
			nbytes = len;
		}

		memcpy(buffer, &bch->buffer[sectoffset], nbytes);

		/* Adjust pointers and counts */
		sector++;

		if (sector >= bch->nsectors) {
			return nbytes;
		}

		bytesread  = nbytes;
		buffer    += nbytes;
		len       -= nbytes;
	}

	/*
	 * Then read all of the full sectors following the partial sector directly
	 * into the user buffer.
	 */
	if (len >= bch->sectsize) {
		nsectors = len / bch->sectsize;
		if (sector + nsectors > bch->nsectors) {
			nsectors = bch->nsectors - sector;
		}

		ret = bch->inode->u.i_bops->read(bch->inode, (FAR uint8_t *)buffer,
						sector, nsectors);
		if (ret < 0) {
			fdbg("ERROR: Read failed: %d\n");
			return ret;
		}

		/* Adjust pointers and counts */
		sector    += nsectors;
		nbytes     = nsectors * bch->sectsize;
		bytesread += nbytes;

		if (sector >= bch->nsectors) {
			return bytesread;
		}

		buffer    += nbytes;
		len       -= nbytes;
	}

	/* Then read any partial final sector */
	if (len > 0) {
		/* Read the sector into the sector buffer */
		bchlib_readsector(bch, sector);

		/* Copy the head end of the sector to the user buffer */
		memcpy(buffer, bch->buffer, len);

		/* Adjust counts */
		bytesread += len;
	}

	return bytesread;
}
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
 * drivers/bch/bchlib_sem.c
 *
 *   Copyright (C) 2008-2009 Gregory Nutt. All rights reserved.
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

#include <errno.h>
#include <assert.h>
#include <debug.h>

#include "bch.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bch_semtake
 ****************************************************************************/
void bchlib_semtake(FAR struct bchlib_s *bch)
{
	/* Take the semaphore (perhaps waiting) */
	while (sem_wait(&bch->sem) != 0) {
		/*
		 * The only case that an error should occur here is if
		 * the wait was awakened by a signal.
		 */
		ASSERT(errno == EINTR);
	}
}
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
 * drivers/bch/bchlib_setup.c
 *
 *   Copyright (C) 2008-2009, 2011, 2016 Gregory Nutt. All rights reserved.
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
#include <sys/mount.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>

#include "bch.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bchlib_setup
 *
 * Description:
 *   Setup so that the block driver referenced by 'blkdev' can be accessed
 *   similar to a character device.
 *
 ****************************************************************************/
int bchlib_setup(const char *blkdev, bool readonly, FAR void **handle)
{
	FAR struct bchlib_s *bch;
	struct geometry geo;
	int ret;

	DEBUGASSERT(blkdev);

	/* Allocate the BCH state structure */
	bch = (FAR struct bchlib_s *)kmm_zalloc(sizeof(struct bchlib_s));
	if (!bch) {
		fdbg("ERROR: Failed to allocate BCH structure\n");
		return -ENOMEM;
	}

	/* Open the block driver */
	ret = open_blockdriver(blkdev, readonly ? MS_RDONLY : 0, &bch->inode);
	if (ret < 0) {
		fdbg("ERROR: Failed to open driver %s: %d\n", blkdev, -ret);
		goto errout_with_bch;
	}

	DEBUGASSERT(bch->inode && bch->inode->u.i_bops && bch->inode->u.i_bops->geometry);

	ret = bch->inode->u.i_bops->geometry(bch->inode, &geo);
	if (ret < 0) {
		fdbg("ERROR: geometry failed: %d\n", -ret);
		goto errout_with_bch;
	}

	if (!geo.geo_available) {
		fdbg("ERROR: geometry failed: %d\n", -ret);
		ret = -ENODEV;
		goto errout_with_bch;
	}

	if (!readonly && (!bch->inode->u.i_bops->write || !geo.geo_writeenabled)) {
		fdbg("ERROR: write access not supported\n");
		ret = -EACCES;
		goto errout_with_bch;
	}

	/* Save the geometry info and complete initialization of the structure */
	sem_init(&bch->sem, 0, 1);
	bch->nsectors = geo.geo_nsectors;
	bch->sectsize = geo.geo_sectorsize;
	bch->sector   = (size_t)-1;
	bch->readonly = readonly;

	/* Allocate the sector I/O buffer */
	bch->buffer = (FAR uint8_t *)kmm_malloc(bch->sectsize);
	if (!bch->buffer) {
		fdbg("ERROR: Failed to allocate sector buffer\n");
		ret = -ENOMEM;
		goto errout_with_bch;
	}

	*handle = bch;
	return OK;

errout_with_bch:
	kmm_free(bch);
	return ret;
}
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
 * drivers/bch/bchlib_teardown.c
 *
 *   Copyright (C) 2008-2009, 2011, 2016 Gregory Nutt. All rights reserved.
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

#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>

#include "bch.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: bchlib_teardown
 *
 * Description:
 *   Setup so that the block driver referenced by 'blkdev' can be accessed
 *   similar to a character device.
 *
 ****************************************************************************/
int bchlib_teardown(FAR void *handle)
{
	FAR struct bchlib_s *bch = (FAR struct bchlib_s *)handle;

	DEBUGASSERT(handle);

	/* Check that there are not outstanding reference counts on the object */
	if (bch->refs > 0) {
		return -EBUSY;
	}

	/* Flush any pending data to the block driver */
	bchlib_flushsector(bch);

	/* Close the block driver */
	(void)close_blockdriver(bch->inode);

	/* Free the BCH state structure */
	if (bch->buffer) {
		kmm_free(bch->buffer);
	}

	sem_destroy(&bch->sem);
	kmm_free(bch);
	return OK;
}

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
 * drivers/bch/bchlib_write.c
 *
 *   Copyright (C) 2008-2009, 2011, 2016 Gregory Nutt. All rights reserved.
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
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/fs/fs.h>

#include "bch.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bchlib_write
 *
 * Description:
 *   Write to the block device set-up by bchlib_setup as if it were a
 *   character device.
 *
 ****************************************************************************/
ssize_t bchlib_write(FAR void *handle, FAR const char *buffer, size_t offset, size_t len)
{
	FAR struct bchlib_s *bch = (FAR struct bchlib_s *)handle;
	size_t   nsectors;
	size_t   sector;
	uint16_t sectoffset;
	size_t   nbytes;
	size_t   byteswritten;
	int      ret;

	/* Get rid of this special case right away */
	if (len < 1) {
		return 0;
	}

	/* Convert the file position into a sector number and offset. */
	sector     = offset / bch->sectsize;
	sectoffset = offset - sector * bch->sectsize;

	if (sector >= bch->nsectors) {
		return -EFBIG;
	}

	/* Write the initial partial sector */

	byteswritten = 0;
	if (sectoffset > 0) {
		/* Read the full sector into the sector buffer */
		bchlib_readsector(bch, sector);

		/* Copy the tail end of the sector from the user buffer */
		if (sectoffset + len > bch->sectsize) {
			nbytes = bch->sectsize - sectoffset;
		} else {
			nbytes = len;
		}

		memcpy(&bch->buffer[sectoffset], buffer, nbytes);
		bch->dirty = true;

		/* Adjust pointers and counts */
		sector++;

		if (sector >= bch->nsectors) {
			return nbytes;
		}

		byteswritten  = nbytes;
		buffer       += nbytes;
		len          -= nbytes;
	}

	/*
	 * Then write all of the full sectors following the partial sector
	 * directly from the user buffer.
	 */
	if (len >= bch->sectsize) {
		nsectors = len / bch->sectsize;
		if (sector + nsectors > bch->nsectors) {
			nsectors = bch->nsectors - sector;
		}

		/* Write the contiguous sectors */
		ret = bch->inode->u.i_bops->write(bch->inode, (FAR uint8_t *)buffer,
				sector, nsectors);
		if (ret < 0) {
			fdbg("ERROR: Write failed: %d\n", ret);
			return ret;
		}

		/* Adjust pointers and counts */
		sector       += nsectors;
		nbytes        = nsectors * bch->sectsize;
		byteswritten += nbytes;

		if (sector >= bch->nsectors) {
			return byteswritten;
		}

		buffer    += nbytes;
		len       -= nbytes;
	}

	/* Then write any partial final sector */
	if (len > 0) {
		/* Read the sector into the sector buffer */
		bchlib_readsector(bch, sector);

		/* Copy the head end of the sector from the user buffer */
		memcpy(bch->buffer, buffer, len);
		bch->dirty = true;

		/* Adjust counts */
		byteswritten += len;
	}

	/* Finally, flush any cached writes to the device as well */
	ret = bchlib_flushsector(bch);
	if (ret < 0) {
		fdbg("ERROR: Flush failed: %d\n", ret);
		return ret;
	}

	return byteswritten;
}

