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
 * mm/shm/shmat.c
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

#include <sys/shm.h>
#include <errno.h>

#include <tinyara/sched.h>
#include <tinyara/arch.h>
#include <tinyara/pgalloc.h>

#include "shm/shm.h"

#ifdef CONFIG_MM_SHM

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
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: shmat
 *
 * Description:
 *   The shmat() function attaches the shared memory segment associated with
 *   the shared memory identifier specified by shmid to the address space of
 *   the calling process. The segment is attached at the address specified
 *   by one of the following criteria:
 *
 *     - If shmaddr is a null pointer, the segment is attached at the first
 *       available address as selected by the system.
 *     - If shmaddr is not a null pointer and (shmflg & SHM_RND) is non-
 *       zero, the segment is attached at the address given by
 *       (shmaddr - ((uintptr_t)shmaddr % SHMLBA)).
 *     - If shmaddr is not a null pointer and (shmflg & SHM_RND) is 0, the
 *       segment is attached at the address given by shmaddr.
 *     - The segment is attached for reading if (shmflg & SHM_RDONLY) is
 *       non-zero and the calling process has read permission; otherwise, if
 *       it is 0 and the calling process has read and write permission, the
 *       segment is attached for reading and writing.
 *
 * Input Parameters:
 *   shmid  - Shared memory identifier
 *   smaddr - Determines mapping of the shared memory region
 *   shmflg - See SHM_* definitions in include/sys/shm.h.  Only SHM_RDONLY
 *            and SHM_RND are supported.
 *
 * Returned Value:
 *   Upon successful completion, shmat() will increment the value of
 *   shm_nattch in the data structure associated with the shared memory ID
 *   of the attached shared memory segment and return the segment's start
 *   address.
 *
 *   Otherwise, the shared memory segment will not be attached, shmat() will
 *   return -1, and errno will be set to indicate the error.
 *
 *     - EACCES
 *       Operation permission is denied to the calling process
 *     - EINVAL
 *       The value of shmid is not a valid shared memory identifier, the
 *       shmaddr is not a null pointer, and the value of
 *       (shmaddr -((uintptr_t)shmaddr % SHMLBA)) is an illegal address for
 *       attaching shared memory; or the shmaddr is not a null pointer,
 *       (shmflg & SHM_RND) is 0, and the value of shmaddr is an illegal
 *       address for attaching shared memory.
 *     - EMFILE
 *       The number of shared memory segments attached to the calling
 *       process would exceed the system-imposed limit.
 *     - ENOMEM
 *       The available data space is not large enough to accommodate the
 *       shared memory segment.
 *
 ****************************************************************************/

FAR void *shmat(int shmid, FAR const void *shmaddr, int shmflg)
{
	FAR struct shm_region_s *region;
	FAR struct task_group_s *group;
	FAR struct tcb_s *tcb;
	uintptr_t vaddr;
	unsigned int npages;
	int ret;

	/* Get the region associated with the shmid */

	DEBUGASSERT(shmid >= 0 && shmid < CONFIG_ARCH_SHM_MAXREGIONS);
	region = &g_shminfo.si_region[shmid];
	DEBUGASSERT((region->sr_flags & SRFLAG_INUSE) != 0);

	/* Get the TCB and group containing our virtual memory allocator */

	tcb = sched_self();
	DEBUGASSERT(tcb && tcb->group);
	group = tcb->group;
	DEBUGASSERT(group->tg_shm.gs_handle != NULL && group->tg_shm.gs_vaddr[shmid] == 0);

	/* Get exclusive access to the region data structure */

	ret = sem_wait(&region->sr_sem);
	if (ret < 0) {
		shmdbg("sem_wait failed: %d\n", ret);
		goto errout;
	}

	/* Set aside a virtual address space to span this physical region */

	vaddr = (uintptr_t)gran_alloc(group->tg_shm.gs_handle, region->sr_ds.shm_segsz);
	if (vaddr == 0) {
		shmdbg("gran_alloc() failed\n");
		ret = -ENOMEM;
		goto errout_with_semaphore;
	}

	/* Convert the region size to pages */

	npages = MM_PGALIGNUP(region->sr_ds.shm_segsz);

	/* Attach, i.e, map, on shared memory region to the user virtual address. */

	ret = up_shmat(region->sr_pages, npages, vaddr);
	if (ret < 0) {
		shmdbg("up_shmat() failed\n");
		goto errout_with_vaddr;
	}

	/* Save the virtual address of the region.  We will need that in shmat()
	 * to do the reverse lookup:  Give the virtual address of the region to
	 * detach, we need to get the region table index.
	 */

	group->tg_shm.gs_vaddr[shmid] = vaddr;

	/* Increment the count of processes attached to this region */

	region->sr_ds.shm_nattch++;

	/* Save the process ID of the the last operation */

	region->sr_ds.shm_lpid = tcb->pid;

	/* Save the time of the last shmat() */

	region->sr_ds.shm_atime = time(NULL);

	/* Release our lock on the entry */

	sem_post(&region->sr_sem);
	return (FAR void *)vaddr;

errout_with_vaddr:
	gran_free(group->tg_shm.gs_handle, (FAR void *)vaddr, region->sr_ds.shm_segsz);
errout_with_semaphore:
	sem_post(&region->sr_sem);
	set_errno(-ret);
errout:
	return (FAR void *)ERROR;
}

