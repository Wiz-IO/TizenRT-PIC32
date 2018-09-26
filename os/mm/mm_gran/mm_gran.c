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
 * mm/mm_gran/mm_granalloc.c
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

#include <assert.h>

#include <tinyara/mm/gran.h>

#include "mm_gran/mm_gran.h"

#ifdef CONFIG_GRAN

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_common_alloc
 *
 * Description:
 *   Allocate memory from the granule heap.
 *
 * Input Parameters:
 *   priv - The granule heap state structure.
 *   size - The size of the memory region to allocate.
 *
 * Returned Value:
 *   On success, a non-NULL pointer to the allocated memory is returned.
 *
 ****************************************************************************/

static inline FAR void *gran_common_alloc(FAR struct gran_s *priv, size_t size)
{
	unsigned int ngranules;
	size_t       tmpmask;
	uintptr_t    alloc;
	uint32_t     curr;
	uint32_t     next;
	uint32_t     mask;
	int          granidx;
	int          gatidx;
	int          bitidx;
	int          shift;

	DEBUGASSERT(priv && size <= 32 * (1 << priv->log2gran));

	if (priv && size > 0) {
		/* Get exclusive access to the GAT */

		gran_enter_critical(priv);

		/* How many contiguous granules we we need to find? */

		tmpmask = (1 << priv->log2gran) - 1;
		ngranules = (size + tmpmask) >> priv->log2gran;

		/* Then create mask for that number of granules */

		DEBUGASSERT(ngranules <= 32);
		mask = 0xffffffff >> (32 - ngranules);

		/* Now search the granule allocation table for that number of contiguous */

		alloc = priv->heapstart;

		for (granidx = 0; granidx < priv->ngranules; granidx += 32) {
			/* Get the GAT index associated with the granule table entry */

			gatidx = granidx >> 5;
			curr = priv->gat[gatidx];

			/* Handle the case where there are no free granules in the entry */

			if (curr == 0xffffffff) {
				alloc += (32 << priv->log2gran);
				continue;
			}

			/* Get the next entry from the GAT to support a 64 bit shift */

			if (granidx < priv->ngranules) {
				next = priv->gat[gatidx + 1];
			}

			/* Use all ones when are at the last entry in the GAT (meaning
			 * nothing can be allocated.
			 */

			else {
				next = 0xffffffff;
			}

			/* Search through the allocations in the 'curr' GAT entry
			 * to see if we can satisfy the allocation starting in that
			 * entry.
			 *
			 * This loop continues until either all of the bits have been
			 * examined (bitidx >= 32), or until there are insufficient
			 * granules left to satisfy the allocation.
			 */

			for (bitidx = 0; bitidx < 32 && (granidx + bitidx + ngranules) <= priv->ngranules;) {
				/* Break out if there are no further free bits in 'curr'.
				 * All of the zero bits might have gotten shifted out.
				 */

				if (curr == 0xffffffff) {
					break;
				}

				/* Check for the first zero bit in the lower or upper 16-bits.
				 * From the test above, we know that at least one of the 32-
				 * bits in 'curr' is zero.
				 */

				else if ((curr & 0x0000ffff) == 0x0000ffff) {
					/* Not in the lower 16 bits.  The first free bit must be
					 * in the upper 16 bits.
					 */

					shift = 16;
				}

				/* We know that the first free bit is now within the lower 16
				 * bits of 'curr'.  Is it in the upper or lower byte?
				 */

				else if ((curr & 0x0000ff) == 0x000000ff) {
					/* Not in the lower 8 bits.  The first free bit must be in
					 * the upper 8 bits.
					 */

					shift = 8;
				}

				/* We know that the first free bit is now within the lower 4
				 * bits of 'curr'.  Is it in the upper or lower nibble?
				 */

				else if ((curr & 0x00000f) == 0x0000000f) {
					/* Not in the lower 4 bits.  The first free bit must be in
					 * the upper 4 bits.
					 */

					shift = 4;
				}

				/* We know that the first free bit is now within the lower 4 bits
				 * of 'curr'.  Is it in the upper or lower pair?
				 */

				else if ((curr & 0x000003) == 0x00000003) {
					/* Not in the lower 2 bits.  The first free bit must be in
					 * the upper 2 bits.
					 */

					shift = 2;
				}

				/* We know that the first free bit is now within the lower 4 bits
				 * of 'curr'.  Check if we have the allocation at this bit position.
				 */

				else if ((curr & mask) == 0) {
					/* Yes.. mark these granules allocated */

					gran_mark_allocated(priv, alloc, ngranules);

					/* And return the allocation address */

					gran_leave_critical(priv);
					return (FAR void *)alloc;
				}

				/* The free allocation does not start at this position */

				else {
					shift = 1;
				}

				/* Set up for the next time through the loop.  Perform a 64
				 * bit shift to move to the next gran position andi ncrement
				 * to the next candidate allocation address.
				 */

				alloc  += (shift << priv->log2gran);
				curr    = (curr >> shift) | (next << (32 - shift));
				next  >>= shift;
				bitidx += shift;
			}
		}

		gran_leave_critical(priv);
	}

	return NULL;
}

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_alloc
 *
 * Description:
 *   Allocate memory from the granule heap.
 *
 *   NOTE: The current implementation also restricts the maximum allocation
 *   size to 32 granules.  That restriction could be eliminated with some
 *   additional coding effort.
 *
 * Input Parameters:
 *   handle - The handle previously returned by gran_initialize
 *   size   - The size of the memory region to allocate.
 *
 * Returned Value:
 *   On success, either a non-NULL pointer to the allocated memory (if
 *   CONFIG_GRAN_SINGLE) or zero  (if !CONFIG_GRAN_SINGLE) is returned.
 *
 ****************************************************************************/

