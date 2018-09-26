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
/************************************************************************
 * libc/stdlib/lib_abort.c
 *
 *   Copyright (C) 2007, 2009, 2011-2012 Gregory Nutt. All rights reserved.
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
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>

#include <stdlib.h>
#include <pthread.h>

/************************************************************************
 * Pre-processor Definitions
 ************************************************************************/

/************************************************************************
 * Private Type Declarations
 ************************************************************************/

/****************************************************************************
 * Private Functions: EDIT
 * [WizIO]
 ****************************************************************************/

static inline int is_real(float x)
{
	const float infinite = 1.0F / 0.0F;
	return (x < infinite) && (x >= -infinite);
}

/************************************************************************
 * Global Variables
 ************************************************************************/

/************************************************************************
 * Private Variables
 ************************************************************************/

/************************************************************************
 * Private Function Prototypes
 ************************************************************************/

/************************************************************************
 * Private Functions
 ************************************************************************/

/************************************************************************
 * Public Functions
 ************************************************************************/

/************************************************************************
 * Name: Abort
 *
 * Description:
 *   The abort() first unblocks the SIGABRT signal, and then raises that
 *   signal for the calling process. This results in the abnormal
 *   termination of the process unless the SIGABRT signal is caught and
 *   the signal handler does not return.
 *
 *   If the abort() function causes process termination, all open
 *   streams are closed and flushed.
 *
 *   If the SIGABRT signal is ignored, or caught by a handler that
 *   returns, the abort() function will still terminate the process.
 *   It does this by restoring the default disposition for SIGABRT and
 *   then raising the signal for a second time.
 *
 * Input parameters:
 *   None
 *
 * Returned Value:
 *  This function does not return,
 *
 ************************************************************************/

