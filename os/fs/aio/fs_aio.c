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
 * libc/aio/aioc_contain.c
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

#include <sched.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include <tinyara/net/net.h>

#include "aio/aio.h"

#ifdef CONFIG_FS_AIO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: aio_contain
 *
 * Description:
 *   Create and initialize a container for the provided AIO control block
 *
 * Input Parameters:
 *   aiocbp - The AIO control block pointer
 *
 * Returned Value:
 *   A reference to the new AIO control block container.   This function
 *   will not fail but will wait if necessary for the resources to perform
 *   this operation.  NULL will be returned on certain errors with the
 *   errno value already set appropriately.
 *
 ****************************************************************************/

FAR struct aio_container_s *aio_contain(FAR struct aiocb *aiocbp)
{
	FAR struct aio_container_s *aioc;
	union {
#ifdef AIO_HAVE_FILEP
		FAR struct file *filep;
#endif
#ifdef AIO_HAVE_FILEP
		FAR struct socket *psock;
#endif
		FAR void *ptr;
	} u;
#ifdef CONFIG_PRIORITY_INHERITANCE
	struct sched_param param;
#endif

#ifdef AIO_HAVE_FILEP
	{
		/* Get the file structure corresponding to the file descriptor. */

		u.filep = fs_getfilep(aiocbp->aio_fildes);
		if (!u.filep) {
			/* The errno value has already been set */

			return NULL;
		}
	}
#endif

	/* Allocate the AIO control block container, waiting for one to become
	 * available if necessary.  This should never fail.
	 */

	aioc = aioc_alloc();
	DEBUGASSERT(aioc);

	/* Initialize the container */

	memset(aioc, 0, sizeof(struct aio_container_s));
	aioc->aioc_aiocbp = aiocbp;
	aioc->u.ptr = u.ptr;
	aioc->aioc_pid = getpid();

#ifdef CONFIG_PRIORITY_INHERITANCE
	DEBUGVERIFY(sched_getparam(aioc->aioc_pid, &param));
	aioc->aioc_prio = param.sched_priority;
#endif

	/* Add the container to the pending transfer list. */

	aio_lock();
	dq_addlast(&aioc->aioc_link, &g_aio_pending);
	aio_unlock();
	return aioc;
}

/****************************************************************************
 * Name: aioc_decant
 *
 * Description:
 *   Remove the AIO control block from the container and free all resources
 *   used by the container.
 *
 * Input Parameters:
 *   aioc - Pointer to the AIO control block container
 *
 * Returned Value:
 *   A pointer to the no-longer contained AIO control block.
 *
 ****************************************************************************/

FAR struct aiocb *aioc_decant(FAR struct aio_container_s *aioc)
{
	FAR struct aiocb *aiocbp;

	DEBUGASSERT(aioc);

	/* Remove the container to the pending transfer list. */

	aio_lock();
	dq_rem(&aioc->aioc_link, &g_aio_pending);

	/* De-cant the AIO control block and return the container to the free list */

	aiocbp = aioc->aioc_aiocbp;
	aioc_free(aioc);

	aio_unlock();
	return aiocbp;
}

#endif							/* CONFIG_FS_AIO */
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
 * fs/aio/aio_cancel.c
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

#include <aio.h>
#include <sched.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/wqueue.h>

#include "aio/aio.h"

#ifdef CONFIG_FS_AIO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Configuration ************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: aio_cancel
 *
 * Description:
 *   The aio_cancel() function attempts to cancel one or more asynchronous
 *   I/O requests currently outstanding against file descriptor 'fildes'.
 *   The aiocbp argument points to the asynchronous I/O control block for
 *   a particular request to be cancelled. If aiocbp is NULL, then all
 *   outstanding cancelable asynchronous I/O requests against fildes will
 *   be cancelled.
 *
 *   Normal asynchronous notification will occur for asynchronous I/O
 *   operations that are successfully cancelled. If there are requests that
 *   cannot be cancelled, then the normal asynchronous completion process
 *   will take place for those requests when they are completed.
 *
 *   For requested operations that are successfully cancelled, the associated
 *   error status will be set to ECANCELED and the return status will be -1.
 *   For requested operations that are not successfully cancelled, the aiocbp
 *   will not be modified by aio_cancel().
 *
 * Input Parameters:
 *   fildes - Not used in this implementation
 *   aiocbp - Points to the asynchronous I/O control block for a particular
 *            request to be cancelled.
 *
 * Returned Value:
 *    The aio_cancel() function will return the value AIO_CANCELED if the
 *    requested operation(s) were cancelled. The value AIO_NOTCANCELED will
 *    be returned if at least one of the requested operation(s) cannot be
 *    cancelled because it is in progress. In this case, the state of the
 *    other operations, if any, referenced in the call to aio_cancel() is
 *    not indicated by the return value of aio_cancel(). The application
 *    may determine the state of affairs for these operations by using
 *    aio_error(). The value AIO_ALLDONE is returned if all of the
 *    operations have already completed. Otherwise, the function will return
 *    -1 and set errno to indicate the error.
 *
 ****************************************************************************/