#endif							/* CONFIG_MM_SHM */
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
 * mm/shm/shmctl.c
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

#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>
#include <errno.h>
#include <assert.h>

#include <tinyara/mm/shm.h>
#include <tinyara/pgalloc.h>

#include "shm/shm.h"

#ifdef CONFIG_MM_SHM

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
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: shmctl
 *
 * Description:
 *   The shmctl() function provides a variety of shared memory control
 *   operations as specified by cmd. The following values for cmd are
 *   available:
 *
 *     - IPC_STAT
 *       Place the current value of each member of the shmid_ds data
 *       structure associated with shmid into the structure pointed to by
 *       buf.
 *     - IPC_SET
 *       Set the value of the shm_perm.mode member of the shmid_ds data
 *       structure associated with shmid to the corresponding value found
 *       in the structure pointed to by buf.
 *     - IPC_RMID
 *       Remove the shared memory identifier specified by shmid from the
 *       system and destroy the shared memory segment and shmid_ds data
 *       structure associated with it.
 *
 * Input Parameters:
 *   shmid - Shared memory identifier
 *   cmd - shmctl() command
 *   buf - Data associated with the shmctl() command
 *
 * Returned Value:
 *   Upon successful completion, shmctl() will return 0; otherwise, it will
 *   return -1 and set errno to indicate the error.
 *
 *     - EACCES
 *       The argument cmd is equal to IPC_STAT and the calling process does
 *       not have read permission.
 *     - EINVAL
 *       The value of shmid is not a valid shared memory identifier, or the
 *       value of cmd is not a valid command.
 *     - EPERM
 *       The argument cmd is equal to IPC_RMID or IPC_SET and the effective
 *       user ID of the calling process is not equal to that of a process
 *       with appropriate privileges and it is not equal to the value of
 *       shm_perm.cuid or shm_perm.uid in the data structure associated with
 *       shmid.
 *     - EOVERFLOW
 *       The cmd argument is IPC_STAT and the gid or uid value is too large
 *       to be stored in the structure pointed to by the buf argument.
 *
 * POSIX Deviations:
 *     - IPC_SET.  Does not set the the shm_perm.uid or shm_perm.gid
 *       members of the shmid_ds data structure associated with shmid
 *       because user and group IDs are not yet supported by TinyAra
 *     - IPC_SET.  Does not restrict the operation to processes with
 *       appropriate privileges or matching user IDs in shmid_ds data
 *       structure associated with shmid.  Again because user IDs and
 *       user/group privileges are are not yet supported by TinyAra
 *     - IPC_RMID.  Does not restrict the operation to processes with
 *       appropriate privileges or matching user IDs in shmid_ds data
 *       structure associated with shmid.  Again because user IDs and
 *       user/group privileges are are not yet supported by TinyAra
 *
 ****************************************************************************/

