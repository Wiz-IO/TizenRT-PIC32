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
 * fs/dirent/fs_closedir.c
 *
 *   Copyright (C) 2007-2009, 2011, 2013-2014 Gregory Nutt. All rights reserved.
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

#include <dirent.h>
#include <errno.h>
#include <string.h>

#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>
#include <tinyara/fs/dirent.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: closedir
 *
 * Description:
 *    The closedir() function closes the directory stream associated with
 *    'dirp'.  The directory stream descriptor 'dirp' is not available after
 *    this call.
 *
 * Inputs:
 *   dirp -- An instance of type DIR created by a previous call to opendir();
 *
 * Return:
 *   The closedir() function returns 0 on success.  On error, -1 is
 *   returned, and errno is set appropriately.
 *
 ****************************************************************************/

int closedir(FAR DIR *dirp)
{
	struct fs_dirent_s *idir = (struct fs_dirent_s *)dirp;
#ifndef CONFIG_DISABLE_MOUNTPOINT
	struct inode *inode;
#endif
	int ret;

	/* Verify that we were provided with a valid directory structure */

	if (!idir) {
		ret = EBADF;
		goto errout;
	}

	/* A special case is when we enumerate an "empty", unused inode.  That is
	 * an inode in the pseudo-filesystem that has no operations and no children.
	 * This is a "dangling" directory entry that has lost its childre.
	 */

	if (idir->fd_root) {
		/* This is the 'root' inode of the directory.  This means different
		 * things wih different filesystems.
		 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
		inode = idir->fd_root;

		/* The way that we handle the close operation depends on what kind of
		 * root inode we have open.
		 */

		if (INODE_IS_MOUNTPT(inode) && !DIRENT_ISPSEUDONODE(idir->fd_flags)) {
			/* The node is a file system mointpoint. Verify that the
			 * mountpoint supports the closedir() method (not an error if it
			 * does not)
			 */

			if (inode->u.i_mops && inode->u.i_mops->closedir) {
				/* Perform the closedir() operation */

				ret = inode->u.i_mops->closedir(inode, idir);
				if (ret < 0) {
					ret = -ret;
					goto errout_with_inode;
				}
			}
		} else
#endif
		{
			/* The node is part of the root pseudo file system, release
			 * our contained reference to the 'next' inode.
			 */

			if (idir->u.pseudo.fd_next) {
				inode_release(idir->u.pseudo.fd_next);
			}
		}

		/* Release our references on the contained 'root' inode */

		inode_release(idir->fd_root);
	}

	/* Then release the container */

	memset(idir, 0, sizeof(struct fs_dirent_s));
	kumm_free(idir);
	return OK;

#ifndef CONFIG_DISABLE_MOUNTPOINT
errout_with_inode:
	inode_release(inode);
	kumm_free(idir);
#endif

errout:
	set_errno(ret);
	return ERROR;
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
 * fs/dirent/fs_opendir.c
 *
 *   Copyright (C) 2007-2009, 2011, 2013-2014 Gregory Nutt. All rights reserved.
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
#include <dirent.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>
#include <tinyara/fs/dirent.h>
#include <sys/stat.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: open_mountpoint
 *
 * Description:
 *   Handle the case where the inode to be opened is within a mountpoint.
 *
 * Inputs:
 *   inode -- the inode of the mountpoint to open
 *   relpath -- the relative path within the mountpoint to open
 *   dir -- the dirent structure to be initialized
 *
 * Return:
 *   On success, OK is returned; Otherwise, a positive errno is returned.
 *
 ****************************************************************************/

#ifndef CONFIG_DISABLE_MOUNTPOINT
static inline int open_mountpoint(FAR struct inode *inode, FAR const char *relpath, FAR struct fs_dirent_s *dir)
{
	int ret;

	/* The inode itself as the 'root' of mounted volume.  The actually
	 * directory is at relpath into the* mounted filesystem.
	 *
	 * Verify that the mountpoint inode  supports the opendir() method
	 */

	if (!inode->u.i_mops || !inode->u.i_mops->opendir) {
		return ENOSYS;
	}

	/* Take reference to the mountpoint inode.  Note that we do not use
	 * inode_addref() because we already hold the tree semaphore.
	 */

	inode->i_crefs++;

	/* Perform the opendir() operation */

	ret = inode->u.i_mops->opendir(inode, relpath, dir);
	if (ret < 0) {
		/* We now need to back off our reference to the inode.  We can't
		 * call inode_release() to do that unless we release the tree
		 * semaphore.  The following should be safe because:  (1) after the
		 * reference count was incremented above it should be >=1 so it should
		 * not decrement below zero, and (2) we hold the tree semaphore so no
		 * other thread should be able to change the reference count.
		 */

		inode->i_crefs--;
		DEBUGASSERT(inode->i_crefs >= 0);

		/* Negate the error value so that it can be used to set errno */

		return -ret;
	}

	return OK;
}
#endif

/****************************************************************************
 * Name: open_pseudodir
 *
 * Description:
 *   Handle the case where the inode to be opened is within the top-level
 *   pseudo-file system.
 *
 * Inputs:
 *   inode -- the inode of the mountpoint to open
 *   dir -- the dirent structure to be initialized
 *
 * Return:
 *   None
 *
 ****************************************************************************/

static void open_pseudodir(FAR struct inode *inode, FAR struct fs_dirent_s *dir)
{
	/* We have a valid pseudo-filesystem node.  Take two references on the
	 * inode -- one for the parent (fd_root) and one for the child (fd_next).
	 * Note that we do not call inode_addref because we are holding the tree
	 * semaphore and that would result in deadlock.
	 */

	inode->i_crefs += 2;
	dir->fd_root = inode;		/* Save the inode where we start */
	dir->u.pseudo.fd_next = inode;	/* This is the next node to use for readdir() */

	/* Flag the inode as belonging to the pseudo-filesystem */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	DIRENT_SETPSEUDONODE(dir->fd_flags);
#endif
}

/****************************************************************************
 * Name: open_emptydir
 *
 * Description:
 *   Handle the case where the inode to be opened is an empty, directory node
 *   within the top-level pseudo-file system.  That is, it has no operations
 *   and, therefore, it must be a directory node.  But is has no children
 *   to be enumerated either.
 *
 * Inputs:
 *   dir -- the dirent structure to be initialized
 *
 * Return:
 *   None
 *
 ****************************************************************************/

static inline void open_emptydir(FAR struct fs_dirent_s *dir)
{
	/* We have a valid, but empty pseudo-filesystem node.  fd_next is NULL
	 * meaning that we are already at the end of the list of its children.
	 * fd_root is NULL so that if the directory is rewound, it will still be
	 * at the end of the list.
	 */

#if 0							/* Already nullified by kumm_zalloc */
	dir->fd_root = NULL;		/* Save the inode where we start */
	dir->u.pseudo.fd_next = NULL;	/* We are at the end of the list */
#endif

	/* Flag the inode as belonging to the pseudo-filesystem */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	DIRENT_SETPSEUDONODE(dir->fd_flags);
#endif
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: opendir
 *
 * Description:
 *   The  opendir() function opens a directory stream corresponding to the
 *   directory name, and returns a pointer to the directory stream. The
 *   stream is positioned at the first entry in the directory.
 *
 * Inputs:
 *   path -- the directory to open
 *
 * Return:
 *   The opendir() function returns a pointer to the directory stream.  On
 *   error, NULL is returned, and errno is set appropriately.
 *
 *   EACCES  - Permission denied.
 *   EMFILE  - Too many file descriptors in use by process.
 *   ENFILE  - Too many files are currently open in the
 *             system.
 *   ENOENT  - Directory does not exist, or name is an empty
 *             string.
 *   ENOMEM  - Insufficient memory to complete the operation.
 *   ENOTDIR - 'path' is not a directory.
 *
 ****************************************************************************/

FAR DIR *opendir(FAR const char *path)
{
	FAR struct inode *inode = NULL;
	FAR struct fs_dirent_s *dir;
	FAR const char *relpath;
	struct stat st;
	bool isroot = false;
	int ret;

	/* If we are given 'nothing' then we will interpret this as
	 * request for the root inode.
	 */

	if (!path || *path == '\0') {
		set_errno(ENOENT);
		return NULL;
	}

	inode_semtake();
	if (strcmp(path, "/") == 0) {
		inode = root_inode;
		isroot = true;
		relpath = NULL;
	} else {
		/* We don't know what to do with relative pathes */

		if (*path != '/') {
			ret = -ENOTDIR;
			goto errout_with_semaphore;
		}

		/* Find the node matching the path. */

		inode = inode_search(&path, (FAR struct inode **)NULL, (FAR struct inode **)NULL, &relpath);
	}

	/* Did we get an inode? */

	if (!inode) {
		/* 'path' is not a does not exist. */

		ret = ENOTDIR;
		goto errout_with_semaphore;
	}

	/* Allocate a type DIR -- which is little more than an inode
	 * container.
	 */

	dir = (FAR struct fs_dirent_s *)kumm_zalloc(sizeof(struct fs_dirent_s));
	if (!dir) {
		/* Insufficient memory to complete the operation. */

		ret = ENOMEM;
		goto errout_with_semaphore;
	}

	/* Populate the DIR structure and return it to the caller.  The way that
	 * we do this depends on whenever this is a "normal" pseudo-file-system
	 * inode or a file system mountpoint.
	 */

	dir->fd_position = 0;		/* This is the position in the read stream */

	/* First, handle the special case of the root inode.  This must be
	 * special-cased here because the root inode might ALSO be a mountpoint.
	 */

	if (isroot) {
		/* Whatever payload the root inode carries, the root inode is always
		 * a directory inode in the pseudo-file system
		 */

		open_pseudodir(inode, dir);
	}

	/* Is this a node in the pseudo filesystem? Or a mountpoint?  If the node
	 * is the root (isroot == TRUE), then this is a special case.
	 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	else if (INODE_IS_MOUNTPT(inode)) {
		/* Yes, the node is a file system mountpoint */

		if (inode->u.i_mops && inode->u.i_mops->stat) {
			/* Perform the stat() operation */

			ret = inode->u.i_mops->stat(inode, path, &st);
			if (ret < 0) {
				ret = -ret;
				goto errout_with_direntry;
			} else if (!S_ISDIR(st.st_mode)) {
				ret = ENOTDIR;
				goto errout_with_direntry;
			}
		} else {
			ret = ENOSYS;
			goto errout_with_direntry;
		}

		dir->fd_root = inode;	/* Save the inode where we start */

		/* Open the directory at the relative path */

		ret = open_mountpoint(inode, relpath, dir);
		if (ret != OK) {
			goto errout_with_direntry;
		}
	}
#endif
	else {
		/* The node is part of the root pseudo file system.  Does the inode
		 * have a child? If so that the child would be the 'root' of a list
		 * of nodes under the directory.
		 */

		ret = inode_stat(inode, &st);
		if (!S_ISDIR(st.st_mode)) {
			ret = ENOTDIR;
			goto errout_with_direntry;
		}

		FAR struct inode *child = inode->i_child;
		if (child) {
			/* It looks we have a valid pseudo-filesystem directory node. */

			open_pseudodir(child, dir);
		} else if (!inode->u.i_ops) {
			/* This is a dangling node with no children and no operations. Set
			 * up to enumerate an empty directory.
			 */

			open_emptydir(dir);
		} else {
			ret = ENOTDIR;
			goto errout_with_direntry;
		}
	}

	inode_semgive();
	return ((DIR *)dir);

	/* Nasty goto's make error handling simpler */

errout_with_direntry:
	kumm_free(dir);

errout_with_semaphore:
	inode_semgive();
	set_errno(ret);
	return NULL;
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
 * fs/dirent/fs_readdir.c
 *
 *   Copyright (C) 2007-2009, 2011 Gregory Nutt. All rights reserved.
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

#include <string.h>
#include <dirent.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include <tinyara/fs/dirent.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: readpseudodir
 ****************************************************************************/

static inline int readpseudodir(struct fs_dirent_s *idir)
{
	FAR struct inode *prev;

	/* Check if we are at the end of the list */

	if (!idir->u.pseudo.fd_next) {
		/* End of file and error conditions are not distinguishable
		 * with readdir.  Here we return -ENOENT to signal the end
		 * of the directory.
		 */

		return -ENOENT;
	}

	/* Copy the inode name into the dirent structure */

	strncpy(idir->fd_dir.d_name, idir->u.pseudo.fd_next->i_name, NAME_MAX + 1);

	/* If the node has file operations, we will say that it is
	 * a file.
	 */

	idir->fd_dir.d_type = 0;
	if (idir->u.pseudo.fd_next->u.i_ops) {
#ifndef CONFIG_DISABLE_MOUNTPOINT
		if (INODE_IS_BLOCK(idir->u.pseudo.fd_next)) {
			idir->fd_dir.d_type |= DTYPE_BLK;
		}
		if (INODE_IS_MOUNTPT(idir->u.pseudo.fd_next)) {
			idir->fd_dir.d_type |= DTYPE_DIRECTORY;
		} else
#endif
		{
			idir->fd_dir.d_type |= DTYPE_CHR;
		}
	}

	/* If the node has child node(s) or no operations, then we will say that
	 * it is a directory rather than a special file.  NOTE: that the node can
	 * be both!
	 */

	if (idir->u.pseudo.fd_next->i_child || !idir->u.pseudo.fd_next->u.i_ops) {
		idir->fd_dir.d_type |= DTYPE_DIRECTORY;
	}

	/* Now get the inode to vist next time that readdir() is called */

	inode_semtake();

	prev = idir->u.pseudo.fd_next;
	idir->u.pseudo.fd_next = prev->i_peer;	/* The next node to visit */

	if (idir->u.pseudo.fd_next) {
		/* Increment the reference count on this next node */

		idir->u.pseudo.fd_next->i_crefs++;
	}

	inode_semgive();

	if (prev) {
		inode_release(prev);
	}

	return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: readdir
 *
 * Description:
 *   The readdir() function returns a pointer to a dirent structure
 *   representing the next directory entry in the directory stream pointed
 *   to by dir.  It returns NULL on reaching the end-of-file or if an error
 *   occurred.
 *
 * Inputs:
 *   dirp -- An instance of type DIR created by a previous call to opendir();
 *
 * Return:
 *   The readdir() function returns a pointer to a dirent structure, or NULL
 *   if an error occurs or end-of-file is reached.  On error, errno is set
 *   appropriately.
 *
 *   EBADF   - Invalid directory stream descriptor dir
 *
 ****************************************************************************/

FAR struct dirent *readdir(DIR *dirp)
{
	FAR struct fs_dirent_s *idir = (struct fs_dirent_s *)dirp;
	struct inode *inode;
	int ret;

	/* Verify that we were provided with a valid directory structure */

	if (!idir) {
		ret = EBADF;
		goto errout;
	}

	/* A special case is when we enumerate an "empty", unused inode.  That is
	 * an inode in the pseudo-filesystem that has no operations and no children.
	 * This is a "dangling" directory entry that has lost its children.
	 */

	inode = idir->fd_root;
	if (!inode) {
		/* End of file and error conditions are not distinguishable
		 * with readdir.  We return NULL to signal either case.
		 */

		ret = OK;
		goto errout;
	}

	/* The way we handle the readdir depends on the type of inode
	 * that we are dealing with.
	 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	if (INODE_IS_MOUNTPT(inode) && !DIRENT_ISPSEUDONODE(idir->fd_flags)) {
		/* The node is a file system mointpoint. Verify that the mountpoint
		 * supports the readdir() method
		 */

		if (!inode->u.i_mops || !inode->u.i_mops->readdir) {
			ret = EACCES;
			goto errout;
		}

		/* Perform the readdir() operation */

		ret = inode->u.i_mops->readdir(inode, idir);
	} else
#endif
	{
		/* The node is part of the root pseudo file system */

		ret = readpseudodir(idir);
	}

	/* ret < 0 is an error.  Special case: ret = -ENOENT is end of file */

	if (ret < 0) {
		if (ret == -ENOENT) {
			ret = OK;
		} else {
			ret = -ret;
		}

		goto errout;
	}

	/* Success */

	idir->fd_position++;
	return &idir->fd_dir;

errout:
	set_errno(ret);
	return NULL;
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
 * fs/dirent/fs_rewinddir.c
 *
 *   Copyright (C) 2007-2009, 2011, 2014 Gregory Nutt. All rights reserved.
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

#include <dirent.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include <tinyara/fs/dirent.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rewindpseudodir
 ****************************************************************************/

static inline void rewindpseudodir(struct fs_dirent_s *idir)
{
	struct inode *prev;

	inode_semtake();

	/* Reset the position to the beginning */

	prev = idir->u.pseudo.fd_next;	/* (Save to delete later) */
	idir->u.pseudo.fd_next = idir->fd_root;	/* The next node to visit */
	idir->fd_position = 0;		/* Reset position */

	/* Increment the reference count on the root=next node.  We
	 * should now have two references on the inode.
	 */

	idir->fd_root->i_crefs++;
	inode_semgive();

	/* Then release the reference to the old next inode */

	if (prev) {
		inode_release(prev);
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rewinddir
 *
 * Description:
 *   The  rewinddir() function resets the position of the
 *   directory stream dir to the beginning of the directory.
 *
 * Inputs:
 *   dirp -- An instance of type DIR created by a previous
 *     call to opendir();
 *
 * Return:
 *   None
 *
 ****************************************************************************/

void rewinddir(FAR DIR *dirp)
{
	struct fs_dirent_s *idir = (struct fs_dirent_s *)dirp;
#ifndef CONFIG_DISABLE_MOUNTPOINT
	struct inode *inode;
#endif

	/* Verify that we were provided with a valid directory structure,
	 * A special case is when we enumerate an "empty", unused inode (fd_root
	 * == 0).  That is an inode in the pseudo-filesystem that has no
	 * operations and no children.  This is a "dangling" directory entry that
	 * has lost its children.
	 */

	if (!idir || !idir->fd_root) {
		return;
	}

	/* The way we handle the readdir depends on the type of inode
	 * that we are dealing with.
	 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	inode = idir->fd_root;
	if (INODE_IS_MOUNTPT(inode)) {
		/* The node is a file system mointpoint. Verify that the mountpoint
		 * supports the rewinddir() method
		 */

		if (inode->u.i_mops && inode->u.i_mops->rewinddir) {
			/* Perform the rewinddir() operation */

			inode->u.i_mops->rewinddir(inode, idir);
		}
	} else
#endif
	{
		/* The node is part of the root pseudo file system */

		rewindpseudodir(idir);
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
 * fs/dirent/fs_seekdir.c
 *
 *   Copyright (C) 2007, 2008, 2011, 2014 Gregory Nutt. All rights reserved.
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
#include <dirent.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include <tinyara/fs/dirent.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: seekpseudodir
 ****************************************************************************/

static inline void seekpseudodir(struct fs_dirent_s *idir, off_t offset)
{
	struct inode *curr;
	struct inode *prev;
	off_t pos;

	/* Determine a starting point for the seek.  If the seek
	 * is "forward" from the current position, then we will
	 * start at the current poisition.  Otherwise, we will
	 * "rewind" to the root dir.
	 */

	if (offset < idir->fd_position) {
		pos = 0;
		curr = idir->fd_root;
	} else {
		pos = idir->fd_position;
		curr = idir->u.pseudo.fd_next;
	}

	/* Traverse the peer list starting at the 'root' of the
	 * the list until we find the node at 'offset".  If devices
	 * are being registered and unregistered, then this can
	 * be a very unpredictable operation.
	 */

	inode_semtake();
	for (; curr && pos != offset; pos++, curr = curr->i_peer) ;

	/* Now get the inode to vist next time that readdir() is called */

	prev = idir->u.pseudo.fd_next;
	idir->u.pseudo.fd_next = curr;	/* The next node to visit (might be null) */
	idir->fd_position = pos;	/* Might be beyond the last dirent */

	if (curr) {
		/* Increment the reference count on this next node */

		curr->i_crefs++;
	}

	inode_semgive();

	if (prev) {
		inode_release(prev);
	}
}

/****************************************************************************
 * Name: seekmountptdir
 ****************************************************************************/

#ifndef CONFIG_DISABLE_MOUNTPOINT
static inline void seekmountptdir(struct fs_dirent_s *idir, off_t offset)
{
	struct inode *inode;
	off_t pos;

	/* Determine a starting point for the seek.  If the seek
	 * is "forward" from the current position, then we will
	 * start at the current poisition.  Otherwise, we will
	 * "rewind" to the root dir.
	 */

	inode = idir->fd_root;
	if (offset < idir->fd_position) {
		if (inode->u.i_mops && inode->u.i_mops->rewinddir) {
			/* Perform the rewinddir() operation */

			inode->u.i_mops->rewinddir(inode, idir);
			pos = 0;
		} else {
			/* We can't do the seek and there is no way to return
			 * an error indication.
			 */

			return;
		}
	} else {
		pos = idir->fd_position;
	}

	/* This is a brute force approach... we will just read
	 * directory entries until we are at the desired position.
	 */

	while (pos < offset) {
		if (!inode->u.i_mops || !inode->u.i_mops->readdir || inode->u.i_mops->readdir(inode, idir) < 0) {
			/* We can't read the next entry and there is no way to return
			 * an error indication.
			 */

			return;
		}

		/* Increment the position on each successful read */

		pos++;
	}

	/* If we get here the directory position has been successfully set */

	idir->fd_position = pos;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: seekdir
 *
 * Description:
 *   The seekdir() function sets the location in the directory stream from
 *   which the next readdir() call will start.  seekdir() should be used with
 *   an offset returned by telldir().
 *
 * Inputs:
 *   dirp -- An instance of type DIR created by a previous
 *     call to opendir();
 *   offset -- offset to seek to
 *
 * Return:
 *   None
 *
 ****************************************************************************/

void seekdir(FAR DIR *dirp, off_t offset)
{
	struct fs_dirent_s *idir = (struct fs_dirent_s *)dirp;

	/* Verify that we were provided with a valid directory structure,
	 * A special case is when we enumerate an "empty", unused inode (fd_root
	 * == 0).  That is an inode in the pseudo-filesystem that has no
	 * operations and no children.  This is a "dangling" directory entry that
	 * has lost its children.
	 */

	if (!idir || !idir->fd_root) {
		return;
	}

	/* The way we handle the readdir depends on the type of inode
	 * that we are dealing with.
	 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	if (INODE_IS_MOUNTPT(idir->fd_root)) {
		/* The node is a file system mointpoint */

		seekmountptdir(idir, offset);
	} else
#endif
	{
		/* The node is part of the root pseudo file system */

		seekpseudodir(idir, offset);
	}
}
