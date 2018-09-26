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
 * fs/vfs/fs_close.c
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

#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <tinyara/fs/fs.h>
#include <tinyara/cancelpt.h>

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
#include <tinyara/net/net.h>
#endif

#include "inode/inode.h"

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: close
 *
 * Description:
 *   close() closes a file descriptor, so that it no longer refers to any
 *   file and may be reused. Any record locks (see fcntl(2)) held on the file
 *   it was associated with, and owned by the process, are removed (regardless
 *   of the file descriptor that was used to obtain the lock).
 *
 *   If fd is the last copy of a particular file descriptor the resources
 *   associated with it are freed; if the descriptor was the last reference
 *   to a file which has been removed using unlink(2) the file is deleted.
 *
 * Parameters:
 *   fd   file descriptor to close
 *
 * Returned Value:
 *   0 on success; -1 on error with errno set appropriately.
 *
 * Assumptions:
 *
 ****************************************************************************/

int close(int fd)
{
	int err;
#if (CONFIG_NFILE_DESCRIPTORS > 0) || (CONFIG_NSOCKET_DESCRIPTORS > 0)
	int ret;
#endif
	/* close() is a cancellation point */
	(void)enter_cancellation_point();

#if CONFIG_NFILE_DESCRIPTORS > 0
	/* Did we get a valid file descriptor? */

	if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS)
#endif
	{
		/* Close a socket descriptor */

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
		if ((unsigned int)fd < (CONFIG_NFILE_DESCRIPTORS + CONFIG_NSOCKET_DESCRIPTORS)) {
			ret = net_close(fd);
			leave_cancellation_point();
			return ret;
		} else
#endif
		{
			err = EBADF;
			goto errout;
		}
	}
#if CONFIG_NFILE_DESCRIPTORS > 0
	/* Close the driver or mountpoint.  NOTES: (1) there is no
	 * exclusion mechanism here , the driver or mountpoint must be
	 * able to handle concurrent operations internally, (2) The driver
	 * may have been opened numerous times (for different file
	 * descriptors) and must also handle being closed numerous times.
	 * (3) for the case of the mountpoint, we depend on the close
	 * methods bing identical in signature and position in the operations
	 * vtable.
	 */

	ret = files_close(fd);
	if (ret < 0) {
		/* An error occurred while closing the driver */

		err = -ret;
		goto errout;
	}
	leave_cancellation_point();
	return OK;

#endif

errout:
	set_errno(err);
	leave_cancellation_point();
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
 * fs/vfs/fs_dup.c
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

#include <unistd.h>
#include <sched.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: dup
 *
 * Description:
 *   Clone a file or socket descriptor to an arbitray descriptor number
 *
 ****************************************************************************/

int dup(int fd)
{
	int ret = OK;

	/* Check the range of the descriptor to see if we got a file or a socket
	 * descriptor. */

#if CONFIG_NFILE_DESCRIPTORS > 0
	if ((unsigned int)fd < CONFIG_NFILE_DESCRIPTORS) {
		/* Its a valid file descriptor.. dup the file descriptor using any
		 * other file descriptor*/

		ret = fs_dupfd(fd, 0);
	} else
#endif
	{
		/* Not a valid file descriptor.  Did we get a valid socket descriptor? */

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
		if ((unsigned int)fd < (CONFIG_NFILE_DESCRIPTORS + CONFIG_NSOCKET_DESCRIPTORS)) {
			/* Yes.. dup the socket descriptor */

			ret = net_dupsd(fd);
		} else
#endif
		{
			/* No.. then it is a bad descriptor number */

			set_errno(EBADF);
			ret = ERROR;
		}
	}

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
 * fs/vfs/fs_dup2.c
 *
 *   Copyright (C) 2007-2009, 2011, 2013 Gregory Nutt. All rights reserved.
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

#include <unistd.h>
#include <sched.h>
#include <errno.h>

#include "inode/inode.h"

/* This logic in this applies only when both socket and file descriptors are
 * in that case, this function descriminates which type of dup2 is being
 * performed.
 */

#if CONFIG_NFILE_DESCRIPTORS > 0 && defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: dup2
 *
 * Description:
 *   Clone a file descriptor or socket descriptor to a specific descriptor
 *   number
 *
 ****************************************************************************/

int dup2(int fd1, int fd2)
{
	/* Check the range of the descriptor to see if we got a file or a socket
	 * descriptor.
	 */

	if ((unsigned int)fd1 >= CONFIG_NFILE_DESCRIPTORS) {
		/* Not a valid file descriptor.  Did we get a valid socket descriptor? */

		if ((unsigned int)fd1 < (CONFIG_NFILE_DESCRIPTORS + CONFIG_NSOCKET_DESCRIPTORS)) {
			/* Yes.. dup the socket descriptor */

			return net_dupsd2(fd1, fd2);
		} else {
			/* No.. then it is a bad descriptor number */

			set_errno(EBADF);
			return ERROR;
		}
	} else {
		/* Its a valid file descriptor.. dup the file descriptor */

		return fs_dupfd2(fd1, fd2);
	}
}

#endif							/* CONFIG_NFILE_DESCRIPTORS > 0 ... */
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
 * fs/vfs/fs_dupfd.c
 *
 *   Copyright (C) 2007-2009, 2011-2014 Gregory Nutt. All rights reserved.
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

#include <sched.h>
#include <errno.h>
#include <assert.h>

#include <tinyara/fs/fs.h>

#include "inode/inode.h"

#if CONFIG_NFILE_DESCRIPTORS > 0

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fs_dupfd OR dup
 *
 * Description:
 *   Clone a file descriptor 'fd' to an arbitray descriptor number (any value
 *   greater than or equal to 'minfd'). If socket descriptors are
 *   implemented, then this is called by dup() for the case of file
 *   descriptors.  If socket descriptors are not implemented, then this
 *   function IS dup().
 *
 ****************************************************************************/

int fs_dupfd(int fd, int minfd)
{
	FAR struct file *filep;

	/* Get the file structure corresponding to the file descriptor. */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */

		return ERROR;
	}

	/* Let file_dup() do the real work */

	return file_dup(filep, minfd);
}

#endif							/* CONFIG_NFILE_DESCRIPTORS > 0 */
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
 * fs/vfs/fs_dupfd2.c
 *
 *   Copyright (C) 2007-2009, 2011-2014 Gregory Nutt. All rights reserved.
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

#include <unistd.h>
#include <sched.h>
#include <errno.h>

#include "inode/inode.h"

#if CONFIG_NFILE_DESCRIPTORS > 0

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define DUP_ISOPEN(filep) (filep->f_inode != NULL)

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fs_dupfd2 OR dup2
 *
 * Description:
 *   Clone a file descriptor to a specific descriptor number. If socket
 *   descriptors are implemented, then this is called by dup2() for the
 *   case of file descriptors.  If socket descriptors are not implemented,
 *   then this function IS dup2().
 *
 ****************************************************************************/

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
int fs_dupfd2(int fd1, int fd2)
#else
int dup2(int fd1, int fd2)
#endif
{
	FAR struct file *filep1;
	FAR struct file *filep2;

	/* Get the file structures corresponding to the file descriptors. */

	filep1 = fs_getfilep(fd1);
	filep2 = fs_getfilep(fd2);

	if (!filep1 || !filep2) {
		/* The errno value has already been set */

		return ERROR;
	}

	/* Verify that fd1 is a valid, open file descriptor */

	if (!DUP_ISOPEN(filep1)) {
		set_errno(EBADF);
		return ERROR;
	}

	/* Handle a special case */

	if (fd1 == fd2) {
		return fd1;
	}

	/* Perform the dup2 operation */

	return file_dup2(filep1, filep2);
}

#endif							/* CONFIG_NFILE_DESCRIPTORS > 0 */
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
 * fs/vfs/fs_fcntl.c
 *
 *   Copyright (C) 2009, 2012-2014 Gregory Nutt. All rights reserved.
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

#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

#include <tinyara/fs/fs.h>
#include <tinyara/net/net.h>
#include <tinyara/sched.h>
#include <tinyara/cancelpt.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: file_vfcntl
 *
 * Description:
 *   Similar to the standard vfcntl function except that is accepts a struct
 *   struct file instance instead of a file descriptor.  Currently used
 *   only by aio_fcntl();
 *
 ****************************************************************************/

#if CONFIG_NFILE_DESCRIPTORS > 0
int file_vfcntl(FAR struct file *filep, int cmd, va_list ap)
{
	int err = 0;
	int ret = OK;

	/* Was this file opened ? */

	if (!filep->f_inode) {
		err = EBADF;
		goto errout;
	}

	switch (cmd) {
	case F_DUPFD:
		/* Return a new file descriptor which shall be the lowest numbered
		 * available (that is, not already open) file descriptor greater than
		 * or equal to the third argument, arg, taken as an integer of type
		 * int. The new file descriptor shall refer to the same open file
		 * description as the original file descriptor, and shall share any
		 * locks.  The FD_CLOEXEC flag associated  with the new file descriptor
		 * shall be cleared to keep the file open across calls to one of the
		 * exec functions.
		 */

	{
		ret = file_dup(filep, va_arg(ap, int));
	}
	break;

	case F_GETFD:
	/* Get the file descriptor flags defined in <fcntl.h> that are associated
	 * with the file descriptor fd.  File descriptor flags are associated
	 * with a single file descriptor and do not affect other file descriptors
	 * that refer to the same file.
	 */

	case F_SETFD:
		/* Set the file descriptor flags defined in <fcntl.h>, that are associated
		 * with fd, to the third argument, arg, taken as type int. If the
		 * FD_CLOEXEC flag in the third argument is 0, the file shall remain open
		 * across the exec functions; otherwise, the file shall be closed upon
		 * successful execution of one  of  the  exec  functions.
		 */

		err = ENOSYS;
		break;

	case F_GETFL:
		/* Get the file status flags and file access modes, defined in <fcntl.h>,
		 * for the file description associated with fd. The file access modes
		 * can be extracted from the return value using the mask O_ACCMODE, which is
		 * defined  in <fcntl.h>. File status flags and file access modes are associated
		 * with the file description and do not affect other file descriptors that
		 * refer to the same file with different open file descriptions.
		 */

	{
		ret = filep->f_oflags;
	}
	break;

	case F_SETFL:
		/* Set the file status flags, defined in <fcntl.h>, for the file description
		 * associated with fd from the corresponding  bits in the third argument,
		 * arg, taken as type int. Bits corresponding to the file access mode and
		 * the file creation flags, as defined in <fcntl.h>, that are set in arg shall
		 * be ignored. If any bits in arg other than those mentioned here are changed
		 * by the application, the result is unspecified.
		 */

	{
		int oflags = va_arg(ap, int);

		oflags &= FFCNTL;
		filep->f_oflags &= ~FFCNTL;
		filep->f_oflags |= oflags;
	}
	break;

	case F_GETOWN:
	/* If fd refers to a socket, get the process or process group ID specified
	 * to receive SIGURG signals when out-of-band data is available. Positive values
	 * indicate a process ID; negative values, other than -1, indicate a process group
	 * ID. If fd does not refer to a socket, the results are unspecified.
	 */

	case F_SETOWN:
		/* If fd refers to a socket, set the process or process group ID specified
		 * to receive SIGURG signals when out-of-band data is available, using the value
		 * of the third argument, arg, taken as type int. Positive values indicate a
		 * process ID; negative values, other than -1, indicate a process group ID. If
		 * fd does not refer to a socket, the results are unspecified.
		 */

		err = EBADF;			/* Only valid on socket descriptors */
		break;

	case F_GETLK:
	/* Get the first lock which blocks the lock description pointed to by the third
	 * argument, arg, taken as a pointer to type struct flock, defined in <fcntl.h>.
	 * The information retrieved shall overwrite the information passed to fcntl() in
	 * the structure flock. If no lock is found that would prevent this lock from being
	 * created, then the structure shall be left unchanged except for the lock type
	 * which shall be set to F_UNLCK.
	 */

	case F_SETLK:
	/* Set or clear a file segment lock according to the lock description pointed to
	 * by the third argument, arg, taken as a pointer to type struct flock, defined in
	 * <fcntl.h>. F_SETLK can establish shared (or read) locks (F_RDLCK) or exclusive
	 * (or write) locks (F_WRLCK), as well  as  to  remove  either  type  of  lock  (F_UNLCK).
	 * F_RDLCK, F_WRLCK, and F_UNLCK are defined in <fcntl.h>. If a shared or exclusive
	 * lock cannot be set, fcntl() shall return immediately with a return value of -1.
	 */

	case F_SETLKW:
		/* This command shall be equivalent to F_SETLK except that if a shared or exclusive
		 * lock is blocked by other locks, the thread shall wait until the request can be
		 * satisfied. If a signal that is to be caught is received while fcntl() is waiting
		 * for a region, fcntl() shall be interrupted. Upon return from the signal handler,
		 * fcntl() shall return -1 with errno set to [EINTR], and the lock operation shall
		 * not be done.
		 */

		err = ENOSYS;			/* Not implemented */
		break;

	default:
		err = EINVAL;
		break;
	}

errout:
	if (err != 0) {
		set_errno(err);
		return ERROR;
	}

	return ret;
}
#endif							/* CONFIG_NFILE_DESCRIPTORS > 0 */