#ifdef CONFIG_GRAN_SINGLE
FAR void *gran_alloc(size_t size)
{
	return gran_common_alloc(g_graninfo, size);
}
#else
FAR void *gran_alloc(GRAN_HANDLE handle, size_t size)
{
	return gran_common_alloc((FAR struct gran_s *)handle, size);
}
#endif

#endif							/* CONFIG_GRAN */
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
 * mm/mm_gran/mm_grancritical.c
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

#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#include <arch/irq.h>
#include <tinyara/mm/gran.h>

#include "mm_gran/mm_gran.h"

#ifdef CONFIG_GRAN

/****************************************************************************
 * Pre-processor Definitions
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
 * Name: gran_enter_critical and gran_leave_critical
 *
 * Description:
 *   Critical section management for the granule allocator.
 *
 * Input Parameters:
 *   priv - Pointer to the gran state
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void gran_enter_critical(FAR struct gran_s *priv)
{
#ifdef CONFIG_GRAN_INTR
	priv->irqstate = irqsave();
#else
	int ret;

	/* Continue waiting if we are awakened by a signal */

	do {
		ret = sem_wait(&priv->exclsem);
		if (ret < 0) {
			DEBUGASSERT(errno == EINTR);
		}
	} while (ret < 0);
#endif
}

void gran_leave_critical(FAR struct gran_s *priv)
{
#ifdef CONFIG_GRAN_INTR
	irqrestore(priv->irqstate);
#else
	sem_post(&priv->exclsem);
#endif
}

#endif							/* CONFIG_GRAN */
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
 * mm/mm_gran/mm_granfree.c
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

#include <assert.h>

#include <tinyara/mm/gran.h>

#include "mm_gran/mm_gran.h"