int aio_cancel(int fildes, FAR struct aiocb *aiocbp)
{
	FAR struct aio_container_s *aioc;
	FAR struct aio_container_s *next;
	int status;
	int ret;

	/* Check if a non-NULL aiocbp was provided */

	/* Lock the scheduler so that no I/O events can complete on the worker
	 * thread until we set complete this operation.
	 */

	ret = AIO_ALLDONE;
	sched_lock();
	aio_lock();

	if (aiocbp) {
		/* Check if the I/O has completed */

		if (aiocbp->aio_result == -EINPROGRESS) {
			/* No.. Find the container for this AIO control block */

			for (aioc = (FAR struct aio_container_s *)g_aio_pending.head; aioc && aioc->aioc_aiocbp != aiocbp; aioc = (FAR struct aio_container_s *)aioc->aioc_link.flink) ;

			/* Did we find a container for this fildes?  We should; the aio_result says
			 * that the transfer is pending.  If not we return AIO_ALLDONE.
			 */

			if (aioc) {
				/* Yes... attempt to cancel the I/O.  There are two
				 * possibilities:* (1) the work has already been started and
				 * is no longer queued, or (2) the work has not been started
				 * and is still in the work queue.  Only the second case can
				 * be cancelled.  work_cancel() will return -ENOENT in the
				 * first case.
				 */

				status = work_cancel(LPWORK, &aioc->aioc_work);
				if (status >= 0) {
					aiocbp->aio_result = -ECANCELED;
					ret = AIO_CANCELED;
				} else {
					ret = AIO_NOTCANCELED;
				}

				/* Remove the container from the list of pending transfers */

				(void)aioc_decant(aioc);
			}
		}
	} else {
		/* No aiocbp.. cancel all outstanding I/O for the fildes */

		next = (FAR struct aio_container_s *)g_aio_pending.head;
		do {
			/* Find the next container with this AIO control block */

			for (aioc = next; aioc && aioc->aioc_aiocbp->aio_fildes != fildes; aioc = (FAR struct aio_container_s *)aioc->aioc_link.flink) ;

			/* Did we find the container?  We should; the aio_result says
			 * that the transfer is pending.  If not we return AIO_ALLDONE.
			 */

			if (aioc) {
				/* Yes... attempt to cancel the I/O.  There are two
				 * possibilities:* (1) the work has already been started and
				 * is no longer queued, or (2) the work has not been started
				 * and is still in the work queue.  Only the second case can
				 * be cancelled.  work_cancel() will return -ENOENT in the
				 * first case.
				 */

				status = work_cancel(LPWORK, &aioc->aioc_work);

				/* Remove the container from the list of pending transfers */

				next = (FAR struct aio_container_s *)aioc->aioc_link.flink;
				aiocbp = aioc_decant(aioc);
				DEBUGASSERT(aiocbp);

				if (status >= 0) {
					aiocbp->aio_result = -ECANCELED;
					if (ret != AIO_NOTCANCELED) {
						ret = AIO_CANCELED;
					}
				} else {
					ret = AIO_NOTCANCELED;
				}
			}
		} while (aioc);
	}

	aio_unlock();
	sched_unlock();
	return ret;
}

#endif							/* CONFIG_FS_AIO */
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
 * fs/aio/aio_fsync.c
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

#include <unistd.h>
#include <fcntl.h>
#include <aio.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <tinyara/fs/fs.h>

#include "aio/aio.h"

