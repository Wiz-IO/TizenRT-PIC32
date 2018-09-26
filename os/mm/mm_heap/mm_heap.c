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
 * mm/mm_heap/mm_addfreechunk.c
 *
 *   Copyright (C) 2007, 2009, 2013 Gregory Nutt. All rights reserved.
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

#include <tinyara/mm/mm.h>

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
 * Name: mm_addfreechunk
 *
 * Description:
 *   Add a free chunk to the node next.  It is assumed that the caller holds
 *   the mm semaphore
 *
 ****************************************************************************/

void mm_addfreechunk(FAR struct mm_heap_s *heap, FAR struct mm_freenode_s *node)
{
	FAR struct mm_freenode_s *next;
	FAR struct mm_freenode_s *prev;

	/* Convert the size to a nodelist index */

	int ndx = mm_size2ndx(node->size);

	/* Now put the new node int the next */

	for (prev = &heap->mm_nodelist[ndx], next = heap->mm_nodelist[ndx].flink; next && next->size && next->size < node->size; prev = next, next = next->flink) ;

	/* Does it go in mid next or at the end? */

	prev->flink = node;
	node->blink = prev;
	node->flink = next;

	if (next) {
		/* The new node goes between prev and next */

		next->blink = node;
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
 * mm/mm_heap/mm_brkaddr.c
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

#include <tinyara/mm/mm.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_brkaddr
 *
 * Description:
 *   Return the break address of a heap region.  Zero is returned if the
 *   memory region is not initialized.
 *
 ****************************************************************************/

FAR void *mm_brkaddr(FAR struct mm_heap_s *heap, int region)
{
	uintptr_t brkaddr;
#if CONFIG_MM_REGIONS > 1
	DEBUGASSERT(heap && region < heap->mm_nregions);
#else
	DEBUGASSERT(heap && region == 0);
#endif

	brkaddr = (uintptr_t)heap->mm_heapend[region];
	return brkaddr ? (FAR void *)(brkaddr + SIZEOF_MM_ALLOCNODE) : 0;
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
 * mm/mm_heap/mm_calloc.c
 *
 *   Copyright (C) 2007, 2009, 2014 Gregory Nutt. All rights reserved.
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

#include <tinyara/mm/mm.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_calloc
 *
 * Descriptor:
 *   mm_calloc() calculates the size of the allocation and calls mm_zalloc()
 *
 ****************************************************************************/

#ifdef CONFIG_DEBUG_MM_HEAPINFO
FAR void *mm_calloc(FAR struct mm_heap_s *heap, size_t n, size_t elem_size, mmaddress_t caller_retaddr)
#else
FAR void *mm_calloc(FAR struct mm_heap_s *heap, size_t n, size_t elem_size)
#endif
{
	FAR void *ret = NULL;

	if (n > 0 && elem_size > 0) {
#ifdef CONFIG_DEBUG_MM_HEAPINFO
		ret = mm_zalloc(heap, n * elem_size, caller_retaddr);
#else
		ret = mm_zalloc(heap, n * elem_size);
#endif
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
 * mm/mm_heap/mm_extend.c
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

#include <tinyara/mm/mm.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define MIN_EXTEND (2 * SIZEOF_MM_ALLOCNODE)

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_extend
 *
 * Description:
 *   Extend a heap region by add a block of (virtually) contiguous memory
 *   to the end of the heap.
 *
 ****************************************************************************/

void mm_extend(FAR struct mm_heap_s *heap, FAR void *mem, size_t size, int region)
{
	struct mm_allocnode_s *oldnode;
	struct mm_allocnode_s *newnode;
	uintptr_t blockstart;
	uintptr_t blockend;

	/* Make sure that we were passed valid parameters */

	DEBUGASSERT(heap && mem);
#if CONFIG_MM_REGIONS > 1
	DEBUGASSERT(size >= MIN_EXTEND && (unsigned)region < heap->mm_nregions);
#else
	DEBUGASSERT(size >= MIN_EXTEND && (unsigned)region == 0);
#endif

	/* Make sure that the memory region are properly aligned */

	blockstart = (uintptr_t)mem;
	blockend   = blockstart + size;

	DEBUGASSERT(MM_ALIGN_UP(blockstart) == blockstart);
	DEBUGASSERT(MM_ALIGN_DOWN(blockend) == blockend);

	/* Take the memory manager semaphore */

	mm_takesemaphore(heap);

	/* Get the terminal node in the old heap.  The block to extend must
	 * immediately follow this node.
	 */

	oldnode = heap->mm_heapend[region];
	DEBUGASSERT((uintptr_t)oldnode + SIZEOF_MM_ALLOCNODE == (uintptr_t)mem);

	/* The size of the old node now extends to the new terminal node.
	 * This is the old size (SIZEOF_MM_ALLOCNODE) plus the size of
	 * the block (size) minus the size of the new terminal node
	 * (SIZEOF_MM_ALLOCNODE) or simply:
	 */

	oldnode->size = size;

	/* The old node should already be marked as allocated */

	DEBUGASSERT((oldnode->preceding & MM_ALLOC_BIT) != 0);

	/* Get and initialize the new terminal node in the heap */

	newnode            = (FAR struct mm_allocnode_s *)(blockend - SIZEOF_MM_ALLOCNODE);
	newnode->size      = SIZEOF_MM_ALLOCNODE;
	newnode->preceding = oldnode->size | MM_ALLOC_BIT;

	heap->mm_heapend[region] = newnode;
	mm_givesemaphore(heap);

	/* Finally "free" the new block of memory where the old terminal node was
	 * located.
	 */

	mm_free(heap, (FAR void *)mem);
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
 * mm/mm_heap/mm_free.c
 *
 *   Copyright (C) 2007, 2009, 2013-2014 Gregory Nutt. All rights reserved.
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
#include <debug.h>

#include <tinyara/mm/mm.h>

#ifdef CONFIG_DEBUG_MM_HEAPINFO
#include  <tinyara/sched.h>
#endif
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
 * Name: mm_free
 *
 * Description:
 *   Returns a chunk of memory to the list of free nodes,  merging with
 *   adjacent free chunks if possible.
 *
 ****************************************************************************/
void mm_free(FAR struct mm_heap_s *heap, FAR void *mem)
{
	FAR struct mm_freenode_s *node;
	FAR struct mm_freenode_s *prev;
	FAR struct mm_freenode_s *next;
#ifdef CONFIG_DEBUG_MM_HEAPINFO
	struct mm_allocnode_s *alloc_node;
#endif

	mvdbg("Freeing %p\n", mem);

	/* Protect against attempts to free a NULL reference */

	if (!mem) {
#ifdef CONFIG_DEBUG_DOUBLE_FREE
		/* Though it's permitted to attempt for releasing a NULL
		 * reference in C, it would be good to catch those cases
		 * atleast in DEBUG MODE as there is no logical reason to
		 * release a NULL reference.
		 * It can be a logical bug in sw to make an attempt of double free!
		 * free(ptr); ptr = NULL; free(ptr);
		 */
		dbg("Attempt to release a null pointer\n");
#endif
		return;
	}

	/* We need to hold the MM semaphore while we muck with the
	 * nodelist.
	 */

	mm_takesemaphore(heap);

	/* Map the memory chunk into a free node */

	node = (FAR struct mm_freenode_s *)((char *)mem - SIZEOF_MM_ALLOCNODE);
#ifdef CONFIG_DEBUG_DOUBLE_FREE
	/* Assert on following logical error scenarios
	 * 1) Attempt to free an unallocated memory or
	 * 2) Attempt to release some arbitrary memory or
	 * 3) Attempt to release already released memory ( double free )
	 * Catch this bug and report to USER in debug mode
	 * 1st scenario: int *ptr; free(ptr);
	 * 2nd scenario: int *ptr = (int*)0x02069f50; free(ptr);
	 * 3rd scenario: ptr = malloc(100); free(ptr); if(ptr) { free(ptr); }
	 */
	if ((node->preceding & MM_ALLOC_BIT) != MM_ALLOC_BIT) {
		dbg("Attempt for double freeing a pointer or releasing an unallocated pointer\n");
		PANIC();
	}

#endif
#ifdef CONFIG_DEBUG_MM_HEAPINFO
	alloc_node = (struct mm_allocnode_s *)node;

	if ((alloc_node->preceding & MM_ALLOC_BIT) != 0) {
		heapinfo_subtract_size(alloc_node->pid, alloc_node->size);
		heapinfo_update_total_size(heap, ((-1) * alloc_node->size), alloc_node->pid);
	}
#endif
	node->preceding &= ~MM_ALLOC_BIT;

	/* Check if the following node is free and, if so, merge it */

	next = (FAR struct mm_freenode_s *)((char *)node + node->size);
	if ((next->preceding & MM_ALLOC_BIT) == 0) {
		FAR struct mm_allocnode_s *andbeyond;

		/* Get the node following the next node (which will
		 * become the new next node). We know that we can never
		 * index past the tail chunk because it is always allocated.
		 */

		andbeyond = (FAR struct mm_allocnode_s *)((char *)next + next->size);

		/* Remove the next node.  There must be a predecessor,
		 * but there may not be a successor node.
		 */

		DEBUGASSERT(next->blink);
		next->blink->flink = next->flink;
		if (next->flink) {
			next->flink->blink = next->blink;
		}

		/* Then merge the two chunks */

		node->size          += next->size;
		andbeyond->preceding = node->size | (andbeyond->preceding & MM_ALLOC_BIT);
		next                 = (FAR struct mm_freenode_s *)andbeyond;
	}

	/* Check if the preceding node is also free and, if so, merge
	 * it with this node
	 */

	prev = (FAR struct mm_freenode_s *)((char *)node - node->preceding);
	if ((prev->preceding & MM_ALLOC_BIT) == 0) {
		/* Remove the node.  There must be a predecessor, but there may
		 * not be a successor node.
		 */

		DEBUGASSERT(prev->blink);
		prev->blink->flink = prev->flink;
		if (prev->flink) {
			prev->flink->blink = prev->blink;
		}

		/* Then merge the two chunks */

		prev->size     += node->size;
		next->preceding = prev->size | (next->preceding & MM_ALLOC_BIT);
		node            = prev;
	}

	/* Add the merged node to the nodelist */

	mm_addfreechunk(heap, node);
	mm_givesemaphore(heap);
}
/****************************************************************************
 *
 * Copyright 2016-2017 Samsung Electronics All Rights Reserved.
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
 * mm/mm_heap/mm_heapinfo.c
 *
 *   Copyright (C) 2007, 2009, 2013-2014 Gregory Nutt. All rights reserved.
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
#include <tinyara/sched.h>
#include <tinyara/mm/mm.h>
#include <tinyara/arch.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#ifdef CONFIG_HEAPINFO_USER_GROUP
#include <string.h>
#include <tinyara/mm/heapinfo_internal.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define MM_PIDHASH(pid) ((pid) & (CONFIG_MAX_TASKS - 1))
#define HEAPINFO_INT INT16_MAX
#define HEAPINFO_NONSCHED (INT16_MAX - 1)

#ifdef CONFIG_HEAPINFO_USER_GROUP
struct heapinfo_group_info_s group_info[HEAPINFO_THREAD_NUM];
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

#ifdef CONFIG_DEBUG_MM_HEAPINFO
/****************************************************************************
 * Name: heapinfo_parse
 *
 * Description:
 *   This function walk through heap and displays alloc info.
 ****************************************************************************/
void heapinfo_parse(FAR struct mm_heap_s *heap, int mode, pid_t pid)
{
	struct mm_allocnode_s *node;
	size_t mxordblk = 0;
	int    ordblks  = 0;		/* Number of non-inuse chunks */
	size_t fordblks = 0;		/* Total non-inuse space */
	size_t heap_resource;
	size_t stack_resource;
	size_t nonsched_resource;
	int nonsched_idx;

	/* This nonsched can be 3 types : group resources, freed when child task finished, leak */
	pid_t nonsched_list[CONFIG_MAX_TASKS];
	size_t nonsched_size[CONFIG_MAX_TASKS];

#if CONFIG_MM_REGIONS > 1
	int region;
#else
#define region 0
#endif
	/* initialize the heap, stack and nonsched resource */
	nonsched_resource = 0;
	heap_resource = 0;
	stack_resource = 0;
	for (nonsched_idx = 0; nonsched_idx < CONFIG_MAX_TASKS; nonsched_idx++) {
		nonsched_list[nonsched_idx] = HEAPINFO_NONSCHED;
		nonsched_size[nonsched_idx] = 0;
	}

	/* Visit each region */

#if CONFIG_MM_REGIONS > 1
	for (region = 0; region < heap->mm_nregions; region++)
#endif
	{
		/* Visit each node in the region
		 * Retake the semaphore for each region to reduce latencies
		 */
		mm_takesemaphore(heap);

		if (mode != HEAPINFO_SIMPLE) {
			printf("****************************************************************\n");
			printf("REGION #%d Start=0x%p, End=0x%p, Size=%d\n",
				region,
				heap->mm_heapstart[region],
				heap->mm_heapend[region],
				(int)heap->mm_heapend[region] - (int)heap->mm_heapstart[region] + SIZEOF_MM_ALLOCNODE);
			printf("****************************************************************\n");
			printf("Allocation Info- (Size in Bytes)\n");
			printf("****************************************************************\n");
			printf("  MemAddr |   Size   | Status |    Owner   |  Pid  |\n");
			printf("----------|----------|--------|------------|-------|\n");
		}

		for (node = heap->mm_heapstart[region]; node < heap->mm_heapend[region]; node = (struct mm_allocnode_s *)((char *)node + node->size)) {

			/* Check if the node corresponds to an allocated memory chunk */
			if ((pid == HEAPINFO_PID_ALL || node->pid == pid) && (node->preceding & MM_ALLOC_BIT) != 0) {
				if (mode == HEAPINFO_DETAIL_ALL || mode == HEAPINFO_DETAIL_PID) {
					if (node->pid >= 0) {
						printf("0x%x | %8u |   %c    | 0x%8x | %3d   |\n", node, node->size, 'A', node->alloc_call_addr, node->pid);
					} else {
						printf("0x%x | %8u |   %c    | 0x%8x | %3d(S)|\n", node, node->size, 'A', node->alloc_call_addr, -(node->pid));
					}
				}

#if CONFIG_TASK_NAME_SIZE > 0
				if (node->pid == HEAPINFO_INT && mode != HEAPINFO_SIMPLE) {
					printf("INT Context\n");
				} else if (node->pid < 0 && sched_gettcb((-1) * (node->pid)) != NULL) {
					stack_resource += node->size;
				} else if (sched_gettcb(node->pid) == NULL) {
					nonsched_list[MM_PIDHASH(node->pid)] = node->pid;
					nonsched_size[MM_PIDHASH(node->pid)] += node->size;
					nonsched_resource += node->size;
				} else {
					heap_resource += node->size;
				}
#else
				printf("\n");
#endif
			} else {
				ordblks++;
				fordblks += node->size;
				if (node->size > mxordblk) {
					mxordblk = node->size;
				}
				if (mode == HEAPINFO_DETAIL_ALL || mode == HEAPINFO_DETAIL_FREE) {
					printf("0x%x | %8d |   %c    |            |       |\n", node, node->size, 'F');
				}
			}
		}

		if (mode != HEAPINFO_SIMPLE) {
			printf("** PID(S) in Pid colum means that mem is used for stack of PID\n");
		}
		printf("\n");
		mm_givesemaphore(heap);
	}
#undef region
	printf("\n****************************************************************\n");
	printf("     Summary of Heap Usages (Size in Bytes)\n");
	printf("****************************************************************\n");
	printf("Total                           : %u (100%%)\n", heap->mm_heapsize);
	printf("  - Allocated (Current / Peak)  : %u (%d%%) / %u (%d%%)\n",\
		heap->total_alloc_size, heap->total_alloc_size * 100 / heap->mm_heapsize,\
		heap->peak_alloc_size,  heap->peak_alloc_size * 100 / heap->mm_heapsize);
	printf("  - Free (Current)              : %u (%d%%)\n", fordblks, fordblks * 100 / heap->mm_heapsize);
	printf("  - Reserved                    : %u\n", SIZEOF_MM_ALLOCNODE * 2);

	printf("\n****************************************************************\n");
	printf("     Details of Heap Usages (Size in Bytes)\n");
	printf("****************************************************************\n");
	printf("< Free >\n");
	printf("  - Number of Free Node               : %d\n", ordblks);
	printf("  - Largest Free Node Size            : %u\n", mxordblk);
	printf("\n< Allocation >\n");
	printf("  - Current Size (Alive Allocation) = (1) + (2) + (3)\n");
	printf("     . by Dead Threads (*) (1)        : %u\n", nonsched_resource);
	printf("     . by Alive Threads\n");
	printf("        - Sum of \"STACK\"(**) (2)      : %u\n", stack_resource);
	printf("        - Sum of \"CURR_HEAP\" (3)      : %u\n", heap_resource - SIZEOF_MM_ALLOCNODE);	// Because of above for loop (node < heap->mm_heapend[region];),
													// one of SIZEOF_MM_ALLOCNODE is subtracted.
	printf("** NOTE **\n");
	printf("(*)  Alive allocation by dead threads might be used by others or might be a leakage.\n");
	printf("(**) Only Idle task has a separate stack region,\n");
	printf("  rest are all allocated on the heap region.\n");

	if (mode != HEAPINFO_SIMPLE) {
		printf("\n< by Dead Threads >\n");
		printf(" Pid | Size \n");
		printf("-----|------\n");
		for (nonsched_idx = 0; nonsched_idx < CONFIG_MAX_TASKS; nonsched_idx++) {
			if (nonsched_list[nonsched_idx] != HEAPINFO_NONSCHED) {
				printf("%4d | %5u\n", nonsched_list[nonsched_idx], nonsched_size[nonsched_idx]);
			}
		}
	}

	return;
}
/****************************************************************************
 * Name: heapinfo_update_group
 *
 * Description:
 * Update Peak heap size for Group
 ****************************************************************************/
#ifdef CONFIG_HEAPINFO_USER_GROUP
static void heapinfo_update_group(mmsize_t size, pid_t pid)
{
	int check_idx;
	int group_num;
	int stack_pid;
	struct mm_heap_s *heap = mm_get_heap_info();
	for (check_idx = 0; check_idx < HEAPINFO_THREAD_NUM; check_idx++) {
		if (pid == group_info[check_idx].pid) {
			group_num = group_info[check_idx].group;
			heap->group[group_num].curr_size += size;
			/* Update peak size */
			if (heap->group[group_num].curr_size > heap->group[group_num].peak_size) {
				heap->group[group_num].peak_size = heap->group[group_num].curr_size;
				/* calculate the summation of stacks */
				heap->group[group_num].stack_size = 0;
				for (stack_pid = 0; stack_pid < HEAPINFO_THREAD_NUM; stack_pid++) {
					if (group_info[stack_pid].pid != -1 && group_info[stack_pid].group == group_num) {
						heap->group[group_num].stack_size += group_info[stack_pid].stack_size;
					}
				}
				heap->group[group_num].heap_size = heap->group[group_num].peak_size - heap->group[group_num].stack_size;
			}
			break;
		}
	}
}
#endif
/****************************************************************************
 * Name: heapinfo_add_size
 *
 * Description:
 * Add the allocated size in tcb
 ****************************************************************************/
void heapinfo_add_size(pid_t pid, mmsize_t size)
{
	struct tcb_s *rtcb = sched_gettcb(pid);
	if (rtcb) {
		rtcb->curr_alloc_size += size;
		rtcb->num_alloc_free++;
		if (rtcb->curr_alloc_size > rtcb->peak_alloc_size) {
			rtcb->peak_alloc_size = rtcb->curr_alloc_size;
		}
	}
}

/****************************************************************************
 * Name: heapinfo_subtract_size
 *
 * Description:
 * Subtract the allocated size in tcb
 ****************************************************************************/
void heapinfo_subtract_size(pid_t pid, mmsize_t size)
{
	struct tcb_s *rtcb = sched_gettcb(pid);

	if (rtcb) {
		rtcb->curr_alloc_size -= size;
		rtcb->num_alloc_free--;
	}
}

/****************************************************************************
 * Name: heapinfo_update_total_size
 *
 * Description:
 * Calculate the total allocated size and update the peak allocated size for heap
 ****************************************************************************/
void heapinfo_update_total_size(struct mm_heap_s *heap, mmsize_t size, pid_t pid)
{
	heap->total_alloc_size += size;
	if (heap->total_alloc_size > heap->peak_alloc_size) {
		heap->peak_alloc_size = heap->total_alloc_size;
	}
#ifdef CONFIG_HEAPINFO_USER_GROUP
	heapinfo_update_group(size, pid);
#endif
}
/****************************************************************************
 * Name: heapinfo_update_node
 *
 * Description:
 * Adds pid and malloc caller return address to mem chunk
 ****************************************************************************/
void heapinfo_update_node(FAR struct mm_allocnode_s *node, mmaddress_t caller_retaddr)
{
	node->alloc_call_addr = caller_retaddr;
	node->reserved = 0;
	if (up_interrupt_context() == true) {
		/* update pid as HEAPINFO_INT(-1) if allocation is from INT context */
		node->pid = HEAPINFO_INT;
	} else {
		node->pid = getpid();
	}
	return;
}

/****************************************************************************
 * Name: heapinfo_exclude_stacksize
 *
 * Description:
 * when create a stack, subtract the stacksize from parent
 ****************************************************************************/
void heapinfo_exclude_stacksize(void *stack_ptr)
{
	struct mm_allocnode_s *node;
	struct tcb_s *rtcb;

	node = (struct mm_allocnode_s *)(stack_ptr - SIZEOF_MM_ALLOCNODE);
	rtcb = sched_gettcb(node->pid);

	ASSERT(rtcb);
	rtcb->curr_alloc_size -= node->size;

#ifdef CONFIG_HEAPINFO_USER_GROUP
	int check_idx;
	int group_num;
	struct mm_heap_s *heap = mm_get_heap_info();

	for (check_idx = 0; check_idx <= heap->max_group; check_idx++) {
		if (node->pid == group_info[check_idx].pid) {
			group_num = group_info[check_idx].group;
			heap->group[group_num].curr_size -= node->size;
			break;
		}
	}
#endif
}

#ifdef CONFIG_HEAPINFO_USER_GROUP
/****************************************************************************
 * Name: heapinfo_update_group_info
 *
 * Description:
 * when create or release task/thread, check that the task/thread is 
 * in group list
 ****************************************************************************/
void heapinfo_update_group_info(pid_t pid, int group, int type)
{
	int info_idx;
	struct tcb_s *tcb;
	struct mm_heap_s *heap = mm_get_heap_info();
	switch (type) {
	case HEAPINFO_INIT_INFO:
		for (info_idx = 0; info_idx < HEAPINFO_THREAD_NUM; info_idx++) {
			group_info[info_idx].pid = pid;
			group_info[info_idx].group = group;
			group_info[info_idx].stack_size = 0;
		}
		break;
	case HEAPINFO_ADD_INFO:
		if (group > heap->max_group) {
			heap->max_group = group;
		}
		for (info_idx = 0; info_idx < HEAPINFO_THREAD_NUM; info_idx++) {
			if (group_info[info_idx].pid <= 0) {
				group_info[info_idx].pid = pid;
				group_info[info_idx].group = group;
				tcb = sched_gettcb(pid);
				if (tcb) {
					group_info[info_idx].stack_size = tcb->adj_stack_size;
					heapinfo_update_group(tcb->adj_stack_size, pid);
				}
				break;
			}
		}
		break;
	case HEAPINFO_DEL_INFO:
		for (info_idx = 0; info_idx < HEAPINFO_THREAD_NUM; info_idx++) {
			if (pid == group_info[info_idx].pid) {
				heapinfo_update_group((-1) * group_info[info_idx].stack_size, pid);

				group_info[info_idx].pid = -1;
				group_info[info_idx].group = -1;
				group_info[info_idx].stack_size = 0;
				break;
			}
		}
		break;
	default:
		break;
	}
}

/****************************************************************************
 * Name: heapinfo_check_group_list
 *
 * Description:
 * check that task/thread is in group list
 ****************************************************************************/
void heapinfo_check_group_list(pid_t pid, char *name)
{
	char *thread_list = CONFIG_HEAPINFO_USER_GROUP_LIST;

	int group_num = 0;

	char *name_start;
	char *name_end;
	int name_length;
	name_start = name_end = thread_list;

	while (*name_start != '\0') {
		if (*name_end == '/' || *name_end == ',' || *name_end == '\0') {
			name_length = name_end - name_start;
			if (name_length == strlen(name)) {
				if (strncmp(name_start, name, name_end - name_start) == 0) {
					heapinfo_update_group_info(pid, group_num, HEAPINFO_ADD_INFO);
					break;
				}
			}
			if (*name_end == '/') {
				group_num++;
			} else if (*name_end == '\0') {
				name_start = name_end;
				continue;
			}
			name_end++;
			name_start = name_end;
		} else {
			name_end++;
		}
	}
}
#endif /* CONFIG_HEAPINFO_USER_GROUP */
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
 * mm/mm_heap/mm_initialize.c
 *
 *   Copyright (C) 2007, 2009, 2011, 2013 Gregory Nutt. All rights reserved.
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
#include <assert.h>
#include <debug.h>

#include <tinyara/mm/mm.h>

/****************************************************************************
 * Pre-processor Definitions
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
 * Name: mm_addregion
 *
 * Description:
 *   This function adds a region of contiguous memory to the selected heap.
 *
 * Parameters:
 *   heap      - The selected heap
 *   heapstart - Start of the heap region
 *   heapsize  - Size of the heap region
 *
 * Return Value:
 *   None
 *
 * Assumptions:
 *
 ****************************************************************************/

void mm_addregion(FAR struct mm_heap_s *heap, FAR void *heapstart, size_t heapsize)
{
	FAR struct mm_freenode_s *node;
	uintptr_t heapbase;
	uintptr_t heapend;
#if CONFIG_MM_REGIONS > 1
	int IDX = heap->mm_nregions;
#else
#define IDX 0
#endif

	/* If the MCU handles wide addresses but the memory manager is configured
	 * for a small heap, then verify that the caller is  not doing something
	 * crazy.
	 */

#if defined(CONFIG_MM_SMALL) && !defined(CONFIG_SMALL_MEMORY)
	DEBUGASSERT(heapsize <= MMSIZE_MAX + 1);
#endif

	/* Adjust the provide heap start and size so that they are both aligned
	 * with the MM_MIN_CHUNK size.
	 */

	heapbase = MM_ALIGN_UP((uintptr_t)heapstart);
	heapend  = MM_ALIGN_DOWN((uintptr_t)heapstart + (uintptr_t)heapsize);
	heapsize = heapend - heapbase;

	mlldbg("Region %d: base=%p size=%u\n", IDX + 1, heapstart, heapsize);

	/* Add the size of this region to the total size of the heap */

	heap->mm_heapsize += heapsize;

	/* Create two "allocated" guard nodes at the beginning and end of
	 * the heap.  These only serve to keep us from allocating outside
	 * of the heap.
	 *
	 * And create one free node between the guard nodes that contains
	 * all available memory.
	 */

	heap->mm_heapstart[IDX]            = (FAR struct mm_allocnode_s *)heapbase;
	heap->mm_heapstart[IDX]->size      = SIZEOF_MM_ALLOCNODE;
	heap->mm_heapstart[IDX]->preceding = MM_ALLOC_BIT;
#ifdef CONFIG_DEBUG_MM_HEAPINFO
	/* fill magic number 0xDEAD as malloc info for head node */
	heapinfo_update_node((FAR struct mm_allocnode_s *)heap->mm_heapstart[IDX], 0xDEAD);
#endif

	node            = (FAR struct mm_freenode_s *)(heapbase + SIZEOF_MM_ALLOCNODE);
	node->size      = heapsize - 2 * SIZEOF_MM_ALLOCNODE;
	node->preceding = SIZEOF_MM_ALLOCNODE;

	heap->mm_heapend[IDX]            = (FAR struct mm_allocnode_s *)(heapend - SIZEOF_MM_ALLOCNODE);
	heap->mm_heapend[IDX]->size      = SIZEOF_MM_ALLOCNODE;
	heap->mm_heapend[IDX]->preceding = node->size | MM_ALLOC_BIT;
#ifdef CONFIG_DEBUG_MM_HEAPINFO
	/* Fill magic number 0xDEADDEAD as malloc info for tail node */
	heapinfo_update_node((FAR struct mm_allocnode_s *)heap->mm_heapend[IDX], 0xDEADDEAD);
#endif

#undef IDX

#if CONFIG_MM_REGIONS > 1
	heap->mm_nregions++;
#endif

	/* Add the single, large free node to the nodelist */

	mm_addfreechunk(heap, node);
}

/****************************************************************************
 * Name: mm_initialize
 *
 * Description:
 *   Initialize the selected heap data structures, providing the initial
 *   heap region.
 *
 * Parameters:
 *   heap      - The selected heap
 *   heapstart - Start of the initial heap region
 *   heapsize  - Size of the initial heap region
 *
 * Return Value:
 *   None
 *
 * Assumptions:
 *
 ****************************************************************************/

void mm_initialize(FAR struct mm_heap_s *heap, FAR void *heapstart, size_t heapsize)
{
	int i;

	mlldbg("Heap: start=%p size=%u\n", heapstart, heapsize);

	/* The following two lines have cause problems for some older ZiLog
	 * compilers in the past (but not the more recent).  Life is easier if we
	 * just the suppress them altogther for those tools.
	 */

#ifndef __ZILOG__
	CHECK_ALLOCNODE_SIZE;
	CHECK_FREENODE_SIZE;
#endif

	/* Set up global variables */

	heap->mm_heapsize = 0;

#if CONFIG_MM_REGIONS > 1
	heap->mm_nregions = 0;
#endif

	/* Initialize the node array */

	memset(heap->mm_nodelist, 0, sizeof(struct mm_freenode_s) * MM_NNODES);
	for (i = 1; i < MM_NNODES; i++) {
		heap->mm_nodelist[i - 1].flink = &heap->mm_nodelist[i];
		heap->mm_nodelist[i].blink = &heap->mm_nodelist[i - 1];
	}

	/* Initialize the malloc semaphore to one (to support one-at-
	 * a-time access to private data sets).
	 */

	mm_seminitialize(heap);

	/* Add the initial region of memory to the heap */

	mm_addregion(heap, heapstart, heapsize);
#ifdef CONFIG_HEAPINFO_USER_GROUP
	heapinfo_update_group_info(-1, -1, HEAPINFO_INIT_INFO);
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
 * mm/mm_heap/mm_mallinfo.c
 *
 *   Copyright (C) 2007, 2009, 2013-2014 Gregory Nutt. All rights reserved.
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
#include <assert.h>
#include <debug.h>
#include <unistd.h>
#include <tinyara/mm/mm.h>
#include <tinyara/sched.h>
/****************************************************************************
 * Pre-processor Definitions
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
 * Name: mm_get_heap_info
 *
 * Description:
 *   returns a heap which type is matched with ttype
 *
 ****************************************************************************/
struct mm_heap_s *mm_get_heap_info(void)
{
#ifdef CONFIG_MM_KERNEL_HEAP
	struct tcb_s *tcb;

	tcb = sched_gettcb(getpid());
	if (tcb->flags & TCB_FLAG_TTYPE_MASK == TCB_FLAG_TTYPE_KERNEL) {
		return &g_kmmheap;
	} else
#endif
	{
		return USR_HEAP;
	}

}
/****************************************************************************
 * Name: mm_mallinfo
 *
 * Description:
 *   mallinfo returns a copy of updated current heap information.
 *
 ****************************************************************************/

int mm_mallinfo(FAR struct mm_heap_s *heap, FAR struct mallinfo *info)
{
	struct mm_allocnode_s *node;
	size_t mxordblk = 0;
	int    ordblks  = 0;		/* Number of non-inuse chunks */
	size_t uordblks = 0;		/* Total allocated space */
	size_t fordblks = 0;		/* Total non-inuse space */
#if CONFIG_MM_REGIONS > 1
	int region;
#else
#define region 0
#endif

	DEBUGASSERT(info);

	/* Visit each region */

#if CONFIG_MM_REGIONS > 1
	for (region = 0; region < heap->mm_nregions; region++)
#endif
	{
		/* Visit each node in the region
		 * Retake the semaphore for each region to reduce latencies
		 */

		mm_takesemaphore(heap);

		for (node = heap->mm_heapstart[region]; node < heap->mm_heapend[region]; node = (struct mm_allocnode_s *)((char *)node + node->size)) {
			mvdbg("region=%d node=%p size=%p preceding=%p (%c)\n", region, node, node->size, (node->preceding & ~MM_ALLOC_BIT), (node->preceding & MM_ALLOC_BIT) ? 'A' : 'F');

			/* Check if the node corresponds to an allocated memory chunk */

			if ((node->preceding & MM_ALLOC_BIT) != 0) {
				uordblks += node->size;
			} else {
				ordblks++;
				fordblks += node->size;
				if (node->size > mxordblk) {
					mxordblk = node->size;
				}
			}
		}

		mm_givesemaphore(heap);

		mvdbg("region=%d node=%p heapend=%p\n", region, node, heap->mm_heapend[region]);
		DEBUGASSERT(node == heap->mm_heapend[region]);
		uordblks += SIZEOF_MM_ALLOCNODE;	/* account for the tail node */
	}
#undef region

	DEBUGASSERT(uordblks + fordblks == heap->mm_heapsize);

	info->arena    = heap->mm_heapsize;
	info->ordblks  = ordblks;
	info->mxordblk = mxordblk;
	info->uordblks = uordblks;
	info->fordblks = fordblks;
	return OK;
}
/****************************************************************************
 *
 * Copyright 2016-2017 Samsung Electronics All Rights Reserved.
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
 * mm/mm_heap/mm_malloc.c
 *
 *   Copyright (C) 2007, 2009, 2013-2014  Gregory Nutt. All rights reserved.
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
#include <debug.h>

#include <tinyara/mm/mm.h>

#ifdef CONFIG_DEBUG_MM_HEAPINFO
#include  <tinyara/sched.h>
#endif
/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifndef NULL
#define NULL ((void*)0)
#endif

/****************************************************************************
 * Type Definitions
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
 * Name: mm_malloc
 *
 * Description:
 *  Find the smallest chunk that satisfies the request. Take the memory from
 *  that chunk, save the remaining, smaller chunk (if any).
 *
 *  8-byte alignment of the allocated data is assured.
 *
 ****************************************************************************/
#ifdef CONFIG_DEBUG_MM_HEAPINFO
FAR void *mm_malloc(FAR struct mm_heap_s *heap, size_t size, mmaddress_t caller_retaddr)
#else
FAR void *mm_malloc(FAR struct mm_heap_s *heap, size_t size)
#endif
{
	FAR struct mm_freenode_s *node;
	void *ret = NULL;
	int ndx;

	/* Handle bad sizes */

	if (size < 1) {
		return NULL;
	}

	if (size > MM_ALIGN_DOWN(MMSIZE_MAX) - SIZEOF_MM_ALLOCNODE) {
		mvdbg("Because of mm_allocnode, %u cannot be allocated. The maximun allocable size is (MM_ALIGN_DOWN(MMSIZE_MAX) - SIZEOF_MM_ALLOCNODE) : %u\n.", size, (MM_ALIGN_DOWN(MMSIZE_MAX) - SIZEOF_MM_ALLOCNODE));
		return NULL;
	}

	/* Adjust the size to account for (1) the size of the allocated node and
	 * (2) to make sure that it is an even multiple of our granule size.
	 */

	size = MM_ALIGN_UP(size + SIZEOF_MM_ALLOCNODE);

	/* We need to hold the MM semaphore while we muck with the nodelist. */

	mm_takesemaphore(heap);

	/* Get the location in the node list to start the search. Special case
	 * really big allocations
	 */

	if (size >= MM_MAX_CHUNK) {
		ndx = MM_NNODES - 1;
	} else {
		/* Convert the request size into a nodelist index */

		ndx = mm_size2ndx(size);
	}

	/* Search for a large enough chunk in the list of nodes. This list is
	 * ordered by size, but will have occasional zero sized nodes as we visit
	 * other mm_nodelist[] entries.
	 */

	for (node = heap->mm_nodelist[ndx].flink; node && node->size < size; node = node->flink) ;

	/* If we found a node with non-zero size, then this is one to use. Since
	 * the list is ordered, we know that is must be best fitting chunk
	 * available.
	 */

	if (node) {
		FAR struct mm_freenode_s *remainder;
		FAR struct mm_freenode_s *next;
		size_t remaining;

		/* Remove the node.  There must be a predecessor, but there may not be
		 * a successor node.
		 */

		DEBUGASSERT(node->blink);
		node->blink->flink = node->flink;
		if (node->flink) {
			node->flink->blink = node->blink;
		}

		/* Check if we have to split the free node into one of the allocated
		 * size and another smaller freenode.  In some cases, the remaining
		 * bytes can be smaller (they may be SIZEOF_MM_ALLOCNODE).  In that
		 * case, we will just carry the few wasted bytes at the end of the
		 * allocation.
		 */

		remaining = node->size - size;
		if (remaining >= SIZEOF_MM_FREENODE) {
			/* Get a pointer to the next node in physical memory */

			next = (FAR struct mm_freenode_s *)(((char *)node) + node->size);

			/* Create the remainder node */

			remainder = (FAR struct mm_freenode_s *)(((char *)node) + size);
			remainder->size = remaining;
			remainder->preceding = size;

			/* Adjust the size of the node under consideration */

			node->size = size;

			/* Adjust the 'preceding' size of the (old) next node, preserving
			 * the allocated flag.
			 */

			next->preceding = remaining | (next->preceding & MM_ALLOC_BIT);

			/* Add the remainder back into the nodelist */

			mm_addfreechunk(heap, remainder);
		}

		/* Handle the case of an exact size match */

		node->preceding |= MM_ALLOC_BIT;

#ifdef CONFIG_DEBUG_MM_HEAPINFO
		heapinfo_update_node((struct mm_allocnode_s *)node, caller_retaddr);
		heapinfo_add_size(((struct mm_allocnode_s *)node)->pid, node->size);
		heapinfo_update_total_size(heap, node->size, ((struct mm_allocnode_s *)node)->pid);
#endif
		ret = (void *)((char *)node + SIZEOF_MM_ALLOCNODE);
	}

	mm_givesemaphore(heap);

	/* If CONFIG_DEBUG_MM is defined, then output the result of the allocation
	 * to the SYSLOG.
	 */

#ifdef CONFIG_DEBUG_MM
	if (!ret) {
		mdbg("Allocation failed, size %u\n", size);
#ifdef CONFIG_DEBUG_MM_HEAPINFO
		heapinfo_parse(heap, HEAPINFO_DETAIL_ALL, HEAPINFO_PID_ALL);
#endif
	} else {
		mvdbg("Allocated %p, size %u\n", ret, size);
	}
#endif

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
 * mm/mm_heap/mm_memalign.c
 *
 *   Copyright (C) 2007, 2009, 2011, 2013-2014 Gregory Nutt. All rights reserved.
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

#include <tinyara/mm/mm.h>

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
 * Name: mm_memalign
 *
 * Description:
 *   memalign requests more than enough space from malloc, finds a region
 *   within that chunk that meets the alignment request and then frees any
 *   leading or trailing space.
 *
 *   The alignment argument must be a power of two (not checked).  8-byte
 *   alignment is guaranteed by normal malloc calls.
 *
 ****************************************************************************/
#ifdef CONFIG_DEBUG_MM_HEAPINFO
FAR void *mm_memalign(FAR struct mm_heap_s *heap, size_t alignment, size_t size, mmaddress_t caller_retaddr)
#else
FAR void *mm_memalign(FAR struct mm_heap_s *heap, size_t alignment, size_t size)
#endif
{
	FAR struct mm_allocnode_s *node;
	size_t rawchunk;
	size_t alignedchunk;
	size_t mask = (size_t)(alignment - 1);
	size_t allocsize;

	/* If this requested alinement's less than or equal to the natural alignment
	 * of malloc, then just let malloc do the work.
	 */

	if (alignment <= MM_MIN_CHUNK) {
#ifdef CONFIG_DEBUG_MM_HEAPINFO
		return mm_malloc(heap, size, caller_retaddr);
#else
		return mm_malloc(heap, size);
#endif
	}

	/* Adjust the size to account for (1) the size of the allocated node, (2)
	 * to make sure that it is an even multiple of our granule size, and to
	 * include the alignment amount.
	 *
	 * Notice that we increase the allocation size by twice the requested
	 * alignment.  We do this so that there will be at least two valid
	 * alignment points within the allocated memory.
	 *
	 * NOTE:  These are sizes given to malloc and not chunk sizes. They do
	 * not include SIZEOF_MM_ALLOCNODE.
	 */

	size = MM_ALIGN_UP(size);	/* Make multiples of our granule size */
	allocsize = size + 2 * alignment;	/* Add double full alignment size */

	/* Then malloc that size */
#ifdef CONFIG_DEBUG_MM_HEAPINFO
	/*Passing Zero as caller addr to avoid adding memalloc info in malloc function,
	   alloc info will be added in this functiona after memory aligment . */
	rawchunk = (size_t)mm_malloc(heap, allocsize, caller_retaddr);
#else
	rawchunk = (size_t)mm_malloc(heap, allocsize);
#endif
	if (rawchunk == 0) {
		return NULL;
	}

	/* We need to hold the MM semaphore while we muck with the chunks and
	 * nodelist.
	 */

	mm_takesemaphore(heap);

	/* Get the node associated with the allocation and the next node after
	 * the allocation.
	 */

	node = (FAR struct mm_allocnode_s *)(rawchunk - SIZEOF_MM_ALLOCNODE);

#ifdef CONFIG_DEBUG_MM_HEAPINFO
		heapinfo_subtract_size(node->pid, node->size);
		heapinfo_update_total_size(heap, ((-1) * (node->size)), node->pid);
#endif
	/* Find the aligned subregion */

	alignedchunk = (rawchunk + mask) & ~mask;

	/* Check if there is free space at the beginning of the aligned chunk */

	if (alignedchunk != rawchunk) {
		FAR struct mm_allocnode_s *newnode;
		FAR struct mm_allocnode_s *next;
		size_t precedingsize;

		/* Get the node the next node after the allocation. */

		next = (FAR struct mm_allocnode_s *)((char *)node + node->size);

		/* Make sure that there is space to convert the preceding mm_allocnode_s
		 * into an mm_freenode_s.  I think that this should always be true
		 */

		DEBUGASSERT(alignedchunk >= rawchunk + 8);

		newnode = (FAR struct mm_allocnode_s *)(alignedchunk - SIZEOF_MM_ALLOCNODE);

		/* Preceding size is full size of the new 'node,' including
		 * SIZEOF_MM_ALLOCNODE
		 */

		precedingsize = (size_t)newnode - (size_t)node;

		/* If we were unlucky, then the alignedchunk can lie in such a position
		 * that precedingsize < SIZEOF_NODE_FREENODE.  We can't let that happen
		 * because we are going to cast 'node' to struct mm_freenode_s below.
		 * This is why we allocated memory large enough to support two
		 * alignment points.  In this case, we will simply use the second
		 * alignment point.
		 */

		if (precedingsize < SIZEOF_MM_FREENODE) {
			alignedchunk += alignment;
			newnode = (FAR struct mm_allocnode_s *)(alignedchunk - SIZEOF_MM_ALLOCNODE);
			precedingsize = (size_t)newnode - (size_t)node;
		}

		/* Set up the size of the new node */

		newnode->size = (size_t)next - (size_t)newnode;
		newnode->preceding = precedingsize | MM_ALLOC_BIT;

		/* Reduce the size of the original chunk and mark it not allocated, */

		node->size = precedingsize;
		node->preceding &= ~MM_ALLOC_BIT;

		/* Fix the preceding size of the next node */

		next->preceding = newnode->size | (next->preceding & MM_ALLOC_BIT);

		/* Convert the newnode chunk size back into malloc-compatible size by
		 * subtracting the header size SIZEOF_MM_ALLOCNODE.
		 */

		allocsize = newnode->size - SIZEOF_MM_ALLOCNODE;

		/* Add the original, newly freed node to the free nodelist */

		mm_addfreechunk(heap, (FAR struct mm_freenode_s *)node);

		/* Replace the original node with the newlay realloaced,
		 * aligned node
		 */
		node = newnode;
	}

	/* Check if there is free space at the end of the aligned chunk */

	if (allocsize > size) {
		/* Shrink the chunk by that much -- remember, mm_shrinkchunk wants
		 * internal chunk sizes that include SIZEOF_MM_ALLOCNODE, and not the
		 * malloc-compatible sizes that we have.
		 */
		mm_shrinkchunk(heap, node, size + SIZEOF_MM_ALLOCNODE);
	}
#ifdef CONFIG_DEBUG_MM_HEAPINFO
	heapinfo_update_node(node, caller_retaddr);

	heapinfo_add_size(node->pid, node->size);
	heapinfo_update_total_size(heap, node->size, node->pid);
#endif
	mm_givesemaphore(heap);
	return (FAR void *)alignedchunk;
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
 * mm/mm_heap/mm_realloc.c
 *
 *   Copyright (C) 2007, 2009, 2013-2014 Gregory Nutt. All rights reserved.
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
#include <string.h>
#include <stdio.h>
#include <assert.h>

#ifdef CONFIG_DEBUG_MM_HEAPINFO
#include <tinyara/sched.h>
#endif
#include <tinyara/mm/mm.h>

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
 * Name: mm_realloc
 *
 * Description:
 *   If the reallocation is for less space, then:
 *
 *     (1) the current allocation is reduced in size
 *     (2) the remainder at the end of the allocation is returned to the
 *         free list.
 *
 *  If the request is for more space and the current allocation can be
 *  extended, it will be extended by:
 *
 *     (1) Taking the additional space from the following free chunk, or
 *     (2) Taking the additional space from the preceding free chunk.
 *     (3) Or both
 *
 *  If the request is for more space but the current chunk cannot be
 *  extended, then malloc a new buffer, copy the data into the new buffer,
 *  and free the old buffer.
 *
 ****************************************************************************/
#ifdef CONFIG_DEBUG_MM_HEAPINFO
FAR void *mm_realloc(FAR struct mm_heap_s *heap, FAR void *oldmem, size_t size, mmaddress_t caller_retaddr)
#else
FAR void *mm_realloc(FAR struct mm_heap_s *heap, FAR void *oldmem, size_t size)
#endif
{
	FAR struct mm_allocnode_s *oldnode;
#ifndef CONFIG_REALLOC_DISABLE_NEIGHBOR_EXTENSION
	FAR struct mm_freenode_s  *prev;
	FAR struct mm_freenode_s  *next;
#endif
	size_t newsize;
	size_t oldsize;
#ifndef CONFIG_REALLOC_DISABLE_NEIGHBOR_EXTENSION
	size_t prevsize = 0;
	size_t nextsize = 0;
#endif
	FAR void *newmem;

	/* If oldmem is NULL, then realloc is equivalent to malloc */

	if (!oldmem) {
#ifdef CONFIG_DEBUG_MM_HEAPINFO
		return mm_malloc(heap, size, caller_retaddr);
#else
		return mm_malloc(heap, size);
#endif
	}

	/* If size is zero, then realloc is equivalent to free */

	if (size < 1) {
		mm_free(heap, oldmem);
		return NULL;
	}

	/* Adjust the size to account for (1) the size of the allocated node and
	 * (2) to make sure that it is an even multiple of our granule size.
	 */

	newsize = MM_ALIGN_UP(size + SIZEOF_MM_ALLOCNODE);

	/* Map the memory chunk into an allocated node structure */

	oldnode = (FAR struct mm_allocnode_s *)((FAR char *)oldmem - SIZEOF_MM_ALLOCNODE);

	/* We need to hold the MM semaphore while we muck with the nodelist. */

	mm_takesemaphore(heap);

	/* Check if this is a request to reduce the size of the allocation. */

	oldsize = oldnode->size;

	if (newsize <= oldsize) {
		/* Handle the special case where we are not going to change the size
		 * of the allocation.
		 */

		if (newsize < oldsize) {
#ifdef CONFIG_DEBUG_MM_HEAPINFO
			/* modify the current allocated size of old node */
			heapinfo_subtract_size(oldnode->pid, oldsize);
			heapinfo_update_total_size(heap, (-1) * oldsize, oldnode->pid);
#endif

			mm_shrinkchunk(heap, oldnode, newsize);
#ifdef CONFIG_DEBUG_MM_HEAPINFO
			/* update the chunk to realloc task information */
			heapinfo_update_node(oldnode, caller_retaddr);

			heapinfo_add_size(oldnode->pid, oldnode->size);
			heapinfo_update_total_size(heap, oldnode->size, oldnode->pid);
#endif
		}

		/* Then return the original address */

		mm_givesemaphore(heap);
		return oldmem;
	}

#ifndef CONFIG_REALLOC_DISABLE_NEIGHBOR_EXTENSION
	/* This is a request to increase the size of the allocation,  Get the
	 * available sizes before and after the oldnode so that we can make the
	 * best decision
	 */

	next = (FAR struct mm_freenode_s *)((FAR char *)oldnode + oldnode->size);
	if ((next->preceding & MM_ALLOC_BIT) == 0) {
		nextsize = next->size;
	}

	prev = (FAR struct mm_freenode_s *)((FAR char *)oldnode - (oldnode->preceding & ~MM_ALLOC_BIT));
	if ((prev->preceding & MM_ALLOC_BIT) == 0) {
		prevsize = prev->size;
	}

	/* Now, check if we can extend the current allocation or not */

	if (nextsize + prevsize + oldsize >= newsize) {
		size_t needed   = newsize - oldsize;
		size_t takeprev = 0;
		size_t takenext = 0;

#ifdef CONFIG_DEBUG_MM_HEAPINFO
		/* modify the current allocated size of old node */
		heapinfo_subtract_size(oldnode->pid, oldsize);
		heapinfo_update_total_size(heap, (-1) * oldsize, oldnode->pid);
#endif

		/* Check if we can extend into the previous chunk and if the
		 * previous chunk is smaller than the next chunk.
		 */

		if (prevsize > 0 && (nextsize >= prevsize || nextsize < 1)) {
			/* Can we get everything we need from the previous chunk? */

			if (needed > prevsize) {
				/* No, take the whole previous chunk and get the
				 * rest that we need from the next chunk.
				 */

				takeprev = prevsize;
				takenext = needed - prevsize;
			} else {
				/* Yes, take what we need from the previous chunk */

				takeprev = needed;
				takenext = 0;
			}

			needed = 0;
		}

		/* Check if we can extend into the next chunk and if we still need
		 * more memory.
		 */

		if (nextsize > 0 && needed) {
			/* Can we get everything we need from the next chunk? */

			if (needed > nextsize) {
				/* No, take the whole next chunk and get the rest that we
				 * need from the previous chunk.
				 */

				takeprev = needed - nextsize;
				takenext = nextsize;
			} else {
				/* Yes, take what we need from the previous chunk */

				takeprev = 0;
				takenext = needed;
			}
		}

		/* Extend into the previous free chunk */

		newmem = oldmem;
		if (takeprev) {
			FAR struct mm_allocnode_s *newnode;

			/* Remove the previous node.  There must be a predecessor, but
			 * there may not be a successor node.
			 */

			DEBUGASSERT(prev->blink);
			prev->blink->flink = prev->flink;
			if (prev->flink) {
				prev->flink->blink = prev->blink;
			}

			/* Extend the node into the previous free chunk */
			/* Did we consume the entire preceding chunk? */

			if ((prevsize - takeprev) >= SIZEOF_MM_FREENODE) {
				/* No.. just take what we need from the previous chunk and put
				 * it back into the free list
				 */
				newnode            = (FAR struct mm_allocnode_s *)((FAR char *)oldnode - takeprev);
				prev->size        -= takeprev;
				newnode->size      = oldsize + takeprev;
				newnode->preceding = prev->size | MM_ALLOC_BIT;
				next->preceding    = newnode->size | (next->preceding & MM_ALLOC_BIT);

				/* Return the previous free node to the nodelist (with the new size) */

				mm_addfreechunk(heap, prev);
			} else {
				/* Yes.. update its size (newnode->preceding is already set) */
				takeprev            = prev->size;
				newnode             = (FAR struct mm_allocnode_s *)((FAR char *)oldnode - takeprev);
				newnode->size      += oldsize;
				newnode->preceding |= MM_ALLOC_BIT;
				next->preceding     = newnode->size | (next->preceding & MM_ALLOC_BIT);
			}

			oldnode = newnode;
			oldsize = newnode->size;

			/* Now we have to move the user contents 'down' in memory.  memcpy should
			 * should be save for this.
			 */

			newmem = (FAR void *)((FAR char *)newnode + SIZEOF_MM_ALLOCNODE);
			memcpy(newmem, oldmem, oldsize - SIZEOF_MM_ALLOCNODE);
		}

		/* Extend into the next free chunk */

		if (takenext) {
			FAR struct mm_freenode_s *newnode;
			FAR struct mm_allocnode_s *andbeyond;

			/* Get the chunk following the next node (which could be the tail
			 * chunk)
			 */

			andbeyond = (FAR struct mm_allocnode_s *)((char *)next + nextsize);

			/* Remove the next node.  There must be a predecessor, but there
			 * may not be a successor node.
			 */

			DEBUGASSERT(next->blink);
			next->blink->flink = next->flink;
			if (next->flink) {
				next->flink->blink = next->blink;
			}

			/* Extend the node into the next chunk */
			/* Did we consume the entire preceding chunk? */

			if ((nextsize - takenext) >= SIZEOF_MM_FREENODE) {
				/* No, take what we need from the next chunk and return it to
				 * the free nodelist.
				 */
				oldnode->size        = oldsize + takenext;
				newnode              = (FAR struct mm_freenode_s *)((char *)oldnode + oldnode->size);
				newnode->size        = nextsize - takenext;
				newnode->preceding   = oldnode->size;
				andbeyond->preceding = newnode->size | (andbeyond->preceding & MM_ALLOC_BIT);

				/* Add the new free node to the nodelist (with the new size) */

				mm_addfreechunk(heap, newnode);
			} else {
				/* Yes, just update some pointers. */
				takenext             = nextsize;
				oldnode->size        = oldsize + takenext;
				andbeyond->preceding = oldnode->size | (andbeyond->preceding & MM_ALLOC_BIT);
			}
		}
#ifdef CONFIG_DEBUG_MM_HEAPINFO
		/* update the chunk to realloc task information */
		heapinfo_update_node(oldnode, caller_retaddr);

		heapinfo_add_size(oldnode->pid, oldnode->size);
		heapinfo_update_total_size(heap, oldnode->size, oldnode->pid);
#endif

		mm_givesemaphore(heap);
		return newmem;
	}

	/* The current chunk cannot be extended.  Just allocate a new chunk and copy */

	else
#endif
	{
		/* Allocate a new block.  On failure, realloc must return NULL but
		 * leave the original memory in place.
		 */
		mm_givesemaphore(heap);
#ifdef CONFIG_DEBUG_MM_HEAPINFO
		newmem = (FAR void *)mm_malloc(heap, size, caller_retaddr);
#else
		newmem = (FAR void *)mm_malloc(heap, size);
#endif
		if (newmem) {
			memcpy(newmem, oldmem, oldsize - SIZEOF_MM_ALLOCNODE);
			mm_free(heap, oldmem);
		}

		return newmem;
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
 * mm/mm_heap/mm_sbrk.c
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

#include <stdint.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/arch.h>
#include <tinyara/mm/mm.h>
#include <tinyara/pgalloc.h>

#ifdef CONFIG_BUILD_KERNEL

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_sbrk
 *
 * Description:
 *    The sbrk() function is used to change the amount of space allocated
 *    for the calling process. The change is made by resetting the process'
 *    break value and allocating the appropriate amount of space.  The amount
 *    of allocated space increases as the break value increases.
 *
 *    The sbrk() function adds 'incr' bytes to the break value and changes
 *    the allocated space accordingly. If incr is negative, the amount of
 *    allocated space is decreased by incr bytes. The current value of the
 *    program break is returned by sbrk(0).
 *
 * Input Parameters:
 *    heap - A reference to the data structure that defines this heap.
 *    incr - Specifies the number of bytes to add or to remove from the
 *      space allocated for the process.
      maxbreak - The maximum permissible break address.
 *
 * Returned Value:
 *    Upon successful completion, sbrk() returns the prior break value.
 *    Otherwise, it returns (void *)-1 and sets errno to indicate the
 *    error:
 *
 *      ENOMEM - The requested change would allocate more space than
 *        allowed under system limits.
 *      EAGAIN - The total amount of system memory available for allocation
 *        to this process is temporarily insufficient. This may occur even
 *        though the space requested was less than the maximum data segment
 *        size.
 *
 ****************************************************************************/

FAR void *mm_sbrk(FAR struct mm_heap_s *heap, intptr_t incr, uintptr_t maxbreak)
{
	uintptr_t brkaddr;
	uintptr_t allocbase;
	unsigned int pgincr;
	size_t bytesize;
	int err;

	DEBUGASSERT(incr >= 0);
	if (incr < 0) {
		err = ENOSYS;
		goto errout;
	}

	/* Get the current break address (NOTE: assumes region 0).  If
	 * the memory manager is uninitialized, mm_brkaddr() will return
	 * zero.
	 */

	brkaddr = (uintptr_t)mm_brkaddr(heap, 0);
	if (incr > 0) {
		/* Convert the increment to multiples of the page size */

		pgincr = MM_NPAGES(incr);

		/* Check if this increment would exceed the maximum break value */

		if ((brkaddr > 0) && ((maxbreak - brkaddr) < (pgincr << MM_PGSHIFT))) {
			err = ENOMEM;
			goto errout;
		}

		/* Allocate the requested number of pages and map them to the
		 * break address.  If we provide a zero brkaddr to pgalloc(),  it
		 * will create the first block in the correct virtual address
		 * space and return the start address of that block.
		 */

		allocbase = pgalloc(brkaddr, pgincr);
		if (allocbase == 0) {
			err = EAGAIN;
			goto errout;
		}

		/* Has the been been initialized?  brkaddr will be zero if the
		 * memory manager has not yet been initialized.
		 */

		bytesize = pgincr << MM_PGSHIFT;
		if (brkaddr != 0) {
			/* No... then initialize it now */

			mm_initialize(heap, (FAR void *)allocbase, bytesize);
		} else {
			/* Extend the heap (region 0) */

			mm_extend(heap, (FAR void *)allocbase, bytesize, 0);
		}
	}

	return (FAR void *)brkaddr;

errout:
	set_errno(err);
	return (FAR void *)-1;
}
#endif							/* CONFIG_BUILD_KERNEL */
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
 * mm/mm_heap/mm_sem.c
 *
 *   Copyright (C) 2007-2009, 2013 Gregory Nutt. All rights reserved.
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
#include <assert.h>

#include <tinyara/mm/mm.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Define the following to enable semaphore state monitoring */
//#define MONITOR_MM_SEMAPHORE 1

#ifdef MONITOR_MM_SEMAPHORE
#ifdef CONFIG_DEBUG
#include <debug.h>
#define msemdbg dbg
#else
#define msemdbg printf
#endif
#else
#ifdef CONFIG_CPP_HAVE_VARARGS
#define msemdbg(...)
#else
#define msemdbg (void)
#endif
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_seminitialize
 *
 * Description:
 *   Initialize the MM mutex
 *
 ****************************************************************************/

void mm_seminitialize(FAR struct mm_heap_s *heap)
{
	/* Initialize the MM semaphore to one (to support one-at-a-time access to
	 * private data sets.
	 */

	(void)sem_init(&heap->mm_semaphore, 0, 1);

	heap->mm_holder      = -1;
	heap->mm_counts_held = 0;
}

/****************************************************************************
 * Name: mm_trysemaphore
 *
 * Description:
 *   Try to take the MM mutex.  This is called only from the OS in certain
 *   conditions when it is necessary to have exclusive access to the memory
 *   manager but it is impossible to wait on a semaphore (e.g., the idle
 *   process when it performs its background memory cleanup).
 *
 ****************************************************************************/

int mm_trysemaphore(FAR struct mm_heap_s *heap)
{
	pid_t my_pid = getpid();

	/* Do I already have the semaphore? */

	if (heap->mm_holder == my_pid) {
		/* Yes, just increment the number of references that I have */

		heap->mm_counts_held++;
		return OK;
	} else {
		/* Try to take the semaphore (perhaps waiting) */

		if (sem_trywait(&heap->mm_semaphore) != 0) {
			return ERROR;
		}

		/* We have it.  Claim the stak and return */

		heap->mm_holder      = my_pid;
		heap->mm_counts_held = 1;
		return OK;
	}
}

/****************************************************************************
 * Name: mm_takesemaphore
 *
 * Description:
 *   Take the MM mutex.  This is the normal action before all memory
 *   management actions.
 *
 ****************************************************************************/

void mm_takesemaphore(FAR struct mm_heap_s *heap)
{
	pid_t my_pid = getpid();

	/* Do I already have the semaphore? */

	if (heap->mm_holder == my_pid) {
		/* Yes, just increment the number of references that I have */

		heap->mm_counts_held++;
	} else {
		/* Take the semaphore (perhaps waiting) */

		msemdbg("PID=%d taking\n", my_pid);
		while (sem_wait(&heap->mm_semaphore) != 0) {
			/* The only case that an error should occur here is if
			 * the wait was awakened by a signal.
			 */

			ASSERT(errno == EINTR);
		}

		/* We have it.  Claim the stake and return */

		heap->mm_holder      = my_pid;
		heap->mm_counts_held = 1;
	}

	msemdbg("Holder=%d count=%d\n", heap->mm_holder, heap->mm_counts_held);
}

/****************************************************************************
 * Name: mm_givesemaphore
 *
 * Description:
 *   Release the MM mutex when it is not longer needed.
 *
 ****************************************************************************/

void mm_givesemaphore(FAR struct mm_heap_s *heap)
{
#ifdef CONFIG_DEBUG
	pid_t my_pid = getpid();
#endif

	/* I better be holding at least one reference to the semaphore */

	DEBUGASSERT(heap->mm_holder == my_pid);

	/* Do I hold multiple references to the semphore */

	if (heap->mm_counts_held > 1) {
		/* Yes, just release one count and return */

		heap->mm_counts_held--;
		msemdbg("Holder=%d count=%d\n", heap->mm_holder, heap->mm_counts_held);
	} else {
		/* Nope, this is the last reference I have */

#ifdef CONFIG_DEBUG
		msemdbg("PID=%d giving\n", my_pid);
#endif

		heap->mm_holder      = -1;
		heap->mm_counts_held = 0;
		ASSERT(sem_post(&heap->mm_semaphore) == 0);
	}
}

/****************************************************************************
 * Name: mm_is_sem_available
 *
 * Description:
 *   Check availability of mm semaphore 
 *
 ****************************************************************************/
void mm_is_sem_available(void)
{
	struct mm_heap_s *heap = mm_get_heap_info();

	mm_takesemaphore(heap);
	mm_givesemaphore(heap);
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
 * mm/mm_heap/mm_shrinkchunk.c
 *
 *   Copyright (C) 2007, 2009, 1013 Gregory Nutt. All rights reserved.
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

#include <tinyara/mm/mm.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_shrinkchunk
 *
 * Description:
 *   Reduce the size of the chunk specified by the node structure to the
 *   specified size.  this internal logic is used both from memalign to
 *   dispose of any trailing memory in the aligned allocation and also by
 *   realloc when there is a request to reduce the size of an allocation.
 *
 *   NOTES:
 *     (1) size is the whole chunk size (payload and header)
 *     (2) the caller must hold the MM semaphore.
 *
 ****************************************************************************/

void mm_shrinkchunk(FAR struct mm_heap_s *heap, FAR struct mm_allocnode_s *node, size_t size)
{
	FAR struct mm_freenode_s *next;

	/* Get a reference to the next node */

	next = (FAR struct mm_freenode_s *)((char *)node + node->size);

	/* Check if it is free */

	if ((next->preceding & MM_ALLOC_BIT) == 0) {
		FAR struct mm_allocnode_s *andbeyond;
		FAR struct mm_freenode_s *newnode;

		/* Get the chunk next the next node (which could be the tail chunk) */

		andbeyond = (FAR struct mm_allocnode_s *)((char *)next + next->size);

		/* Remove the next node.  There must be a predecessor, but there may
		 * not be a successor node.
		 */

		DEBUGASSERT(next->blink);
		next->blink->flink = next->flink;
		if (next->flink) {
			next->flink->blink = next->blink;
		}

		/* Create a new chunk that will hold both the next chunk and the
		 * tailing memory from the aligned chunk.
		 */

		newnode = (FAR struct mm_freenode_s *)((char *)node + size);

		/* Set up the size of the new node */

		newnode->size        = next->size + node->size - size;
		newnode->preceding   = size;
		node->size           = size;
		andbeyond->preceding = newnode->size | (andbeyond->preceding & MM_ALLOC_BIT);

		/* Add the new node to the freenodelist */

		mm_addfreechunk(heap, newnode);
	}

	/* The next chunk is allocated.  Try to free the end portion at the end
	 * chunk to be shrunk.
	 */

	else if (node->size >= size + SIZEOF_MM_FREENODE) {
		FAR struct mm_freenode_s *newnode;

		/* Create a new chunk that will hold both the next chunk and the
		 * tailing memory from the aligned chunk.
		 */

		newnode = (FAR struct mm_freenode_s *)((char *)node + size);

		/* Set up the size of the new node */

		newnode->size      = node->size - size;
		newnode->preceding = size;
		node->size         = size;
		next->preceding    = newnode->size | MM_ALLOC_BIT;

		/* Add the new node to the freenodelist */

		mm_addfreechunk(heap, newnode);
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
 * mm/mm_heap/mm_size2ndx.c
 *
 *   Copyright (C) 2007, 2009 Gregory Nutt. All rights reserved.
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

#include <tinyara/mm/mm.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_size2ndx
 *
 * Description:
 *    Convert the size to a nodelist index.
 *
 ****************************************************************************/

int mm_size2ndx(size_t size)
{
	int ndx = 0;

	if (size >= MM_MAX_CHUNK) {
		return MM_NNODES - 1;
	}

	size >>= MM_MIN_SHIFT;
	while (size > 1) {
		ndx++;
		size >>= 1;
	}

	return ndx;
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
 * mm/mm_heap/mm_zalloc.c
 *
 *   Copyright (C) 2007, 2009, 2014 Gregory Nutt. All rights reserved.
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

#include <tinyara/mm/mm.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_zalloc
 *
 * Description:
 *   mm_zalloc calls mm_malloc, then zeroes out the allocated chunk.
 *
 ****************************************************************************/

#ifdef CONFIG_DEBUG_MM_HEAPINFO
FAR void *mm_zalloc(FAR struct mm_heap_s *heap, size_t size, mmaddress_t caller_retaddr)
#else
FAR void *mm_zalloc(FAR struct mm_heap_s *heap, size_t size)
#endif
{
#ifdef CONFIG_DEBUG_MM_HEAPINFO
	FAR void *alloc = mm_malloc(heap, size, caller_retaddr);
#else
	FAR void *alloc = mm_malloc(heap, size);
#endif
	if (alloc) {
		memset(alloc, 0, size);
	}

	return alloc;
}

//WizIO


/****************************************************************************
 * Name: mm_heapmember
 *
 * Description:
 *   Check if an address lies in the heap.
 *
 * Parameters:
 *   heap - The heap to check
 *   mem  - The address to check
 *
 * Return Value:
 *   true if the address is a member of the heap.  false if not
 *   not.  If the address is not a member of the heap, then it
 *   must be a member of the user-space heap (unchecked)
 *
 ****************************************************************************/

bool mm_heapmember(FAR struct mm_heap_s *heap, FAR void *mem)
{
#if CONFIG_MM_REGIONS > 1
  int i;

  /* A valid address from the heap for this region would have to lie
   * between the region's two guard nodes.
   */

  for (i = 0; i < heap->mm_nregions; i++)
    {
      if (mem > (FAR void *)heap->mm_heapstart[i] &&
          mem < (FAR void *)heap->mm_heapend[i])
        {
          return true;
        }
    }

  /* The address does not like any any region assigned to the heap */

  return false;

#else
  /* A valid address from the heap would have to lie between the
   * two guard nodes.
   */

  if (mem > (FAR void *)heap->mm_heapstart[0] &&
      mem < (FAR void *)heap->mm_heapend[0])
    {
      return true;
    }

  /* Otherwise, the address does not lie in the heap */

  return false;

#endif
}