int shmctl(int shmid, int cmd, struct shmid_ds *buf)
{
	FAR struct shm_region_s *region;
	int ret;

	DEBUGASSERT(shmid >= 0 && shmid < CONFIG_ARCH_SHM_MAXREGIONS);
	region = &g_shminfo.si_region[shmid];
	DEBUGASSERT((region->sr_flags & SRFLAG_INUSE) != 0);

	/* Get exclusive access to the region data structure */

	ret = sem_wait(&region->sr_sem);
	if (ret < 0) {
		shmdbg("sem_wait failed: %d\n", ret);
		return ret;
	}

	/* Handle the request according to the received cmd */

	switch (cmd) {
	case IPC_STAT: {
		/* Place the current value of each member of the shmid_ds data
		 * structure associated with shmid into the structure pointed to
		 * by buf.
		 */

		DEBUGASSERT(buf);
		memcpy(buf, &region->sr_ds, sizeof(struct shmid_ds));
	}
	break;

	case IPC_SET: {
		/* Set the value of the shm_perm.mode member of the shmid_ds
		 * data structure associated with shmid to the corresponding
		 * value found in the structure pointed to by buf.
		 */

		region->sr_ds.shm_perm.mode = buf->shm_perm.mode;
	}
	break;

	case IPC_RMID: {
		/* Are any processes attached to the region? */

		if (region->sr_ds.shm_nattch > 0) {
			/* Yes.. just set the UNLINKED flag.  The region will be removed when there are no longer any processes attached to it.
			 */

			region->sr_flags |= SRFLAG_UNLINKED;
		} else {
			/* No.. free the entry now */

			shm_destroy(shmid);

			/* Don't try anything further on the deleted region */

			return OK;
		}
	}
	break;

	default:
		shmdbg("Unrecognized command: %d\n", cmd);
		ret = -EINVAL;
		goto errout_with_semaphore;
	}

	/* Save the process ID of the the last operation */

	region = &g_shminfo.si_region[shmid];
	region->sr_ds.shm_lpid = getpid();

	/* Save the time of the last shmctl() */

	region->sr_ds.shm_ctime = time(NULL);

	/* Release our lock on the entry */

	sem_post(&region->sr_sem);
	return ret;

errout_with_semaphore:
	sem_post(&region->sr_sem);
	set_errno(-ret);
	return ERROR;
}

/****************************************************************************
 * Name: shm_destroy
 *
 * Description:
 *   Destroy a memory region.  This function is called:
 *
 *   - On certain conditions when shmget() is not successful in instantiating
 *     the full memory region and we need to clean up and free a table entry.
 *   - When shmctl() is called with cmd == IPC_RMID and there are no
 *     processes attached to the memory region.
 *   - When shmdt() is called after the last process detaches from memory
 *     region after it was previously marked for deletion by shmctl().
 *
 * Input Parameters:
 *   shmid - Shared memory identifier
 *
 * Returned Value:
 *   None
 *
 * Assumption:
 *   The caller holds either the region table semaphore or else the
 *   semaphore on the particular entry being deleted.
 *
 ****************************************************************************/

void shm_destroy(int shmid)
{
	FAR struct shm_region_s *region = &g_shminfo.si_region[shmid];
	int i;

	/* Free all of the allocated physical pages */

	for (i = 0; i < CONFIG_ARCH_SHM_NPAGES && region->sr_pages[i] != 0; i++) {
		mm_pgfree(region->sr_pages[i], 1);
	}

	/* Reset the region entry to its initial state */

	sem_destroy(&region->sr_sem);
	memset(region, 0, sizeof(struct shm_region_s));
}

#endif							/* CONFIG_MM_SHM */
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
 * mm/shm/shmdt.c
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

#include <sys/shm.h>
#include <errno.h>

#include <tinyara/arch.h>
#include <tinyara/sched.h>
#include <tinyara/mm/shm.h>

#include "shm/shm.h"

#ifdef CONFIG_MM_SHM

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
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: shmdt
 *
 * Description:
 *   The shmdt() function detaches the shared memory segment located at the
 *   address specified by shmaddr from the address space of the calling
 *   process.
 *
 * Input Parameters:
 *   shmid - Shared memory identifier
 *
 * Returned Value:
 *   Upon successful completion, shmdt() will decrement the value of
 *   shm_nattch in the data structure associated with the shared memory ID
 *   of the attached shared memory segment and return 0.
 *
 *   Otherwise, the shared memory segment will not be detached, shmdt()
 &   will return -1, and errno will be set to indicate the error.
 *
 *   - EINVAL
 *     The value of shmaddr is not the data segment start address of a
 *     shared memory segment.
 *
 ****************************************************************************/