#ifdef CONFIG_FS_AIO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: aio_fsync_worker
 *
 * Description:
 *   This function executes on the worker thread and performs the
 *   asynchronous I/O operation.
 *
 * Input Parameters:
 *   arg - Worker argument.  In this case, a pointer to an instance of
 *     struct aiocb cast to void *.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static void aio_fsync_worker(FAR void *arg)
{
	FAR struct aio_container_s *aioc = (FAR struct aio_container_s *)arg;
	FAR struct aiocb *aiocbp;
	pid_t pid;
#ifdef CONFIG_PRIORITY_INHERITANCE
	uint8_t prio;
#endif
	int ret;

	/* Get the information from the container, decant the AIO control block,
	 * and free the container before starting any I/O.  That will minimize
	 * the delays by any other threads waiting for a pre-allocated container.
	 */

	DEBUGASSERT(aioc && aioc->aioc_aiocbp);
	pid = aioc->aioc_pid;
#ifdef CONFIG_PRIORITY_INHERITANCE
	prio = aioc->aioc_prio;
#endif
	aiocbp = aioc_decant(aioc);

	/* Perform the fsync using u.aioc_filep */

	ret = file_fsync(aioc->u.aioc_filep);
	if (ret < 0) {
		int errcode = get_errno();
		fdbg("ERROR: fsync failed: %d\n", errcode);
		DEBUGASSERT(errcode > 0);
		aiocbp->aio_result = -errcode;
	} else {
		aiocbp->aio_result = OK;
	}

	/* Signal the client */

	(void)aio_signal(pid, aiocbp);

#ifdef CONFIG_PRIORITY_INHERITANCE
	/* Restore the low priority worker thread default priority */

	lpwork_restorepriority(prio);
#endif
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: aio_fsync
 *
 * Description:
 *   The aio_fsync() function asynchronously forces all I/O operations
 *   associated with the file indicated by the file descriptor aio_fildes
 *   member of the aiocb structure referenced by the aiocbp argument and
 *   queued at the time of the call to aio_fsync() to the synchronized
 *   I/O completion state. The function call will return when the
 *   synchronization request has been initiated or queued to the file or
 *   device (even when the data cannot be synchronized immediately).
 *
 *   If op is O_DSYNC, all currently queued I/O operations will be
 *   completed as if by a call to fdatasync(); that is, as defined for
 *   synchronized I/O data integrity completion. If op is O_SYNC, all
 *   currently queued I/O operations will be completed as if by a call to
 *   fsync(); that is, as defined for synchronized I/O file integrity
 *   completion. If the aio_fsync() function fails, or if the operation
 *   queued by aio_fsync() fails, then, as for fsync() and fdatasync(),
 *   outstanding I/O operations are not guaranteed to have been completed.
 *   [See "POSIX Compliance" below]
 *
 *   If aio_fsync() succeeds, then it is only the I/O that was queued at
 *   the time of the call to aio_fsync() that is guaranteed to be forced
 *   to the relevant completion state. The completion of subsequent I/O
 *   on the file descriptor is not guaranteed to be completed in a
 *   synchronized fashion.
 *
 *   The aiocbp argument refers to an asynchronous I/O control block. The
 *   aiocbp value may be used as an argument to aio_error() and aio_return()
 *   in order to determine the error status and return status, respectively,
 *   of the asynchronous operation while it is proceeding. When the request
 *   is queued, the error status for the operation is [EINPROGRESS]. When
 *   all data has been successfully transferred, the error status will be
 *   reset to reflect the success or failure of the operation. If the
 *   operation does not complete successfully, the error status for the
 *   operation will be set to indicate the error. The aio_sigevent member
 *   determines the asynchronous notification to occur when all operations
 *   have achieved synchronized I/O completion. All other members of the
 *   structure referenced by aiocbp are ignored. If the control block
 *   referenced by aiocbp becomes an illegal address prior to asynchronous
 *   I/O completion, then the behavior is undefined.
 *
 *   If the aio_fsync() function fails or aiocbp indicates an error condition,
 *   data is not guaranteed to have been successfully transferred.
 *
 * Input Parameters:
 *   op     - Should be either O_SYNC or O_DSYNC.  Ignored in this implementation.
 *   aiocbp - A pointer to an instance of struct aiocb
 *
 * Returned Value:
 *   The aio_fsync() function will return the value 0 if the I/O operation is
 *   successfully queued; otherwise, the function will return the value -1 and
 *   set errno to indicate the error.
 *
 *   The aio_fsync() function will fail if:
 *
 *     EAGAIN - The requested asynchronous operation was not queued due to
 *       temporary resource limitations.
 *     EBADF - The aio_fildes member of the aiocb structure referenced by
 *       the aiocbp argument is not a valid file descriptor open for writing.
 *     EINVAL - This implementation does not support synchronized I/O for
 *       this file.
 *      EINVAL - A value of op other than O_DSYNC or O_SYNC was specified.
 *
 *   In the event that any of the queued I/O operations fail, aio_fsync()
 *   will return the error condition defined for read() and write(). The
 *   error is returned in the error status for the asynchronous fsync()
 *   operation, which can be retrieved using aio_error().
 *
 * POSIX Compliance
 * - TinyAra does not currently make any distinction between O_DYSNC and O_SYNC.
 *   Hence, the 'op' argument is ignored altogether.
 * - Most errors required in the standard are not detected at this point.
 *   There are no pre-queuing checks for the validity of the operation.
 *
 ****************************************************************************/

int aio_fsync(int op, FAR struct aiocb *aiocbp)
{
	FAR struct aio_container_s *aioc;
	int ret;

	DEBUGASSERT(op == O_SYNC /* || op == O_DSYNC */);
	DEBUGASSERT(aiocbp);

	/* The result -EINPROGRESS means that the transfer has not yet completed */

	aiocbp->aio_result = -EINPROGRESS;
	aiocbp->aio_priv = NULL;

	/* Create a container for the AIO control block.  This may cause us to
	 * block if there are insufficient resources to satisfy the request.
	 */

	aioc = aio_contain(aiocbp);
	if (!aioc) {
		/* The errno has already been set (probably EBADF) */

		aiocbp->aio_result = -get_errno();
		return ERROR;
	}

	/* Defer the work to the worker thread */

	ret = aio_queue(aioc, aio_fsync_worker);
	if (ret < 0) {
		/* The result and the errno have already been set */

		return ERROR;
	}

	return OK;
}

#endif							/* CONFIG_FS_AIO */
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
 * fs/aio/aio_initialize.c
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

#include <semaphore.h>
#include <assert.h>
#include <errno.h>
#include <queue.h>

#include <tinyara/sched.h>

#include "aio/aio.h"

#ifdef CONFIG_FS_AIO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This is an array of pre-allocated AIO containers */

static struct aio_container_s g_aioc_alloc[CONFIG_FS_NAIOC];

/* This is a list of free AIO containers */

static dq_queue_t g_aioc_free;

/* This counting semaphore tracks the number of free AIO containers */

static sem_t g_aioc_freesem;

/* This binary semaphore supports exclusive access to the list of pending
 * asynchronous I/O.  g_aio_holder and a_aio_count support the reentrant
 * lock.
 */

static sem_t g_aio_exclsem;
static pid_t g_aio_holder;
static uint16_t g_aio_count;

/****************************************************************************
 * Public Data
 ****************************************************************************/
/* This is a list of pending asynchronous I/O.  The user must hold the
 * lock on this list in order to access the list.
 */

dq_queue_t g_aio_pending;

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: aio_initialize
 *
 * Description:
 *   Perform one-time initialization of the asynchronous I/O sub-system
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void aio_initialize(void)
{
	int i;

	/* Initialize counting semaphores */

	(void)sem_init(&g_aioc_freesem, 0, CONFIG_FS_NAIOC);
	(void)sem_init(&g_aio_exclsem, 0, 1);

	g_aio_holder = INVALID_PROCESS_ID;

	/* Initialize the container queues */

	dq_init(&g_aioc_free);
	dq_init(&g_aio_pending);

	/* Add all of the pre-allocated AIO containers to the free list */

	for (i = 0; i < CONFIG_FS_NAIOC; i++) {
		/* Add the container to the free list */

		dq_addlast(&g_aioc_alloc[i].aioc_link, &g_aioc_free);
	}
}

/****************************************************************************
 * Name: aio_lock/aio_unlock
 *
 * Description:
 *   Take/give the lock on the pending asynchronous I/O list
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void aio_lock(void)
{
	pid_t me = getpid();

	/* Does this thread already hold the semaphore? */

	if (g_aio_holder == me) {
		/* Yes, just increment the counts held */

		DEBUGASSERT(g_aio_count > 0 && g_aio_count < UINT16_MAX);
		g_aio_count++;
	} else {
		/* No.. take the semaphore */

		while (sem_wait(&g_aio_exclsem) < 0) {
			DEBUGASSERT(get_errno() == EINTR);
		}

		/* And mark it as ours */

		g_aio_holder = me;
		g_aio_count = 1;
	}
}