/****************************************************************************
 * Name: fcntl
 ****************************************************************************/

int fcntl(int fd, int cmd, ...)
{
	FAR struct file *filep;
	va_list ap;
	int ret;

	/* fcntl() is a cancellation point */
	(void)enter_cancellation_point();

	/* Setup to access the variable argument list */

	va_start(ap, cmd);

	/* Did we get a valid file descriptor? */

#if CONFIG_NFILE_DESCRIPTORS > 0
	if ((unsigned int)fd < CONFIG_NFILE_DESCRIPTORS) {
		/* Get the file structure corresponding to the file descriptor. */

		filep = fs_getfilep(fd);
		if (!filep) {
			/* The errno value has already been set */

			va_end(ap);
			leave_cancellation_point();
			return ERROR;
		}

		/* Let file_vfcntl() do the real work */

		ret = file_vfcntl(filep, cmd, ap);
	} else
#endif
	{
		/* No... check for operations on a socket descriptor */

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
		if ((unsigned int)fd < (CONFIG_NFILE_DESCRIPTORS + CONFIG_NSOCKET_DESCRIPTORS)) {
			/* Yes.. defer socket descriptor operations to net_vfcntl() */
			ret = net_vfcntl(fd, cmd, ap);
		} else
#endif
		{
			/* No.. this descriptor number is out of range */

			set_errno(EBADF);
			ret = ERROR;
		}
	}

	va_end(ap);
	leave_cancellation_point();
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
 * fs/vfs/fs_fdopen.c
 *
 *   Copyright (C) 2007-2014 Gregory Nutt. All rights reserved.
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
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>

#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>
#include <tinyara/net/net.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fs_checkfd
 *
 * Description:
 *   Check if the file descriptor is valid for the provided TCB and if it
 *   supports the requested access.
 *
 ****************************************************************************/

#if CONFIG_NFILE_DESCRIPTORS > 0
static inline int fs_checkfd(FAR struct tcb_s *tcb, int fd, int oflags)
{
	FAR struct file *filep;
	FAR struct inode *inode;

	DEBUGASSERT(tcb && tcb->group);

	/* Get the file structure corresponding to the file descriptor. */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */

		return ERROR;
	}

	/* Get the inode associated with the file descriptor.  This should
	 * normally be the case if fd >= 0.  But not in the case where the
	 * called attempts to explicitly stdin with fdopen(0) but stdin has
	 * been closed.
	 */

	inode = filep->f_inode;
	if (!inode) {
		/* No inode -- descriptor does not correspond to an open file */

		return -ENOENT;
	}

	/* Make sure that the inode supports the requested access.  In
	 * the case of fdopen, we are not actually creating the file -- in
	 * particular w and w+ do not truncate the file and any files have
	 * already been created.
	 */

	if (inode_checkflags(inode, oflags) != OK) {
		/* Cannot support the requested access */

		return -EACCES;
	}

	/* Looks good to me */

	return OK;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fs_fdopen
 *
 * Description:
 *   This function does the core operations for fopen and fdopen.
 *
 ****************************************************************************/

FAR struct file_struct *fs_fdopen(int fd, int oflags, FAR struct tcb_s *tcb)
{
	FAR struct streamlist *slist;
	FAR FILE *stream;
	int err = OK;
	int ret;
	int i;

	/* Check input parameters */

	if (fd < 0) {
		err = EBADF;
		goto errout;
	}

	/* A NULL TCB pointer means to use this threads TCB.  This is a little
	 * hack the let's this function be called from user-space (via a syscall)
	 * without having access to the TCB.
	 */

	if (!tcb) {
		tcb = sched_self();
	}

	DEBUGASSERT(tcb && tcb->group);

	/* Verify that this is a valid file/socket descriptor and that the
	 * requested access can be support.
	 *
	 * Is this fd in the range of valid file descriptors?  Socket descriptors
	 * lie in a different range.
	 */

#if CONFIG_NFILE_DESCRIPTORS > 0
	if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS)
#endif
	{
		/* No.. If networking is enabled then this might be a socket
		 * descriptor.
		 */

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
		ret = net_checksd(fd, oflags);
#else
		/* No networking... it is just a bad descriptor */

		err = EBADF;
		goto errout;
#endif
	}

	/* The descriptor is in a valid range to file descriptor... perform some more checks */

#if CONFIG_NFILE_DESCRIPTORS > 0
	else {
		ret = fs_checkfd(tcb, fd, oflags);
	}
#endif

	/* Do we have a good descriptor of some sort? */

	if (ret < 0) {
		/* No... return the reported error */

		err = -ret;
		goto errout;
	}

	/* Get the stream list from the TCB */

#if (defined(CONFIG_BUILD_PROTECTED) || defined(CONFIG_BUILD_KERNEL)) && \
	 defined(CONFIG_MM_KERNEL_HEAP)
	slist = tcb->group->tg_streamlist;
#else
	slist = &tcb->group->tg_streamlist;
#endif

	/* Find an unallocated FILE structure in the stream list */

	ret = sem_wait(&slist->sl_sem);
	if (ret != OK) {
		goto errout_with_errno;
	}

	for (i = 0; i < CONFIG_NFILE_STREAMS; i++) {
		stream = &slist->sl_streams[i];
		if (stream->fs_fd < 0) {
			/* Zero the structure */

			memset(stream, 0, sizeof(FILE));

#if CONFIG_STDIO_BUFFER_SIZE > 0
			/* Initialize the semaphore the manages access to the buffer */

			(void)sem_init(&stream->fs_sem, 0, 1);

			/* Allocate the IO buffer at the appropriate privilege level for
			 * the group.
			 */

			stream->fs_bufstart = group_malloc(tcb->group, CONFIG_STDIO_BUFFER_SIZE);

			if (!stream->fs_bufstart) {
				err = ENOMEM;
				goto errout_with_sem;
			}

			/* Set up pointers */

			stream->fs_bufend = &stream->fs_bufstart[CONFIG_STDIO_BUFFER_SIZE];
			stream->fs_bufpos = stream->fs_bufstart;
			stream->fs_bufread = stream->fs_bufstart;
#endif
			/* Save the file description and open flags.  Setting the
			 * file descriptor locks this stream.
			 */

			stream->fs_fd = fd;
			stream->fs_oflags = (uint16_t)oflags;

			sem_post(&slist->sl_sem);
			return stream;
		}
	}

	/* No free stream available.. report ENFILE */

	err = ENFILE;

#if CONFIG_STDIO_BUFFER_SIZE > 0
errout_with_sem:
#endif
	sem_post(&slist->sl_sem);

errout:
	set_errno(err);
errout_with_errno:
	return NULL;
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
 * fs/vfs/fs_fstat.c
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
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

#include <unistd.h>
#include <sched.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include "inode/inode.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fstat
 *
 * Description:
 *   The fstat() function will obtain information about an open file
 *   associated with the file descriptor 'fd', and will write it to the area
 *   pointed to by 'buf'.
 *
 *   The 'buf' argument is a pointer to a stat structure, as defined in
 *   <sys/stat.h>, into which information is placed concerning the file.
 *
 * Input Parameters:
 *   fd  - The file descriptor associated with the open file of interest
 *   buf - The caller provide location in which to return information about
 *         the open file.
 *
 * Returned Value:
 *   Upon successful completion, 0 shall be returned. Otherwise, -1 shall be
 *   returned and errno set to indicate the error.
 *
 ****************************************************************************/

int fstat(int fd, FAR struct stat *buf)
{
	FAR struct file *filep;
	FAR struct inode *inode;
	int ret;

	/* Did we get a valid file descriptor? */
	if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS) {
		/* No networking... it is a bad descriptor in any event */
		set_errno(EBADF);
		return ERROR;
	}

	/* The descriptor is in a valid range to file descriptor... do the
	 * read.	First, get the file structure.	Note that on failure,
	 * fs_getfilep() will set the errno variable. */
	filep = fs_getfilep(fd);
	if (filep == NULL) {
		/* The errno value has already been set */
		return ERROR;
	}

	/* Get the inode from the file structure */
	inode = filep->f_inode;
	DEBUGASSERT(inode != NULL);

	/* The way we handle the stat depends on the type of inode that we
	 * are dealing with. */
#ifndef CONFIG_DISABLE_MOUNTPOINT
	if (INODE_IS_MOUNTPT(inode)) {
		/* The inode is a file system mointpoint. Verify that the mountpoint
		 * supports the fstat() method */
		ret = -ENOSYS;
		if (inode->u.i_mops && inode->u.i_mops->fstat) {
			/* Perform the fstat() operation */
			ret = inode->u.i_mops->fstat(filep, buf);
		}
	} else
#endif
	{
		/* The inode is part of the root pseudo file system. */
		ret = inode_stat(inode, buf);
	}

	/* Check if the fstat operation was successful */
	if (ret < 0) {
		set_errno(-ret);
		return ERROR;
	}

	/* Successfully fstat'ed the file */
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
 * fs/vfs/fs_fstatfs.c
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
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
#include <string.h>
#include <limits.h>
#include <sched.h>
#include <errno.h>

#include "inode/inode.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fstatfs
 *
 * Return: Zero on success; -1 on failure with errno set:
 *
 *   EACCES  Search permission is denied for one of the directories in the
 *           path prefix of path.
 *   EFAULT  Bad address.
 *   ENOENT  A component of the path path does not exist, or the path is an
 *           empty string.
 *   ENOMEM  Out of memory
 *   ENOTDIR A component of the path is not a directory.
 *   ENOSYS  The file system does not support this call.
 *
 ****************************************************************************/

int fstatfs(int fd, FAR struct statfs *buf)
{
	FAR struct file *filep;
	FAR struct inode *inode;
	int ret;

	DEBUGASSERT(buf != NULL);

	/* First, get the file structure.
     * Note that on failure, fs_getfilep() will set the errno variable.
	 */
	filep = fs_getfilep(fd);
	if (filep == NULL) {
		/* The errno value has already been set */
		return ERROR;
	}

	/* Get the inode from the file structure */
	inode = filep->f_inode;
	DEBUGASSERT(inode != NULL);

	/* Check if the file is open */
	if (inode == NULL) {
		/* The descriptor does not refer to an open file. */
		ret = -EBADF;
	} else
#ifndef CONFIG_DISABLE_MOUNTPOINT
	/* The way we handle the stat depends on the type of inode that we
	 * are dealing with. */
	if (INODE_IS_MOUNTPT(inode)) {
		/* The node is a file system mointpoint. Verify that the mountpoint
		 * supports the statfs() method */
		ret = -ENOSYS;
		if (inode->u.i_mops && inode->u.i_mops->statfs) {
			/* Perform the statfs() operation */
			ret = inode->u.i_mops->statfs(inode, buf);
		}
	} else
#endif
	{
		/* The node is part of the root pseudo file system */
		memset(buf, 0, sizeof(struct statfs));
		buf->f_type = PROC_SUPER_MAGIC;
		buf->f_namelen = NAME_MAX;
		ret = OK;
	}

	/* Check if the fstat operation was successful */
	if (ret < 0) {
		set_errno(-ret);
		return ERROR;
	}

	/* Successfully statfs'ed the file */
	return OK;
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
 * fs/vfs/fs_fsync.c
 *
 *   Copyright (C) 2007-2009, 2013-2014 Gregory Nutt. All rights reserved.
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

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>

#include <tinyara/sched.h>
#include <tinyara/cancelpt.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"

#ifndef CONFIG_DISABLE_MOUNTPOINT

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
 * Name: file_fsync
 *
 * Description:
 *   Equivalent to the standard fsync() function except that is accepts a
 *   struct file instance instead of a file descriptor.  Currently used
 *   only by aio_fsync();
 *
 ****************************************************************************/

int file_fsync(FAR struct file *filep)
{
	struct inode *inode;
	int ret;

	/* Was this file opened for write access? */

	if ((filep->f_oflags & O_WROK) == 0) {
		ret = EBADF;
		goto errout;
	}

	/* Is this inode a registered mountpoint? Does it support the
	 * sync operations may be relevant to device drivers but only
	 * the mountpoint operations vtable contains a sync method.
	 */

	inode = filep->f_inode;
	if (!inode || !INODE_IS_MOUNTPT(inode) || !inode->u.i_mops || !inode->u.i_mops->sync) {
		ret = EINVAL;
		goto errout;
	}

	/* Yes, then tell the mountpoint to sync this file */

	ret = inode->u.i_mops->sync(filep);
	if (ret >= 0) {
		return OK;
	}

	ret = -ret;

errout:
	set_errno(ret);
	return ERROR;
}

/****************************************************************************
 * Name: fsync
 *
 * Description:
 *   This func simply binds inode sync methods to the sync system call.
 *
 ****************************************************************************/

int fsync(int fd)
{
	FAR struct file *filep;
	int ret;

	/* fsync() is a cancellation point */
	(void)enter_cancellation_point();

	/* Get the file structure corresponding to the file descriptor. */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */

		leave_cancellation_point();
		return ERROR;
	}

	/* Perform the fsync operation */

	ret = file_fsync(filep);
	leave_cancellation_point();
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
 * fs/vfs/fs_getfilep.c
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
#include <sys/types.h>

#include <unistd.h>
#include <fcntl.h>
#include <sched.h>
#include <errno.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fs_getfilep
 *
 * Description:
 *   Given a file descriptor, return the corresponding instance of struct
 *   file.  NOTE that this function will currently fail if it is provided
 *   with a socket descriptor.
 *
 * Parameters:
 *   fd - The file descriptor
 *
 * Return:
 *   A point to the corresponding struct file instance is returned on
 *   success.  On failure,  NULL is returned and the errno value is
 *   set appropriately (EBADF).
 *
 ****************************************************************************/

FAR struct file *fs_getfilep(int fd)
{
	FAR struct filelist *list;
	int errcode;

	if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS) {
		errcode = EBADF;
		goto errout;
	}

	/* The descriptor is in a valid range to file descriptor... Get the
	 * thread-specific file list.
	 */

	list = sched_getfiles();

	/* The file list can be NULL under one obscure cornercase:  When memory
	 * management debug output is enabled.  Then there may be attempts to
	 * write to stdout from malloc before the group data has been allocated.
	 */

	if (!list) {
		errcode = EAGAIN;
		goto errout;
	}

	/* And return the file pointer from the list */

	return &list->fl_files[fd];

errout:
	set_errno(errcode);
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
 * fs/vfs/fs_ioctl.c
 *
 *   Copyright (C) 2007-2010, 2012-2014 Gregory Nutt. All rights reserved.
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

#include <sys/ioctl.h>
#include <sched.h>
#include <errno.h>
#include <assert.h>

#include <net/if.h>

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
#include <tinyara/net/net.h>
#endif

#include "inode/inode.h"

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: ioctl/fs_ioctl
 *
 * Description:
 *   Perform device specific operations.
 *
 * Parameters:
 *   fd       File/socket descriptor of device
 *   req      The ioctl command
 *   arg      The argument of the ioctl cmd
 *
 * Return:
 *   >=0 on success (positive non-zero values are cmd-specific)
 *   -1 on failure with errno set properly:
 *
 *   EBADF
 *     'fd' is not a valid descriptor.
 *   EFAULT
 *     'arg' references an inaccessible memory area.
 *   EINVAL
 *     'cmd' or 'arg' is not valid.
 *   ENOTTY
 *     'fd' is not associated with a character special device.
 *   ENOTTY
 *      The specified request does not apply to the kind of object that the
 *      descriptor 'fd' references.
 *
 ****************************************************************************/

#ifdef CONFIG_LIBC_IOCTL_VARIADIC
int fs_ioctl(int fd, int req, unsigned long arg)
#else
int ioctl(int fd, int req, unsigned long arg)
#endif
{
	int err;
#if CONFIG_NFILE_DESCRIPTORS > 0
	FAR struct file *filep;
	FAR struct inode *inode;
	int ret = OK;

	/* Did we get a valid file descriptor? */

	if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS)
#endif
	{
		/* Perform the socket ioctl */

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
		if ((unsigned int)fd < (CONFIG_NFILE_DESCRIPTORS + CONFIG_NSOCKET_DESCRIPTORS)) {
			return netdev_ioctl(fd, req, arg);
		} else
#endif
		{
			err = EBADF;
			goto errout;
		}
	}
#if CONFIG_NFILE_DESCRIPTORS > 0
	/* Get the file structure corresponding to the file descriptor. */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */

		return ERROR;
	}

	/* Is a driver registered? Does it support the ioctl method? */

	inode = filep->f_inode;
	if (inode && inode->u.i_ops && inode->u.i_ops->ioctl) {
		/* Yes, then let it perform the ioctl */

		ret = (int)inode->u.i_ops->ioctl(filep, req, arg);
		if (ret < 0) {
			err = -ret;
			goto errout;
		}
	} else {
		err = ENOTTY;
		goto errout;
	}

	return ret;
#endif

errout:
	set_errno(err);
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
 * fs/vfs/fs_lseek.c
 *
 *   Copyright (C) 2008 Gregory Nutt. All rights reserved.
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
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <assert.h>

#include "inode/inode.h"

#if CONFIG_NFILE_DESCRIPTORS > 0

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: file_seek
 *
 * Description:
 *   This is the internal implementation of lseek.  See the comments in
 *   lseek() for further information.
 *
 * Parameters:
 *   file     File structure instance
 *   offset   Defines the offset to position to
 *   whence   Defines how to use offset
 *
 * Return:
 *   The resulting offset on success.  -1 on failure withi errno set
 *   properly (see lseek comments).
 *
 ****************************************************************************/

off_t file_seek(FAR struct file *filep, off_t offset, int whence)
{
	FAR struct inode *inode;
	int ret;
	int err = OK;

	DEBUGASSERT(filep);
	inode = filep->f_inode;

	/* File is not open */

	if (!inode) {
		err = -EBADF;
		goto errout;
	}

	/* Invoke the file seek method if available */

	if (inode->u.i_ops && inode->u.i_ops->seek) {
		ret = (int)inode->u.i_ops->seek(filep, offset, whence);
		if (ret < 0) {
			err = -ret;
			goto errout;
		}
	} else {
		/* No... Just set the common file position value */

		switch (whence) {
		case SEEK_CUR:
			offset += filep->f_pos;

		/* FALLTHROUGH */

		case SEEK_SET:
			if (offset >= 0) {
				filep->f_pos = offset;	/* Might be beyond the end-of-file */
				break;
			} else {
				err = EINVAL;
				goto errout;
			}
			break;

		case SEEK_END:
			err = ENOSYS;
			goto errout;

		default:
			err = EINVAL;
			goto errout;
		}
	}

	return filep->f_pos;

errout:
	set_errno(err);
	return (off_t)ERROR;
}

/****************************************************************************
 * Name: lseek
 *
 * Description:
 *   The lseek() function repositions the offset of the open file associated
 *   with the file descriptor fd to the argument 'offset' according to the
 *   directive 'whence' as follows:
 *
 *   SEEK_SET
 *      The offset is set to offset bytes.
 *   SEEK_CUR
 *      The offset is set to its current location plus offset bytes.
 *   SEEK_END
 *      The offset is set to the size of the file plus offset bytes.
 *
 *  The lseek() function allows the file offset to be set beyond the end of the
 *  file (but this does not change the size of the file). If data is later written
 *  at this point, subsequent reads of the data in the gap (a "hole") return null
 *  bytes ('\0') until data is actually written into the gap.
 *
 * Parameters:
 *   fd       File descriptor of device
 *   offset   Defines the offset to position to
 *   whence   Defines how to use offset
 *
 * Return:
 *   The resulting offset on success.  -1 on failure withi errno set properly:
 *
 *   EBADF      fd is not an open file descriptor.
 *   EINVAL     whence  is  not one of SEEK_SET, SEEK_CUR, SEEK_END; or the
 *              resulting file offset would be negative, or beyond the end of a
 *              seekable device.
 *   EOVERFLOW  The resulting file offset cannot be represented in an off_t.
 *   ESPIPE     fd is associated with a pipe, socket, or FIFO.
 *
 ****************************************************************************/

off_t lseek(int fd, off_t offset, int whence)
{
	FAR struct file *filep;

	/* Get the file structure corresponding to the file descriptor. */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */

		return (off_t)ERROR;
	}

	/* Then let file_seek do the real work */

	return file_seek(filep, offset, whence);
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
 * fs/vfs/fs_mkdir.c
 *
 *   Copyright (C) 2007, 2008, 2014 Gregory Nutt. All rights reserved.
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
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <tinyara/fs/fs.h>
#include <tinyara/kmalloc.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#undef FS_HAVE_WRITABLE_MOUNTPOINT
#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_WRITABLE) && \
	CONFIG_NFILE_STREAMS > 0
#define FS_HAVE_WRITABLE_MOUNTPOINT 1
#endif

#undef FS_HAVE_PSEUDOFS_OPERATIONS
#if !defined(CONFIG_DISABLE_PSEUDOFS_OPERATIONS) && CONFIG_NFILE_STREAMS > 0
#define FS_HAVE_PSEUDOFS_OPERATIONS 1
#endif

#undef FS_HAVE_MKDIR
#if defined(FS_HAVE_WRITABLE_MOUNTPOINT) || defined(FS_HAVE_PSEUDOFS_OPERATIONS)
#define FS_HAVE_MKDIR 1
#endif

#ifdef FS_HAVE_MKDIR

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
 * Name: mkdir
 *
 * Description:  Create a directory
 *
 ****************************************************************************/

int mkdir(const char *pathname, mode_t mode)
{
	FAR struct inode *inode;
	const char *relpath = NULL;
	int errcode;
	int ret;
#ifndef CONFIG_DISABLE_MOUNTPOINT
	FAR char *parent;
	const char *ptr;
	int index;
	int len;
	struct stat st;
#endif

	/* Find the inode that includes this path */

	inode = inode_find(pathname, &relpath);

	if (inode) {
		/* An inode was found that includes this path and possibly refers to a
		 * mountpoint.
		 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
		/* Check if the inode is a valid mountpoint. */

		if (!INODE_IS_MOUNTPT(inode) || !inode->u.i_mops) {
			/* The inode is not a mountpoint */

			errcode = ENXIO;
			goto errout_with_inode;
		}

		ptr = relpath;
		index = 0;
		len = 0;

		while (ptr != NULL && *ptr != '\0') {
			/* Search a path of parent directory */
			if (*ptr == '/') {
				index = len;
			}
			len++;
			ptr++;
		}

		if (index > 0) {
			/* In another directory */
			parent = (FAR char *)kmm_malloc(index + 1);
			if (parent == NULL) {
				ret = ENOMEM;
				goto errout_with_inode;
			}
			memset(parent, 0, index + 1);
			strncpy(parent, relpath, index);

			if (inode->u.i_mops->stat) {
				/* Perform the stat() operation */

				ret = inode->u.i_mops->stat(inode, parent, &st);
				kmm_free(parent);
				if (ret < 0) {
					ret = -ret;
					goto errout_with_inode;
				} else if ((st.st_mode & (S_IWUSR | S_IWGRP | S_IWOTH)) == 0) {
					ret = EACCES;
					goto errout_with_inode;
				}
			} else {
				ret = ENOSYS;
				kmm_free(parent);
				goto errout_with_inode;
			}
		}

		/* Perform the mkdir operation using the relative path
		 * at the mountpoint.
		 */

		if (inode->u.i_mops->mkdir) {
			ret = inode->u.i_mops->mkdir(inode, relpath, mode);
			if (ret < 0) {
				errcode = -ret;
				goto errout_with_inode;
			}
		} else {
			errcode = ENOSYS;
			goto errout_with_inode;
		}

		/* Release our reference on the inode */

		inode_release(inode);
#else
		/* But mountpoints are not supported in this configuration */

		errcode = EEXIST;
		goto errout_with_inode;
#endif
	}
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
	/* No inode exists that contains this path.  Create a new inode in the
	 * pseudo-filesystem at this location.
	 */
	else {
		/* Create an inode in the pseudo-filesystem at this path */

		inode_semtake();
		ret = inode_reserve(pathname, &inode);
		inode_semgive();

		if (ret < 0) {
			errcode = -ret;
			goto errout;
		}
	}
#else
	else {
		errcode = ENXIO;
		goto errout;
	}
#endif

	/* Directory successfully created */

	return OK;

errout_with_inode:
	inode_release(inode);
errout:
	set_errno(errcode);
	return ERROR;
}

#endif							/* FS_HAVE_MKDIR */
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
 * fs/vfs/fs_open.c
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

#include <sys/types.h>
#include <fcntl.h>
#include <sched.h>
#include <errno.h>
#include <assert.h>
#ifdef CONFIG_FILE_MODE
#include <stdarg.h>
#endif

#include <tinyara/cancelpt.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"
#include "driver/block/driver.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: inode_checkflags
 *
 * Description:
 *   Check if the access described by 'oflags' is supported on 'inode'
 *
 ****************************************************************************/

int inode_checkflags(FAR struct inode *inode, int oflags)
{
	if (((oflags & O_RDOK) != 0 && !inode->u.i_ops->read) || ((oflags & O_WROK) != 0 && !inode->u.i_ops->write)) {
		return -EACCES;
	} else {
		return OK;
	}
}

/****************************************************************************
 * Name: open
 *
 * Description:
 *   Standard 'open' interface
 *
 ****************************************************************************/

int open(const char *path, int oflags, ...)
{
	FAR struct file *filep;
	FAR struct inode *inode;
	FAR const char *relpath = NULL;
#if defined(CONFIG_FILE_MODE) || !defined(CONFIG_DISABLE_MOUNTPOINT)
	mode_t mode = 0666;
#endif
	int ret;
	int fd;

#ifdef CONFIG_FILE_MODE
#ifdef CONFIG_CPP_HAVE_WARNING
#warning "File creation not implemented"
#endif

	/* open() is a cancellation point */
	(void)enter_cancellation_point();

	/* If the file is opened for creation, then get the mode bits */

	if ((oflags & (O_WRONLY | O_CREAT)) != 0) {
		va_list ap;
		va_start(ap, oflags);
		mode = va_arg(ap, mode_t);
		va_end(ap);
	}
#endif

	/* Get an inode for this file */

	inode = inode_find(path, &relpath);
	if (!inode) {
		/* "O_CREAT is not set and the named file does not exist.  Or, a
		 * directory component in pathname does not exist or is a dangling
		 * symbolic link."
		 */

		ret = ENOENT;
		goto errout;
	}

#if !defined(CONFIG_DISABLE_MOUNTPOINT) && \
	!defined(CONFIG_DISABLE_PSEUDOFS_OPERATIONS) && defined(CONFIG_BCH)
	/*
	 * If the inode is block driver, then we may return a character driver
	 * proxy for the block driver. block_proxy() will instantiate a BCH
	 * character driver wrapper around the block driver, open(), then
	 * unlink() the character driver. On success, block_proxy() will
	 * return the file descriptor of the opened character driver.
	 *
	 * NOTE: This will recurse to open the character driver proxy.
	 */
	if (INODE_IS_BLOCK(inode)) {
		/* Release the inode reference */
		inode_release(inode);

		/* Get the file descriptor of the opened character driver proxy */
		fd = block_proxy(path, oflags);
		if (fd < 0) {
			ret = -fd;
			goto errout;
		}

		leave_cancellation_point();
		return fd;
	} else
#endif

	/* Verify that the inode is valid and either a "normal" character driver or a
	 * mountpoint.  We specifically exclude block drivers and and "special"
	 * inodes (semaphores, message queues, shared memory).
	 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	if ((!INODE_IS_DRIVER(inode) && !INODE_IS_MOUNTPT(inode)) || !inode->u.i_ops)
#else
	if (!INODE_IS_DRIVER(inode) || !inode->u.i_ops)
#endif
	{
		ret = ENXIO;
		goto errout_with_inode;
	}

	/* Make sure that the inode supports the requested access */

	ret = inode_checkflags(inode, oflags);
	if (ret < 0) {
		ret = -ret;
		goto errout_with_inode;
	}

	/* Associate the inode with a file structure */

	fd = files_allocate(inode, oflags, 0, 0);
	if (fd < 0) {
		ret = EMFILE;
		goto errout_with_inode;
	}

	/* Get the file structure corresponding to the file descriptor. */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */
		leave_cancellation_point();
		return ERROR;
	}

	/* Perform the driver open operation.  NOTE that the open method may be
	 * called many times.  The driver/mountpoint logic should handled this
	 * because it may also be closed that many times.
	 */

	ret = OK;
	if (inode->u.i_ops->open) {
#ifndef CONFIG_DISABLE_MOUNTPOINT
		if (INODE_IS_MOUNTPT(inode)) {
			ret = inode->u.i_mops->open(filep, relpath, oflags, mode);
		} else
#endif
		{
			ret = inode->u.i_ops->open(filep);
		}
	}

	if (ret < 0) {
		ret = -ret;
		goto errout_with_fd;
	}

	leave_cancellation_point();
	return fd;

errout_with_fd:
	files_release(fd);
errout_with_inode:
	inode_release(inode);
errout:
	set_errno(ret);
	leave_cancellation_point();
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
 * fs/vfs/fs_poll.c
 *
 *   Copyright (C) 2008-2009, 2012-2014 Gregory Nutt. All rights reserved.
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

#include <stdint.h>
#include <stdbool.h>
#include <poll.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/sched.h>
#include <tinyara/clock.h>
#include <tinyara/cancelpt.h>
#include <tinyara/semaphore.h>
#include <tinyara/fs/fs.h>

#ifdef CONFIG_NET_LWIP
#include <net/lwip/sockets.h>
#endif

#include <arch/irq.h>

#include "inode/inode.h"

#ifndef CONFIG_DISABLE_POLL

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define poll_semgive(sem) sem_post(sem)

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: poll_semtake
 ****************************************************************************/

static int poll_semtake(FAR sem_t *sem)
{
	/* Take the semaphore (perhaps waiting) */

	if (sem_wait(sem) < 0) {
		int err = get_errno();

		/* The only case that an error should occur here is if the wait were
		 * awakened by a signal.
		 */

		DEBUGASSERT(err == EINTR);
		return -err;
	}

	return OK;
}

/****************************************************************************
 * Name: poll_fdsetup
 *
 * Description:
 *   Configure (or unconfigure) one file/socket descriptor for the poll
 *   operation.  If fds and sem are non-null, then the poll is being setup.
 *   if fds and sem are NULL, then the poll is being torn down.
 *
 ****************************************************************************/

#if CONFIG_NFILE_DESCRIPTORS > 0
static int poll_fdsetup(int fd, FAR struct pollfd *fds, bool setup)
{
	FAR struct file *filep;
	FAR struct inode *inode;
	int ret = -ENOSYS;

	/* Check for a valid file descriptor */

	if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS) {
		/* Perform the socket ioctl */

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
		if ((unsigned int)fd < (CONFIG_NFILE_DESCRIPTORS + CONFIG_NSOCKET_DESCRIPTORS)) {
#ifdef CONFIG_NET_LWIP
			ret = lwip_poll(fd, fds, setup);
			return ret;
#endif
		} else
#endif
		{
			ret = -EBADF;
			return ret;
		}
	}

	/* Get the file pointer corresponding to this file descriptor */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */

		return ERROR;
	}

	inode = filep->f_inode;

	if (inode) {
		/* Is a driver registered? Does it support the poll method?
		 * If not, return -ENOSYS
		 */

		if (INODE_IS_DRIVER(inode) && inode->u.i_ops && inode->u.i_ops->poll) {
			/* Yes, then setup the poll */

			ret = (int)inode->u.i_ops->poll(filep, fds, setup);
		} else if (INODE_IS_MOUNTPT(inode) || INODE_IS_BLOCK(inode)) {
			/* Regular files shall always poll TRUE for reading and writing */

			if (setup) {
				fds->revents |= (fds->events & (POLLIN | POLLOUT));
				if (fds->revents != 0) {
					sem_post(fds->sem);
				}
			}
			ret = OK;
		}
	}

	return ret;
}
#endif

