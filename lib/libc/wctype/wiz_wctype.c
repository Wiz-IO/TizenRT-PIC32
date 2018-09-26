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
 * lib/libc/wctype/lib_iswctype.c
 *
 *    Copyright (c) 2002 Red Hat Incorporated.
 *    All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 *   The name of Red Hat Incorporated may not be used to endorse
 *   or promote products derived from this software without specific
 *   prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL RED HAT INCORPORATED BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <errno.h>

#ifdef CONFIG_LIBC_WCHAR

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int iswalnum(wint_t c)
{
	return (iswalpha(c) || iswdigit(c));
}

int iswalpha(wint_t c)
{
	return (c < (wint_t) 0x100 ? isalpha(c) : 0);
}

int iswblank(wint_t c)
{
	return (c < (wint_t) 0x100 ? isblank(c) : 0);
}

int iswcntrl(wint_t c)
{
	return (c < (wint_t) 0x100 ? iscntrl(c) : 0);
}

int iswdigit(wint_t c)
{
	return (c >= (wint_t) '0' && c <= (wint_t) '9');
}

int iswgraph(wint_t c)
{
	return (iswprint(c) && !iswspace(c));
}

int iswlower(wint_t c)
{
	return (towupper(c) != c);
}

int iswprint(wint_t c)
{
	return (c < (wint_t) 0x100 ? isprint(c) : 0);
}

int iswpunct(wint_t c)
{
	return (!iswalnum(c) && iswgraph(c));
}

int iswspace(wint_t c)
{
	return (c < 0x100 ? isspace(c) : 0);
}

int iswupper(wint_t c)
{
	return (towlower(c) != c);
}

int iswxdigit(wint_t c)
{
	return ((c >= (wint_t) '0' && c <= (wint_t) '9') || (c >= (wint_t) 'a' && c <= (wint_t) 'f') || (c >= (wint_t) 'A' && c <= (wint_t) 'F'));
}

int iswctype(wint_t c, wctype_t desc)
{
	switch (desc) {
	case WC_ALNUM:
		return iswalnum(c);

	case WC_ALPHA:
		return iswalpha(c);

	case WC_BLANK:
		return iswblank(c);

	case WC_CNTRL:
		return iswcntrl(c);

	case WC_DIGIT:
		return iswdigit(c);

	case WC_GRAPH:
		return iswgraph(c);

	case WC_LOWER:
		return iswlower(c);

	case WC_PRINT:
		return iswprint(c);

	case WC_PUNCT:
		return iswpunct(c);

	case WC_SPACE:
		return iswspace(c);

	case WC_UPPER:
		return iswupper(c);

	case WC_XDIGIT:
		return iswxdigit(c);

	default:
		return 0;				/* eliminate warning */
	}

	/* Otherwise unknown */

	return 0;
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
 * lib/libc/wchar/lib_towlower.c
 *
 *    Copyright (c) 2002 Red Hat Incorporated.
 *    All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 *   The name of Red Hat Incorporated may not be used to endorse
 *   or promote products derived from this software without specific
 *   prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL RED HAT INCORPORATED BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>

#ifdef CONFIG_LIBC_WCHAR

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: towlower
 *
 * Description:
 *   The  towlower() function is the wide-character equivalent of the
 *   tolower() function.  If c is an uppercase wide character, and there
 *   exists a lowercase equivalent in the current locale, it returns the
 *   lowercase  equivalent  of c. This current code don't use locale.
 *
 ****************************************************************************/

wint_t towlower(wint_t c)
{
	return (c < (wint_t) 0x00ff ? (wint_t) tolower((int)c) : c);
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
 * lib/libc/wchar/lib_towupper.c
 *
 *    Copyright (c) 2002 Red Hat Incorporated.
 *    All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 *   The name of Red Hat Incorporated may not be used to endorse
 *   or promote products derived from this software without specific
 *   prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL RED HAT INCORPORATED BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>

#ifdef CONFIG_LIBC_WCHAR

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: towupper
 *
 * Description:
 *   The  towupper() function is the wide-character equivalent of the
 *   toupper() function.  If c is an lowercase wide character, and there
 *   exists a uppercase equivalent in the current locale, it returns the
 *   uppercase  equivalent  of c. This current code don't use locale.
 *
 ****************************************************************************/

wint_t towupper(wint_t c)
{
	return (c < (wint_t) 0x00ff ? (wint_t) toupper((int)c) : c);
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
 * lib/libc/wctype/wctype.c
 *
 *    Copyright (c) 2002 Red Hat Incorporated.
 *    All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 *   The name of Red Hat Incorporated may not be used to endorse
 *   or promote products derived from this software without specific
 *   prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL RED HAT INCORPORATED BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <string.h>
#include <wctype.h>
#include <errno.h>

#ifdef CONFIG_LIBC_WCHAR

/****************************************************************************
 * Public Functions
 ****************************************************************************/

wctype_t wctype(FAR const char *c)
{
	switch (*c) {
	case 'a':
		if (!strcmp(c, "alnum")) {
			return WC_ALNUM;
		} else if (!strcmp(c, "alpha")) {
			return WC_ALPHA;
		}

		break;

	case 'b':
		if (!strcmp(c, "blank")) {
			return WC_BLANK;
		}

		break;

	case 'c':
		if (!strcmp(c, "cntrl")) {
			return WC_CNTRL;
		}

		break;

	case 'd':
		if (!strcmp(c, "digit")) {
			return WC_DIGIT;
		}

		break;

	case 'g':
		if (!strcmp(c, "graph")) {
			return WC_GRAPH;
		}

		break;

	case 'l':
		if (!strcmp(c, "lower")) {
			return WC_LOWER;
		}

		break;

	case 'p':
		if (!strcmp(c, "print")) {
			return WC_PRINT;
		} else if (!strcmp(c, "punct")) {
			return WC_PUNCT;
		}

		break;

	case 's':
		if (!strcmp(c, "space")) {
			return WC_SPACE;
		}

		break;

	case 'u':
		if (!strcmp(c, "upper")) {
			return WC_UPPER;
		}

		break;

	case 'x':
		if (!strcmp(c, "xdigit")) {
			return WC_XDIGIT;
		}

		break;
	}

	return 0;
}
#endif
   