void aio_unlock(void)
{
	DEBUGASSERT(g_aio_holder == getpid() && g_aio_count > 0);

	/* Would decrementing the count release the lock? */

	if (g_aio_count <= 1) {
		/* Yes.. that we will no longer be the holder */

		g_aio_holder = INVALID_PROCESS_ID;
		g_aio_count = 0;
		sem_post(&g_aio_exclsem);
	} else {
		/* Otherwise, just decrement the count.  We still hold the lock. */

		g_aio_count--;
	}
}

/****************************************************************************
 * Name: aioc_alloc
 *
 * Description:
 *   Allocate a new AIO container by taking the next, pre-allocated
 *   container from the free list.  This function will wait until
 *   aioc_free() is called in the event that there is no free container
 *   available in the free list.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   A reference to the allocated AIO container.  This allocation never
 *   fails because the logic will wait in the event that there is no free
 *   container.
 *
 ****************************************************************************/

FAR struct aio_container_s *aioc_alloc(void)
{
	FAR struct aio_container_s *aioc;

	/* Take a count from semaphore, thus guaranteeing that we have an AIO
	 * container set aside for us.
	 */

	while (sem_wait(&g_aioc_freesem) < 0) {
		DEBUGASSERT(get_errno() == EINTR);
	}

	/* Get our AIO container */

	aio_lock();
	aioc = (FAR struct aio_container_s *)dq_remfirst(&g_aioc_free);
	aio_unlock();

	DEBUGASSERT(aioc);
	return aioc;
}

/****************************************************************************
 * Name: aioc_free
 *
 * Description:
 *   Free an AIO container by returning it to the free list and, perhaps,
 *   awakening any threads waiting for that resource
 *
 * Input Parameters:
 *   aioc - The AIO container to be free
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void aioc_free(FAR struct aio_container_s *aioc)
{
	DEBUGASSERT(aioc);

	/* Return the container to the free list */

	aio_lock();
	dq_addlast(&aioc->aioc_link, &g_aioc_free);
	aio_unlock();

	/* The post the counting semaphore, announcing the availability of the
	 * free AIO container.
	 */

	sem_post(&g_aioc_freesem);
}

#endif							/* CONFIG_FS_AIO */
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
 * fs/aio/aio_queue.c
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

#include <sched.h>
#include <aio.h>
#include <errno.h>
#include <debug.h>

#include <tinyara/wqueue.h>

#include "aio/aio.h"