#ifdef CONFIG_GRAN

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_common_free
 *
 * Description:
 *   Return memory to the granule heap.
 *
 * Input Parameters:
 *   handle - The handle previously returned by gran_initialize
 *   memory - A pointer to memory previoiusly allocated by gran_alloc.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static inline void gran_common_free(FAR struct gran_s *priv, FAR void *memory, size_t size)
{
	unsigned int granno;
	unsigned int gatidx;
	unsigned int gatbit;
	unsigned int granmask;
	unsigned int ngranules;
	unsigned int avail;
	uint32_t     gatmask;

	DEBUGASSERT(priv && memory && size <= 32 * (1 << priv->log2gran));

	/* Get exclusive access to the GAT */

	gran_enter_critical(priv);

	/* Determine the granule number of the first granule in the allocation */

	granno = ((uintptr_t)memory - priv->heapstart) >> priv->log2gran;

	/* Determine the GAT table index and bit number associated with the
	 * allocation.
	 */

	gatidx = granno >> 5;
	gatbit = granno & 31;

	/* Determine the number of granules in the allocation */

	granmask = (1 << priv->log2gran) - 1;
	ngranules = (size + granmask) >> priv->log2gran;

	/* Clear bits in the GAT entry or entries */

	avail = 32 - gatbit;
	if (ngranules > avail) {
		/* Clear bits in the first GAT entry */

		gatmask = (0xffffffff << gatbit);
		DEBUGASSERT((priv->gat[gatidx] & gatmask) == gatmask);

		priv->gat[gatidx] &= ~gatmask;
		ngranules -= avail;

		/* Clear bits in the second GAT entry */

		gatmask = 0xffffffff >> (32 - ngranules);
		DEBUGASSERT((priv->gat[gatidx + 1] & gatmask) == gatmask);

		priv->gat[gatidx + 1] &= ~gatmask;
	}

	/* Handle the case where where all of the granules came from one entry */

	else {
		/* Clear bits in a single GAT entry */

		gatmask = 0xffffffff >> (32 - ngranules);
		gatmask <<= gatbit;
		DEBUGASSERT((priv->gat[gatidx] & gatmask) == gatmask);

		priv->gat[gatidx] &= ~gatmask;
	}

	gran_leave_critical(priv);
}

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_free
 *
 * Description:
 *   Return memory to the granule heap.
 *
 * Input Parameters:
 *   handle - The handle previously returned by gran_initialize
 *   memory - A pointer to memory previoiusly allocated by gran_alloc.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

#ifdef CONFIG_GRAN_SINGLE
void gran_free(FAR void *memory, size_t size)
{
	return gran_common_free(g_graninfo, memory, size);
}
#else
void gran_free(GRAN_HANDLE handle, FAR void *memory, size_t size)
{
	return gran_common_free((FAR struct gran_s *)handle, memory, size);
}
#endif

#endif							/* CONFIG_GRAN */
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
 * mm/mm_gran/mm_graninit.c
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

#include <assert.h>
#include <errno.h>

#include <tinyara/mm/gran.h>
#include <tinyara/kmalloc.h>

#include "mm_gran/mm_gran.h"

#ifdef CONFIG_GRAN

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* State of the single GRAN allocator */

#ifdef CONFIG_GRAN_SINGLE
FAR struct gran_s *g_graninfo;
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_common_initialize
 *
 * Description:
 *   Perform common GRAN initialization.
 *
 * Input Parameters:
 *   heapstart - Start of the granule allocation heap
 *   heapsize  - Size of heap in bytes
 *   log2gran  - Log base 2 of the size of one granule.  0->1 byte,
 *               1->2 bytes, 2->4 bytes, 3-> 8 bytes, etc.
 *   log2align - Log base 2 of required alignment.  0->1 byte,
 *               1->2 bytes, 2->4 bytes, 3-> 8 bytes, etc.  Note that
 *               log2gran must be greater than or equal to log2align
 *               so that all contiguous granules in memory will meet
 *               the minimum alignment requirement. A value of zero
 *               would mean that no alignment is required.
 *
 * Returned Value:
 *   On success, a non-NULL info structure is returned that may be used with
 *   other granule allocator interfaces.
 *
 ****************************************************************************/

