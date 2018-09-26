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
 * fs/mount/fs_foreachmountpoint.c
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

#include <sys/statfs.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "inode/inode.h"

#ifndef CONFIG_DISABLE_MOUNTPOINT

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure just remembers the final consumer of the mountpoint
 * information (and its argument).
 */

struct enum_mountpoint_s {
	foreach_mountpoint_t handler;
	FAR void *arg;
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

static int mountpoint_filter(FAR struct inode *node, FAR char dirpath[PATH_MAX], FAR void *arg)
{
	FAR struct enum_mountpoint_s *info = (FAR struct enum_mountpoint_s *)arg;
	struct statfs statbuf;
	int pathlen;
	int namlen;
	int ret = OK;

	DEBUGASSERT(node && info && info->handler);

	/* Check if the inode is a mountpoint.  Mountpoints must support statfs.
	 * If this one does not for some reason, then it will be ignored.
	 *
	 * The root node is a special case:  It has no operations (u.i_mops == NULL)
	 */

	if (INODE_IS_MOUNTPT(node) && node->u.i_mops && node->u.i_mops->statfs) {
		/* Yes... get the full path to the inode by concatenating the inode
		 * name and the path to the directory containing the inode.
		 */

		pathlen = strlen(dirpath);
		namlen = strlen(node->i_name) + 1;

		/* Make sure that this would not exceed the maximum path length */

		if (pathlen + namlen > PATH_MAX) {
			return -ENAMETOOLONG;
		}

		/* Append the inode name to the directory path */

		snprintf(&dirpath[pathlen], PATH_MAX - pathlen, "/%s", node->i_name);

		/* Get the status of the file system */

		ret = node->u.i_mops->statfs(node, &statbuf);
		if (ret == OK) {
			/* And pass the full path and file system status to the handler */

			ret = info->handler(dirpath, &statbuf, info->arg);
		}

		/* Truncate the path name back to the correct length */

		dirpath[pathlen] = '\0';
	}

	return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
* Name: foreach_mountpoint
*
* Description:
*   Visit each mountpoint in the pseudo-file system.  The traversal is
*   terminated when the callback 'handler' returns a non-zero value, or when
*   all of the mountpoints have been visited.
*
*   This is just a front end "filter" to foreach_inode() that forwards only
*   mountpoint inodes.  It is intended to support the mount() command to
*   when the mount command is used to enumerate mounts.
*
*   NOTE 1: Use with caution... The pseudo-file system is locked throughout
*   the traversal.
*   NOTE 2: The search algorithm is recursive and could, in principle, use
*   an indeterminant amount of stack space.  This will not usually be a
*   real work issue.
*
****************************************************************************/

int foreach_mountpoint(foreach_mountpoint_t handler, FAR void *arg)
{
	struct enum_mountpoint_s info;

	/* Let foreach_inode do the real work */

	info.handler = handler;
	info.arg = arg;

	return foreach_inode(mountpoint_filter, (FAR void *)&info);
}

#endif
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
 * fs/mount/fs_mount.c
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

#include <sys/mount.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/fs/fs.h>

#include "inode/inode.h"
#include "driver/block/driver.h"

/* At least one filesystem must be defined, or this file will not compile.
 * It may be desire-able to make filesystems dynamically registered at
 * some time in the future, but at present, this file needs to know about
 * every configured filesystem.
 */

#ifdef CONFIG_FS_READABLE

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Configuration ************************************************************/
/* In the canonical case, a file system is bound to a block driver.  However,
 * some less typical cases a block driver is not required.  Examples are
 * pseudo file systems (like BINFS or PROCFS) and MTD file systems (like NXFFS).
 *
 * These file systems all require block drivers:
 */

#if defined(CONFIG_FS_SMARTFS) || defined(CONFIG_FS_ROMFS)
#define BDFS_SUPPORT 1
#endif

#if defined(CONFIG_FS_PROCFS) || defined(CONFIG_FS_TMPFS)
#define NONBDFS_SUPPORT
#endif

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct fsmap_t {
	FAR const char *fs_filesystemtype;
	FAR const struct mountpt_operations *fs_mops;
};

/****************************************************************************
 * Private Variables
 ****************************************************************************/

#ifdef BDFS_SUPPORT
/*
 * How to add new type of file system:
 * for adding new type of file system at first define a macro so that,
 * file systems can be differentiated. Then use that macro to add like below,
 *
 * #ifdef NEW_FILE_SYSTEM
 * extern const struct mountpt_operations new_file_system;
 * #else
 * extern const struct mountpt_operations smartfs_operations;
 * #endif
 *
 */

#ifdef CONFIG_FS_SMARTFS
extern const struct mountpt_operations smartfs_operations;
#endif
#ifdef CONFIG_FS_ROMFS
extern const struct mountpt_operations romfs_operations;
#endif
static const struct fsmap_t g_bdfsmap[] = {
	/*
	 * For a new file system you have to add { "new_file_system", &operations }
	 * here. If no file system exists then you have to add { NULL, NULL }
	 */
#ifdef CONFIG_FS_SMARTFS
	{"smartfs", &smartfs_operations},
#endif
#ifdef CONFIG_FS_ROMFS
	{"romfs", &romfs_operations},
#endif
	{NULL, NULL},
};
#endif							/* BDFS_SUPPORT */

#ifdef NONBDFS_SUPPORT

#ifdef CONFIG_FS_PROCFS
extern const struct mountpt_operations procfs_operations;
#endif
#ifdef CONFIG_FS_TMPFS
extern const struct mountpt_operations tmpfs_operations;
#endif

static const struct fsmap_t g_nonbdfsmap[] = {
#ifdef CONFIG_FS_PROCFS
	{"procfs", &procfs_operations},
#endif

#ifdef CONFIG_FS_TMPFS
	{TMPFS_FSTYPE, &tmpfs_operations},
#endif
	{NULL, NULL},
};
#endif							/* NONBDFS_SUPPORT */

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mount_findfs
 *
 * Description:
 *    find the specified filesystem
 *
 ****************************************************************************/

#if defined(BDFS_SUPPORT) || defined(NONBDFS_SUPPORT)
static FAR const struct mountpt_operations *mount_findfs(FAR const struct fsmap_t *fstab, FAR const char *filesystemtype)
{
	FAR const struct fsmap_t *fsmap;

	for (fsmap = fstab; fsmap->fs_filesystemtype; fsmap++) {
		if (strcmp(filesystemtype, fsmap->fs_filesystemtype) == 0) {
			return fsmap->fs_mops;
		}
	}

	return NULL;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mount
 *
 * Description:
 *   mount() attaches the filesystem specified by the 'source' block device
 *   name into the root file system at the path specified by 'target.'
 *
 * Return:
 *   Zero is returned on success; -1 is returned on an error and errno is
 *   set appropriately:
 *
 *   EACCES A component of a path was not searchable or mounting a read-only
 *      filesystem was attempted without giving the MS_RDONLY flag.
 *   EEXIST 'source' is already  mounted.
 *   EFAULT One of the pointer arguments points outside the user address
 *      space.
 *   EINVAL 'source' had an invalid superblock.
 *   ENODEV 'filesystemtype' not configured
 *   ENOENT A pathname was empty or had a nonexistent component.
 *   ENOMEM Could not allocate a memory to copy filenames or data into.
 *   ENOTBLK 'source' is not a block device
 *
 ****************************************************************************/

int mount(FAR const char *source, FAR const char *target, FAR const char *filesystemtype, unsigned long mountflags, FAR const void *data)
{
#if defined(BDFS_SUPPORT) || defined(NONBDFS_SUPPORT)
#ifdef BDFS_SUPPORT
	FAR struct inode *blkdrvr_inode = NULL;
#endif
	FAR struct inode *mountpt_inode;
	FAR const struct mountpt_operations *mops;
	void *fshandle;
	int errcode;
	int ret;

	/* Verify required pointer arguments */

	DEBUGASSERT(target && filesystemtype);

	/* Find the specified filesystem.  Try the block driver file systems first */

#ifdef BDFS_SUPPORT
	if (source && (mops = mount_findfs(g_bdfsmap, filesystemtype)) != NULL) {
		/* Make sure that a block driver argument was provided */

		DEBUGASSERT(source);

		/* Find the block driver */

		ret = find_blockdriver(source, mountflags, &blkdrvr_inode);
		if (ret < 0) {
			/* find_blockdriver can fail for a couple of reasons, it may return:
			 *
			 *  -EINVAL  - pathname or pinode is NULL
			 *  -ENOENT  - No block driver of this name is registered
			 *  -ENOTBLK - The inode associated with the pathname is not a block driver
			 *  -EACCESS - The MS_RDONLY option was not set but this driver does not support write access
			 */

			fdbg("ERROR: Failed to find block driver %s\n", source);
			errcode = -ret;
			goto errout;
		}
	} else
#endif							/* BDFS_SUPPORT */
#ifdef NONBDFS_SUPPORT
		if ((mops = mount_findfs(g_nonbdfsmap, filesystemtype)) != NULL) {
		} else
#endif							/* NONBDFS_SUPPORT */
		{
			fdbg("ERROR: Failed to find file system %s\n", filesystemtype);
			errcode = ENODEV;
			goto errout;
		}

	/* Insert a dummy node -- we need to hold the inode semaphore
	 * to do this because we will have a momentarily bad structure.
	 */

	inode_semtake();
	ret = inode_reserve(target, &mountpt_inode);
	if (ret < 0) {
		/* inode_reserve can fail for a couple of reasons, but the most likely
		 * one is that the inode already exists. inode_reserve may return:
		 *
		 *  -EINVAL - 'path' is invalid for this operation
		 *  -EEXIST - An inode already exists at 'path'
		 *  -ENOMEM - Failed to allocate in-memory resources for the operation
		 */

		fdbg("ERROR: Failed to reserve inode\n");
		errcode = -ret;
		goto errout_with_semaphore;
	}

	/* Bind the block driver to an instance of the file system.  The file
	 * system returns a reference to some opaque, fs-dependent structure
	 * that encapsulates this binding.
	 */

	if (!mops->bind) {
		/* The filesystem does not support the bind operation ??? */

		fdbg("ERROR: Filesystem does not support bind\n");
		errcode = EINVAL;
		goto errout_with_mountpt;
	}

	/* Increment reference count for the reference we pass to the file system */

#ifdef BDFS_SUPPORT
#ifdef NONBDFS_SUPPORT
	if (blkdrvr_inode)
#endif
	{
		blkdrvr_inode->i_crefs++;
	}
#endif

	/* On failure, the bind method returns -errorcode */

#ifdef BDFS_SUPPORT
	ret = mops->bind(blkdrvr_inode, data, &fshandle);
#else
	ret = mops->bind(NULL, data, &fshandle);
#endif
	if (ret != 0) {
		/* The inode is unhappy with the blkdrvr for some reason.  Back out
		 * the count for the reference we failed to pass and exit with an
		 * error.
		 */

		fdbg("ERROR: Bind method failed: %d\n", ret);
#ifdef BDFS_SUPPORT
#ifdef NONBDFS_SUPPORT
		if (blkdrvr_inode)
#endif
		{
			blkdrvr_inode->i_crefs--;
		}
#endif
		errcode = -ret;
		goto errout_with_mountpt;
	}

	/* We have it, now populate it with driver specific information. */

	INODE_SET_MOUNTPT(mountpt_inode);

	mountpt_inode->u.i_mops = mops;
#ifdef CONFIG_FILE_MODE
	mountpt_inode->i_mode = mode;
#endif
	mountpt_inode->i_private = fshandle;
	inode_semgive();

	/* We can release our reference to the blkdrver_inode, if the filesystem
	 * wants to retain the blockdriver inode (which it should), then it must
	 * have called inode_addref().  There is one reference on mountpt_inode
	 * that will persist until umount() is called.
	 */

#ifdef BDFS_SUPPORT
#ifdef NONBDFS_SUPPORT
	if (blkdrvr_inode)
#endif
	{
		inode_release(blkdrvr_inode);
	}
#endif

	return OK;

	/* A lot of goto's!  But they make the error handling much simpler */

errout_with_mountpt:
	mountpt_inode->i_crefs = 0;
	inode_remove(target);
	inode_semgive();
#ifdef BDFS_SUPPORT
#ifdef NONBDFS_SUPPORT
	if (blkdrvr_inode)
#endif
	{
		inode_release(blkdrvr_inode);
	}
#endif

	inode_release(mountpt_inode);
	goto errout;

errout_with_semaphore:
	inode_semgive();
#ifdef BDFS_SUPPORT
#ifdef NONBDFS_SUPPORT
	if (blkdrvr_inode)
#endif
	{
		inode_release(blkdrvr_inode);
	}
#endif

errout:
	set_errno(errcode);
	return ERROR;

#else
	fdbg("ERROR: No filesystems enabled\n");
	set_errno(ENOSYS);
	return ERROR;
#endif							/* BDFS_SUPPORT || NONBDFS_SUPPORT */
}

#endif							/* CONFIG_FS_READABLE */
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
 * fs/mount/fs_umount.c
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

#include <sys/mount.h>
#include <errno.h>
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
 * Name: umount
 *
 * Description:
 *   umount() detaches the filesystem mounted at the path specified by
 *  'target.'
 *
 * Return:
 *   Zero is returned on success; -1 is returned on an error and errno is
 *   set appropriately:
 *
 *   EACCES A component of a path was not searchable or mounting a read-only
 *      filesystem was attempted without giving the MS_RDONLY flag.
 *   EBUSY The target could not be unmounted because it is busy.
 *   EFAULT The pointer argument points outside the user address space.
 *
 ****************************************************************************/

int umount(const char *target)
{
	FAR struct inode *mountpt_inode;
	FAR struct inode *blkdrvr_inode = NULL;
	int errcode = OK;
	int status;

	/* Verify required pointer arguments */

	if (!target) {
		errcode = EFAULT;
		goto errout;
	}

	/* Find the mountpt */

	mountpt_inode = inode_find(target, NULL);
	if (!mountpt_inode) {
		errcode = ENOENT;
		goto errout;
	}

	/* Verify that the inode is a mountpoint */

	if (!INODE_IS_MOUNTPT(mountpt_inode)) {
		errcode = EINVAL;
		goto errout_with_mountpt;
	}

	/* Unbind the block driver from the file system (destroying any fs
	 * private data.
	 */

	if (!mountpt_inode->u.i_mops->unbind) {
		/* The filesystem does not support the unbind operation ??? */

		errcode = EINVAL;
		goto errout_with_mountpt;
	}

	/* The unbind method returns the number of references to the
	 * filesystem (i.e., open files), zero if the unbind was
	 * performed, or a negated error code on a failure.
	 */

	inode_semtake();			/* Hold the semaphore through the unbind logic */
	status = mountpt_inode->u.i_mops->unbind(mountpt_inode->i_private, &blkdrvr_inode);
	if (status < 0) {
		/* The inode is unhappy with the blkdrvr for some reason */

		errcode = -status;
		goto errout_with_semaphore;
	} else if (status > 0) {
		errcode = EBUSY;
		goto errout_with_semaphore;
	}

	/* Successfully unbound */

	mountpt_inode->i_private = NULL;

	/* Successfully unbound, remove the mountpoint inode from
	 * the inode tree.  The inode will not be deleted yet because
	 * there is still at least reference on it (from the mount)
	 */

	status = inode_remove(target);
	inode_semgive();

	/* The return value of -EBUSY is normal (in fact, it should
	 * not be OK)
	 */

	if (status != OK && status != -EBUSY) {
		errcode = -status;
		goto errout_with_mountpt;
	}

	/* Release the mountpoint inode and any block driver inode
	 * returned by the file system unbind above.  This should cause
	 * the inode to be deleted (unless there are other references)
	 */

	inode_release(mountpt_inode);

	/* Did the unbind method return a contained block driver */

	if (blkdrvr_inode) {
		inode_release(blkdrvr_inode);
	}

	return OK;

	/* A lot of goto's!  But they make the error handling much simpler */

errout_with_semaphore:
	inode_semgive();
errout_with_mountpt:
	inode_release(mountpt_inode);
	if (blkdrvr_inode) {
		inode_release(blkdrvr_inode);
	}
errout:
	set_errno(errcode);
	return ERROR;
}