#ifdef CONFIG_FS_AIO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: aio_queue
 *
 * Description:
 *   Schedule the asynchronous I/O on the low priority work queue
 *
 * Input Parameters:
 *   arg - Worker argument.  In this case, a pointer to an instance of
 *     struct aiocb cast to void *.
 *
 * Returned Value:
 *   Zero (OK) on success.  Otherwise, -1 is returned and the errno is set
 *   appropriately.
 *
 ****************************************************************************/

int aio_queue(FAR struct aio_container_s *aioc, worker_t worker)
{
	int ret;

#ifdef CONFIG_PRIORITY_INHERITANCE
	/* Prohibit context switches until we complete the queuing */

	sched_lock();

	/* Make sure that the low-priority worker thread is running at at least
	 * the priority specified for this action.
	 */

	lpwork_boostpriority(aioc->aioc_prio);
#endif

	/* Schedule the work on the low priority worker thread */

	ret = work_queue(LPWORK, &aioc->aioc_work, worker, aioc, 0);
	if (ret < 0) {
		FAR struct aiocb *aiocbp = aioc->aioc_aiocbp;
		DEBUGASSERT(aiocbp);

		aiocbp->aio_result = ret;
		set_errno(-ret);
		ret = ERROR;
	}
#ifdef CONFIG_PRIORITY_INHERITANCE
	/* Now the low-priority work queue might run at its new priority */

	sched_unlock();
#endif
	return ret;
}

#endif							/* CONFIG_FS_AIO */
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
 * fs/aio/aio_read.c
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

#include <unistd.h>
#include <sched.h>
#include <aio.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <tinyara/net/net.h>

#include "aio/aio.h"

