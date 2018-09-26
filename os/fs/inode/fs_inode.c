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
 * fs/inode/fs_files.c
 *
 *   Copyright (C) 2007-2009, 2011-2013 Gregory Nutt. All rights reserved.
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
#include <string.h>
#include <semaphore.h>
#include <assert.h>
#include <sched.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include <tinyara/kmalloc.h>

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
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: _files_semtake
 ****************************************************************************/

static void _files_semtake(FAR struct filelist *list)
{
	/* Take the semaphore (perhaps waiting) */

	while (sem_wait(&list->fl_sem) != 0) {
		/* The only case that an error should occr here is if
		 * the wait was awakened by a signal.
		 */

		ASSERT(get_errno() == EINTR);
	}
}

/****************************************************************************
 * Name: _files_semgive
 ****************************************************************************/

#define _files_semgive(list) sem_post(&list->fl_sem)

/****************************************************************************
 * Name: _files_close
 *
 * Description:
 *   Close an inode (if open)
 *
 * Assumuptions:
 *   Caller holds the list semaphore because the file descriptor will be freed.
 *
 ****************************************************************************/

static int _files_close(FAR struct file *filep)
{
	struct inode *inode = filep->f_inode;
	int ret = OK;

	/* Check if the struct file is open (i.e., assigned an inode) */

	if (inode) {
		/* Close the file, driver, or mountpoint. */

		if (inode->u.i_ops && inode->u.i_ops->close) {
			/* Perform the close operation */

			ret = inode->u.i_ops->close(filep);
		}

		/* And release the inode */

		inode_release(inode);

		/* Release the file descriptor */

		filep->f_oflags = 0;
		filep->f_pos = 0;
		filep->f_inode = NULL;
	}

	return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: files_initialize
 *
 * Description:
 *   This is called from the FS initialization logic to configure the files.
 *
 ****************************************************************************/

void files_initialize(void)
{
}

/****************************************************************************
 * Name: files_initlist
 *
 * Description: Initializes the list of files for a new task
 *
 ****************************************************************************/

void files_initlist(FAR struct filelist *list)
{
	DEBUGASSERT(list);

	/* Initialize the list access mutex */

	(void)sem_init(&list->fl_sem, 0, 1);
}

/****************************************************************************
 * Name: files_releaselist
 *
 * Description:
 *   Release a reference to the file list
 *
 ****************************************************************************/

void files_releaselist(FAR struct filelist *list)
{
	int i;

	DEBUGASSERT(list);

	/* Close each file descriptor .. Normally, you would need take the list
	 * semaphore, but it is safe to ignore the semaphore in this context because
	 * there should not be any references in this context.
	 */

	for (i = 0; i < CONFIG_NFILE_DESCRIPTORS; i++) {
		(void)_files_close(&list->fl_files[i]);
	}

	/* Destroy the semaphore */

	(void)sem_destroy(&list->fl_sem);
}

/****************************************************************************
 * Name: file_dup
 *
 * Description:
 *   Equivalent to the non-standard fs_dupfd() function except that it
 *   accepts a struct file instance instead of a file descriptor.  Currently
 *   used only by file_vfcntl();
 *
 ****************************************************************************/

int file_dup(FAR struct file *filep, int minfd)
{
	int fd2;
	struct file *filep2;

	/* Verify that fd is a valid, open file descriptor */
	if (!filep || !filep->f_inode) {
		set_errno(EBADF);
		return ERROR;
	}

	/* Increment the reference count on the contained inode */

	inode_addref(filep->f_inode);

	/* Then allocate a new file descriptor for the inode */

	fd2 = files_allocate(filep->f_inode, filep->f_oflags, filep->f_pos, minfd);
	if (fd2 < 0) {
		goto errout_with_inode;
	}

	filep2 = fs_getfilep(fd2);
	if (!filep2) {
		goto errout_with_inode;
	}

	DEBUGASSERT(filep->f_inode == filep2->f_inode);

	if (filep->f_inode->u.i_ops && filep->f_inode->u.i_ops->open) {
		int ret = 0;
#ifndef CONFIG_DISABLE_MOUNTPOINT
		if (INODE_IS_MOUNTPT(filep->f_inode)) {
			/* Dup the open file on the in the new file structure */
			ret = filep->f_inode->u.i_mops->dup(filep, filep2);
		} else
#endif
		{
			ret = filep->f_inode->u.i_ops->open(filep2);
		}

		/* Handle open failures */
		if (ret < 0) {
			goto errout_with_fd;
		}
	}
	return fd2;

errout_with_fd:
	files_release(fd2);

errout_with_inode:
	inode_release(filep->f_inode);
	set_errno(EMFILE);
	return ERROR;
}

/****************************************************************************
 * Name: file_dup2
 *
 * Description:
 *   Assign an inode to a specific files structure.  This is the heart of
 *   dup2.
 *
 ****************************************************************************/

int file_dup2(FAR struct file *filep1, FAR struct file *filep2)
{
	FAR struct filelist *list;
	FAR struct inode *inode;
	int err;
	int ret;

	if (!filep1 || !filep1->f_inode || !filep2) {
		err = EBADF;
		goto errout;
	}

	list = sched_getfiles();
	DEBUGASSERT(list);

	_files_semtake(list);

	/* If there is already an inode contained in the new file structure,
	 * close the file and release the inode.
	 */

	ret = _files_close(filep2);
	if (ret < 0) {
		/* An error occurred while closing the driver */

		goto errout_with_ret;
	}

	/* Increment the reference count on the contained inode */

	inode = filep1->f_inode;
	inode_addref(inode);

	/* Then clone the file structure */

	filep2->f_oflags = filep1->f_oflags;
	filep2->f_pos = filep1->f_pos;
	filep2->f_inode = inode;

	/* Call the open method on the file, driver, mountpoint so that it
	 * can maintain the correct open counts.
	 */

	if (inode->u.i_ops && inode->u.i_ops->open) {
#ifndef CONFIG_DISABLE_MOUNTPOINT
		if (INODE_IS_MOUNTPT(inode)) {
			/* Dup the open file on the in the new file structure */

			ret = inode->u.i_mops->dup(filep1, filep2);
		} else
#endif
		{
			/* (Re-)open the pseudo file or device driver */

			ret = inode->u.i_ops->open(filep2);
		}

		/* Handle open failures */

		if (ret < 0) {
			goto errout_with_inode;
		}
	}

	_files_semgive(list);
	return OK;

	/* Handler various error conditions */

errout_with_inode:
	inode_release(filep2->f_inode);
	filep2->f_oflags = 0;
	filep2->f_pos = 0;
	filep2->f_inode = NULL;

errout_with_ret:
	err = -ret;
	_files_semgive(list);

errout:
	set_errno(err);
	return ERROR;
}

/****************************************************************************
 * Name: files_allocate
 *
 * Description:
 *   Allocate a struct files instance and associate it with an inode instance.
 *   Returns the file descriptor == index into the files array.
 *
 ****************************************************************************/

int files_allocate(FAR struct inode *inode, int oflags, off_t pos, int minfd)
{
	FAR struct filelist *list;
	int i;

	list = sched_getfiles();
	DEBUGASSERT(list);

	_files_semtake(list);
	for (i = minfd; i < CONFIG_NFILE_DESCRIPTORS; i++) {
		if (!list->fl_files[i].f_inode) {
			list->fl_files[i].f_oflags = oflags;
			list->fl_files[i].f_pos = pos;
			list->fl_files[i].f_inode = inode;
			list->fl_files[i].f_priv = NULL;
			_files_semgive(list);
			return i;
		}
	}

	_files_semgive(list);
	return ERROR;
}

/****************************************************************************
 * Name: files_close
 *
 * Description:
 *   Close an inode (if open)
 *
 * Assumuptions:
 *   Caller holds the list semaphore because the file descriptor will be freed.
 *
 ****************************************************************************/

int files_close(int fd)
{
	FAR struct filelist *list;
	int ret;

	/* Get the thread-specific file list */

	list = sched_getfiles();
	DEBUGASSERT(list);

	/* If the file was properly opened, there should be an inode assigned */

	if (fd < 0 || fd >= CONFIG_NFILE_DESCRIPTORS || !list->fl_files[fd].f_inode) {
		return -EBADF;
	}

	/* Perform the protected close operation */

	_files_semtake(list);
	ret = _files_close(&list->fl_files[fd]);
	_files_semgive(list);
	return ret;
}

/****************************************************************************
 * Name: files_release
 *
 * Assumuptions:
 *   Similar to files_close().  Called only from open() logic on error
 *   conditions.
 *
 ****************************************************************************/

void files_release(int fd)
{
	FAR struct filelist *list;

	list = sched_getfiles();
	DEBUGASSERT(list);

	if (fd >= 0 && fd < CONFIG_NFILE_DESCRIPTORS) {
		_files_semtake(list);
		list->fl_files[fd].f_oflags = 0;
		list->fl_files[fd].f_pos = 0;
		list->fl_files[fd].f_inode = NULL;
		_files_semgive(list);
	}
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
 * fs/inode/fs_foreachinode.c
 *
 *   Copyright (C) 2012-2014 Gregory Nutt. All rights reserved.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Is it better to allocate the struct inode_path_s from the heap? or
 * from the stack?  This decision depends on how often this is down and
 * how much stack space you can afford.
 */

#define ENUM_INODE_ALLOC 1

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure manages the full path to the inode. */

struct inode_path_s {
	foreach_inode_t handler;
	FAR void *arg;
	char path[CONFIG_PATH_MAX];
};

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/
/****************************************************************************
 * Name: foreach_inodelevel
 *
 * Description:
 *   This is the recursive 'heart' of foreach_inode.  It will visit each
 *   inode at this level in the hierarchy and recurse handle each inode
 *   at the next level down.
 *
 * Assumptions:
 *   The caller holds the inode semaphore.
 *
 ****************************************************************************/

static int foreach_inodelevel(FAR struct inode *node, struct inode_path_s *info)
{
	int ret = OK;

	/* Visit each node at this level */

	for (; node; node = node->i_peer) {
		/* Give the next inode to the callback */

		ret = info->handler(node, info->path, info->arg);

		/* Break out of the looop early if the handler returns a non-zero
		 * value
		 */

		if (ret != 0) {
			break;
		}

		/* If there is a level 'beneath' this one, then recurse to visit all
		 * of the inodes at that level.
		 */

		if (node->i_child) {
			/* Construct the path to the next level */

			int pathlen = strlen(info->path);
			int namlen = strlen(node->i_name) + 1;

			/* Make sure that this would not exceed the maximum path length */

			if (pathlen + namlen > PATH_MAX) {
				ret = -ENAMETOOLONG;
				break;
			}

			/* Append the path segment to this inode and recurse */

			snprintf(&info->path[pathlen], PATH_MAX - pathlen, "/%s", node->i_name);
			ret = foreach_inodelevel(node->i_child, info);

			/* Truncate the path name back to the correct length */

			info->path[pathlen] = '\0';

			/* Return early if the handler at the lower level returned a non-
			 * zero value
			 */

			if (ret != 0) {
				break;
			}
		}
	}

	/* Return the result of the traversal. */

	return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: foreach_inode
 *
 * Description:
 *   Visit each inode in the pseudo-file system.  The traversal is terminated
 *   when the callback 'handler' returns a non-zero value, or when all of
 *   the inodes have been visited.
 *
 *   NOTE 1: Use with caution... The pseudo-file system is locked throughout
 *   the traversal.
 *   NOTE 2: The search algorithm is recursive and could, in principle, use
 *   an indeterminant amount of stack space.  This will not usually be a
 *   real work issue.
 *
 ****************************************************************************/

int foreach_inode(foreach_inode_t handler, FAR void *arg)
{
#ifdef ENUM_INODE_ALLOC
	FAR struct inode_path_s *info;
	int ret;

	/* Allocate the mountpoint info structure */

	info = (FAR struct inode_path_s *)kmm_malloc(sizeof(struct inode_path_s));
	if (!info) {
		return -ENOMEM;
	}

	/* Initialize the info structure */

	info->handler = handler;
	info->arg = arg;
	info->path[0] = '\0';

	/* Start the recursion at the root inode */

	inode_semtake();
	ret = foreach_inodelevel(root_inode, info);
	inode_semgive();

	/* Free the info structure and return the result */

	kmm_free(info);
	return ret;

#else
	struct inode_path_s info;
	int ret;

	/* Initialize the info structure */

	info.handler = handler;
	info.arg = arg;
	info.path[0] = '\0';

	/* Start the recursion at the root inode */

	inode_semtake();
	ret = foreach_inodelevel(root_inode, &info);
	inode_semgive();

	return ret;

#endif
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
 * fs/inode/fs_inode.c
 *
 *   Copyright (C) 2007-2009, 2011-2012 Gregory Nutt. All rights reserved.
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

#include <assert.h>
#include <semaphore.h>
#include <errno.h>

#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define NO_HOLDER (pid_t)-1;

/****************************************************************************
 * Private Types
 ****************************************************************************/
/* Implements a re-entrant mutex for inode access.  This must be re-entrant
 * because there can be cycles.  For example, it may be necessary to destroy
 * a block driver inode on umount() after a removable block device has been
 * removed.  In that case umount() hold the inode semaphore, but the block
 * driver may callback to unregister_blockdriver() after the un-mount,
 * requiring the seamphore again.
 */

struct inode_sem_s {
	sem_t sem;					/* The semaphore */
	pid_t holder;				/* The current holder of the semaphore */
	int16_t count;				/* Number of counts held */
};

/****************************************************************************
 * Private Variables
 ****************************************************************************/

static struct inode_sem_s g_inode_sem;

/****************************************************************************
 * Public Variables
 ****************************************************************************/

FAR struct inode *root_inode = NULL;

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: _inode_compare
 *
 * Description:
 *   Compare two inode names
 *
 ****************************************************************************/

static int _inode_compare(FAR const char *fname, FAR struct inode *node)
{
	char *nname = node->i_name;

	if (!nname) {
		return 1;
	}

	if (!fname) {
		return -1;
	}

	for (;;) {
		/* At end of node name? */

		if (!*nname) {
			/* Yes.. also end of find name? */

			if (!*fname || *fname == '/') {
				/* Yes.. return match */

				return 0;
			} else {
				/* No... return find name > node name */

				return 1;
			}
		}

		/* At end of find name? */

		else if (!*fname || *fname == '/') {
			/* Yes... return find name < node name */

			return -1;
		}

		/* Check for non-matching characters */

		else if (*fname > *nname) {
			return 1;
		} else if (*fname < *nname) {
			return -1;
		}

		/* Not at the end of either string and all of the
		 * characters still match.  keep looking.
		 */

		else {
			fname++;
			nname++;
		}
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: inode_initialize
 *
 * Description:
 *   This is called from the OS initialization logic to configure the file
 *   system.
 *
 ****************************************************************************/

void inode_initialize(void)
{
	/* Initialize the semaphore to one (to support one-at-a-time access to the
	 * inode tree).
	 */

	(void)sem_init(&g_inode_sem.sem, 0, 1);
	g_inode_sem.holder = NO_HOLDER;
	g_inode_sem.count = 0;

	/* Initialize files array (if it is used) */

#ifdef CONFIG_HAVE_WEAKFUNCTIONS
	if (files_initialize != NULL)
#endif
	{
		files_initialize();
	}
}

/****************************************************************************
 * Name: inode_semtake
 *
 * Description:
 *   Get exclusive access to the in-memory inode tree (g_inode_sem).
 *
 ****************************************************************************/

void inode_semtake(void)
{
	pid_t me;

	/* Do we already hold the semaphore? */

	me = getpid();
	if (me == g_inode_sem.holder) {
		/* Yes... just increment the count */

		g_inode_sem.count++;
		DEBUGASSERT(g_inode_sem.count > 0);
	}

	/* Take the semaphore (perhaps waiting) */

	else {
		while (sem_wait(&g_inode_sem.sem) != 0) {
			/* The only case that an error should occr here is if
			 * the wait was awakened by a signal.
			 */

			ASSERT(get_errno() == EINTR);
		}

		/* No we hold the semaphore */

		g_inode_sem.holder = me;
		g_inode_sem.count = 1;
	}
}

/****************************************************************************
 * Name: inode_semgive
 *
 * Description:
 *   Relinquish exclusive access to the in-memory inode tree (g_inode_sem).
 *
 ****************************************************************************/

void inode_semgive(void)
{
	DEBUGASSERT(g_inode_sem.holder == getpid());

	/* Is this our last count on the semaphore? */

	if (g_inode_sem.count > 1) {
		/* No.. just decrement the count */

		g_inode_sem.count--;
	}

	/* Yes.. then we can really release the semaphore */

	else {
		g_inode_sem.holder = NO_HOLDER;
		g_inode_sem.count = 0;
		sem_post(&g_inode_sem.sem);
	}
}

/****************************************************************************
 * Name: inode_search
 *
 * Description:
 *   Find the inode associated with 'path' returning the inode references
 *   and references to its companion nodes.
 *
 * Assumptions:
 *   The caller holds the g_inode_sem semaphore
 *
 ****************************************************************************/

FAR struct inode *inode_search(FAR const char **path, FAR struct inode **peer, FAR struct inode **parent, FAR const char **relpath)
{
	FAR const char *name = *path + 1;	/* Skip over leading '/' */
	FAR struct inode *node = root_inode;
	FAR struct inode *left = NULL;
	FAR struct inode *above = NULL;

	while (node) {
		int result = _inode_compare(name, node);

		/* Case 1:  The name is less than the name of the node.
		 * Since the names are ordered, these means that there
		 * is no peer node with this name and that there can be
		 * no match in the fileystem.
		 */

		if (result < 0) {
			node = NULL;
			break;
		}

		/* Case 2: the name is greater than the name of the node.
		 * In this case, the name may still be in the list to the
		 * "right"
		 */

		else if (result > 0) {
			left = node;
			node = node->i_peer;
		}

		/* The names match */

		else {
			/* Now there are three more possibilities:
			 *   (1) This is the node that we are looking for or,
			 *   (2) The node we are looking for is "below" this one.
			 *   (3) This node is a mountpoint and will absorb all request
			 *       below this one
			 */

			name = inode_nextname(name);
			if (!*name || INODE_IS_MOUNTPT(node)) {
				/* Either (1) we are at the end of the path, so this must be the
				 * node we are looking for or else (2) this node is a mountpoint
				 * and will handle the remaining part of the pathname
				 */

				if (relpath) {
					*relpath = name;
				}
				break;
			} else {
				/* More to go, keep looking at the next level "down" */

				above = node;
				left = NULL;
				node = node->i_child;
			}
		}
	}

	/* node is null.  This can happen in one of four cases:
	 * With node = NULL
	 *   (1) We went left past the final peer:  The new node
	 *       name is larger than any existing node name at
	 *       that level.
	 *   (2) We broke out in the middle of the list of peers
	 *       because the name was not found in the ordered
	 *       list.
	 *   (3) We went down past the final parent:  The new node
	 *       name is "deeper" than anything that we currently
	 *       have in the tree.
	 * with node != NULL
	 *   (4) When the node matching the full path is found
	 */

	if (peer) {
		*peer = left;
	}

	if (parent) {
		*parent = above;
	}

	*path = name;
	return node;
}

/****************************************************************************
 * Name: inode_free
 *
 * Description:
 *   Free resources used by an inode
 *
 ****************************************************************************/

void inode_free(FAR struct inode *node)
{
	if (node) {
		inode_free(node->i_peer);
		inode_free(node->i_child);
		kmm_free(node);
	}
}

/****************************************************************************
 * Name: inode_nextname
 *
 * Description:
 *   Given a path with node names separated by '/', return the next path
 *   segment name.
 *
 ****************************************************************************/

FAR const char *inode_nextname(FAR const char *name)
{
	/* Search for the '/' delimiter or the NUL terminator at the end of the
	 * path segment.
	 */

	while (*name && *name != '/') {
		name++;
	}

	/* If we found the '/' delimiter, then the path segment we want begins at
	 * the next character (which might also be the NUL terminator).
	 */

	if (*name) {
		name++;
	}

	return name;
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
 * fs/inode/fs_inodeaddref.c
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
 * Name: inode_addref
 *
 * Description:
 *   Increment the reference count on an inode (as when a file descriptor
 *   is dup'ed).
 *
 ****************************************************************************/

void inode_addref(FAR struct inode *inode)
{
	if (inode) {
		inode_semtake();
		inode->i_crefs++;
		inode_semgive();
	}
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
 * fs/inode/fs_basename.c
 *
 *   Copyright (C) 2014 Gregory Nutt. All rights reserved.
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
 * Name: inode_nextname
 *
 * Description:
 *   Given a path with node names separated by '/', return the name of last
 *   segment in the path.
 *
 ****************************************************************************/

FAR const char *inode_basename(FAR const char *name)
{
	FAR const char *basename = NULL;

	for (;;) {
		/* Get the name for the next path segment */

		name = inode_nextname(name);

		/* When the final segment is terminated by the NUL character, then
		 * previous name that we saved is the basename.
		 */

		if (name == NULL || *name == '\0') {
			/* Break out of the loop with basename pointer to the
			 * final segment of the path.
			 */

			break;
		}

		/* Set basename to point to the remainder of the path */

		basename = name;
	}

	return basename;
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
 * fs/inode/fs_inodefind.c
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
 * Name: inode_find
 *
 * Description:
 *   This is called from the open() logic to get a reference to the inode
 *   associated with a path.
 *
 ****************************************************************************/

FAR struct inode *inode_find(FAR const char *path, FAR const char **relpath)
{
	FAR struct inode *node;

	if (!path || !*path || path[0] != '/') {
		return NULL;
	}

	/* Find the node matching the path.  If found, increment the count of
	 * references on the node.
	 */

	inode_semtake();
	node = inode_search(&path, (FAR struct inode **)NULL, (FAR struct inode **)NULL, relpath);
	if (node) {
		node->i_crefs++;
	}

	inode_semgive();
	return node;
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
 * fs/inode/fs_inoderelease.c
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

#include <errno.h>

#include <tinyara/kmalloc.h>
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
 * Name: inode_release
 *
 * Description:
 *   This is called from close() logic when it no longer refers to the inode.
 *
 ****************************************************************************/

void inode_release(FAR struct inode *node)
{
	if (node) {
		/* Decrement the references of the inode */

		inode_semtake();
		if (node->i_crefs) {
			node->i_crefs--;
		}

		/* If the subtree was previously deleted and the reference
		 * count has decrement to zero,  then delete the inode
		 * now.
		 */

		if (node->i_crefs <= 0 && (node->i_flags & FSNODEFLAG_DELETED) != 0) {
			inode_semgive();
			inode_free(node->i_child);
			kmm_free(node);
		} else {
			inode_semgive();
		}
	}
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
 * fs/inode/fs_inoderemove.c
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

#include <errno.h>

#include <tinyara/kmalloc.h>
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
 * Name: inode_unlink
 *
 * Description:
 *   Given a path, remove a the node from the in-memory, inode tree that the
 *   path refers to.  This is normally done in preparation to removing or
 *   moving an inode.
 *
 * Assumptions/Limitations:
 *   The caller must hold the inode semaphore
 *
 ****************************************************************************/

FAR struct inode *inode_unlink(FAR const char *path)
{
	const char *name = path;
	FAR struct inode *node;
	FAR struct inode *peer;
	FAR struct inode *parent;

	/* Verify parameters.  Ignore null paths and relative paths */

	if (!path || *path == '\0' || path[0] != '/') {
		return NULL;
	}

	/* Find the node to unlink */

	node = inode_search(&name, &peer, &parent, (const char **)NULL);
	if (node) {
		/* If peer is non-null, then remove the node from the right of
		 * of that peer node.
		 */

		if (peer) {
			peer->i_peer = node->i_peer;
		}

		/* If parent is non-null, then remove the node from head of
		 * of the list of children.
		 */

		else if (parent) {
			parent->i_child = node->i_peer;
		}

		/* Otherwise, we must be removing the root inode. */

		else {
			root_inode = node->i_peer;
		}

		node->i_peer = NULL;
	}

	return node;
}

/****************************************************************************
 * Name: inode_remove
 *
 * Description:
 *   Given a path, remove a the node from the in-memory, inode tree that the
 *   path refers to and free all resources related to the inode.  If the
 *   inode is in-use, then it will be unlinked, but will not be freed until
 *   the last reference to the inode is released.
 *
 * Assumptions/Limitations:
 *   The caller must hold the inode semaphore
 *
 ****************************************************************************/

int inode_remove(FAR const char *path)
{
	FAR struct inode *node;

	/* Find the inode and unlink it from the in-memory inode tree */

	node = inode_unlink(path);
	if (node) {
		/* Found it! But we cannot delete the inode if there are references
		 * to it
		 */

		if (node->i_crefs) {
			/* In that case, we will mark it deleted, when the filesystem
			 * releases the inode, we will then, finally delete the subtree
			 */

			node->i_flags |= FSNODEFLAG_DELETED;
			return -EBUSY;
		} else {
			/* And delete it now -- recursively to delete all of its children */

			inode_free(node->i_child);
			kmm_free(node);
			return OK;
		}
	}

	/* The node does not exist */

	return -ENOENT;
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
 * fs/inode/fs_registerreserve.c
 *
 *   Copyright (C) 2007-2009, 2011-2012 Gregory Nutt. All rights reserved.
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

#include <assert.h>
#include <errno.h>
#include <string.h>

#include <tinyara/kmalloc.h>
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
 * Name: inode_namelen
 ****************************************************************************/

static int inode_namelen(FAR const char *name)
{
	const char *tmp = name;
	while (*tmp && *tmp != '/') {
		tmp++;
	}
	return tmp - name;
}

/****************************************************************************
 * Name: inode_namecpy
 ****************************************************************************/

static void inode_namecpy(char *dest, const char *src)
{
	while (*src && *src != '/') {
		*dest++ = *src++;
	}
	*dest = '\0';
}

/****************************************************************************
 * Name: inode_alloc
 ****************************************************************************/

static FAR struct inode *inode_alloc(FAR const char *name)
{
	int namelen = inode_namelen(name);
	FAR struct inode *node = (FAR struct inode *)kmm_zalloc(FSNODE_SIZE(namelen));
	if (node) {
		inode_namecpy(node->i_name, name);
	}

	return node;
}

/****************************************************************************
 * Name: inode_insert
 ****************************************************************************/

static void inode_insert(FAR struct inode *node, FAR struct inode *peer, FAR struct inode *parent)
{
	/* If peer is non-null, then new node simply goes to the right
	 * of that peer node.
	 */

	if (peer) {
		node->i_peer = peer->i_peer;
		peer->i_peer = node;
	}

	/* If parent is non-null, then it must go at the head of its
	 * list of children.
	 */

	else if (parent) {
		node->i_peer = parent->i_child;
		parent->i_child = node;
	}

	/* Otherwise, this must be the new root_inode */

	else {
		node->i_peer = root_inode;
		root_inode = node;
	}
}

/****************************************************************************
 * Name: select_last_inode
 ****************************************************************************/

static void* select_last_inode(FAR const char *name)
{
	const char *tmp = name;
	void *last = NULL;

	while (*tmp && *tmp != '\0') {
		if (*tmp == '/') {
			last = (void*)tmp;
		}
		tmp++;
	}

	return ++last;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: inode_reserve
 *
 * Description:
 *   Reserve an (initialized) inode the pseudo file system.
 *
 *   NOTE: Caller must hold the inode semaphore
 *
 * Input parameters:
 *   path - The path to the inode to create
 *   inode - The location to return the inode pointer
 *
 * Returned Value:
 *   Zero on success (with the inode point in 'inode'); A negated errno
 *   value is returned on failure:
 *
 *   EINVAL       - 'path' is invalid for this operation
 *   EEXIST       - An inode already exists at 'path'
 *   ENOMEM       - Failed to allocate in-memory resources for the operation
 *   ENAMETOOLONG - File name too long
 *
 ****************************************************************************/

int inode_reserve(FAR const char *path, FAR struct inode **inode)
{
	FAR const char *name = path;
	FAR struct inode *left;
	FAR struct inode *parent;

	/* Assume failure */

	DEBUGASSERT(path && inode);
	*inode = NULL;

	/* Handle paths that are interpreted as the root directory */

	if (!*path || path[0] != '/') {
		return -EINVAL;
	}

	/* Check file name length */

	if (strlen(select_last_inode(name)) > CONFIG_NAME_MAX) {
		return -ENAMETOOLONG;
	}

	/* Find the location to insert the new subtree */

	if (inode_search(&name, &left, &parent, (FAR const char **)NULL) != NULL) {
		/* It is an error if the node already exists in the tree */

		return -EEXIST;
	}

	/* Now we now where to insert the subtree */

	for (;;) {
		FAR struct inode *node;

		/* Create a new node -- we need to know if this is the
		 * the leaf node or some intermediary.  We can find this
		 * by looking at the next name.
		 */

		FAR const char *next_name = inode_nextname(name);
		if (*next_name) {
			/* Insert an operationless node */

			node = inode_alloc(name);
			if (node) {
				inode_insert(node, left, parent);

				/* Set up for the next time through the loop */

				name = next_name;
				left = NULL;
				parent = node;
				continue;
			}
		} else {
			node = inode_alloc(name);
			if (node) {
				inode_insert(node, left, parent);
				*inode = node;
				return OK;
			}
		}

		/* We get here on failures to allocate node memory */

		return -ENOMEM;
	}
}