int shmdt(FAR const void *shmaddr)
{
	FAR struct shm_region_s *region;
	FAR struct task_group_s *group;
	FAR struct tcb_s *tcb;
	unsigned int npages;
	int shmid;
	int ret;

	/* Get the TCB and group containing our virtual memory allocator */

	tcb = sched_self();
	DEBUGASSERT(tcb && tcb->group);
	group = tcb->group;
	DEBUGASSERT(group->tg_shm.gs_handle != NULL);

	/* Perform the reverse lookup to get the shmid corresponding to this
	 * shmaddr.
	 */

	for (shmid = 0; shmid < CONFIG_ARCH_SHM_MAXREGIONS && group->tg_shm.gs_vaddr[shmid] != (uintptr_t)shmaddr; shmid++) ;

	if (shmid >= CONFIG_ARCH_SHM_MAXREGIONS) {
		shmdbg("No region matching this virtual address: %p\n", shmaddr);
		ret = -EINVAL;
		goto errout_with_errno;
	}

	/* Get the region associated with the shmid */

	region = &g_shminfo.si_region[shmid];
	DEBUGASSERT((region->sr_flags & SRFLAG_INUSE) != 0);

	/* Get exclusive access to the region data structure */

	ret = sem_wait(&region->sr_sem);
	if (ret < 0) {
		shmdbg("sem_wait failed: %d\n", ret);
		goto errout;
	}

	/* Free the virtual address space */

	gran_free(group->tg_shm.gs_handle, (FAR void *)shmaddr, region->sr_ds.shm_segsz);

	/* Convert the region size to pages */

	npages = MM_PGALIGNUP(region->sr_ds.shm_segsz);

	/* Detach, i.e, unmap, on shared memory region from a user virtual
	 * address.
	 */

	ret = up_shmdt((uintptr_t)shmaddr, npages);
	if (ret < 0) {
		shmdbg("up_shmdt() failed\n");
	}

	/* Indicate that there is no longer any mapping for this region. */

	group->tg_shm.gs_vaddr[shmid] = 0;

	/* Decrement the count of processes attached to this region.
	 * If the count decrements to zero and there is a pending unlink,
	 * then destroy the shared memory region now and stop any further
	 * operations on it.
	 */

	DEBUGASSERT(region->sr_ds.shm_nattch > 0);
	if (region->sr_ds.shm_nattch <= 1) {
		region->sr_ds.shm_nattch = 0;
		if ((region->sr_flags & SRFLAG_UNLINKED) != 0) {
			shm_destroy(shmid);
			return OK;
		}
	} else {
		/* Just decrement the number of processes attached to the shared
		 * memory region.
		 */

		region->sr_ds.shm_nattch--;
	}

	/* Save the process ID of the the last operation */

	region->sr_ds.shm_lpid = tcb->pid;

	/* Save the time of the last shmdt() */

	region->sr_ds.shm_dtime = time(NULL);

	/* Release our lock on the entry */

	sem_post(&region->sr_sem);
	return OK;

errout_with_errno:
	set_errno(-ret);
errout:
	return ERROR;
}

#endif							/* CONFIG_MM_SHM */
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
 * mm/shm/shmget.c
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

#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>

#include <tinyara/pgalloc.h>
#include <tinyara/mm/shm.h>

#include "shm/shm.h"

#ifdef CONFIG_MM_SHM

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
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: shm_find
 *
 * Description:
 *   Find the shared memory region with matching key
 *
 * Input parameters:
 *   key - The value that uniquely identifies a shared memory region.
 *
 * Returned value:
 *   On success, an index in the range of 0 to CONFIG_ARCH_SHM_MAXREGIONS-1
 *   is returned to identify the matching region; -ENOENT is returned on
 *   failure.
 *
 ****************************************************************************/

static int shm_find(key_t key)
{
	int i;

	for (i = 0; i < CONFIG_ARCH_SHM_MAXREGIONS; i++) {
		if (g_shminfo.si_region[i].sr_key == key) {
			return i;
		}
	}

	return -ENOENT;
}

