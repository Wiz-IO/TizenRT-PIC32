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
 * libc/fixedmath/lib_b16atan2.c
 *
 *   Copyright (C) 2011 Gregory Nutt. All rights reserved.
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

#include <fixedmath.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define B16_C1     0x00000373	/* 0.013480470 */
#define B16_C2     0x00000eb7	/* 0.057477314 */
#define B16_C3     0x00001f0a	/* 0.121239071 */
#define B16_C4     0x00003215	/* 0.195635925 */
#define B16_C5     0x0000553f	/* 0.332994597 */
#define B16_C6     0x00010000	/* 0.999995630 */
#define B16_HALFPI 0x00019220	/* 1.570796327 */
#define B16_PI     0x00032440	/* 3.141592654 */

#ifndef MAX
#define MAX(a, b) (a > b ? a : b)
#endif

#ifndef MIN
#define MIN(a, b) (a < b ? a : b)
#endif

#ifndef ABS
#define ABS(a)   (a < 0 ? -a : a)
#endif

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: b16atan2
 *
 * Description:
 *   atan2 calculates the arctangent of y/x.  (Based on a algorithm I saw
 *   posted on the internet... now I have lost the link -- sorry).
 *
 ****************************************************************************/

b16_t b16atan2(b16_t y, b16_t x)
{
	b16_t t0;
	b16_t t1;
	b16_t t2;
	b16_t t3;

	t2 = ABS(x);
	t1 = ABS(y);
	t0 = MAX(t2, t1);
	t1 = MIN(t2, t1);
	t2 = ub16inv(t0);
	t2 = b16mulb16(t1, t2);

	t3 = b16mulb16(t2, t2);
	t0 = -B16_C1;
	t0 = b16mulb16(t0, t3) + B16_C2;
	t0 = b16mulb16(t0, t3) - B16_C3;
	t0 = b16mulb16(t0, t3) + B16_C4;
	t0 = b16mulb16(t0, t3) - B16_C5;
	t0 = b16mulb16(t0, t3) + B16_C6;
	t2 = b16mulb16(t0, t2);

	t2 = (ABS(y) > ABS(x)) ? B16_HALFPI - t2 : t2;
	t2 = (x < 0) ? B16_PI - t2 : t2;
	t2 = (y < 0) ? -t2 : t2;

	return t2;
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
 * libc/fixedmath/lib_b16cos.c
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
 * Included Files
 ****************************************************************************/

#include <fixedmath.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: b16cos
 ****************************************************************************/

b16_t b16cos(b16_t rad)
{
	/* Compute cosine: sin(rad + PI/2) = cos(rad) */

	rad += b16HALFPI;
	if (rad > b16PI) {
		rad -= b16TWOPI;
	}
	return b16sin(rad);
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
 * libc/fixedmath/lib_b16sin.c
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
 * Included Files
 ****************************************************************************/

#include <fixedmath.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define b16_P225       0x0000399a
#define b16_P405284735 0x000067c1
#define b16_1P27323954 0x000145f3

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: b16sin
 * Ref: http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/
 ****************************************************************************/

b16_t b16sin(b16_t rad)
{
	b16_t tmp1;
	b16_t tmp2;
	b16_t tmp3;

	/* Force angle into the good range */

	if (rad < -b16PI) {
		rad += b16TWOPI;
	} else if (rad > b16PI) {
		rad -= b16TWOPI;
	}

	/* tmp1 = 1.27323954 * rad
	 * tmp2 = .405284735 * rad * rad
	 */

	tmp1 = b16mulb16(b16_1P27323954, rad);
	tmp2 = b16mulb16(b16_P405284735, b16sqr(rad));

	if (rad < 0) {
		/* tmp3 = 1.27323954 * rad + .405284735 * rad * rad */

		tmp3 = tmp1 + tmp2;
	} else {
		/* tmp3 = 1.27323954 * rad - 0.405284735 * rad * rad */

		tmp3 = tmp1 - tmp2;
	}

	/* tmp1 = tmp3*tmp3 */

	tmp1 = b16sqr(tmp3);
	if (tmp3 < 0) {
		/* tmp1 = tmp3 * -tmp3 */

		tmp1 = -tmp1;
	}

	/* Return sin = .225 * (tmp3 * (+/-tmp3) - tmp3) + tmp3 */

	return b16mulb16(b16_P225, (tmp1 - tmp3)) + tmp3;
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
 * libc/math/lib_fixedmath.c
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
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdint.h>
#include <stdbool.h>
#include <fixedmath.h>

#ifndef CONFIG_HAVE_LONG_LONG

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
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Name: fixsign
 ****************************************************************************/

static void fixsign(b16_t *parg1, b16_t *parg2, bool *pnegate)
{
	bool negate = false;
	b16_t arg;

	arg = *parg1;
	if (arg < 0) {
		*parg1 = -arg;
		negate = true;
	}

	arg = *parg2;
	if (arg < 0) {
		*parg2 = -arg;
		negate ^= true;
	}

	*pnegate = negate;
}

/****************************************************************************
 * Name: adjustsign
 ****************************************************************************/

static b16_t adjustsign(b16_t result, bool negate)
{
	/* If the product is negative, then we overflowed */

	if (result < 0) {
		if (result) {
			return b16MIN;
		} else {
			return b16MAX;
		}
	}

	/* correct the sign of the result */

	if (negate) {
		return -result;
	}
	return result;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: b16mulb16
 ****************************************************************************/

b16_t b16mulb16(b16_t m1, b16_t m2)
{
	bool negate;
	b16_t product;

	fixsign(&m1, &m2, &negate);
	product = (b16_t)ub16mulub16((ub16_t)m1, (ub16_t)m2);
	return adjustsign(product, negate);
}

/****************************************************************************
 * Name: ub16mulub16
 **************************************************************************/

ub16_t ub16mulub16(ub16_t m1, ub16_t m2)
{
	/* Let:
	 *
	 *   m1 = m1i*2**16 + m1f                                            (b16)
	 *   m2 = m2i*2**16 + m2f                                            (b16)
	 *
	 * Then:
	 *
	 *  m1*m2 = (m1i*m2i)*2**32 + (m1i*m2f + m2i*m1f)*2**16 + m1f*m2f     (b32)
	 *        = (m1i*m2i)*2**16 + (m1i*m2f + m2i*m1f) + m1f*m2f*2**-16    (b16)
	 *        = a*2**16 + b + c*2**-16
	 */

	uint32_t m1i = ((uint32_t)m1 >> 16);
	uint32_t m2i = ((uint32_t)m2 >> 16);
	uint32_t m1f = ((uint32_t)m1 & 0x0000ffff);
	uint32_t m2f = ((uint32_t)m2 & 0x0000ffff);

	return (m1i * m2i << 16) + m1i * m2f + m2i * m1f + (((m1f * m2f) + b16HALF) >> 16);
}

/****************************************************************************
 * Name: b16sqr
 **************************************************************************/

b16_t b16sqr(b16_t a)
{
	b16_t sq;

	/* The result is always positive.  Just take the absolute value */

	if (a < 0) {
		a = -a;
	}

	/* Overflow occurred if the result is negative */

	sq = (b16_t)ub16sqr(a);
	if (sq < 0) {
		sq = b16MAX;
	}
	return sq;
}

/****************************************************************************
 * Name: b16divb16
 **************************************************************************/

ub16_t ub16sqr(ub16_t a)
{
	/* Let:
	 *
	 *   m = mi*2**16 + mf                                               (b16)
	 *
	 * Then:
	 *
	 *  m*m = (mi*mi)*2**32 + 2*(m1*m2)*2**16 + mf*mf                    (b32)
	 *      = (mi*mi)*2**16 + 2*(mi*mf)       + mf*mf*2**-16             (b16)
	 */

	uint32_t mi = ((uint32_t)a >> 16);
	uint32_t mf = ((uint32_t)a & 0x0000ffff);

	return (mi * mi << 16) + (mi * mf << 1) + ((mf * mf + b16HALF) >> 16);
}

/****************************************************************************
 * Name: b16divb16
 **************************************************************************/

b16_t b16divb16(b16_t num, b16_t denom)
{
	bool negate;
	b16_t quotient;

	fixsign(&num, &denom, &negate);
	quotient = (b16_t)ub16divub16((ub16_t)num, (ub16_t)denom);
	return adjustsign(quotient, negate);
}

/****************************************************************************
 * Name: ub16divub16
 **************************************************************************/

ub16_t ub16divub16(ub16_t num, ub16_t denom)
{
	uint32_t term1;
	uint32_t numf;
	uint32_t product;

	/* Let:
	 *
	 *   num = numi*2**16 + numf                                         (b16)
	 *   den = deni*2**16 + denf                                         (b16)
	 *
	 * Then:
	 *
	 *  num/den = numi*2**16 / den + numf / den                          (b0)
	 *          = numi*2**32 / den + numf*2**16 /den                     (b16)
	 */

	/* Check for overflow in the first part of the quotient */

	term1 = ((uint32_t)num & 0xffff0000) / denom;
	if (term1 >= 0x00010000) {
		return ub16MAX;			/* Will overflow */
	}

	/* Finish the division */

	numf = num - term1 * denom;
	term1 <<= 16;
	product = term1 + (numf + (denom >> 1)) / denom;

	/* Check for overflow */

	if (product < term1) {
		return ub16MAX;			/* Overflowed */
	}
	return product;
}

#endif
   