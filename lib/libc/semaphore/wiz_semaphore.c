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
 * lib/libc/semaphore/sem_getprotocol.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
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

#include <tinyara/semaphore.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function: sem_getprotocol
 *
 * Description:
 *    Return the value of the semaphore protocol attribute.
 *
 * Parameters:
 *    sem      - A pointer to the semaphore whose attributes are to be
 *               queried.
 *    protocol - The user provided location in which to store the protocol
 *               value.
 *
 * Return Value:
 *   0 if successful.  Otherwise, -1 is returned and the errno value is set
 *   appropriately.
 *
 ****************************************************************************/

int sem_getprotocol(FAR sem_t *sem, FAR int *protocol)
{
	if ((sem == NULL) || (protocol == NULL) || ((sem->flags & FLAGS_INITIALIZED) == 0)) {
		set_errno(EINVAL);
		return ERROR;
	}

#ifdef CONFIG_PRIORITY_INHERITANCE
	if ((sem->flags & PRIOINHERIT_FLAGS_DISABLE) != 0) {
		*protocol = SEM_PRIO_NONE;
	} else {
		*protocol = SEM_PRIO_INHERIT;
	}
#else
	*protocol = SEM_PRIO_NONE;
#endif

	return OK;
}
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
 * libc/semaphore/sem_getvalue.c
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

#include <sys/types.h>
#include <semaphore.h>
#include <errno.h>

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Global Variables
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
 * Function:  sem_getvalue
 *
 * Description:
 *   This function updates the location referenced by 'sval' argument to
 *   have the value of the semaphore referenced by 'sem' without effecting
 *   the state of the semaphore.  The updated value represents the actual
 *   semaphore value that occurred at some unspecified time during the call,
 *   but may not reflect the actual value of the semaphore when it is
 *   returned to the calling task.
 *
 *   If 'sem' is locked, the value return by sem_getvalue() will either be
 *   zero or a negative number whose absolute value represents the number
 *   of tasks waiting for the semaphore.
 *
 * Parameters:
 *   sem - Semaphore descriptor
 *   sval - Buffer by which the value is returned
 *
 * Return Value:
 *   0 (OK), or -1 (ERROR) if unsuccessful
 *
 * Assumptions:
 *
 ****************************************************************************/

int sem_getvalue(FAR sem_t *sem, FAR int *sval)
{
	if (sem && sval && ((sem->flags & FLAGS_INITIALIZED) != 0)) {
		*sval = sem->semcount;
		return OK;
	} else {
		set_errno(EINVAL);
		return ERROR;
	}
}
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
 * libc/sem/sem_init.c
 *
 *   Copyright (C) 2007-2009, 2011-2012, 2016 Gregory Nutt. All rights reserved.
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
#include <limits.h>
#include <semaphore.h>
#include <errno.h>

#ifdef CONFIG_SEMAPHORE_HISTORY
#include <tinyara/debug/sysdbg.h>
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function: sem_init
 *
 * Description:
 *   This function initializes the UNAMED semaphore sem. Following a
 *   successful call to sem_init(), the semaophore may be used in subsequent
 *   calls to sem_wait(), sem_post(), and sem_trywait().  The semaphore
 *   remains usable until it is destroyed.
 *
 *   Only sem itself may be used for performing synchronization. The result
 *   of referring to copies of sem in calls to sem_wait(), sem_trywait(),
 *   sem_post(), and sem_destroy() is undefined.
 *
 * Parameters:
 *   sem - Semaphore to be initialized
 *   pshared - Process sharing (not used)
 *   value - Semaphore initialization value
 *
 * Return Value:
 *   0 (OK), or -1 (ERROR) if unsuccessful.
 *
 * Assumptions:
 *
 ****************************************************************************/

int sem_init(FAR sem_t *sem, int pshared, unsigned int value)
{
	/* Verify that a semaphore was provided and the count is within the valid
	 * range.
	 */

	if (sem && value <= SEM_VALUE_MAX) {
		/* Initialize the seamphore count */

		sem->semcount = (int16_t)value;
#ifdef CONFIG_SEMAPHORE_HISTORY
		save_semaphore_history(sem, (void *)NULL, SEM_INIT);
#endif

		sem->flags = FLAGS_INITIALIZED;

		/* Initialize to support priority inheritance */

#ifdef CONFIG_PRIORITY_INHERITANCE
		sem->flags &= ~(PRIOINHERIT_FLAGS_DISABLE);
#if CONFIG_SEM_PREALLOCHOLDERS > 0
		sem->hhead = NULL;
#else
		sem->holder.htcb = NULL;
		sem->holder.counts = 0;
#endif
#endif
		return OK;
	} else {
		set_errno(EINVAL);
		return ERROR;
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
 * lib/libc/semaphore/sem_setprotocol.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
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

#include <tinyara/semaphore.h>

#ifndef CONFIG_PRIORITY_INHERITANCE

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function: sem_setprotocol
 *
 * Description:
 *    Set semaphore protocol attribute.
 *
 *    One particularly important use of this furnction is when a semaphore
 *    is used for inter-task communication like:
 *
 *      TASK A                 TASK B
 *      sem_init(sem, 0, 0);
 *      sem_wait(sem);
 *                             sem_post(sem);
 *      Awakens as holder
 *
 *    In this case priority inheritance can interfere with the operation of
 *    the semaphore.  The problem is that when TASK A is restarted it is a
 *    holder of the semaphore.  However, it never calls sem_post(sem) so it
 *    becomes *permanently* a holder of the semaphore and may have its
 *    priority boosted when any other task tries to acquire the semaphore.
 *
 *    The fix is to call sem_setprotocol(SEM_PRIO_NONE) immediately after
 *    the sem_init() call so that there will be no priority inheritance
 *    operations on this semaphore.
 *
 * Parameters:
 *    sem      - A pointer to the semaphore whose attributes are to be
 *               modified
 *    protocol - The new protocol to use
 *
 * Return Value:
 *   0 if successful.  Otherwise, -1 is returned and the errno value is set
 *   appropriately.
 *
 ****************************************************************************/

int sem_setprotocol(FAR sem_t *sem, int protocol)
{
	int errcode = EINVAL;

	if ((sem != NULL) && ((sem->flags & FLAGS_INITIALIZED) != 0)) {
		switch (protocol) {
		case SEM_PRIO_NONE:
			return OK;

		case SEM_PRIO_INHERIT:
		case SEM_PRIO_PROTECT:
			errcode = ENOSYS;
			break;

		default:
			errcode = EINVAL;
			break;
		}
	}

	set_errno(errcode);
	return ERROR;
}

#endif /* !CONFIG_PRIORITY_INHERITANCE */
   