/****************************************************************************
 * Name: shm_reserve
 *
 * Description:
 *   Allocate an unused shared memory region.  That is one with a key of -1
 *
 * Input parameters:
 *   None
 *
 * Returned value:
 *   On success, an index in the range of 0 to CONFIG_ARCH_SHM_MAXREGIONS-1
 *   is returned to identify the matching region; -ENOSPC is returned on
 *   failure.
 *
 ****************************************************************************/

static int shm_reserve(key_t key, int shmflg)
{
	FAR struct shm_region_s *region;
	int i;

	for (i = 0; i < CONFIG_ARCH_SHM_MAXREGIONS; i++) {
		/* Is this region in use? */

		region = &g_shminfo.si_region[i];
		if (region->sr_flags == SRFLAG_AVAILABLE) {
			/* No... reserve it for the caller now */

			memset(region, 0, sizeof(struct shm_region_s));
			region->sr_key = key;
			region->sr_flags = SRFLAG_INUSE;

			sem_init(&region->sr_sem, 0, 1);

			/* Set the low-order nine bits of shm_perm.mode to the low-order
			 * nine bits of shmflg.
			 */

			region->sr_ds.shm_perm.mode = shmflg & IPC_MODE;

			/* The value of shm_segsz is left equal to zero for now because no
			 * memory has yet been allocated.
			 *
			 * The values of shm_lpid, shm_nattch, shm_atime, and shm_dtime are
			 * set equal to 0.
			 */

			/* The value of shm_ctime is set equal to the current time. */

			region->sr_ds.shm_ctime = time(NULL);
			return i;
		}
	}

	return -ENOSPC;
}

/****************************************************************************
 * Name: shm_extend
 *
 * Description:
 *   Extend the size of a memory regions by allocating physical pages as
 *   necessary
 *
 * Input parameters:
 *   shmid - The index of the region of interest in the shared memory region
 *     table.
 *   size - The new size of the region.
 *
 * Returned value:
 *   Zero is returned on success; -ENOMEM is returned on failure.
 *   (Should a different error be returned if the region is just too big?)
 *
 ****************************************************************************/

static int shm_extend(int shmid, size_t size)
{
	FAR struct shm_region_s *region = &g_shminfo.si_region[shmid];
	unsigned int pgalloc;
	unsigned int pgneeded;

	/* This is the number of pages that are needed to satisfy the allocation */

	pgneeded = MM_PGALIGNUP(size);

	/* This is the number of pages that have already been allocated */

	pgalloc = MM_PGALIGNUP(region->sr_ds.shm_segsz);

	/* Loop until all pages have been allocated (or something bad happens) */

	while (pgalloc < pgneeded && pgalloc < CONFIG_ARCH_SHM_NPAGES) {
		/* Allocate one more physical page */

		region->sr_pages[pgalloc] = mm_pgalloc(1);
		if (region->sr_pages[pgalloc] == 0) {
			shmdbg("mm_pgalloc(1) failed\n");
			break;
		}

		/* Increment the number of pages successully allocated */

		pgalloc++;
	}

	/* We get here (1) because all of the pages were successfully, (2) because
	 * mm_pgalloc() failed, or (3) because any additional pages allocated
	 * would exceed CONFIG_ARCH_SHM_NPAGES.
	 */

	if (pgalloc < pgneeded) {
		/* Set the amount memory available which will be less than the
		 * requested size.
		 */

		region->sr_ds.shm_segsz = pgalloc << MM_PGSHIFT;
		return -ENOMEM;
	}

	/* Set the new region size and return success */

	region->sr_ds.shm_segsz = size;
	return OK;
}

/****************************************************************************
 * Name: shm_create
 *
 * Description:
 *   Create the shared memory region.
 *
 * Input parameters:
 *   key     - The key that is used to access the unique shared memory
 *             identifier.
 *   size    - The shared memory region that is created will be at least
 *             this size in bytes.
 *   shmflgs - See IPC_* definitions in sys/ipc.h.  Only the values
 *             IPC_PRIVATE or IPC_CREAT are supported.
 *
 * Returned value:
 *   Zero is returned on success;  A negated errno value is returned on
 *   failure.
 *
 ****************************************************************************/

