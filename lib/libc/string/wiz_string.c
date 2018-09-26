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
 * libc/string/lib_isbasedigit.c
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
 * Name: lib_isbasedigit
 *
 * Description:
 *   Given an ASCII character, ch, and a base (1-36) do two
 *   things:  1) Determine if ch is a valid charcter, and 2)
 *   convert ch to its binary value.
 *
 ****************************************************************************/

bool lib_isbasedigit(int ch, int base, int *value)
{
	bool ret = false;
	int tmp = 0;

	if (base <= 10) {
		if (ch >= '0' && ch <= base + '0' - 1) {
			tmp = ch - '0';
			ret = true;
		}
	} else if (base <= 36) {
		if (ch >= '0' && ch <= '9') {
			tmp = ch - '0';
			ret = true;
		} else if (ch >= 'a' && ch <= 'a' + base - 11) {
			tmp = ch - 'a' + 10;
			ret = true;
		} else if (ch >= 'A' && ch <= 'A' + base - 11) {
			tmp = ch - 'A' + 10;
			ret = true;
		}
	}

	if (value) {
		*value = tmp;
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
 * libc/string/lib_memccpy.c
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: memccpy
 *
 * Description:
 *   The memccpy() function copies bytes from memory area s2 into s1,
 *   stopping after the first occurrence of byte c (converted to an unsigned
 *   char) is copied, or after n bytes are copied, whichever comes first. If
 *   copying takes place between objects that overlap, the behavior is
 *   undefined.
 *
 * Returned Value:
 *   The memccpy() function returns a pointer to the byte after the copy of c
 *   in s1, or a null pointer if c was not found in the first n bytes of s2.
 *
 ****************************************************************************/

FAR void *memccpy(FAR void *s1, FAR const void *s2, int c, size_t n)
{
	FAR unsigned char *pout = (FAR unsigned char *)s1;
	FAR unsigned char *pin = (FAR unsigned char *)s2;

	/* Copy at most n bytes */

	while (n-- > 0) {
		/* Copy one byte */

		*pout = *pin++;

		/* Did we just copy the terminating byte c? */

		if (*pout == (unsigned char)c) {
			/* Yes return a pointer to the byte after the copy of c into s1 */

			return (FAR void *)(++pout);
		}

		/* No increment to the next destination location */

		pout++;
	}

	/* C was not found in the first n bytes of s2 */

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
 * libc/string/lib_memchr.c
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

#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: memchr
 *
 * Description:
 *   The memchr() function locates the first occurrence of 'c' (converted to
 *   an unsigned char) in the initial 'n' bytes (each interpreted as
 *   unsigned char) of the object pointed to by s.
 *
 * Returned Value:
 *   The memchr() function returns a pointer to the located byte, or a null
 *   pointer if the byte does not occur in the object.
 *
 ****************************************************************************/

FAR void *memchr(FAR const void *s, int c, size_t n)
{
	FAR const unsigned char *p = (FAR const unsigned char *)s;

	if (s) {
		while (n--) {
			if (*p == (unsigned char)c) {
				return (FAR void *)p;
			}

			p++;
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
/************************************************************
 * libc/string/lib_memcmp.c
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
 ************************************************************/

/************************************************************
 * Compilation Switches
 ************************************************************/

/************************************************************
 * Included Files
 ************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/************************************************************
 * Global Functions
 ************************************************************/

#ifndef CONFIG_ARCH_MEMCMP
int memcmp(FAR const void *s1, FAR const void *s2, size_t n)
{
	unsigned char *p1 = (unsigned char *)s1;
	unsigned char *p2 = (unsigned char *)s2;

	while (n-- > 0) {
		if (*p1 < *p2) {
			return -1;
		} else if (*p1 > *p2) {
			return 1;
		}

		p1++;
		p2++;
	}
	return 0;
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
 * libc/string/lib_memcpy.c
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: memcpy
 ****************************************************************************/

#ifndef CONFIG_ARCH_MEMCPY
FAR void *memcpy(FAR void *dest, FAR const void *src, size_t n)
{
	FAR unsigned char *pout = (FAR unsigned char *)dest;
	FAR unsigned char *pin = (FAR unsigned char *)src;
	while (n-- > 0) {
		*pout++ = *pin++;
	}
	return dest;
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
/************************************************************
 * libc/string/lib_memmove.c
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
 ************************************************************/

/************************************************************
 * Compilation Switches
 ************************************************************/

/************************************************************
 * Included Files
 ************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/************************************************************
 * Global Functions
 ************************************************************/

#ifndef CONFIG_ARCH_MEMMOVE
FAR void *memmove(FAR void *dest, FAR const void *src, size_t count)
{
	char *tmp, *s;
	if (dest <= src) {
		tmp = (char *)dest;
		s = (char *)src;
		while (count--) {
			*tmp++ = *s++;
		}
	} else {
		tmp = (char *)dest + count;
		s = (char *)src + count;
		while (count--) {
			*--tmp = *--s;
		}
	}

	return dest;
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
 * libc/string/lib_memset.c
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

#include <tinyara/config.h>

#include <sys/types.h>

#include <stdint.h>
#include <string.h>
#include <assert.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Can't support CONFIG_MEMSET_64BIT if the platform does not have 64-bit
 * integer types.
 */

#ifndef CONFIG_HAVE_LONG_LONG
#undef CONFIG_MEMSET_64BIT
#endif

/****************************************************************************
 * Global Functions
 ****************************************************************************/

#ifndef CONFIG_ARCH_MEMSET
void *memset(void *s, int c, size_t n)
{
#ifdef CONFIG_MEMSET_OPTSPEED
	/* This version is optimized for speed (you could do better
	 * still by exploiting processor caching or memory burst
	 * knowledge.)
	 */

	uintptr_t addr = (uintptr_t)s;
	uint16_t val16 = ((uint16_t)c << 8) | (uint16_t)c;
	uint32_t val32 = ((uint32_t)val16 << 16) | (uint32_t)val16;
#ifdef CONFIG_MEMSET_64BIT
	uint64_t val64 = ((uint64_t)val32 << 32) | (uint64_t)val32;
#endif

	/* Make sure that there is something to be cleared */

	if (n > 0) {
		/* Align to a 16-bit boundary */

		if ((addr & 1) != 0) {
			*(uint8_t *)addr = (uint8_t)c;
			addr += 1;
			n -= 1;
		}

		/* Check if there are at least 16-bits left to be written */

		if (n >= 2) {
			/* Align to a 32-bit boundary (we know that the destination
			 * address is already aligned to at least a 16-bit boundary).
			 */

			if ((addr & 3) != 0) {
				*(uint16_t *)addr = val16;
				addr += 2;
				n -= 2;
			}
#ifndef CONFIG_MEMSET_64BIT
			/* Loop while there are at least 32-bits left to be written */

			while (n >= 4) {
				*(uint32_t *)addr = val32;
				addr += 4;
				n -= 4;
			}
#else
			/* Check if there are at least 32-bits left to be written */

			if (n >= 4) {
				/* Align to a 64-bit boundary (we know that the destination
				 * address is already aligned to at least a 32-bit boundary).
				 */

				if ((addr & 7) != 0) {
					*(uint32_t *)addr = val32;
					addr += 4;
					n -= 4;
				}

				/* Loop while there are at least 64-bits left to be written */

				while (n >= 8) {
					*(uint64_t *)addr = val64;
					addr += 8;
					n -= 8;
				}
			}
#endif
		}
#ifdef CONFIG_MEMSET_64BIT
		/* We may get here with n in the range 0..7.  If n >= 4, then we should
		 * have 64-bit alignment.
		 */

		if (n >= 4) {
			*(uint32_t *)addr = val32;
			addr += 4;
			n -= 4;
		}
#endif

		/* We may get here under the following conditions:
		 *
		 *   n = 0, addr may or may not be aligned
		 *   n = 1, addr is aligned to at least a 16-bit boundary
		 *   n = 2, addr is aligned to a 32-bit boundary
		 *   n = 3, addr is aligned to a 32-bit boundary
		 */

		if (n >= 2) {
			*(uint16_t *)addr = val16;
			addr += 2;
			n -= 2;
		}

		if (n >= 1) {
			*(uint8_t *)addr = (uint8_t)c;
		}
	}
#else
	/* This version is optimized for size */
	unsigned char *p = (unsigned char *)s;   
	while (n-- > 0) {
		*p++ = c;
	}
#endif
	return s;
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
 * libc/string/lib_skipspace.c
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
 * Name: lib_skipspace
 *
 * Description:
 *   Skip over leading whitespace
 *
 ****************************************************************************/

void lib_skipspace(const char **pptr)
{
	const char *ptr = *pptr;
	while (isspace(*ptr)) {
		ptr++;
	}
	*pptr = ptr;
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
 * libc/string/lib_strppy.c
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
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>

#include <string.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

/************************************************************************
 * Name: stpcpy
 *
 * Description:
 *   Copies the string pointed to by 'src' (including the terminating NUL
 *   character) into the array pointed to by 'dest'.
 *
 * Returned value:
 *   The stpcpy() function returns a pointer to the terminating NUL
 *   character copied into the 'dest' buffer
 *
 ************************************************************************/

#ifndef CONFIG_ARCH_STPCPY
FAR char *stpcpy(FAR char *dest, FAR const char *src)
{
	while ((*dest++ = *src++) != '\0');
	return --dest;
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
 * libc/string/lib_strcasecmp.c
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
 *****************************************************************************/

/****************************************************************************
 * Included Files
 *****************************************************************************/

#include <tinyara/config.h>

#include <string.h>
#include <ctype.h>

/****************************************************************************
 * Public Functions
 *****************************************************************************/

#ifndef CONFIG_ARCH_STRCMP
int strcasecmp(const char *cs, const char *ct)
{
	int result;
	for (;;) {
		if ((result = (int)toupper(*cs) - (int)toupper(*ct)) != 0 || !*cs) {
			break;
		}

		cs++;
		ct++;
	}
	return result;
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
 * libc/string/lib_strstr.c
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use str source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions str binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer str
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

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static FAR char *strcasechr(FAR const char *s, int uc)
{
	register char ch;

	if (s) {
		for (; *s; s++) {
			ch = *s;
			if (toupper(ch) == uc) {
				return (FAR char *)s;
			}
		}
	}

	return NULL;
}

/****************************************************************************
 * Global Functions
 ****************************************************************************/

FAR char *strcasestr(FAR const char *str, FAR const char *substr)
{
	const char *candidate;		/* Candidate in str with matching start character */
	char ch;					/* First character of the substring */
	int len;					/* The length of the substring */

	/* Special case the empty substring */

	len = strlen(substr);
	ch = *substr;

	if (!ch) {
		/* We'll say that an empty substring matches at the beginning of
		 * the string
		 */

		return (char *)str;
	}

	/* Search for the substring */

	candidate = str;
	ch = toupper(ch);

	for (;;) {
		/* strcasechr() will return a pointer to the next occurrence of the
		 * character ch in the string (ignoring case)
		 */

		candidate = strcasechr(candidate, ch);
		if (!candidate || strlen(candidate) < len) {
			/* First character of the substring does not appear in the string
			 * or the remainder of the string is not long enough to contain the
			 * substring.
			 */

			return NULL;
		}

		/* Check if this is the beginning of a matching substring (ignoring case) */

		if (strncasecmp(candidate, substr, len) == 0) {
			/* Yes.. return the pointer to the first occurrence of the matching
			 * substring.
			 */

			return (char *)candidate;
		}

		/* No, find the next candidate after this one */

		candidate++;
	}

	/* Won't get here, but some compilers might complain.  Others might complain
	 * about this code being unreachable too.
	 */

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
 * libc/string/lib_strcat.c
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

#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

#ifndef CONFIG_ARCH_STRCAT
char *strcat(char *dest, const char *src)
{
	char *ret = dest;

	dest += strlen(dest);
	while (*src != '\0') {
		*dest++ = *src++;
	}
	*dest = '\0';

	return ret;
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
 * libc/string/lib_strchr.c
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
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strchr
 *
 * Description:
 *   The strchr() function locates the first occurrence of 'c' (converted to
 *   a char) in the string pointed to by 's'. The terminating null byte is
 *   considered to be part of the string.
 *
 * Returned Value:
 *   Upon completion, strchr() returns a pointer to the byte, or a null
 *   pointer if the byte was not found.
 *
 ****************************************************************************/

#ifndef CONFIG_ARCH_STRCHR
FAR char *strchr(FAR const char *s, int c)
{
	if (s) {
		for (;; s++) {
			if (*s == c) {
				return (FAR char *)s;
			}

			if (!*s) {
				break;
			}
		}
	}

	return NULL;
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
 * libc/string/lib_strcmp.c
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
 *****************************************************************************/

/****************************************************************************
 * Included Files
 *****************************************************************************/

#include <tinyara/config.h>

#include <string.h>

/****************************************************************************
 * Public Functions
 *****************************************************************************/

#ifndef CONFIG_ARCH_STRCMP
int strcmp(const char *cs, const char *ct)
{
	register signed char result;
	for (;;) {
		if ((result = *cs - *ct++) != 0 || !*cs++) {
			break;
		}
	}
	return result;
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
 * lib/libc/string/lib_strcoll.c
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
#include <string.h>
#include <wchar.h>

#ifdef CONFIG_LIBC_LOCALE

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strcoll
 *
 * Description:
 *   The strcoll() compares the string pointed to by a to the string pointed
 *   to by b, using an interpretation appropriate to the current
 *   LC_COLLATE state. Current implementation doesn't care about locale.
 *
 ****************************************************************************/

int strcoll(const char *a, const char *b)
{
	return strcmp(a, b);
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
/************************************************************************
 * libc/string/lib_strcpy.c
 *
 *   Copyright (C) 2007, 2009, 2011, 2014 Gregory Nutt. All rights reserved.
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

#include <string.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

/************************************************************************
 * Name: strcpy
 *
 * Description:
 *   Copies the string pointed to by 'src' (including the terminating NUL
 *   character) into the array pointed to by 'des'.
 *
 * Returned value:
 *   The strcpy() function returns the 'dest' pointer
 *
 ************************************************************************/

#ifndef CONFIG_ARCH_STRCPY
FAR char *strcpy(FAR char *dest, FAR const char *src)
{
	char *tmp = dest;
	while ((*dest++ = *src++) != '\0');
	return tmp;
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
 * libc/string/lib_strcspn.c
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strcspn
 *
 * Description:
 *  strspn() calculates the length of the initial segment of s which
 *  consists entirely of characters not in reject
 *
 ****************************************************************************/

size_t strcspn(const char *s, const char *reject)
{
	size_t i;
	for (i = 0; s[i] && strchr(reject, s[i]) == NULL; i++);
	return i;
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
 * libc/string//lib_strdup.c
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
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>

#include <string.h>

#include "lib_internal.h"

/************************************************************************
 * Global Functions
 ************************************************************************/

FAR char *strdup(const char *s)
{
	FAR char *news = NULL;
	if (s) {
		news = (FAR char *)lib_malloc(strlen(s) + 1);
		if (news) {
			strcpy(news, s);
		}
	}

	return news;
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
 * libc/string/lib_strerror.c
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

#include <stdint.h>
#include <string.h>
#include <errno.h>

/************************************************************************
 * Definitions
 ************************************************************************/

/************************************************************************
 * Private Types
 ************************************************************************/

struct errno_strmap_s {
	uint8_t errnum;
	const char *str;
};

/************************************************************************
 * Private Data
 ************************************************************************/

#ifdef CONFIG_LIBC_STRERROR

/* This table maps all error numbers to descriptive strings.
 * The only assumption that the code makes with regard to this
 * this table is that it is ordered by error number.
 *
 * The size of this table is quite large.  Its size can be
 * reduced by eliminating some of the more obscure error
 * strings.
 */

#ifndef CONFIG_LIBC_STRERROR_SHORT

static const struct errno_strmap_s g_errnomap[] = {
	{EPERM, EPERM_STR},
	{ENOENT, ENOENT_STR},
	{ESRCH, ESRCH_STR},
	{EINTR, EINTR_STR},
	{EIO, EIO_STR},
	{ENXIO, ENXIO_STR},
	{E2BIG, E2BIG_STR},
	{ENOEXEC, ENOEXEC_STR},
	{EBADF, EBADF_STR},
	{ECHILD, ECHILD_STR},
	{EAGAIN, EAGAIN_STR},
	{ENOMEM, ENOMEM_STR},
	{EACCES, EACCES_STR},
	{EFAULT, EFAULT_STR},
	{ENOTBLK, ENOTBLK_STR},
	{EBUSY, EBUSY_STR},
	{EEXIST, EEXIST_STR},
	{EXDEV, EXDEV_STR},
	{ENODEV, ENODEV_STR},
	{ENOTDIR, ENOTDIR_STR},
	{EISDIR, EISDIR_STR},
	{EINVAL, EINVAL_STR},
	{ENFILE, ENFILE_STR},
	{EMFILE, EMFILE_STR},
	{ENOTTY, ENOTTY_STR},
	{ETXTBSY, ETXTBSY_STR},
	{EFBIG, EFBIG_STR},
	{ENOSPC, ENOSPC_STR},
	{ESPIPE, ESPIPE_STR},
	{EROFS, EROFS_STR},
	{EMLINK, EMLINK_STR},
	{EPIPE, EPIPE_STR},
	{EDOM, EDOM_STR},
	{ERANGE, ERANGE_STR},
	{EDEADLK, EDEADLK_STR},
	{ENAMETOOLONG, ENAMETOOLONG_STR},
	{ENOLCK, ENOLCK_STR},
	{ENOSYS, ENOSYS_STR},
	{ENOTEMPTY, ENOTEMPTY_STR},
	{ELOOP, ELOOP_STR},
	{ENOMSG, ENOMSG_STR},
	{EIDRM, EIDRM_STR},
	{ECHRNG, ECHRNG_STR},
	{EL2NSYNC, EL2NSYNC_STR},
	{EL3HLT, EL3HLT_STR},
	{EL3RST, EL3RST_STR},
	{ELNRNG, ELNRNG_STR},
	{EUNATCH, EUNATCH_STR},
	{ENOCSI, ENOCSI_STR},
	{EL2HLT, EL2HLT_STR},
	{EBADE, EBADE_STR},
	{EBADR, EBADR_STR},
	{EXFULL, EXFULL_STR},
	{ENOANO, ENOANO_STR},
	{EBADRQC, EBADRQC_STR},
	{EBADSLT, EBADSLT_STR},
	{EBFONT, EBFONT_STR},
	{ENOSTR, ENOSTR_STR},
	{ENODATA, ENODATA_STR},
	{ETIME, ETIME_STR},
	{ENOSR, ENOSR_STR},
	{ENONET, ENONET_STR},
	{ENOPKG, ENOPKG_STR},
	{EREMOTE, EREMOTE_STR},
	{ENOLINK, ENOLINK_STR},
	{EADV, EADV_STR},
	{ESRMNT, ESRMNT_STR},
	{ECOMM, ECOMM_STR},
	{EPROTO, EPROTO_STR},
	{EMULTIHOP, EMULTIHOP_STR},
	{EDOTDOT, EDOTDOT_STR},
	{EBADMSG, EBADMSG_STR},
	{EOVERFLOW, EOVERFLOW_STR},
	{ENOTUNIQ, ENOTUNIQ_STR},
	{EBADFD, EBADFD_STR},
	{EREMCHG, EREMCHG_STR},
	{ELIBACC, ELIBACC_STR},
	{ELIBBAD, ELIBBAD_STR},
	{ELIBSCN, ELIBSCN_STR},
	{ELIBMAX, ELIBMAX_STR},
	{ELIBEXEC, ELIBEXEC_STR},
	{EILSEQ, EILSEQ_STR},
	{ERESTART, ERESTART_STR},
	{ESTRPIPE, ESTRPIPE_STR},
	{EUSERS, EUSERS_STR},
	{ENOTSOCK, ENOTSOCK_STR},
	{EDESTADDRREQ, EDESTADDRREQ_STR},
	{EMSGSIZE, EMSGSIZE_STR},
	{EPROTOTYPE, EPROTOTYPE_STR},
	{ENOPROTOOPT, ENOPROTOOPT_STR},
	{EPROTONOSUPPORT, EPROTONOSUPPORT_STR},
	{ESOCKTNOSUPPORT, ESOCKTNOSUPPORT_STR},
	{EOPNOTSUPP, EOPNOTSUPP_STR},
	{EPFNOSUPPORT, EPFNOSUPPORT_STR},
	{EAFNOSUPPORT, EAFNOSUPPORT_STR},
	{EADDRINUSE, EADDRINUSE_STR},
	{EADDRNOTAVAIL, EADDRNOTAVAIL_STR},
	{ENETDOWN, ENETDOWN_STR},
	{ENETUNREACH, ENETUNREACH_STR},
	{ENETRESET, ENETRESET_STR},
	{ECONNABORTED, ECONNABORTED_STR},
	{ECONNRESET, ECONNRESET_STR},
	{ENOBUFS, ENOBUFS_STR},
	{EISCONN, EISCONN_STR},
	{ENOTCONN, ENOTCONN_STR},
	{ESHUTDOWN, ESHUTDOWN_STR},
	{ETOOMANYREFS, ETOOMANYREFS_STR},
	{ETIMEDOUT, ETIMEDOUT_STR},
	{ECONNREFUSED, ECONNREFUSED_STR},
	{EHOSTDOWN, EHOSTDOWN_STR},
	{EHOSTUNREACH, EHOSTUNREACH_STR},
	{EALREADY, EALREADY_STR},
	{EINPROGRESS, EINPROGRESS_STR},
	{ESTALE, ESTALE_STR},
	{EUCLEAN, EUCLEAN_STR},
	{ENOTNAM, ENOTNAM_STR},
	{ENAVAIL, ENAVAIL_STR},
	{EISNAM, EISNAM_STR},
	{EREMOTEIO, EREMOTEIO_STR},
	{EDQUOT, EDQUOT_STR},
	{ENOMEDIUM, ENOMEDIUM_STR},
	{EMEDIUMTYPE, EMEDIUMTYPE_STR}
};

#else							/* CONFIG_LIBC_STRERROR_SHORT */

static const struct errno_strmap_s g_errnomap[] = {
	{EPERM, "EPERM"},
	{ENOENT, "ENOENT"},
	{ESRCH, "ESRCH"},
	{EINTR, "EINTR"},
	{EIO, "EIO"},
	{ENXIO, "ENXIO"},
	{E2BIG, "E2BIG"},
	{ENOEXEC, "ENOEXEC"},
	{EBADF, "EBADF"},
	{ECHILD, "ECHILD"},
	{EAGAIN, "EAGAIN"},
	{ENOMEM, "ENOMEM"},
	{EACCES, "EACCES"},
	{EFAULT, "EFAULT"},
	{ENOTBLK, "ENOTBLK"},
	{EBUSY, "EBUSY"},
	{EEXIST, "EEXIST"},
	{EXDEV, "EXDEV"},
	{ENODEV, "ENODEV"},
	{ENOTDIR, "ENOTDIR"},
	{EISDIR, "EISDIR"},
	{EINVAL, "EINVAL"},
	{ENFILE, "ENFILE"},
	{EMFILE, "EMFILE"},
	{ENOTTY, "ENOTTY"},
	{ETXTBSY, "ETXTBSY"},
	{EFBIG, "EFBIG"},
	{ENOSPC, "ENOSPC"},
	{ESPIPE, "ESPIPE"},
	{EROFS, "EROFS"},
	{EMLINK, "EMLINK"},
	{EPIPE, "EPIPE"},
	{EDOM, "EDOM"},
	{ERANGE, "ERANGE"},
	{EDEADLK, "EDEADLK"},
	{ENAMETOOLONG, "ENAMETOOLONG"},
	{ENOLCK, "ENOLCK"},
	{ENOSYS, "ENOSYS"},
	{ENOTEMPTY, "ENOTEMPTY"},
	{ELOOP, "ELOOP"},
	{ENOMSG, "ENOMSG"},
	{EIDRM, "EIDRM"},
	{ECHRNG, "ECHRNG"},
	{EL2NSYNC, "EL2NSYNC"},
	{EL3HLT, "EL3HLT"},
	{EL3RST, "EL3RST"},
	{EL3RST, "EL3RST"},
	{EUNATCH, "EUNATCH"},
	{ENOCSI, "ENOCSI"},
	{EL2HLT, "EL2HLT"},
	{EBADE, "EBADE"},
	{EBADR, "EBADR"},
	{EXFULL, "EXFULL"},
	{ENOANO, "ENOANO"},
	{EBADRQC, "EBADRQC"},
	{EBADSLT, "EBADSLT"},
	{EBFONT, "EBFONT"},
	{ENOSTR, "ENOSTR"},
	{ENODATA, "ENODATA"},
	{ETIME, "ETIME"},
	{ENOSR, "ENOSR"},
	{ENONET, "ENONET"},
	{ENOPKG, "ENOPKG"},
	{EREMOTE, "EREMOTE"},
	{ENOLINK, "ENOLINK"},
	{EADV, "EADV"},
	{ESRMNT, "ESRMNT"},
	{ECOMM, "ECOMM"},
	{EPROTO, "EPROTO"},
	{EMULTIHOP, "EMULTIHOP"},
	{EDOTDOT, "EDOTDOT"},
	{EBADMSG, "EBADMSG"},
	{EOVERFLOW, "EOVERFLOW"},
	{ENOTUNIQ, "ENOTUNIQ"},
	{EBADFD, "EBADFD"},
	{EREMCHG, "EREMCHG"},
	{ELIBACC, "ELIBACC"},
	{ELIBBAD, "ELIBBAD"},
	{ELIBSCN, "ELIBSCN"},
	{ELIBMAX, "ELIBMAX"},
	{ELIBEXEC, "ELIBEXEC"},
	{EILSEQ, "EILSEQ"},
	{ERESTART, "ERESTART"},
	{ESTRPIPE, "ESTRPIPE"},
	{EUSERS, "EUSERS"},
	{ENOTSOCK, "ENOTSOCK"},
	{EDESTADDRREQ, "EDESTADDRREQ"},
	{EMSGSIZE, "EMSGSIZE"},
	{EPROTOTYPE, "EPROTOTYPE"},
	{ENOPROTOOPT, "ENOPROTOOPT"},
	{EPROTONOSUPPORT, "EPROTONOSUPPORT"},
	{ESOCKTNOSUPPORT, "ESOCKTNOSUPPORT"},
	{EOPNOTSUPP, "EOPNOTSUPP"},
	{EPFNOSUPPORT, "EPFNOSUPPORT"},
	{EAFNOSUPPORT, "EAFNOSUPPORT"},
	{EADDRINUSE, "EADDRINUSE"},
	{EADDRNOTAVAIL, "EADDRNOTAVAIL"},
	{ENETDOWN, "ENETDOWN"},
	{ENETUNREACH, "ENETUNREACH"},
	{ENETRESET, "ENETRESET"},
	{ECONNABORTED, "ECONNABORTED"},
	{ECONNRESET, "ECONNRESET"},
	{ENOBUFS, "ENOBUFS"},
	{EISCONN, "EISCONN"},
	{ENOTCONN, "ENOTCONN"},
	{ESHUTDOWN, "ESHUTDOWN"},
	{ETOOMANYREFS, "ETOOMANYREFS"},
	{ETIMEDOUT, "ETIMEDOUT"},
	{ECONNREFUSED, "ECONNREFUSED"},
	{EHOSTDOWN, "EHOSTDOWN"},
	{EHOSTUNREACH, "EHOSTUNREACH"},
	{EALREADY, "EALREADY"},
	{EINPROGRESS, "EINPROGRESS"},
	{ESTALE, "ESTALE"},
	{EUCLEAN, "EUCLEAN"},
	{ENOTNAM, "ENOTNAM"},
	{ENAVAIL, "ENAVAIL"},
	{EISNAM, "EISNAM"},
	{EREMOTEIO, "EREMOTEIO"},
	{EDQUOT, "EDQUOT"},
	{ENOMEDIUM, "ENOMEDIUM"},
	{EMEDIUMTYPE, "EMEDIUMTYPE"}
};

#endif							/* CONFIG_LIBC_STRERROR_SHORT */

#define NERRNO_STRS (sizeof(g_errnomap) / sizeof(struct errno_strmap_s))

#endif							/* CONFIG_LIBC_STRERROR */

/************************************************************************
 * Private Functions
 ************************************************************************/

/************************************************************************
 * Public Functions
 ************************************************************************/

/************************************************************************
 * Name: strerror
 ************************************************************************/

FAR const char *strerror(int errnum)
{
#ifdef CONFIG_LIBC_STRERROR
	int ndxlow = 0;
	int ndxhi = NERRNO_STRS - 1;
	int ndxmid;

	do {
		ndxmid = (ndxlow + ndxhi) >> 1;
		if (errnum > g_errnomap[ndxmid].errnum) {
			ndxlow = ndxmid + 1;
		} else if (errnum < g_errnomap[ndxmid].errnum) {
			ndxhi = ndxmid - 1;
		} else {
			return g_errnomap[ndxmid].str;
		}
	} while (ndxlow <= ndxhi);
#endif
	return "Unknown error";
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
 * lib/libc/string/lib_strerrorr.c
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

#include <sys/types.h>
#include <string.h>
#include <assert.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strerror_r
 ****************************************************************************/

int strerror_r(int errnum, FAR char *buf, size_t buflen)
{
	FAR const char *errstr = strerror(errnum);

	DEBUGASSERT(buf != NULL);
	strncpy(buf, errstr, buflen);
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
/*	$OpenBSD: strlcpy.c,v 1.8 2003/06/17 21:56:24 millert Exp $	*/

/*
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

/************************************************************************
 * Name: strlcpy
 *
 * Description:
 *   Copies up to size - 1 characters from the NUL-terminated string src to dest,
 * NUL-terminating the result..
 *
 * Returned value:
 *   The strlcpy() function returns the total length of the string they tried to create.
 *
 ************************************************************************/

size_t strlcpy(char *__restrict dest, const char *__restrict src, size_t size)
{
	char *d = dest;
	const char *s = src;
	size_t n = size;

	/* Copy as many bytes as will fit */
	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0') {
				break;
			}
		}
	}

	/* Not enough room in dest, add NUL and traverse rest of src */
	if (n == 0) {
		if (size != 0) {
			*d = '\0';    /* NUL-terminate dest */
		}
		while (*s++) { ; }
	}

	return (s - src - 1);		/* count does not include NUL */
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
 * libc/string/lib_strlen.c
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

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

#ifndef CONFIG_ARCH_STRLEN
size_t strlen(const char *s)
{
	const char *sc;
	for (sc = s; *sc != '\0'; ++sc);
	return sc - s;
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
 * libc/string/lib_strncasecmp.c
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
 *****************************************************************************/

/****************************************************************************
 * Compilation Switches
 *****************************************************************************/

/****************************************************************************
 * Included Files
 *****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <string.h>
#include <ctype.h>

/****************************************************************************
 * Global Functions
 *****************************************************************************/

#ifndef CONFIG_ARCH_STRNCASECMP
int strncasecmp(const char *cs, const char *ct, size_t nb)
{
	int result = 0;
	for (; nb > 0; nb--) {
		if ((result = (int)toupper(*cs) - (int)toupper(*ct)) != 0 || !*cs) {
			break;
		}

		cs++;
		ct++;
	}
	return result;
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
/************************************************************
 * libc/string/lib_strncat.c
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
 ************************************************************/

/************************************************************
 * Included Files
 ************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/************************************************************
 * Global Functions
 ************************************************************/

#ifndef CONFIG_ARCH_STRNCAT
char *strncat(char *dest, const char *src, size_t n)
{
	char *ret = dest;

	dest += strlen(dest);
	for (; n > 0 && *src != '\0'; n--) {
		*dest++ = *src++;
	}
	*dest = '\0';

	return ret;
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
 * libc/lib_strncmp.c
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
 *****************************************************************************/

/****************************************************************************
 * Compilation Switches
 *****************************************************************************/

/****************************************************************************
 * Included Files
 *****************************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/****************************************************************************
 * Global Functions
 *****************************************************************************/

#ifndef CONFIG_ARCH_STRNCMP
int strncmp(const char *cs, const char *ct, size_t nb)
{
	int result = 0;
	for (; nb > 0; nb--) {
		if ((result = (int)*cs - (int)*ct++) != 0 || !*cs++) {
			break;
		}
	}

	return result;
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
/************************************************************
 * libc/string/lib_strncpy.c
 *
 *   Copyright (C) 2007, 2011, 2014 Gregory Nutt. All rights reserved.
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
 ************************************************************/

/************************************************************
 * Included Files
 ************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/************************************************************
 * Public Functions
 ************************************************************/

/************************************************************
 * Name: strncpy
 ************************************************************/

#ifndef CONFIG_ARCH_STRNCPY
char *strncpy(FAR char *dest, FAR const char *src, size_t n)
{
    //if(NULL == dest || NULL == src) return NULL; //[WizIO]]
    
	char *ret = dest;			/* Value to be returned */
	char *end = dest + n;		/* End of dest buffer + 1 byte */

	while ((dest != end) && (*dest++ = *src++) != '\0');
	while (dest != end) {
		*dest++ = '\0';
	}

	return ret;
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
/************************************************************************
 * libc/string//lib_strndup.c
 *
 *   Copyright (C) 2011, 2013 Gregory Nutt. All rights reserved.
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

#include <string.h>

#include "lib_internal.h"

/************************************************************************
 * Global Functions
 ************************************************************************/
/************************************************************************
 * Name: strndup
 *
 * Description:
 *   The strndup() function is equivalent to the strdup() function,
 *   duplicating the provided 's' in a new block of memory allocated as
 *   if by using malloc(), with the exception being that strndup() copies
 *   at most 'size' plus one bytes into the newly allocated memory,
 *   terminating the new string with a NUL character. If the length of 's'
 *   is larger than 'size', only 'size' bytes will be duplicated. If
 *   'size' is larger than the length of 's', all bytes in s will be
 *   copied into the new memory buffer, including the terminating NUL
 *   character. The newly created string will always be properly
 *   terminated.
 *
 ************************************************************************/

FAR char *strndup(FAR const char *s, size_t size)
{
	FAR char *news = NULL;
	if (s) {
		/* Get the size of the new string (limited to size) */

		size_t allocsize = strnlen(s, size);

		/* Allocate the new string, adding 1 for the NUL terminator */

		news = (FAR char *)lib_malloc(allocsize + 1);
		if (news) {
			/* Copy the string into the allocated memory and add a NUL
			 * terminator in any case.
			 */

			memcpy(news, s, allocsize);
			news[allocsize] = '\0';
		}
	}

	return news;
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
 * libc/string/lib_strnlen.c
 *
 * This file is part of NuttX, contributed by Michael Hrabanek
 *
 *   Copyright (C) 2010 Gregory Nutt. All rights reserved.
 *   Author: Michael Hrabanek
 *
 * Derives from the file libc/lib_strlen.c:
 *
 *   Copyright (C) 2007, 2008, 2010 Gregory Nutt. All rights reserved.
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
#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

#ifndef CONFIG_ARCH_STRNLEN
size_t strnlen(const char *s, size_t maxlen)
{
	const char *sc;
	for (sc = s; maxlen != 0 && *sc != '\0'; maxlen--, ++sc);
	return sc - s;
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
 * libc/string/lib_strpbrk.c
 *
 *   Copyright (C) 2009, 2011 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use str source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions str binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer str
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

/****************************************************************************
 * Global Functions
 ****************************************************************************/

char *strpbrk(const char *str, const char *charset)
{
	/* Sanity checking */

#ifdef CONFIG_DEBUG
	if (!str || !charset) {
		return NULL;
	}
#endif

	/* Check each character in the string */

	while (*str) {
		/* Check if the character from the string matches any character in the charset */

		if (strchr(charset, *str) != NULL) {
			/* Yes, then this position must be the first occurrence in string */

			return (char *)str;
		}

		/* This character from the strings matches none of those in the charset.
		 * Try the next character from the string.
		 */

		str++;
	}

	/* We have looked at every character in the string, and none of them match any of
	 * the characters in charset.
	 */

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
/************************************************************************
 * libc/string/lib_strrchr.c
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
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>

#include <string.h>

/************************************************************************
 * Global Functions
 ************************************************************************/

/* The strrchr() function returns a pointer to the last
 * occurrence of the character c in the string s.
 */

char *strrchr(const char *s, int c)
{
	if (s) {
		const char *p = &s[strlen(s) - 1];
		for (; p >= s; p--) {
			if (*p == c) {
				return (char *)p;
			}
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
 * libc/string/lib_strspn.c
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
 * Compilation Switches
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <sys/types.h>
#include <string.h>

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strspn
 *
 * Description:
 *  strspn() calculates the length of the initial segment of s which
 *  consists entirely of characters in accept.
 *
 ****************************************************************************/

size_t strspn(const char *s, const char *accept)
{
	size_t i;
	for (i = 0; s[i] && strchr(accept, s[i]) != NULL; i++);
	return i;
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
 * libc/string/lib_strstr.c
 *
 *   Copyright (C) 2009, 2011 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use str source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions str binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer str
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

/****************************************************************************
 * Global Functions
 ****************************************************************************/

FAR char *strstr(FAR const char *str, FAR const char *substr)
{
	FAR const char *candidate;	/* Candidate in str with matching start character */
	char ch;					/* First character of the substring */
	int len;					/* The length of the substring */

	/* Special case the empty substring */

	len = strlen(substr);
	ch = *substr;

	if (!ch) {
		/* We'll say that an empty substring matches at the beginning of
		 * the string
		 */

		return (char *)str;
	}

	/* Search for the substring */

	candidate = str;
	for (;;) {
		/* strchr() will return a pointer to the next occurrence of the
		 * character ch in the string
		 */

		candidate = strchr(candidate, ch);
		if (!candidate || strlen(candidate) < len) {
			/* First character of the substring does not appear in the string
			 * or the remainder of the string is not long enough to contain the
			 * substring.
			 */

			return NULL;
		}

		/* Check if this is the beginning of a matching substring */

		if (strncmp(candidate, substr, len) == 0) {
			return (char *)candidate;
		}

		/* No, find the next candidate after this one */

		candidate++;
	}

	/* Won't get here, but some compilers might complain.  Other compilers
	 * might complain about this code being unreachable too.
	 */

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
 * libc/string/lib_strtok.c
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

#include <string.h>

/****************************************************************************
 * Private Data
 ****************************************************************************/

static char *g_saveptr = NULL;

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strtok
 *
 * Description:
 *    The  strtok()  function  parses  a string into a
 *    sequence of tokens.  On the first call to strtok() the
 *    string to be parsed should be specified in 'str'.  In
 *    each subsequent call that should parse the same string,
 *    'str' should be NULL.
 *
 *    The 'delim' argument specifies a set of characters that
 *    delimit the tokens in the parsed string.  The caller
 *    may specify different strings in delim in successive
 *    calls that parse the same string.
 *
 *    Each call to strtok() returns a pointer to a null-
 *    terminated string containing the next token. This
 *    string  does not include the delimiting character.  If
 *    no more tokens are found, strtok() returns NULL.
 *
 *    A sequence of two or more contiguous delimiter
 *    characters in the parsed string is considered to be a
 *    single delimiter. Delimiter characters at the start or
 *    end of the string are ignored.  The tokens returned by
 *    strtok() are always non-empty strings.
 *
 * Return
 *    strtok() returns a pointer to the next token, or NULL
 *    if there are no more tokens.
 *
 ****************************************************************************/

char *strtok(char *str, const char *delim)
{
	return strtok_r(str, delim, &g_saveptr);
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
 * libc/string/lib_strtokr.c
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

#include <string.h>

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strtok_r
 *
 * Description:
 *   The strtok_r() function is a reentrant version strtok().
 *   Like strtok(), it  parses  a string into a sequence of
 *   tokens.  On the first call to strtok() the string to be
 *   parsed should be specified in 'str'.  In each subsequent
 *   call that should parse the same string, 'str' should be
 *   NULL.
 *
 *   The 'saveptr' argument is a pointer to a char *
 *   variable  that  is  used internally by strtok_r() in
 *   order to maintain context between successive calls
 *   that parse the same string.
 *
 *   On the first call to strtok_r(), 'str' should point to the
 *   string to be parsed, and the value of 'saveptr' is
 *   ignored.  In subsequent calls, 'str' should be NULL, and
 *   saveptr should be unchanged since the previous call.
 *
 *   The 'delim' argument specifies a set of characters that
 *   delimit the tokens in the parsed string.  The caller
 *   may specify different strings in delim in successive
 *   calls that parse the same string.
 *
 *   Each call to strtok_r() returns a pointer to a null-
 *   terminated string containing the next token. This
 *   string  does not include the delimiting character.  If
 *   no more tokens are found, strtok_r() returns NULL.
 *
 *   A sequence of two or more contiguous delimiter
 *   characters in the parsed string is considered to be a
 *   single delimiter. Delimiter characters at the start or
 *   end of the string are ignored.  The tokens returned by
 *   strtok() are always non-empty strings.
 *
 * Return
 *    strtok_r() returns a pointer to the next token, or NULL
 *    if there are no more tokens.
 *
 ****************************************************************************/

FAR char *strtok_r(FAR char *str, FAR const char *delim, FAR char **saveptr)
{
	char *pbegin;
	char *pend = NULL;

	/* Decide if we are starting a new string or continuing from
	 * the point we left off.
	 */

	if (str) {
		pbegin = str;
	} else if (saveptr && *saveptr) {
		pbegin = *saveptr;
	} else {
		return NULL;
	}

	/* Find the beginning of the next token */

	for (; *pbegin && strchr(delim, *pbegin) != NULL; pbegin++);

	/* If we are at the end of the string with nothing
	 * but delimiters found, then return NULL.
	 */

	if (!*pbegin) {
		return NULL;
	}

	/* Find the end of the token */

	for (pend = pbegin + 1; *pend && strchr(delim, *pend) == NULL; pend++);

	/* pend either points to the end of the string or to
	 * the first delimiter after the string.
	 */

	if (*pend) {
		/* Turn the delimiter into a null terminator */

		*pend++ = '\0';
	}

	/* Save the pointer where we left off and return the
	 * beginning of the token.
	 */

	if (saveptr) {
		*saveptr = pend;
	}
	return pbegin;
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
 * lib/libc/string/lib_strxfrm.c
 *
 *   Copyright (c)1999 Citrus Project,
 *   All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
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
#include <string.h>

#ifdef CONFIG_LIBC_LOCALE

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: strxfrm
 *
 * Description:
 *   This function transforms the string pointed to by s2 and places the
 *   resulting string into the array pointed to by s1. The transformation is
 *   such that if the strcmp() function is applied to the two transformed
 *   strings, it returns a value greater than, equal to, or less than zero,
 *   correspoinding to the result of a <<strcoll>> function applied to the
 *   same two original strings.
 *   With a C locale, this function just copies.
 *
 ****************************************************************************/

size_t strxfrm(FAR char *s1, FAR const char *s2, size_t n)
{
	size_t res;
	res = 0;
	while (n-- > 0) {
		if ((*s1++ = *s2++) != '\0') {
			++res;
		} else {
			return res;
		}
	}
	while (*s2) {
		++s2;
		++res;
	}

	return res;
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
 * File: libc/string/lib_vikmemcpy.c
 *
 * This is version of the optimized memcpy by Daniel Vik, adapted to the
 * NuttX environment.
 *
 *   Copyright (C) 1999-2010 Daniel Vik
 *
 * Adaptations include:
 * - File name change
 * - Use of types defined in stdint.h
 * - Integration with the NuttX configuration system
 * - Other cosmetic changes for consistency with NuttX coding standards
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any
 * damages arising from the use of this software.
 * Permission is granted to anyone to use this software for any
 * purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you
 *    must not claim that you wrote the original software. If you
 *    use this software in a product, an acknowledgment in the
 *    use this software in a product, an acknowledgment in the
 *    product documentation would be appreciated but is not
 *    required.
 *
 * 2. Altered source versions must be plainly marked as such, and
 *    must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 *    distribution.
 *
 * Description: Implementation of the standard library function memcpy.
 *              This implementation of memcpy() is ANSI-C89 compatible.
 *
 * The following configuration options can be set:
 *
 *   CONFIG_ENDIAN_BIG
 *     Uses processor with big endian addressing. Default is little endian.
 *
 *   CONFIG_MEMCPY_PRE_INC_PTRS
 *     Use pre increment of pointers. Default is post increment of pointers.
 *
 *   CONFIG_MEMCPY_INDEXED_COPY
 *     Copying data using array indexing. Using this option, disables the
 *     CONFIG_MEMCPY_PRE_INC_PTRS option.
 *
 *   CONFIG_MEMCPY_64BIT - Compiles memcpy for 64 bit architectures
 *
 ****************************************************************************/

/********************************************************************
 * Included Files
 *******************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <stddef.h>
#include <stdint.h>
#include <string.h>

/********************************************************************
 * Pre-processor Definitions
 *******************************************************************/

/* Can't support CONFIG_MEMCPY_64BIT if the platform does not have 64-bit
 * integer types.
 */

#ifndef CONFIG_HAVE_LONG_LONG
#undef CONFIG_MEMCPY_64BIT
#endif

/* Remove definitions when CONFIG_MEMCPY_INDEXED_COPY is defined */

#if defined(CONFIG_MEMCPY_INDEXED_COPY)
#if defined(CONFIG_MEMCPY_PRE_INC_PTRS)
#undef CONFIG_MEMCPY_PRE_INC_PTRS
#endif							/* CONFIG_MEMCPY_PRE_INC_PTRS */
#endif							/* CONFIG_MEMCPY_INDEXED_COPY */

/* Definitions for pre and post increment of pointers */

#if defined(CONFIG_MEMCPY_PRE_INC_PTRS)

#define START_VAL(x)            (x)--
#define INC_VAL(x)              *++(x)
#define CAST_TO_U8(p, o)        ((uint8_t*)p + o + TYPE_WIDTH)
#define WHILE_DEST_BREAK        (TYPE_WIDTH - 1)
#define PRE_LOOP_ADJUST         - (TYPE_WIDTH - 1)
#define PRE_SWITCH_ADJUST       + 1

#else							/* CONFIG_MEMCPY_PRE_INC_PTRS */

#define START_VAL(x)
#define INC_VAL(x)              *(x)++
#define CAST_TO_U8(p, o)        ((uint8_t*)p + o)
#define WHILE_DEST_BREAK        0
#define PRE_LOOP_ADJUST
#define PRE_SWITCH_ADJUST

#endif							/* CONFIG_MEMCPY_PRE_INC_PTRS */

/* Definitions for endian-ness */

#ifdef CONFIG_ENDIAN_BIG

#define SHL <<
#define SHR >>

#else							/* CONFIG_ENDIAN_BIG */

#define SHL >>
#define SHR <<

#endif							/* CONFIG_ENDIAN_BIG */

/********************************************************************
 * Macros for copying words of  different alignment.
 * Uses incremening pointers.
 *******************************************************************/

#define CP_INCR()                         \
	do {                                  \
		INC_VAL(dstN) = INC_VAL(srcN);    \
	} while (0)

#define CP_INCR_SH(shl, shr)              \
	do {                                  \
		dstWord       = srcWord SHL shl;  \
		srcWord       = INC_VAL(srcN);    \
		dstWord      |= srcWord SHR shr;  \
		INC_VAL(dstN) = dstWord;          \
	} while (0)

/********************************************************************
 * Macros for copying words of  different alignment.
 * Uses array indexes.
 *******************************************************************/

#define CP_INDEX(idx)                     \
	do {                                  \
		dstN[idx] = srcN[idx];            \
	} while (0)

#define CP_INDEX_SH(x, shl, shr)          \
	do {                                  \
		dstWord   = srcWord SHL shl;      \
		srcWord   = srcN[x];              \
		dstWord  |= srcWord SHR shr;      \
		dstN[x]   = dstWord;              \
	} while (0)

/********************************************************************
 * Macros for copying words of different alignment.
 * Uses incremening pointers or array indexes depending on
 * configuration.
 *******************************************************************/

#if defined(CONFIG_MEMCPY_INDEXED_COPY)

#define CP(idx)               CP_INDEX(idx)
#define CP_SH(idx, shl, shr)  CP_INDEX_SH(idx, shl, shr)

#define INC_INDEX(p, o)       ((p) += (o))

#else							/* CONFIG_MEMCPY_INDEXED_COPY */

#define CP(idx)               CP_INCR()
#define CP_SH(idx, shl, shr)  CP_INCR_SH(shl, shr)

#define INC_INDEX(p, o)

#endif							/* CONFIG_MEMCPY_INDEXED_COPY */

#define COPY_REMAINING(count)                                     \
	do {                                                          \
		START_VAL(dst8);                                          \
		START_VAL(src8);                                          \
																  \
		switch (count) {                                          \
		case 7: INC_VAL(dst8) = INC_VAL(src8);                    \
		case 6: INC_VAL(dst8) = INC_VAL(src8);                    \
		case 5: INC_VAL(dst8) = INC_VAL(src8);                    \
		case 4: INC_VAL(dst8) = INC_VAL(src8);                    \
		case 3: INC_VAL(dst8) = INC_VAL(src8);                    \
		case 2: INC_VAL(dst8) = INC_VAL(src8);                    \
		case 1: INC_VAL(dst8) = INC_VAL(src8);                    \
		case 0:                                                   \
		default: break;                                           \
		}                                                         \
	} while (0)

#define COPY_NO_SHIFT()                                           \
	do {                                                          \
		UIntN* dstN = (UIntN*)(dst8 PRE_LOOP_ADJUST);             \
		UIntN* srcN = (UIntN*)(src8 PRE_LOOP_ADJUST);             \
		size_t length = count / TYPE_WIDTH;                       \
																  \
		while (length & 7) {                                      \
			CP_INCR();                                            \
			length--;                                             \
		}                                                         \
																  \
		length /= 8;                                              \
																  \
		while (length--) {                                        \
			CP(0);                                                \
			CP(1);                                                \
			CP(2);                                                \
			CP(3);                                                \
			CP(4);                                                \
			CP(5);                                                \
			CP(6);                                                \
			CP(7);                                                \
																  \
			INC_INDEX(dstN, 8);                                   \
			INC_INDEX(srcN, 8);                                   \
		}                                                         \
																  \
		src8 = CAST_TO_U8(srcN, 0);                               \
		dst8 = CAST_TO_U8(dstN, 0);                               \
																  \
		COPY_REMAINING(count & (TYPE_WIDTH - 1));                 \
																  \
		return dest;                                              \
	} while (0)

#define COPY_SHIFT(shift)                                         \
	do {                                                          \
		UIntN *dstN  = (UIntN *)((((uintptr_t)dst8) PRE_LOOP_ADJUST) & \
								 ~(TYPE_WIDTH - 1));              \
		UIntN *srcN  = (UIntN *)((((uintptr_t)src8) PRE_LOOP_ADJUST) & \
								 ~(TYPE_WIDTH - 1));              \
		size_t length  = count / TYPE_WIDTH;                      \
		UIntN srcWord = INC_VAL(srcN);                            \
		UIntN dstWord;                                            \
																  \
		while (length & 7) {                                      \
			CP_INCR_SH(8 * shift, 8 * (TYPE_WIDTH - shift));      \
			length--;                                             \
		}                                                         \
																  \
		length /= 8;                                              \
																  \
		while (length--) {                                        \
			CP_SH(0, 8 * shift, 8 * (TYPE_WIDTH - shift));        \
			CP_SH(1, 8 * shift, 8 * (TYPE_WIDTH - shift));        \
			CP_SH(2, 8 * shift, 8 * (TYPE_WIDTH - shift));        \
			CP_SH(3, 8 * shift, 8 * (TYPE_WIDTH - shift));        \
			CP_SH(4, 8 * shift, 8 * (TYPE_WIDTH - shift));        \
			CP_SH(5, 8 * shift, 8 * (TYPE_WIDTH - shift));        \
			CP_SH(6, 8 * shift, 8 * (TYPE_WIDTH - shift));        \
			CP_SH(7, 8 * shift, 8 * (TYPE_WIDTH - shift));        \
																  \
			INC_INDEX(dstN, 8);                                   \
			INC_INDEX(srcN, 8);                                   \
		}                                                         \
																  \
		src8 = CAST_TO_U8(srcN, (shift - TYPE_WIDTH));            \
		dst8 = CAST_TO_U8(dstN, 0);                               \
																  \
		COPY_REMAINING(count & (TYPE_WIDTH - 1));                 \
																  \
		return dest;                                              \
	} while (0)

/********************************************************************
 * Type Definitions
 *******************************************************************/

#ifdef CONFIG_MEMCPY_64BIT
typedef uint64_t UIntN;
#define TYPE_WIDTH        8L
#else
typedef uint32_t UIntN;
#define TYPE_WIDTH        4L
#endif

/********************************************************************
 * Public Functions
 *******************************************************************/
/********************************************************************
 * Name: memcpy
 *
 * Description:
 *   Copies count bytes from src to dest. No overlap check is performed.
 *
 * Input Parameters:
 *   dest        - pointer to destination buffer
 *   src         - pointer to source buffer
 *   count       - number of bytes to copy
 *
 * Returned Value:
 *   A pointer to destination buffer
 *
 *******************************************************************/
#if 0 /*[WizIO]*/
void *memcpy(void *dest, const void *src, size_t count)
{
	uint8_t *dst8 = (uint8_t *)dest;
	uint8_t *src8 = (uint8_t *)src;

	if (count < 8) {
		COPY_REMAINING(count);
		return dest;
	}

	START_VAL(dst8);
	START_VAL(src8);

	while (((uintptr_t)dst8 & (TYPE_WIDTH - 1)) != WHILE_DEST_BREAK) {
		INC_VAL(dst8) = INC_VAL(src8);
		count--;
	}

	switch ((((uintptr_t)src8) PRE_SWITCH_ADJUST) & (TYPE_WIDTH - 1)) {
	case 0:
		COPY_NO_SHIFT();
		break;
	case 1:
		COPY_SHIFT(1);
		break;
	case 2:
		COPY_SHIFT(2);
		break;
	case 3:
		COPY_SHIFT(3);
		break;
#if TYPE_WIDTH > 4
	case 4:
		COPY_SHIFT(4);
		break;
	case 5:
		COPY_SHIFT(5);
		break;
	case 6:
		COPY_SHIFT(6);
		break;
	case 7:
		COPY_SHIFT(7);
		break;
#endif
	}

	return dest;
}
#endif