void abort(void)
{
	/* TinyAra does not support standard signal functionality (like the
	 * behavior of the SIGABRT signal).  So no attempt is made to provide
	 * a conformant version of abort() at this time.  This version does not
	 * signal the calling thread all.
	 *
	 * Note that pthread_exit() is called instead of exit().  That is because
	 * we do no know if abort was called from a pthread or a normal thread
	 * (we could find out, of course).  If abort() is called from a non-pthread,
	 * then pthread_exit() should fail and fall back to call exit() anyway.
	 *
	 * If exit() is called (either below or via pthread_exit()), then exit()
	 * will flush and close all open files and terminate the thread.  If this
	 * function was called from a pthread, then pthread_exit() will complete
	 * any joins, but will not flush or close any streams.
	 */

#ifdef CONFIG_DISABLE_PTHREAD
	exit(EXIT_FAILURE);
#else
	pthread_exit(NULL);
#endif
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
/************************************************************************
 * libc/stdlib/lib_abs.c
 *
 *   Copyright (C) 2010-2011 Gregory Nutt. All rights reserved.
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
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>
#include <stdlib.h>

/************************************************************************
 * Global Functions
 ************************************************************************/

int abs(int j)
{
	if (j < 0) {
		j = -j;
	}
	return j;
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
 * libc/stdlib/lib_bsearch.c
 *
 *   Copyright (c) 1990, 1993
 *   The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdlib.h>
#include <assert.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bsearch
 *
 * Description:
 *   The bsearch() function will search an array of nel objects, the initial
 *   element of which is pointed to by 'base', for an element that matches
 *   the object pointed to by 'key'. The size of each element in the array
 *   is specified by 'width'. If the nel argument has the value zero, the
 *   comparison function pointed to by 'compar' will not be called and no
 *   match will be found.
 *
 *   The comparison function pointed to by 'compar' will be called with two
 *   arguments that point to the 'key' object and to an array element, in
 *   that order.
 *
 *   The application will ensure that the comparison function pointed to by
 *   'compar 'does not alter the contents of the array. The implementation
 *   may reorder elements of the array between calls to the comparison
 *   function, but will not alter the contents of any individual element.
 *
 *   The implementation will ensure that the first argument is always a
 *   pointer to the 'key'.
 *
 *   When the same objects (consisting of width bytes, irrespective of their
 *   current positions in the array) are passed more than once to the
 *   comparison function, the results will be consistent with one another.
 *   That is, the same object will always compare the same way with the key.
 *
 *   The application will ensure that the function returns an integer less
 *   than, equal to, or greater than 0 if the key object is considered,
 *   respectively, to be less than, to match, or to be greater than the
 *   array element. The application will ensure that the array consists of
 *   all the elements that compare less than, all the elements that compare
 *   equal to, and all the elements that compare greater than the key
 *   object, in that order.
 *
 *   (Based on description from OpenGroup.org).
 *
 * Returned Value:
 *   The bsearch() function will return a pointer to a matching member of
 *   the array, or a null pointer if no match is found. If two or more
 *   members compare equal, which member is returned is unspecified.
 *
 * Notes from the NetBSD version:
 *   The code below is a bit sneaky.  After a comparison fails, we divide
 *   the work in half by moving either left or right. If 'lim' is odd,
 *   moving left simply involves halving 'lim': e.g., when 'lim' is 5 we
 *   look at item 2, so we change 'lim' to 2 so that we will look at items
 *   0 & 1.  If 'lim' is even, the same applies.  If 'lim' is odd, moving
 *   right again involes halving 'lim', this time moving the base up one
 *   item past 'middle': e.g., when 'lim' is 5 we change base to item 3 and
 *   make 'lim' 2 so that we will look at items 3 and 4.  If 'lim' is
 *   even, however, we have to shrink it by one before halving: e.g.,
 *   when 'lim' is 4, we still looked at item 2, so we have to make 'lim'
 *   3, then halve, obtaining 1, so that we will only look at item 3.
 *
 ****************************************************************************/

FAR void *bsearch(FAR const void *key, FAR const void *base, size_t nel, size_t width, CODE int (*compar)(FAR const void *, FAR const void *))
{
	FAR const void *middle;		/* Current entry being tested */
	FAR const char *lower;		/* The lower limit of the search region */
	size_t lim;					/* The number of elements in the region */
	int cmp;					/* Boolean comparison result */

	DEBUGASSERT(key != NULL);
	DEBUGASSERT(base != NULL || nel == 0);
	DEBUGASSERT(compar != NULL);

	for (lim = nel, lower = (const char *)base; lim != 0; lim >>= 1) {
		middle = lower + (lim >> 1) * width;
		cmp = (*compar)(key, middle);

		if (cmp == 0) {
			return (FAR void *)middle;
		}

		if (cmp > 0) {
			/* key > middle: move right (else move left) */

			lower = (FAR const char *)middle + width;
			lim--;
		}
	}

	return NULL;
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
 * libc/stdlib/lib_checkbase.c
 *
 *   Copyright (C) 2007, 2009, 2011 Gregory Nutt. All rights reserved.
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
#include <ctype.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_checkbase
 *
 * Description:
 *   This is part of the strol() family implementation.  This function checks
 *   the initial part of a string to see if it can determine the numeric
 *   base that is represented.
 *
 * Assumptions:
 *   *ptr points to the first, non-whitespace character in the string.
 *
 * Returns:
 *   - if base is valid, the actual base to use, and pptr is updated to point
 *     at the first digit.
 *   - if base is invalid (<2 or >36), return -1.
 *
 ****************************************************************************/

int lib_checkbase(int base, FAR const char **pptr)
{
	const char *ptr = *pptr;

	/* Check for unspecified base */

	if (!base) {
		/* Assume base 10 */

		base = 10;

		/* Check for leading '0' - that would signify octal or hex (or binary) */

		if (*ptr == '0') {
			/* Assume octal */

			base = 8;
			ptr++;

			/* Check for hexadecimal */

			if ((*ptr == 'X' || *ptr == 'x') && lib_isbasedigit(ptr[1], 16, NULL)) {
				base = 16;
				ptr++;
			}
		}
	}

	/* If it a hexadecimal representation, than discard any leading "0X" or "0x" */

	else if (base == 16) {
		if (ptr[0] == '0' && (ptr[1] == 'X' || ptr[1] == 'x')) {
			ptr += 2;
		}
	}

	/* Check for incorrect bases. */
	else if (base < 2 || base > 26) {
		return -1;				/* Means incorrect base */
	}

	/* Return the updated pointer and base */

	*pptr = ptr;
	return base;
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
 * libc/stdlib/lib_div.c
 *
 *   Copyright (C) 2015 Stavros Polymenis. All rights reserved.
 *   Author: Stavros Polymenis <sp@orbitalfox.com>
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
#include <tinyara/compiler.h>

#include <stdlib.h>

#ifdef CONFIG_CAN_PASS_STRUCTS

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: div
 *
 * Description:
 *   The div() function computes the quotient and remainder of the division
 *   of the numerator 'numer' by the denominator 'denom". If the division is
 *   inexact, the resulting quotient is the integer of lesser magnitude that
 *   is the nearest to the algebraic quotient. If the result cannot be
 *   represented, the behavior is undefined; otherwise, quot * denom + rem
 *   will equal 'numer'.
 *
 * Input Parameters:
 *   numer - Numerator of the Division
 *   denom - Denominator of the division
 *
 * Returned Value:
 *   The result of the devision represent as values of type div_t
 *
 ****************************************************************************/

div_t div(int numer, int denom)
{
	div_t f;

	f.quot = numer / denom;
	f.rem = numer % denom;
	return f;
}

#endif							/* CONFIG_CAN_PASS_STRUCTS */
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
/************************************************************************
 * libc/stdlib/lib_itoa.c
 *
 *   Copyright (C) 2013 Brooks Automation, Inc. All rights reserved.
 *   Author: Ryan Sundberg <ryan.sundberg@brooks.com>
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2010-2011 Gregory Nutt. All rights reserved.
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
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>
#include <stdlib.h>

/************************************************************************
 * Global Functions
 ************************************************************************/

char *itoa(int val, char *str, int base)
{
	static const char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	int intval = abs(val), digit, pos, len;
	char *buf = str;
	char swap;

	if (base >= 2 && base <= 36) {
		do {
			digit = intval % base;
			intval = intval / base;
			*buf++ = digits[digit];
		} while (intval > 0);

		if (val < 0) {
			*buf++ = '-';
		}

		for (pos = 0, len = buf - str; pos < len / 2; pos++) {
			swap = str[len - pos - 1];
			str[len - pos - 1] = str[pos];
			str[pos] = swap;
		}
	}

	*buf = '\0';

	return str;
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
/************************************************************************
 * libc/stdlib/lib_labs.c
 *
 *   Copyright (C) 2010-2011 Gregory Nutt. All rights reserved.
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
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>
#include <stdlib.h>

/************************************************************************
 * Global Functions
 ************************************************************************/

long int labs(long int j)
{
	if (j < 0) {
		j = -j;
	}
	return j;
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
 * libc/stdlib/lib_ldiv.c
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * A direct leverage of the div() inplement by:
 *
 *   Copyright (C) 2015 Stavros Polymenis. All rights reserved.
 *   Author: Stavros Polymenis <sp@orbitalfox.com>
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
#include <tinyara/compiler.h>

#include <stdlib.h>

#ifdef CONFIG_CAN_PASS_STRUCTS

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: ldiv
 *
 * Description:
 *   The ldiv() function computes the quotient and remainder of the division
 *   of the numerator 'numer' by the denominator 'denom". If the division is
 *   inexact, the resulting quotient is the integer of lesser magnitude that
 *   is the nearest to the algebraic quotient. If the result cannot be
 *   represented, the behavior is undefined; otherwise, quot * denom + rem
 *   will equal 'numer'.
 *
 * Input Parameters:
 *   numer - Numerator of the Division
 *   denom - Denominator of the division
 *
 * Returned Value:
 *   The result of the devision represent as values of type ldiv_t
 *
 ****************************************************************************/

ldiv_t ldiv(long numer, long denom)
{
	ldiv_t f;

	f.quot = numer / denom;
	f.rem = numer % denom;
	return f;
}

#endif							/* CONFIG_CAN_PASS_STRUCTS */
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
/************************************************************************
 * libc/stdlib/lib_llabs.c
 *
 *   Copyright (C) 2010-2011 Gregory Nutt. All rights reserved.
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
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>
#include <stdlib.h>

/************************************************************************
 * Global Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_LONG
long long int llabs(long long int j)
{
	if (j < 0) {
		j = -j;
	}
	return j;
}
#endif
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
 * libc/stdlib/lib_lldiv.c
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * A direct leverage of the div() inplement by:
 *
 *   Copyright (C) 2015 Stavros Polymenis. All rights reserved.
 *   Author: Stavros Polymenis <sp@orbitalfox.com>
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
#include <tinyara/compiler.h>

#include <stdlib.h>

#if defined(CONFIG_CAN_PASS_STRUCTS) && defined(CONFIG_HAVE_LONG_LONG)

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lldiv
 *
 * Description:
 *   The lldiv() function computes the quotient and remainder of the division
 *   of the numerator 'numer' by the denominator 'denom". If the division is
 *   inexact, the resulting quotient is the integer of lesser magnitude that
 *   is the nearest to the algebraic quotient. If the result cannot be
 *   represented, the behavior is undefined; otherwise, quot * denom + rem
 *   will equal 'numer'.
 *
 * Input Parameters:
 *   numer - Numerator of the Division
 *   denom - Denominator of the division
 *
 * Returned Value:
 *   The result of the devision represent as values of type lldiv_t
 *
 ****************************************************************************/

lldiv_t lldiv(long long numer, long long denom)
{
	lldiv_t f;

	f.quot = numer / denom;
	f.rem = numer % denom;
	return f;
}

#endif							/* CONFIG_CAN_PASS_STRUCTS && CONFIG_HAVE_LONG_LONG */
/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
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
 * lib/libc/stdlib/lib_mbtowc.c
 *
 *   Copyright (c)1999 Citrus Project,
 *   All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <stdlib.h>
#include <wchar.h>

#ifdef CONFIG_LIBC_WCHAR

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mbtowc.c
 *
 * Description:
 *   Minimal multibyte to wide char converter
 *
 ****************************************************************************/

int mbtowc(FAR wchar_t *pwc, FAR const char *s, size_t n)
{
	if (s == NULL) {
		return 0;
	}

	if (n == 0) {
		return -1;
	}

	if (pwc) {
		*pwc = (wchar_t) * s;
	}

	return (*s != '\0');
}
#endif
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
 * libc/stdlib/lib_mkstemp.c
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
#include <tinyara/compiler.h>

#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lib_internal.h"

#ifdef CONFIG_FS_WRITABLE

/****************************************************************************
 * Pre-processor definitions
 ****************************************************************************/

#ifndef CONFIG_LIBC_TMPDIR
#define CONFIG_LIBC_TMPDIR "/tmp"
#endif

#define MAX_XS 6
#define BIG_XS 5

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mkstemp
 *
 * Description:
 *   The mkstemp() function replaces the contents of the string pointed to
 *   by path_template by a unique filename, and returns a file descriptor
 *   for the file open for reading and writing. The function thus prevents
 *   any possible race condition between testing whether the file exists and
 *   opening it for use. The string in path_template should look like a
 *   filename with six trailing 'X' s; mkstemp() replaces each 'X' with a
 *   character from the portable filename character set. The characters are
 *   chosen such that the resulting name does not duplicate the name of an
 *   existing file at the time of a call to mkstemp().
 *
 * Input Parameters:
 *   path_template - The base file name that will be modified to produce
 *     the unique file name.  This must be a full path beginning with /tmp.
 *     This function will modify only the first XXXXXX characters within
 *     that full path.
 *
 * Returned Value:
 *
 * Upon successful completion, mkstemp() returns an open file descriptor.
 * Otherwise, -1 is returned if no suitable file could be created.
 *
 ****************************************************************************/

int mkstemp(FAR char *path_template)
{
	uint32_t retries;
	FAR char *xptr;
	FAR char *ptr;
	int xlen;
	int fd;
	int i;

	if (!path_template) {
		set_errno(EINVAL);
		return ERROR;
	}

	/* Count the number of X's at the end of the template */

	xptr = strchr(path_template, 'X');
	if (!xptr) {
		/* No Xs?  There should always really be 6 */

		return open(path_template, O_RDWR | O_CREAT | O_EXCL, 0666);
	}

	/* There is at least one.. count all of them */

	for (xlen = 0, ptr = xptr; xlen < MAX_XS && *ptr == 'X'; xlen++, ptr++);

	/* If xlen is small, then we need to determine the maximum number of
	 * retries before the values will repeat.
	 */

	if (xlen >= BIG_XS) {
		retries = UINT32_MAX;
	} else {
		for (i = 1, retries = 62; i < xlen; i++, retries *= 62);
	}

	/* Then loop until we find a unique file name */

	do {
		/* Form the candidate file name */

		(void)__randname(xptr, xlen);

		/* Attempt to open the candidate file -- creating it exclusively
		 *
		 * REVISIT: This prohibits the use of this function to create unique
		 * directories
		 */

		fd = open(path_template, O_RDWR | O_CREAT | O_EXCL, 0666);
		if (fd >= 0) {
			/* We have it... return the file descriptor */

			return fd;
		}
	} while (--retries && get_errno() == EEXIST);

	/* We could not find an unique filename */

	return ERROR;
}

#endif							/* CONFIG_FS_WRITABLE */
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
 *
 * Copyright © 2005-2014 Rich Felker, et al.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ***************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/stat.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: mktemp
 *
 * Description:
 *   The use of mktemp is dangerous; use mkstemp instead.
 *   The mktemp() function generates a unique temporary filename from template.
 *   The last six characters of template must be XXXXXX and these are replaced
 *   with a  string  that  makes the filename unique.
 *   Since it will be modified, template must not be a string constant,
 *   but should be declared as a character array.
 *
 * Return Value:
 *   The mktemp() function always returns template.
 *   If a unique name was created,  the  last six  bytes  of template will have
 *   been modified in such a way that the resulting name is unique
 *   (i.e., does not exist already) If a unique name could not be created,
 *   template is made an empty string, and errno is set to indicate the error.
 *
 ****************************************************************************/

FAR char *mktemp(FAR char *path_template)
{
	size_t len;
	int retries = 100;
	struct stat st;

	if (!path_template) {
		set_errno(EINVAL);
		return NULL;
	}

	len = strlen(path_template);

	/* Check the number of X's at the end of the template */

	if (len < 6 || memcmp((path_template + len - 6), "XXXXXX", 6)) {
		/* No Xs?  There should always really be 6 */
		set_errno(EINVAL);
		*path_template = '\0';
		return path_template;
	}

	/* Then loop until we find a unique file name */

	do {
		/* Form the candidate file name */

		__randname((path_template + len - 6), 6);

		/* Check whether the file with name generated exist or not */

		if (stat(path_template, &st)) {
			if (get_errno() != ENOENT) {
				*path_template = '\0';
			}
			return path_template;
		}
	} while (--retries);

	/* We could not find an unique filename */

	*path_template = '\0';
	set_errno(EEXIST);

	return path_template;
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
 * libc/stdlib/lib_qsort.c
 *
 *   Copyright (C) 2007, 2009, 2011 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Leveraged from:
 *
 *  Copyright (c) 1992, 1993
 *  The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the University of
 *    California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdlib.h>

/****************************************************************************
 * Preprocessor Definitions
 ****************************************************************************/

#define min(a, b)  (a) < (b) ? a : b

#define swapcode(TYPE, parmi, parmj, n) \
	do { \
		long i = (n) / sizeof(TYPE); \
		register TYPE *pi = (TYPE *)(parmi); \
		register TYPE *pj = (TYPE *)(parmj); \
		do { \
			register TYPE  t = *pi; \
			*pi++ = *pj; \
			*pj++ = t; \
		} while (--i > 0); \
	} while (0)

#define SWAPINIT(a, size) \
	swaptype = ((char *)a - (char *)0) % sizeof(long) || \
	size % sizeof(long) ? 2 : size == sizeof(long) ? 0 : 1;

#define swap(a, b) \
	if (swaptype == 0) { \
		long t = *(long *)(a); \
		*(long *)(a) = *(long *)(b); \
		*(long *)(b) = t; \
	} else { \
		swapfunc(a, b, size, swaptype); \
	}

#define vecswap(a, b, n) if ((n) > 0) swapfunc(a, b, n, swaptype)

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static inline void swapfunc(char *a, char *b, int n, int swaptype);
static inline char *med3(char *a, char *b, char *c, int (*compar)(const void *, const void *));

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static inline void swapfunc(char *a, char *b, int n, int swaptype)
{
	if (swaptype <= 1) {
		swapcode(long, a, b, n);
	} else {
		swapcode(char, a, b, n);
	}
}
static inline char *med3(char *a, char *b, char *c, int (*compar)(const void *, const void *))
{
	return compar(a, b) < 0 ? (compar(b, c) < 0 ? b : (compar(a, c) < 0 ? c : a))
		   : (compar(b, c) > 0 ? b : (compar(a, c) < 0 ? a : c));
}

/****************************************************************************
 * Public Function
 ****************************************************************************/

/****************************************************************************
 * Name: qsort
 *
 * Description:
 *   Qsort routine from Bentley & McIlroy's "Engineering a Sort Function".
 *
 ****************************************************************************/

void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
	int d, r, swaptype, swap_cnt;

loop:
	SWAPINIT(base, size);
	swap_cnt = 0;
	if (nmemb < 7) {
		for (pm = (char *)base + size; pm < (char *)base + nmemb * size; pm += size) {
			for (pl = pm; pl > (char *)base && compar(pl - size, pl) > 0; pl -= size) {
				swap(pl, pl - size);
			}
		}
		return;
	}

	pm = (char *)base + (nmemb / 2) * size;
	if (nmemb > 7) {
		pl = base;
		pn = (char *)base + (nmemb - 1) * size;
		if (nmemb > 40) {
			d = (nmemb / 8) * size;
			pl = med3(pl, pl + d, pl + 2 * d, compar);
			pm = med3(pm - d, pm, pm + d, compar);
			pn = med3(pn - 2 * d, pn - d, pn, compar);
		}
		pm = med3(pl, pm, pn, compar);
	}
	swap(base, pm);
	pa = pb = (char *)base + size;

	pc = pd = (char *)base + (nmemb - 1) * size;
	for (;;) {
		while (pb <= pc && (r = compar(pb, base)) <= 0) {
			if (r == 0) {
				swap_cnt = 1;
				swap(pa, pb);
				pa += size;
			}
			pb += size;
		}
		while (pb <= pc && (r = compar(pc, base)) >= 0) {
			if (r == 0) {
				swap_cnt = 1;
				swap(pc, pd);
				pd -= size;
			}
			pc -= size;
		}

		if (pb > pc) {
			break;
		}

		swap(pb, pc);
		swap_cnt = 1;
		pb += size;
		pc -= size;
	}

	if (swap_cnt == 0) {
		/* Switch to insertion sort */

		for (pm = (char *)base + size; pm < (char *)base + nmemb * size; pm += size) {
			for (pl = pm; pl > (char *)base && compar(pl - size, pl) > 0; pl -= size) {
				swap(pl, pl - size);
			}
		}

		return;
	}

	pn = (char *)base + nmemb * size;
	r = min(pa - (char *)base, pb - pa);
	vecswap(base, pb - r, r);
	r = min(pd - pc, pn - pd - size);
	vecswap(pb, pn - r, r);

	if ((r = pb - pa) > size) {
		qsort(base, r / size, size, compar);
	}

	if ((r = pd - pc) > size) {
		/* Iterate rather than recurse to save stack space */

		base = pn - r;
		nmemb = r / size;
		goto loop;
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
 * libc/stdlib/lib_rand.c
 *
 *   Copyright (C) 2007, 2011 Gregory Nutt. All rights reserved.
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

#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* First, second, and thired order congruential generators are supported */

#ifndef CONFIG_LIB_RAND_ORDER
#define CONFIG_LIB_RAND_ORDER 1
#endif

#if CONFIG_LIB_RAND_ORDER > 3
#undef CONFIG_LIB_RAND_ORDER
#define CONFIG_LIB_RAND_ORDER 3
#endif

/* Values needed by the random number generator */

#define RND1_CONSTK  470001
#define RND1_CONSTP  999563
#define RND2_CONSTK1 366528
#define RND2_CONSTK2 508531
#define RND2_CONSTP  998917
#define RND3_CONSTK1 360137
#define RND3_CONSTK2 519815
#define RND3_CONSTK3 616087
#define RND3_CONSTP  997783

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static unsigned int nrand(unsigned int nLimit);

/* First order congruential generators */

static inline unsigned long fgenerate1(void);
#if (CONFIG_LIB_RAND_ORDER == 1)
static double_t frand1(void);
#endif

/* Second order congruential generators */

#if (CONFIG_LIB_RAND_ORDER > 1)
static inline unsigned long fgenerate2(void);
#if (CONFIG_LIB_RAND_ORDER == 2)
static double_t frand2(void);
#endif

/* Third order congruential generators */

#if (CONFIG_LIB_RAND_ORDER > 2)
static inline unsigned long fgenerate3(void);
static double_t frand3(void);
#endif
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

static unsigned long g_randint1;
#if (CONFIG_LIB_RAND_ORDER > 1)
static unsigned long g_randint2;
#if (CONFIG_LIB_RAND_ORDER > 2)
static unsigned long g_randint3;
#endif
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static unsigned int nrand(unsigned int nLimit)
{
	unsigned long result;
	double_t ratio;

	/* Loop to be sure a legal random number is generated */

	do {
		/* Get a random integer in the requested range */

#if (CONFIG_LIB_RAND_ORDER == 1)
		ratio = frand1();
#elif (CONFIG_LIB_RAND_ORDER == 2)
		ratio = frand2();
#else							/* if (CONFIG_LIB_RAND_ORDER > 2) */
		ratio = frand3();
#endif

		/* Then, produce the return-able value */

		result = (unsigned long)(((double_t)nLimit) * ratio);
	} while (result >= (unsigned long)nLimit);

	return (unsigned int)result;
}

/* First order congruential generators */

static inline unsigned long fgenerate1(void)
{
	unsigned long randint;

	/* First order congruential generator.  One may be added to the result of the
	 * generated value to avoid the value zero.  This would be fatal for the
	 * first order random number generator.
	 */

	randint = (RND1_CONSTK * g_randint1) % RND1_CONSTP;
	g_randint1 = (randint == 0 ? 1 : randint);
	return randint;
}

#if (CONFIG_LIB_RAND_ORDER == 1)
static double_t frand1(void)
{
	/* First order congruential generator. */

	unsigned long randint = fgenerate1();

	/* Construct an floating point value in the range from 0.0 up to 1.0 */

	return ((double_t)randint) / ((double_t)RND1_CONSTP);
}
#endif

/* Second order congruential generators */

#if (CONFIG_LIB_RAND_ORDER > 1)
static inline unsigned long fgenerate2(void)
{
	unsigned long randint;

	/* Second order congruential generator. */

	randint = (RND2_CONSTK1 * g_randint1 + RND2_CONSTK2 * g_randint2) % RND2_CONSTP;

	g_randint2 = g_randint1;
	g_randint1 = randint;

	/* We cannot permit both values to become zero.  That would be fatal for the
	 * second order random number generator.
	 */

	if (g_randint2 == 0 && g_randint1 == 0) {
		g_randint2 = 1;
	}

	return randint;
}

#if (CONFIG_LIB_RAND_ORDER == 2)
static double_t frand2(void)
{
	/* Second order congruential generator */

	unsigned long randint = fgenerate2();

	/* Construct an floating point value in the range from 0.0 up to 1.0 */

	return ((double_t)randint) / ((double_t)RND2_CONSTP);
}
#endif

/* Third order congruential generators */

#if (CONFIG_LIB_RAND_ORDER > 2)
static inline unsigned long fgenerate3(void)
{
	unsigned long randint;

	/* Third order congruential generator. */

	randint = (RND3_CONSTK1 * g_randint1 + RND3_CONSTK2 * g_randint2 + RND3_CONSTK2 * g_randint3) % RND3_CONSTP;

	g_randint3 = g_randint2;
	g_randint2 = g_randint1;
	g_randint1 = randint;

	/* We cannot permit all three values to become zero.  That would be fatal for the
	 * third order random number generator.
	 */

	if (g_randint3 == 0 && g_randint2 == 0 && g_randint1 == 0) {
		g_randint3 = 1;
	}

	return randint;
}

static double_t frand3(void)
{
	/* Third order congruential generator */

	unsigned long randint = fgenerate3();

	/* Construct an floating point value in the range from 0.0 up to 1.0 */

	return ((double_t)randint) / ((double_t)RND3_CONSTP);
}
#endif
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  srand, rand
 ****************************************************************************/

void srand(unsigned int seed)
{
	g_randint1 = seed;
#if (CONFIG_LIB_RAND_ORDER > 1)
	g_randint2 = seed;
	(void)fgenerate1();
#if (CONFIG_LIB_RAND_ORDER > 2)
	g_randint3 = seed;
	(void)fgenerate2();
#endif
#endif
}

int rand(void)
{
	return (int)nrand(INT_MAX);
}

/****************************************************************************
 * Name:  random
 *
 * Description:
 *   Generate a non-negative, integer random number in the range of 0 through
 *   (LONG_MAX - 1)
 *
 ****************************************************************************/

long random(void)
{
	return (long)nrand(LONG_MAX);
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
 * libc/stdlib/lib_strtod.c
 * Convert string to double
 *
 *   Copyright (C) 2002 Michael Ringgaard. All rights reserved.
 *   Copyright (C) 2006-2007 H. Peter Anvin.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#ifdef CONFIG_HAVE_DOUBLE

/****************************************************************************
 * Pre-processor definitions
 ****************************************************************************/

/* These are predefined with GCC, but could be issues for other compilers. If
 * not defined, an arbitrary big number is put in for now.  These should be
 * added to tinyara/compiler for your compiler.
 */

#if !defined(__DBL_MIN_EXP__) || !defined(__DBL_MAX_EXP__)
#ifdef CONFIG_CPP_HAVE_WARNING
#warning "Size of exponent is unknown"
#endif
#undef  __DBL_MIN_EXP__
#define __DBL_MIN_EXP__ (-1021)
#undef  __DBL_MAX_EXP__
#define __DBL_MAX_EXP__ (1024)
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

#if 0
static inline int is_real(double x)
{
	const double infinite = 1.0 / 0.0;
	return (x < infinite) && (x >= -infinite);
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/***************************************************(************************
 * Name: strtod
 *
 * Description:
 *   Convert a string to a double value
 *
 ****************************************************************************/

double strtod(const char *str, char **endptr)
{
	double number;
	int exponent;
	int negative;
	FAR char *p = (char *)str;
	double p10;
	int n;
	int num_digits;
	int num_decimals;
	const double infinite = 1.0 / 0.0;

	/* Skip leading whitespace */

	while (isspace(*p)) {
		p++;
	}

	/* Handle optional sign */

	negative = 0;
	switch (*p) {
	case '-':
		negative = 1;			/* Fall through to increment position */
	case '+':
		p++;
	}

	number = 0.;
	exponent = 0;
	num_digits = 0;
	num_decimals = 0;

	/* Process string of digits */

	while (isdigit(*p)) {
		number = number * 10. + (*p - '0');
		p++;
		num_digits++;
	}

	/* Process decimal part */

	if (*p == '.') {
		p++;

		while (isdigit(*p)) {
			number = number * 10. + (*p - '0');
			p++;
			num_digits++;
			num_decimals++;
		}

		exponent -= num_decimals;
	}

	if (num_digits == 0) {
		set_errno(ERANGE);
		return 0.0;
	}

	/* Correct for sign */

	if (negative) {
		number = -number;
	}

	/* Process an exponent string */

	if (*p == 'e' || *p == 'E') {
		/* Handle optional sign */

		negative = 0;
		switch (*++p) {
		case '-':
			negative = 1;		/* Fall through to increment pos */
		case '+':
			p++;
		}

		/* Process string of digits */

		n = 0;
		while (isdigit(*p)) {
			n = n * 10 + (*p - '0');
			p++;
		}

		if (negative) {
			exponent -= n;
		} else {
			exponent += n;
		}
	}

	if (exponent < __DBL_MIN_EXP__ || exponent > __DBL_MAX_EXP__) {
		set_errno(ERANGE);
		return infinite;
	}

	/* Scale the result */

	p10 = 10.;
	n = exponent;
	if (n < 0) {
		n = -n;
	}
	while (n) {
		if (n & 1) {
			if (exponent < 0) {
				number /= p10;
			} else {
				number *= p10;
			}
		}
		n >>= 1;
		p10 *= p10;
	}

	if (!is_real(number)) {
		set_errno(ERANGE);
	}

	if (endptr) {
		*endptr = p;
	}

	return number;
}

#endif							/* CONFIG_HAVE_DOUBLE */
/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
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
 * lib/libc/stdlib/lib_strtof.c
 * Convert string to float
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *
 * A pretty straight forward conversion fo strtod():
 *
 *   Copyright (C) 2002 Michael Ringgaard. All rights reserved.
 *   Copyright (C) 2006-2007 H. Peter Anvin.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

/****************************************************************************
 * Pre-processor definitions
 ****************************************************************************/

/* These are predefined with GCC, but could be issues for other compilers. If
 * not defined, an arbitrary big number is put in for now.  These should be
 * added to tinyara/compiler for your compiler.
 */

#if !defined(__FLT_MIN_EXP__) || !defined(__FLT_MAX_EXP__)
#ifdef CONFIG_CPP_HAVE_WARNING
#warning "Size of exponent is unknown"
#endif
#undef  __FLT_MIN_EXP__
#define __FLT_MIN_EXP__ (-125)
#undef  __FLT_MAX_EXP__
#define __FLT_MAX_EXP__ (128)
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

#if 0
static inline int is_real(float x)
{
	const float infinite = 1.0F / 0.0F;
	return (x < infinite) && (x >= -infinite);
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/***************************************************(************************
 * Name: strtof
 *
 * Description:
 *   Convert a string to a float value
 *
 ****************************************************************************/

float strtof(FAR const char *str, FAR char **endptr)
{
	float number;
	int exponent;
	int negative;
	FAR char *p = (FAR char *)str;
	float p10;
	int n;
	int num_digits;
	int num_decimals;
	const float infinite = 1.0F / 0.0F;

	/* Skip leading whitespace */

	while (isspace(*p)) {
		p++;
	}

	/* Handle optional sign */

	negative = 0;
	switch (*p) {
	case '-':
		negative = 1;			/* Fall through to increment position */
	case '+':
		p++;
	default:
		break;
	}

	number = 0.0F;
	exponent = 0;
	num_digits = 0;
	num_decimals = 0;

	/* Process string of digits */

	while (isdigit(*p)) {
		number = number * 10.0F + (float)(*p - '0');
		p++;
		num_digits++;
	}

	/* Process decimal part */

	if (*p == '.') {
		p++;

		while (isdigit(*p)) {
			number = number * 10.0F + (float)(*p - '0');
			p++;
			num_digits++;
			num_decimals++;
		}

		exponent -= num_decimals;
	}

	if (num_digits == 0) {
		set_errno(ERANGE);
		number = 0.0F;
		goto errout;
	}

	/* Correct for sign */

	if (negative) {
		number = -number;
	}

	/* Process an exponent string */

	if (*p == 'e' || *p == 'E') {
		/* Handle optional sign */

		negative = 0;
		switch (*++p) {
		case '-':
			negative = 1;		/* Fall through to increment pos */
		case '+':
			p++;
		default:
			break;
		}

		/* Process string of digits */

		n = 0;
		while (isdigit(*p)) {
			n = n * 10 + (*p - '0');
			p++;
		}

		if (negative) {
			exponent -= n;
		} else {
			exponent += n;
		}
	}

	if (exponent < __FLT_MIN_EXP__ || exponent > __FLT_MAX_EXP__) {
		set_errno(ERANGE);
		number = infinite;
		goto errout;
	}

	/* Scale the result */

	p10 = 10.0F;
	n = exponent;
	if (n < 0) {
		n = -n;
	}
	while (n) {
		if (n & 1) {
			if (exponent < 0) {
				number /= p10;
			} else {
				number *= p10;
			}
		}

		n >>= 1;
		p10 *= p10;
	}

	if (!is_real(number)) {
		set_errno(ERANGE);
	}

errout:
	if (endptr) {
		*endptr = p;
	}

	return number;
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
 * libc/stdlib/lib_strtol.c
 *
 *   Copyright (C) 2007, 2009, 2011 Gregory Nutt. All rights reserved.
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
#include <stdlib.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strtol
 *
 * Description:
 *   The  strtol() function  converts  the initial part of the string in
 *   nptr to a long integer value according to the given base, which must be
 *   between 2 and 36 inclusive, or be the special value 0.
 *
 * Returns:
 *   - The converted value, if the base and number are valid
 *   - 0 if an error occurs, and set errno to:
 *     * EINVAL if base < 2 or base > 36
 *   - LONG_MIN or LONG_MAX, of correct sign, if an overflow occurs,
 *     and set errno to:
 *     * ERANGE if the number cannot be represented using long
 *
 ****************************************************************************/

long strtol(const char *nptr, char **endptr, int base)
{
	unsigned long accum = 0;
	bool negate = false;

	if (nptr) {
		/* Skip leading spaces */

		lib_skipspace(&nptr);

		/* Check for leading + or - */

		if (*nptr == '-') {
			negate = true;
			nptr++;
		} else if (*nptr == '+') {
			nptr++;
		}

		/* Get the unsigned value */

		accum = strtoul(nptr, endptr, base);

		/* Correct the sign of the result */
		/* Correct the sign of the result and check for overflow */

		if (negate) {
			const unsigned long limit = ((unsigned long) - (LONG_MIN + 1)) + 1;

			if (accum > limit) {
				set_errno(ERANGE);
				return LONG_MIN;
			}

			return (accum == limit) ? LONG_MIN : -(long)accum;
		}

		if (accum > LONG_MAX) {
			set_errno(ERANGE);
			return LONG_MAX;
		}
	}

	return (long)accum;
}
/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
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
 * lib/libc/stdlib/lib_strtod.c
 * Convert string to long double
 *
 *   Copyright (C) 2002 Michael Ringgaard. All rights reserved.
 *   Copyright (C) 2006-2007 H. Peter Anvin.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#ifdef CONFIG_HAVE_LONG_DOUBLE

/****************************************************************************
 * Pre-processor definitions
 ****************************************************************************/

/* These are predefined with GCC, but could be issues for other compilers. If
 * not defined, an arbitrary big number is put in for now.  These should be
 * added to tinyara/compiler for your compiler.
 */

#if !defined(__LDBL_MIN_EXP__) || !defined(__LDBL_MAX_EXP__)
#ifdef CONFIG_CPP_HAVE_WARNING
#warning "Size of exponent is unknown"
#endif
#undef  __LDBL_MIN_EXP__
#define __LDBL_MIN_EXP__ (-1021)
#undef  __LDBL_MAX_EXP__
#define __LDBL_MAX_EXP__ (1024)
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

#if 0
static inline int is_real(long double x)
{
	const long double infinite = 1.0L / 0.0L;
	return (x < infinite) && (x >= -infinite);
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/***************************************************(************************
 * Name: strtold
 *
 * Description:
 *   Convert a string to a long double value
 *
 ****************************************************************************/

long double strtold(FAR const char *str, FAR char **endptr)
{
	long double number;
	int exponent;
	int negative;
	FAR char *p = (FAR char *)str;
	long double p10;
	int n;
	int num_digits;
	int num_decimals;
	const long double infinite = 1.0L / 0.0L;

	/* Skip leading whitespace */

	while (isspace(*p)) {
		p++;
	}

	/* Handle optional sign */

	negative = 0;
	switch (*p) {
	case '-':
		negative = 1;			/* Fall through to increment position */
	case '+':
		p++;
	default:
		break;
	}

	number = 0.0L;
	exponent = 0;
	num_digits = 0;
	num_decimals = 0;

	/* Process string of digits */

	while (isdigit(*p)) {
		number = number * 10.0L + (long double)(*p - '0');
		p++;
		num_digits++;
	}

	/* Process decimal part */

	if (*p == '.') {
		p++;

		while (isdigit(*p)) {
			number = number * 10.0L + (long double)(*p - '0');
			p++;
			num_digits++;
			num_decimals++;
		}

		exponent -= num_decimals;
	}

	if (num_digits == 0) {
		set_errno(ERANGE);
		number = 0.0L;
		goto errout;
	}

	/* Correct for sign */

	if (negative) {
		number = -number;
	}

	/* Process an exponent string */

	if (*p == 'e' || *p == 'E') {
		/* Handle optional sign */

		negative = 0;
		switch (*++p) {
		case '-':
			negative = 1;		/* Fall through to increment pos */
		case '+':
			p++;
		default:
			break;
		}

		/* Process string of digits */

		n = 0;
		while (isdigit(*p)) {
			n = n * 10 + (*p - '0');
			p++;
		}

		if (negative) {
			exponent -= n;
		} else {
			exponent += n;
		}
	}

	if (exponent < __LDBL_MIN_EXP__ || exponent > __LDBL_MAX_EXP__) {
		set_errno(ERANGE);
		number = infinite;
		goto errout;
	}

	/* Scale the result */

	p10 = 10.;
	n = exponent;
	if (n < 0) {
		n = -n;
	}
	while (n) {
		if (n & 1) {
			if (exponent < 0) {
				number /= p10;
			} else {
				number *= p10;
			}
		}

		n >>= 1;
		p10 *= p10;
	}

	if (!is_real(number)) {
		set_errno(ERANGE);
	}

errout:
	if (endptr) {
		*endptr = p;
	}

	return number;
}

#endif							/* CONFIG_HAVE_LONG_DOUBLE */
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
 * libc/stdlib/lib_strtoll.c
 *
 *   Copyright (C) 2009, 2011 Gregory Nutt. All rights reserved.
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
#include <stdlib.h>
#include <errno.h>

#include "lib_internal.h"

#ifdef CONFIG_HAVE_LONG_LONG

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strtoll
 *
 * Description:
 *   The strtoll() function  converts  the initial part of the string in
 *   nptr to a long long integer value according to the given base, which
 *   must be between 2 and 36 inclusive, or be the special value 0.
 *
 * Returns:
 *   - The converted value, if the base and number are valid
 *   - 0 if an error occurs, and set errno to:
 *     * EINVAL if base < 2 or base > 36
 *   - LLONG_MIN or LLONG_MAX, of correct sign, if an overflow occurs,
 *     and set errno to:
 *     * ERANGE if the number cannot be represented using long long
 *
 ****************************************************************************/

long long strtoll(const char *nptr, char **endptr, int base)
{
	unsigned long long accum = 0;
	bool negate = false;

	if (nptr) {
		/* Skip leading spaces */

		lib_skipspace(&nptr);

		/* Check for leading + or - */

		if (*nptr == '-') {
			negate = true;
			nptr++;
		} else if (*nptr == '+') {
			nptr++;
		}

		/* Get the unsigned value */

		accum = strtoull(nptr, endptr, base);

		/* Correct the sign of the result */
		/* Correct the sign of the result and check for overflow */

		if (negate) {
			const unsigned long long limit = ((unsigned long long) - (LLONG_MIN + 1)) + 1;

			if (accum > limit) {
				set_errno(ERANGE);
				return LLONG_MIN;
			}

			return (accum == limit) ? LLONG_MIN : -(long long)accum;
		}

		if (accum > LLONG_MAX) {
			set_errno(ERANGE);
			return LLONG_MAX;
		}
	}

	return (long long)accum;
}

#endif
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
 * /libc/stdlib/lib_strtoul.c
 *
 *   Copyright (C) 2007, 2009, 2011 Gregory Nutt. All rights reserved.
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
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strtoul
 *
 * Description:
 *   The strtoul() function  converts  the initial part of the string in
 *   nptr to a long unsigned integer value according to the given base, which
 *   must be between 2 and 36 inclusive, or be the special value 0.
 *
 * Returns:
 *   - The converted value, if the base and number are valid
 *   - 0 if an error occurs, and set errno to:
 *     * EINVAL if base < 2 or base > 36
 *   - ULONG_MAX if an overflow occurs, and set errno to:
 *     * ERANGE if the number cannot be represented using unsigned long
 *
 ****************************************************************************/

unsigned long strtoul(const char *nptr, char **endptr, int base)
{
	unsigned long prev, accum = 0;
	int value;

	if (nptr) {
		/* Skip leading spaces */

		lib_skipspace(&nptr);

		/* Check for unspecified base */
		/* Check for unspecified or incorrect base */

		base = lib_checkbase(base, &nptr);
		if (base < 0) {
			set_errno(EINVAL);
			return 0;
		}

		/* Accumulate each "digit" */

		while (lib_isbasedigit(*nptr, base, &value)) {
			prev = accum;
			accum = accum * base + value;
			nptr++;

			/* Check for overflow */

			if (accum < prev) {
				set_errno(ERANGE);
				accum = ULONG_MAX;
				break;
			}
		}

		/* Return the final pointer to the unused value */

		if (endptr) {
			*endptr = (char *)nptr;
		}
	}

	return accum;
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
 * /libc/stdlib/lib_strtoull.c
 *
 *   Copyright (C) 2009, 2010 Gregory Nutt. All rights reserved.
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
#include <tinyara/compiler.h>

#include <stdlib.h>
#include <errno.h>

#include "lib_internal.h"

#ifdef CONFIG_HAVE_LONG_LONG

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strtoull
 *
 * Description:
 *   The strtoull() function  converts  the initial part of the string in
 *   nptr to a long unsigned integer value according to the given base, which
 *   must be between 2 and 36 inclusive, or be the special value 0.
 *
 * Returns:
 *   - The converted value, if the base and number are valid
 *   - 0 if an error occurs, and set errno to:
 *     * EINVAL if base < 2 or base > 36
 *   - ULLONG_MAX if an overflow occurs, and set errno to:
 *     * ERANGE if the number cannot be represented using unsigned long long
 *
 ****************************************************************************/

unsigned long long strtoull(const char *nptr, char **endptr, int base)
{
	unsigned long long prev, accum = 0;
	int value;

	if (nptr) {
		/* Skip leading spaces */

		lib_skipspace(&nptr);

		/* Check for unspecified base */

		base = lib_checkbase(base, &nptr);
		if (base < 0) {
			set_errno(EINVAL);
			return 0;
		}

		/* Accumulate each "digit" */

		while (lib_isbasedigit(*nptr, base, &value)) {
			prev = accum;
			accum = accum * base + value;
			nptr++;

			/* Check for overflow */

			if (accum < prev) {
				set_errno(ERANGE);
				accum = 0;
				break;
			}
		}

		/* Return the final pointer to the unused value */

		if (endptr) {
			*endptr = (char *)nptr;
		}
	}
	return accum;
}
#endif
/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
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
 * lib/libc/stdlib/lib_wctomb.c
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <errno.h>

#ifdef CONFIG_LIBC_WCHAR

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: wctomb
 *
 * Description:
 *   Try to represent a wide character as a multi byte
 *
 ****************************************************************************/

int wctomb(FAR char *s, wchar_t wc)
{
	if (s == NULL) {
		return 0;
	}

	/* Verify that wchar is a valid single-byte character.  */

	if ((size_t) wc >= 0x100) {
		errno = EILSEQ;
		return -1;
	}

	*s = (char)wc;
	return 1;
}
#endif
/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
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
 *
 * Copyright © 2005-2014 Rich Felker, et al.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ***************************************************************************/

#include <time.h>
#include <stdint.h>

/* This assumes that a check for the
 * template size has already been made
 */

char *__randname(char *template, uint8_t len)
{
	int i;
	struct timespec ts;
	unsigned long r;

	if (template && len > 0) {
		clock_gettime(CLOCK_REALTIME, &ts);
		r = ts.tv_nsec * UINT16_MAX ^ ((uintptr_t)&ts / 16 + (uintptr_t)template);
		for (i = 0; i < len; i++, r >>= 5) {
			template[i] = 'A' + (r & 15) + (r & 16) * 2;
		}
	}

	return template;
}
   