static int shm_create(key_t key, size_t size, int shmflg)
{
	FAR struct shm_region_s *region;
	int shmid;
	int ret;

	/* Reserve the shared memory region */

	ret = shm_reserve(key, shmflg);
	if (ret < 0) {
		shmdbg("shm_reserve failed: %d\n", ret);
		return ret;
	}

	/* Save the shared memory ID */

	shmid = ret;

	/* Then allocate the physical memory (by extending it from the initial
	 * size of zero).
	 */

	ret = shm_reserve(shmid, size);
	if (ret < 0) {
		/* Free any partial allocations and unreserve the region */

		shm_destroy(shmid);
		return ret;
	}

	/* Save the process ID of the creator */

	region = &g_shminfo.si_region[shmid];
	region->sr_ds.shm_cpid = getpid();

	/* Return the shared memory ID */

	return shmid;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: shmget
 *
 * Description:
 *   The shmget() function will return the shared memory identifier
 *   associated with key.
 *
 *   A shared memory identifier, associated data structure, and shared
 *   memory segment of at least size bytes is created for key if one of the
 *   following is true:
 *
 *     - The argument key is equal to IPC_PRIVATE.
 *     - The argument key does not already have a shared memory identifier
 *       associated with it and (shmflg & IPC_CREAT) is non-zero.
 *
 *   Upon creation, the data structure associated with the new shared memory
 *   identifier will be initialized as follows:
 *
 *     - The low-order nine bits of shm_perm.mode are set equal to the low-
 *       order nine bits of shmflg.
 *     - The value of shm_segsz is set equal to the value of size.
 *     - The values of shm_lpid, shm_nattch, shm_atime, and shm_dtime are
 *       set equal to 0.
 *     - The value of shm_ctime is set equal to the current time.
 *
 *   When the shared memory segment is created, it will be initialized with
 *   all zero values.
 *
 * Input Parameters:
 *   key     - The key that is used to access the unique shared memory
 *             identifier.
 *   size    - The shared memory region that is created will be at least
 *             this size in bytes.
 *   shmflgs - See IPC_* definitions in sys/ipc.h.  Only the values
 *             IPC_PRIVATE or IPC_CREAT are supported.
 *
 * Returned Value:
 *   Upon successful completion, shmget() will return a non-negative
 *   integer, namely a shared memory identifier; otherwise, it will return
 *   -1 and set errno to indicate the error.
 *
 *     - EACCES
 *       A shared memory identifier exists for key but operation permission
 *       as specified by the low-order nine bits of shmflg would not be
 *       granted.
 *     - EEXIST
 *       A shared memory identifier exists for the argument key but
 *      (shmflg & IPC_CREAT) && (shmflg & IPC_EXCL) are non-zero.
 *     - EINVAL
 *       A shared memory segment is to be created and the value of size is
 *       less than the system-imposed minimum or greater than the system-
 *       imposed maximum.
 *     - EINVAL
 *       No shared memory segment is to be created and a shared memory
 *       segment exists for key but the size of the segment associated with
 *       it is less than size and size is not 0.
 *     - ENOENT
 *       A shared memory identifier does not exist for the argument key and
 *       (shmflg & IPC_CREAT) is 0.
 *     - ENOMEM
 *       A shared memory identifier and associated shared memory segment
 *       will be created, but the amount of available physical memory is
 *       not sufficient to fill the request.
 *     - ENOSPC
 *       A shared memory identifier is to be created, but the system-imposed
 *       limit on the maximum number of allowed shared memory identifiers
 *       system-wide would be exceeded.
 *
 * POSIX Deviations:
 *     - The values of shm_perm.cuid, shm_perm.uid, shm_perm.cgid, and
 *       shm_perm.gid should be set equal to the effective user ID and
 *       effective group ID, respectively, of the calling process.
 *       The TinyAra ipc_perm structure, however, does not support these
 *       fields because user and group IDs are not yet supported by TinyAra.
 *
 ****************************************************************************/

int shmget(key_t key, size_t size, int shmflg)
{
	FAR struct shm_region_s *region;
	int shmid = -1;
	int ret;

	/* Check for the special case where the caller doesn't really want shared
	 * memory (they why do they bother to call us?)
	 */

	if (key == IPC_PRIVATE) {
		/* Not yet implemented */

		ret = -ENOSYS;
		goto errout;
	}

	/* Get exclusive access to the global list of shared memory regions */

	ret = sem_wait(&g_shminfo.si_sem);
	if (ret >= 0) {
		/* Find the requested memory region */

		ret = shm_find(key);
		if (ret < 0) {
			/* The memory region does not exist.. create it if IPC_CREAT is
			 * included in the shmflags.
			 */

			if ((shmflg & IPC_CREAT) != 0) {
				/* Create the memory region */

				ret = shm_create(key, size, shmflg);
				if (ret < 0) {
					shmdbg("shm_create failed: %d\n", ret);
					goto errout_with_semaphore;
				}

				/* Return the shared memory ID */

				shmid = ret;
			} else {
				/* Fail with ENOENT */

				goto errout_with_semaphore;
			}
		}

		/* The region exists */

		else {
			/* Remember the shared memory ID */

			shmid = ret;

			/* Is the region big enough for the request? */

			region = &g_shminfo.si_region[shmid];
			if (region->sr_ds.shm_segsz < size) {
				/* We we asked to create the region?  If so we can just
				 * extend it.
				 *
				 * REVISIT: We should check the mode bits of the regions
				 * first
				 */

				if ((shmflg & IPC_CREAT) != 0) {
					/* Extend the region */

					ret = shm_extend(shmid, size);
					if (ret < 0) {
						shmdbg("shm_create failed: %d\n", ret);
						goto errout_with_semaphore;
					}
				} else {
					/* Fail with EINVAL */

					ret = -EINVAL;
					goto errout_with_semaphore;
				}
			}

			/* The region is already big enough or else we successfully
			 * extended the size of the region.  If the region was previously
			 * deleted, but waiting for processes to detach from the region,
			 * then it is no longer deleted.
			 */

			region->sr_flags = SRFLAG_INUSE;
		}

		/* Release our lock on the shared memory region list */

		sem_post(&g_shminfo.si_sem);
	}

	return shmid;

errout_with_semaphore:
	sem_post(&g_shminfo.si_sem);
errout:
	set_errno(-ret);
	return ERROR;
}

#endif							/* CONFIG_MM_SHM */
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
 * mm/shm/shm_initialize.c
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

#include <assert.h>
#include <errno.h>

#include <tinyara/addrenv.h>
#include <tinyara/sched.h>
#include <tinyara/mm/gran.h>
#include <tinyara/pgalloc.h>
#include <tinyara/mm/shm.h>

#include "shm/shm.h"

#ifdef CONFIG_MM_SHM

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* State of the all shared memory */

struct shm_info_s g_shminfo;

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: shm_initialize
 *
 * Description:
 *   Perform one time, start-up initialization of the shared memor logic.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void shm_initialize(void)
{
#if 0
	FAR struct shm_region_s *region;
	int i;
#endif

	/* Initialize the shared memory region list */

	sem_init(&g_shminfo.si_sem, 0, 1);

#if 0
	/* Initialize each shared memory region */

	for (i = 0; i < CONFIG_ARCH_SHM_NPAGES; i++) {
		region = &g_shminfo.si_region[i];

		/* Nothing to be done */
	}
#endif
}

/****************************************************************************
 * Name: shm_group_initialize
 *
 * Description:
 *   Initialize the group shared memory data structures when a new task
 *   group is initialized.
 *
 * Input Parameters:
 *   group - A reference to the new group structure to be initialized.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int shm_group_initialize(FAR struct task_group_s *group)
{
	DEBUGASSERT(group && !group->tg_shm.gs_handle);

	group->tg_shm.gs_handle = gran_initialize((FAR void *)CONFIG_ARCH_SHM_VBASE, ARCH_SHM_MAXPAGES << MM_PGSHIFT, MM_PGSHIFT, MM_PGSHIFT);

	if (!group->tg_shm.gs_handle) {
		shmdbg("gran_initialize() failed\n");
		return -ENOMEM;
	}

	return OK;
}

/****************************************************************************
 * Name: shm_group_release
 *
 * Description:
 *   Release resources used by the group shared memory logic.  This function
 *   is called at the time at the group is destroyed.
 *
 * Input Parameters:
 *   group - A reference to the group structure to be un-initialized.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void shm_group_release(FAR struct task_group_s *group)
{
	GRAN_HANDLE handle;
	DEBUGASSERT(group)

	handle = group->tg_shm.gs_handle;
	if (handle) {
		gran_release(handle);
	}
}

#endif							/* CONFIG_MM_SHM */
