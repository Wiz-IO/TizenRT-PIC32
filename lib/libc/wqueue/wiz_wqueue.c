/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
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
 * libc/wqueue/work_cancel.c
 *
 *   Copyright (C) 2009-2010, 2012-2014 Gregory Nutt. All rights reserved.
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

#include <queue.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/arch.h>
#include <tinyara/wqueue.h>

#include "wqueue/wqueue.h"

#if defined(CONFIG_LIB_USRWORK) && !defined(__KERNEL__)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: work_qcancel
 *
 * Description:
 *   Cancel previously queued work.  This removes work from the work queue.
 *   After work has been cancelled, it may be re-queue by calling work_queue()
 *   again.
 *
 * Input parameters:
 *   qid    - The work queue ID
 *   work   - The previously queue work structure to cancel
 *
 * Returned Value:
 *   Zero (OK) on success, a negated errno on failure.  This error may be
 *   reported:
 *
 *   -ENOENT - There is no such work queued.
 *   -EINVAL - An invalid work queue was specified
 *
 ****************************************************************************/

static int work_qcancel(FAR struct usr_wqueue_s *wqueue, FAR struct work_s *work)
{
	int ret = -ENOENT;

	DEBUGASSERT(work != NULL);

	/* Get exclusive access to the work queue */

	while (work_lock() < 0);

	/* Cancelling the work is simply a matter of removing the work structure
	 * from the work queue.  This must be done with interrupts disabled because
	 * new work is typically added to the work queue from interrupt handlers.
	 */

	if (work->worker != NULL) {
		/* A little test of the integrity of the work queue */

		DEBUGASSERT(work->dq.flink || (FAR dq_entry_t *)work == wqueue->q.tail);
		DEBUGASSERT(work->dq.blink || (FAR dq_entry_t *)work == wqueue->q.head);

		/* Remove the entry from the work queue and make sure that it is
		 * mark as available (i.e., the worker field is nullified).
		 */

		dq_rem((FAR dq_entry_t *)work, &wqueue->q);
		work->worker = NULL;
		ret = OK;
	}

	work_unlock();
	return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: work_cancel
 *
 * Description:
 *   Cancel previously queued user-mode work.  This removes work from the
 *   user mode work queue.  After work has been cancelled, it may be re-queue
 *   by calling work_queue() again.
 *
 * Input parameters:
 *   qid    - The work queue ID (must be USRWORK)
 *   work   - The previously queue work structure to cancel
 *
 * Returned Value:
 *   Zero (OK) on success, a negated errno on failure.  This error may be
 *   reported:
 *
 *   -ENOENT - There is no such work queued.
 *
 ****************************************************************************/

int work_cancel(int qid, FAR struct work_s *work)
{
	if (qid == USRWORK) {
		return work_qcancel(&g_usrwork, work);
	} else {
		return -EINVAL;
	}
}

#endif							/* CONFIG_LIB_USRWORK && !__KERNEL__ */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
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
 * libc/wqueue/work_lock.c
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

#include <pthread.h>
#include <semaphore.h>
#include <assert.h>
#include <errno.h>

#include "wqueue/wqueue.h"

#if defined(CONFIG_LIB_USRWORK) && !defined(__KERNEL__)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: work_lock
 *
 * Description:
 *   Lock the user-mode work queue.
 *
 * Input parameters:
 *   None
 *
 * Returned Value:
 *   Zero (OK) on success, a negated errno on failure.  This error may be
 *   reported:
 *
 *   -EINTR - Wait was interrupted by a signal
 *
 ****************************************************************************/

int work_lock(void)
{
	int ret;

#ifdef CONFIG_BUILD_PROTECTED
	ret = sem_wait(&g_usrsem);
	if (ret < 0) {
		DEBUGASSERT(errno == EINTR);
		return -EINTR;
	}
#else
	ret = pthread_mutex_lock(&g_usrmutex);
	if (ret != 0) {
		DEBUGASSERT(ret == EINTR);
		return -EINTR;
	}
#endif

	return ret;
}

/****************************************************************************
 * Name: work_unlock
 *
 * Description:
 *   Unlock the user-mode work queue.
 *
 * Input parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void work_unlock(void)
{
#ifdef CONFIG_BUILD_PROTECTED
	(void)sem_post(&g_usrsem);
#else
	(void)pthread_mutex_unlock(&g_usrmutex);
#endif
}

#endif							/* CONFIG_LIB_USRWORK && !__KERNEL__ */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
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
 * libc/wqueue/work_queue.c
 *
 *   Copyright (C) 2009-2011, 2014 Gregory Nutt. All rights reserved.
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
#include <signal.h>
#include <assert.h>
#include <queue.h>
#include <errno.h>

#include <tinyara/clock.h>
#include <tinyara/wqueue.h>

#include "wqueue/wqueue.h"

#if defined(CONFIG_LIB_USRWORK) && !defined(__KERNEL__)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: work_qqueue
 *
 * Description:
 *   Queue work to be performed at a later time.  All queued work will be
 *   performed on the worker thread of of execution (not the caller's).
 *
 *   The work structure is allocated by caller, but completely managed by
 *   the work queue logic.  The caller should never modify the contents of
 *   the work queue structure; the caller should not call work_queue()
 *   again until either (1) the previous work has been performed and removed
 *   from the queue, or (2) work_cancel() has been called to cancel the work
 *   and remove it from the work queue.
 *
 * Input parameters:
 *   qid    - The work queue ID (index)
 *   work   - The work structure to queue
 *   worker - The worker callback to be invoked.  The callback will invoked
 *            on the worker thread of execution.
 *   arg    - The argument that will be passed to the workder callback when
 *            int is invoked.
 *   delay  - Delay (in clock ticks) from the time queue until the worker
 *            is invoked. Zero means to perform the work immediately.
 *
 * Returned Value:
 *   Zero on success, a negated errno on failure
 *
 ****************************************************************************/

static int work_qqueue(FAR struct usr_wqueue_s *wqueue, FAR struct work_s *work, worker_t worker, FAR void *arg, uint32_t delay)
{
	DEBUGASSERT(work != NULL);

	/* First, initialize the work structure */

	work->worker = worker;		/* Work callback */
	work->arg = arg;			/* Callback argument */
	work->delay = delay;		/* Delay until work performed */

	/* Get exclusive access to the work queue */

	while (work_lock() < 0);

	/* Now, time-tag that entry and put it in the work queue. */

	work->qtime = clock();	/* Time work queued */

	dq_addlast((FAR dq_entry_t *)work, &wqueue->q);
	kill(wqueue->pid, SIGWORK);	/* Wake up the worker thread */

	work_unlock();
	return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: work_queue
 *
 * Description:
 *   Queue user-mode work to be performed at a later time.  All queued work
 *   will be performed on the worker thread of of execution (not the caller's).
 *
 *   The work structure is allocated by caller, but completely managed by
 *   the work queue logic.  The caller should never modify the contents of
 *   the work queue structure; the caller should not call work_queue()
 *   again until either (1) the previous work has been performed and removed
 *   from the queue, or (2) work_cancel() has been called to cancel the work
 *   and remove it from the work queue.
 *
 * Input parameters:
 *   qid    - The work queue ID (index)
 *   work   - The work structure to queue
 *   worker - The worker callback to be invoked.  The callback will invoked
 *            on the worker thread of execution.
 *   arg    - The argument that will be passed to the workder callback when
 *            int is invoked.
 *   delay  - Delay (in clock ticks) from the time queue until the worker
 *            is invoked. Zero means to perform the work immediately.
 *
 * Returned Value:
 *   Zero on success, a negated errno on failure
 *
 ****************************************************************************/

int work_queue(int qid, FAR struct work_s *work, worker_t worker, FAR void *arg, uint32_t delay)
{
	if (qid == USRWORK) {
		return work_qqueue(&g_usrwork, work, worker, arg, delay);
	} else {
		return -EINVAL;
	}
}

#endif							/* CONFIG_LIB_USRWORK && !__KERNEL__ */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
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
 * libc/wqueue/work_signal.c
 *
 *   Copyright (C) 2009-2014 Gregory Nutt. All rights reserved.
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

#include <signal.h>
#include <errno.h>

#include <tinyara/wqueue.h>

#include "wqueue/wqueue.h"

#if defined(CONFIG_LIB_USRWORK) && !defined(__KERNEL__)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
 * Name: work_signal
 *
 * Description:
 *   Signal the worker thread to process the work queue now.  This function
 *   is used internally by the work logic but could also be used by the
 *   user to force an immediate re-assessment of pending work.
 *
 * Input parameters:
 *   qid    - The work queue ID
 *
 * Returned Value:
 *   Zero on success, a negated errno on failure
 *
 ****************************************************************************/

int work_signal(int qid)
{
	int ret;

	if (qid == USRWORK) {
		/* Signal the worker thread */

		ret = kill(g_usrwork.pid, SIGWORK);
		if (ret < 0) {
			int errcode = errno;
			ret = -errcode;
		}
	} else {
		ret = -EINVAL;
	}

	return ret;
}

#endif							/* CONFIG_LIB_USRWORK && !__KERNEL__ */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
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
 * libc/wqueue/work_usrthread.c
 *
 *   Copyright (C) 2009-2014 Gregory Nutt. All rights reserved.
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
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <errno.h>
#include <assert.h>
#include <queue.h>

#include <tinyara/wqueue.h>
#include <tinyara/clock.h>

#include "wqueue/wqueue.h"

#if defined(CONFIG_LIB_USRWORK) && !defined(__KERNEL__)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Use CLOCK_MONOTONIC if it is available.  CLOCK_REALTIME can cause bad
 * delays if the time is changed.
 */

#ifdef CONFIG_CLOCK_MONOTONIC
#define WORK_CLOCK CLOCK_MONOTONIC
#else
#define WORK_CLOCK CLOCK_REALTIME
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* The state of the user mode work queue. */

struct usr_wqueue_s g_usrwork;

/* This semaphore supports exclusive access to the user-mode work queue */

#ifdef CONFIG_BUILD_PROTECTED
sem_t g_usrsem;
#else
pthread_mutex_t g_usrmutex;
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: work_process
 *
 * Description:
 *   This is the logic that performs actions placed on any work list.  This
 *   logic is the common underlying logic to all work queues.  This logic is
 *   part of the internal implementation of each work queue; it should not
 *   be called from application level logic.
 *
 * Input parameters:
 *   wqueue - Describes the work queue to be processed
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void work_process(FAR struct usr_wqueue_s *wqueue)
{
	volatile FAR struct work_s *work;
	worker_t worker;
	FAR void *arg;
	clock_t elapsed;
	uint32_t remaining;
	clock_t stick;
	clock_t ctick;
	uint32_t next;
	int ret;

	/* Then process queued work.  Lock the work queue while we process items
	 * in the work list.
	 */

	next = wqueue->delay;
	ret = work_lock();
	if (ret < 0) {
		/* Break out earlier if we were awakened by a signal */

		return;
	}

	/* Get the time that we started this polling cycle in clock ticks. */

	stick = clock();

	/* And check each entry in the work queue.  Since we have locked the
	 * work queue we know:  (1) we will not be suspended unless we do
	 * so ourselves, and (2) there will be no changes to the work queue
	 */

	work = (FAR struct work_s *)wqueue->q.head;
	while (work) {
		/* Is this work ready?  It is ready if there is no delay or if
		 * the delay has elapsed. qtime is the time that the work was added
		 * to the work queue.  It will always be greater than or equal to
		 * zero.  Therefore a delay of zero will always execute immediately.
		 */

		ctick = clock();
		elapsed = ctick - work->qtime;
		if (elapsed >= work->delay) {
			/* Remove the ready-to-execute work from the list */

			(void)dq_rem((struct dq_entry_s *)work, &wqueue->q);

			/* Extract the work description from the entry (in case the work
			 * instance by the re-used after it has been de-queued).
			 */

			worker = work->worker;

			/* Check for a race condition where the work may be nullified
			 * before it is removed from the queue.
			 */

			if (worker != NULL) {
				/* Extract the work argument (before unlocking the work queue) */

				arg = work->arg;

				/* Mark the work as no longer being queued */

				work->worker = NULL;

				/* Do the work.  Unlock the the work queue while the work is being
				 * performed... we don't have any idea how long this will take!
				 */

				work_unlock();
				worker(arg);

				/* Now, unfortunately, since we unlocked the work queue we don't
				 * know the state of the work list and we will have to start
				 * back at the head of the list.
				 */

				ret = work_lock();
				if (ret < 0) {
					/* Break out earlier if we were awakened by a signal */

					return;
				}

				work = (FAR struct work_s *)wqueue->q.head;
			} else {
				/* Cancelled.. Just move to the next work in the list with
				 * the work queue still locked.
				 */

				work = (FAR struct work_s *)work->dq.flink;
			}
		} else {				/* elapsed < work->delay */

			/* This one is not ready.
			 *
			 * NOTE that elapsed is relative to the the current time,
			 * not the time of beginning of this queue processing pass.
			 * So it may need an adjustment.
			 */

			elapsed += (ctick - stick);
			if (elapsed > work->delay) {
				/* The delay has expired while we are processing */

				elapsed = work->delay;
			}

			/* Will it be ready before the next scheduled wakeup interval? */

			remaining = work->delay - elapsed;
			if (remaining < next) {
				/* Yes.. Then schedule to wake up when the work is ready */

				next = remaining;
			}

			/* Then try the next in the list. */

			work = (FAR struct work_s *)work->dq.flink;
		}
	}

	/* Get the delay (in clock ticks) since we started the sampling */

	elapsed = clock() - stick;
	if (elapsed < wqueue->delay && next > 0) {
		/* How must time would we need to delay to get to the end of the
		 * sampling period?  The amount of time we delay should be the smaller
		 * of the time to the end of the sampling period and the time to the
		 * next work expiry.
		 */

		remaining = wqueue->delay - elapsed;
		next = MIN(next, remaining);

		/* Wait awhile to check the work list.  We will wait here until
		 * either the time elapses or until we are awakened by a signal.
		 * Interrupts will be re-enabled while we wait.
		 */

		usleep(next * USEC_PER_TICK);
	}

	work_unlock();
}

/****************************************************************************
 * Name: work_usrthread
 *
 * Description:
 *   This is the worker thread that performs the actions placed on the user
 *   work queue.
 *
 *   This is a user mode work queue.  It must be used by applications for
 *   miscellaneous operations.  The user work thread must be started by
 *   application start-up logic by calling work_usrstart().
 *
 * Input parameters:
 *   argc, argv (not used)
 *
 * Returned Value:
 *   Does not return
 *
 ****************************************************************************/

#ifdef CONFIG_BUILD_PROTECTED
static int work_usrthread(int argc, char *argv[])
#else
static pthread_addr_t work_usrthread(pthread_addr_t arg)
#endif
{
	/* Loop forever */

	for (;;) {
		/* Then process queued work.  We need to keep the work queue locked
		 * while we process items in the work list.
		 */

		work_process(&g_usrwork);
	}

#ifdef CONFIG_BUILD_PROTECTED
	return OK;					/* To keep some compilers happy */
#else
	return NULL;				/* To keep some compilers happy */
#endif
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: work_usrstart
 *
 * Description:
 *   Start the user mode work queue.
 *
 * Input parameters:
 *   None
 *
 * Returned Value:
 *   The task ID of the worker thread is returned on success.  A negated
 *   errno value is returned on failure.
 *
 ****************************************************************************/

int work_usrstart(void)
{
	/* Initialize work queue data structures */

	g_usrwork.delay = CONFIG_LIB_USRWORKPERIOD / USEC_PER_TICK;
	dq_init(&g_usrwork.q);

#ifdef CONFIG_BUILD_PROTECTED
	{
		/* Set up the work queue lock */

		(void)sem_init(&g_usrsem, 0, 1);

		/* Start a user-mode worker thread for use by applications. */

		g_usrwork.pid = task_create("uwork", CONFIG_LIB_USRWORKPRIORITY, CONFIG_LIB_USRWORKSTACKSIZE, (main_t)work_usrthread, (FAR char *const *)NULL);

		DEBUGASSERT(g_usrwork.pid > 0);
		if (g_usrwork.pid < 0) {
			int errcode = errno;
			DEBUGASSERT(errcode > 0);
			return -errcode;
		}

		return g_usrwork.pid;
	}
#else
	{
		pthread_t usrwork;
		pthread_attr_t attr;
		struct sched_param param;
		int status;

		/* Set up the work queue lock */

		(void)pthread_mutex_init(&g_usrmutex, NULL);

		/* Start a user-mode worker thread for use by applications. */

		(void)pthread_attr_init(&attr);
		(void)pthread_attr_setstacksize(&attr, CONFIG_LIB_USRWORKSTACKSIZE);

		param.sched_priority = CONFIG_LIB_USRWORKPRIORITY;
		(void)pthread_attr_setschedparam(&attr, &param);

		status = pthread_create(&usrwork, &attr, work_usrthread, NULL);
		if (status != 0) {
			return -status;
		}

		/* Detach because the return value and completion status will not be
		 * requested.
		 */

		(void)pthread_detach(usrwork);

		g_usrwork.pid = (pid_t)usrwork;
		return g_usrwork.pid;
	}
#endif
}

#endif							/* CONFIG_LIB_USRWORK && !__KERNEL__ */
   