static inline FAR struct gran_s *gran_common_initialize(FAR void *heapstart, size_t heapsize, uint8_t log2gran, uint8_t log2align)
{
	FAR struct gran_s *priv;
	uintptr_t          heapend;
	uintptr_t          alignedstart;
	unsigned int       mask;
	unsigned int       alignedsize;
	unsigned int       ngranules;

	/* Check parameters if debug is on.  Note the size of a granule is
	 * limited to 2**31 bytes and that the size of the granule must be greater
	 * than or equal to the alignment size.
	 */

	DEBUGASSERT(heapstart && heapsize > 0 && log2gran > 0 && log2gran < 32 && log2gran >= log2align);

	/* Get the aligned start of the heap */

	mask         = (1 << log2align) - 1;
	alignedstart = ((uintptr_t)heapstart + mask) & ~mask;

	/* Determine the number of granules */

	mask         = (1 << log2gran) - 1;
	heapend      = (uintptr_t)heapstart + heapsize;
	alignedsize  = (heapend - alignedstart) & ~mask;
	ngranules    = alignedsize >> log2gran;

	/* Allocate the information structure with a granule table of the
	 * correct size.
	 */

	priv = (FAR struct gran_s *)kmm_zalloc(SIZEOF_GRAN_S(ngranules));
	if (priv) {
		/* Initialize non-zero elements of the granules heap info structure */

		priv->log2gran  = log2gran;
		priv->ngranules = ngranules;
		priv->heapstart = alignedstart;

		/* Initialize mutual exclusion support */

#ifndef CONFIG_GRAN_INTR
		sem_init(&priv->exclsem, 0, 1);
#endif
	}

	return priv;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_initialize
 *
 * Description:
 *   Set up one granule allocator instance.  Allocations will be aligned to
 *   the alignment size (log2align; allocations will be in units of the
 *   granule size (log2gran). Larger granules will give better performance
 *   and less overhead but more losses of memory due to quantization waste.
 *   Additional memory waste can occur from alignment; log2align should be
 *   set to 0 unless you are using the granule allocator to manage DMA
 *   or page-aligned memory and your hardware has specific memory alignment
 *   requirements.
 *
 *   General Usage Summary.  This is an example using the GCC section
 *   attribute to position a DMA heap in memory (logic in the linker script
 *   would assign the section .dmaheap to the DMA memory.
 *
 *     FAR uint32_t g_dmaheap[DMAHEAP_SIZE] __attribute__((section(.dmaheap)));
 *
 *   The heap is created by calling gran_initialize().  Here the granule size
 *   is set to 64 bytes (2**6) and the alignment to 16 bytes (2**4):
 *
 *     GRAN_HANDLE handle = gran_initialize(g_dmaheap, DMAHEAP_SIZE, 6, 4);
 *
 *   Then the GRAN_HANDLE can be used to allocate memory (There is no
 *   GRAN_HANDLE if CONFIG_GRAN_SINGLE=y):
 *
 *     FAR uint8_t *dma_memory = (FAR uint8_t *)gran_alloc(handle, 47);
 *
 *   The actual memory allocates will be 64 byte (wasting 17 bytes) and
 *   will be aligned at least to (1 << log2align).
 *
 *   NOTE: The current implementation also restricts the maximum allocation
 *   size to 32 granules.  That restriction could be eliminated with some
 *   additional coding effort.
 *
 * Input Parameters:
 *   heapstart - Start of the granule allocation heap
 *   heapsize  - Size of heap in bytes
 *   log2gran  - Log base 2 of the size of one granule.  0->1 byte,
 *               1->2 bytes, 2->4 bytes, 3->8 bytes, etc.
 *   log2align - Log base 2 of required alignment.  0->1 byte,
 *               1->2 bytes, 2->4 bytes, 3->8 bytes, etc.  Note that
 *               log2gran must be greater than or equal to log2align
 *               so that all contiguous granules in memory will meet
 *               the minimum alignment requirement. A value of zero
 *               would mean that no alignment is required.
 *
 * Returned Value:
 *   On success, a non-NULL handle is returned that may be used with other
 *   granule allocator interfaces.
 *
 ****************************************************************************/

#ifdef CONFIG_GRAN_SINGLE
int gran_initialize(FAR void *heapstart, size_t heapsize, uint8_t log2gran, uint8_t log2align)
{
	g_graninfo = gran_common_initialize(heapstart, heapsize, log2gran, log2align);
	if (!g_graninfo) {
		return -ENOMEM;
	}

	return OK;
}
#else
GRAN_HANDLE gran_initialize(FAR void *heapstart, size_t heapsize, uint8_t log2gran, uint8_t log2align)
{
	return (GRAN_HANDLE)gran_common_initialize(heapstart, heapsize, log2gran, log2align);
}
#endif

#endif							/* CONFIG_GRAN */
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
 * mm/mm_gran/mm_granmark.c
 *
 *   Copyright (C) 2012, 2014 Gregory Nutt. All rights reserved.
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

#include <tinyara/mm/gran.h>

#include "mm_gran/mm_gran.h"

#ifdef CONFIG_GRAN

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
 * Name: gran_mark_allocated
 *
 * Description:
 *   Mark a range of granules as allocated.
 *
 * Input Parameters:
 *   priv  - The granule heap state structure.
 *   alloc - The address of the allocation.
 *   ngranules - The number of granules allocated
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void gran_mark_allocated(FAR struct gran_s *priv, uintptr_t alloc, unsigned int ngranules)
{
	unsigned int granno;
	unsigned int gatidx;
	unsigned int gatbit;
	unsigned int avail;
	uint32_t     gatmask;

	/* Determine the granule number of the allocation */

	granno = (alloc - priv->heapstart) >> priv->log2gran;

	/* Determine the GAT table index associated with the allocation */

	gatidx = granno >> 5;
	gatbit = granno & 31;

	/* Mark bits in the GAT entry or entries */

	avail = 32 - gatbit;
	if (ngranules > avail) {
		/* Mark bits in the first GAT entry */

		gatmask = 0xffffffff << gatbit;
		DEBUGASSERT((priv->gat[gatidx] & gatmask) == 0);

		priv->gat[gatidx] |= gatmask;
		ngranules -= avail;

		/* Mark bits in the second GAT entry */

		gatmask = 0xffffffff >> (32 - ngranules);
		DEBUGASSERT((priv->gat[gatidx + 1] & gatmask) == 0);

		priv->gat[gatidx + 1] |= gatmask;
	}

	/* Handle the case where where all of the granules come from one entry */

	else {
		/* Mark bits in a single GAT entry */

		gatmask = 0xffffffff >> (32 - ngranules);
		gatmask <<= gatbit;
		DEBUGASSERT((priv->gat[gatidx] & gatmask) == 0);

		priv->gat[gatidx] |= gatmask;
		return;
	}
}

#endif							/* CONFIG_GRAN */
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
 * mm/mm_gran/mm_graninit.c
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

#include <assert.h>
#include <errno.h>

#include <tinyara/mm/gran.h>
#include <tinyara/kmalloc.h>

#include "mm_gran/mm_gran.h"

#ifdef CONFIG_GRAN

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* State of the single GRAN allocator */

#ifdef CONFIG_GRAN_SINGLE
FAR struct gran_s *g_graninfo;
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_release_common
 *
 * Description:
 *   Perform common GRAN initialization.
 *
 * Input Parameters:
 *   priv - Reference to the granule heap structure to be released.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static inline void gran_release_common(FAR struct gran_s *priv)
{
	DEBUGASSERT(priv);
#ifndef CONFIG_GRAN_INTR
	sem_destroy(&priv->exclsem);
#endif
	kmm_free(priv);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_release
 *
 * Description:
 *   Uninitialize a gram memory allocator and release resources held by the
 *   allocator.
 *
 * Input Parameters:
 *   handle - The handle previously returned by gran_initialize
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

#ifdef CONFIG_GRAN_SINGLE
void gran_release(void)
{
	gran_release_common(g_graninfo);
	g_graninfo = NULL;
}
#else
void gran_release(GRAN_HANDLE handle)
{
	gran_release_common(handle);
}
#endif

#endif							/* CONFIG_GRAN */
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
 * mm/mm_gran/mm_granreserve.c
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

#include <tinyara/mm/gran.h>

#include "mm_gran/mm_gran.h"

#ifdef CONFIG_GRAN

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_common_reserve
 *
 * Description:
 *   Reserve memory in the granule heap.  This will reserve the granules
 *   that contain the start and end addresses plus all of the granules
 *   in between.  This should be done early in the initialization sequence
 *   before any other allocations are made.
 *
 *   Reserved memory can never be allocated (it can be freed however which
 *   essentially unreserves the memory).
 *
 * Input Parameters:
 *   priv  - The granule heap state structure.
 *   start - The address of the beginning of the region to be reserved.
 *   size  - The size of the region to be reserved
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static inline void gran_common_reserve(FAR struct gran_s *priv, uintptr_t start, size_t size)
{
	if (size > 0) {
		uintptr_t mask = (1 << priv->log2gran) - 1;
		uintptr_t end  = start + size - 1;
		unsigned int ngranules;

		/* Get the aligned (down) start address and the aligned (up) end
		 * address
		 */

		start &= ~mask;
		end = (end + mask) & ~mask;

		/* Calculate the new size in granules */

		ngranules = ((end - start) >> priv->log2gran) + 1;

		/* And reserve the granules */

		gran_mark_allocated(priv, start, ngranules);
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gran_reserve
 *
 * Description:
 *   Reserve memory in the granule heap.  This will reserve the granules
 *   that contain the start and end addresses plus all of the granules
 *   in between.  This should be done early in the initialization sequence
 *   before any other allocations are made.
 *
 *   Reserved memory can never be allocated (it can be freed however which
 *   essentially unreserves the memory).
 *
 * Input Parameters:
 *   handle - The handle previously returned by gran_initialize
 *   start  - The address of the beginning of the region to be reserved.
 *   size   - The size of the region to be reserved
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

#ifdef CONFIG_GRAN_SINGLE
void gran_reserve(uintptr_t start, size_t size)
{
	return gran_common_reserve(g_graninfo, start, size);
}
#else
void gran_reserve(GRAN_HANDLE handle, uintptr_t start, size_t size)
{
	return gran_common_reserve((FAR struct gran_s *)handle, start, size);
}
#endif

#endif							/* CONFIG_GRAN */
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
 * mm/mm_gran/mm_pgalloc.c
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

#include <tinyara/mm/gran.h>
#include <tinyara/pgalloc.h>

#include "mm_gran/mm_gran.h"

#ifdef CONFIG_MM_PGALLOC

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Configuration ************************************************************/
/* CONFIG_MM_PGALLOC - Enable page allocator support
 * CONFIG_MM_PGSIZE - The page size.  Must be one of {1024, 2048,
 *   4096, 8192, or 16384}.  This is easily extensible, but only those
 *   values are currently support.
 * CONFIG_DEBUG_PGALLOC - Just like CONFIG_DEBUG_MM, but only generates
 *   output from the page allocation logic.
 *
 * Dependencies:  CONFIG_ARCH_USE_MMU and CONFIG_GRAN
 */

/* Debug */

#ifdef CONFIG_CPP_HAVE_VARARGS
#ifdef CONFIG_DEBUG_PGALLOC
#define pgadbg(format, ...)       dbg(format, ##__VA_ARGS__)
#define pgavdbg(format, ...)      vdbg(format, ##__VA_ARGS__)
#else
#define pgadbg(format, ...)       mdbg(format, ##__VA_ARGS__)
#define pgavdbg(format, ...)      mvdbg(format, ##__VA_ARGS__)
#endif
#else
#ifdef CONFIG_DEBUG_PGALLOC
#define pgadbg                    dbg
#define pgavdbg                   vdbg
#else
#define pgadbg                    (void)
#define pgavdbg                   (void)
#endif
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

#ifndef CONFIG_GRAN_SINGLE
/* The state of the page allocator */

static GRAN_HANDLE g_pgalloc;
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_pginitialize
 *
 * Description:
 *   Initialize the page allocator.
 *
 * Input Parameters:
 *   heap_start - The physical address of the start of memory region that
 *                will be used for the page allocator heap
 *   heap_size  - The size (in bytes) of the memory region that will be used
 *                for the page allocator heap.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void mm_pginitialize(FAR void *heap_start, size_t heap_size)
{
#ifdef CONFIG_GRAN_SINGLE
	int ret;

	ret = gran_initialize(heap_start, heap_size, MM_PGSHIFT, MM_PGSHIFT);
	DEBUGASSERT(ret == OK);
	UNUSED(ret);

#else
	g_pgalloc = gran_initialize(heap_start, heap_size, MM_PGSHIFT, MM_PGSHIFT);
	DEBUGASSERT(pg_alloc != NULL);

#endif
}

/****************************************************************************
 * Name: mm_pgreserve
 *
 * Description:
 *   Reserve memory in the page memory pool.  This will reserve the pages
 *   that contain the start and end addresses plus all of the pages
 *   in between.  This should be done early in the initialization sequence
 *   before any other allocations are made.
 *
 *   Reserved memory can never be allocated (it can be freed however which
 *   essentially unreserves the memory).
 *
 * Input Parameters:
 *   start  - The address of the beginning of the region to be reserved.
 *   size   - The size of the region to be reserved
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void mm_pgreserve(uintptr_t start, size_t size)
{
#ifdef CONFIG_GRAN_SINGLE
	gran_reserve(start, size);
#else
	gran_reserve(g_pgalloc, start, size);
#endif
}

/****************************************************************************
 * Name: mm_pgalloc
 *
 * Description:
 *   Allocate page memory from the page memory pool.
 *
 * Input Parameters:
 *   npages - The number of pages to allocate, each of size CONFIG_MM_PGSIZE.
 *
 * Returned Value:
 *   On success, a non-zero, physical address of the allocated page memory
 *   is returned.  Zero is returned on failure.  NOTE:  This is an unmapped
 *   physical address and cannot be used until it is appropriately mapped.
 *
 ****************************************************************************/

uintptr_t mm_pgalloc(unsigned int npages)
{
#ifdef CONFIG_GRAN_SINGLE
	return (uintptr_t)gran_alloc((size_t)1 << MM_PGSHIFT);
#else
	return (uintptr_t)gran_alloc(g_pgalloc, (size_t)1 << MM_PGSHIFT);
#endif
}

/****************************************************************************
 * Name: mm_pgfree
 *
 * Description:
 *   Return page memory to the page memory pool.
 *
 * Input Parameters:
 *   paddr  - A physical address to a page in the page memory pool previously
 *            allocated by mm_pgalloc.
 *   npages - The number of contiguous pages to be return to the page memory
 *            pool, beginning with the page at paddr;
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void mm_pgfree(uintptr_t paddr, unsigned int npages)
{
#ifdef CONFIG_GRAN_SINGLE
	gran_free((FAR void *)paddr, (size_t)npages << MM_PGSHIFT);
#else
	gran_free(g_pgalloc, (FAR void *)paddr, (size_t)npages << MM_PGSHIFT);
#endif
}

#endif							/* CONFIG_MM_PGALLOC */