/****************************************************************************
 * Name: poll_setup
 *
 * Description:
 *   Setup the poll operation for each descriptor in the list.
 *
 ****************************************************************************/

#if CONFIG_NFILE_DESCRIPTORS > 0
static inline int poll_setup(FAR struct pollfd *fds, nfds_t nfds, sem_t *sem)
{
	unsigned int i;
	unsigned int j;
	int ret;

	/* Process each descriptor in the list */

	for (i = 0; i < nfds; i++) {
		/* Setup the poll descriptor */

		fds[i].sem = sem;
		fds[i].revents = 0;
		fds[i].priv = NULL;

		/* Check for invalid descriptors. "If the value of fd is less than 0,
		 * events shall be ignored, and revents shall be set to 0 in that entry
		 * on return from poll()."
		 *
		 * NOTE:  There is a potential problem here.  If there is only one fd
		 * and if it is negative, then poll will hang.  From my reading of the
		 * spec, that appears to be the correct behavior.
		 */

		if (fds[i].fd >= 0) {
			/* Set up the poll on this valid file descriptor */

			ret = poll_fdsetup(fds[i].fd, &fds[i], true);
			if (ret < 0) {
				/* Setup failed for fds[i]. We now need to teardown previously
				 * setup fds[0 .. (i - 1)] to release allocated resources and
				 * to prevent memory corruption by access to freed/released 'fds'
				 * and 'sem'.
				 */

				for (j = 0; j < i; j++) {
					(void)poll_fdsetup(fds[j].fd, &fds[j], false);
				}

				/* Indicate an error on the file descriptor */

				fds[i].revents |= POLLERR;
				return ret;
			}
		}
	}

	return OK;
}
#endif

