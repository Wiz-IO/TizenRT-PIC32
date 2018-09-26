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
 * libc/stdio/lib_asprintf.c
 *
 *   Copyright (C) 2011-2012 Gregory Nutt. All rights reserved.
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

#include <stdio.h>
#include <stdarg.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/
//[WizIO] ADD

#define FLAG_SHOWPLUS            0x01
#define FLAG_ALTFORM             0x02
#define FLAG_HASDOT              0x04
#define FLAG_HASASTERISKWIDTH    0x08
#define FLAG_HASASTERISKTRUNC    0x10
#define FLAG_LONGPRECISION       0x20
#define FLAG_LONGLONGPRECISION   0x40
#define FLAG_NEGATE              0x80

#define SET_SHOWPLUS(f)          do { (f) |= FLAG_SHOWPLUS; } while (0)
#define SET_ALTFORM(f)           do { (f) |= FLAG_ALTFORM; } while (0)
#define SET_HASDOT(f)            do { (f) |= FLAG_HASDOT; } while (0)
#define SET_HASASTERISKWIDTH(f)  do { (f) |= FLAG_HASASTERISKWIDTH; } while (0)
#define SET_HASASTERISKTRUNC(f)  do { (f) |= FLAG_HASASTERISKTRUNC; } while (0)
#define SET_LONGPRECISION(f)     do { (f) |= FLAG_LONGPRECISION; } while (0)
#define SET_LONGLONGPRECISION(f) do { (f) |= FLAG_LONGLONGPRECISION; } while (0)
#define SET_NEGATE(f)            do { (f) |= FLAG_NEGATE; } while (0)

#define CLR_SHOWPLUS(f)          do { (f) &= ~FLAG_SHOWPLUS; } while (0)
#define CLR_ALTFORM(f)           do { (f) &= ~FLAG_ALTFORM; } while (0)
#define CLR_HASDOT(f)            do { (f) &= ~FLAG_HASDOT; } while (0)
#define CLR_HASASTERISKWIDTH(f)  do { (f) &= ~FLAG_HASASTERISKWIDTH; } while (0)
#define CLR_HASASTERISKTRUNC(f)  do { (f) &= ~FLAG_HASASTERISKTRUNC; } while (0)
#define CLR_LONGPRECISION(f)     do { (f) &= ~FLAG_LONGPRECISION; } while (0)
#define CLR_LONGLONGPRECISION(f) do { (f) &= ~FLAG_LONGLONGPRECISION; } while (0)
#define CLR_NEGATE(f)            do { (f) &= ~FLAG_NEGATE; } while (0)
#define CLR_SIGNED(f)            do { (f) &= ~(FLAG_SHOWPLUS|FLAG_NEGATE); } while (0)

#define IS_SHOWPLUS(f)           (((f) & FLAG_SHOWPLUS) != 0)
#define IS_ALTFORM(f)            (((f) & FLAG_ALTFORM) != 0)
#define IS_HASDOT(f)             (((f) & FLAG_HASDOT) != 0)
#define IS_HASASTERISKWIDTH(f)   (((f) & FLAG_HASASTERISKWIDTH) != 0)
#define IS_HASASTERISKTRUNC(f)   (((f) & FLAG_HASASTERISKTRUNC) != 0)
#define IS_LONGPRECISION(f)      (((f) & FLAG_LONGPRECISION) != 0)
#define IS_LONGLONGPRECISION(f)  (((f) & FLAG_LONGLONGPRECISION) != 0)
#define IS_NEGATE(f)             (((f) & FLAG_NEGATE) != 0)
#define IS_SIGNED(f)             (((f) & (FLAG_SHOWPLUS|FLAG_NEGATE)) != 0)

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: asprintf
 *
 * Description:
 *   This function is similar to sprintf, except that it dynamically
 *   allocates a string (as with malloc) to hold the output, instead of
 *   putting the output in a buffer you allocate in advance.  The ptr
 *   argument should be the address of a char * object, and a successful
 *   call to asprintf stores a pointer to the newly allocated string at that
 *   location.
 *
 * Returned Value:
 *   The returned value is the number of characters allocated for the buffer,
 *   or less than zero if an error occurred. Usually this means that the buffer
 *   could not be allocated.
 *
 ****************************************************************************/

int asprintf(FAR char **ptr, const char *fmt, ...)
{
	va_list ap;
	int ret;

	/* Let vasprintf do all of the work */

	va_start(ap, fmt);
	ret = vasprintf(ptr, fmt, ap);
	va_end(ap);

	return ret;
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
 * libc/stdio/lib_clearerr.c
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

#include <stdio.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#if CONFIG_NFILE_STREAMS > 0

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: Functions
 *
 * Description:
 *   Clear any end-of-file or error conditions.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void clearerr(FILE *stream)
{
	stream->fs_flags = 0;
}
#endif							/* CONFIG_NFILE_STREAMS */
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
 * libc/stdio/lib_dprintf.c
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

#include <stdio.h>

/****************************************************************************
 * Public Functions
 **************************************************************************/

/****************************************************************************
 * Name: dprintf
 **************************************************************************/

int dprintf(int fd, FAR const char *fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap, fmt);
	ret = vdprintf(fd, fmt, ap);
	va_end(ap);

	return ret;
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
 * libc/stdio/lib_dtoa.c
 *
 * This file was ported to NuttX by Yolande Cates.
 *
 * Copyright (c) 1990, 1993
 *      The Regents of the University of California.  All rights reserved.
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

#include <tinyara/config.h>

#include <stdint.h>
#include <string.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef Unsigned_Shifts
#define Sign_Extend(a, b) if (b < 0) a |= 0xffff0000;
#else
#define Sign_Extend(a, b)		/* no-op */
#endif

#ifdef CONFIG_ENDIAN_BIG
#define word0(x) ((uint32_t *)&x)[0]
#define word1(x) ((uint32_t *)&x)[1]
#else
#define word0(x) ((uint32_t *)&x)[1]
#define word1(x) ((uint32_t *)&x)[0]
#endif

#ifdef CONFIG_ENDIAN_BIG
#define Storeinc(a, b, c) (((unsigned short *)a)[0] = (unsigned short)b, \
						   ((unsigned short *)a)[1] = (unsigned short)c, a++)
#else
#define Storeinc(a, b, c) (((unsigned short *)a)[1] = (unsigned short)b, \
						   ((unsigned short *)a)[0] = (unsigned short)c, a++)
#endif

#define Exp_shift  20
#define Exp_shift1 20
#define Exp_msk1    0x100000
#define Exp_msk11   0x100000
#define Exp_mask  0x7ff00000
#define P 53
#define Bias 1023
#define IEEE_Arith
#define Emin (-1022)
#define Exp_1  0x3ff00000
#define Exp_11 0x3ff00000
#define Ebits 11
#define Frac_mask  0xfffff
#define Frac_mask1 0xfffff
#define Ten_pmax 22
#define Bletch 0x10
#define Bndry_mask  0xfffff
#define Bndry_mask1 0xfffff
#define LSB 1
#define Sign_bit 0x80000000
#define Log2P 1
#define Tiny0 0
#define Tiny1 1
#define Quick_max 14
#define Int_max 14
#define Infinite(x) (word0(x) == 0x7ff00000)	/* sufficient test for here */

#define Kmax 15

#define Bcopy(x, y) memcpy((char *)&x->sign, (char *)&y->sign, \
						   y->wds*sizeof(long) + 2*sizeof(int))

/****************************************************************************
 * Private Type Definitions
 ****************************************************************************/

struct Bigint {
	struct Bigint *next;
	int k;
	int maxwds;
	int sign;
	int wds;
	unsigned long x[1];
};

typedef struct Bigint Bigint;

/****************************************************************************
 * Private Data
 ****************************************************************************/

static Bigint *freelist[Kmax + 1];

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static Bigint *Balloc(int k)
{
	int x;
	Bigint *rv;

	if ((rv = freelist[k])) {
		freelist[k] = rv->next;
	} else {
		x = 1 << k;
		rv = (Bigint *)lib_malloc(sizeof(Bigint) + (x - 1) * sizeof(long));
		if (rv == NULL) {
			return NULL;
		}
		rv->k = k;
		rv->maxwds = x;
	}

	rv->sign = rv->wds = 0;
	return rv;
}

static void Bfree(Bigint *v)
{
	if (v) {
		v->next = freelist[v->k];
		freelist[v->k] = v;
	}
}

/* multiply by m and add a */

static Bigint *multadd(Bigint *b, int m, int a)
{
	int i, wds;
	unsigned long *x, y;
#ifdef Pack_32
	unsigned long xi, z;
#endif
	Bigint *b1;

	wds = b->wds;
	x = b->x;
	i = 0;
	do {
#ifdef Pack_32
		xi = *x;
		y = (xi & 0xffff) * m + a;
		z = (xi >> 16) * m + (y >> 16);
		a = (int)(z >> 16);
		*x++ = (z << 16) + (y & 0xffff);
#else
		y = *x * m + a;
		a = (int)(y >> 16);
		*x++ = y & 0xffff;
#endif
	} while (++i < wds);

	if (a) {
		if (wds >= b->maxwds) {
			b1 = Balloc(b->k + 1);
			Bcopy(b1, b);
			Bfree(b);
			b = b1;
		}
		b->x[wds++] = a;
		b->wds = wds;
	}

	return b;
}

static int hi0bits(unsigned long x)
{
	int k = 0;

	if (!(x & 0xffff0000)) {
		k = 16;
		x <<= 16;
	}

	if (!(x & 0xff000000)) {
		k += 8;
		x <<= 8;
	}

	if (!(x & 0xf0000000)) {
		k += 4;
		x <<= 4;
	}

	if (!(x & 0xc0000000)) {
		k += 2;
		x <<= 2;
	}

	if (!(x & 0x80000000)) {
		k++;
		if (!(x & 0x40000000)) {
			return 32;
		}
	}

	return k;
}

static int lo0bits(unsigned long *y)
{
	int k;
	unsigned long x = *y;

	if (x & 7) {
		if (x & 1) {
			return 0;
		}

		if (x & 2) {
			*y = x >> 1;
			return 1;
		}

		*y = x >> 2;
		return 2;
	}

	k = 0;
	if (!(x & 0xffff)) {
		k = 16;
		x >>= 16;
	}

	if (!(x & 0xff)) {
		k += 8;
		x >>= 8;
	}

	if (!(x & 0xf)) {
		k += 4;
		x >>= 4;
	}

	if (!(x & 0x3)) {
		k += 2;
		x >>= 2;
	}

	if (!(x & 1)) {
		k++;
		x >>= 1;
		if (!(x & 1)) {
			return 32;
		}
	}

	*y = x;
	return k;
}

static Bigint *i2b(int i)
{
	Bigint *b;

	b = Balloc(1);
	b->x[0] = i;
	b->wds = 1;
	return b;
}

static Bigint *mult(Bigint *a, Bigint *b)
{
	Bigint *c;
	int k, wa, wb, wc;
	unsigned long carry, y, z;
	unsigned long *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
#ifdef Pack_32
	uint32_t z2;
#endif

	if (a->wds < b->wds) {
		c = a;
		a = b;
		b = c;
	}

	k = a->k;
	wa = a->wds;
	wb = b->wds;
	wc = wa + wb;
	if (wc > a->maxwds) {
		k++;
	}

	c = Balloc(k);
	for (x = c->x, xa = x + wc; x < xa; x++) {
		*x = 0;
	}

	xa = a->x;
	xae = xa + wa;
	xb = b->x;
	xbe = xb + wb;
	xc0 = c->x;
#ifdef Pack_32
	for (; xb < xbe; xb++, xc0++) {
		if ((y = *xb & 0xffff)) {
			x = xa;
			xc = xc0;
			carry = 0;
			do {
				z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
				carry = z >> 16;
				z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
				carry = z2 >> 16;
				Storeinc(xc, z2, z);
			} while (x < xae);

			*xc = carry;
		}

		if ((y = *xb >> 16)) {
			x = xa;
			xc = xc0;
			carry = 0;
			z2 = *xc;
			do {
				z = (*x & 0xffff) * y + (*xc >> 16) + carry;
				carry = z >> 16;
				Storeinc(xc, z, z2);
				z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
				carry = z2 >> 16;
			} while (x < xae);

			*xc = z2;
		}
	}
#else
	for (; xb < xbe; xc0++) {
		if ((y = *xb++)) {
			x = xa;
			xc = xc0;
			carry = 0;
			do {
				z = *x++ * y + *xc + carry;
				carry = z >> 16;
				*xc++ = z & 0xffff;
			} while (x < xae);

			*xc = carry;
		}
	}
#endif

	for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc);
	c->wds = wc;
	return c;
}

static Bigint *p5s;

static Bigint *pow5mult(Bigint *b, int k)
{
	Bigint *b1, *p5, *p51;
	int i;
	static int p05[3] = { 5, 25, 125 };

	if ((i = k & 3)) {
		b = multadd(b, p05[i - 1], 0);
	}

	if (!(k >>= 2)) {
		return b;
	}

	if (!(p5 = p5s)) {
		/* first time */
		p5 = p5s = i2b(625);
		p5->next = 0;
	}

	for (;;) {
		if (k & 1) {
			b1 = mult(b, p5);
			Bfree(b);
			b = b1;
		}

		if (!(k >>= 1)) {
			break;
		}

		if (!(p51 = p5->next)) {
			p51 = p5->next = mult(p5, p5);
			p51->next = 0;
		}

		p5 = p51;
	}

	return b;
}

static Bigint *lshift(Bigint *b, int k)
{
	int i, k1, n, n1;
	Bigint *b1;
	unsigned long *x, *x1, *xe, z;

#ifdef Pack_32
	n = k >> 5;
#else
	n = k >> 4;
#endif
	k1 = b->k;
	n1 = n + b->wds + 1;
	for (i = b->maxwds; n1 > i; i <<= 1) {
		k1++;
	}

	b1 = Balloc(k1);
	x1 = b1->x;
	for (i = 0; i < n; i++) {
		*x1++ = 0;
	}

	x = b->x;
	xe = x + b->wds;
#ifdef Pack_32
	if (k &= 0x1f) {
		k1 = 32 - k;
		z = 0;
		do {
			*x1++ = *x << k | z;
			z = *x++ >> k1;
		} while (x < xe);

		if ((*x1 = z)) {
			++n1;
		}
	}
#else
	if (k &= 0xf) {
		k1 = 16 - k;
		z = 0;
		do {
			*x1++ = ((*x << k) & 0xffff) | z;
			z = *x++ >> k1;
		} while (x < xe);

		if ((*x1 = z)) {
			++n1;
		}
	}
#endif
	else {
		do {
			*x1++ = *x++;
		} while (x < xe);
	}

	b1->wds = n1 - 1;
	Bfree(b);
	return b1;
}

static int cmp(Bigint *a, Bigint *b)
{
	unsigned long *xa, *xa0, *xb, *xb0;
	int i, j;

	i = a->wds;
	j = b->wds;
#ifdef CONFIG_DEBUG_LIB
	if (i > 1 && !a->x[i - 1]) {
		ldbg("cmp called with a->x[a->wds-1] == 0\n");
	}

	if (j > 1 && !b->x[j - 1]) {
		ldbg("cmp called with b->x[b->wds-1] == 0\n");
	}
#endif

	if (i -= j) {
		return i;
	}

	xa0 = a->x;
	xa = xa0 + j;
	xb0 = b->x;
	xb = xb0 + j;
	for (;;) {
		if (*--xa != *--xb) {
			return *xa < *xb ? -1 : 1;
		}

		if (xa <= xa0) {
			break;
		}
	}
	return 0;
}

static Bigint *diff(Bigint *a, Bigint *b)
{
	Bigint *c;
	int i, wa, wb;
	long borrow, y;				/* We need signed shifts here. */
	unsigned long *xa, *xae, *xb, *xbe, *xc;
#ifdef Pack_32
	int32_t z;
#endif

	i = cmp(a, b);
	if (!i) {
		c = Balloc(0);
		c->wds = 1;
		c->x[0] = 0;
		return c;
	}

	if (i < 0) {
		c = a;
		a = b;
		b = c;
		i = 1;
	} else {
		i = 0;
	}

	c = Balloc(a->k);
	c->sign = i;
	wa = a->wds;
	xa = a->x;
	xae = xa + wa;
	wb = b->wds;
	xb = b->x;
	xbe = xb + wb;
	xc = c->x;
	borrow = 0;
#ifdef Pack_32
	do {
		y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
		borrow = y >> 16;
		Sign_Extend(borrow, y);
		z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
		borrow = z >> 16;
		Sign_Extend(borrow, z);
		Storeinc(xc, z, y);
	} while (xb < xbe);

	while (xa < xae) {
		y = (*xa & 0xffff) + borrow;
		borrow = y >> 16;
		Sign_Extend(borrow, y);
		z = (*xa++ >> 16) + borrow;
		borrow = z >> 16;
		Sign_Extend(borrow, z);
		Storeinc(xc, z, y);
	}
#else
	do {
		y = *xa++ - *xb++ + borrow;
		borrow = y >> 16;
		Sign_Extend(borrow, y);
		*xc++ = y & 0xffff;
	} while (xb < xbe);

	while (xa < xae) {
		y = *xa++ + borrow;
		borrow = y >> 16;
		Sign_Extend(borrow, y);
		*xc++ = y & 0xffff;
	}
#endif

	while (!*--xc) {
		wa--;
	}

	c->wds = wa;
	return c;
}

static Bigint *d2b(double d, int *e, int *bits)
{
	Bigint *b;
	int de, i, k;
	unsigned long *x, y, z;

#ifdef Pack_32
	b = Balloc(1);
#else
	b = Balloc(2);
#endif
	x = b->x;

	z = word0(d) & Frac_mask;
	word0(d) &= 0x7fffffff;		/* clear sign bit, which we ignore */
	if ((de = (int)(word0(d) >> Exp_shift))) {
		z |= Exp_msk1;
	}
#ifdef Pack_32
	if ((y = word1(d))) {
		if ((k = lo0bits(&y))) {
			x[0] = y | z << (32 - k);
			z >>= k;
		} else {
			x[0] = y;
		}

		i = b->wds = (x[1] = z) ? 2 : 1;
	} else {
#ifdef CONFIG_DEBUG_LIB
		if (!z) {
			ldbg("Zero passed to d2b\n");
		}
#endif
		k = lo0bits(&z);
		x[0] = z;
		i = b->wds = 1;
		k += 32;
	}
#else
	if ((y = word1(d))) {
		if ((k = lo0bits(&y)))
			if (k >= 16) {
				x[0] = y | ((z << (32 - k)) & 0xffff);
				x[1] = z >> (k - 16) & 0xffff;
				x[2] = z >> k;
				i = 2;
			} else {
				x[0] = y & 0xffff;
				x[1] = (y >> 16) | ((z << (16 - k)) & 0xffff);
				x[2] = z >> k & 0xffff;
				x[3] = z >> (k + 16);
				i = 3;
			}
		else {
			x[0] = y & 0xffff;
			x[1] = y >> 16;
			x[2] = z & 0xffff;
			x[3] = z >> 16;
			i = 3;
		}
	} else {
#ifdef CONFIG_DEBUG_LIB
		if (!z) {
			ldbg("Zero passed to d2b\n");
		}
#endif
		k = lo0bits(&z);
		if (k >= 16) {
			x[0] = z;
			i = 0;
		} else {
			x[0] = z & 0xffff;
			x[1] = z >> 16;
			i = 1;
		}

		k += 32;
	}
	while (!x[i]) {
		--i;
	}
	b->wds = i + 1;
#endif
	if (de) {
		*e = de - Bias - (P - 1) + k;
		*bits = P - k;
	} else {
		*e = de - Bias - (P - 1) + 1 + k;
#ifdef Pack_32
		*bits = 32 * i - hi0bits(x[i - 1]);
#else
		*bits = (i + 2) * 16 - hi0bits(x[i]);
#endif
	}

	return b;
}

static const double tens[] = {
	1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9,
	1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19,
	1e20, 1e21, 1e22
};

#ifdef IEEE_Arith
static const double bigtens[] = { 1e16, 1e32, 1e64, 1e128, 1e256 };

#define n_bigtens 5
#else
static const double bigtens[] = { 1e16, 1e32 };

#define n_bigtens 2
#endif