#ifdef CONFIG_FS_AIO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: aio_read_worker
 *
 * Description:
 *   This function executes on the worker thread and performs the
 *   asynchronous I/O operation.
 *
 * Input Parameters:
 *   arg - Worker argument.  In this case, a pointer to an instance of
 *     struct aiocb cast to void *.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static void aio_read_worker(FAR void *arg)
{
	FAR struct aio_container_s *aioc = (FAR struct aio_container_s *)arg;
	FAR struct aiocb *aiocbp;
	pid_t pid;
#ifdef CONFIG_PRIORITY_INHERITANCE
	uint8_t prio;
#endif
	ssize_t nread = 0;

	/* Get the information from the container, decant the AIO control block,
	 * and free the container before starting any I/O.  That will minimize
	 * the delays by any other threads waiting for a pre-allocated container.
	 */

	DEBUGASSERT(aioc && aioc->aioc_aiocbp);
	pid = aioc->aioc_pid;
#ifdef CONFIG_PRIORITY_INHERITANCE
	prio = aioc->aioc_prio;
#endif
	aiocbp = aioc_decant(aioc);

#ifdef AIO_HAVE_FILEP
	{
		/* Perform the file read using:
		 *
		 *   u.aioc_filep - File structure pointer
		 *   aio_buf      - Location of buffer
		 *   aio_nbytes   - Length of transfer
		 *   aio_offset   - File offset
		 */

		nread = file_pread(aioc->u.aioc_filep, (FAR void *)aiocbp->aio_buf, aiocbp->aio_nbytes, aiocbp->aio_offset);
	}
#endif

	/* Set the result of the read */

	if (nread < 0) {
		int errcode = get_errno();
		fdbg("ERROR: pread failed: %d\n", errcode);
		DEBUGASSERT(errcode > 0);
		aiocbp->aio_result = -errcode;
	} else {
		aiocbp->aio_result = nread;
	}

	/* Signal the client */

	(void)aio_signal(pid, aiocbp);

#ifdef CONFIG_PRIORITY_INHERITANCE
	/* Restore the low priority worker thread default priority */

	lpwork_restorepriority(prio);
#endif
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: aio_read
 *
 * Description:
 *   The aio_read() function reads aiocbp->aio_nbytes from the file
 *   associated with aiocbp->aio_fildes into the buffer pointed to by
 *   aiocbp->aio_buf. The function call will return when the read request
 *   has been initiated or queued to the file or device (even when the data
 *   cannot be delivered immediately).
 *
 *   If prioritized I/O is supported for this file, then the asynchronous
 *   operation will be submitted at a priority equal to a base scheduling
 *   priority minus aiocbp->aio_reqprio. If Thread Execution Scheduling is
 *   not supported, then the base scheduling priority is that of the calling
 *   thread (the latter is implemented at present).
 *
 *   The aiocbp value may be used as an argument to aio_error() and
 *   aio_return() in order to determine the error status and return status,
 *   respectively, of the asynchronous operation while it is proceeding. If
 *   an error condition is encountered during queuing, the function call
 *   will return without having initiated or queued the request. The
 *   requested operation takes place at the absolute position in the file as
 *   given by aio_offset, as if lseek() were called immediately prior to the
 *   operation with an offset equal to aio_offset and a whence equal to
 *   SEEK_SET. After a successful call to enqueue an asynchronous I/O
 *   operation, the value of the file offset for the file is unspecified.
 *
 *   The aiocbp->aio_lio_opcode field will be ignored by aio_read().
 *
 *   The aiocbp argument points to an aiocb structure. If the buffer pointed
 *   to by aiocbp->aio_buf or the control block pointed to by aiocbp becomes
 *   an illegal address prior to asynchronous I/O completion, then the
 *   behavior is undefined.
 *
 *   Simultaneous asynchronous operations using the same aiocbp produce
 *   undefined results.
 *
 *   For any system action that changes the process memory space while an
 *   synchronous I/O is outstanding to the address range being changed, the
 *   result of that action is undefined.
 *
 * Input Parameters:
 *   aiocbp - A pointer to an instance of struct aiocb
 *
 * Returned Value:
 *
 *   The aio_read() function will return the value zero if the I/O operation
 *   is successfully queued; otherwise, the function will return the value
 *   -1 and set errno to indicate the error.  The aio_read() function will
 *   ail if:
 *
 *   EAGAIN - The requested asynchronous I/O operation was not queued due to
 *     system resource limitations.
 *
 *   Each of the following conditions may be detected synchronously at the
 *   time of the call to aio_read(), or asynchronously. If any of the
 *   conditions below are detected synchronously, the aio_read() function
 *   will return -1 and set errno to the corresponding value. If any of the
 *   conditions below are detected asynchronously, the return status of the
 *   asynchronous operation is set to -1, and the error status of the
 *   asynchronous operation is set to the corresponding value.
 *
 *   EBADF - The aiocbp->aio_fildes argument is not a valid file descriptor
 *     open for reading.
 *   EINVAL - The file offset value implied by aiocbp->aio_offset would be
 *     invalid, aiocbp->aio_reqprio is not a valid value, or
 *     aiocbp->aio_nbytes is an invalid value.
 *
 *   In the case that the aio_read() successfully queues the I/O operation
 *   but the operation is subsequently cancelled or encounters an error, the
 *   return status of the asynchronous operation is one of the values
 *   normally returned by the read() function call. In addition, the error
 *   status of the asynchronous operation is set to one of the error
 *   statuses normally set by the read() function call, or one of the
 *   following values:
 *
 *   EBADF - The aiocbp->aio_fildes argument is not a valid file descriptor
 *     open for reading.
 *   ECANCELED - The requested I/O was cancelled before the I/O completed
 *     due to an explicit aio_cancel() request.
 *   EINVAL - The file offset value implied by aiocbp->aio_offset would be
 *     invalid.
 *
 * The following condition may be detected synchronously or asynchronously:
 *
 *   EOVERFLOW - The file is a regular file, aiobcp->aio_nbytes is greater
 *     than 0, and the starting offset in aiobcp->aio_offset is before the
 *     end-of-file and is at or beyond the offset maximum in the open file
 *     description associated with aiocbp->aio_fildes.
 *
 * POSIX Compliance:
 * - Most errors required in the standard are not detected at this point.
 *   There are no pre-queuing checks for the validity of the operation.
 *
 ****************************************************************************/

int aio_read(FAR struct aiocb *aiocbp)
{
	FAR struct aio_container_s *aioc;
	int ret;

	DEBUGASSERT(aiocbp);

	/* The result -EINPROGRESS means that the transfer has not yet completed */

	aiocbp->aio_result = -EINPROGRESS;
	aiocbp->aio_priv = NULL;

	/* Create a container for the AIO control block.  This may cause us to
	 * block if there are insufficient resources to satisfy the request.
	 */

	aioc = aio_contain(aiocbp);
	if (!aioc) {
		/* The errno has already been set (probably EBADF) */

		aiocbp->aio_result = -get_errno();
		return ERROR;
	}

	/* Defer the work to the worker thread */

	ret = aio_queue(aioc, aio_read_worker);
	if (ret < 0) {
		/* The result and the errno have already been set */

		return ERROR;
	}

	return OK;
}

#endif							/* CONFIG_FS_AIO */
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
 * fs/aio/aio_signal.c
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
#include <sched.h>
#include <signal.h>
#include <aio.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include "aio/aio.h"

#ifdef CONFIG_FS_AIO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: aio_signal
 *
 * Description:
 *   Signal the client that an I/O has completed.
 *
 * Input Parameters:
 *   pid    - ID of the task to signal
 *   aiocbp - Pointer to the asynchronous I/O state structure that includes
 *            information about how to signal the client
 *
 * Returned Value:
 *   Zero (OK) if the client was successfully signalled.  Otherwise, a
 *   negated errno value is returned.
 *
 * Assumptions:
 *   This function runs only in the context of the worker thread.
 *
 ****************************************************************************/

int aio_signal(pid_t pid, FAR struct aiocb *aiocbp)
{
#ifdef CONFIG_CAN_PASS_STRUCTS
	union sigval value;
#endif
	int errcode;
	int status;
	int ret;

	DEBUGASSERT(aiocbp);

	ret = OK;					/* Assume success */

	/* Signal the client */

	if (aiocbp->aio_sigevent.sigev_notify == SIGEV_SIGNAL) {
#ifdef CONFIG_CAN_PASS_STRUCTS
		status = sigqueue(pid, aiocbp->aio_sigevent.sigev_signo, aiocbp->aio_sigevent.sigev_value);
#else
		status = sigqueue(pid, aiocbp->aio_sigevent.sigev_sign, aiocbp->aio_sigevent.sigev_value.sival_ptr);
#endif
		if (status < 0) {
			errcode = get_errno();
			fdbg("ERROR: sigqueue #1 failed: %d\n", errcode);
			ret = ERROR;
		}
	}

	/* Send the poll signal in any event in case the caller is waiting
	 * on sig_suspend();
	 */

#ifdef CONFIG_CAN_PASS_STRUCTS
	value.sival_ptr = aiocbp;
	status = sigqueue(pid, SIGPOLL, value);
#else
	status = sigqueue(pid, SIGPOLL, aiocbp);
#endif
	if (status && ret == OK) {
		errcode = get_errno();
		fdbg("ERROR: sigqueue #2 failed: %d\n", errcode);
		ret = ERROR;
	}

	/* Make sure that errno is set correctly on return */

	if (ret < 0) {
		set_errno(errcode);
		return ERROR;
	}

	return OK;
}

#endif							/* CONFIG_FS_AIO */
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
 * fs/aio/aio_write.c
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

#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sched.h>
#include <aio.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include "aio/aio.h"

#ifdef CONFIG_FS_AIO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: file_fcntl
 ****************************************************************************/

#ifdef AIO_HAVE_FILEP
static inline int file_fcntl(FAR struct file *filep, int cmd, ...)
{
	va_list ap;
	int ret;

	va_start(ap, cmd);
	ret = file_vfcntl(filep, cmd, ap);
	va_end(ap);
	return ret;
}
#endif

/****************************************************************************
 * Name: aio_write_worker
 *
 * Description:
 *   This function executes on the worker thread and performs the
 *   asynchronous I/O operation.
 *
 * Input Parameters:
 *   arg - Worker argument.  In this case, a pointer to an instance of
 *     struct aiocb cast to void *.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static void aio_write_worker(FAR void *arg)
{
	FAR struct aio_container_s *aioc = (FAR struct aio_container_s *)arg;
	FAR struct aiocb *aiocbp;
	pid_t pid;
#ifdef CONFIG_PRIORITY_INHERITANCE
	uint8_t prio;
#endif
	ssize_t nwritten = 0;
#ifdef AIO_HAVE_FILEP
	int oflags;
#endif

	/* Get the information from the container, decant the AIO control block,
	 * and free the container before starting any I/O.  That will minimize
	 * the delays by any other threads waiting for a pre-allocated container.
	 */

	DEBUGASSERT(aioc && aioc->aioc_aiocbp);
	pid = aioc->aioc_pid;
#ifdef CONFIG_PRIORITY_INHERITANCE
	prio = aioc->aioc_prio;
#endif
	aiocbp = aioc_decant(aioc);

#ifdef AIO_HAVE_FILEP
	{
		/* Call fcntl(F_GETFL) to get the file open mode. */

		oflags = file_fcntl(aioc->u.aioc_filep, F_GETFL);
		if (oflags < 0) {
			int errcode = get_errno();
			fdbg("ERROR: fcntl failed: %d\n", errcode);
			aiocbp->aio_result = -errcode;
			goto errout;
		}

		/* Perform the write using:
		 *
		 *   u.aioc_filep - File structure pointer
		 *   aio_buf      - Location of buffer
		 *   aio_nbytes   - Length of transfer
		 *   aio_offset   - File offset
		 */

		/* Check if O_APPEND is set in the file open flags */

		if ((oflags & O_APPEND) != 0) {
			/* Append to the current file position */

			nwritten = file_write(aioc->u.aioc_filep, (FAR const void *)aiocbp->aio_buf, aiocbp->aio_nbytes);
		} else {
			nwritten = file_pwrite(aioc->u.aioc_filep, (FAR const void *)aiocbp->aio_buf, aiocbp->aio_nbytes, aiocbp->aio_offset);
		}
	}
#endif

	/* Check the result of the write */

	if (nwritten < 0) {
		int errcode = get_errno();
		fdbg("ERROR: write/pwrite failed: %d\n", errcode);
		DEBUGASSERT(errcode > 0);
		aiocbp->aio_result = -errcode;
	} else {
		aiocbp->aio_result = nwritten;
	}

#ifdef AIO_HAVE_FILEP
errout:
#endif

	/* Signal the client */

	(void)aio_signal(pid, aiocbp);

#ifdef CONFIG_PRIORITY_INHERITANCE
	/* Restore the low priority worker thread default priority */

	lpwork_restorepriority(prio);
#endif
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: aio_write
 *
 * Description:
 *   The aio_write() function writes aiocbp->aio_nbytes to the file
 *   associated with aiocbp->aio_fildes from the buffer pointed to by
 *   aiocbp->aio_buf. The function call will return when the write request
 *   has been initiated or queued to the file or device (even when the data
 *   cannot be delivered immediately).
 *
 *   If prioritized I/O is supported for this file, then the asynchronous
 *   operation will be submitted at a priority equal to a base scheduling
 *   priority minus aiocbp->aio_reqprio. If Thread Execution Scheduling is
 *   not supported, then the base scheduling priority is that of the calling
 *   thread (the latter is implemented at present).
 *
 *   The aiocbp value may be used as an argument to aio_error() and
 *   aio_return() in order to determine the error status and return status,
 *   respectively, of the asynchronous operation while it is proceeding.
 *
 *   The aiocbp argument points to an aiocb structure. If the buffer pointed
 *   to by aiocbp->aio_buf or the control block pointed to by aiocbp becomes
 *   an illegal address prior to asynchronous I/O completion, then the
 *   behavior is undefined.
 *
 *   If O_APPEND is not set for the file descriptor aio_fildes, then the
 *   requested operation will take place at the absolute position in the file
 *   as given by aio_offset, as if lseek() were called immediately prior to the
 *   operation with an offset equal to aio_offset and a whence equal to SEEK_SET.
 *   If O_APPEND is set for the file descriptor, write operations append to the
 *   file in the same order as the calls were made. After a successful call to
 *   enqueue an asynchronous I/O operation, the value of the file offset for the
 *   file is unspecified.
 *
 *   The aiocbp->aio_lio_opcode field will be ignored by aio_write().
 *
 *   Simultaneous asynchronous operations using the same aiocbp produce
 *   undefined results.
 *
 *   For any system action that changes the process memory space while an
 *   synchronous I/O is outstanding to the address range being changed, the
 *   result of that action is undefined.
 *
 * Input Parameters:
 *   aiocbp - A pointer to an instance of struct aiocb
 *
 * Returned Value:
 *
 *   The aio_write() function will return the value zero if the I/O operation
 *   is successfully queued; otherwise, the function will return the value
 *   -1 and set errno to indicate the error.  The aio_write() function will
 *   ail if:
 *
 *   EAGAIN - The requested asynchronous I/O operation was not queued due to
 *     system resource limitations.
 *
 *   Each of the following conditions may be detected synchronously at the
 *   time of the call to aio_write(), or asynchronously. If any of the
 *   conditions below are detected synchronously, the aio_write() function
 *   will return -1 and set errno to the corresponding value. If any of the
 *   conditions below are detected asynchronously, the return status of the
 *   asynchronous operation is set to -1, and the error status of the
 *   asynchronous operation is set to the corresponding value.
 *
 *   EBADF - The aiocbp->aio_fildes argument is not a valid file descriptor
 *     open for writing.
 *   EINVAL - The file offset value implied by aiocbp->aio_offset would be
 *     invalid, aiocbp->aio_reqprio is not a valid value, or
 *     aiocbp->aio_nbytes is an invalid value.
 *
 *   In the case that the aio_write() successfully queues the I/O operation
 *   but the operation is subsequently cancelled or encounters an error, the
 *   return status of the asynchronous operation is one of the values
 *   normally returned by the write() function call. In addition, the error
 *   status of the asynchronous operation is set to one of the error
 *   statuses normally set by the write() function call, or one of the
 *   following values:
 *
 *   EBADF - The aiocbp->aio_fildes argument is not a valid file descriptor
 *     open for writing.
 *   EINVAL - The file offset value implied by aiocbp->aio_offset would be
 *     invalid.
 *   ECANCELED - The requested I/O was cancelled before the I/O completed
 *     due to an explicit aio_cancel() request.
 *
 * The following condition may be detected synchronously or asynchronously:
 *
 *   EFBIG - The file is a regular file, aiobcp->aio_nbytes is greater
 *     than 0, and the starting offset in aiobcp->aio_offset is at or
 *     beyond the offset maximum in the open file description associated
 *     with aiocbp->aio_fildes.
 *
 * POSIX Compliance:
 * - Most errors required in the standard are not detected at this point.
 *   There are no pre-queuing checks for the validity of the operation.
 *
 ****************************************************************************/

int aio_write(FAR struct aiocb *aiocbp)
{
	FAR struct aio_container_s *aioc;
	int ret;

	DEBUGASSERT(aiocbp);

	/* The result -EINPROGRESS means that the transfer has not yet completed */

	aiocbp->aio_result = -EINPROGRESS;
	aiocbp->aio_priv = NULL;

	/* Create a container for the AIO control block.  This may cause us to
	 * block if there are insufficient resources to satisfy the request.
	 */

	aioc = aio_contain(aiocbp);
	if (!aioc) {
		/* The errno has already been set (probably EBADF) */

		aiocbp->aio_result = -get_errno();
		return ERROR;
	}

	/* Defer the work to the worker thread */

	ret = aio_queue(aioc, aio_write_worker);
	if (ret < 0) {
		/* The result and the errno have already been set */

		return ERROR;
	}

	return OK;
}

#endif							/* CONFIG_FS_AIO */