/****************************************************************************
 * Name: poll_teardown
 *
 * Description:
 *   Teardown the poll operation for each descriptor in the list and return
 *   the count of non-zero poll events.
 *
 ****************************************************************************/

#if CONFIG_NFILE_DESCRIPTORS > 0
static inline int poll_teardown(FAR struct pollfd *fds, nfds_t nfds, int *count, int ret)
{
	unsigned int i;
	int status;

	/* Process each descriptor in the list */

	*count = 0;
	for (i = 0; i < nfds; i++) {
		/* Ignore negative descriptors */

		if (fds[i].fd >= 0) {
			/* Teardown the poll */

			status = poll_fdsetup(fds[i].fd, &fds[i], false);
			if (status < 0) {
				ret = status;
			}
		}

		/* Check if any events were posted */

		if (fds[i].revents != 0) {
			(*count)++;
		}

		/* Un-initialize the poll structure */

		fds[i].sem = NULL;
	}

	return ret;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: poll
 *
 * Description:
 *   poll() waits for one of a set of file descriptors to become ready to
 *   perform I/O.  If none of the events requested (and no error) has
 *   occurred for any of  the  file  descriptors,  then  poll() blocks until
 *   one of the events occurs.
 *
 * Inputs:
 *   fds  - List of structures describing file descriptors to be monitored
 *   nfds - The number of entries in the list
 *   timeout - Specifies an upper limit on the time for which poll() will
 *     block in milliseconds.  A negative value of timeout means an infinite
 *     timeout.
 *
 * Return:
 *   On success, the number of structures that have non-zero revents fields.
 *   A value of 0 indicates that the call timed out and no file descriptors
 *   were ready.  On error, -1 is returned, and errno is set appropriately:
 *
 *   EBADF  - An invalid file descriptor was given in one of the sets.
 *   EFAULT - The fds address is invalid
 *   EINTR  - A signal occurred before any requested event.
 *   EINVAL - The nfds value exceeds a system limit.
 *   ENOMEM - There was no space to allocate internal data structures.
 *   ENOSYS - One or more of the drivers supporting the file descriptor
 *     does not support the poll method.
 *
 ****************************************************************************/

int poll(FAR struct pollfd *fds, nfds_t nfds, int timeout)
{
	struct timespec abstime;
	irqstate_t flags;
	sem_t sem;
	int count = 0;
	int ret;

	DEBUGASSERT((fds != NULL));
	/* poll() is a cancellation point */
	(void)enter_cancellation_point();

	/*
	 * This semaphore is used for signaling and, hence, should not have
	 * priority inheritance enabled.
	 */
	sem_init(&sem, 0, 0);
	sem_setprotocol(&sem, SEM_PRIO_NONE);

	ret = poll_setup(fds, nfds, &sem);
	if (ret >= 0) {
		if (timeout == 0) {
			/* Poll returns immediately whether we have a poll event or not. */

			ret = OK;
		} else if (timeout > 0) {
			time_t sec;
			uint32_t nsec;

			/* Either wait for either a poll event(s), for a signal to occur,
			 * or for the specified timeout to elapse with no event.
			 *
			 * NOTE: If a poll event is pending (i.e., the semaphore has already
			 * been incremented), sem_timedwait() will not wait, but will return
			 * immediately.
			 */

			sec = timeout / MSEC_PER_SEC;
			nsec = (timeout - MSEC_PER_SEC * sec) * NSEC_PER_MSEC;

			/* Make sure that the following are atomic by disabling interrupts.
			 * Interrupts will be re-enabled while we are waiting.
			 */

			flags = irqsave();
			(void)clock_gettime(CLOCK_REALTIME, &abstime);

			abstime.tv_sec += sec;
			abstime.tv_nsec += nsec;
			if (abstime.tv_nsec >= NSEC_PER_SEC) {
				abstime.tv_sec++;
				abstime.tv_nsec -= NSEC_PER_SEC;
			}

			ret = sem_timedwait(&sem, &abstime);
			if (ret < 0) {
				int err = get_errno();

				if (err == ETIMEDOUT) {
					/* Return zero (OK) in the event of a timeout */

					ret = OK;
				} else {
					/* EINTR is the only other error expected in normal operation */

					ret = -err;
				}
			}

			irqrestore(flags);
		} else {
			/* Wait for the poll event or signal with no timeout */

			ret = poll_semtake(&sem);
		}

		/* Teardown the poll operation and get the count of events.  Zero will be
		 * returned in the case of a timeout.
		 */

		ret = poll_teardown(fds, nfds, &count, ret);
	}

	sem_destroy(&sem);
	leave_cancellation_point();

	/* Check for errors */

	if (ret < 0) {
		set_errno(-ret);
		return ERROR;
	}

	return count;
}

#endif							/* CONFIG_DISABLE_POLL */
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
 * fs/vfs/fs_pread.c
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

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include <tinyara/cancelpt.h>
#include <tinyara/fs/fs.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: file_pread
 *
 * Description:
 *   Equivalent to the standard pread function except that is accepts a
 *   struct file instance instead of a file descriptor.  Currently used
 *   only by aio_read();
 *
 ****************************************************************************/

ssize_t file_pread(FAR struct file *filep, FAR void *buf, size_t nbytes, off_t offset)
{
	off_t savepos;
	off_t pos;
	ssize_t ret;
	int errcode;

	/* Perform the seek to the current position.  This will not move the
	 * file pointer, but will return its current setting
	 */

	savepos = file_seek(filep, 0, SEEK_CUR);
	if (savepos == (off_t)-1) {
		/* file_seek might fail if this if the media is not seekable */

		return ERROR;
	}

	/* Then seek to the correct position in the file */

	pos = file_seek(filep, offset, SEEK_SET);
	if (pos == (off_t)-1) {
		/* This might fail is the offset is beyond the end of file */

		return ERROR;
	}

	/* Then perform the read operation */

	ret = file_read(filep, buf, nbytes);
	errcode = get_errno();

	/* Restore the file position */

	pos = file_seek(filep, savepos, SEEK_SET);
	if (pos == (off_t)-1 && ret >= 0) {
		/* This really should not fail */

		return ERROR;
	}

	set_errno(errcode);
	return ret;
}

/****************************************************************************
 * Name: pread
 *
 * Description:
 *   The pread() function performs the same action as read(), except that it
 *   reads from a given position in the file without changing the file
 *   pointer. The first three arguments to pread() are the same as read()
 *   with the addition of a fourth argument offset for the desired position
 *   inside the file. An attempt to perform a pread() on a file that is
 *   incapable of seeking results in an error.
 *
 *   NOTE: This function could have been wholly implemented within libc but
 *   it is not.  Why?  Because if pread were implemented in libc, it would
 *   require four system calls.  If it is implemented within the kernel,
 *   only three.
 *
 * Parameters:
 *   file     File structure instance
 *   buf      User-provided to save the data
 *   nbytes   The maximum size of the user-provided buffer
 *   offset   The file offset
 *
 * Return:
 *   The positive non-zero number of bytes read on success, 0 on if an
 *   end-of-file condition, or -1 on failure with errno set appropriately.
 *   See read() return values
 *
 ****************************************************************************/

ssize_t pread(int fd, FAR void *buf, size_t nbytes, off_t offset)
{
	FAR struct file *filep;
	ssize_t ret;

	/* pread() is a cancellation point */
	(void)enter_cancellation_point();

	/* Get the file structure corresponding to the file descriptor. */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */

		ret = (ssize_t)ERROR;
	} else {
		/* Let file_pread do the real work */
		ret = file_pread(filep, buf, nbytes, offset);
	}

	leave_cancellation_point();
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
 * fs/vfs/fs_pwrite.c
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

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include <tinyara/cancelpt.h>
#include <tinyara/fs/fs.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: file_pwrite
 *
 * Description:
 *   Equivalent to the standard pwrite function except that is accepts a
 *   struct file instance instead of a file descriptor.  Currently used
 *   only by aio_write();
 *
 ****************************************************************************/

ssize_t file_pwrite(FAR struct file *filep, FAR const void *buf, size_t nbytes, off_t offset)
{
	off_t savepos;
	off_t pos;
	ssize_t ret;
	int errcode;

	/* Perform the seek to the current position.  This will not move the
	 * file pointer, but will return its current setting
	 */

	savepos = file_seek(filep, 0, SEEK_CUR);
	if (savepos == (off_t)-1) {
		/* file_seek might fail if this if the media is not seekable */

		return ERROR;
	}

	/* Then seek to the correct position in the file */

	pos = file_seek(filep, offset, SEEK_SET);
	if (pos == (off_t)-1) {
		/* This might fail is the offset is beyond the end of file */

		return ERROR;
	}

	/* Then perform the write operation */

	ret = file_write(filep, buf, nbytes);
	errcode = get_errno();

	/* Restore the file position */

	pos = file_seek(filep, savepos, SEEK_SET);
	if (pos == (off_t)-1 && ret >= 0) {
		/* This really should not fail */

		return ERROR;
	}

	set_errno(errcode);
	return ret;
}

/****************************************************************************
 * Name: pwrite
 *
 * Description:
 *   The pwrite() function performs the same action as write(), except that
 *   it writes into a given position without changing the file pointer. The
 *   first three arguments to pwrite() are the same as write() with the
 *   addition of a fourth argument offset for the desired position inside
 *   the file.
 *
 *   NOTE: This function could have been wholly implemented within libc but
 *   it is not.  Why?  Because if pwrite were implemented in libc, it would
 *   require four system calls.  If it is implemented within the kernel,
 *   only three.
 *
 * Parameters:
 *   fd       file descriptor (or socket descriptor) to write to
 *   buf      Data to write
 *   nbytes   Length of data to write
 *
 * Return:
 *   The positive non-zero number of bytes read on success, 0 on if an
 *   end-of-file condition, or -1 on failure with errno set appropriately.
 *   See write() return values
 *
 ****************************************************************************/

ssize_t pwrite(int fd, FAR const void *buf, size_t nbytes, off_t offset)
{
	FAR struct file *filep;
	ssize_t ret;

	/* pwrite() is a cancellation point */
	(void)enter_cancellation_point();

	/* Get the file structure corresponding to the file descriptor. */

	filep = fs_getfilep(fd);
	if (!filep) {
		/* The errno value has already been set */

		ret = (ssize_t)ERROR;
	} else {
		/* Let file_pread do the real work */

		ret = file_pwrite(filep, buf, nbytes, offset);
	}

	leave_cancellation_point();
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
 * fs/vfs/fs_read.c
 *
 *   Copyright (C) 2007-2009, 2012-2014 Gregory Nutt. All rights reserved.
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
#include <sys/socket.h>

#include <unistd.h>
#include <fcntl.h>
#include <sched.h>
#include <errno.h>
#include <tinyara/cancelpt.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: file_read
 *
 * Description:
 *   This is the internal implementation of read().
 *
 * Parameters:
 *   file     File structure instance
 *   buf      User-provided to save the data
 *   nbytes   The maximum size of the user-provided buffer
 *
 * Return:
 *   The positive non-zero number of bytes read on success, 0 on if an
 *   end-of-file condition, or -1 on failure with errno set appropriately.
 *
 ****************************************************************************/

ssize_t file_read(FAR struct file *filep, FAR void *buf, size_t nbytes)
{
	FAR struct inode *inode;
	int ret = -EBADF;

	DEBUGASSERT(filep);
	inode = filep->f_inode;

	/* Was this file opened for read access? */

	if ((filep->f_oflags & O_RDOK) == 0) {
		/* No.. File is not read-able */

		ret = -EACCES;
	}

	/* Is a driver or mountpoint registered? If so, does it support the read
	 * method?
	 */

	else if (inode && inode->u.i_ops && inode->u.i_ops->read) {
		/* Yes.. then let it perform the read.  NOTE that for the case of the
		 * mountpoint, we depend on the read methods being identical in
		 * signature and position in the operations vtable.
		 */

		ret = (int)inode->u.i_ops->read(filep, (char *)buf, (size_t)nbytes);
	}

	/* If an error occurred, set errno and return -1 (ERROR) */

	if (ret < 0) {
		set_errno(-ret);
		return ERROR;
	}

	/* Otherwise, return the number of bytes read */

	return ret;
}

/****************************************************************************
 * Name: read
 *
 * Description:
 *   The standard, POSIX read interface.
 *
 * Parameters:
 *   file     File structure instance
 *   buf      User-provided to save the data
 *   nbytes   The maximum size of the user-provided buffer
 *
 * Return:
 *   The positive non-zero number of bytes read on success, 0 on if an
 *   end-of-file condition, or -1 on failure with errno set appropriately.
 *
 ****************************************************************************/

ssize_t read(int fd, FAR void *buf, size_t nbytes)
{
	ssize_t ret;

	/* read() is a cancellation point */
	(void)enter_cancellation_point();

	/* Did we get a valid file descriptor? */

#if CONFIG_NFILE_DESCRIPTORS > 0
	if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS)
#endif
	{
		/* No.. If networking is enabled, read() is the same as recv() with
		 * the flags parameter set to zero. Note that recv() sets
		 * the errno variables
		 */

#if defined(CONFIG_NET) && CONFIG_NSOCKET_DESCRIPTORS > 0
		ret = recv(fd, buf, nbytes, 0);
#else
		/* No networking... it is a bad descriptor in any event */

		set_errno(EBADF);
		ret = ERROR;
#endif
	}
#if CONFIG_NFILE_DESCRIPTORS > 0
	else {
		FAR struct file *filep;

		/* The descriptor is in a valid range to file descriptor... do the
		 * read.  First, get the file structure. Note that on failure,
		 * fs_getfilep() will set the errno variable.
		 */

		filep = fs_getfilep(fd);
		if (!filep) {
			/* The errno value has already been set */

			ret = ERROR;
		} else {

			/* Then let file_read do all of the work */

			ret = file_read(filep, buf, nbytes);
		}
	}
#endif

	leave_cancellation_point();
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
 * fs/vfs/fs_rename.c
 *
 *   Copyright (C) 2007-2009, 2014 Gregory Nutt. All rights reserved.
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
#include <errno.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#undef FS_HAVE_WRITABLE_MOUNTPOINT
#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_WRITABLE) && \
	CONFIG_NFILE_STREAMS > 0
#define FS_HAVE_WRITABLE_MOUNTPOINT 1
#endif

#undef FS_HAVE_PSEUDOFS_OPERATIONS
#if !defined(CONFIG_DISABLE_PSEUDOFS_OPERATIONS) && CONFIG_NFILE_STREAMS > 0
#define FS_HAVE_PSEUDOFS_OPERATIONS 1
#endif

#undef FS_HAVE_RENAME
#if defined(FS_HAVE_WRITABLE_MOUNTPOINT) || defined(FS_HAVE_PSEUDOFS_OPERATIONS)
#define FS_HAVE_RENAME 1
#endif

#ifdef FS_HAVE_RENAME

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
 * Name: rename
 *
 * Description:  Remove a file managed a mountpoint
 *
 ****************************************************************************/

int rename(FAR const char *oldpath, FAR const char *newpath)
{
	FAR struct inode *oldinode;
	FAR struct inode *newinode;
	const char *oldrelpath = NULL;
#ifndef CONFIG_DISABLE_MOUNTPOINT
	const char *newrelpath = NULL;
#endif
	int errcode;
	int ret;

	/* Ignore paths that are interpreted as the root directory which has no name
	 * and cannot be moved
	 */

	if (!oldpath || *oldpath == '\0' || oldpath[0] != '/' || !newpath || *newpath == '\0' || newpath[0] != '/') {
		errcode = EINVAL;
		goto errout;
	}

	/* Get an inode that includes the oldpath */

	oldinode = inode_find(oldpath, &oldrelpath);
	if (!oldinode) {
		/* There is no inode that includes in this path */

		errcode = ENOENT;
		goto errout;
	}
#ifndef CONFIG_DISABLE_MOUNTPOINT
	/* Verify that the old inode is a valid mountpoint. */

	if (INODE_IS_MOUNTPT(oldinode) && oldinode->u.i_mops) {
		/* Get an inode for the new relpath -- it should like on the same
		 * mountpoint
		 */

		newinode = inode_find(newpath, &newrelpath);
		if (!newinode) {
			/* There is no mountpoint that includes in this path */

			errcode = ENOENT;
			goto errout_with_oldinode;
		}

		/* Verify that the two paths lie on the same mountpoint inode */

		if (oldinode != newinode) {
			errcode = EXDEV;
			goto errout_with_newinode;
		}

		/* Perform the rename operation using the relative paths
		 * at the common mountpoint.
		 */

		if (oldinode->u.i_mops->rename) {
			ret = oldinode->u.i_mops->rename(oldinode, oldrelpath, newrelpath);
			if (ret < 0) {
				errcode = -ret;
				goto errout_with_newinode;
			}
		} else {
			errcode = ENOSYS;
			goto errout_with_newinode;
		}

		/* Successfully renamed */

		inode_release(newinode);
	} else
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
	{
		/* Create a new, empty inode at the destination location */

		inode_semtake();
		ret = inode_reserve(newpath, &newinode);
		if (ret < 0) {
			/* It is an error if a node at newpath already exists in the tree
			 * OR if we fail to allocate memory for the new inode (and possibly
			 * any new intermediate path segments).
			 */

			inode_semgive();
			errcode = EEXIST;
			goto errout_with_oldinode;
		}

		/* Copy the inode state from the old inode to the newly allocated inode */

		newinode->i_child = oldinode->i_child;	/* Link to lower level inode */
		newinode->i_flags = oldinode->i_flags;	/* Flags for inode */
		newinode->u.i_ops = oldinode->u.i_ops;	/* Inode operations */
#ifdef CONFIG_FILE_MODE
		newinode->i_mode = oldinode->i_mode;	/* Access mode flags */
#endif
		newinode->i_private = oldinode->i_private;	/* Per inode driver private data */

		/* We now have two copies of the inode.  One with a reference count of
		 * zero (the new one), and one that may have multiple references
		 * including one by this logic (the old one)
		 *
		 * Remove the old inode.  Because we hold a reference count on the
		 * inode, it will not be deleted now.  It will be deleted when all of
		 * the references to to the inode have been released (perhaps when
		 * inode_release() is called below).  inode_remove() should return
		 * -EBUSY to indicate that the inode was not deleted now.
		 */

		ret = inode_remove(oldpath);
		if (ret < 0 && ret != -EBUSY) {
			/* Remove the new node we just recreated */

			(void)inode_remove(newpath);
			inode_semgive();

			errcode = -ret;
			goto errout_with_oldinode;
		}

		/* Remove all of the children from the unlinked inode */

		oldinode->i_child = NULL;
		inode_semgive();
	}
#else
	{
		errcode = ENXIO;
		goto errout;
	}
#endif

	/* Successfully renamed */

	inode_release(oldinode);
	return OK;

#ifndef CONFIG_DISABLE_MOUNTPOINT
errout_with_newinode:
	inode_release(newinode);
#endif
errout_with_oldinode:
	inode_release(oldinode);
errout:
	set_errno(errcode);
	return ERROR;
}

#endif							/* FS_HAVE_RENAME */
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
 * fs/vfs/fs_rmdir.c
 *
 *   Copyright (C) 2007-2009, 2014 Gregory Nutt. All rights reserved.
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

#include <unistd.h>
#include <errno.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#undef FS_HAVE_WRITABLE_MOUNTPOINT
#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_WRITABLE) && \
	CONFIG_NFILE_STREAMS > 0
#define FS_HAVE_WRITABLE_MOUNTPOINT 1
#endif

#undef FS_HAVE_PSEUDOFS_OPERATIONS
#if !defined(CONFIG_DISABLE_PSEUDOFS_OPERATIONS) && CONFIG_NFILE_STREAMS > 0
#define FS_HAVE_PSEUDOFS_OPERATIONS 1
#endif

#undef FS_HAVE_RMDIR
#if defined(FS_HAVE_WRITABLE_MOUNTPOINT) || defined(FS_HAVE_PSEUDOFS_OPERATIONS)
#define FS_HAVE_RMDIR 1
#endif

#ifdef FS_HAVE_RMDIR

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
 * Name: rmdir
 *
 * Description:  Remove a file managed a mountpoint
 *
 ****************************************************************************/

int rmdir(FAR const char *pathname)
{
	FAR struct inode *inode;
	const char *relpath = NULL;
	int errcode;

	/* Get an inode for this file.  inode_find() automatically increments the
	 * reference count on the inode if one is found.
	 */

	inode = inode_find(pathname, &relpath);
	if (!inode) {
		/* There is no inode that includes in this path */

		errcode = ENOENT;
		goto errout;
	}
#ifndef CONFIG_DISABLE_MOUNTPOINT
	/* Check if the inode is a valid mountpoint. */

	if (INODE_IS_MOUNTPT(inode) && inode->u.i_mops) {
		/* Perform the rmdir operation using the relative path
		 * from the mountpoint.
		 */

		if (inode->u.i_mops->rmdir) {
			int ret = inode->u.i_mops->rmdir(inode, relpath);
			if (ret < 0) {
				errcode = -ret;
				goto errout_with_inode;
			}
		} else {
			errcode = ENOSYS;
			goto errout_with_inode;
		}
	} else
#endif

#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
		/* If this is a "dangling" pseudo-directory node (i.e., it has no operations)
		 * then rmdir should remove the node.
		 */

		if (!inode->u.i_ops) {
			int ret;

			/* If the directory inode has children, however, then it cannot be
			 * removed.
			 */

			if (inode->i_child) {
				errcode = ENOTEMPTY;
				goto errout_with_inode;
			}

			/* Remove the inode.  NOTE: Because we hold a reference count on the
			 * inode, it will not be deleted now.  But probably when inode_release()
			 * is called below.  inode_remove should return -EBUSY to indicate that
			 * the inode was not deleted now.
			 */

			inode_semtake();
			ret = inode_remove(pathname);
			inode_semgive();

			if (ret < 0 && ret != -EBUSY) {
				errcode = -ret;
				goto errout_with_inode;
			}
		} else {
			errcode = ENOTDIR;
			goto errout_with_inode;
		}
#else
	{
		errcode = ENXIO;
		goto errout_with_inode;
	}
#endif

	/* Successfully removed the directory */

	inode_release(inode);
	return OK;

errout_with_inode:
	inode_release(inode);
errout:
	set_errno(errcode);
	return ERROR;
}

#endif							/* FS_HAVE_RMDIR */
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
 * fs/vfs/fs_select.c
 *
 *   Copyright (C) 2008-2009, 2012-2013 Gregory Nutt. All rights reserved.
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

#include <sys/select.h>
#include <sys/time.h>

#include <string.h>
#include <poll.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/kmalloc.h>
#include <tinyara/cancelpt.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"

#ifndef CONFIG_DISABLE_POLL

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: select
 *
 * Description:
 *   select() allows a program to monitor multiple file descriptors, waiting
 *   until one or more of the file descriptors become "ready" for some class
 *   of I/O operation (e.g., input possible).  A file descriptor is
 *   considered  ready if it is possible to perform the corresponding I/O
 *   operation (e.g., read(2)) without blocking.
 *
 *   NOTE: poll() is the fundamental API for performing such monitoring
 *   operation under NuttX.  select() is provided for compatibility and
 *   is simply a layer of added logic on top of poll().  As such, select()
 *   is more wasteful of resources and poll() is the recommended API to be
 *   used.
 *
 * Input parameters:
 *   nfds - the maximum fd number (+1) of any descriptor in any of the
 *     three sets.
 *   readfds - the set of descriptions to monitor for read-ready events
 *   writefds - the set of descriptions to monitor for write-ready events
 *   exceptfds - the set of descriptions to monitor for error events
 *   timeout - Return at this time if none of these events of interest
 *     occur.
 *
 *  Return:
 *   0: Timer expired
 *  >0: The number of bits set in the three sets of descriptors
 *  -1: An error occurred (errno will be set appropriately)
 *
 ****************************************************************************/

int select(int nfds, FAR fd_set *readfds, FAR fd_set *writefds, FAR fd_set *exceptfds, FAR struct timeval *timeout)
{
	struct pollfd *pollset = NULL;
	int errcode = OK;
	int fd;
	int npfds;
	int msec;
	int ndx;
	int ret;

	/* select() is a cancellation point */
	(void)enter_cancellation_point();

	/* How many pollfd structures do we need to allocate? */

	/* Initialize the descriptor list for poll() */

	for (fd = 0, npfds = 0; fd < nfds; fd++) {
		/* Check if any monitor operation is requested on this fd */

		if ((readfds && FD_ISSET(fd, readfds)) || (writefds && FD_ISSET(fd, writefds)) || (exceptfds && FD_ISSET(fd, exceptfds))) {
			/* Yes.. increment the count of pollfds structures needed */

			npfds++;
		}
	}

	if (npfds > 0) {
		/* Allocate the descriptor list for poll() */

		pollset = (struct pollfd *)kmm_zalloc(npfds * sizeof(struct pollfd));
		if (!pollset) {
			set_errno(ENOMEM);
			leave_cancellation_point();
			return ERROR;
		}
	}

	/* Initialize the descriptor list for poll() */

	for (fd = 0, ndx = 0; fd < nfds; fd++) {
		int incr = 0;

		/* The readfs set holds the set of FDs that the caller can be assured
		 * of reading from without blocking.  Note that POLLHUP is included as
		 * a read-able condition.  POLLHUP will be reported at the end-of-file
		 * or when a connection is lost.  In either case, the read() can then
		 * be performed without blocking.
		 */

		if (readfds && FD_ISSET(fd, readfds)) {
			pollset[ndx].fd = fd;
			pollset[ndx].events |= POLLIN;
			incr = 1;
		}

		/* The writefds set holds the set of FDs that the caller can be assured
		 * of writing to without blocking.
		 */

		if (writefds && FD_ISSET(fd, writefds)) {
			pollset[ndx].fd = fd;
			pollset[ndx].events |= POLLOUT;
			incr = 1;
		}

		/* The exceptfds set holds the set of FDs that are watched for exceptions */

		if (exceptfds && FD_ISSET(fd, exceptfds)) {
			pollset[ndx].fd = fd;
			pollset[ndx].events |= POLLERR;
			incr = 1;
		}

		ndx += incr;
	}

	DEBUGASSERT(ndx == npfds);

	/* Convert the timeout to milliseconds */

	if (timeout) {
		/* Calculate the timeout in milliseconds */

		msec = timeout->tv_sec * 1000 + timeout->tv_usec / 1000;
	} else {
		/* Any negative value of msec means no timeout */

		msec = -1;
	}

	/* Then let poll do all of the real work. */

	ret = poll(pollset, npfds, msec);
	if (ret < 0) {
		/* poll() failed! Save the errno value */

		errcode = get_errno();
	}

	/* Now set up the return values */

	if (readfds) {
		memset(readfds, 0, sizeof(fd_set));
	}

	if (writefds) {
		memset(writefds, 0, sizeof(fd_set));
	}

	if (exceptfds) {
		memset(exceptfds, 0, sizeof(fd_set));
	}

	/* Convert the poll descriptor list back into selects 3 bitsets */

	if (ret > 0) {
		ret = 0;
		for (ndx = 0; ndx < npfds; ndx++) {
			/* Check for read conditions.  Note that POLLHUP is included as a
			 * read condition.  POLLHUP will be reported when no more data will
			 * be available (such as when a connection is lost).  In either
			 * case, the read() can then be performed without blocking.
			 */

			if (readfds) {
				if (pollset[ndx].revents & (POLLIN | POLLHUP)) {
					FD_SET(pollset[ndx].fd, readfds);
					ret++;
				}
			}

			/* Check for write conditions */

			if (writefds) {
				if (pollset[ndx].revents & POLLOUT) {
					FD_SET(pollset[ndx].fd, writefds);
					ret++;
				}
			}

			/* Check for exceptions */

			if (exceptfds) {
				if (pollset[ndx].revents & POLLERR) {
					FD_SET(pollset[ndx].fd, exceptfds);
					ret++;
				}
			}
		}
	}
	if (pollset) {
		kmm_free(pollset);
	}

	/* Did poll() fail above? */

	if (ret < 0) {
		/* Yes.. restore the errno value */

		set_errno(errcode);
	}

	leave_cancellation_point();
	return ret;
}

#endif							/* CONFIG_DISABLE_POLL */
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
 * fs/vfs/fs_stat.c
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

#include <sys/stat.h>
#include <string.h>
#include <sched.h>
#include <errno.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: statroot
 ****************************************************************************/

static inline int statroot(FAR struct stat *buf)
{
	/* There is no inode associated with the fake root directory */

	memset(buf, 0, sizeof(struct stat));
	buf->st_mode = S_IFDIR | S_IROTH | S_IRGRP | S_IRUSR;
	return OK;
}

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stat
 *
 * Returned Value:
 *   Zero on success; -1 on failure with errno set:
 *
 *   EACCES  Search permission is denied for one of the directories in the
 *           path prefix of path.
 *   EFAULT  Bad address.
 *   ENOENT  A component of the path path does not exist, or the path is an
 *           empty string.
 *   ENOMEM  Out of memory
 *   ENOTDIR A component of the path is not a directory.
 *
 ****************************************************************************/

int stat(FAR const char *path, FAR struct stat *buf)
{
	FAR struct inode *inode;
	const char *relpath = NULL;
	int ret = OK;

	/* Sanity checks */

	if (!path || !buf) {
		ret = EFAULT;
		goto errout;
	}

	if (!path[0]) {
		ret = ENOENT;
		goto errout;
	}

	/* Check for the fake root directory (which has no inode) */

	if (strcmp(path, "/") == 0) {
		return statroot(buf);
	}

	/* Get an inode for this file */

	inode = inode_find(path, &relpath);
	if (!inode) {
		/* This name does not refer to a psudeo-inode and there is no
		 * mountpoint that includes in this path.
		 */

		ret = ENOENT;
		goto errout;
	}

	/* The way we handle the stat depends on the type of inode that we
	 * are dealing with.
	 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	if (INODE_IS_MOUNTPT(inode)) {
		/* The node is a file system mointpoint. Verify that the mountpoint
		 * supports the stat() method
		 */

		if (inode->u.i_mops && inode->u.i_mops->stat) {
			/* Perform the stat() operation */

			ret = inode->u.i_mops->stat(inode, relpath, buf);
		}
	} else
#endif
	{
		/* The node is part of the root pseudo file system */

		ret = inode_stat(inode, buf);
	}

	/* Check if the stat operation was successful */

	if (ret < 0) {
		ret = -ret;
		goto errout_with_inode;
	}

	/* Successfully stat'ed the file */

	inode_release(inode);
	return OK;

	/* Failure conditions always set the errno appropriately */

errout_with_inode:
	inode_release(inode);
errout:
	set_errno(ret);
	return ERROR;
}

/****************************************************************************
 * Name: inode_stat
 *
 * Description:
 *   The inode_stat() function will obtain information about an 'inode' in
 *   the pseudo file system and will write it to the area pointed to by 'buf'.
 *
 *   The 'buf' argument is a pointer to a stat structure, as defined in
 *   <sys/stat.h>, into which information is placed concerning the file.
 *
 * Input Parameters:
 *   inode - The inode of interest
 *   buf   - The caller provide location in which to return information about
 *           the inode.
 *
 * Returned Value:
 *   Zero (OK) returned on success.  Otherwise, a negated errno value is
 *   returned to indicate the nature of the failure.
 *
 ****************************************************************************/

int inode_stat(FAR struct inode *inode, FAR struct stat *buf)
{
	DEBUGASSERT(inode != NULL && buf != NULL);

	memset(buf, 0, sizeof(*buf));

	if (INODE_IS_SPECIAL(inode)) {
#if defined(CONFIG_FS_NAMED_SEMAPHORES)
		if (INODE_IS_NAMEDSEM(inode)) {
			buf->st_mode = S_IFSEM;
		} else
#endif
#if !defined(CONFIG_DISABLE_MQUEUE)
		if (INODE_IS_MQUEUE(inode)) {
			buf->st_mode = S_IFMQ;
		} else
#endif
		{
		}
	} else if (inode->u.i_ops != NULL) {
		/* Determine read/write privileges based on the existence of read
		 * and write methods.
		 */
		if (inode->u.i_ops->read) {
			buf->st_mode = S_IROTH | S_IRGRP | S_IRUSR;
		}
		if (inode->u.i_ops->write) {
			buf->st_mode |= S_IWOTH | S_IWGRP | S_IWUSR;
		}
		/* Determine the type of the inode */
		if (INODE_IS_MOUNTPT(inode)) {
			buf->st_mode |= S_IFDIR;
		} else if (INODE_IS_BLOCK(inode)) {
			/* What is if also has child inodes? */
			buf->st_mode |= S_IFBLK;
		} else /* if (INODE_IS_DRIVER(inode)) */ {
			/* What is it if it also has child inodes? */
			buf->st_mode |= S_IFCHR;
		}
	} else {
		/* If it has no operations, then it must just be a intermediate
		 * node in the inode tree. It is something like a directory.
		 * We'll say that all pseudo-directories are read-able but not
		 * write-able.
		 */
		buf->st_mode |= S_IFDIR | S_IROTH | S_IRGRP | S_IRUSR;
	}

	return OK;
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
 * fs/vfs/fs_statfs.c
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

#include <sys/statfs.h>
#include <string.h>
#include <limits.h>
#include <sched.h>
#include <errno.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: statpseudo
 ****************************************************************************/

static inline int statpseudofs(FAR struct inode *inode, FAR struct statfs *buf)
{
	memset(buf, 0, sizeof(struct statfs));
	buf->f_type = PROC_SUPER_MAGIC;
	buf->f_namelen = NAME_MAX;
	return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stat
 *
 * Return: Zero on success; -1 on failure with errno set:
 *
 *   EACCES  Search permission is denied for one of the directories in the
 *           path prefix of path.
 *   EFAULT  Bad address.
 *   ENOENT  A component of the path path does not exist, or the path is an
 *           empty string.
 *   ENOMEM  Out of memory
 *   ENOTDIR A component of the path is not a directory.
 *   ENOSYS  The file system does not support this call.
 *
 ****************************************************************************/

int statfs(FAR const char *path, FAR struct statfs *buf)
{
	FAR struct inode *inode;
	FAR const char *relpath = NULL;
	int ret = OK;

	/* Sanity checks */

	if (!path || !buf) {
		ret = EFAULT;
		goto errout;
	}

	if (!path[0]) {
		ret = ENOENT;
		goto errout;
	}

	/* Get an inode for this file */

	inode = inode_find(path, &relpath);
	if (!inode) {
		/* This name does not refer to a psudeo-inode and there is no
		 * mountpoint that includes in this path.
		 */

		ret = ENOENT;
		goto errout;
	}

	/* The way we handle the statfs depends on the type of inode that we
	 * are dealing with.
	 */

#ifndef CONFIG_DISABLE_MOUNTPOINT
	if (INODE_IS_MOUNTPT(inode)) {
		/* The node is a file system mointpoint. Verify that the mountpoint
		 * supports the statfs() method
		 */

		if (inode->u.i_mops && inode->u.i_mops->statfs) {
			/* Perform the statfs() operation */

			ret = inode->u.i_mops->statfs(inode, buf);
		}
	} else
#endif
	{
		/* The node is part of the root pseudo file system */

		ret = statpseudofs(inode, buf);
	}

	/* Check if the statfs operation was successful */

	if (ret < 0) {
		ret = -ret;
		goto errout_with_inode;
	}

	/* Successfully statfs'ed the file */

	inode_release(inode);
	return OK;

	/* Failure conditions always set the errno appropriately */

errout_with_inode:
	inode_release(inode);
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
 * fs/vfs/fs_unlink.c
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

#include <unistd.h>
#include <errno.h>
#include <tinyara/fs/fs.h>

#include "inode/inode.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#undef FS_HAVE_WRITABLE_MOUNTPOINT
#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_WRITABLE) && \
	CONFIG_NFILE_STREAMS > 0
#define FS_HAVE_WRITABLE_MOUNTPOINT 1
#endif

#undef FS_HAVE_PSEUDOFS_OPERATIONS
#if !defined(CONFIG_DISABLE_PSEUDOFS_OPERATIONS) && CONFIG_NFILE_STREAMS > 0
#define FS_HAVE_PSEUDOFS_OPERATIONS 1
#endif

#undef FS_HAVE_UNLINK
#if defined(FS_HAVE_WRITABLE_MOUNTPOINT) || defined(FS_HAVE_PSEUDOFS_OPERATIONS)
#define FS_HAVE_UNLINK 1
#endif

#ifdef FS_HAVE_UNLINK

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
 * Name: unlink
 *
 * Description:  Remove a file managed a mountpoint
 *
 ****************************************************************************/

int unlink(FAR const char *pathname)
{
	FAR struct inode *inode;
	const char *relpath = NULL;
	int errcode;
	int ret;

	/* Get an inode for this file */

	inode = inode_find(pathname, &relpath);
	if (!inode) {
		/* There is no inode that includes in this path */

		errcode = ENOENT;
		goto errout;
	}
#ifndef CONFIG_DISABLE_MOUNTPOINT
	/* Check if the inode is a valid mountpoint. */

	if (INODE_IS_MOUNTPT(inode) && inode->u.i_mops) {
		/* Perform the unlink operation using the relative path at the
		 * mountpoint.
		 */

		if (inode->u.i_mops->unlink) {
			ret = inode->u.i_mops->unlink(inode, relpath);
			if (ret < 0) {
				errcode = -ret;
				goto errout_with_inode;
			}
		} else {
			errcode = ENOSYS;
			goto errout_with_inode;
		}
	} else
#endif

#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
		/* If this is a "dangling" pseudo-file node (i.e., it has operations) then rm
		 * should remove the node.
		 */

		if (!INODE_IS_SPECIAL(inode) && inode->u.i_ops) {
			/* If this is a pseudo-file node (i.e., it has no operations)
			 * then rmdir should remove the node.
			 */

			if (inode->u.i_ops) {
				inode_semtake();

				/* Refuse to unlink the inode if it has children.  I.e., if it is
				 * functioning as a directory and the directory is not empty.
				 */

				if (inode->i_child != NULL) {
					errcode = ENOTEMPTY;
					inode_semgive();
					goto errout_with_inode;
				}

				/* Notify the driver that it has been unlinked.  If there are no
				 * open references to the driver instance, then the driver should
				 * release all resources because it is no longer accessible.
				 */

				if (INODE_IS_DRIVER(inode) && inode->u.i_ops->unlink) {
					/* Notify the character driver that it has been unlinked */

					ret = inode->u.i_ops->unlink(inode);
					if (ret < 0) {
						errcode = -ret;
						goto errout_with_inode;
					}
				}
#ifndef CONFIG_DISABLE_MOUNTPOINT
				else if (INODE_IS_BLOCK(inode) && inode->u.i_bops->unlink) {
					/* Notify the block driver that it has been unlinked */

					ret = inode->u.i_bops->unlink(inode);
					if (ret < 0) {
						errcode = -ret;
						goto errout_with_inode;
					}
				}
#endif

				/* Remove the old inode.  Because we hold a reference count on the
				 * inode, it will not be deleted now.  It will be deleted when all
				 * of the references to to the inode have been released (perhaps
				 * when inode_release() is called below).  inode_remove() will
				 * return -EBUSY to indicate that the inode was not deleted now.
				 */

				ret = inode_remove(pathname);
				inode_semgive();

				if (ret < 0 && ret != -EBUSY) {
					errcode = -ret;
					goto errout_with_inode;
				}
			} else {
				errcode = EISDIR;
				goto errout_with_inode;
			}
		} else
#endif
		{
			errcode = ENXIO;
			goto errout_with_inode;
		}

	/* Successfully unlinked */

	inode_release(inode);
	return OK;

errout_with_inode:
	inode_release(inode);
errout:
	set_errno(errcode);
	return ERROR;
}

#endif							/* FS_HAVE_UNLINK */
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
 * fs/vfs/fs_write.c
 *
 *   Copyright (C) 2007-2009, 2012-2014 Gregory Nutt. All rights reserved.
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
#include <unistd.h>
#include <fcntl.h>
#include <sched.h>
#include <errno.h>
#include <assert.h>

#include <tinyara/cancelpt.h>
#include <sys/socket.h>

#include "inode/inode.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: file_write
 *
 * Description:
 *   Equivalent to the standard write() function except that is accepts a
 *   struct file instance instead of a file descriptor.  Currently used
 *   only by aio_write();
 *
 ****************************************************************************/

ssize_t file_write(FAR struct file *filep, FAR const void *buf, size_t nbytes)
{
	FAR struct inode *inode;
	ssize_t ret;
	int err;

	/* Was this file opened for write access? */

	if ((filep->f_oflags & O_WROK) == 0) {
		err = EBADF;
		goto errout;
	}

	/* Is a driver registered? Does it support the write method? */

	inode = filep->f_inode;
	if (!inode || !inode->u.i_ops || !inode->u.i_ops->write) {
		err = EBADF;
		goto errout;
	}

	/* Yes, then let the driver perform the write */

	ret = inode->u.i_ops->write(filep, buf, nbytes);
	if (ret < 0) {
		err = -ret;
		goto errout;
	}

	return ret;

errout:
	set_errno(err);
	return ERROR;
}

/***************************************************************************
 * Name: write
 *
 * Description:
 *  write() writes up to nytes bytes to the file referenced by the file
 *  descriptor fd from the buffer starting at buf.
 *
 * Parameters:
 *   fd       file descriptor (or socket descriptor) to write to
 *   buf      Data to write
 *   nbytes   Length of data to write
 *
 * Returned Value:
 *  On success, the number of bytes  written are returned (zero indicates
 *  nothing was written). On error, -1 is returned, and errno is set appro-
 *  priately:
 *
 *  EAGAIN
 *    Non-blocking I/O has been selected using O_NONBLOCK and the write
 *    would block.
 *  EBADF
 *    fd is not a valid file descriptor or is not open for writing.
 *  EFAULT
 *    buf is outside your accessible address space.
 *  EFBIG
 *    An attempt was made to write a file that exceeds the implementation
 *    defined maximum file size or the process' file size limit, or
 *    to write at a position past the maximum allowed offset.
 *  EINTR
 *    The call was interrupted by a signal before any data was written.
 *  EINVAL
 *    fd is attached to an object which is unsuitable for writing; or
 *    the file was opened with the O_DIRECT flag, and either the address
 *    specified in buf, the value specified in count, or the current
 *     file offset is not suitably aligned.
 *  EIO
 *    A low-level I/O error occurred while modifying the inode.
 *  ENOSPC
 *    The device containing the file referred to by fd has no room for
 *    the data.
 *  EPIPE
 *    fd is connected to a pipe or socket whose reading end is closed.
 *    When this happens the writing process will also receive a SIGPIPE
 *    signal. (Thus, the write return value is seen only if the program
 *    catches, blocks or ignores this signal.)
 *
 * Assumptions:
 *
 ********************************************************************************************/

ssize_t write(int fd, FAR const void *buf, size_t nbytes)
{
#if CONFIG_NFILE_DESCRIPTORS > 0
	FAR struct file *filep;
#endif
	ssize_t ret;

	/* write() is a cancellation point */
	(void)enter_cancellation_point();

	/* Did we get a valid file descriptor? */

#if CONFIG_NFILE_DESCRIPTORS > 0
	if ((unsigned int)fd >= CONFIG_NFILE_DESCRIPTORS)
#endif
	{
		/* Write to a socket descriptor is equivalent to send with flags == 0 */

#if defined(CONFIG_NET_LWIP) && CONFIG_NSOCKET_DESCRIPTORS > 0
		ret = send(fd, buf, nbytes, 0);
#else
		set_errno(EBADF);
		ret = ERROR;
#endif
	}
#if CONFIG_NFILE_DESCRIPTORS > 0
	else {
		/* The descriptor is in the right range to be a file descriptor... write
		 * to the file. Note that fs_getfilep() will set the errno on failure.
		 */

		filep = fs_getfilep(fd);
		if (!filep) {
			/* The errno value has already been set */

			ret = ERROR;
		} else {
			/* Perform the write operation using the file descriptor as an index.
			 * Note that file_write() will set the errno on failure.
			 */

			ret = file_write(filep, buf, nbytes);
		}
	}
#endif
	leave_cancellation_point();
	return ret;
}