static int quorem(Bigint *b, Bigint *S)
{
	int n;
	long borrow, y;
	unsigned long carry, q, ys;
	unsigned long *bx, *bxe, *sx, *sxe;
#ifdef Pack_32
	int32_t z;
	uint32_t si, zs;
#endif

	n = S->wds;
#ifdef CONFIG_DEBUG_LIB
	if (b->wds > n) {
		ldbg("oversize b in quorem\n");
	}
#endif
	if (b->wds < n) {
		return 0;
	}

	sx = S->x;
	sxe = sx + --n;
	bx = b->x;
	bxe = bx + n;
	q = *bxe / (*sxe + 1);		/* ensure q <= true quotient */
#ifdef CONFIG_DEBUG_LIB
	if (q > 9) {
		ldbg("oversized quotient in quorem\n");
	}
#endif

	if (q) {
		borrow = 0;
		carry = 0;
		do {
#ifdef Pack_32
			si = *sx++;
			ys = (si & 0xffff) * q + carry;
			zs = (si >> 16) * q + (ys >> 16);
			carry = zs >> 16;
			y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
			borrow = y >> 16;
			Sign_Extend(borrow, y);
			z = (*bx >> 16) - (zs & 0xffff) + borrow;
			borrow = z >> 16;
			Sign_Extend(borrow, z);
			Storeinc(bx, z, y);
#else
			ys = *sx++ * q + carry;
			carry = ys >> 16;
			y = *bx - (ys & 0xffff) + borrow;
			borrow = y >> 16;
			Sign_Extend(borrow, y);
			*bx++ = y & 0xffff;
#endif
		} while (sx <= sxe);

		if (!*bxe) {
			bx = b->x;
			while (--bxe > bx && !*bxe) {
				--n;
			}

			b->wds = n;
		}
	}
	if (cmp(b, S) >= 0) {
		q++;
		borrow = 0;
		carry = 0;
		bx = b->x;
		sx = S->x;
		do {
#ifdef Pack_32
			si = *sx++;
			ys = (si & 0xffff) + carry;
			zs = (si >> 16) + (ys >> 16);
			carry = zs >> 16;
			y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
			borrow = y >> 16;
			Sign_Extend(borrow, y);
			z = (*bx >> 16) - (zs & 0xffff) + borrow;
			borrow = z >> 16;
			Sign_Extend(borrow, z);
			Storeinc(bx, z, y);
#else
			ys = *sx++ + carry;
			carry = ys >> 16;
			y = *bx - (ys & 0xffff) + borrow;
			borrow = y >> 16;
			Sign_Extend(borrow, y);
			*bx++ = y & 0xffff;
#endif
		} while (sx <= sxe);
		bx = b->x;
		bxe = bx + n;
		if (!*bxe) {
			while (--bxe > bx && !*bxe) {
				--n;
			}
			b->wds = n;
		}
	}

	return q;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/* dtoa for IEEE arithmetic (dmg): convert double to ASCII string.
 *
 * Inspired by "How to Print Floating-Point Numbers Accurately" by
 * Guy L. Steele, Jr. and Jon L. White [Proc. ACM SIGPLAN '90, pp. 92-101].
 *
 * Modifications:
 *      1. Rather than iterating, we use a simple numeric overestimate
 *         to determine k = floor(log10(d)).  We scale relevant
 *         quantities using O(log2(k)) rather than O(k) multiplications.
 *      2. For some modes > 2 (corresponding to ecvt and fcvt), we don't
 *         try to generate digits strictly left to right.  Instead, we
 *         compute with fewer bits and propagate the carry if necessary
 *         when rounding the final digit up.  This is often faster.
 *      3. Under the assumption that input will be rounded nearest,
 *         mode 0 renders 1e23 as 1e23 rather than 9.999999999999999e22.
 *         That is, we allow equality in stopping tests when the
 *         round-nearest rule will give the same floating-point value
 *         as would satisfaction of the stopping test with strict
 *         inequality.
 *      4. We remove common factors of powers of 2 from relevant
 *         quantities.
 *      5. When converting floating-point integers less than 1e16,
 *         we use floating-point arithmetic rather than resorting
 *         to multiple-precision integers.
 *      6. When asked to produce fewer than 15 digits, we first try
 *         to get by with floating-point arithmetic; we resort to
 *         multiple-precision integer arithmetic only if we cannot
 *         guarantee that the floating-point calculation has given
 *         the correctly rounded result.  For k requested digits and
 *         "uniformly" distributed input, the probability is
 *         something like 10^(k-15) that we must resort to the int32_t
 *         calculation.
 */

char *__dtoa(double d, int mode, int ndigits, int *decpt, int *sign, char **rve)
{
	/* Arguments ndigits, decpt, sign are similar to those of ecvt and fcvt;
	 * trailing zeros are suppressed from the returned string.  If not null, *rve
	 * is set to point to the end of the return value.  If d is +-Infinity or
	 * NaN, then *decpt is set to 9999.
	 *
	 * mode: 0 ==> shortest string that yields d when read in and rounded to
	 * nearest. 1 ==> like 0, but with Steele & White stopping rule; e.g. with
	 * IEEE P754 arithmetic , mode 0 gives 1e23 whereas mode 1 gives
	 * 9.999999999999999e22. 2 ==> max(1,ndigits) significant digits.  This gives
	 * a return value similar to that of ecvt, except that trailing zeros are
	 * suppressed. 3 ==> through ndigits past the decimal point.  This gives a
	 * return value similar to that from fcvt, except that trailing zeros are
	 * suppressed, and ndigits can be negative. 4-9 should give the same return
	 * values as 2-3, i.e., 4 <= mode <= 9 ==> same return as mode 2 + (mode &
	 * 1).  These modes are mainly for debugging; often they run slower but
	 * sometimes faster than modes 2-3. 4,5,8,9 ==> left-to-right digit
	 * generation. 6-9 ==> don't try fast floating-point estimate (if
	 * applicable).
	 *
	 * Values of mode other than 0-9 are treated as mode 0.
	 *
	 * Sufficient space is allocated to the return value to hold the suppressed
	 * trailing zeros. */

	int bbits;
	int b2;
	int b5;
	int be;
	int dig;
	int i;
	int ieps;
	int ilim = 0;
	int ilim0;
	int ilim1 = 0;
	int j;
	int j_1;
	int k;
	int k0;
	int k_check;
	int leftright;
	int m2;
	int m5;
	int s2;
	int s5;
	int spec_case = 0;
	int try_quick;
	long L;
	int denorm;
	unsigned long x;
	Bigint *b;
	Bigint *b1;
	Bigint *delta;
	Bigint *mlo = NULL;
	Bigint *mhi;
	Bigint *S;
	double d2;
	double ds;
	double eps;
	char *s;
	char *s0;
	static Bigint *result;
	static int result_k;

	if (result) {
		result->k = result_k;
		result->maxwds = 1 << result_k;
		Bfree(result);
		result = 0;
	}

	if (word0(d) & Sign_bit) {
		/* set sign for everything, including 0's and NaNs */
		*sign = 1;
		word0(d) &= ~Sign_bit;	/* clear sign bit */
	} else {
		*sign = 0;
	}

#if defined(IEEE_Arith)
#ifdef IEEE_Arith
	if ((word0(d) & Exp_mask) == Exp_mask)
#else
	if (word0(d) == 0x8000)
#endif
	{
		/* Infinity or NaN */
		*decpt = 9999;
		s =
#ifdef IEEE_Arith
			!word1(d) && !(word0(d) & 0xfffff) ? "Infinity" :
#endif
			"NaN";
		if (rve) {
			*rve =
#ifdef IEEE_Arith
				s[3] ? s + 8 :
#endif
				s + 3;
		}

		return s;
	}
#endif
	if (!d) {
		*decpt = 1;
		s = "0";
		if (rve) {
			*rve = s + 1;
		}

		return s;
	}

	b = d2b(d, &be, &bbits);
	if ((i = (int)(word0(d) >> Exp_shift1 & (Exp_mask >> Exp_shift1)))) {
		d2 = d;
		word0(d2) &= Frac_mask1;
		word0(d2) |= Exp_11;

		/* log(x) ~=~ log(1.5) + (x-1.5)/1.5 log10(x) = log(x) / log(10) ~=~
		 * log(1.5)/log(10) + (x-1.5)/(1.5*log(10)) log10(d) =
		 * (i-Bias)*log(2)/log(10) + log10(d2) This suggests computing an
		 * approximation k to log10(d) by k = (i - Bias)*0.301029995663981 + (
		 * (d2-1.5)*0.289529654602168 + 0.176091259055681 ); We want k to be too
		 * large rather than too small. The error in the first-order Taylor
		 * series approximation is in our favor, so we just round up the constant
		 * enough to compensate for any error in the multiplication of (i - Bias)
		 * by 0.301029995663981; since |i - Bias| <= 1077, and 1077 * 0.30103 *
		 * 2^-52 ~=~ 7.2e-14, adding 1e-13 to the constant term more than
		 * suffices. Hence we adjust the constant term to 0.1760912590558. (We
		 * could get a more accurate k by invoking log10, but this is probably
		 * not worthwhile.) */

		i -= Bias;
		denorm = 0;
	} else {
		/* d is denormalized */

		i = bbits + be + (Bias + (P - 1) - 1);
		x = i > 32 ? word0(d) << (64 - i) | word1(d) >> (i - 32)
			: word1(d) << (32 - i);
		d2 = x;
		word0(d2) -= 31 * Exp_msk1;	/* adjust exponent */
		i -= (Bias + (P - 1) - 1) + 1;
		denorm = 1;
	}

	ds = (d2 - 1.5) * 0.289529654602168 + 0.1760912590558 + i * 0.301029995663981;
	k = (int)ds;
	if (ds < 0. && ds != k) {
		k--;					/* want k = floor(ds) */
	}

	k_check = 1;

	if (k >= 0 && k <= Ten_pmax) {
		if (d < tens[k]) {
			k--;
		}
		k_check = 0;
	}

	j = bbits - i - 1;
	if (j >= 0) {
		b2 = 0;
		s2 = j;
	} else {
		b2 = -j;
		s2 = 0;
	}

	if (k >= 0) {
		b5 = 0;
		s5 = k;
		s2 += k;
	} else {
		b2 -= k;
		b5 = -k;
		s5 = 0;
	}

	if (mode < 0 || mode > 9) {
		mode = 0;
	}

	try_quick = 1;
	if (mode > 5) {
		mode -= 4;
		try_quick = 0;
	}

	leftright = 1;
	switch (mode) {
	case 0:
	case 1:
		ilim = ilim1 = -1;
		i = 18;
		ndigits = 0;
		break;

	case 2:
		leftright = 0;
	/* no break */
	case 4:
		if (ndigits <= 0) {
			ndigits = 1;
		}

		ilim = ilim1 = i = ndigits;
		break;

	case 3:
		leftright = 0;
	/* no break */
	case 5:
		i = ndigits + k + 1;
		ilim = i;
		ilim1 = i - 1;
		if (i <= 0) {
			i = 1;
		}
	}

	j = sizeof(unsigned long);
	for (result_k = 0; (signed)(sizeof(Bigint) - sizeof(unsigned long) + j) <= i; j <<= 1) {
		result_k++;
	}

	result = Balloc(result_k);
	s = s0 = (char *)result;

	if (ilim >= 0 && ilim <= Quick_max && try_quick) {
		/* Try to get by with floating-point arithmetic. */

		i = 0;
		d2 = d;
		k0 = k;
		ilim0 = ilim;
		ieps = 2;				/* conservative */

		if (k > 0) {
			ds = tens[k & 0xf];
			j = k >> 4;

			if (j & Bletch) {
				/* prevent overflows */
				j &= Bletch - 1;
				d /= bigtens[n_bigtens - 1];
				ieps++;
			}

			for (; j; j >>= 1, i++) {
				if (j & 1) {
					ieps++;
					ds *= bigtens[i];
				}
			}

			d /= ds;
		} else if ((j_1 = -k)) {
			d *= tens[j_1 & 0xf];
			for (j = j_1 >> 4; j; j >>= 1, i++) {
				if (j & 1) {
					ieps++;
					d *= bigtens[i];
				}
			}
		}

		if (k_check && d < 1. && ilim > 0) {
			if (ilim1 <= 0) {
				goto fast_failed;
			}

			ilim = ilim1;
			k--;
			d *= 10.;
			ieps++;
		}

		eps = ieps * d + 7.;
		word0(eps) -= (P - 1) * Exp_msk1;
		if (ilim == 0) {
			S = mhi = 0;
			d -= 5.;
			if (d > eps) {
				goto one_digit;
			}
			if (d < -eps) {
				goto no_digits;
			}
			goto fast_failed;
		}
#ifndef No_leftright
		if (leftright) {
			/* Use Steele & White method of only generating digits needed. */

			eps = 0.5 / tens[ilim - 1] - eps;
			for (i = 0;;) {
				L = (int)d;
				d -= L;
				*s++ = '0' + (int)L;
				if (d < eps) {
					goto ret1;
				}

				if (1. - d < eps) {
					goto bump_up;
				}

				if (++i >= ilim) {
					break;
				}

				eps *= 10.;
				d *= 10.;
			}
		} else {
#endif
			/* Generate ilim digits, then fix them up. */

			eps *= tens[ilim - 1];
			for (i = 1;; i++, d *= 10.) {
				L = (int)d;
				d -= L;
				*s++ = '0' + (int)L;
				if (i == ilim) {
					if (d > 0.5 + eps) {
						goto bump_up;
					} else if (d < 0.5 - eps) {
						while (*--s == '0');
						s++;
						goto ret1;
					}

					break;
				}
			}
#ifndef No_leftright
		}
#endif
fast_failed:
		s = s0;
		d = d2;
		k = k0;
		ilim = ilim0;
	}

	/* Do we have a "small" integer? */

	if (be >= 0 && k <= Int_max) {
		/* Yes. */

		ds = tens[k];
		if (ndigits < 0 && ilim <= 0) {
			S = mhi = 0;
			if (ilim < 0 || d <= 5 * ds) {
				goto no_digits;
			}

			goto one_digit;
		}

		for (i = 1;; i++) {
			L = (int)(d / ds);
			d -= L * ds;
#ifdef Check_FLT_ROUNDS
			/* If FLT_ROUNDS == 2, L will usually be high by 1 */
			if (d < 0) {
				L--;
				d += ds;
			}
#endif
			*s++ = '0' + (int)L;
			if (i == ilim) {
				d += d;
				if (d > ds || (d == ds && (L & 1))) {
bump_up:
					while (*--s == '9')
						if (s == s0) {
							k++;
							*s = '0';
							break;
						}

					++*s++;
				}
				break;
			}

			if (!(d *= 10.)) {
				break;
			}
		}

		goto ret1;
	}

	m2 = b2;
	m5 = b5;
	mhi = mlo = 0;
	if (leftright) {
		if (mode < 2) {
			i = denorm ? be + (Bias + (P - 1) - 1 + 1) : 1 + P - bbits;
		} else {
			j = ilim - 1;
			if (m5 >= j) {
				m5 -= j;
			} else {
				s5 += j -= m5;
				b5 += j;
				m5 = 0;
			}

			if ((i = ilim) < 0) {
				m2 -= i;
				i = 0;
			}
		}

		b2 += i;
		s2 += i;
		mhi = i2b(1);
	}

	if (m2 > 0 && s2 > 0) {
		i = m2 < s2 ? m2 : s2;
		b2 -= i;
		m2 -= i;
		s2 -= i;
	}

	if (b5 > 0) {
		if (leftright) {
			if (m5 > 0) {
				mhi = pow5mult(mhi, m5);
				b1 = mult(mhi, b);
				Bfree(b);
				b = b1;
			}

			if ((j = b5 - m5)) {
				b = pow5mult(b, j);
			}
		} else {
			b = pow5mult(b, b5);
		}
	}

	S = i2b(1);
	if (s5 > 0) {
		S = pow5mult(S, s5);
	}

	/* Check for special case that d is a normalized power of 2. */

	if (mode < 2) {
		if (!word1(d) && !(word0(d) & Bndry_mask) && word0(d) & Exp_mask) {
			/* The special case */
			b2 += Log2P;
			s2 += Log2P;
			spec_case = 1;
		} else {
			spec_case = 0;
		}
	}

	/* Arrange for convenient computation of quotients: shift left if
	 * necessary so divisor has 4 leading 0 bits.
	 *
	 * Perhaps we should just compute leading 28 bits of S once and for all
	 * and pass them and a shift to quorem, so it can do shifts and ors
	 * to compute the numerator for q.
	 */

#ifdef Pack_32
	if ((i = ((s5 ? 32 - hi0bits(S->x[S->wds - 1]) : 1) + s2) & 0x1f)) {
		i = 32 - i;
	}
#else
	if ((i = ((s5 ? 32 - hi0bits(S->x[S->wds - 1]) : 1) + s2) & 0xf)) {
		i = 16 - i;
	}
#endif

	if (i > 4) {
		i -= 4;
		b2 += i;
		m2 += i;
		s2 += i;
	} else if (i < 4) {
		i += 28;
		b2 += i;
		m2 += i;
		s2 += i;
	}

	if (b2 > 0) {
		b = lshift(b, b2);
	}

	if (s2 > 0) {
		S = lshift(S, s2);
	}

	if (k_check) {
		if (cmp(b, S) < 0) {
			k--;
			b = multadd(b, 10, 0);	/* we botched the k estimate */
			if (leftright) {
				mhi = multadd(mhi, 10, 0);
			}

			ilim = ilim1;
		}
	}

	if (ilim <= 0 && mode > 2) {
		if (ilim < 0 || cmp(b, S = multadd(S, 5, 0)) <= 0) {
			/* no digits, fcvt style */

no_digits:
			k = -1 - ndigits;
			goto ret;
		}

one_digit:
		*s++ = '1';
		k++;
		goto ret;
	}

	if (leftright) {
		if (m2 > 0) {
			mhi = lshift(mhi, m2);
		}

		/* Compute mlo -- check for special case that d is a normalized power of
		 * 2. */

		mlo = mhi;
		if (spec_case) {
			mhi = Balloc(mhi->k);
			Bcopy(mhi, mlo);
			mhi = lshift(mhi, Log2P);
		}

		for (i = 1;; i++) {
			dig = quorem(b, S) + '0';
			/* Do we yet have the shortest decimal string that will round to d? */
			j = cmp(b, mlo);
			delta = diff(S, mhi);
			j_1 = delta->sign ? 1 : cmp(b, delta);
			Bfree(delta);
#ifndef ROUND_BIASED
			if (j_1 == 0 && !mode && !(word1(d) & 1)) {
				if (dig == '9') {
					goto round_9_up;
				}

				if (j > 0) {
					dig++;
				}

				*s++ = dig;
				goto ret;
			}
#endif
			if (j < 0 || (j == 0 && !mode
#ifndef ROUND_BIASED
						  && (!(word1(d) & 1))
#endif
						 )) {
				if ((j_1 > 0)) {
					b = lshift(b, 1);
					j_1 = cmp(b, S);
					if ((j_1 > 0 || (j_1 == 0 && (dig & 1))) && dig++ == '9') {
						goto round_9_up;
					}
				}

				*s++ = dig;
				goto ret;
			}

			if (j_1 > 0) {
				if (dig == '9') {
					/* possible if i == 1 */
round_9_up:
					*s++ = '9';
					goto roundoff;
				}

				*s++ = dig + 1;
				goto ret;
			}

			*s++ = dig;
			if (i == ilim) {
				break;
			}

			b = multadd(b, 10, 0);
			if (mlo == mhi) {
				mlo = mhi = multadd(mhi, 10, 0);
			} else {
				mlo = multadd(mlo, 10, 0);
				mhi = multadd(mhi, 10, 0);
			}
		}
	} else {
		for (i = 1;; i++) {
			*s++ = dig = quorem(b, S) + '0';
			if (i >= ilim) {
				break;
			}

			b = multadd(b, 10, 0);
		}
	}

	/* Round off last digit */

	b = lshift(b, 1);
	j = cmp(b, S);
	if (j > 0 || (j == 0 && (dig & 1))) {
roundoff:
		while (*--s == '9')
			if (s == s0) {
				k++;
				*s++ = '1';
				goto ret;
			}

		++*s++;
	} else {
		while (*--s == '0') ;
		s++;
	}

ret:
	Bfree(S);
	if (mhi) {
		if (mlo && mlo != mhi) {
			Bfree(mlo);
		}

		Bfree(mhi);
	}
ret1:
	Bfree(b);
	if (s == s0) {
		/* Don't return empty string */
		*s++ = '0';
		k = 0;
	}

	*s = 0;
	*decpt = k + 1;
	if (rve) {
		*rve = s;
	}

	return s0;
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
 * libc/stdio/lib_fclose.c
 *
 *   Copyright (C) 2007-2009, 2011, 3013 Gregory Nutt. All rights reserved.
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
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fclose
 *
 * Description
 *   The fclose() function will flush the stream pointed to by stream
 *   (writing any buffered output data using lib_fflush()) and close the
 *   underlying file descriptor.
 *
 * Returned Value:
 *   Upon successful completion 0 is returned. Otherwise, EOF is returned
 *   and the global variable errno is set to indicate the error. In either
 *   case any further access (including another call to fclose()) to the
 *   stream results in undefined behaviour.
 *
 ****************************************************************************/

int fclose(FAR FILE *stream)
{
	int err = EINVAL;
	int ret = ERROR;
	int status;

	/* Verify that a stream was provided. */

	if (stream) {
		/* Check that the underlying file descriptor corresponds to an an open
		 * file.
		 */

		ret = OK;
		if (stream->fs_fd >= 0) {
			/* If the stream was opened for writing, then flush the stream */

			if ((stream->fs_oflags & O_WROK) != 0) {
				ret = lib_fflush(stream, true);
				err = errno;
			}

			/* Close the underlying file descriptor and save the return status */

			status = close(stream->fs_fd);

			/* If close() returns an error but flush() did not then make sure
			 * that we return the close() error condition.
			 * Also If flush returns error but storage is full, we return close status.
			 */

			if (ret == OK || ret == -ENOSPC) {
				ret = status;
				err = errno;
			}
		}
#if CONFIG_STDIO_BUFFER_SIZE > 0
		/* Destroy the semaphore */

		sem_destroy(&stream->fs_sem);

		/* Release the buffer */

		if (stream->fs_bufstart != NULL && (stream->fs_flags & __FS_FLAG_UBF) == 0) {
			lib_free(stream->fs_bufstart);
		}

		/* Clear the whole structure */

		memset(stream, 0, sizeof(FILE));
#else
#if CONFIG_NUNGET_CHARS > 0
		/* Reset the number of ungetc characters */

		stream->fs_nungotten = 0;
#endif
		/* Reset the flags */

		stream->fs_oflags = 0;
#endif
		/* Setting the file descriptor to -1 makes the stream available for reuse */

		stream->fs_fd = -1;
	}

	/* On an error, reset the errno to the first error encountered and return
	 * EOF.
	 */

	if (ret != OK) {
		set_errno(err);
		return EOF;
	}

	/* Return success */

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
 * libc/stdio/lib_feof.c
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

#include <stdio.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#if CONFIG_NFILE_STREAMS > 0

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: feof
 *
 * Description:
 *   The feof() function shall test if the currently file pointer for the
 *   stream is at the end of file.
 *
 * Returned Value:
 *  This function will return non-zero if the file pointer is positioned
 *  at the end of file.
 *
 ****************************************************************************/

int feof(FILE *stream)
{
	/* If the end-of-file condition is encountered by any of the C-buffered
	 * I/O functions that perform read operations, they should set the
	 * __FS_FLAG_EOF in the fs_flags field of struct file_struct.
	 */

	return (stream->fs_flags & __FS_FLAG_EOF) != 0;
}

#endif							/* CONFIG_NFILE_STREAMS */
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
 * libc/stdio/lib_ferror.c
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

#include <stdio.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#if CONFIG_NFILE_STREAMS > 0

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: ferror
 *
 * Description:
 *   This function will test if the last operation resulted in an eror.  This
 *   is used to disambiguate EOF and error conditions.
 *
 * Return Value:
 *   A non-zero value is returned to indicate the error condition.
 *
 ****************************************************************************/

int ferror(FILE *stream)
{
	/* If an error is encountered by any of the C-buffered I/O functions, they
	 * should set the __FS_FLAG_ERROR in the fs_flags field of struct
	 * file_struct.
	 */

	return (stream->fs_flags & __FS_FLAG_ERROR) != 0;
}

#endif							/* CONFIG_NFILE_STREAMS */
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
 * libc/stdio/lib_fflush.c
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

#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fflush
 *
 * Description:
 *  The function fflush() forces a write of all user-space buffered data for
 *  the given output or update stream via the stream's underlying write
 *  function.  The open status of the stream is unaffected.
 *
 *  If the stream argument is NULL, fflush() flushes all open output streams.
 *
 * Return:
 *  OK on success EOF on failure (with errno set appropriately)
 *
 ****************************************************************************/

int fflush(FAR FILE *stream)
{
	int ret;

	/* Is the stream argument NULL? */

	if (!stream) {
		/* Yes... then this is a request to flush all streams */

		ret = lib_flushall(sched_getstreams());
	} else {
		ret = lib_fflush(stream, true);
	}

	/* Check the return value */

	if (ret < 0) {
		/* An error occurred during the flush AND/OR we were unable to flush
		 * all of the buffered write data. Set the errno value.
		 */

		set_errno(-ret);

		/* And return EOF on failure. */

		return EOF;
	}

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
 * libc/stdio/lib_fgetc.c
 *
 *   Copyright (C) 2007, 2008, 2011 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>
#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Function Prototypes
 ****************************************************************************/

/**************************************************************************
 * Global Constant Data
 **************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/**************************************************************************
 * Private Constant Data
 **************************************************************************/

/****************************************************************************
 * Private Variables
 **************************************************************************/

/****************************************************************************
 * Global Functions
 **************************************************************************/

/****************************************************************************
 * fgetc
 **************************************************************************/

int fgetc(FAR FILE *stream)
{
	unsigned char ch;
	ssize_t ret;

	ret = lib_fread(&ch, 1, stream);
	if (ret > 0) {
		return ch;
	} else {
		return EOF;
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
 * libc/stdio/lib_fgetpos.c
 *
 *   Copyright (C) 2008-2009, 2011 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdio.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
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
 * Name: fgetpos
 *
 * Description:
 *   fgetpos() function is an alternate interfaces equivalent to ftell().
 *   It gets the current value of the file offset and store it in the location
 *   referenced by pos.  On some non-UNIX systems an fpos_t object may be a
 *   complex object and fsetpos may be the only way to portably reposition a
 *   stream.
 *
 * Returned Value:
 *   Zero on succes; -1 on failure with errno set appropriately.
 *
 ****************************************************************************/

int fgetpos(FAR FILE *stream, FAR fpos_t *pos)
{
	long position;

#ifdef CONFIG_DEBUG
	if (!stream || !pos) {
		set_errno(EINVAL);
		return ERROR;
	}
#endif

	position = ftell(stream);
	if (position == -1) {
		return ERROR;
	}

	*pos = (fpos_t)position;
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
 * libc/stdio/lib_fgets.c
 *
 *   Copyright (C) 2007-2008, 2011-2014 Gregory Nutt. All rights reserved.
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

#include "lib_internal.h"

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
 * Name: fgets
 *
 * Description:
 *   fgets() reads in at most one less than 'buflen' characters from stream
 *   and stores them into the buffer pointed to by 'buf'. Reading stops after
 *   an EOF or a newline.  If a newline is read, it is stored into the
 *   buffer.  A null terminator is stored after the last character in the
 *   buffer.
 *
 **************************************************************************/

char *fgets(FAR char *buf, int buflen, FILE *stream)
{
	/* Handle negative buffer size */

	if (buflen < 0) {
		return NULL;
	}

	/* Let lib_fgets() do the heavy lifting */

	else {
		return lib_fgets(buf, (size_t)buflen, stream, true, false);
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
 * libc/stdio/lib_fileno.c
 *
 *   Copyright (C) 2009, 2011, 2013 Gregory Nutt. All rights reserved.
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

#if CONFIG_NFILE_STREAMS > 0

/****************************************************************************
 * Global Functions
 ****************************************************************************/

int fileno(FAR FILE *stream)
{
	int ret = -1;
	if (stream) {
		ret = stream->fs_fd;
	}

	if (ret < 0) {
		set_errno(EBADF);
		return ERROR;
	}

	return ret;
}
#endif							/* CONFIG_NFILE_STREAMS */
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
 * libc/stdio/lib_fopen.c
 *
 *   Copyright (C) 2007-2012 Gregory Nutt. All rights reserved.
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
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Open mode flags */

#define MODE_R    (1 << 0)		/* Bit 0: "r{b|x|+}" open for reading */
#define MODE_W    (1 << 1)		/* Bit 1: "w{b|x|+}" open for writing, truncating,
								 * or creating file */
#define MODE_A    (1 << 2)		/* Bit 2: "a{b|x|+}" open for writing, appending
								 * the to file */
#define MODE_PLUS (1 << 3)		/* Bit 3: "{r|w|a|b|x}+" open for update (reading
								 * and writing) */
#define MODE_B    (1 << 4)		/* Bit 4: "{r|w|a|x|+}b" Binary mode */
#define MODE_X    (1 << 5)		/* Bit 5: "{r|w|a|b|+}x" Open exclusive mode */

#define MODE_NONE 0				/* No access mode determined */
#define MODE_MASK (MODE_R | MODE_W | MODE_A)

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_mode2oflags
 ****************************************************************************/

int lib_mode2oflags(FAR const char *mode)
{
	unsigned int state;
	int oflags;

	/* Verify that a mode string was provided.  */

	DEBUGASSERT(mode);

	if (!mode || !*mode) {
		goto errout;
	}

	/* Parse the mode string to determine the corresponding open flags */

	state = MODE_NONE;
	oflags = 0;

	for (; *mode; mode++) {
		switch (*mode) {
		/* Open for read access ("r{b|x|+}") */

		case 'r':
			if (state == MODE_NONE) {
				/* Open for read access */

				oflags = O_RDOK;
				state = MODE_R;
			} else {
				goto errout;
			}
			break;

		/* Open for write access ("w{b|x|+}") */

		case 'w':
			if (state == MODE_NONE) {
				/* Open for write access, truncating any existing file */

				oflags = (O_WROK | O_CREAT | O_TRUNC);
				state = MODE_W;
			} else {
				goto errout;
			}
			break;

		/* Open for write/append access ("a{b|x|+}") */

		case 'a':
			if (state == MODE_NONE) {
				/* Write to the end of the file */

				oflags = O_WROK | O_CREAT | O_APPEND;
				state = MODE_A;
			} else {
				goto errout;
			}
			break;

		/* Open for update access ("{r|w|a|b|x}+") */

		case '+':
			switch (state & MODE_MASK) {
			case MODE_R: {
				/* Retain any binary and exclusive mode selections */

				oflags &= (O_BINARY | O_EXCL);

				/* Open for read/write access */

				oflags |= O_RDWR;
				state |= MODE_PLUS;
			}
			break;

			case MODE_W: {
				/* Retain any binary and exclusive mode selections */

				oflags &= (O_BINARY | O_EXCL);

				/* Open for write read/access, truncating any existing file */

				oflags |= (O_RDWR | O_CREAT | O_TRUNC);
				state |= MODE_PLUS;
			}
			break;

			case MODE_A: {
				/* Retain any binary and exclusive mode selections */

				oflags &= (O_BINARY | O_EXCL);

				/* Read from the beginning of the file; write to the end */

				oflags |= (O_RDWR | O_CREAT | O_APPEND);
				state |= MODE_PLUS;
			}
			break;

			default:
				goto errout;
				break;
			}
			break;

		/* Open for binary access ("{r|w|a|x|+}b") */

		case 'b':
			if ((state & MODE_MASK) != MODE_NONE) {
				/* The file is opened in binary mode */

				oflags |= O_BINARY;
				state |= MODE_B;
			} else {
				goto errout;
			}
			break;

		/* Open for exclusive access ("{r|w|a|b|+}x") */

		case 'x':
			if ((state & MODE_MASK) != MODE_NONE) {
				/* The file is opened in exclusive mode */

				oflags |= O_EXCL;
				state |= MODE_X;
			} else {
				goto errout;
			}
			break;

		/* Unrecognized or unsupported mode */

		default:
			goto errout;
			break;
		}
	}

	return oflags;

	/* Both fopen and fdopen should fail with errno == EINVAL if the mode
	 * string is invalid.
	 */

errout:
	set_errno(EINVAL);
	return ERROR;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fdopen
 ****************************************************************************/

FAR FILE *fdopen(int fd, FAR const char *mode)
{
	FAR FILE *ret = NULL;
	int oflags;

	/* Map the open mode string to open flags */

	oflags = lib_mode2oflags(mode);
	if (oflags >= 0) {
		ret = fs_fdopen(fd, oflags, NULL);
	}

	return ret;
}

/****************************************************************************
 * Name: fopen
 ****************************************************************************/

FAR FILE *fopen(FAR const char *path, FAR const char *mode)
{
	FAR FILE *ret = NULL;
	int oflags;
	int fd;

	/* Map the open mode string to open flags */

	oflags = lib_mode2oflags(mode);
	if (oflags < 0) {
		return NULL;
	}

	/* Open the file */

	fd = open(path, oflags, 0666);

	/* If the open was successful, then fdopen() the fil using the file
	 * desciptor returned by open.  If open failed, then just return the
	 * NULL stream -- open() has already set the errno.
	 */

	if (fd >= 0) {
		ret = fs_fdopen(fd, oflags, NULL);
		if (!ret) {
			/* Don't forget to close the file descriptor if any other
			 * failures are reported by fdopen().
			 */

			(void)close(fd);
		}
	}
	return ret;
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
 * libc/stdio/lib_fprintf.c
 *
 *   Copyright (C) 2007, 2011-2012 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fprintf
 ****************************************************************************/

int fprintf(FAR FILE *stream, FAR const char *fmt, ...)
{
	va_list ap;
	int n;

	/* vfprintf into the stream */

	va_start(ap, fmt);
	n = vfprintf(stream, fmt, ap);
	va_end(ap);
	return n;
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
 * libc/stdio/lib_fputc.c
 *
 *   Copyright (C) 2007, 2008, 2011-2012 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>
#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fputc
 ****************************************************************************/

int fputc(int c, FAR FILE *stream)
{
	unsigned char buf = (unsigned char)c;
	int ret;

	ret = lib_fwrite(&buf, 1, stream);
	if (ret > 0) {
		/* Flush the buffer if a newline is output */

#ifdef CONFIG_STDIO_LINEBUFFER
		if (c == '\n') {
			ret = lib_fflush(stream, true);
			if (ret < 0) {
				return EOF;
			}
		}
#endif
		return c;
	} else {
		return EOF;
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
 * libc/stdio/lib_fputs.c
 *
 *   Copyright (C) 2007, 2008, 2011-2012 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <tinyara/arch.h>

#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fputs
 *
 * Description:
 *   fputs() writes the string s to stream, without its trailing '\0'.
 *
 ****************************************************************************/

#if defined(CONFIG_ARCH_ROMGETC)
int fputs(FAR const char *s, FAR FILE *stream)
{
	int nput;
	int ret;
	char ch;

	/* Make sure that a string was provided. */

#ifdef CONFIG_DEBUG				/* Most parameter checking is disabled if DEBUG is off */
	if (!s) {
		set_errno(EINVAL);
		return EOF;
	}
#endif

	/* Write the string.  Loop until the null terminator is encountered */

	for (nput = 0, ch = up_romgetc(s); ch; nput++, s++, ch = up_romgetc(s)) {
		/* Write the next character to the stream buffer */

		ret = lib_fwrite(&ch, 1, stream);
		if (ret <= 0) {
			return EOF;
		}

		/* Flush the buffer if a newline was written to the buffer */

#ifdef CONFIG_STDIO_LINEBUFFER
		if (ch == '\n') {
			ret = lib_fflush(stream, true);
			if (ret < 0) {
				return EOF;
			}
		}
#endif
	}

	return nput;
}

#elif defined(CONFIG_STDIO_LINEBUFFER)
int fputs(FAR const char *s, FAR FILE *stream)
{
	int nput;
	int ret;

	/* Make sure that a string was provided. */

#ifdef CONFIG_DEBUG				/* Most parameter checking is disabled if DEBUG is off */
	if (!s) {
		set_errno(EINVAL);
		return EOF;
	}
#endif

	/* Write the string.  Loop until the null terminator is encountered */

	for (nput = 0; *s; nput++, s++) {
		/* Write the next character to the stream buffer */

		ret = lib_fwrite(s, 1, stream);
		if (ret <= 0) {
			return EOF;
		}

		/* Flush the buffer if a newline was written to the buffer */

		if (*s == '\n') {
			ret = lib_fflush(stream, true);
			if (ret < 0) {
				return EOF;
			}
		}
	}

	return nput;
}

#else
int fputs(FAR const char *s, FAR FILE *stream)
{
	int ntowrite;
	int nput;

	/* Make sure that a string was provided. */

#ifdef CONFIG_DEBUG				/* Most parameter checking is disabled if DEBUG is off */
	if (!s) {
		set_errno(EINVAL);
		return EOF;
	}
#endif

	/* Get the length of the string. */

	ntowrite = strlen(s);
	if (ntowrite == 0) {
		return 0;
	}

	/* Write the string */

	nput = lib_fwrite(s, ntowrite, stream);
	if (nput < 0) {
		return EOF;
	}
	return nput;
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
 * libc/stdio/lib_fread.c
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
#include <stdio.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fread
 ****************************************************************************/

size_t fread(FAR void *ptr, size_t size, size_t n_items, FAR FILE *stream)
{
	size_t full_size = n_items * (size_t)size;
	ssize_t bytes_read;
	size_t items_read = 0;

	/* Write the data into the stream buffer */

	bytes_read = lib_fread(ptr, full_size, stream);
	if (bytes_read > 0) {
		/* Return the number of full items read */

		items_read = bytes_read / size;
	}

	return items_read;
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
 * libc/stdio/lib_freopen.c
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
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

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: freopen
 *
 * Description:
 *   Reuses stream to either open the file specified by path or to change
 *   its access mode.
 *
 *   If a new path is specified, the function first attempts to close
 *   any file already associated with stream (third parameter) and
 *   disassociates it. Then, independently of whether that stream was
 *   successfuly closed or not, freopen opens the file specified by path
 *   and associates it with the stream just as fopen would do using the
 *   specified mode.
 *
 *   If path is a null pointer, the function attempts to change the mode
 *   of the stream. Although a particular library implementation is allowed
 *   to restrict the changes permitted, and under which circumstances.
 *
 *   The error indicator and eof indicator are automatically cleared (as if
 *   clearerr was called).
 *
 * Input Paramters:
 *   path   - If non-NULL, refers to the name of the file to be opened.
 *   mode   - String describing the new file access mode
 *   stream - Pointer to the type FILE to be reopened.
 *
 * Returned Value:
 *   If the file is successfully reopened, the function returns the pointer
 *   passed as parameter stream, which can be used to identify the reopened
 *   stream.   Otherwise, a null pointer is returned and the errno variable
 *   is also set to a system-specific error code on failure.
 *
 ****************************************************************************/

FAR FILE *freopen(FAR const char *path, FAR const char *mode, FAR FILE *stream)
{
	int oflags;
	int ret;
	int fd;

	/* Was a file name provided? */

	if (path != NULL) {
		/* Yes, close the stream */

		if (stream) {
			(void)fclose(stream);
		}

		/* And attempt to reopen the file at the provided path */

		return fopen(path, mode);
	}

	/* Otherwise, we are just changing the mode of the current file. */

	if (stream) {
		/* Convert the mode string into standard file open mode flags. */

		oflags = lib_mode2oflags(mode);
		if (oflags < 0) {
			return NULL;
		}

		/* Get the underlying file descriptor from the stream */

		fd = fileno(stream);
		if (fd < 0) {
			return NULL;
		}

		/* Set the new file mode for the file descriptor */

		ret = fcntl(fd, F_SETFL, oflags);
		if (ret < 0) {
			return NULL;
		}

		clearerr(stream);
		return stream;
	}

	set_errno(EINVAL);
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
 * libc/stdio/lib_fseek.c
 *
 *   Copyright (C) 2007, 2008, 2011, 2013 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
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
 * Name: fseek
 *
 * Description:
 *   The fseek() function sets the file position indicator for the stream
 *   pointed to by stream. The new position, measured in bytes, is obtained
 *   by adding offset bytes to the position specified by whence. If whence is
 *   set to SEEK_SET, SEEK_CUR, or SEEK_END, the offset is relative to the
 *   start of the file, the current position indicator, or end-of-file,
 *   respectively. A successful call to the fseek() function clears the
 *   end-of-file indicator for the stream and undoes any effects of the ungetc(3)
 *   function on the same stream.
 *
 * Returned Value:
 *   Zero on succes; -1 on failure with errno set appropriately.
 *
 ****************************************************************************/

int fseek(FAR FILE *stream, long int offset, int whence)
{
#if CONFIG_STDIO_BUFFER_SIZE > 0
	/* Flush any valid read/write data in the buffer (also verifies stream) */

	if (lib_rdflush(stream) < 0 || lib_wrflush(stream) < 0) {
		return ERROR;
	}
#else
	/* Verify that we were provided with a stream */

	if (!stream) {
		set_errno(EBADF);
		return ERROR;
	}
#endif

	/* On success or failure, discard any characters saved by ungetc() */

#if CONFIG_NUNGET_CHARS > 0
	stream->fs_nungotten = 0;
#endif

	/* Perform the fseek on the underlying file descriptor */

	return lseek(stream->fs_fd, offset, whence) == (off_t)-1 ? ERROR : OK;
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
 * libc/stdio/lib_fsetpos.c
 *
 *   Copyright (C) 2008, 2011 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
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
 * Name: fsetpos
 *
 * Description:
 *   fsetpos() function is an alternate interfaces equivalent to fseek()
 *   (with whence set to  SEEK_SET).  It sets the current value of the file
 *   offset to value in the location referenced by pos.  On some non-UNIX
 *   systems an fpos_t object may be a complex object and fsetpos may be the
 *   only way to portably reposition a stream.
 *
 * Returned Value:
 *   Zero on succes; -1 on failure with errno set appropriately.
 *
 ****************************************************************************/

int fsetpos(FAR FILE *stream, FAR fpos_t *pos)
{
#ifdef CONFIG_DEBUG
	if (!stream || !pos) {
		set_errno(EINVAL);
		return ERROR;
	}
#endif

	return fseek(stream, (FAR off_t)*pos, SEEK_SET);
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
 * libc/stdio/lib_ftell.c
 *
 *   Copyright (C) 2008, 2011, 2013 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_getrdoffset
 *
 * Description:
 *   It is insufficient to simply use the file offset; we must also account
 *   for the data offset in the any buffered data.  This function calculates
 *   that offset.
 *
 * Returned Value:
 *   The file position offset due to buffered data.
 *
 ****************************************************************************/

#if CONFIG_STDIO_BUFFER_SIZE > 0
static off_t lib_getrdoffset(FAR FILE *stream)
{
	off_t rdoffset = 0;
	lib_take_semaphore(stream);

	if (stream->fs_bufread != stream->fs_bufstart) {
#if CONFIG_NUNGET_CHARS > 0
		rdoffset = stream->fs_bufread - stream->fs_bufpos + stream->fs_nungotten;
#else
		rdoffset = stream->fs_bufread - stream->fs_bufpos;
#endif
	}

	lib_give_semaphore(stream);
	return rdoffset;
}
#else
#define lib_getrdoffset(stream) (0)
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: ftell
 *
 * Description:
 *   ftell() returns the current value of the file position indicator for the
 *   stream pointed to by stream.
 *
 * Returned Value:
 *   Zero on success; -1 on failure with errno set appropriately.
 *
 ****************************************************************************/

long ftell(FAR FILE *stream)
{
	off_t position;

	/* Verify that we were provided with a stream */

	if (!stream) {
		set_errno(EBADF);
		return ERROR;
	}

	/* Perform the lseek to the current position.  This will not move the
	 * file pointer, but will return its current setting
	 */

	position = lseek(stream->fs_fd, 0, SEEK_CUR);
	if (position != (off_t)-1) {
		return (long)(position - lib_getrdoffset(stream));
	} else {
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
 * libc/stdio/lib_fwrite.c
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
#include <stdio.h>

#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: fwrite
 ****************************************************************************/

size_t fwrite(FAR const void *ptr, size_t size, size_t n_items, FAR FILE *stream)
{
	size_t full_size = n_items * (size_t)size;
	ssize_t bytes_written;
	size_t items_written = 0;

	/* Write the data into the stream buffer */

	bytes_written = lib_fwrite(ptr, full_size, stream);
	if (bytes_written > 0) {
		/* Return the number of full items written */

		items_written = bytes_written / size;
	}
	return items_written;
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
 * libc/stdio/lib_gets.c
 *
 *   Copyright (C) 2007-2008, 2011-2012 Gregory Nutt. All rights reserved.
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
#include <stdio.h>

#include "lib_internal.h"

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
 * Name: gets
 *
 * Description:
 *   gets() reads a line from stdin into the buffer pointed to by s until
 *   either a terminating newline or EOF, which it replaces with '\0'.  No
 *   check for buffer overrun is performed
 *
 *   This API should not be used because it is inherently unsafe.  Consider
 *   using fgets which is safer and slightly more efficient.
 *
 **************************************************************************/

FAR char *gets(FAR char *s)
{
	/* Let lib_fgets() do the heavy lifting */

	return lib_fgets(s, (size_t)INT_MAX, stdin, false, false);
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
 * libc/stdio/lib_gets_s.c
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

#include <stdio.h>
#include <stdint.h>

#include "lib_internal.h"

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
 * Name: gets
 *
 * Description:
 *   gets() reads a line from stdin into the buffer pointed to by s until
 *   either a terminating newline or EOF, which it replaces with '\0'.  Reads
 *   at most n-1 characters from stdin into the array pointed to by str until
 *   new-line character, end-of-file condition, or read error.   The newline
 *   character, if encountered, is not saved in the arraay.  A NUL character
 *   is written immediately after the last character read into the array, or
 *   to str[0] if no characters were read.
 *
 *   If n is zero or is greater than RSIZE_MAX, a null character is written
 *   to str[0] but the function reads and discards characters from stdin
 *   until new-line character, end-of-file condition, or read error (not
 *   implemented).
 *
 *   If n-1 characters have been read, continues reading and discarding the
 *   characters from stdin until new-line character, end-of-file condition,
 *   or read error.
 *
 **************************************************************************/

FAR char *gets_s(FAR char *s, rsize_t n)
{
	/* Handle the case where n is out of range as required */

	if (n < 1 || n > RSIZE_MAX) {
		/* Set n=1, i.e., room only for the NUL terminator */

		n = 1;
	}

	/* Then let lib_fgets() do the heavy lifting */

	return lib_fgets(s, (size_t)n, stdin, false, true);
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
 * libc/unistd/lib_libdtoa.c
 *
 * This file was ported to NuttX by Yolande Cates.
 *
 * Copyright (c) 1990, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
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

#include <math.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define MAX_PREC 16

#ifndef MIN
#define MIN(a, b) (a < b ? a : b)
#endif

#ifndef MAX
#define MAX(a, b) (a > b ? a : b)
#endif

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: zeroes
 *
 * Description:
 *   Print the specified number of zeres
 *
 ****************************************************************************/

static void zeroes(FAR struct lib_outstream_s *obj, int nzeroes)
{
	int i;

	for (i = nzeroes; i > 0; i--) {
		obj->put(obj, '0');
	}
}

/****************************************************************************
 * Name: lib_dtoa_string
 *
 * Description:
 *   Print the specified string
 *
 ****************************************************************************/

static void lib_dtoa_string(FAR struct lib_outstream_s *obj, const char *str)
{
	while (*str) {
		obj->put(obj, *str++);
	}
}

/****************************************************************************
 * Name: lib_dtoa
 *
 * Description:
 *   This is part of lib_vsprintf().  It handles the floating point formats.
 *   This version supports only the %f (with precision).  If no precision
 *   was provided in the format, this will use precision == 0 which is
 *   probably not what you want.
 *
 * Input Parameters:
 *   obj   - The output stream object
 *   fmt   - The format character.  Not used 'f' is always assumed
 *   prec  - The number of digits to the right of the decimal point. If no
 *           precision is provided in the format, this will be zero.  And,
 *           unfortunately in this case, it will be treated literally as
 *           a precision of zero.
 *   flags - Only ALTFORM and SHOWPLUS flags are supported.  ALTFORM only
 *           applies if prec == 0 which is not supported anyway.
 *   value - The floating point value to convert.
 *
 ****************************************************************************/

static void lib_dtoa(FAR struct lib_outstream_s *obj, int fmt, int prec, uint8_t flags, double value)
{
	FAR char *digits;			/* String returned by __dtoa */
	FAR char *rve;				/* Points to the end of the return value */
	int expt;					/* Integer value of exponent */
	int numlen;					/* Actual number of digits returned by cvt */
	int nchars;					/* Number of characters to print */
	int dsgn;					/* Unused sign indicator */
	int i;

	/* Special handling for NaN and Infinity */

	if (isnan(value)) {
		lib_dtoa_string(obj, "NaN");
		return;
	}

	if (isinf(value)) {
		if (value < 0.0) {
			obj->put(obj, '-');
		}

		lib_dtoa_string(obj, "Infinity");
		return;
	}

	/* Non-zero... positive or negative */

	if (value < 0) {
		value = -value;
		SET_NEGATE(flags);
	}

	/* Perform the conversion */

	digits = __dtoa(value, 3, prec, &expt, &dsgn, &rve);
	numlen = rve - digits;

	/* Avoid precision error from missing trailing zeroes */

	numlen = MAX(expt, numlen);

	if (IS_NEGATE(flags)) {
		obj->put(obj, '-');
	} else if (IS_SHOWPLUS(flags)) {
		obj->put(obj, '+');
	}

	/* Special case exact zero or the case where the number is smaller than
	 * the print precision.
	 */

	if (value == 0 || expt < -prec) {
		/* kludge for __dtoa irregularity */

		obj->put(obj, '0');

		/* A decimal point is printed only in the alternate form or if a
		 * particular precision is requested.
		 */

		if (prec > 0 || IS_ALTFORM(flags)) {
			obj->put(obj, '.');

			/* Always print at least one digit to the right of the decimal point. */

			prec = MAX(1, prec);
		}
	}

	/* A non-zero value will be printed */

	else {

		/* Handle the case where the value is less than 1.0 (in magnitude) and
		 * will need a leading zero.
		 */

		if (expt <= 0) {
			/* Print a single zero to the left of the decimal point */

			obj->put(obj, '0');

			/* Print the decimal point */

			obj->put(obj, '.');

			/* Print any leading zeros to the right of the decimal point */

			if (expt < 0) {
				nchars = MIN(-expt, prec);
				zeroes(obj, nchars);
				prec -= nchars;
			}
		}

		/* Handle the general case where the value is greater than 1.0 (in
		 * magnitude).
		 */

		else {
			/* Print the integer part to the left of the decimal point */

			for (i = expt; i > 0; i--) {
				if (*digits != '\0') {
					obj->put(obj, *digits);
					digits++;
				} else {
					obj->put(obj, '0');
				}
			}

			/* Get the length of the fractional part */

			numlen -= expt;

			/* If there is no fractional part, then a decimal point is printed
			 * only in the alternate form or if a particular precision is
			 * requested.
			 */

			if (numlen > 0 || prec > 0 || IS_ALTFORM(flags)) {
				/* Print the decimal point */

				obj->put(obj, '.');

				/* Always print at least one digit to the right of the decimal
				 * point.
				 */

				prec = MAX(1, prec);
			}
		}

		/* If a precision was specified, then limit the number digits to the
		 * right of the decimal point.
		 */

		if (prec > 0) {
			nchars = MIN(numlen, prec);
		} else {
			nchars = numlen;
		}

		/* Print the fractional part to the right of the decimal point */

		for (i = nchars; i > 0; i--) {
			obj->put(obj, *digits);
			digits++;
		}

		/* Decrement to get the number of trailing zeroes to print */

		prec -= nchars;
	}

	/* Finally, print any trailing zeroes */

	zeroes(obj, prec);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/
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
 * libc/stdio/lib_libfflush.c
 *
 *   Copyright (C) 2007-2008, 2011-2014 Gregory Nutt. All rights reserved.
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
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_fflush
 *
 * Description:
 *  The function lib_fflush() forces a write of all user-space buffered data for
 *  the given output or update stream via the stream's underlying write
 *  function.  The open status of the stream is unaffected.
 *
 * Parmeters:
 *  stream - the stream to flush
 *  bforce - flush must be complete.
 *
 * Return:
 *  A negated errno value on failure, otherwise the number of bytes remaining
 *  in the buffer.
 *
 ****************************************************************************/

ssize_t lib_fflush(FAR FILE *stream, bool bforce)
{
#if CONFIG_STDIO_BUFFER_SIZE > 0
	FAR const unsigned char *src;
	ssize_t bytes_written;
	ssize_t nbuffer;

	/* Return EBADF if the file is not opened for writing */

	if (stream->fs_fd < 0 || (stream->fs_oflags & O_WROK) == 0) {
		return -EBADF;
	}

	/* Make sure that we have exclusive access to the stream */

	lib_take_semaphore(stream);

	/* Make sure that the buffer holds valid data */

	if (stream->fs_bufpos != stream->fs_bufstart) {
		/* Make sure that the buffer holds buffered write data.  We do not
		 * support concurrent read/write buffer usage.
		 */

		if (stream->fs_bufread != stream->fs_bufstart) {
			/* The buffer holds read data... just return zero meaning "no bytes
			 * remaining in the buffer."
			 */

			lib_give_semaphore(stream);
			return 0;
		}

		/* How many bytes of write data are used in the buffer now */

		nbuffer = stream->fs_bufpos - stream->fs_bufstart;

		/* Try to write that amount */

		src = stream->fs_bufstart;
		do {
			/* Perform the write */

			bytes_written = write(stream->fs_fd, src, nbuffer);
			if (bytes_written < 0) {
				/* Write failed.  The cause of the failure is in 'errno'.
				 * returned the negated errno value.
				 */

				stream->fs_flags |= __FS_FLAG_ERROR;
				lib_give_semaphore(stream);
				return -get_errno();
			}

			/* Handle partial writes.  fflush() must either return with
			 * an error condition or with the data successfully flushed
			 * from the buffer.
			 */

			src += bytes_written;
			nbuffer -= bytes_written;
		} while (bforce && nbuffer > 0);

		/* Reset the buffer position to the beginning of the buffer */

		stream->fs_bufpos = stream->fs_bufstart;

		/* For the case of an incomplete write, nbuffer will be non-zero
		 * It will hold the number of bytes that were not written.
		 * Move the data down in the buffer to handle this (rare) case
		 */

		while (nbuffer) {
			*stream->fs_bufpos++ = *src++;
			--nbuffer;
		}
	}

	/* Restore normal access to the stream and return the number of bytes
	 * remaining in the buffer.
	 */

	lib_give_semaphore(stream);
	return stream->fs_bufpos - stream->fs_bufstart;
#else
	/* Return no bytes remaining in the buffer */

	return 0;
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
/****************************************************************************
 * libc/stdio/lib_libfgets.c
 *
 *   Copyright (C) 2007-2008, 2011-2014 Gregory Nutt. All rights reserved.
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
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <debug.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Some environments may return CR as end-of-line, others LF, and others
 * both.  If not specified, the logic here assumes either (but not both) as
 * the default.
 */

#if defined(CONFIG_EOL_IS_CR)
#undef  CONFIG_EOL_IS_LF
#undef  CONFIG_EOL_IS_BOTH_CRLF
#undef  CONFIG_EOL_IS_EITHER_CRLF
#elif defined(CONFIG_EOL_IS_LF)
#undef  CONFIG_EOL_IS_CR
#undef  CONFIG_EOL_IS_BOTH_CRLF
#undef  CONFIG_EOL_IS_EITHER_CRLF
#elif defined(CONFIG_EOL_IS_BOTH_CRLF)
#undef  CONFIG_EOL_IS_CR
#undef  CONFIG_EOL_IS_LF
#undef  CONFIG_EOL_IS_EITHER_CRLF
#elif defined(CONFIG_EOL_IS_EITHER_CRLF)
#undef  CONFIG_EOL_IS_CR
#undef  CONFIG_EOL_IS_LF
#undef  CONFIG_EOL_IS_BOTH_CRLF
#else
#undef  CONFIG_EOL_IS_CR
#undef  CONFIG_EOL_IS_LF
#undef  CONFIG_EOL_IS_BOTH_CRLF
#define CONFIG_EOL_IS_EITHER_CRLF 1
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: consume_eol
 *
 * Description:
 *   If 'consume' is true, then consume_eol() will read and discard bytes from
 *   'stream' until an EOF or a newline encountered or until a read error
 *   occurs.
 *
 **************************************************************************/

static void consume_eol(FILE *stream, bool consume)
{
	if (consume) {
		int ch;

		do {
			ch = fgetc(stream);
		}
#if  defined(CONFIG_EOL_IS_LF) || defined(CONFIG_EOL_IS_BOTH_CRLF)
		while (ch != EOF && ch != '\n');
#elif defined(CONFIG_EOL_IS_CR)
		while (ch != EOF && ch != '\r');
#else							/* elif defined(CONFIG_EOL_IS_EITHER_CRLF) */
		while (ch != EOF && ch != '\n' && ch != '\r');
#endif
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_fgets
 *
 * Description:
 *   lib_fgets() implements the core logic for both fgets() and gets_s().
 *   lib_fgets() reads in at most one less than 'buflen' characters from
 *   stream and stores them into the buffer pointed to by 'buf'. Reading
 *   stops after an EOF or a newline encountered or after a read error
 *   occurs.
 *
 *   If a newline is read, it is stored into the buffer only if 'keepnl' is
 *   set true.  A null terminator is always stored after the last character
 *   in the buffer.
 *
 *   If 'buflen'-1 bytes were read into 'buf' without encountering an EOF
 *   or newline then the following behavior depends on the value of
 *   'consume':  If consume is true, then lib_fgets() will continue reading
 *   bytes and discarding them until an EOF or a newline encountered or
 *   until a read error occurs.  Otherwise, lib_fgets() returns with the
 *   remaining of the incoming stream buffer.
 *
 **************************************************************************/

FAR char *lib_fgets(FAR char *buf, size_t buflen, FILE *stream, bool keepnl, bool consume)
{
	size_t nch = 0;

	/* Sanity checks */

	if (!stream || !buf || stream->fs_fd < 0) {
		return NULL;
	}

	/* Make sure that we have a buffer and space for at least one character */

	if (buflen < 1) {
		consume_eol(stream, consume);
		return NULL;
	}

	/* Make sure that we have space for something in addition to the NUL
	 * terminator.
	 */

	if (buflen < 2) {
		*buf = '\0';
		consume_eol(stream, consume);
		return buf;
	}

	/* Read characters until we have a full line. On each the loop we must
	 * be assured that there are two free bytes in the line buffer:  One for
	 * the next character and one for the null terminator.
	 */

	for (;;) {
		/* Get the next character */

		int ch = fgetc(stream);

		/* Check for end-of-line.  This is tricky only in that some
		 * environments may return CR as end-of-line, others LF, and
		 * others both.
		 */

#if  defined(CONFIG_EOL_IS_LF) || defined(CONFIG_EOL_IS_BOTH_CRLF)
		if (ch == '\n')
#elif defined(CONFIG_EOL_IS_CR)
		if (ch == '\r')
#else							/* elif defined(CONFIG_EOL_IS_EITHER_CRLF) */
		if (ch == '\n' || ch == '\r')
#endif
		{
			if (keepnl) {
				/* Store newline is stored in the buffer */

				buf[nch++] = '\n';
			}

			/* Terminate the string */

			buf[nch] = '\0';
			return buf;
		}

		/* Check for end-of-file */

		else if (ch == EOF) {
			/* End of file with no data? */

			if (!nch) {
				/* Yes.. return NULL as the end of file mark */

				return NULL;
			} else {
				/* No, terminate the accumulated string */

				buf[nch] = '\0';
				return buf;
			}
		}

		/* Otherwise, check if the character is printable and, if so, put the
		 * character in the line buffer
		 */

		else if (isprint(ch)) {
			buf[nch++] = ch;

			/* Check if there is room for another character and the line's
			 * NUL terminator.  If not then we have to end the line now,
			 * perhaps consuming any data up to the end-of-line.
			 */

			if (nch + 1 >= buflen) {
				buf[nch] = '\0';
				consume_eol(stream, consume);
				return buf;
			}
		}
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
 * libc/stdio/lib_libflushall.c
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

#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_flushall
 *
 * Description:
 *   Called either (1) by the OS when a task exits, or (2) from fflush()
 *   when a NULL stream argument is provided.
 *
 ****************************************************************************/

int lib_flushall(FAR struct streamlist *list)
{
	int lasterrno = OK;
	int ret;

	/* Make sure that there are streams associated with this thread */

	if (list) {
		int i;

		/* Process each stream in the thread's stream list */

		stream_semtake(list);
		for (i = 0; i < CONFIG_NFILE_STREAMS; i++) {
			FILE *stream = &list->sl_streams[i];

			/* If the stream is open (i.e., assigned a non-negative file
			 * descriptor) and opened for writing, then flush all of the pending
			 * write data in the stream.
			 */

			if (stream->fs_fd >= 0 && (stream->fs_oflags & O_WROK) != 0) {
				/* Flush the writable FILE */

				ret = lib_fflush(stream, true);
				if (ret < 0) {
					/* An error occurred during the flush AND/OR we were unable
					 * to flush all of the buffered write data.  Remember the
					 * last errcode.
					 */

					lasterrno = ret;
				}
			}
		}

		stream_semgive(list);
	}

	/* If any flush failed, return the errorcode of the last failed flush */

	return lasterrno;
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
 * libc/stdio/lib_libfread.c
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

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_fread
 ****************************************************************************/

ssize_t lib_fread(FAR void *ptr, size_t count, FAR FILE *stream)
{
	unsigned char *dest = (unsigned char *)ptr;
	ssize_t bytes_read;
#if CONFIG_STDIO_BUFFER_SIZE > 0
	int ret;
#endif

	/* Make sure that reading from this stream is allowed */

	if (!stream || (stream->fs_oflags & O_RDOK) == 0) {
		set_errno(EBADF);
		bytes_read = -1;
	} else {
		/* The stream must be stable until we complete the read */

		lib_take_semaphore(stream);

#if CONFIG_NUNGET_CHARS > 0
		/* First, re-read any previously ungotten characters */

		while ((stream->fs_nungotten > 0) && (count > 0)) {
			/* Decrement the count of ungotten bytes to get an index */

			stream->fs_nungotten--;

			/* Return the last ungotten byte */

			*dest++ = stream->fs_ungotten[stream->fs_nungotten];

			/* That's one less byte that we have to read */

			count--;
		}
#endif

#if CONFIG_STDIO_BUFFER_SIZE > 0
		/* If the buffer is currently being used for write access, then
		 * flush all of the buffered write data.  We do not support concurrent
		 * buffered read/write access.
		 */

		ret = lib_wrflush(stream);
		if (ret < 0) {
			lib_give_semaphore(stream);
			return ret;
		}

		/* Now get any other needed chars from the buffer or the file. */

		while (count > 0) {
			/* Is there readable data in the buffer? */

			while ((count > 0) && (stream->fs_bufpos < stream->fs_bufread)) {
				/* Yes, copy a byte into the user buffer */

				*dest++ = *stream->fs_bufpos++;
				count--;
			}

			/* The buffer is empty OR we have already supplied the number of
			 * bytes requested in the read.  Check if we need to read
			 * more from the file.
			 */

			if (count > 0) {
				size_t buffer_available;

				/* We need to read more data into the buffer from the file */

				/* Mark the buffer empty */

				stream->fs_bufpos = stream->fs_bufread = stream->fs_bufstart;

				/* How much space is available in the buffer? */

				buffer_available = stream->fs_bufend - stream->fs_bufread;

				/* Will the number of bytes that we need to read fit into
				 * the buffer space that is available? If the read size is
				 * larger than the buffer, then read some of the data
				 * directly into the user's buffer.
				 */

				if (count > buffer_available) {
					bytes_read = read(stream->fs_fd, dest, count);
					if (bytes_read < 0) {
						/* An error occurred on the read.  The error code is
						 * in the 'errno' variable.
						 */

						goto errout_with_errno;
					} else if (bytes_read == 0) {
						/* We are at the end of the file.  But we may already
						 * have buffered data.  In that case, we will report
						 * the EOF indication later.
						 */

						goto shortread;
					} else {
						/* Some bytes were read. Adjust the dest pointer */

						dest += bytes_read;

						/* Were all of the requested bytes read? */

						if ((size_t)bytes_read < count) {
							/* No.  We must be at the end of file. */

							goto shortread;
						} else {
							/* Yes.  We are done. */

							count = 0;
						}
					}
				} else {
					/* The number of bytes required to satisfy the read
					 * is less than or equal to the size of the buffer
					 * space that we have left. Read as much as we can
					 * into the buffer.
					 */

					bytes_read = read(stream->fs_fd, stream->fs_bufread, buffer_available);
					if (bytes_read < 0) {
						/* An error occurred on the read.  The error code is
						 * in the 'errno' variable.
						 */

						goto errout_with_errno;
					} else if (bytes_read == 0) {
						/* We are at the end of the file.  But we may already
						 * have buffered data.  In that case, we will report
						 * the EOF indication later.
						 */

						goto shortread;
					} else {
						/* Some bytes were read */

						stream->fs_bufread += bytes_read;
					}
				}
			}
		}
#else
		/* Now get any other needed chars from the file. */

		while (count > 0) {
			bytes_read = read(stream->fs_fd, dest, count);
			if (bytes_read < 0) {
				/* An error occurred on the read.  The error code is
				 * in the 'errno' variable.
				 */

				goto errout_with_errno;
			} else if (bytes_read == 0) {
				/* We are at the end of the file.  But we may already
				 * have buffered data.  In that case, we will report
				 * the EOF indication later.
				 */

				break;
			} else {
				dest += bytes_read;
				count -= bytes_read;
			}
		}
#endif
		/* Here after a successful (but perhaps short) read */

#if CONFIG_STDIO_BUFFER_SIZE > 0
shortread:
#endif
		bytes_read = dest - (unsigned char *)ptr;

		/* Set or clear the EOF indicator.  If we get here because of a
		 * short read and the total number of* bytes read is zero, then
		 * we must be at the end-of-file.
		 */

		if (bytes_read > 0) {
			stream->fs_flags &= ~__FS_FLAG_EOF;
		} else {
			stream->fs_flags |= __FS_FLAG_EOF;
		}

		lib_give_semaphore(stream);
	}

	return bytes_read;

	/* Error exits */

errout_with_errno:
	stream->fs_flags |= __FS_FLAG_ERROR;
	lib_give_semaphore(stream);
	return -get_errno();
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
 * libc/stdio/lib_libfwrite.c
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

#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_fwrite
 ****************************************************************************/

ssize_t lib_fwrite(FAR const void *ptr, size_t count, FAR FILE *stream)
#if CONFIG_STDIO_BUFFER_SIZE > 0
{
	FAR const unsigned char *start = ptr;
	FAR const unsigned char *src = ptr;
	ssize_t ret = ERROR;
	unsigned char *dest;

	/* Make sure that writing to this stream is allowed */

	if (!stream || (stream->fs_oflags & O_WROK) == 0) {
		set_errno(EBADF);
		goto errout;
	}

	/* Get exclusive access to the stream */

	lib_take_semaphore(stream);

	/* If the buffer is currently being used for read access, then
	 * discard all of the read-ahead data.  We do not support concurrent
	 * buffered read/write access.
	 */

	if (lib_rdflush(stream) < 0) {
		goto errout_with_semaphore;
	}

	/* Loop until all of the bytes have been buffered */

	while (count > 0) {
		/* Determine the number of bytes left in the buffer */

		size_t gulp_size = stream->fs_bufend - stream->fs_bufpos;

		/* Will the user data fit into the amount of buffer space
		 * that we have left?
		 */

		if (gulp_size > count) {
			/* Yes, clip the gulp to the size of the user data */

			gulp_size = count;
		}

		/* Adjust the number of bytes remaining to be transferred
		 * on the next pass through the loop (might be zero).
		 */

		count -= gulp_size;

		/* Transfer the data into the buffer */

		for (dest = stream->fs_bufpos; gulp_size > 0; gulp_size--) {
			*dest++ = *src++;
		}

		stream->fs_bufpos = dest;

		/* Is the buffer full? */

		if (dest >= stream->fs_bufend) {
			/* Flush the buffered data to the IO stream */

			int bytes_buffered = lib_fflush(stream, false);
			if (bytes_buffered < 0) {
				goto errout_with_semaphore;
			}
		}
	}

	/* Return the number of bytes written */

	ret = src - start;

errout_with_semaphore:
	lib_give_semaphore(stream);

errout:
	if (stream && (ret < 0)) {
		stream->fs_flags |= __FS_FLAG_ERROR;
	}

	return ret;
}
#else
{
	ssize_t ret = write(stream->fs_fd, ptr, count);
	if (ret < 0) {
		stream->fs_flags |= __FS_FLAG_ERROR;
	}

	return ret;
}
#endif							/* CONFIG_STDIO_BUFFER_SIZE */
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
 * libc/stdio/lib_libnoflush.c
 *
 *   Copyright (C) 2011-2012 Gregory Nutt. All rights reserved.
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
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include <tinyara/streams.h>

#include "lib_internal.h"

#ifdef CONFIG_STDIO_LINEBUFFER

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_noflush
 *
 * Description:
 *  lib_noflush() provides a common, dummy flush method for output streams
 *  that are not flushable.  Only used if CONFIG_STDIO_LINEBUFFER is selected.
 *
 * Return:
 *  Always returns OK
 *
 ****************************************************************************/

int lib_noflush(FAR struct lib_outstream_s *this)
{
	return OK;
}

#endif							/* CONFIG_STDIO_LINEBUFFER */
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
 * libc/stdio/lib_libsnoflush.c
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

#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "lib_internal.h"

#ifdef CONFIG_STDIO_LINEBUFFER

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_snoflush
 *
 * Description:
 *  lib_snoflush() provides a common, dummy flush method for seekable output
 *  streams that are not flushable.  Only used if CONFIG_STDIO_LINEBUFFER
 *  is selected.
 *
 * Return:
 *  Always returns OK
 *
 ****************************************************************************/

int lib_snoflush(FAR struct lib_sostream_s *this)
{
	return OK;
}

#endif							/* CONFIG_STDIO_LINEBUFFER */
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
 * libc/stdio/lib_libsprintf.c
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

#include <stdio.h>
#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_sprintf
 ****************************************************************************/

int lib_sprintf(FAR struct lib_outstream_s *obj, const char *fmt, ...)
{
	va_list ap;
	int n;

	/* Let lib_vsprintf do the real work */

	va_start(ap, fmt);
	n = lib_vsprintf(obj, fmt, ap);
	va_end(ap);
	return n;
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
 * libc/stdio/lib_libvsprintf.c
 *
 *   Copyright (C) 2007-2012 Gregory Nutt. All rights reserved.
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

#include <tinyara/compiler.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <tinyara/arch.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* If you have floating point but no fieldwidth, then use a fixed (but
 * configurable) floating point precision.
 */

#if defined(CONFIG_LIBC_FLOATINGPOINT) && \
	defined(CONFIG_NOPRINTF_FIELDWIDTH) && \
	!defined(CONFIG_LIBC_FIXEDPRECISION)
#define CONFIG_LIBC_FIXEDPRECISION 3
#endif

#if defined(CONFIG_LIBC_FLOATINGPOINT) && !defined(CONFIG_LIBC_FLOATPRECISION)
#define CONFIG_LIBC_FLOATPRECISION 6
#endif

#define FLAG_SHOWPLUS            0x01
#define FLAG_ALTFORM             0x02
#define FLAG_HASDOT              0x04
#define FLAG_HASASTERISKWIDTH    0x08
#define FLAG_HASASTERISKTRUNC    0x10
#define FLAG_LONGPRECISION       0x20
#define FLAG_LONGLONGPRECISION   0x40
#define FLAG_NEGATE              0x80

#define SET_SHOWPLUS(f)          do { (f) |= FLAG_SHOWPLUS; } while (0)
#define SET_ALTFORM(f)           do { (f) |= FLAG_ALTFORM; } while (0)
#define SET_HASDOT(f)            do { (f) |= FLAG_HASDOT; } while (0)
#define SET_HASASTERISKWIDTH(f)  do { (f) |= FLAG_HASASTERISKWIDTH; } while (0)
#define SET_HASASTERISKTRUNC(f)  do { (f) |= FLAG_HASASTERISKTRUNC; } while (0)
#define SET_LONGPRECISION(f)     do { (f) |= FLAG_LONGPRECISION; } while (0)
#define SET_LONGLONGPRECISION(f) do { (f) |= FLAG_LONGLONGPRECISION; } while (0)
#define SET_NEGATE(f)            do { (f) |= FLAG_NEGATE; } while (0)

#define CLR_SHOWPLUS(f)          do { (f) &= ~FLAG_SHOWPLUS; } while (0)
#define CLR_ALTFORM(f)           do { (f) &= ~FLAG_ALTFORM; } while (0)
#define CLR_HASDOT(f)            do { (f) &= ~FLAG_HASDOT; } while (0)
#define CLR_HASASTERISKWIDTH(f)  do { (f) &= ~FLAG_HASASTERISKWIDTH; } while (0)
#define CLR_HASASTERISKTRUNC(f)  do { (f) &= ~FLAG_HASASTERISKTRUNC; } while (0)
#define CLR_LONGPRECISION(f)     do { (f) &= ~FLAG_LONGPRECISION; } while (0)
#define CLR_LONGLONGPRECISION(f) do { (f) &= ~FLAG_LONGLONGPRECISION; } while (0)
#define CLR_NEGATE(f)            do { (f) &= ~FLAG_NEGATE; } while (0)
#define CLR_SIGNED(f)            do { (f) &= ~(FLAG_SHOWPLUS|FLAG_NEGATE); } while (0)

#define IS_SHOWPLUS(f)           (((f) & FLAG_SHOWPLUS) != 0)
#define IS_ALTFORM(f)            (((f) & FLAG_ALTFORM) != 0)
#define IS_HASDOT(f)             (((f) & FLAG_HASDOT) != 0)
#define IS_HASASTERISKWIDTH(f)   (((f) & FLAG_HASASTERISKWIDTH) != 0)
#define IS_HASASTERISKTRUNC(f)   (((f) & FLAG_HASASTERISKTRUNC) != 0)
#define IS_LONGPRECISION(f)      (((f) & FLAG_LONGPRECISION) != 0)
#define IS_LONGLONGPRECISION(f)  (((f) & FLAG_LONGLONGPRECISION) != 0)
#define IS_NEGATE(f)             (((f) & FLAG_NEGATE) != 0)
#define IS_SIGNED(f)             (((f) & (FLAG_SHOWPLUS|FLAG_NEGATE)) != 0)

/* If CONFIG_ARCH_ROMGETC is defined, then it is assumed that the format
 * string data cannot be accessed by simply de-referencing the format string
 * pointer.  This might be in the case in Harvard architectures where string
 * data might be stored in instruction space or if string data were stored
 * on some media like EEPROM or external serial FLASH.  In all of these cases,
 * string data has to be accessed indirectly using the architecture-supplied
 * up_romgetc().  The following mechanisms attempt to make these different
 * access methods indistinguishable in the following code.
 *
 * NOTE: It is assumed that string arguments for %s still reside in memory
 * that can be directly accessed by de-referencing the string pointer.
 */

#ifdef CONFIG_ARCH_ROMGETC
#define FMT_TOP      ch = up_romgetc(src)			/* Loop initialization */
#define FMT_BOTTOM   src++, ch = up_romgetc(src)	/* Bottom of a loop */
#define FMT_CHAR     ch								/* Access a character */
#define FMT_NEXT     src++; ch = up_romgetc(src)	/* Advance to the next character */
#define FMT_PREV     src--; ch = up_romgetc(src)	/* Backup to the previous character */
#else
#define FMT_TOP					/* Loop initialization */
#define FMT_BOTTOM   src++		/* Bottom of a loop */
#define FMT_CHAR     *src		/* Access a character */
#define FMT_NEXT     src++		/* Advance to the next character */
#define FMT_PREV     src--		/* Backup to the previous character */
#endif

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

enum {
	FMT_RJUST = 0,				/* Default */
	FMT_LJUST,
	FMT_RJUST0,
	FMT_CENTER
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* Pointer to ASCII conversion */

#ifdef CONFIG_PTR_IS_NOT_INT
static void ptohex(FAR struct lib_outstream_s *obj, uint8_t flags, FAR void *p);
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static int getsizesize(uint8_t fmt, uint8_t flags, FAR void *p)
#endif							/* CONFIG_NOPRINTF_FIELDWIDTH */
#endif							/* CONFIG_PTR_IS_NOT_INT */
/* Unsigned int to ASCII conversion */
static void utodec(FAR struct lib_outstream_s *obj, unsigned int n);
static void utohex(FAR struct lib_outstream_s *obj, unsigned int n, uint8_t a);
static void utooct(FAR struct lib_outstream_s *obj, unsigned int n);
static void utobin(FAR struct lib_outstream_s *obj, unsigned int n);
static void utoascii(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, unsigned int lln);

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void fixup(uint8_t fmt, FAR uint8_t *flags, int *n);
static int getusize(uint8_t fmt, uint8_t flags, unsigned int lln);
#endif

/* Unsigned long int to ASCII conversion */

#ifdef CONFIG_LONG_IS_NOT_INT
static void lutodec(FAR struct lib_outstream_s *obj, unsigned long ln);
static void lutohex(FAR struct lib_outstream_s *obj, unsigned long ln, uint8_t a);
static void lutooct(FAR struct lib_outstream_s *obj, unsigned long ln);
static void lutobin(FAR struct lib_outstream_s *obj, unsigned long ln);
static void lutoascii(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, unsigned long ln);
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void lfixup(uint8_t fmt, FAR uint8_t *flags, long *ln);
static int getlusize(uint8_t fmt, FAR uint8_t flags, unsigned long ln);
#endif
#endif

/* Unsigned long long int to ASCII conversions */

#ifndef CONFIG_NOPRINTF_LONGLONG_TO_ASCII
static void llutodec(FAR struct lib_outstream_s *obj, unsigned long long lln);
static void llutohex(FAR struct lib_outstream_s *obj, unsigned long long lln, uint8_t a);
static void llutooct(FAR struct lib_outstream_s *obj, unsigned long long lln);
static void llutobin(FAR struct lib_outstream_s *obj, unsigned long long lln);
static void llutoascii(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, unsigned long long lln);
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void llfixup(uint8_t fmt, FAR uint8_t *flags, FAR long long *lln);
static int getllusize(uint8_t fmt, FAR uint8_t flags, FAR unsigned long long lln);
#endif
#endif

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void prejustify(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, int fieldwidth, int valwidth);
static void postjustify(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, int fieldwidth, int valwidth);
#endif

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

static const char g_nullstring[] = "(null)";

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/* Include floating point functions */

#ifdef CONFIG_LIBC_FLOATINGPOINT
#include "stdio/lib_libdtoa.c"
#endif

/****************************************************************************
 * Name: ptohex
 ****************************************************************************/

#ifdef CONFIG_PTR_IS_NOT_INT
static void ptohex(FAR struct lib_outstream_s *obj, uint8_t flags, FAR void *p)
{
	union {
		uint32_t dw;
		FAR void *p;
	} u;
	uint8_t bits;

	/* Check for alternate form */

	if (IS_ALTFORM(flags)) {
		/* Prefix the number with "0x" */

		obj->put(obj, '0');
		obj->put(obj, 'x');
	}

	u.dw = 0;
	u.p = p;

	for (bits = 8 * sizeof(void *); bits > 0; bits -= 4) {
		uint8_t nibble = (uint8_t)((u.dw >> (bits - 4)) & 0xf);
		if (nibble < 10) {
			obj->put(obj, nibble + '0');
		} else {
			obj->put(obj, nibble + 'a' - 10);
		}
	}
}

/****************************************************************************
 * Name: getpsize
 ****************************************************************************/

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static int getpsize(uint8_t flags, FAR void *p)
{
	struct lib_outstream_s nulloutstream;
	lib_nulloutstream(&nulloutstream);

	ptohex(&nulloutstream, flags, p);
	return nulloutstream.nput;
}

#endif							/* CONFIG_NOPRINTF_FIELDWIDTH */
#endif							/* CONFIG_PTR_IS_NOT_INT */

/****************************************************************************
 * Name: utodec
 ****************************************************************************/

static void utodec(FAR struct lib_outstream_s *obj, unsigned int n)
{
	unsigned int remainder = n % 10;
	unsigned int dividend = n / 10;

	if (dividend) {
		utodec(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: utohex
 ****************************************************************************/

static void utohex(FAR struct lib_outstream_s *obj, unsigned int n, uint8_t a)
{
	bool nonzero = false;
	uint8_t bits;

	for (bits = 8 * sizeof(unsigned int); bits > 0; bits -= 4) {
		uint8_t nibble = (uint8_t)((n >> (bits - 4)) & 0xf);
		if (nibble || nonzero) {
			nonzero = true;

			if (nibble < 10) {
				obj->put(obj, nibble + '0');
			} else {
				obj->put(obj, nibble + a - 10);
			}
		}
	}

	if (!nonzero) {
		obj->put(obj, '0');
	}
}

/****************************************************************************
 * Name: utooct
 ****************************************************************************/

static void utooct(FAR struct lib_outstream_s *obj, unsigned int n)
{
	unsigned int remainder = n & 0x7;
	unsigned int dividend = n >> 3;

	if (dividend) {
		utooct(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: utobin
 ****************************************************************************/

static void utobin(FAR struct lib_outstream_s *obj, unsigned int n)
{
	unsigned int remainder = n & 1;
	unsigned int dividend = n >> 1;

	if (dividend) {
		utobin(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: utoascii
 ****************************************************************************/

static void utoascii(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, unsigned int n)
{
	/* Perform the integer conversion according to the format specifier */

	switch (fmt) {
	case 'd':
	case 'i':
		/* Signed base 10 */
	{
#ifdef CONFIG_NOPRINTF_FIELDWIDTH
		if ((int)n < 0) {
			obj->put(obj, '-');
			n = (unsigned int)(-(int)n);
		} else if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
		}
#endif
		/* Convert the unsigned value to a string. */

		utodec(obj, n);
	}
	break;

	case 'u':
		/* Unigned base 10 */
	{
#ifdef CONFIG_NOPRINTF_FIELDWIDTH
		if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
		}
#endif
		/* Convert the unsigned value to a string. */

		utodec(obj, n);
	}
	break;

#ifndef CONFIG_PTR_IS_NOT_INT
	case 'p':
#endif
	case 'x':
	case 'X':
		/* Hexadecimal */
	{
		/* Check for alternate form */

		if (IS_ALTFORM(flags)) {
			/* Prefix the number with "0x" */

			obj->put(obj, '0');
			obj->put(obj, 'x');
		}

		/* Convert the unsigned value to a string. */

		if (fmt == 'X') {
			utohex(obj, n, 'A');
		} else {
			utohex(obj, n, 'a');
		}
	}
	break;

	case 'o':
		/* Octal */
	{
		/* Check for alternate form */

		if (IS_ALTFORM(flags)) {
			/* Prefix the number with '0' */

			obj->put(obj, '0');
		}

		/* Convert the unsigned value to a string. */

		utooct(obj, n);
	}
	break;

	case 'b':
		/* Binary */
	{
		/* Convert the unsigned value to a string. */

		utobin(obj, n);
	}
	break;

#ifdef CONFIG_PTR_IS_NOT_INT
	case 'p':
#endif
	default:
		break;
	}
}

/****************************************************************************
 * Name: fixup
 ****************************************************************************/

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void fixup(uint8_t fmt, FAR uint8_t *flags, FAR int *n)
{
	/* Perform the integer conversion according to the format specifier */

	switch (fmt) {
	case 'd':
	case 'i':
		/* Signed base 10 */

		if (*n < 0) {
			SET_NEGATE(*flags);
			CLR_SHOWPLUS(*flags);
			*n = -*n;
		}
		break;

	case 'u':
		/* Unsigned base 10 */
		break;

	case 'p':
	case 'x':
	case 'X':
	/* Hexadecimal */
	case 'o':
	/* Octal */
	case 'b':
		/* Binary */
		CLR_SIGNED(*flags);
		break;

	default:
		break;
	}
}

/****************************************************************************
 * Name: getusize
 ****************************************************************************/

static int getusize(uint8_t fmt, uint8_t flags, unsigned int n)
{
	struct lib_outstream_s nulloutstream;
	lib_nulloutstream(&nulloutstream);

	utoascii(&nulloutstream, fmt, flags, n);
	return nulloutstream.nput;
}

/****************************************************************************
 * Name: getdblsize
 ****************************************************************************/

#ifdef CONFIG_LIBC_FLOATINGPOINT
static int getdblsize(uint8_t fmt, int trunc, uint8_t flags, double n)
{
	struct lib_outstream_s nulloutstream;
	lib_nulloutstream(&nulloutstream);

	lib_dtoa(&nulloutstream, fmt, trunc, flags, n);
	return nulloutstream.nput;
}
#endif
#endif							/* CONFIG_NOPRINTF_FIELDWIDTH */

#ifdef CONFIG_LONG_IS_NOT_INT
/****************************************************************************
 * Name: lutodec
 ****************************************************************************/

static void lutodec(FAR struct lib_outstream_s *obj, unsigned long n)
{
	unsigned int remainder = n % 10;
	unsigned long dividend = n / 10;

	if (dividend) {
		lutodec(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: lutohex
 ****************************************************************************/

static void lutohex(FAR struct lib_outstream_s *obj, unsigned long n, uint8_t a)
{
	bool nonzero = false;
	uint8_t bits;

	for (bits = 8 * sizeof(unsigned long); bits > 0; bits -= 4) {
		uint8_t nibble = (uint8_t)((n >> (bits - 4)) & 0xf);
		if (nibble || nonzero) {
			nonzero = true;

			if (nibble < 10) {
				obj->put(obj, nibble + '0');
			} else {
				obj->put(obj, nibble + a - 10);
			}
		}
	}

	if (!nonzero) {
		obj->put(obj, '0');
	}
}

/****************************************************************************
 * Name: lutooct
 ****************************************************************************/

static void lutooct(FAR struct lib_outstream_s *obj, unsigned long n)
{
	unsigned int remainder = n & 0x7;
	unsigned long dividend = n >> 3;

	if (dividend) {
		lutooct(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: lutobin
 ****************************************************************************/

static void lutobin(FAR struct lib_outstream_s *obj, unsigned long n)
{
	unsigned int remainder = n & 1;
	unsigned long dividend = n >> 1;

	if (dividend) {
		lutobin(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: lutoascii
 ****************************************************************************/

static void lutoascii(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, unsigned long ln)
{
	/* Perform the integer conversion according to the format specifier */

	switch (fmt) {
	case 'd':
	case 'i':
		/* Signed base 10 */
	{
#ifdef CONFIG_NOPRINTF_FIELDWIDTH
		if ((long)ln < 0) {
			obj->put(obj, '-');
			ln = (unsigned long)(-(long)ln);
		} else if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
		}
#endif
		/* Convert the unsigned value to a string. */

		lutodec(obj, ln);
	}
	break;

	case 'u':
		/* Unigned base 10 */
	{
#ifdef CONFIG_NOPRINTF_FIELDWIDTH
		if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
		}
#endif
		/* Convert the unsigned value to a string. */

		lutodec(obj, ln);
	}
	break;

	case 'x':
	case 'X':
		/* Hexadecimal */
	{
		/* Check for alternate form */

		if (IS_ALTFORM(flags)) {
			/* Prefix the number with "0x" */

			obj->put(obj, '0');
			obj->put(obj, 'x');
		}

		/* Convert the unsigned value to a string. */

		if (fmt == 'X') {
			lutohex(obj, ln, 'A');
		} else {
			lutohex(obj, ln, 'a');
		}
	}
	break;

	case 'o':
		/* Octal */
	{
		/* Check for alternate form */

		if (IS_ALTFORM(flags)) {
			/* Prefix the number with '0' */

			obj->put(obj, '0');
		}

		/* Convert the unsigned value to a string. */

		lutooct(obj, ln);
	}
	break;

	case 'b':
		/* Binary */
	{
		/* Convert the unsigned value to a string. */

		lutobin(obj, ln);
	}
	break;

	case 'p':
	default:
		break;
	}
}

/****************************************************************************
 * Name: lfixup
 ****************************************************************************/

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void lfixup(uint8_t fmt, FAR uint8_t *flags, FAR long *ln)
{
	/* Perform the integer conversion according to the format specifier */

	switch (fmt) {
	case 'd':
	case 'i':
		/* Signed base 10 */

		if (*ln < 0) {
			SET_NEGATE(*flags);
			CLR_SHOWPLUS(*flags);
			*ln = -*ln;
		}
		break;

	case 'u':
		/* Unsigned base 10 */
		break;

	case 'p':
	case 'x':
	case 'X':
	/* Hexadecimal */
	case 'o':
	/* Octal */
	case 'b':
		/* Binary */
		CLR_SIGNED(*flags);
		break;

	default:
		break;
	}
}

/****************************************************************************
 * Name: getlusize
 ****************************************************************************/

static int getlusize(uint8_t fmt, uint8_t flags, unsigned long ln)
{
	struct lib_outstream_s nulloutstream;
	lib_nulloutstream(&nulloutstream);

	lutoascii(&nulloutstream, fmt, flags, ln);
	return nulloutstream.nput;
}

#endif							/* CONFIG_NOPRINTF_FIELDWIDTH */
#endif							/* CONFIG_LONG_IS_NOT_INT */

#ifndef CONFIG_NOPRINTF_LONGLONG_TO_ASCII
/****************************************************************************
 * Name: llutodec
 ****************************************************************************/

static void llutodec(FAR struct lib_outstream_s *obj, unsigned long long n)
{
	unsigned int remainder = n % 10;
	unsigned long long dividend = n / 10;

	if (dividend) {
		llutodec(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: llutohex
 ****************************************************************************/

static void llutohex(FAR struct lib_outstream_s *obj, unsigned long long n, uint8_t a)
{
	bool nonzero = false;
	uint8_t bits;

	for (bits = 8 * sizeof(unsigned long long); bits > 0; bits -= 4) {
		uint8_t nibble = (uint8_t)((n >> (bits - 4)) & 0xf);
		if (nibble || nonzero) {
			nonzero = true;

			if (nibble < 10) {
				obj->put(obj, (nibble + '0'));
			} else {
				obj->put(obj, (nibble + a - 10));
			}
		}
	}

	if (!nonzero) {
		obj->put(obj, '0');
	}
}

/****************************************************************************
 * Name: llutooct
 ****************************************************************************/

static void llutooct(FAR struct lib_outstream_s *obj, unsigned long long n)
{
	unsigned int remainder = n & 0x7;
	unsigned long long dividend = n >> 3;

	if (dividend) {
		llutooct(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: llutobin
 ****************************************************************************/

static void llutobin(FAR struct lib_outstream_s *obj, unsigned long long n)
{
	unsigned int remainder = n & 1;
	unsigned long long dividend = n >> 1;

	if (dividend) {
		llutobin(obj, dividend);
	}

	obj->put(obj, (remainder + (unsigned int)'0'));
}

/****************************************************************************
 * Name: llutoascii
 ****************************************************************************/

static void llutoascii(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, unsigned long long lln)
{
	/* Perform the integer conversion according to the format specifier */

	switch (fmt) {
	case 'd':
	case 'i':
		/* Signed base 10 */
	{
#ifdef CONFIG_NOPRINTF_FIELDWIDTH
		if ((long long)lln < 0) {
			obj->put(obj, '-');
			lln = (unsigned long long)(-(long long)lln);
		} else if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
		}
#endif
		/* Convert the unsigned value to a string. */

		llutodec(obj, (unsigned long long)lln);
	}
	break;

	case 'u':
		/* Unigned base 10 */
	{
#ifdef CONFIG_NOPRINTF_FIELDWIDTH
		if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
		}
#endif
		/* Convert the unsigned value to a string. */

		llutodec(obj, (unsigned long long)lln);
	}
	break;

	case 'x':
	case 'X':
		/* Hexadecimal */
	{
		/* Check for alternate form */

		if (IS_ALTFORM(flags)) {
			/* Prefix the number with "0x" */

			obj->put(obj, '0');
			obj->put(obj, 'x');
		}

		/* Convert the unsigned value to a string. */

		if (fmt == 'X') {
			llutohex(obj, (unsigned long long)lln, 'A');
		} else {
			llutohex(obj, (unsigned long long)lln, 'a');
		}
	}
	break;

	case 'o':
		/* Octal */
	{
		/* Check for alternate form */

		if (IS_ALTFORM(flags)) {
			/* Prefix the number with '0' */

			obj->put(obj, '0');
		}

		/* Convert the unsigned value to a string. */

		llutooct(obj, (unsigned long long)lln);
	}
	break;

	case 'b':
		/* Binary */
	{
		/* Convert the unsigned value to a string. */

		llutobin(obj, (unsigned long long)lln);
	}
	break;

	case 'p':
	default:
		break;
	}
}

/****************************************************************************
 * Name: llfixup
 ****************************************************************************/

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void llfixup(uint8_t fmt, FAR uint8_t *flags, FAR long long *lln)
{
	/* Perform the integer conversion according to the format specifier */

	switch (fmt) {
	case 'd':
	case 'i':
		/* Signed base 10 */

		if (*lln < 0) {
			SET_NEGATE(*flags);
			CLR_SHOWPLUS(*flags);
			*lln = -*lln;
		}
		break;

	case 'u':
		/* Unsigned base 10 */
		break;

	case 'p':
	case 'x':
	case 'X':
	/* Hexadecimal */
	case 'o':
	/* Octal */
	case 'b':
		/* Binary */
		CLR_SIGNED(*flags);
		break;

	default:
		break;
	}
}

/****************************************************************************
 * Name: getllusize
 ****************************************************************************/

static int getllusize(uint8_t fmt, uint8_t flags, unsigned long long lln)
{
	struct lib_outstream_s nulloutstream;
	lib_nulloutstream(&nulloutstream);

	llutoascii(&nulloutstream, fmt, flags, lln);
	return nulloutstream.nput;
}

#endif							/* CONFIG_NOPRINTF_FIELDWIDTH */
#endif							/* CONFIG_NOPRINTF_LONGLONG_TO_ASCII */

/****************************************************************************
 * Name: prejustify
 ****************************************************************************/

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void prejustify(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, int fieldwidth, int valwidth)
{
	int i;

	switch (fmt) {
	default:
	case FMT_RJUST:
		if (IS_SIGNED(flags)) {
			valwidth++;
		}

		for (i = fieldwidth - valwidth; i > 0; i--) {
			obj->put(obj, ' ');
		}

		if (IS_NEGATE(flags)) {
			obj->put(obj, '-');
		} else if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
		}
		break;

	case FMT_RJUST0:
		if (IS_NEGATE(flags)) {
			obj->put(obj, '-');
			valwidth++;
		} else if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
			valwidth++;
		}

		for (i = fieldwidth - valwidth; i > 0; i--) {
			obj->put(obj, '0');
		}
		break;

	case FMT_LJUST:
		if (IS_NEGATE(flags)) {
			obj->put(obj, '-');
		} else if (IS_SHOWPLUS(flags)) {
			obj->put(obj, '+');
		}
		break;
	}
}
#endif

/****************************************************************************
 * Name: postjustify
 ****************************************************************************/

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
static void postjustify(FAR struct lib_outstream_s *obj, uint8_t fmt, uint8_t flags, int fieldwidth, int valwidth)
{
	int i;

	/* Apply field justification to the integer value. */

	switch (fmt) {
	default:
	case FMT_RJUST:
	case FMT_RJUST0:
		break;

	case FMT_LJUST:
		if (IS_SIGNED(flags)) {
			valwidth++;
		}

		for (i = fieldwidth - valwidth; i > 0; i--) {
			obj->put(obj, ' ');
		}
		break;
	}
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * libc/stdio/lib_vsprintf
 ****************************************************************************/

int lib_vsprintf(FAR struct lib_outstream_s *obj, FAR const char *src, va_list ap)
{
	FAR char *ptmp;
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
	int width;
#ifdef CONFIG_LIBC_FLOATINGPOINT
	int trunc;
#endif
	int trunc_sfmt;
	uint8_t fmt;
#endif
	uint8_t flags;
#ifdef CONFIG_ARCH_ROMGETC
	char ch;
#endif

	for (FMT_TOP; FMT_CHAR; FMT_BOTTOM) {
		/* Just copy regular characters */

		if (FMT_CHAR != '%') {
			/* Output the character */

			obj->put(obj, FMT_CHAR);

			/* Flush the buffer if a newline is encountered */

#ifdef CONFIG_STDIO_LINEBUFFER
			if (FMT_CHAR == '\n') {
				/* Should return an error on a failure to flush */

				(void)obj->flush(obj);
			}
#endif
			/* Process the next character in the format */

			continue;
		}

		/* We have found a format specifier. Move past it. */

		FMT_NEXT;

		/* Assume defaults */

		flags = 0;
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
		fmt = FMT_RJUST;
		width = 0;
#ifdef CONFIG_LIBC_FLOATINGPOINT
		trunc = CONFIG_LIBC_FLOATPRECISION;
#endif
		trunc_sfmt = 0;
#endif

		/* Process each format qualifier. */

		for (; FMT_CHAR; FMT_BOTTOM) {
			/* Break out of the loop when the format is known. */

			if (strchr("diuxXpobeEfgGlLsc%", FMT_CHAR)) {
				break;
			}

			/* Check for left justification. */

			else if (FMT_CHAR == '-') {
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				fmt = FMT_LJUST;
#endif
			}

			/* Check for leading zero fill right justification. */

			else if (FMT_CHAR == '0') {
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				fmt = FMT_RJUST0;
#endif
			}
#if 0
			/* Center justification. */

			else if (FMT_CHAR == '~') {
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				fmt = FMT_CENTER;
#endif
			}
#endif

			else if (FMT_CHAR == '*') {
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				int value = va_arg(ap, int);
				if (IS_HASDOT(flags)) {
#ifdef CONFIG_LIBC_FLOATINGPOINT
					trunc = value;
					SET_HASASTERISKTRUNC(flags);
#endif
				} else {
					width = value;
					SET_HASASTERISKWIDTH(flags);
				}
#endif
			}

			/* Check for field width */

			else if (FMT_CHAR >= '1' && FMT_CHAR <= '9') {
#ifdef CONFIG_NOPRINTF_FIELDWIDTH
				do {
					FMT_NEXT;
				} while (FMT_CHAR >= '0' && FMT_CHAR <= '9');
#else
				/* Accumulate the field width integer. */

				int n = ((int)(FMT_CHAR)) - (int)'0';
				for (;;) {
					FMT_NEXT;
					if (FMT_CHAR >= '0' && FMT_CHAR <= '9') {
						n = 10 * n + (((int)(FMT_CHAR)) - (int)'0');
					} else {
						break;
					}
				}

				if (IS_HASDOT(flags)) {
#ifdef CONFIG_LIBC_FLOATINGPOINT
					trunc = n;
#endif
					trunc_sfmt = n;
				} else {
					width = n;
				}
#endif
				/* Back up to the last digit. */

				FMT_PREV;
			}

			/* Check for a decimal point. */

			else if (FMT_CHAR == '.') {
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				SET_HASDOT(flags);
#endif
			}

			/* Check for leading plus sign. */

			else if (FMT_CHAR == '+') {
				SET_SHOWPLUS(flags);
			}

			/* Check for alternate form. */

			else if (FMT_CHAR == '#') {
				SET_ALTFORM(flags);
			}
		}

		/* "%%" means that a literal '%' was intended (instead of a format
		 * specification).
		 */

		if (FMT_CHAR == '%') {
			obj->put(obj, '%');
			continue;
		}

		/* Check for the string format. */

		if (FMT_CHAR == 's') {
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
			int swidth;
#endif
			/* Get the string to output */

			ptmp = va_arg(ap, char *);
			if (!ptmp) {
				ptmp = (char *)g_nullstring;
			}

			/* Get the width of the string and perform right-justification
			 * operations.
			 */

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
			swidth = strlen(ptmp);
			prejustify(obj, fmt, 0, width, swidth);

			/* Concatenate the string into the output */

			if (trunc_sfmt) {
				while (*ptmp && trunc_sfmt--) {
					obj->put(obj, *ptmp);
					ptmp++;
				}
			} else
#endif
			{
				while (*ptmp) {
					obj->put(obj, *ptmp);
					ptmp++;
				}
			}

			/* Perform left-justification operations. */

#ifndef CONFIG_NOPRINTF_FIELDWIDTH
			postjustify(obj, fmt, 0, width, swidth);
#endif
			continue;
		}

		/* Check for the character output */

		else if (FMT_CHAR == 'c') {
			/* Just copy the character into the output. */

			int n = va_arg(ap, int);
			obj->put(obj, n);
			continue;
		}

		/* Check for the long long prefix. */

		if (FMT_CHAR == 'L') {
			SET_LONGLONGPRECISION(flags);
			FMT_NEXT;
		} else if (FMT_CHAR == 'l') {
			SET_LONGPRECISION(flags);
			FMT_NEXT;
			if (FMT_CHAR == 'l') {
				SET_LONGLONGPRECISION(flags);
				FMT_NEXT;
			}
		}

		/* Handle integer conversions */

		if (strchr("diuxXpob", FMT_CHAR)) {
#ifndef CONFIG_NOPRINTF_LONGLONG_TO_ASCII
			if (IS_LONGLONGPRECISION(flags) && FMT_CHAR != 'p') {
				long long lln;
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				int lluwidth;
#endif
				/* Extract the long long value. */

				lln = va_arg(ap, long long);

#ifdef CONFIG_NOPRINTF_FIELDWIDTH
				/* Output the number */

				llutoascii(obj, FMT_CHAR, flags, (unsigned long long)lln);
#else
				/* Resolve sign-ness and format issues */

				llfixup(FMT_CHAR, &flags, &lln);

				/* Get the width of the output */

				lluwidth = getllusize(FMT_CHAR, flags, lln);

				/* Perform left field justification actions */

				prejustify(obj, fmt, flags, width, lluwidth);

				/* Output the number */

				llutoascii(obj, FMT_CHAR, flags, (unsigned long long)lln);

				/* Perform right field justification actions */

				postjustify(obj, fmt, flags, width, lluwidth);
#endif
			} else
#endif							/* CONFIG_NOPRINTF_LONGLONG_TO_ASCII */
#ifdef CONFIG_LONG_IS_NOT_INT
			if (IS_LONGPRECISION(flags) && FMT_CHAR != 'p') {
				long ln;
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				int luwidth;
#endif
				/* Extract the long value. */

				ln = va_arg(ap, long);

#ifdef CONFIG_NOPRINTF_FIELDWIDTH
				/* Output the number */

				lutoascii(obj, FMT_CHAR, flags, (unsigned long)ln);
#else
				/* Resolve sign-ness and format issues */

				lfixup(FMT_CHAR, &flags, &ln);

				/* Get the width of the output */

				luwidth = getlusize(FMT_CHAR, flags, ln);

				/* Perform left field justification actions */

				prejustify(obj, fmt, flags, width, luwidth);

				/* Output the number */

				lutoascii(obj, FMT_CHAR, flags, (unsigned long)ln);

				/* Perform right field justification actions */

				postjustify(obj, fmt, flags, width, luwidth);
#endif
			} else
#endif							/* CONFIG_LONG_IS_NOT_INT */
#ifdef CONFIG_PTR_IS_NOT_INT
			if (FMT_CHAR == 'p') {
				void *p;
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				int pwidth;
#endif
				/* Extract the integer value. */

				p = va_arg(ap, void *);

#ifdef CONFIG_NOPRINTF_FIELDWIDTH
				/* Output the pointer value */

				ptohex(obj, flags, p);
#else
				/* Resolve sign-ness and format issues */

				lfixup(FMT_CHAR, &flags, &ln);

				/* Get the width of the output */

				pwidth = getpsize(FMT_CHAR, flags, p);

				/* Perform left field justification actions */

				prejustify(obj, fmt, flags, width, pwidth);

				/* Output the pointer value */

				ptohex(obj, flags, p);

				/* Perform right field justification actions */

				postjustify(obj, fmt, flags, width, pwidth);
#endif
			} else
#endif
			{
				int n;
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
				int uwidth;
#endif
				/* Extract the long long value. */

				n = va_arg(ap, int);

#ifdef CONFIG_NOPRINTF_FIELDWIDTH
				/* Output the number */

				utoascii(obj, FMT_CHAR, flags, (unsigned int)n);
#else
				/* Resolve sign-ness and format issues */

				fixup(FMT_CHAR, &flags, &n);

				/* Get the width of the output */

				uwidth = getusize(FMT_CHAR, flags, n);

				/* Perform left field justification actions */

				prejustify(obj, fmt, flags, width, uwidth);

				/* Output the number */

				utoascii(obj, FMT_CHAR, flags, (unsigned int)n);

				/* Perform right field justification actions */

				postjustify(obj, fmt, flags, width, uwidth);
#endif
			}
		}

		/* Handle floating point conversions */

#ifdef CONFIG_LIBC_FLOATINGPOINT
		else if (strchr("eEfgG", FMT_CHAR)) {
#ifndef CONFIG_NOPRINTF_FIELDWIDTH
			double dblval = va_arg(ap, double);
			int dblsize;

			/* Get the width of the output */

			dblsize = getdblsize(FMT_CHAR, trunc, flags, dblval);

			/* Perform left field justification actions */

			prejustify(obj, fmt, 0, width, dblsize);

			/* Output the number */

			lib_dtoa(obj, FMT_CHAR, trunc, flags, dblval);

			/* Perform right field justification actions */

			postjustify(obj, fmt, 0, width, dblsize);
#else
			/* Output the number with a fixed precision */

			double dblval = va_arg(ap, double);
			lib_dtoa(obj, FMT_CHAR, CONFIG_LIBC_FIXEDPRECISION, flags, dblval);
#endif
		}
#endif							/* CONFIG_LIBC_FLOATINGPOINT */
	}

	return obj->nput;
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
 * libc/stdio/lib_lowinstream.c
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

#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/arch.h>

#include "lib_internal.h"

#ifdef CONFIG_ARCH_LOWGETC

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lowinstream_getc
 ****************************************************************************/

static int lowinstream_getc(FAR struct lib_instream_s *this)
{
	int ret;

	DEBUGASSERT(this);

	/* Get the next character from the incoming stream */

	ret = up_getc(ch);
	if (ret != EOF) {
		this->nget++;
	}

	return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_lowinstream
 *
 * Description:
 *   Initializes a stream for use with low-level, architecture-specific I/O.
 *
 * Input parameters:
 *   lowoutstream - User allocated, uninitialized instance of struct
 *                  lib_lowoutstream_s to be initialized.
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_lowinstream(FAR struct lib_instream_s *stream)
{
	stream->get = lowinstream_getc;
	stream->nget = 0;
}

#endif							/* CONFIG_ARCH_LOWGETC */
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
 * libc/stdio/lib_lowoutstream.c
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

#ifdef CONFIG_ARCH_LOWPUTC

#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <tinyara/arch.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lowoutstream_putc
 ****************************************************************************/

static void lowoutstream_putc(FAR struct lib_outstream_s *this, int ch)
{
	DEBUGASSERT(this);
#if defined(CONFIG_BUILD_PROTECTED)
	if (putchar(ch) != EOF)
#else
	if (up_putc(ch) != EOF)
#endif
	{
		this->nput++;
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_lowoutstream
 *
 * Description:
 *   Initializes a stream for use with low-level, architecture-specific I/O.
 *
 * Input parameters:
 *   lowoutstream - User allocated, uninitialized instance of struct
 *                  lib_lowoutstream_s to be initialized.
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_lowoutstream(FAR struct lib_outstream_s *stream)
{
	stream->put = lowoutstream_putc;
#ifdef CONFIG_STDIO_LINEBUFFER
	stream->flush = lib_noflush;
#endif
	stream->nput = 0;
}

#endif							/* CONFIG_ARCH_LOWPUTC */
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
 * libc/stdio/lib_meminstream.c
 *
 *   Copyright (C) 2007-2009, 2011-2012, 2014 Gregory Nutt. All rights reserved.
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

#include <assert.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: meminstream_getc
 ****************************************************************************/

static int meminstream_getc(FAR struct lib_instream_s *this)
{
	FAR struct lib_meminstream_s *mthis = (FAR struct lib_meminstream_s *)this;
	int ret;

	DEBUGASSERT(this);

	/* Get the next character (if any) from the buffer */

	if (this->nget < mthis->buflen) {
		ret = mthis->buffer[this->nget];
		this->nget++;
	} else {
		ret = EOF;
	}

	return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_meminstream
 *
 * Description:
 *   Initializes a stream for use with a fixed-size memory buffer.
 *
 * Input parameters:
 *   instream    - User allocated, uninitialized instance of struct
 *                 lib_meminstream_s to be initialized.
 *   bufstart    - Address of the beginning of the fixed-size memory buffer
 *   buflen      - Size of the fixed-sized memory buffer in bytes
 *
 * Returned Value:
 *   None (instream initialized).
 *
 ****************************************************************************/

void lib_meminstream(FAR struct lib_meminstream_s *instream, FAR const char *bufstart, int buflen)
{
	instream->public.get = meminstream_getc;
	instream->public.nget = 0;	/* Will be buffer index */
	instream->buffer = bufstart;	/* Start of buffer */
	instream->buflen = buflen;	/* Length of the buffer */
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
 * libc/stdio/lib_memoutstream.c
 *
 *   Copyright (C) 2007-2009, 2011-2012, 2014 Gregory Nutt. All rights reserved.
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

#include <assert.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: memoutstream_putc
 ****************************************************************************/

static void memoutstream_putc(FAR struct lib_outstream_s *this, int ch)
{
	FAR struct lib_memoutstream_s *mthis = (FAR struct lib_memoutstream_s *)this;

	DEBUGASSERT(this);

	/* If this will not overrun the buffer, then write the character to the
	 * buffer.  Not that buflen was pre-decremented when the stream was
	 * created so it is okay to write past the end of the buflen by one.
	 */

	if (this->nput < mthis->buflen) {
		mthis->buffer[this->nput] = ch;
		this->nput++;
		mthis->buffer[this->nput] = '\0';
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_memoutstream
 *
 * Description:
 *   Initializes a stream for use with a fixed-size memory buffer.
 *
 * Input parameters:
 *   outstream - User allocated, uninitialized instance of struct
 *                  lib_memoutstream_s to be initialized.
 *   bufstart     - Address of the beginning of the fixed-size memory buffer
 *   buflen       - Size of the fixed-sized memory buffer in bytes
 *
 * Returned Value:
 *   None (outstream initialized).
 *
 ****************************************************************************/

void lib_memoutstream(FAR struct lib_memoutstream_s *outstream, FAR char *bufstart, int buflen)
{
	outstream->public.put = memoutstream_putc;
#ifdef CONFIG_STDIO_LINEBUFFER
	outstream->public.flush = lib_noflush;
#endif
	outstream->public.nput = 0;	/* Will be buffer index */
	outstream->buffer = bufstart;	/* Start of buffer */
	outstream->buflen = buflen - 1;	/* Save space for null terminator */
	outstream->buffer[0] = '\0';	/* Start with an empty string */
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
 * libc/stdio/lib_memsistream.c
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

#include <assert.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: memsistream_getc
 ****************************************************************************/

static int memsistream_getc(FAR struct lib_sistream_s *this)
{
	FAR struct lib_memsistream_s *mthis = (FAR struct lib_memsistream_s *)this;
	int ret;

	DEBUGASSERT(this);

	/* Get the next character (if any) from the buffer */

	if (mthis->offset < mthis->buflen) {
		ret = mthis->buffer[mthis->offset];
		mthis->offset++;
		this->nget++;
	} else {
		ret = EOF;
	}

	return ret;
}

/****************************************************************************
 * Name: memsistream_seek
 ****************************************************************************/

static off_t memsistream_seek(FAR struct lib_sistream_s *this, off_t offset, int whence)
{
	FAR struct lib_memsistream_s *mthis = (FAR struct lib_memsistream_s *)this;
	off_t newpos;

	DEBUGASSERT(this);

	switch (whence) {
	case SEEK_CUR:
		newpos = (off_t)mthis->offset + offset;
		break;

	case SEEK_SET:
		newpos = offset;
		break;

	case SEEK_END:
		newpos = (off_t)mthis->buflen + offset;
		break;

	default:
		return (off_t)ERROR;
	}

	/* Make sure that the new position is within range */

	if (newpos < 0 || newpos >= (off_t)mthis->buflen) {
		return (off_t)ERROR;
	}

	/* Return the new position */

	mthis->offset = (size_t)newpos;
	return newpos;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_memsistream
 *
 * Description:
 *   Initializes a stream for use with a fixed-size memory buffer.
 *
 * Input parameters:
 *   instream    - User allocated, uninitialized instance of struct
 *                 lib_memsistream_s to be initialized.
 *   bufstart    - Address of the beginning of the fixed-size memory buffer
 *   buflen      - Size of the fixed-sized memory buffer in bytes
 *
 * Returned Value:
 *   None (instream initialized).
 *
 ****************************************************************************/

void lib_memsistream(FAR struct lib_memsistream_s *instream, FAR const char *bufstart, int buflen)
{
	instream->public.get = memsistream_getc;
	instream->public.seek = memsistream_seek;
	instream->public.nget = 0;	/* Total number of characters read */
	instream->buffer = bufstart;	/* Start of buffer */
	instream->offset = 0;		/* Will be the buffer index */
	instream->buflen = buflen;	/* Length of the buffer */
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
 * libc/stdio/lib_memsostream.c
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

#include <assert.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: memsostream_putc
 ****************************************************************************/

static void memsostream_putc(FAR struct lib_sostream_s *this, int ch)
{
	FAR struct lib_memsostream_s *mthis = (FAR struct lib_memsostream_s *)this;

	DEBUGASSERT(this);

	/* If this will not overrun the buffer, then write the character to the
	 * buffer.  Not that buflen was pre-decremented when the stream was
	 * created so it is okay to write past the end of the buflen by one.
	 */

	if (mthis->offset < mthis->buflen) {
		mthis->buffer[mthis->offset] = ch;
		mthis->offset++;
		this->nput++;
		mthis->buffer[mthis->offset] = '\0';
	}
}

/****************************************************************************
 * Name: memsostream_seek
 ****************************************************************************/

static off_t memsostream_seek(FAR struct lib_sostream_s *this, off_t offset, int whence)
{
	FAR struct lib_memsostream_s *mthis = (FAR struct lib_memsostream_s *)this;
	off_t newpos;

	DEBUGASSERT(this);

	switch (whence) {
	case SEEK_CUR:
		newpos = (off_t)mthis->offset + offset;
		break;

	case SEEK_SET:
		newpos = offset;
		break;

	case SEEK_END:
		newpos = (off_t)mthis->buflen + offset;
		break;

	default:
		return (off_t)ERROR;
	}

	/* Make sure that the new position is within range */

	if (newpos < 0 || newpos >= (off_t)mthis->buflen) {
		return (off_t)ERROR;
	}

	/* Return the new position */

	mthis->offset = (size_t)newpos;
	return newpos;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_memsostream
 *
 * Description:
 *   Initializes a stream for use with a fixed-size memory buffer.
 *
 * Input parameters:
 *   outstream - User allocated, uninitialized instance of struct
 *                  lib_memsostream_s to be initialized.
 *   bufstart     - Address of the beginning of the fixed-size memory buffer
 *   buflen       - Size of the fixed-sized memory buffer in bytes
 *
 * Returned Value:
 *   None (outstream initialized).
 *
 ****************************************************************************/

void lib_memsostream(FAR struct lib_memsostream_s *outstream, FAR char *bufstart, int buflen)
{
	outstream->public.put = memsostream_putc;
#ifdef CONFIG_STDIO_LINEBUFFER
	outstream->public.flush = lib_snoflush;
#endif
	outstream->public.seek = memsostream_seek;
	outstream->public.nput = 0;	/* Total number of characters written */
	outstream->buffer = bufstart;	/* Start of buffer */
	outstream->offset = 0;		/* Will be the buffer index */
	outstream->buflen = buflen - 1;	/* Save space for null terminator */
	outstream->buffer[0] = '\0';	/* Start with an empty string */
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
 * libc/stdio/lib_nullinstream.c
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

#include <stdio.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static int nullinstream_getc(FAR struct lib_instream_s *this)
{
	return EOF;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_nullinstream
 *
 * Description:
 *   Initializes a NULL stream. The initialized stream will  will return only
 *   EOF.
 *
 * Input parameters:
 *   nullinstream  - User allocated, uninitialized instance of struct
 *                   lib_instream_s to be initialized.
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_nullinstream(FAR struct lib_instream_s *nullinstream)
{
	nullinstream->get = nullinstream_getc;
	nullinstream->nget = 0;
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
 * libc/stdio/lib_nulloutstream.c
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

#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static void nulloutstream_putc(FAR struct lib_outstream_s *this, int ch)
{
	DEBUGASSERT(this);
	this->nput++;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_nulloutstream
 *
 * Description:
 *   Initializes a NULL streams. The initialized stream will write all data
 *   to the bit-bucket.
 *
 * Input parameters:
 *   nulloutstream - User allocated, uninitialized instance of struct
 *                   lib_outstream_s to be initialized.
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_nulloutstream(FAR struct lib_outstream_s *nulloutstream)
{
	nulloutstream->put = nulloutstream_putc;
#ifdef CONFIG_STDIO_LINEBUFFER
	nulloutstream->flush = lib_noflush;
#endif
	nulloutstream->nput = 0;
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
 * libc/stdio/lib_perror.c
 *
 *   Copyright (C) 2012-2013 Gregory Nutt. All rights reserved.
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
#include <errno.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* POSIX requires that perror provide its output on stderr.  This option may
 * be defined, however, to provide perror output that is serialized with
 * other stdout messages.
 */

#ifdef CONFIG_LIBC_PERROR_STDOUT
#define PERROR_STREAM stdout
#else
#define PERROR_STREAM stderr
#endif

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Public Data
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
 * Name: perror
 ****************************************************************************/

void perror(FAR const char *s)
{

	/* If strerror() is not enabled, then just print the error number */

#ifdef CONFIG_LIBC_STRERROR
	(void)fprintf(PERROR_STREAM, "%s: %s\n", s, strerror(errno));
#else
	(void)fprintf(PERROR_STREAM, "%s: Error %d\n", s, errno);
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
/****************************************************************************
 * libc/stdio/lib_printf.c
 *
 *   Copyright (C) 2007-2008, 2011-2012, 2014 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>
#include <syslog.h>

#include "lib_internal.h"

#if defined(CONFIG_LOGM) && defined(CONFIG_PRINTF2LOGM)
#include <tinyara/logm.h>
#endif

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Function Prototypes
 ****************************************************************************/

/**************************************************************************
 * Global Constant Data
 **************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/**************************************************************************
 * Private Constant Data
 **************************************************************************/

/****************************************************************************
 * Private Variables
 **************************************************************************/

/****************************************************************************
 * Global Functions
 **************************************************************************/

/****************************************************************************
 * Name: printf
 **************************************************************************/

int printf(FAR const char *fmt, ...)
{
	va_list ap;
	int ret;
	va_start(ap, fmt);

#if defined(CONFIG_LOGM) && defined(CONFIG_PRINTF2LOGM)
	ret = logm_internal(LOGM_NORMAL, LOGM_UNKNOWN, LOGM_DEF_PRIORITY, fmt, ap);
#elif CONFIG_NFILE_STREAMS > 0
	ret = vfprintf(stdout, fmt, ap);
#elif CONFIG_NFILE_DESCRIPTORS > 0
	ret = vsyslog(LOG_INFO, fmt, ap);
#elif defined(CONFIG_ARCH_LOWPUTC)
	ret = lowvsyslog(LOG_INFO, fmt, ap);
#else
#ifdef CONFIG_CPP_HAVE_WARNING
#warning "printf has no data sink"
#endif
	ret = 0;
#endif
	va_end(ap);

	return ret;
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
 * libc/stdio/lib_puts.c
 *
 *   Copyright (C) 2007, 2008, 2011-2012 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>
#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Public Constant Data
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: puts
 *
 * Description:
 *   puts() writes the string s and a trailing newline to stdout.
 *
 ****************************************************************************/

int puts(FAR const char *s)
{
	FILE *stream = stdout;
	int nwritten;
	int nput = EOF;
	int ret;

	/* Write the string (the next two steps must be atomic) */

	lib_take_semaphore(stream);

	/* Write the string without its trailing '\0' */

	nwritten = fputs(s, stream);
	if (nwritten > 0) {
		/* Followed by a newline */

		char newline = '\n';
		ret = lib_fwrite(&newline, 1, stream);
		if (ret > 0) {
			nput = nwritten + 1;

			/* Flush the buffer after the newline is output. */

#ifdef CONFIG_STDIO_LINEBUFFER
			ret = lib_fflush(stream, true);
			if (ret < 0) {
				nput = EOF;
			}
#endif
		}
	}

	lib_give_semaphore(stdout);
	return nput;
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
 * libc/stdio/lib_rawinstream.c
 *
 *   Copyright (C) 2007-2009, 2011-2012, 2014 Gregory Nutt. All rights reserved.
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

#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rawinstream_getc
 ****************************************************************************/

static int rawinstream_getc(FAR struct lib_instream_s *this)
{
	FAR struct lib_rawinstream_s *rthis = (FAR struct lib_rawinstream_s *)this;
	int nwritten;
	char ch;

	DEBUGASSERT(this && rthis->fd >= 0);

	/* Attempt to read one character */

	nwritten = read(rthis->fd, &ch, 1);
	if (nwritten == 1) {
		this->nget++;
		return ch;
	}

	/* Return EOF on any failure to read from the incoming byte stream. The
	 * only expected error is EINTR meaning that the read was interrupted
	 * by a signal.  A Zero return value would indicated an end-of-file
	 * confition.
	 */

	return EOF;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_rawinstream
 *
 * Description:
 *   Initializes a stream for use with a file descriptor.
 *
 * Input parameters:
 *   instream - User allocated, uninitialized instance of struct
 *              lib_rawinstream_s to be initialized.
 *   fd       - User provided file/socket descriptor (must have been opened
 *              for the correct access).
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_rawinstream(FAR struct lib_rawinstream_s *instream, int fd)
{
	instream->public.get = rawinstream_getc;
	instream->public.nget = 0;
	instream->fd = fd;
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
 * libc/stdio/lib_rawoutstream.c
 *
 *   Copyright (C) 2007-2009, 2011-2012, 2014 Gregory Nutt. All rights reserved.
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

#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rawoutstream_putc
 ****************************************************************************/

static void rawoutstream_putc(FAR struct lib_outstream_s *this, int ch)
{
	FAR struct lib_rawoutstream_s *rthis = (FAR struct lib_rawoutstream_s *)this;
	char buffer = ch;
	int nwritten;
	int errcode;

	DEBUGASSERT(this && rthis->fd >= 0);

	/* Loop until the character is successfully transferred or until an
	 * irrecoverable error occurs.
	 */

	do {
		nwritten = write(rthis->fd, &buffer, 1);
		if (nwritten == 1) {
			this->nput++;
			return;
		}

		/* The only expected error is EINTR, meaning that the write operation
		 * was awakened by a signal.  Zero or values > 1 would not be valid
		 * return values from write().
		 */

		errcode = get_errno();
		DEBUGASSERT(nwritten < 0);
	} while (errcode == EINTR);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_rawoutstream
 *
 * Description:
 *   Initializes a stream for use with a file descriptor.
 *
 * Input parameters:
 *   outstream - User allocated, uninitialized instance of struct
 *               lib_rawoutstream_s to be initialized.
 *   fd        - User provided file/socket descriptor (must have been opened
 *               for write access).
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_rawoutstream(FAR struct lib_rawoutstream_s *outstream, int fd)
{
	outstream->public.put = rawoutstream_putc;
#ifdef CONFIG_STDIO_LINEBUFFER
	outstream->public.flush = lib_noflush;
#endif
	outstream->public.nput = 0;
	outstream->fd = fd;
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
 * libc/stdio/lib_rawsistream.c
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

#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rawsistream_getc
 ****************************************************************************/

static int rawsistream_getc(FAR struct lib_sistream_s *this)
{
	FAR struct lib_rawsistream_s *rthis = (FAR struct lib_rawsistream_s *)this;
	int nwritten;
	char ch;

	DEBUGASSERT(this && rthis->fd >= 0);

	/* Attempt to read one character */

	nwritten = read(rthis->fd, &ch, 1);
	if (nwritten == 1) {
		this->nget++;
		return ch;
	}

	/* Return EOF on any failure to read from the incoming byte stream. The
	 * only expected error is EINTR meaning that the read was interrupted
	 * by a signal.  A Zero return value would indicated an end-of-file
	 * confition.
	 */

	return EOF;
}

/****************************************************************************
 * Name: rawsistream_seek
 ****************************************************************************/

static off_t rawsistream_seek(FAR struct lib_sistream_s *this, off_t offset, int whence)
{
	FAR struct lib_rawsistream_s *mthis = (FAR struct lib_rawsistream_s *)this;

	DEBUGASSERT(this);
	return lseek(mthis->fd, offset, whence);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_rawsistream
 *
 * Description:
 *   Initializes a stream for use with a file descriptor.
 *
 * Input parameters:
 *   instream - User allocated, uninitialized instance of struct
 *              lib_rawsistream_s to be initialized.
 *   fd       - User provided file/socket descriptor (must have been opened
 *              for the correct access).
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_rawsistream(FAR struct lib_rawsistream_s *instream, int fd)
{
	instream->public.get = rawsistream_getc;
	instream->public.seek = rawsistream_seek;
	instream->public.nget = 0;
	instream->fd = fd;
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
 * libc/stdio/lib_rawsostream.c
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

#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rawsostream_putc
 ****************************************************************************/

static void rawsostream_putc(FAR struct lib_sostream_s *this, int ch)
{
	FAR struct lib_rawsostream_s *rthis = (FAR struct lib_rawsostream_s *)this;
	int nwritten;
	char buffer = ch;

	DEBUGASSERT(this && rthis->fd >= 0);

	/* Loop until the character is successfully transferred or until an
	 * irrecoverable error occurs.
	 */

	do {
		nwritten = write(rthis->fd, &buffer, 1);
		if (nwritten == 1) {
			this->nput++;
			return;
		}

		/* The only expected error is EINTR, meaning that the write operation
		 * was awakened by a signal.  Zero would not be a valid return value
		 * from write().
		 */

		DEBUGASSERT(nwritten < 0);
	} while (get_errno() == EINTR);
}

/****************************************************************************
 * Name: rawsostream_seek
 ****************************************************************************/

static off_t rawsostream_seek(FAR struct lib_sostream_s *this, off_t offset, int whence)
{
	FAR struct lib_rawsostream_s *mthis = (FAR struct lib_rawsostream_s *)this;

	DEBUGASSERT(this);
	return lseek(mthis->fd, offset, whence);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_rawsostream
 *
 * Description:
 *   Initializes a stream for use with a file descriptor.
 *
 * Input parameters:
 *   outstream - User allocated, uninitialized instance of struct
 *               lib_rawsostream_s to be initialized.
 *   fd        - User provided file/socket descriptor (must have been opened
 *               for write access).
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_rawsostream(FAR struct lib_rawsostream_s *outstream, int fd)
{
	outstream->public.put = rawsostream_putc;
#ifdef CONFIG_STDIO_LINEBUFFER
	outstream->public.flush = lib_snoflush;
#endif
	outstream->public.seek = rawsostream_seek;
	outstream->public.nput = 0;
	outstream->fd = fd;
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
 * libc/stdio/lib_rdflush.c
 *
 *   Copyright (C) 2008, 2011 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_rdflush
 *
 * Description:
 *   Flush read data from the I/O buffer and adjust the file pointer to
 *   account for the unread data
 *
 ****************************************************************************/

#if CONFIG_STDIO_BUFFER_SIZE > 0
int lib_rdflush(FAR FILE *stream)
{
	if (!stream) {
		set_errno(EBADF);
		return ERROR;
	}

	/* Get exclusive access to the stream */

	lib_take_semaphore(stream);

	/* If the buffer is currently being used for read access, then discard all
	 * of the read-ahead data.  We do not support concurrent buffered read/write
	 * access.
	 */

	if (stream->fs_bufread != stream->fs_bufstart) {
		/* Now adjust the stream pointer to account for the read-ahead data that
		 * was not actually read by the user.
		 */

#if CONFIG_NUNGET_CHARS > 0
		off_t rdoffset = stream->fs_bufread - stream->fs_bufpos + stream->fs_nungotten;
#else
		off_t rdoffset = stream->fs_bufread - stream->fs_bufpos;
#endif
		/* Mark the buffer as empty (do this before calling fseek() because fseek()
		 * also calls this function).
		 */

		stream->fs_bufpos = stream->fs_bufread = stream->fs_bufstart;
#if CONFIG_NUNGET_CHARS > 0
		stream->fs_nungotten = 0;
#endif
		/* Then seek to the position corresponding to the last data read by the user */

		if (fseek(stream, -rdoffset, SEEK_CUR) < 0) {
			lib_give_semaphore(stream);
			return ERROR;
		}
	}

	lib_give_semaphore(stream);
	return OK;
}
#endif							/* CONFIG_STDIO_BUFFER_SIZE */
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
 * libc/stdio/lib_remove.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Sebastien Lorquet <sebastien@lorquet.fr>
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

#include <sys/stat.h>
#include <unistd.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: remove
 *
 * Description:
 *   The remove() function causes the object denoted by path to be removed.
 *   The function is equivalent to unlink() or rmdir().
 *
 * Input Parmeters:
 *   path - A pointer to a file or directory to be removed.
 *
 * Returned Value:
 *   0(OK) on success; -1(ERROR) on failure with errno set appropriately:
 *
 *   For returned errno values, see unlink or rmdir.
 *
 ****************************************************************************/

int remove(FAR const char *path)
{
	struct stat buf;
	int ret;

	/* Check the kind of object pointed by path */

	ret = stat(path, &buf);
	if (ret != 0) {
		return ret;
	}

	/* Act according to the kind of object */

	if (S_ISDIR(buf.st_mode)) {
		return rmdir(path);
	} else {
		return unlink(path);
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
 * libc/stdio/lib_setbuf.c
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
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT will THE
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
#include <assert.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: setbuf
 *
 * Description:
 *   Except that it returns no value, the function call setbuf(stream, buf)
 *   is equivalent to:
 *
 *     setvbuf(stream, buf, _IOFBF, BUFFSIZ)
 *
 *   if buf is not a null pointer, or to:
 *
 *     setvbuf(stream, buf, _IONBF, BUFFSIZ)
 *
 *   if buf is a null pointer.
 *
 * Input Parameters:
 *   stream - The stream whose buffer will be modified
 *   buffer - If non-NULL, this is user allocated buffer of size BUFFSIZ. If
 *            NULL, setvbuf will disable buffering
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

#if CONFIG_STDIO_BUFFER_SIZE > 0
void setbuf(FAR FILE *stream, FAR char *buf)
{
	int mode;

	DEBUGASSERT(stream != NULL);

	mode = (buf != NULL) ? _IOFBF : _IONBF;
	(void)setvbuf(stream, buf, mode, BUFSSIZ);

}
#endif
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
 * libc/stdio/lib_setvbuf.c
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
 *   Author: Alan Carvalho de Assis <acassis@gmail.com>
 *           Gregory Nutt <gnutt@nuttx.org>
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
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT will THE
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
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <tinyara/fs/fs.h>

#include "lib_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: setvbuf
 *
 * Description:
 *   The setvbuf() function may be used after the stream pointed to by
 *   stream is associated with an open file but before any other operation
 *   (other than an unsuccessful call to setvbuf()) is performed on the
 *   stream. The argument type determines how stream will be buffered, as
 *   follows:
 *
 *   _IOFBF - Will cause input/output to be fully buffered.
 *   _IOLBF - Will cause input/output to be line buffered.
 *   _IONBF - Will cause input/output to be unbuffered.
 *
 * If buf is not a null pointer, the array it points to may be used instead
 * of a buffer allocated by setvbuf() and the argument size specifies the size
 * of the array; otherwise, size may determine the size of a buffer allocated
 * by the setvbuf() function. The contents of the array at any time are
 * unspecified.
 *
 * Input Parameters:
 *   stream - the stream to flush
 *   buffer - the user allocate buffer. If NULL, will allocates a buffer of
 *            specified size
 *   mode   - specifies a mode for file buffering
 *   size   - size of buffer
 *
 * Returned Value:
 *   Upon successful completion, setvbuf() will return 0. Otherwise, it will
 *   return a non-zero value if an invalid value is given for type or if the
 *   request cannot be honored, [CX] and may set errno to indicate the error
 *
 ****************************************************************************/

#if CONFIG_STDIO_BUFFER_SIZE > 0
int setvbuf(FAR FILE *stream, FAR char *buffer, int mode, size_t size)
{
	FAR unsigned char *newbuf;
	uint8_t flags;
	int errcode;

	/* Verify arguments */
	/* Make sure that a valid mode was provided */

	if (mode != _IOFBF && mode != _IOLBF && mode != _IONBF) {
		errcode = EINVAL;
		goto errout;
	}

	/* If a buffer pointer is provided, then it must have a non-zero size */

	if (buffer != NULL && size == 0) {
		errcode = EINVAL;
		goto errout;
	}

	/* My assumption is that if size is zero for modes {_IOFBF, _IOLBF} the
	 * caller is only attempting to change the buffering mode.  In this case,
	 * the existing buffer should be re-used (if there is one).  If there is no
	 * existing buffer, then I suppose we should allocate one of the default
	 * size?
	 */

	if ((mode == _IOFBF || mode == _IOLBF) && size == 0 && stream->fs_bufstart == NULL) {
		size = BUFSSIZ;
	}

	/* A non-zero size (or a non-NULL buffer) with mode = _IONBF makes no
	 * sense but is, apparently, permissible. We simply force the buffer to
	 * NULL and size to zero in this case without complaining.
	 */

	else if (mode == _IONBF) {
		buffer = NULL;
		size = 0;
	}

	/* Make sure that we have exclusive access to the stream */

	lib_take_semaphore(stream);

	/* setvbuf() may only be called AFTER the file has been opened and BEFORE
	 * any operations have been performed on the string.
	 */

	/* Return EBADF if the file is not open */

	if (stream->fs_fd < 0) {
		errcode = EBADF;
		goto errout_with_semaphore;
	}

	/* Return EBUSY if operations have already been performed on the buffer.
	 * Here we really only verify that there is no valid data in the existing
	 * buffer.
	 *
	 * REVIST:  There could be race conditions here, could there not?
	 */

	if (stream->fs_bufpos != stream->fs_bufstart) {
		errcode = EBUSY;
		goto errout_with_semaphore;
	}

	/* Initialize by clearing related flags.  We try to avoid any permanent
	 * changes to the stream structure until we know that we will be
	 * successful.
	 */

	flags = stream->fs_flags & ~(__FS_FLAG_LBF | __FS_FLAG_UBF);

	/* Allocate a new buffer if one is needed or reuse the existing buffer it
	 * is appropriate to do so.
	 */

	switch (mode) {
	case _IOLBF:
		flags |= __FS_FLAG_LBF;

		/* Fall through */

	case _IOFBF:
		/* Use the existing buffer if size == 0 */

		if (size > 0) {
			/* A new buffer is needed.  Did the caller provide the buffer
			 * memory?
			 */

			if (buffer != NULL) {
				newbuf = (FAR unsigned char *)buffer;

				/* Indicate that we have an I/O buffer managed by the caller of
				 * setvbuf.
				 */

				flags |= __FS_FLAG_UBF;
			} else {
				newbuf = (FAR unsigned char *)lib_malloc(size);
				if (newbuf == NULL) {
					errcode = ENOMEM;
					goto errout_with_semaphore;
				}
			}
		} else {
			/* Re-use the existing buffer and retain some existing flags.
			 * This supports changing the buffering mode without changing
			 * the buffer.
			 */

			DEBUGASSERT(stream->fs_bufstart != NULL);
			flags |= stream->fs_flags & __FS_FLAG_UBF;
			goto reuse_buffer;
		}

		break;

	case _IONBF:
		/* No buffer needed... We must be performing unbuffered I/O */

		newbuf = NULL;
		break;

	default:
		PANIC();
	}

	/* Do not release the previous buffer if it was allocated by the user
	 * on a previous call to setvbuf().
	 */

	if (stream->fs_bufstart != NULL && (stream->fs_flags & __FS_FLAG_UBF) == 0) {
		lib_free(stream->fs_bufstart);
	}

	/* Set the new buffer information */

	stream->fs_bufstart = newbuf;
	stream->fs_bufpos = newbuf;
	stream->fs_bufread = newbuf;
	stream->fs_bufend = newbuf + size;

	/* Update the stream flags and return success */

reuse_buffer:

	stream->fs_flags = flags;
	lib_give_semaphore(stream);
	return OK;

errout_with_semaphore:
	lib_give_semaphore(stream);

errout:
	set_errno(errcode);
	return ERROR;
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
 * libc/stdio/lib_snprintf.c
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

#include <sys/types.h>
#include <stdio.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * sprintf
 ****************************************************************************/

int snprintf(FAR char *buf, size_t size, const char *format, ...)
{
	union {
		struct lib_outstream_s nulloutstream;
		struct lib_memoutstream_s memoutstream;
	} u;

	FAR struct lib_outstream_s *stream;
	va_list ap;
	int n;

	/* "If the value of [size] is zero on a call to snprintf(), nothing shall
	 *  be written, the number of bytes that would have been written had [size]
	 *  been sufficiently large excluding the terminating null shall be returned,
	 *  and [buf] may be a null pointer." -- opengroup.org
	 */

	if (size > 0) {
		/* Initialize a memory stream to write to the buffer */

		lib_memoutstream(&u.memoutstream, buf, size);
		stream = &u.memoutstream.public;
	} else {
		/* Use a null stream to get the size of the buffer */

		lib_nulloutstream(&u.nulloutstream);
		stream = &u.nulloutstream;
	}

	/* Then let lib_vsprintf do the real work */

	va_start(ap, format);
	n = lib_vsprintf(stream, format, ap);
	va_end(ap);
	return n;
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
 * libc/stdio/lib_sprintf.c
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

#include <stdio.h>
#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * sprintf
 ****************************************************************************/

int sprintf(FAR char *buf, const char *fmt, ...)
{
	struct lib_memoutstream_s memoutstream;
	va_list ap;
	int n;

	/* Initialize a memory stream to write to the buffer */

	lib_memoutstream((FAR struct lib_memoutstream_s *)&memoutstream, buf, LIB_BUFLEN_UNKNOWN);

	/* Then let lib_vsprintf do the real work */

	va_start(ap, fmt);
	n = lib_vsprintf((FAR struct lib_outstream_s *)&memoutstream.public, fmt, ap);
	va_end(ap);
	return n;
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
 * libc/stdio/lib_sscanf.c
 *
 *   Copyright (C) 2007, 2008, 2011-2014 Gregory Nutt. All rights reserved.
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

#include <tinyara/compiler.h>

#include <sys/types.h>

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <debug.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define MAXLN 128

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Function Prototypes
 ****************************************************************************/

int vsscanf(FAR const char *buf, FAR const char *fmt, va_list ap);

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

static const char spaces[] = " \t\n\r\f\v";

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  findwidth
 *
 * Description:
 *    Try to figure out the width of the input data.
 *
 ****************************************************************************/

static int findwidth(FAR const char *buf, FAR const char *fmt)
{
	FAR const char *next = fmt + 1;

	/* No... is there a space after the format? Or does the format string end
	 * here?
	 */

	if (isspace(*next) || *next == 0) {
		/* Use the input up until the first white space is encountered. */

		return strcspn(buf, spaces);
	}

	/* No.. Another possibility is the format character is followed by
	 * some recognizable delimiting value.
	 */

	if (*next != '%') {
		/* If so we will say that the string ends there if we can find that
		 * delimiter in the input string.
		 */

		FAR const char *ptr = strchr(buf, *next);
		if (ptr) {
			return (int)(ptr - buf);
		}
	}

	/* No... the format has no delimiter and is back-to-back with the next
	 * format (or is followed by a delimiter that does not exist in the
	 * input string).  At this point we just bail and Use the input up until
	 * the first white space is encountered.
	 *
	 * NOTE:  This means that values from the following format may be
	 * concatenated with the first. This is a bug.  We have no generic way of
	 * determining the width of the data if there is no fieldwidth, no space
	 * separating the input, and no usable delimiter character.
	 */

	return strcspn(buf, spaces);
}

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Function:  findscanset
 *
 * Description:
 *    Fill in the given table from the scanset at the given format.
 *    Return a pointer to the character the closing ']'.
 *    The table has a 1 wherever characters should be considered part of the
 *    scanset.
 *
 *    Function findscanset based on source function __sccl of FreeBSD
 *   (https://github.com/lattera/freebsd/blob/master/sys/kern/subr_scanf.c)
 *
 ****************************************************************************/

#ifdef CONFIG_LIBC_SCANSET
static FAR const char *findscanset(FAR const char *fmt,
					FAR unsigned char set[32])
{
	int c;
	int n;
	int v;
	int i;

	fmt++;           /* Skip '[' */

	/* First `clear' the whole table */

	c = *fmt++;      /* First char hat => negated scanset */
	if (c == '^') {
		v = 1;       /* Default => accept */
		c = *fmt++;  /* Get new first char */
	} else {
		v = 0;       /* Default => reject */
	}

	memset(set, 0, 32);
	if (c == 0) {
		goto doexit;
	}

	/* Now set the entries corresponding to the actual scanset
	* to the opposite of the above.
	*
	* The first character may be ']' (or '-') without being special;
	* the last character may be '-'.
	*/

	for (;;) {
		set[c / 8] |= (1 << (c % 8));  /* Take character c */

doswitch:
		n = *fmt++;    /* Examine the next */
		switch (n) {
		case 0:      /* Format ended too soon */
		case ']':    /* End of scanset */
			goto doexit;

		case '-':
			/* A scanset of the form
			*
			*  [01+-]
			*
			* is defined as "the digit 0, the digit 1, the character +, the
			* character -", but the effect of a scanset such as
			*
			*  [a-zA-Z0-9]
			*
			* is implementation defined.  The V7 Unix scanf treats "a-z" as
			* "the letters a through z", but treats "a-a" as "the letter a,
			* the character -, and the letter a".
			*
			* For compatibility, the `-' is not considerd to define a range
			* if the character following it is either a close bracket
			* (required by ANSI) or is not numerically greater than the
			* character* we just stored in the table (c).
			*/

			n = *fmt;
			if (n == ']' || n < c) {
				c = '-';
				break;  /* Resume the for(;;) */
			}

			fmt++;
			do {
				/* Fill in the range */

				c++;
				set[c / 8] |= (1 << (c % 8));  /* Take character c */
			} while (c < n);

			/* Alas, the V7 Unix scanf also treats formats such as [a-c-e] as
			* "the letters a through e".  This too is permitted by the
			* standard.
			*/

			goto doswitch;

		default:    /* Just another character */
			c = n;
			break;
		}
	}

doexit:
	if (v) { /* Default => accept */
		for (i = 0; i < 32; i++) {  /* Invert all */
			set[i] ^= 0xFF;
		}
	}

	return (fmt - 1);
}
#endif

/****************************************************************************
 * Function:  scansetwidth
 ****************************************************************************/

#ifdef CONFIG_LIBC_SCANSET
static int scansetwidth(FAR const char *buf,
			FAR const unsigned char set[32])
{
	FAR const char *next = buf;
	int c;

	while (*next) {
		c = *next;
		if ((set[c / 8] & (1 << (c % 8))) == 0) {
			break;
		}

		next++;
	}

	return (next - buf);
}
#endif



/****************************************************************************
 * Function:  sscanf
 *
 * Description:
 *    ANSI standard sscanf implementation.
 *
 ****************************************************************************/

int sscanf(FAR const char *buf, FAR const char *fmt, ...)
{
	va_list ap;
	int count;

	va_start(ap, fmt);
	count = vsscanf((FAR const char *)buf, fmt, ap);
	va_end(ap);
	return count;
}

/****************************************************************************
 * Function:  vsscanf
 *
 * Description:
 *    ANSI standard vsscanf implementation.
 *
 ****************************************************************************/

int vsscanf(FAR const char *buf, FAR const char *fmt, va_list ap)
{
	FAR const char *bufstart;
	FAR char *tv;
	FAR const char *tc;
	bool lflag;
	bool noassign;
	int count;
	int width;
	int base = 10;
	char tmp[MAXLN];
#ifdef CONFIG_LIBC_SCANSET
	unsigned char   set[32]; /* Bit field (256 / 8) */
#endif

	lvdbg("vsscanf: buf=\"%s\" fmt=\"%s\"\n", buf, fmt);

	/* Remember the start of the input buffer.  We will need this for %n
	 * calculations.
	 */

	bufstart = buf;

	/* Parse the format, extracting values from the input buffer as needed */

	count = 0;
	width = 0;
	noassign = false;
	lflag = false;

	/* Loop until all characters in the fmt string have been processed.  We
	 * may have to continue loop after reaching the end the input data in
	 * order to handle trailing %n format specifiers.
	 */

	while (*fmt) {
		/* Skip over white space */

		while (isspace(*fmt)) {
			fmt++;
		}

		/* Check for a conversion specifier */

		if (*fmt == '%') {
			lvdbg("vsscanf: Specifier found\n");

			/* Check for qualifiers on the conversion specifier */

			fmt++;
			for (; *fmt; fmt++) {
				lvdbg("vsscanf: Processing %c\n", *fmt);
#ifdef CONFIG_LIBC_SCANSET
				if (strchr("dibouxcsefgn[%", *fmt)) {
#else
				if (strchr("dibouxcsefgn%", *fmt)) {
#endif
					break;
				}

				if (*fmt == '*') {
					noassign = true;
				} else if (*fmt == 'l' || *fmt == 'L') {
					/* NOTE: Missing check for long long ('ll') */

					lflag = true;
				} else if (*fmt >= '1' && *fmt <= '9') {
					for (tc = fmt; isdigit(*fmt); fmt++);
					strncpy(tmp, tc, fmt - tc);
					tmp[fmt - tc] = '\0';
					width = MIN(sizeof(tmp) - 1, atoi(tmp));
					fmt--;
				}
			}

			/* Process %s:  String conversion */

			if (*fmt == 's') {
				lvdbg("vsscanf: Performing string conversion\n");

				/* Get a pointer to the char * value.  We need to do this even
				 * if we have reached the end of the input data in order to
				 * update the 'ap' variable.
				 */

				tv = NULL;		/* To avoid warnings about begin uninitialized */
				if (!noassign) {
					tv = va_arg(ap, char *);
					tv[0] = '\0';
				}

				/* But we only perform the data conversion is we still have
				 * bytes remaining in the input data stream.
				 */

				if (*buf) {
					/* Skip over white space */

					while (isspace(*buf)) {
						buf++;
					}

					/* Was a fieldwidth specified? */

					if (!width) {
						/* No... Guess a field width using some heuristics */

						int tmpwidth = findwidth(buf, fmt);
						width = MIN(sizeof(tmp) - 1, tmpwidth);
					}

					/* Copy the string (if we are making an assignment) */

					if (!noassign) {
						strncpy(tv, buf, width);
						tv[width] = '\0';
						count++;
					}

					/* Update the buffer pointer past the string in the input */

					buf += width;
				}
			}

#ifdef CONFIG_LIBC_SCANSET
			/* Process %[:  Scanset conversion */

			if (*fmt == '[') {
				lvdbg("vsscanf: Performing scanset conversion\n");

				fmt = findscanset(fmt, set); /* find scanset */

				/* Get a pointer to the char * value.  We need to do this even
				* if we have reached the end of the input data in order to
				* update the 'ap' variable.
				*/

				tv = NULL;      /* To avoid warnings about begin uninitialized */
				if (!noassign) {
					tv    = va_arg(ap, FAR char *);
					tv[0] = '\0';
				}

				/* But we only perform the data conversion is we still have
				* bytes remaining in the input data stream.
				*/

				if (*buf) {
					/* Skip over white space */

					while (isspace(*buf)) {
						buf++;
					}

					/* Guess a field width using some heuristics */

					int fwidth = scansetwidth(buf, set);

					/* Use the actual field's width if 1) no fieldwidth
					* specified or 2) the actual field's width is smaller
					* than fieldwidth specified
					*/

					if (!width || fwidth < width) {
						width  = fwidth;
					}

					width = MIN(sizeof(tmp) - 1, width);

					/* Copy the string (if we are making an assignment) */

					if (!noassign) {
						strncpy(tv, buf, width);
						tv[width] = '\0';
						count++;
					}

					/* Update the buffer pointer past the string in the input */

					buf += width;
				}
			}
#endif

			/* Process %c:  Character conversion */

			else if (*fmt == 'c') {
				lvdbg("vsscanf: Performing character conversion\n");

				/* Get a pointer to the char * value.  We need to do this even
				 * if we have reached the end of the input data in order to
				 * update the 'ap' variable.
				 */

				tv = NULL;		/* To avoid warnings about beign uninitialized */
				if (!noassign) {
					tv = va_arg(ap, char *);
					tv[0] = '\0';
				}

				/* But we only perform the data conversion is we still have
				 * bytes remaining in the input data stream.
				 */

				if (*buf) {
					/* Was a field width specified? */

					if (!width) {
						/* No, then width is this one single character */

						width = 1;
					}

					/* Copy the character(s) (if we are making an assignment) */

					if (!noassign) {
						strncpy(tv, buf, width);
						tv[width] = '\0';
						count++;
					}

					/* Update the buffer pointer past the character(s) in the
					 * input
					 */

					buf += width;
				}
			}

			/* Process %d, %o, %b, %x, %u:  Various integer conversions */

			else if (strchr("dobxu", *fmt)) {
				FAR long *plong = NULL;
				FAR int *pint = NULL;
				bool sign;

				lvdbg("vsscanf: Performing integer conversion\n");

				/* Get a pointer to the integer value.  We need to do this even
				 * if we have reached the end of the input data in order to
				 * update the 'ap' variable.
				 */

				if (!noassign) {
					/* We have to check whether we need to return a long or an
					 * int.
					 */

					if (lflag) {
						plong = va_arg(ap, long *);
						*plong = 0;
					} else {
						pint = va_arg(ap, int *);
						*pint = 0;
					}
				}

				/* But we only perform the data conversion if we still have
				 * bytes remaining in the input data stream.
				 */

				if (*buf) {
					FAR char *endptr;
					int errsave;
					long tmplong;

					/* Skip over any white space before the integer string */

					while (isspace(*buf)) {
						buf++;
					}

					/* The base of the integer conversion depends on the
					 * specific conversion specification.
					 */

					sign = false;
					switch (*fmt) {
					default:
					case 'd':
						sign = true;

					/* FALLTHROUGH */

					case 'u':
						base = 10;
						break;

					case 'X':
					case 'x':
						base = 16;
						break;

					case 'o':
						base = 8;
						break;

					case 'b':
						base = 2;
						break;
					}

					/* Was a field width specified? */

					if (!width) {
						/* No... Guess a field width using some heuristics */

						int tmpwidth = findwidth(buf, fmt);
						width = MIN(sizeof(tmp) - 1, tmpwidth);
					}

					/* Copy the numeric string into a temporary working
					 * buffer.
					 */

					strncpy(tmp, buf, width);
					tmp[width] = '\0';

					lvdbg("vsscanf: tmp[]=\"%s\"\n", tmp);

					/* Perform the integer conversion */
					/* Preserve the errno value */

					errsave = get_errno();
					set_errno(0);
					if (sign) {
						tmplong = strtol(tmp, &endptr, base);
					} else {
						tmplong = strtoul(tmp, &endptr, base);
					}

					/* Check if the number was successfully converted */

					if (tmp == endptr || get_errno() == ERANGE) {
						return count;
					}

					/* Move by the actual number of characters converted */

					buf += (endptr - tmp);
					set_errno(errsave);
					if (!noassign) {

						/* We have to check whether we need to return a long
						 * or an int.
						 */

						if (lflag) {
							lvdbg("vsscanf: Return %ld to 0x%p\n", tmplong, plong);
							*plong = tmplong;
						} else {
							lvdbg("vsscanf: Return %ld to 0x%p\n", tmplong, pint);
							*pint = (int)tmplong;
						}

						count++;
					}
				}
			}

			/* Process %f:  Floating point conversion */

			else if (*fmt == 'f' || *fmt == 'F') {
#ifdef CONFIG_HAVE_DOUBLE
				FAR double_t *pd = NULL;
#endif
				FAR float *pf = NULL;

				lvdbg("vsscanf: Performing floating point conversion\n");

				/* Get a pointer to the double value.  We need to do this even
				 * if we have reached the end of the input data in order to
				 * update the 'ap' variable.
				 */

				if (!noassign) {
					/* We have to check whether we need to return a float or a
					 * double.
					 */

#ifdef CONFIG_HAVE_DOUBLE
					if (lflag) {
						pd = va_arg(ap, double_t *);
						*pd = 0.0;
					} else
#endif
					{
						pf = va_arg(ap, float *);
						*pf = 0.0;
					}
				}
#ifdef CONFIG_LIBC_FLOATINGPOINT
				/* But we only perform the data conversion is we still have
				 * bytes remaining in the input data stream.
				 */

				if (*buf) {
					/* Skip over any white space before the real string */

					while (isspace(*buf)) {
						buf++;
					}

					/* Was a fieldwidth specified? */

					if (!width) {
						/* No... Lets calculate the width */

						while (isdigit(*(buf + width)) || *(buf + width) == '.') {
							width++;
						}
					}

					/* Copy the real string into a temporary working buffer. */

					strncpy(tmp, buf, width);
					tmp[width] = '\0';
					buf += width;

					lvdbg("vsscanf: tmp[]=\"%s\"\n", tmp);

					/* Perform the floating point conversion */

					if (!noassign) {
						/* strtod always returns a double */

						FAR char *endptr;
						int errsave;
						double_t dvalue;

						/* Preserve the errno value */

						errsave = get_errno();
						set_errno(0);
						dvalue = strtod(tmp, &endptr);

						/* Check if the number was successfully converted */

						if (tmp == endptr || get_errno() == ERANGE) {
							return count;
						}

						set_errno(errsave);

						/* We have to check whether we need to return a float
						 * or a double.
						 */

#ifdef CONFIG_HAVE_DOUBLE
						if (lflag) {
							lvdbg("vsscanf: Return %f to %p\n", dvalue, pd);
							*pd = dvalue;
						} else
#endif
						{
							lvdbg("vsscanf: Return %f to %p\n", dvalue, pf);
							*pf = (float)dvalue;
						}

						count++;
					}
				}
#endif
			}

			/* Process %n:  Character count */

			else if (*fmt == 'n') {
				lvdbg("vsscanf: Performing character count\n");

				if (!noassign) {
					size_t nchars = (size_t)(buf - bufstart);

					/* Note %n does not count as a conversion */

					if (lflag) {
						FAR long *plong = va_arg(ap, long *);
						*plong = (long)nchars;
					} else {
						FAR int *pint = va_arg(ap, int *);
						*pint = (int)nchars;
					}
				}
			}

			width = 0;
			noassign = false;
			lflag = false;

			fmt++;
		}

		/* It is not a conversion specifier */

		else if (*buf) {
			/* Skip over any leading spaces in the input buffer */

			while (isspace(*buf)) {
				buf++;
			}

			/* Skip over matching characters in the buffer and format */

			if (*fmt != *buf) {
				break;
			} else {
				fmt++;
				buf++;
			}
		} else {
			/* NULL terminator encountered */

			break;
		}
	}

	/* sscanf is required to return EOF if the input ends before the first
	 * matching failure or conversion.
	 */

	return count ? count : EOF;
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
 * libc/stdio/lib_stdinstream.c
 *
 *   Copyright (C) 2007-2009, 2011-2012, 2014 Gregory Nutt. All rights reserved.
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

#include <assert.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stdinstream_getc
 ****************************************************************************/

static int stdinstream_getc(FAR struct lib_instream_s *this)
{
	FAR struct lib_stdinstream_s *sthis = (FAR struct lib_stdinstream_s *)this;
	int ret;

	DEBUGASSERT(this);

	/* Get the next character from the incoming stream */

	ret = getc(sthis->stream);
	if (ret != EOF) {
		this->nget++;
	}

	return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_stdinstream
 *
 * Description:
 *   Initializes a stream for use with a FILE instance.
 *
 * Input parameters:
 *   instream - User allocated, uninitialized instance of struct
 *              lib_stdinstream_s to be initialized.
 *   stream   - User provided stream instance (must have been opened for
 *              read access).
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_stdinstream(FAR struct lib_stdinstream_s *instream, FAR FILE *stream)
{
	instream->public.get = stdinstream_getc;
	instream->public.nget = 0;
	instream->stream = stream;
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
 * libc/stdio/lib_stdoutstream.c
 *
 *   Copyright (C) 2007-2009, 2011-2012, 2014 Gregory Nutt. All rights reserved.
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

#include <fcntl.h>
#include <assert.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stdoutstream_putc
 ****************************************************************************/

static void stdoutstream_putc(FAR struct lib_outstream_s *this, int ch)
{
	FAR struct lib_stdoutstream_s *sthis = (FAR struct lib_stdoutstream_s *)this;
	int result;

	DEBUGASSERT(this && sthis->stream);

	/* Loop until the character is successfully transferred or an irrecoverable
	 * error occurs.
	 */

	do {
		result = fputc(ch, sthis->stream);
		if (result != EOF) {
			this->nput++;
			return;
		}

		/* EINTR (meaning that fputc was interrupted by a signal) is the only
		 * recoverable error.
		 */
	} while (get_errno() == EINTR);
}

/****************************************************************************
 * Name: stdoutstream_flush
 ****************************************************************************/

#if defined(CONFIG_STDIO_LINEBUFFER) && CONFIG_STDIO_BUFFER_SIZE > 0
static int stdoutstream_flush(FAR struct lib_outstream_s *this)
{
	FAR struct lib_stdoutstream_s *sthis = (FAR struct lib_stdoutstream_s *)this;
	return lib_fflush(sthis->stream, true);
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_stdoutstream
 *
 * Description:
 *   Initializes a stream for use with a FILE instance.
 *
 * Input parameters:
 *   outstream - User allocated, uninitialized instance of struct
 *               lib_stdoutstream_s to be initialized.
 *   stream    - User provided stream instance (must have been opened for
 *               write access).
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_stdoutstream(FAR struct lib_stdoutstream_s *outstream, FAR FILE *stream)
{
	/* Select the put operation */

	outstream->public.put = stdoutstream_putc;

	/* Select the correct flush operation.  This flush is only called when
	 * a newline is encountered in the output stream.  However, we do not
	 * want to support this line buffering behavior if the stream was
	 * opened in binary mode.  In binary mode, the newline has no special
	 * meaning.
	 */

#ifdef CONFIG_STDIO_LINEBUFFER
#if CONFIG_STDIO_BUFFER_SIZE > 0
	if ((stream->fs_oflags & O_BINARY) == 0) {
		outstream->public.flush = stdoutstream_flush;
	} else
#endif
	{
		outstream->public.flush = lib_noflush;
	}
#endif

	/* Set the number of bytes put to zero and remember the stream */

	outstream->public.nput = 0;
	outstream->stream = stream;
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
 * libc/stdio/lib_stdsistream.c
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

#include <assert.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stdsistream_getc
 ****************************************************************************/

static int stdsistream_getc(FAR struct lib_sistream_s *this)
{
	FAR struct lib_stdsistream_s *sthis = (FAR struct lib_stdsistream_s *)this;
	int ret;

	DEBUGASSERT(this);

	/* Get the next character from the incoming stream */

	ret = getc(sthis->stream);
	if (ret != EOF) {
		this->nget++;
	}

	return ret;
}

/****************************************************************************
 * Name: stdsistream_seek
 ****************************************************************************/

static off_t stdsistream_seek(FAR struct lib_sistream_s *this, off_t offset, int whence)
{
	FAR struct lib_stdsistream_s *mthis = (FAR struct lib_stdsistream_s *)this;

	DEBUGASSERT(this);
	return fseek(mthis->stream, offset, whence);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_stdsistream
 *
 * Description:
 *   Initializes a stream for use with a FILE instance.
 *
 * Input parameters:
 *   instream - User allocated, uninitialized instance of struct
 *              lib_stdsistream_s to be initialized.
 *   stream   - User provided stream instance (must have been opened for
 *              read access).
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_stdsistream(FAR struct lib_stdsistream_s *instream, FAR FILE *stream)
{
	instream->public.get = stdsistream_getc;
	instream->public.seek = stdsistream_seek;
	instream->public.nget = 0;
	instream->stream = stream;
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
 * libc/stdio/lib_stdsostream.c
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

#include <fcntl.h>
#include <assert.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stdsostream_putc
 ****************************************************************************/

static void stdsostream_putc(FAR struct lib_sostream_s *this, int ch)
{
	FAR struct lib_stdsostream_s *sthis = (FAR struct lib_stdsostream_s *)this;
	int result;

	DEBUGASSERT(this && sthis->stream);

	/* Loop until the character is successfully transferred or an irrecoverable
	 * error occurs.
	 */

	do {
		result = fputc(ch, sthis->stream);
		if (result != EOF) {
			this->nput++;
			return;
		}

		/* EINTR (meaning that fputc was interrupted by a signal) is the only
		 * recoverable error.
		 */
	} while (get_errno() == EINTR);
}

/****************************************************************************
 * Name: stdsostream_flush
 ****************************************************************************/

#if defined(CONFIG_STDIO_LINEBUFFER) && CONFIG_STDIO_BUFFER_SIZE > 0
static int stdsostream_flush(FAR struct lib_sostream_s *this)
{
	FAR struct lib_stdsostream_s *sthis = (FAR struct lib_stdsostream_s *)this;
	return lib_fflush(sthis->stream, true);
}
#endif

/****************************************************************************
 * Name: stdsostream_seek
 ****************************************************************************/

static off_t stdsostream_seek(FAR struct lib_sostream_s *this, off_t offset, int whence)
{
	FAR struct lib_stdsostream_s *mthis = (FAR struct lib_stdsostream_s *)this;

	DEBUGASSERT(this);
	return fseek(mthis->stream, offset, whence);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_stdsostream
 *
 * Description:
 *   Initializes a stream for use with a FILE instance.
 *
 * Input parameters:
 *   outstream - User allocated, uninitialized instance of struct
 *               lib_stdsostream_s to be initialized.
 *   stream    - User provided stream instance (must have been opened for
 *               write access).
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_stdsostream(FAR struct lib_stdsostream_s *outstream, FAR FILE *stream)
{
	/* Select the put operation */

	outstream->public.put = stdsostream_putc;

	/* Select the correct flush operation.  This flush is only called when
	 * a newline is encountered in the output stream.  However, we do not
	 * want to support this line buffering behavior if the stream was
	 * opened in binary mode.  In binary mode, the newline has no special
	 * meaning.
	 */

#ifdef CONFIG_STDIO_LINEBUFFER
#if CONFIG_STDIO_BUFFER_SIZE > 0
	if ((stream->fs_oflags & O_BINARY) == 0) {
		outstream->public.flush = stdsostream_flush;
	} else
#endif
	{
		outstream->public.flush = lib_snoflush;
	}
#endif

	/* Select the seek operation */

	outstream->public.seek = stdsostream_seek;

	/* Set the number of bytes put to zero and remember the stream */

	outstream->public.nput = 0;
	outstream->stream = stream;
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
 * libc/stdio/lib_tempnam.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: tempnam
 *
 * Description:
 *   The tempnam() function generates a pathname that may be used for a
 *   temporary file.
 *
 *   The tempnam() function allows the user to control the choice of a
 *   directory. The dir argument points to the name of the directory in which
 *   the file is to be created. If dir is a null pointer or points to a
 *   string which is not a name for an appropriate directory, the path prefix
 *   defined as P_tmpdir in the <stdio.h> header will be used. If that
 *   directory is not accessible, an implementation-defined directory may be
 *   used.
 *
 *   Many applications prefer their temporary files to have certain initial
 *   letter sequences in their names. The pfx argument should be used for
 *   this. This argument may be a null pointer or point to a string of up
 *   to five bytes to be used as the beginning of the filename.
 *
 * Returned Value:
 *   Upon successful completion, tempnam() will allocate space for a string
 *   put the generated pathname in that space, and return a pointer to it.
 *   The pointer will be suitable for use in a subsequent call to free().
 *   Otherwise, it will return a null pointer and set errno to indicate the
 *   error.
 *
 *   The tempnam() function will fail if:
 *     ENOMEM - Insufficient storage space is available.
 *
 ****************************************************************************/

FAR char *tempnam(FAR const char *dir, FAR const char *pfx)
{
	FAR char *path;
	char *ret;

	if (!dir) {
		dir = P_tmpdir;
	}

	if (!pfx) {
		asprintf(&path, "%s/XXXXXX", dir);
	} else {
		asprintf(&path, "%s/%.5sXXXXXX", dir, pfx);
	}

	if (path) {
		ret = mktemp(path);
		if (strncmp(ret, "", 1)) {
			return path;
		}

		free(path);
	}

	set_errno(ENOMEM);
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
 * libc/stdio/lib_tmpnam.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: tmpnam
 *
 * Description:
 *   The tmpnam() function generates a string that is a valid filename and
 *   that is not the same as the name of an existing file. The function is
 *   potentially capable of generating TMP_MAX different strings, but any or
 *   all of them may already be in use by existing files and thus not be
 *   suitable return values.
 *
 *   The tmpnam() function generates a different string each time it is
 *   called from the same process, up to {TMP_MAX} times. If it is called
 *   more than {TMP_MAX} times, the behavior is implementation-defined.
 *
 * Returned Value:
 *   Upon successful completion, tmpnam() returns a pointer to a string. I
 *   no suitable string can be generated, the tmpnam() function will
 *   return a null pointer.
 *
 *   If the argument s is a null pointer, tmpnam() will leave its result
 *   in an internal static object and return a pointer to that object.
 *   Subsequent calls to tmpnam() may modify the same object. If the
 *   argument s is not a null pointer, it is presumed to point to an
 *   array of at least L_tmpnam chars; tmpnam() will write its result in
 *   that array and will return the argument as its value.
 *
 ****************************************************************************/

FAR char *tmpnam(FAR char *s)
{
	static char path[L_tmpnam];
	char *ret;

	if (s == NULL) {
		s = path;
	}

	(void)snprintf(s, L_tmpnam, "%s/XXXXXX", P_tmpdir);
	ret = mktemp(s);
	return (strncmp(ret, "", 1)) ? s : NULL;
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
 * libc/stdio/lib_ungetc.c
 *
 *   Copyright (C) 2007, 2008, 2011, 2013 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <tinyara/fs/fs.h>
#include "lib_internal.h"

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Function Prototypes
 ****************************************************************************/

/**************************************************************************
 * Global Constant Data
 **************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/**************************************************************************
 * Private Constant Data
 **************************************************************************/

/****************************************************************************
 * Private Variables
 **************************************************************************/

/****************************************************************************
 * Public Functions
 **************************************************************************/

/****************************************************************************
 * Name: ungetc
 **************************************************************************/

int ungetc(int c, FAR FILE *stream)
{
#if CONFIG_NUNGET_CHARS > 0
	int nungotten;
#endif

	/* Stream must be open for read access */

	if (!stream || stream->fs_fd < 0 || (stream->fs_oflags & O_RDOK) == 0) {
		set_errno(EBADF);
		return EOF;
	}
#if CONFIG_NUNGET_CHARS > 0
	nungotten = stream->fs_nungotten;
	if (stream->fs_nungotten < CONFIG_NUNGET_CHARS) {
		stream->fs_ungotten[nungotten] = c;
		stream->fs_nungotten = nungotten + 1;
		return c;
	} else
#endif
	{
		set_errno(ENOMEM);
		return EOF;
	}
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
 * libc/stdio/lib_vasprintf.c
 *
 *   Copyright (C) 2011-2012 Gregory Nutt. All rights reserved.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* On some architectures, va_list is really a pointer to a structure on the
 * stack.  And the va_arg builtin will modify that instance of va_list.  Since
 * vasprintf traverse the parameters in the va_list twice, the va_list will
 * be altered in this first cases and the second usage will fail.  So far, I
 * have seen this only on the X86 family with GCC.
 */

#undef CLONE_APLIST
#define ap1 ap
#define ap2 ap

#if defined(CONFIG_ARCH_X86)
#define CLONE_APLIST 1
#undef ap2
#elif defined(CONFIG_ARCH_SIM) && (defined(CONFIG_HOST_X86) || defined(CONFIG_HOST_X86_64))
#define CLONE_APLIST 1
#undef ap2
#endif

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: vasprintf
 *
 * Description:
 *   This function is similar to vsprintf, except that it dynamically
 *   allocates a string (as with malloc) to hold the output, instead of
 *   putting the output in a buffer you allocate in advance.  The ptr
 *   argument should be the address of a char * object, and a successful
 *   call to vasprintf stores a pointer to the newly allocated string at that
 *   location.
 *
 * Returned Value:
 *   The returned value is the number of characters allocated for the buffer,
 *   or less than zero if an error occurred. Usually this means that the buffer
 *   could not be allocated.
 *
 ****************************************************************************/

int vasprintf(FAR char **ptr, const char *fmt, va_list ap)
{
	struct lib_outstream_s nulloutstream;
	struct lib_memoutstream_s memoutstream;
#ifdef CLONE_APLIST
	va_list ap2;
#endif
	FAR char *buf;
	int nbytes;

	DEBUGASSERT(ptr && fmt);

#ifdef CLONE_APLIST
	/* Clone the va_list so that the contents of the input values are not altered */

	va_copy(ap2, ap);
#endif

	/* First, use a nullstream to get the size of the buffer.  The number
	 * of bytes returned may or may not include the null terminator.
	 */

	lib_nulloutstream(&nulloutstream);
	lib_vsprintf((FAR struct lib_outstream_s *)&nulloutstream, fmt, ap1);

	/* Then allocate a buffer to hold that number of characters, adding one
	 * for the null terminator.
	 */

	buf = (FAR char *)malloc(nulloutstream.nput + 1);
	if (!buf) {
		return ERROR;
	}

	/* Initialize a memory stream to write into the allocated buffer.  The
	 * memory stream will reserve one byte at the end of the buffer for the
	 * null terminator and will not report this in the number of output bytes.
	 */

	lib_memoutstream((FAR struct lib_memoutstream_s *)&memoutstream, buf, nulloutstream.nput + 1);

	/* Then let lib_vsprintf do it's real thing */

	nbytes = lib_vsprintf((FAR struct lib_outstream_s *)&memoutstream.public, fmt, ap2);

	/* Return a pointer to the string to the caller.  NOTE: the memstream put()
	 * method has already added the NUL terminator to the end of the string (not
	 * included in the nput count).
	 *
	 * Hmmm.. looks like the memory would be stranded if lib_vsprintf() returned
	 * an error.  Does that ever happen?
	 */

	DEBUGASSERT(nbytes < 0 || nbytes == nulloutstream.nput);
	*ptr = buf;
	return nbytes;
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
 * libc/stdio/lib_vdprintf.c
 *
 *   Copyright (C) 2012 Andrew Tridgell. All rights reserved.
 *   Authors: Author: Andrew Tridgell <andrew@tridgell.net>
 *            Gregory Nutt <gnutt@nuttx.org>
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

#include "lib_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int vdprintf(int fd, FAR const char *fmt, va_list ap)
{
	struct lib_rawoutstream_s rawoutstream;

	/* Wrap the fd in a stream object and let lib_vsprintf do the work. */

	lib_rawoutstream(&rawoutstream, fd);
	return lib_vsprintf(&rawoutstream.public, fmt, ap);
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
 * libc/stdio/lib_vfprintf.c
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

#include <stdio.h>
#include <semaphore.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int vfprintf(FAR FILE *stream, FAR const char *fmt, va_list ap)
{
	struct lib_stdoutstream_s stdoutstream;
	int n = ERROR;

	if (stream) {
		/* Wrap the stream in a stream object and let lib_vsprintf
		 * do the work.
		 */

		lib_stdoutstream(&stdoutstream, stream);

		/* Hold the stream semaphore throughout the lib_vsprintf
		 * call so that this thread can get its entire message out
		 * before being pre-empted by the next thread.
		 */

		lib_take_semaphore(stream);
		n = lib_vsprintf(&stdoutstream.public, fmt, ap);
		lib_give_semaphore(stream);
	}

	return n;
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
 * libc/stdio/lib_vprintf.c
 *
 *   Copyright (C) 2007, 2008, 2011 Gregory Nutt. All rights reserved.
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>

/****************************************************************************
 * Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Function Prototypes
 ****************************************************************************/

/**************************************************************************
 * Global Constant Data
 **************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/**************************************************************************
 * Private Constant Data
 **************************************************************************/

/****************************************************************************
 * Private Variables
 **************************************************************************/

/****************************************************************************
 * Public Functions
 **************************************************************************/

/****************************************************************************
 * Name: vprintf
 **************************************************************************/

int vprintf(FAR const char *fmt, va_list ap)
{
	/* vfprintf into stdout */

	return vfprintf(stdout, fmt, ap);
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
 * libc/stdio/lib_vsnprintf.c
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
#include <stdio.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: vsnprintf
 ****************************************************************************/

int vsnprintf(FAR char *buf, size_t size, const char *format, va_list ap)
{
	union {
		struct lib_outstream_s nulloutstream;
		struct lib_memoutstream_s memoutstream;
	} u;

	FAR struct lib_outstream_s *stream;
	int n;

	/* "If the value of [size] is zero on a call to vsnprintf(), nothing shall
	 *  be written, the number of bytes that would have been written had [size]
	 *  been sufficiently large excluding the terminating null shall be returned,
	 *  and [buf] may be a null pointer."
	 */

	if (size > 0) {
		/* Initialize a memory stream to write to the buffer */

		lib_memoutstream(&u.memoutstream, buf, size);
		stream = &u.memoutstream.public;
	} else {
		/* Use a null stream to get the size of the buffer */

		lib_nulloutstream(&u.nulloutstream);
		stream = &u.nulloutstream;
	}

	/* Then let lib_vsprintf do the real work */

	n = lib_vsprintf(stream, format, ap);
	return n;
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
 * libc/stdio/lib_vsprintf.c
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

#include <stdio.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: vsprintf
 ****************************************************************************/

int vsprintf(FAR char *dest, const char *src, va_list ap)
{
	struct lib_memoutstream_s memoutstream;

	/* Wrap the destination buffer in a stream object and let
	 * libc/stdio/lib_vsprintf do the work.
	 */

	lib_memoutstream((FAR struct lib_memoutstream_s *)&memoutstream, dest, LIB_BUFLEN_UNKNOWN);
	return lib_vsprintf((FAR struct lib_outstream_s *)&memoutstream.public, src, ap);
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
 * libc/stdio/lib_wrflush.c
 *
 *   Copyright (C) 2008-2009, 2011-2012 Gregory Nutt. All rights reserved.
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
#include <fcntl.h>
#include <errno.h>

#include "lib_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Declarations
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Global Constant Data
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Constant Data
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_wrflush
 *
 * Description:
 *   This is simply a version of fflush that does not report an error if
 *   the file is not open for writing.
 *
 ****************************************************************************/

int lib_wrflush(FAR FILE *stream)
{
#if CONFIG_STDIO_BUFFER_SIZE > 0
	/* Verify that we were passed a valid (i.e., non-NULL) stream */

#ifdef CONFIG_DEBUG
	if (!stream) {
		return -EINVAL;
	}
#endif

	/* Verify that the stream is opened for writing... lib_fflush will
	 * return an error if it is called for a stream that is not opened for
	 * writing.  Check that first so that this function will not fail in
	 * that case.
	 */

	if ((stream->fs_oflags & O_WROK) == 0) {
		/* Report that the success was successful if we attempt to flush a
		 * read-only stream.
		 */

		return OK;
	}

	/* Flush the stream.   Return success if there is no buffered write data
	 * -- i.e., that the stream is opened for writing and  that all of the
	 * buffered write data was successfully flushed by lib_fflush().
	 */

	return lib_fflush(stream, true);
#else
	/* Verify that we were passed a valid (i.e., non-NULL) stream */

#ifdef CONFIG_DEBUG
	if (!stream) {
		return -EINVAL;
	}
#endif

	return OK;
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
/****************************************************************************
 * libc/stdio/lib_zeroinstream.c
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

#include <stdio.h>
#include <errno.h>
#include "lib_internal.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static int zeroinstream_getc(FAR struct lib_instream_s *this)
{
	this->nget++;
	return 0;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_zeroinstream
 *
 * Description:
 *   Initializes a NULL stream.  The initialized stream will return an
 *   infinitely long stream of zeroes.
 *
 * Input parameters:
 *   zeroinstream  - User allocated, uninitialized instance of struct
 *                   lib_instream_s to be initialized.
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_zeroinstream(FAR struct lib_instream_s *zeroinstream)
{
	zeroinstream->get = zeroinstream_getc;
	zeroinstream->nget = 0;
}
   