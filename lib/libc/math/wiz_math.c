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
 * libc/math/lib_acos.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

#include <tinyara/compiler.h>
#include <tinyara/math.h>

/************************************************************************
 * Private Data
 ************************************************************************/

static const unsigned
B1 = 709958130,				/* B1 = (127-127.0/3-0.03306235651)*2**23 */
B2 = 642849266;				/* B2 = (127-127.0/3-24/3-0.03306235651)*2**23 */




/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double acos(double x)
{
	return (M_PI_2 - asin(x));
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
 * libc/math/lib_acosf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float acosf(float x)
{
	return (M_PI_2 - asinf(x));
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
 * libc/math/lib_acosh.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double acosh(double x)
{
	return log(x + sqrt(x * x - 1));
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
 * libc/math/lib_acoshf.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float acoshf(float x)
{
	return logf(x + sqrtf(x * x - 1));
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
 * libc/math/lib_acoshl.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double acoshl(long double x)
{
	return logl(x + sqrtl(x * x - 1));
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
 * libc/math/lib_acos.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double acosl(long double x)
{
	return (M_PI_2 - asinl(x));
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
 * libc/math/lib_sin.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <float.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double asin(double x)
{
	long double y;
	long double y_sin;
	long double y_cos;

	y = 0;

	while (1) {
		y_sin = sin(y);
		y_cos = cos(y);

		if (y > M_PI_2 || y < -M_PI_2) {
			y = fmod(y, M_PI);
		}

		if (y_sin + DBL_EPSILON >= x && y_sin - DBL_EPSILON <= x) {
			break;
		}

		y = y - (y_sin - x) / y_cos;
	}

	return y;
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
 * libc/math/lib_sinf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>
#include <float.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float asinf(float x)
{
	long double y;
	long double y_sin;
	long double y_cos;

	y = 0;

	while (1) {
		y_sin = sinf(y);
		y_cos = cosf(y);

		if (y > M_PI_2 || y < -M_PI_2) {
			y = fmodf(y, M_PI);
		}

		if (y_sin + FLT_EPSILON >= x && y_sin - FLT_EPSILON <= x) {
			break;
		}

		y = y - (y_sin - x) / y_cos;
	}

	return y;
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
 * libc/math/lib_asinh.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double asinh(double x)
{
	return log(x + sqrt(x * x + 1));
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
 * libc/math/lib_asinhf.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float asinhf(float x)
{
	return logf(x + sqrtf(x * x + 1));
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
 * libc/math/lib_asinhl.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double asinhl(long double x)
{
	return logl(x + sqrtl(x * x + 1));
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
 * libc/math/lib_sinl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <float.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double asinl(long double x)
{
	long double y;
	long double y_sin;
	long double y_cos;

	y = 0;

	while (1) {
		y_sin = sinl(y);
		y_cos = cosl(y);

		if (y > M_PI_2 || y < -M_PI_2) {
			y = fmodl(y, M_PI);
		}

		if (y_sin + LDBL_EPSILON >= x && y_sin - LDBL_EPSILON <= x) {
			break;
		}

		y = y - (y_sin - x) / y_cos;
	}

	return y;
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
 * libc/math/lib_atan.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <stddef.h>
#include <stdint.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double atan(double x)
{
	return asin(x / sqrt(x * x + 1));
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
 * libc/math/lib_atan2.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double atan2(double y, double x)
{
	if (x > 0) {
		return atan(y / x);
	} else if (y >= 0 && x < 0) {
		return atan(y / x) + M_PI;
	} else if (y < 0) {
		if (x == 0) {
			return -M_PI_2;
		} else {				/* Can only be x < 0 */

			return atan(y / x) - M_PI;
		}
	} else if (y > 0 && x == 0) {
		return M_PI_2;
	} else {					/* if (y == 0 && x == 0) Undefined but returns normally 0 */

		return 0;
	}
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
 * libc/math/lib_atan2f.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float atan2f(float y, float x)
{
	if (x > 0) {
		return atanf(y / x);
	} else if (y >= 0 && x < 0) {
		return atanf(y / x) + M_PI;
	} else if (y < 0) {
		if (x == 0) {
			return -M_PI_2;
		} else {				/* Can only be x < 0 */

			return atanf(y / x) - M_PI;
		}
	} else if (y > 0 && x == 0) {
		return M_PI_2;
	} else {					/* if (y == 0 && x == 0) Undefined but returns normally 0 */

		return 0;
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
/************************************************************************
 * libc/math/lib_atan2l.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double atan2l(long double y, long double x)
{
	if (x > 0) {
		return atanl(y / x);
	} else if (y >= 0 && x < 0) {
		return atanl(y / x) + M_PI;
	} else if (y < 0) {
		if (x == 0) {
			return -M_PI_2;
		} else {				/* Can only be x < 0 */

			return atanl(y / x) - M_PI;
		}
	} else if (y > 0 && x == 0) {
		return M_PI_2;
	} else {					/* if (y == 0 && x == 0) Undefined but returns normally 0 */

		return 0;
	}
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
 * libc/math/lib_atanf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float atanf(float x)
{
	return asinf(x / sqrtf(x * x + 1));
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
 * libc/math/lib_atanh.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double atanh(double x)
{
	return 0.5 * log((1 + x) / (1 - x));
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
 * libc/math/lib_atanhf.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float atanhf(float x)
{
	return 0.5 * logf((1 + x) / (1 - x));
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
 * libc/math/lib_atanhl.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
long double atanhl(long double x)
{
	return 0.5 * logl((1 + x) / (1 - x));
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
 * libc/math/lib_atanl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double atanl(long double x)
{
	return asinl(x / sqrtl(x * x + 1));
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
 * origin: FreeBSD /usr/src/lib/msun/src/s_cbrt.c
 *
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 * Optimized by Bruce D. Evans.

 * cbrt(x)
 * Return cube root of x
 *
 ***************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <stdint.h>

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Private Data
 ************************************************************************/
//static const uint32_t 
//B1 = 715094163,	/* B1 = (1023-1023/3-0.03306235651)*2**20 */
//B2 = 696219795;	/* B2 = (1023-1023/3-54/3-0.03306235651)*2**20 */

/* |1/cbrt(x) - p(x)| < 2**-23.5 (~[-7.93e-8, 7.929e-8]). */
static const double
P0 = 1.87595182427177009643,	/* 0x3ffe03e6, 0x0f61e692 */
P1 = -1.88497979543377169875,	/* 0xbffe28e0, 0x92f02420 */
P2 = 1.621429720105354466140,	/* 0x3ff9f160, 0x4a49d6c2 */
P3 = -0.758397934778766047437,	/* 0xbfe844cb, 0xbee751d9 */
P4 = 0.145996192886612446982;	/* 0x3fc2b000, 0xd4e4edd7 */

/************************************************************************
 * Public Functions
 ************************************************************************/

double cbrt(double x)
{
	union {
		double f;
		uint64_t i;
	} u = {
		x
	};
	double r;
	double s;
	double t;
	double w;
	uint32_t hx = u.i >> 32 & 0x7fffffff;

	if (hx >= 0x7ff00000) {		/* cbrt(NaN,INF) is itself */
		return x + x;
	}

	/*
	 * Rough cbrt to 5 bits:
	 *    cbrt(2**e*(1+m) ~= 2**(e/3)*(1+(e%3+m)/3)
	 * where e is integral and >= 0, m is real and in [0, 1), and "/" and
	 * "%" are integer division and modulus with rounding towards minus
	 * infinity.  The RHS is always >= the LHS and has a maximum relative
	 * error of about 1 in 16.  Adding a bias of -0.03306235651 to the
	 * (e%3+m)/3 term reduces the error to about 1 in 32. With the IEEE
	 * floating point representation, for finite positive normal values,
	 * ordinary integer divison of the value in bits magically gives
	 * almost exactly the RHS of the above provided we first subtract the
	 * exponent bias (1023 for doubles) and later add it back.  We do the
	 * subtraction virtually to keep e >= 0 so that ordinary integer
	 * division rounds towards minus infinity; this is also efficient.
	 */
	if (hx < 0x00100000) {		/* zero or subnormal? */
		u.f = x * 0x1p54;
		hx = u.i >> 32 & 0x7fffffff;
		if (hx == 0) {
			return x;			/* cbrt(0) is itself */
		}
		hx = hx / 3 + B2;
	} else {
		hx = hx / 3 + B1;
	}
	u.i &= 1ULL << 63;
	u.i |= (uint64_t) hx << 32;
	t = u.f;

	/*
	 * New cbrt to 23 bits:
	 *    cbrt(x) = t*cbrt(x/t**3) ~= t*P(t**3/x)
	 * where P(r) is a polynomial of degree 4 that approximates 1/cbrt(r)
	 * to within 2**-23.5 when |r - 1| < 1/10.  The rough approximation
	 * has produced t such than |t/cbrt(x) - 1| ~< 1/32, and cubing this
	 * gives us bounds for r = t**3/x.
	 *
	 * Try to optimize for parallel evaluation as in __tanf.c.
	 */
	r = (t * t) * (t / x);
	t = t * ((P0 + r * (P1 + r * P2)) + ((r * r) * r) * (P3 + r * P4));

	/*
	 * Round t away from zero to 23 bits (sloppily except for ensuring that
	 * the result is larger in magnitude than cbrt(x) but not much more than
	 * 2 23-bit ulps larger).  With rounding towards zero, the error bound
	 * would be ~5/6 instead of ~4/6.  With a maximum error of 2 23-bit ulps
	 * in the rounded t, the infinite-precision error in the Newton
	 * approximation barely affects third digit in the final error
	 * 0.667; the error in the rounded t can be up to about 3 23-bit ulps
	 * before the final error is larger than 0.667 ulps.
	 */
	u.f = t;
	u.i = (u.i + 0x80000000) & 0xffffffffc0000000ULL;
	t = u.f;

	/* one step Newton iteration to 53 bits with error < 0.667 ulps */
	s = t * t;					/* t*t is exact */
	r = x / s;					/* error <= 0.5 ulps; |r| < |t| */
	w = t + t;					/* t+t is exact */
	r = (r - t) / (w + r);		/* r-t is exact; w+r ~= 3*t */
	t = t + t * r;				/* error <= 0.5 + 0.5/3 + epsilon */
	return t;
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
 * origin: FreeBSD /usr/src/lib/msun/src/s_cbrtf.c
 *
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 * Debugged and optimized by Bruce D. Evans.
 *
 *
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 * cbrtf(x)
 * Return cube root of x
 ***************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <stdint.h>


/************************************************************************
 * Public Functions
 ************************************************************************/

float cbrtf(float x)
{
	double r;
	double T;
	union {
		float f;
		uint32_t i;
	} u = {
		x
	};
	uint32_t hx = u.i & 0x7fffffff;

	if (hx >= 0x7f800000) {		/* cbrt(NaN,INF) is itself */
		return x + x;
	}

	/* rough cbrt to 5 bits */
	if (hx < 0x00800000) {		/* zero or subnormal? */
		if (hx == 0) {
			return x;			/* cbrt(+-0) is itself */
		}
		u.f = x * 0x1p24f;
		hx = u.i & 0x7fffffff;
		hx = hx / 3 + B2;
	} else {
		hx = hx / 3 + B1;
	}
	u.i &= 0x80000000;
	u.i |= hx;

	/*
	 * First step Newton iteration (solving t*t-x/t == 0) to 16 bits.  In
	 * double precision so that its terms can be arranged for efficiency
	 * without causing overflow or underflow.
	 */
	T = u.f;
	r = T * T * T;
	T = T * ((double)x + x + r) / (x + r + r);

	/*
	 * Second step Newton iteration to 47 bits.  In double precision for
	 * efficiency and accuracy.
	 */
	r = T * T * T;
	T = T * ((double)x + x + r) / (x + r + r);

	/* rounding to 24 bits is perfect in round-to-nearest mode */
	return T;
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
 * origin: FreeBSD /usr/src/lib/msun/src/s_cbrtl.c
 *
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Copyright (c) 2009-2011, Bruce D. Evans, Steven G. Kargl, David Schultz.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 * The argument reduction and testing for exceptional cases was
 * written by Steven G. Kargl with input from Bruce D. Evans
 * and David A. Schultz.
 ***************************************************************************/

/****************************************************************************
 *	Included Files
 ***************************************************************************/

#include <tinyara/compiler.h>

#include "libm.h"

/****************************************************************************
 *	Public Fuctions
 ***************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double cbrtl(long double x)
{
	return cbrt(x);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384

/************************************************************************
 * Private Data
 ************************************************************************/
//static const unsigned B1 = 709958130;	/* B1 = (127-127.0/3-0.03306235651)*2**23 */

long double cbrtl(long double x)
{
	union ldshape u = { x }, v;
	union {
		float f;
		uint32_t i;
	} uft;
	long double r;
	long double s;
	long double t;
	long double w;
	double_t dr;
	double_t dt;
	double_t dx;
	float_t ft;
	int e = u.i.se & 0x7fff;
	int sign = u.i.se & 0x8000;

	/*
	 * If x = +-Inf, then cbrt(x) = +-Inf.
	 * If x = NaN, then cbrt(x) = NaN.
	 */
	if (e == 0x7fff) {
		return x + x;
	}
	if (e == 0) {
		/* Adjust subnormal numbers. */
		u.f *= 0x1p120;
		e = u.i.se & 0x7fff;
		/* If x = +-0, then cbrt(x) = +-0. */
		if (e == 0) {
			return x;
		}
		e -= 120;
	}
	e -= 0x3fff;
	u.i.se = 0x3fff;
	x = u.f;
	switch (e % 3) {
	case 1:
	case -2:
		x *= 2;
		e--;
		break;
	case 2:
	case -1:
		x *= 4;
		e -= 2;
		break;
	}
	v.f = 1.0;
	v.i.se = sign | (0x3fff + e / 3);

	/*
	 * The following is the guts of s_cbrtf, with the handling of
	 * special values removed and extra care for accuracy not taken,
	 * but with most of the extra accuracy not discarded.
	 */

	/* ~5-bit estimate: */
	uft.f = x;
	uft.i = (uft.i & 0x7fffffff) / 3 + B1;
	ft = uft.f;

	/* ~16-bit estimate: */
	dx = x;
	dt = ft;
	dr = dt * dt * dt;
	dt = dt * (dx + dx + dr) / (dx + dr + dr);

	/* ~47-bit estimate: */
	dr = dt * dt * dt;
	dt = dt * (dx + dx + dr) / (dx + dr + dr);

#if LDBL_MANT_DIG == 64
	/*
	 * dt is cbrtl(x) to ~47 bits (after x has been reduced to 1 <= x < 8).
	 * Round it away from zero to 32 bits (32 so that t*t is exact, and
	 * away from zero for technical reasons).
	 */
	t = dt + (0x1.0p32L + 0x1.0p-31L) - 0x1.0p32;
#elif LDBL_MANT_DIG == 113
	/*
	 * Round dt away from zero to 47 bits.  Since we don't trust the 47,
	 * add 2 47-bit ulps instead of 1 to round up.  Rounding is slow and
	 * might be avoidable in this case, since on most machines dt will
	 * have been evaluated in 53-bit precision and the technical reasons
	 * for rounding up might not apply to either case in cbrtl() since
	 * dt is much more accurate than needed.
	 */
	t = dt + 0x2.0p-46 + 0x1.0p60L-0x1.0p60;
#endif

	/*
	 * Final step Newton iteration to 64 or 113 bits with
	 * error < 0.667 ulps
	 */
	s = t * t;					/* t*t is exact */
	r = x / s;					/* error <= 0.5 ulps; |r| < |t| */
	w = t + t;					/* t+t is exact */
	r = (r - t) / (w + r);		/* r-t is exact; w+r ~= 3*t */
	t = t + t * r;				/* error <= 0.5 + 0.5/3 + epsilon */

	t *= v.f;
	return t;
}
#endif
#endif
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
/************************************************************************
 * libc/math/lib_ceil.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double ceil(double x)
{
	double x1 = x;

	modf(x, &x);
	if (x1 > 0.0 && fabs(x1 - x) > 0.0) {
		x += 1.0;
	}

	return x;
}
#endif
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
/************************************************************************
 * libc/math/lib_ceilf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float ceilf(float x)
{
	float x1 = x;

	modff(x, &x);
	if (x1 > 0.0 && fabsf(x1 - x) > 0.0) {
		x += 1.0;
	}

	return x;
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
/************************************************************************
 * libc/math/lib_ceil.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double ceill(long double x)
{
	long double x1 = x;

	modfl(x, &x);
	if (x1 > 0.0 && fabsl(x1 - x) > 0.0) {
		x += 1.0;
	}

	return x;
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
 * libc/math/lib_copysign.c
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Authors: Gregory Nutt <gnutt@nuttx.org>
 *            Dave Marples <dave@marples.net>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double copysign(double x, double y)
{
	if (y < 0) {
		return -fabs(x);
	}

	return fabs(x);
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
 * libc/math/lib_copysignf.c
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Authors: Gregory Nutt <gnutt@nuttx.org>
 *            Dave Marples <dave@marples.net>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float copysignf(float x, float y)
{
	if (y < 0) {
		return -fabsf(x);
	}

	return fabsf(x);
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
 * libc/math/lib_copysignl.c
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Authors: Gregory Nutt <gnutt@nuttx.org>
 *            Dave Marples <dave@marples.net>
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double copysignl(long double x, long double y)
{
	if (y < 0) {
		return -fabsl(x);
	}

	return fabsl(x);
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
 * libc/math/lib_cos.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double cos(double x)
{
	return sin(x + M_PI_2);
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
 * libc/math/lib_cosf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float cosf(float x)
{
	return sinf(x + M_PI_2);
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
 * libc/math/lib_cosh.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double cosh(double x)
{
	x = exp(x);
	return ((x + (1.0 / x)) / 2.0);
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
 * libc/math/lib_coshf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float coshf(float x)
{
	x = expf(x);
	return ((x + (1.0 / x)) / 2.0);
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
 * libc/math/lib_coshl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double coshl(long double x)
{
	x = expl(x);
	return ((x + (1.0 / x)) / 2.0);
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
 * libc/math/lib_cosl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double cosl(long double x)
{
	return sinl(x + M_PI_2);
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
 * libc/math/lib_erf.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

#include <math.h>

#ifdef CONFIG_HAVE_DOUBLE

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define  A1     0.254829592
#define  A2   (-0.284496736)
#define  A3     1.421413741
#define  A4   (-1.453152027)
#define  A5     1.061405429
#define  P      0.3275911

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: erf
 *
 * Description:
 *   This implementation comes from the Handbook of Mathmatical Functions
 *   The implementations in this book are not protected by copyright.
 *   erf comes from formula 7.1.26
 *
 ****************************************************************************/

double erf(double x)
{
  double t;
  double z;

  z = fabs(x);
  t = 1.0 / (1.0 + P * z);
  t = 1.0 - (((((A5 * t + A4) * t) + A3) * t + A2) * t + A1) * t * exp(-z * z);
  return copysign(t, x);
}

#endif /* CONFIG_HAVE_DOUBLE */
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
 * libc/math/lib_erff.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

#include <math.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define  A1     0.254829592F
#define  A2   (-0.284496736F)
#define  A3     1.421413741F
#define  A4   (-1.453152027F)
#define  A5     1.061405429F
#define  P      0.3275911F

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: erff
 *
 * Description:
 *   This implementation comes from the Handbook of Mathmatical Functions
 *   The implementations in this book are not protected by copyright.
 *   erf comes from formula 7.1.26
 *
 ****************************************************************************/

float erff(float x)
{
  float t;
  float z;

  z = fabsf(x);
  t = 1.0F / (1.0F + P * z);
  t = 1.0F - (((((A5 * t + A4) * t) + A3) * t + A2) * t + A1) * t * expf(-z * z);
  return copysignf(t, x);
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
 * libc/math/lib_erfl.c
 *
 *   Copyright (C) 2015 Brennan Ashton. All rights reserved.
 *   Author: Brennan Ashton <bashton@brennanashton.com>
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

#include <math.h>

#ifdef CONFIG_HAVE_LONG_DOUBLE

/****************************************************************************
 * Public Functions
 ****************************************************************************/

#define  A1     0.254829592
#define  A2   (-0.284496736)
#define  A3     1.421413741
#define  A4   (-1.453152027)
#define  A5     1.061405429
#define  P      0.3275911

long double erfl(long double x)
{
  /* This implementation comes from the Handbook of Mathmatical Functions
   * The implementations in this book are not protected by copyright.
   * erf comes from formula 7.1.26
   */

  long double t, z;

  z = fabsl(x);
  t = 1.0 / (1.0 + P * z);
  t = 1.0 - (((((A5 * t + A4) * t) + A3) * t + A2) * t + A1) * t * expl(-z * z);
  return copysignl(t, x);
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
 * libc/math/lib_exp.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <sys/types.h>
#include <math.h>

#include "lib_internal.h"

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Private Data
 ************************************************************************/

static double _dbl_inv_fact[] = {
	1.0 / 1.0,					/* 1 / 0! */
	1.0 / 1.0,					/* 1 / 1! */
	1.0 / 2.0,					/* 1 / 2! */
	1.0 / 6.0,					/* 1 / 3! */
	1.0 / 24.0,					/* 1 / 4! */
	1.0 / 120.0,				/* 1 / 5! */
	1.0 / 720.0,				/* 1 / 6! */
	1.0 / 5040.0,				/* 1 / 7! */
	1.0 / 40320.0,				/* 1 / 8! */
	1.0 / 362880.0,				/* 1 / 9! */
	1.0 / 3628800.0,			/* 1 / 10! */
	1.0 / 39916800.0,			/* 1 / 11! */
	1.0 / 479001600.0,			/* 1 / 12! */
	1.0 / 6227020800.0,			/* 1 / 13! */
	1.0 / 87178291200.0,		/* 1 / 14! */
	1.0 / 1307674368000.0,		/* 1 / 15! */
	1.0 / 20922789888000.0,		/* 1 / 16! */
	1.0 / 355687428096000.0,	/* 1 / 17! */
	1.0 / 6402373705728000.0,	/* 1 / 18! */
};

/************************************************************************
 * Public Functions
 ************************************************************************/

double exp(double x)
{
	size_t int_part;
	bool invert;
	double value;
	double x0;
	size_t i;

	if (x == 0) {
		return 1;
	} else if (x < 0) {
		invert = true;
		x = -x;
	} else {
		invert = false;
	}

	/* Extract integer component */

	int_part = (size_t)x;

	/* Set x to fractional component */

	x -= (double)int_part;

	/* Perform Taylor series approximation with nineteen terms */

	value = 0.0;
	x0 = 1.0;
	for (i = 0; i < 19; i++) {
		value += x0 * _dbl_inv_fact[i];
		x0 *= x;
	}

	/* Multiply by exp of the integer component */

	value *= lib_expi(int_part);

	if (invert) {
		return (1.0 / value);
	} else {
		return value;
	}
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
 * origin: FreeBSD /usr/src/lib/msun/src/s_exp2.c
 *
 * Copyright (c) 2005 David Schultz <das@FreeBSD.ORG>
 * All rights reserved.
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
 ***************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include "libm.h"

#ifdef CONFIG_HAVE_DOUBLE

#define TBLSIZE 256

/************************************************************************
 * Private Data
 ************************************************************************/

static const double redux = 0x1.8p52 / TBLSIZE;
static const double P1 = 0x1.62e42fefa39efp-1;
static const double P2 = 0x1.ebfbdff82c575p-3;
static const double P3 = 0x1.c6b08d704a0a6p-5;
static const double P4 = 0x1.3b2ab88f70400p-7;
static const double P5 = 0x1.5d88003875c74p-10;

static const double tbl[TBLSIZE * 2] = {
	/* exp2(z +eps)         eps     */
	0x1.6a09e667f3d5dp-1, 0x1.9880p-44,
	0x1.6b052fa751744p-1, 0x1.8000p-50,
	0x1.6c012750bd9fep-1, -0x1.8780p-45,
	0x1.6cfdcddd476bfp-1, 0x1.ec00p-46,
	0x1.6dfb23c651a29p-1, -0x1.8000p-50,
	0x1.6ef9298593ae3p-1, -0x1.c000p-52,
	0x1.6ff7df9519386p-1, -0x1.fd80p-45,
	0x1.70f7466f42da3p-1, -0x1.c880p-45,
	0x1.71f75e8ec5fc3p-1, 0x1.3c00p-46,
	0x1.72f8286eacf05p-1, -0x1.8300p-44,
	0x1.73f9a48a58152p-1, -0x1.0c00p-47,
	0x1.74fbd35d7ccfcp-1, 0x1.f880p-45,
	0x1.75feb564267f1p-1, 0x1.3e00p-47,
	0x1.77024b1ab6d48p-1, -0x1.7d00p-45,
	0x1.780694fde5d38p-1, -0x1.d000p-50,
	0x1.790b938ac1d00p-1, 0x1.3000p-49,
	0x1.7a11473eb0178p-1, -0x1.d000p-49,
	0x1.7b17b0976d060p-1, 0x1.0400p-45,
	0x1.7c1ed0130c133p-1, 0x1.0000p-53,
	0x1.7d26a62ff8636p-1, -0x1.6900p-45,
	0x1.7e2f336cf4e3bp-1, -0x1.2e00p-47,
	0x1.7f3878491c3e8p-1, -0x1.4580p-45,
	0x1.80427543e1b4ep-1, 0x1.3000p-44,
	0x1.814d2add1071ap-1, 0x1.f000p-47,
	0x1.82589994ccd7ep-1, -0x1.1c00p-45,
	0x1.8364c1eb942d0p-1, 0x1.9d00p-45,
	0x1.8471a4623cab5p-1, 0x1.7100p-43,
	0x1.857f4179f5bbcp-1, 0x1.2600p-45,
	0x1.868d99b4491afp-1, -0x1.2c40p-44,
	0x1.879cad931a395p-1, -0x1.3000p-45,
	0x1.88ac7d98a65b8p-1, -0x1.a800p-45,
	0x1.89bd0a4785800p-1, -0x1.d000p-49,
	0x1.8ace5422aa223p-1, 0x1.3280p-44,
	0x1.8be05bad619fap-1, 0x1.2b40p-43,
	0x1.8cf3216b54383p-1, -0x1.ed00p-45,
	0x1.8e06a5e08664cp-1, -0x1.0500p-45,
	0x1.8f1ae99157807p-1, 0x1.8280p-45,
	0x1.902fed0282c0ep-1, -0x1.cb00p-46,
	0x1.9145b0b91ff96p-1, -0x1.5e00p-47,
	0x1.925c353aa2ff9p-1, 0x1.5400p-48,
	0x1.93737b0cdc64ap-1, 0x1.7200p-46,
	0x1.948b82b5f98aep-1, -0x1.9000p-47,
	0x1.95a44cbc852cbp-1, 0x1.5680p-45,
	0x1.96bdd9a766f21p-1, -0x1.6d00p-44,
	0x1.97d829fde4e2ap-1, -0x1.1000p-47,
	0x1.98f33e47a23a3p-1, 0x1.d000p-45,
	0x1.9a0f170ca0604p-1, -0x1.8a40p-44,
	0x1.9b2bb4d53ff89p-1, 0x1.55c0p-44,
	0x1.9c49182a3f15bp-1, 0x1.6b80p-45,
	0x1.9d674194bb8c5p-1, -0x1.c000p-49,
	0x1.9e86319e3238ep-1, 0x1.7d00p-46,
	0x1.9fa5e8d07f302p-1, 0x1.6400p-46,
	0x1.a0c667b5de54dp-1, -0x1.5000p-48,
	0x1.a1e7aed8eb8f6p-1, 0x1.9e00p-47,
	0x1.a309bec4a2e27p-1, 0x1.ad80p-45,
	0x1.a42c980460a5dp-1, -0x1.af00p-46,
	0x1.a5503b23e259bp-1, 0x1.b600p-47,
	0x1.a674a8af46213p-1, 0x1.8880p-44,
	0x1.a799e1330b3a7p-1, 0x1.1200p-46,
	0x1.a8bfe53c12e8dp-1, 0x1.6c00p-47,
	0x1.a9e6b5579fcd2p-1, -0x1.9b80p-45,
	0x1.ab0e521356fb8p-1, 0x1.b700p-45,
	0x1.ac36bbfd3f381p-1, 0x1.9000p-50,
	0x1.ad5ff3a3c2780p-1, 0x1.4000p-49,
	0x1.ae89f995ad2a3p-1, -0x1.c900p-45,
	0x1.afb4ce622f367p-1, 0x1.6500p-46,
	0x1.b0e07298db790p-1, 0x1.fd40p-45,
	0x1.b20ce6c9a89a9p-1, 0x1.2700p-46,
	0x1.b33a2b84f1a4bp-1, 0x1.d470p-43,
	0x1.b468415b747e7p-1, -0x1.8380p-44,
	0x1.b59728de5593ap-1, 0x1.8000p-54,
	0x1.b6c6e29f1c56ap-1, 0x1.ad00p-47,
	0x1.b7f76f2fb5e50p-1, 0x1.e800p-50,
	0x1.b928cf22749b2p-1, -0x1.4c00p-47,
	0x1.ba5b030a10603p-1, -0x1.d700p-47,
	0x1.bb8e0b79a6f66p-1, 0x1.d900p-47,
	0x1.bcc1e904bc1ffp-1, 0x1.2a00p-47,
	0x1.bdf69c3f3a16fp-1, -0x1.f780p-46,
	0x1.bf2c25bd71db8p-1, -0x1.0a00p-46,
	0x1.c06286141b2e9p-1, -0x1.1400p-46,
	0x1.c199bdd8552e0p-1, 0x1.be00p-47,
	0x1.c2d1cd9fa64eep-1, -0x1.9400p-47,
	0x1.c40ab5fffd02fp-1, -0x1.ed00p-47,
	0x1.c544778fafd15p-1, 0x1.9660p-44,
	0x1.c67f12e57d0cbp-1, -0x1.a100p-46,
	0x1.c7ba88988c1b6p-1, -0x1.8458p-42,
	0x1.c8f6d9406e733p-1, -0x1.a480p-46,
	0x1.ca3405751c4dfp-1, 0x1.b000p-51,
	0x1.cb720dcef9094p-1, 0x1.1400p-47,
	0x1.ccb0f2e6d1689p-1, 0x1.0200p-48,
	0x1.cdf0b555dc412p-1, 0x1.3600p-48,
	0x1.cf3155b5bab3bp-1, -0x1.6900p-47,
	0x1.d072d4a0789bcp-1, 0x1.9a00p-47,
	0x1.d1b532b08c8fap-1, -0x1.5e00p-46,
	0x1.d2f87080d8a85p-1, 0x1.d280p-46,
	0x1.d43c8eacaa203p-1, 0x1.1a00p-47,
	0x1.d5818dcfba491p-1, 0x1.f000p-50,
	0x1.d6c76e862e6a1p-1, -0x1.3a00p-47,
	0x1.d80e316c9834ep-1, -0x1.cd80p-47,
	0x1.d955d71ff6090p-1, 0x1.4c00p-48,
	0x1.da9e603db32aep-1, 0x1.f900p-48,
	0x1.dbe7cd63a8325p-1, 0x1.9800p-49,
	0x1.dd321f301b445p-1, -0x1.5200p-48,
	0x1.de7d5641c05bfp-1, -0x1.d700p-46,
	0x1.dfc97337b9aecp-1, -0x1.6140p-46,
	0x1.e11676b197d5ep-1, 0x1.b480p-47,
	0x1.e264614f5a3e7p-1, 0x1.0ce0p-43,
	0x1.e3b333b16ee5cp-1, 0x1.c680p-47,
	0x1.e502ee78b3fb4p-1, -0x1.9300p-47,
	0x1.e653924676d68p-1, -0x1.5000p-49,
	0x1.e7a51fbc74c44p-1, -0x1.7f80p-47,
	0x1.e8f7977cdb726p-1, -0x1.3700p-48,
	0x1.ea4afa2a490e8p-1, 0x1.5d00p-49,
	0x1.eb9f4867ccae4p-1, 0x1.61a0p-46,
	0x1.ecf482d8e680dp-1, 0x1.5500p-48,
	0x1.ee4aaa2188514p-1, 0x1.6400p-51,
	0x1.efa1bee615a13p-1, -0x1.e800p-49,
	0x1.f0f9c1cb64106p-1, -0x1.a880p-48,
	0x1.f252b376bb963p-1, -0x1.c900p-45,
	0x1.f3ac948dd7275p-1, 0x1.a000p-53,
	0x1.f50765b6e4524p-1, -0x1.4f00p-48,
	0x1.f6632798844fdp-1, 0x1.a800p-51,
	0x1.f7bfdad9cbe38p-1, 0x1.abc0p-48,
	0x1.f91d802243c82p-1, -0x1.4600p-50,
	0x1.fa7c1819e908ep-1, -0x1.b0c0p-47,
	0x1.fbdba3692d511p-1, -0x1.0e00p-51,
	0x1.fd3c22b8f7194p-1, -0x1.0de8p-46,
	0x1.fe9d96b2a23eep-1, 0x1.e430p-49,
	0x1.0000000000000p+0, 0x0.0000p+0,
	0x1.00b1afa5abcbep+0, -0x1.3400p-52,
	0x1.0163da9fb3303p+0, -0x1.2170p-46,
	0x1.02168143b0282p+0, 0x1.a400p-52,
	0x1.02c9a3e77806cp+0, 0x1.f980p-49,
	0x1.037d42e11bbcap+0, -0x1.7400p-51,
	0x1.04315e86e7f89p+0, 0x1.8300p-50,
	0x1.04e5f72f65467p+0, -0x1.a3f0p-46,
	0x1.059b0d315855ap+0, -0x1.2840p-47,
	0x1.0650a0e3c1f95p+0, 0x1.1600p-48,
	0x1.0706b29ddf71ap+0, 0x1.5240p-46,
	0x1.07bd42b72a82dp+0, -0x1.9a00p-49,
	0x1.0874518759bd0p+0, 0x1.6400p-49,
	0x1.092bdf66607c8p+0, -0x1.0780p-47,
	0x1.09e3ecac6f383p+0, -0x1.8000p-54,
	0x1.0a9c79b1f3930p+0, 0x1.fa00p-48,
	0x1.0b5586cf988fcp+0, -0x1.ac80p-48,
	0x1.0c0f145e46c8ap+0, 0x1.9c00p-50,
	0x1.0cc922b724816p+0, 0x1.5200p-47,
	0x1.0d83b23395dd8p+0, -0x1.ad00p-48,
	0x1.0e3ec32d3d1f3p+0, 0x1.bac0p-46,
	0x1.0efa55fdfa9a6p+0, -0x1.4e80p-47,
	0x1.0fb66affed2f0p+0, -0x1.d300p-47,
	0x1.1073028d7234bp+0, 0x1.1500p-48,
	0x1.11301d0125b5bp+0, 0x1.c000p-49,
	0x1.11edbab5e2af9p+0, 0x1.6bc0p-46,
	0x1.12abdc06c31d5p+0, 0x1.8400p-49,
	0x1.136a814f2047dp+0, -0x1.ed00p-47,
	0x1.1429aaea92de9p+0, 0x1.8e00p-49,
	0x1.14e95934f3138p+0, 0x1.b400p-49,
	0x1.15a98c8a58e71p+0, 0x1.5300p-47,
	0x1.166a45471c3dfp+0, 0x1.3380p-47,
	0x1.172b83c7d5211p+0, 0x1.8d40p-45,
	0x1.17ed48695bb9fp+0, -0x1.5d00p-47,
	0x1.18af9388c8d93p+0, -0x1.c880p-46,
	0x1.1972658375d66p+0, 0x1.1f00p-46,
	0x1.1a35beb6fcba7p+0, 0x1.0480p-46,
	0x1.1af99f81387e3p+0, -0x1.7390p-43,
	0x1.1bbe084045d54p+0, 0x1.4e40p-45,
	0x1.1c82f95281c43p+0, -0x1.a200p-47,
	0x1.1d4873168b9b2p+0, 0x1.3800p-49,
	0x1.1e0e75eb44031p+0, 0x1.ac00p-49,
	0x1.1ed5022fcd938p+0, 0x1.1900p-47,
	0x1.1f9c18438cdf7p+0, -0x1.b780p-46,
	0x1.2063b88628d8fp+0, 0x1.d940p-45,
	0x1.212be3578a81ep+0, 0x1.8000p-50,
	0x1.21f49917ddd41p+0, 0x1.b340p-45,
	0x1.22bdda2791323p+0, 0x1.9f80p-46,
	0x1.2387a6e7561e7p+0, -0x1.9c80p-46,
	0x1.2451ffb821427p+0, 0x1.2300p-47,
	0x1.251ce4fb2a602p+0, -0x1.3480p-46,
	0x1.25e85711eceb0p+0, 0x1.2700p-46,
	0x1.26b4565e27d16p+0, 0x1.1d00p-46,
	0x1.2780e341de00fp+0, 0x1.1ee0p-44,
	0x1.284dfe1f5633ep+0, -0x1.4c00p-46,
	0x1.291ba7591bb30p+0, -0x1.3d80p-46,
	0x1.29e9df51fdf09p+0, 0x1.8b00p-47,
	0x1.2ab8a66d10e9bp+0, -0x1.27c0p-45,
	0x1.2b87fd0dada3ap+0, 0x1.a340p-45,
	0x1.2c57e39771af9p+0, -0x1.0800p-46,
	0x1.2d285a6e402d9p+0, -0x1.ed00p-47,
	0x1.2df961f641579p+0, -0x1.4200p-48,
	0x1.2ecafa93e2ecfp+0, -0x1.4980p-45,
	0x1.2f9d24abd8822p+0, -0x1.6300p-46,
	0x1.306fe0a31b625p+0, -0x1.2360p-44,
	0x1.31432edeea50bp+0, -0x1.0df8p-40,
	0x1.32170fc4cd7b8p+0, -0x1.2480p-45,
	0x1.32eb83ba8e9a2p+0, -0x1.5980p-45,
	0x1.33c08b2641766p+0, 0x1.ed00p-46,
	0x1.3496266e3fa27p+0, -0x1.c000p-50,
	0x1.356c55f929f0fp+0, -0x1.0d80p-44,
	0x1.36431a2de88b9p+0, 0x1.2c80p-45,
	0x1.371a7373aaa39p+0, 0x1.0600p-45,
	0x1.37f26231e74fep+0, -0x1.6600p-46,
	0x1.38cae6d05d838p+0, -0x1.ae00p-47,
	0x1.39a401b713ec3p+0, -0x1.4720p-43,
	0x1.3a7db34e5a020p+0, 0x1.8200p-47,
	0x1.3b57fbfec6e95p+0, 0x1.e800p-44,
	0x1.3c32dc313a8f2p+0, 0x1.f800p-49,
	0x1.3d0e544ede122p+0, -0x1.7a00p-46,
	0x1.3dea64c1234bbp+0, 0x1.6300p-45,
	0x1.3ec70df1c4eccp+0, -0x1.8a60p-43,
	0x1.3fa4504ac7e8cp+0, -0x1.cdc0p-44,
	0x1.40822c367a0bbp+0, 0x1.5b80p-45,
	0x1.4160a21f72e95p+0, 0x1.ec00p-46,
	0x1.423fb27094646p+0, -0x1.3600p-46,
	0x1.431f5d950a920p+0, 0x1.3980p-45,
	0x1.43ffa3f84b9ebp+0, 0x1.a000p-48,
	0x1.44e0860618919p+0, -0x1.6c00p-48,
	0x1.45c2042a7d201p+0, -0x1.bc00p-47,
	0x1.46a41ed1d0016p+0, -0x1.2800p-46,
	0x1.4786d668b3326p+0, 0x1.0e00p-44,
	0x1.486a2b5c13c00p+0, -0x1.d400p-45,
	0x1.494e1e192af04p+0, 0x1.c200p-47,
	0x1.4a32af0d7d372p+0, -0x1.e500p-46,
	0x1.4b17dea6db801p+0, 0x1.7800p-47,
	0x1.4bfdad53629e1p+0, -0x1.3800p-46,
	0x1.4ce41b817c132p+0, 0x1.0800p-47,
	0x1.4dcb299fddddbp+0, 0x1.c700p-45,
	0x1.4eb2d81d8ab96p+0, -0x1.ce00p-46,
	0x1.4f9b2769d2d02p+0, 0x1.9200p-46,
	0x1.508417f4531c1p+0, -0x1.8c00p-47,
	0x1.516daa2cf662ap+0, -0x1.a000p-48,
	0x1.5257de83f51eap+0, 0x1.a080p-43,
	0x1.5342b569d4edap+0, -0x1.6d80p-45,
	0x1.542e2f4f6ac1ap+0, -0x1.2440p-44,
	0x1.551a4ca5d94dbp+0, 0x1.83c0p-43,
	0x1.56070dde9116bp+0, 0x1.4b00p-45,
	0x1.56f4736b529dep+0, 0x1.15a0p-43,
	0x1.57e27dbe2c40ep+0, -0x1.9e00p-45,
	0x1.58d12d497c76fp+0, -0x1.3080p-45,
	0x1.59c0827ff0b4cp+0, 0x1.dec0p-43,
	0x1.5ab07dd485427p+0, -0x1.4000p-51,
	0x1.5ba11fba87af4p+0, 0x1.0080p-44,
	0x1.5c9268a59460bp+0, -0x1.6c80p-45,
	0x1.5d84590998e3fp+0, 0x1.69a0p-43,
	0x1.5e76f15ad20e1p+0, -0x1.b400p-46,
	0x1.5f6a320dcebcap+0, 0x1.7700p-46,
	0x1.605e1b976dcb8p+0, 0x1.6f80p-45,
	0x1.6152ae6cdf715p+0, 0x1.1000p-47,
	0x1.6247eb03a5531p+0, -0x1.5d00p-46,
	0x1.633dd1d1929b5p+0, -0x1.2d00p-46,
	0x1.6434634ccc313p+0, -0x1.a800p-49,
	0x1.652b9febc8efap+0, -0x1.8600p-45,
	0x1.6623882553397p+0, 0x1.1fe0p-40,
	0x1.671c1c708328ep+0, -0x1.7200p-44,
	0x1.68155d44ca97ep+0, 0x1.6800p-49,
	0x1.690f4b19e9471p+0, -0x1.9780p-45,
};

/************************************************************************
 * Public Functions
 ************************************************************************/

/*
 * exp2(x): compute the base 2 exponential of x
 *
 * Accuracy: Peak error < 0.503 ulp for normalized results.
 *
 * Method: (accurate tables)
 *
 *   Reduce x:
 *     x = k + y, for integer k and |y| <= 1/2.
 *     Thus we have exp2(x) = 2**k * exp2(y).
 *
 *   Reduce y:
 *     y = i/TBLSIZE + z - eps[i] for integer i near y * TBLSIZE.
 *     Thus we have exp2(y) = exp2(i/TBLSIZE) * exp2(z - eps[i]),
 *     with |z - eps[i]| <= 2**-9 + 2**-39 for the table used.
 *
 *   We compute exp2(i/TBLSIZE) via table lookup and exp2(z - eps[i]) via
 *   a degree-5 minimax polynomial with maximum error under 1.3 * 2**-61.
 *   The values in exp2t[] and eps[] are chosen such that
 *   exp2t[i] = exp2(i/TBLSIZE + eps[i]), and eps[i] is a small offset such
 *   that exp2t[i] is accurate to 2**-64.
 *
 *   Note that the range of i is +-TBLSIZE/2, so we actually index the tables
 *   by i0 = i + TBLSIZE/2.  For cache efficiency, exp2t[] and eps[] are
 *   virtual tables, interleaved in the real table tbl[].
 *
 *   This method is due to Gal, with many details due to Gal and Bachelis:
 *
 *      Gal, S. and Bachelis, B.  An Accurate Elementary Mathematical Library
 *      for the IEEE Floating Point Standard.  TOMS 17(1), 26-46 (1991).
 */
double exp2(double x)
{
	double r;
	double t;
	double z;
	uint32_t ix;
	uint32_t i0;
	union {
		double f;
		uint64_t i;
	} u = { x };
	union {
		uint32_t u;
		int32_t i;
	} k;

	/* Filter out exceptional cases. */
	ix = u.i >> 32 & 0x7fffffff;
	if (ix >= 0x408ff000) {		/* |x| >= 1022 or nan */
		if (ix >= 0x40900000 && u.i >> 63 == 0) {	/* x >= 1024 or nan */
			/* overflow */
			x *= 0x1p1023;
			return x;
		}
		if (ix >= 0x7ff00000) {	/* -inf or -nan */
			return -1 / x;
		}
		if (u.i >> 63) {		/* x <= -1022 */
			/* underflow */
			if (x <= -1075 || x-0x1p52 + 0x1p52 != x) {
				FORCE_EVAL((float)(-0x1p-149 / x));
			}
			if (x <= -1075) {
				return 0;
			}
		}
	} else if (ix < 0x3c900000) {	/* |x| < 0x1p-54 */
		return 1.0 + x;
	}

	/* Reduce x, computing z, i0, and k. */
	u.f = x + redux;
	i0 = u.i;
	i0 += TBLSIZE / 2;
	k.u = i0 / TBLSIZE * TBLSIZE;
	k.i /= TBLSIZE;
	i0 %= TBLSIZE;
	u.f -= redux;
	z = x - u.f;

	/* Compute r = exp2(y) = exp2t[i0] * p(z - eps[i]). */
	t = tbl[2 * i0];			/* exp2t[i0] */
	z -= tbl[2 * i0 + 1];		/* eps[i0]   */
	r = t + t * z * (P1 + z * (P2 + z * (P3 + z * (P4 + z * P5))));

	return scalbn(r, k.i);
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
 * origin: FreeBSD /usr/src/lib/msun/src/s_exp2.c
 *
 * Copyright (c) 2005 David Schultz <das@FreeBSD.ORG>
 * All rights reserved.
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
 ***************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include "libm.h"

#define TBLSIZE 16

/************************************************************************
 * Private Data
 ************************************************************************/

static const float redux = 0x1.8p23f / TBLSIZE;
static const float P1 = 0x1.62e430p-1f;
static const float P2 = 0x1.ebfbe0p-3f;
static const float P3 = 0x1.c6b348p-5f;
static const float P4 = 0x1.3b2c9cp-7f;

static const double exp2ft[TBLSIZE] = {
	0x1.6a09e667f3bcdp-1,
	0x1.7a11473eb0187p-1,
	0x1.8ace5422aa0dbp-1,
	0x1.9c49182a3f090p-1,
	0x1.ae89f995ad3adp-1,
	0x1.c199bdd85529cp-1,
	0x1.d5818dcfba487p-1,
	0x1.ea4afa2a490dap-1,
	0x1.0000000000000p+0,
	0x1.0b5586cf9890fp+0,
	0x1.172b83c7d517bp+0,
	0x1.2387a6e756238p+0,
	0x1.306fe0a31b715p+0,
	0x1.3dea64c123422p+0,
	0x1.4bfdad5362a27p+0,
	0x1.5ab07dd485429p+0,
};

/************************************************************************
 * Public Functions
 ************************************************************************/

/*
 * exp2f(x): compute the base 2 exponential of x
 *
 * Accuracy: Peak error < 0.501 ulp; location of peak: -0.030110927.
 *
 * Method: (equally-spaced tables)
 *
 *   Reduce x:
 *     x = k + y, for integer k and |y| <= 1/2.
 *     Thus we have exp2f(x) = 2**k * exp2(y).
 *
 *   Reduce y:
 *     y = i/TBLSIZE + z for integer i near y * TBLSIZE.
 *     Thus we have exp2(y) = exp2(i/TBLSIZE) * exp2(z),
 *     with |z| <= 2**-(TBLSIZE+1).
 *
 *   We compute exp2(i/TBLSIZE) via table lookup and exp2(z) via a
 *   degree-4 minimax polynomial with maximum error under 1.4 * 2**-33.
 *   Using double precision for everything except the reduction makes
 *   roundoff error insignificant and simplifies the scaling step.
 *
 *   This method is due to Tang, but I do not use his suggested parameters:
 *
 *      Tang, P.  Table-driven Implementation of the Exponential Function
 *      in IEEE Floating-Point Arithmetic.  TOMS 15(2), 144-157 (1989).
 */
float exp2f(float x)
{
	double t;
	double r;
	double z;
	union {
		float f;
		uint32_t i;
	} u = { x };
	union {
		double f;
		uint64_t i;
	} uk;
	uint32_t ix;
	uint32_t i0;
	uint32_t k;

	/* Filter out exceptional cases. */
	ix = u.i & 0x7fffffff;
	if (ix > 0x42fc0000) {		/* |x| > 126 */
		if (ix > 0x7f800000) {	/* NaN */
			return x;
		}
		if (u.i >= 0x43000000 && u.i < 0x80000000) {	/* x >= 128 */
			x *= 0x1p127f;
			return x;
		}
		if (u.i >= 0x80000000) {	/* x < -126 */
			if (u.i >= 0xc3160000 || (u.i & 0x0000ffff)) {
				FORCE_EVAL(-0x1p-149f / x);
			}
			if (u.i >= 0xc3160000) {	/* x <= -150 */
				return 0;
			}
		}
	} else if (ix <= 0x33000000) {	/* |x| <= 0x1p-25 */
		return 1.0f + x;
	}

	/* Reduce x, computing z, i0, and k. */
	u.f = x + redux;
	i0 = u.i;
	i0 += TBLSIZE / 2;
	k = i0 / TBLSIZE;
	uk.i = (uint64_t)(0x3ff + k) << 52;
	i0 &= TBLSIZE - 1;
	u.f -= redux;
	z = x - u.f;
	/* Compute r = exp2(y) = exp2ft[i0] * p(z). */
	r = exp2ft[i0];
	t = r * z;
	r = r + t * (P1 + z * P2) + t * (z * z) * (P3 + z * P4);

	/* Scale by 2**k */
	return r * uk.f;
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
 * origin: FreeBSD /usr/src/lib/msun/src/s_exp2.c
 *
 * Copyright (c) 2005 David Schultz <das@FreeBSD.ORG>
 * All rights reserved.
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
 ***************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double exp2l(long double x)
{
	return exp2(x);
}
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
#define TBLBITS 7
#define TBLSIZE (1 << TBLBITS)

/************************************************************************
 * Private Data
 ************************************************************************/

static const double redux = 0x1.8p63 / TBLSIZE;
static const double P1 = 0x1.62e42fefa39efp-1;
static const double P2 = 0x1.ebfbdff82c58fp-3;
static const double P3 = 0x1.c6b08d7049fap-5;
static const double P4 = 0x1.3b2ab6fba4da5p-7;
static const double P5 = 0x1.5d8804780a736p-10;
static const double P6 = 0x1.430918835e33dp-13;

static const double tbl[TBLSIZE * 2] = {
	0x1.6a09e667f3bcdp-1, -0x1.bdd3413b2648p-55,
	0x1.6c012750bdabfp-1, -0x1.2895667ff0cp-57,
	0x1.6dfb23c651a2fp-1, -0x1.bbe3a683c88p-58,
	0x1.6ff7df9519484p-1, -0x1.83c0f25860fp-56,
	0x1.71f75e8ec5f74p-1, -0x1.16e4786887bp-56,
	0x1.73f9a48a58174p-1, -0x1.0a8d96c65d5p-55,
	0x1.75feb564267c9p-1, -0x1.0245957316ep-55,
	0x1.780694fde5d3fp-1, 0x1.866b80a0216p-55,
	0x1.7a11473eb0187p-1, -0x1.41577ee0499p-56,
	0x1.7c1ed0130c132p-1, 0x1.f124cd1164ep-55,
	0x1.7e2f336cf4e62p-1, 0x1.05d02ba157ap-57,
	0x1.80427543e1a12p-1, -0x1.27c86626d97p-55,
	0x1.82589994cce13p-1, -0x1.d4c1dd41533p-55,
	0x1.8471a4623c7adp-1, -0x1.8d684a341cep-56,
	0x1.868d99b4492edp-1, -0x1.fc6f89bd4f68p-55,
	0x1.88ac7d98a6699p-1, 0x1.994c2f37cb5p-55,
	0x1.8ace5422aa0dbp-1, 0x1.6e9f156864bp-55,
	0x1.8cf3216b5448cp-1, -0x1.0d55e32e9e4p-57,
	0x1.8f1ae99157736p-1, 0x1.5cc13a2e397p-56,
	0x1.9145b0b91ffc6p-1, -0x1.dd6792e5825p-55,
	0x1.93737b0cdc5e5p-1, -0x1.75fc781b58p-58,
	0x1.95a44cbc8520fp-1, -0x1.64b7c96a5fp-57,
	0x1.97d829fde4e5p-1, -0x1.d185b7c1b86p-55,
	0x1.9a0f170ca07bap-1, -0x1.173bd91cee6p-55,
	0x1.9c49182a3f09p-1, 0x1.c7c46b071f2p-57,
	0x1.9e86319e32323p-1, 0x1.824ca78e64cp-57,
	0x1.a0c667b5de565p-1, -0x1.359495d1cd5p-55,
	0x1.a309bec4a2d33p-1, 0x1.6305c7ddc368p-55,
	0x1.a5503b23e255dp-1, -0x1.d2f6edb8d42p-55,
	0x1.a799e1330b358p-1, 0x1.bcb7ecac564p-55,
	0x1.a9e6b5579fdbfp-1, 0x1.0fac90ef7fdp-55,
	0x1.ac36bbfd3f37ap-1, -0x1.f9234cae76dp-56,
	0x1.ae89f995ad3adp-1, 0x1.7a1cd345dcc8p-55,
	0x1.b0e07298db666p-1, -0x1.bdef54c80e4p-55,
	0x1.b33a2b84f15fbp-1, -0x1.2805e3084d8p-58,
	0x1.b59728de5593ap-1, -0x1.c71dfbbba6ep-55,
	0x1.b7f76f2fb5e47p-1, -0x1.5584f7e54acp-57,
	0x1.ba5b030a1064ap-1, -0x1.efcd30e5429p-55,
	0x1.bcc1e904bc1d2p-1, 0x1.23dd07a2d9fp-56,
	0x1.bf2c25bd71e09p-1, -0x1.efdca3f6b9c8p-55,
	0x1.c199bdd85529cp-1, 0x1.11065895049p-56,
	0x1.c40ab5fffd07ap-1, 0x1.b4537e083c6p-55,
	0x1.c67f12e57d14bp-1, 0x1.2884dff483c8p-55,
	0x1.c8f6d9406e7b5p-1, 0x1.1acbc48805cp-57,
	0x1.cb720dcef9069p-1, 0x1.503cbd1e94ap-57,
	0x1.cdf0b555dc3fap-1, -0x1.dd83b53829dp-56,
	0x1.d072d4a07897cp-1, -0x1.cbc3743797a8p-55,
	0x1.d2f87080d89f2p-1, -0x1.d487b719d858p-55,
	0x1.d5818dcfba487p-1, 0x1.2ed02d75b37p-56,
	0x1.d80e316c98398p-1, -0x1.11ec18bedep-55,
	0x1.da9e603db3285p-1, 0x1.c2300696db5p-55,
	0x1.dd321f301b46p-1, 0x1.2da5778f019p-55,
	0x1.dfc97337b9b5fp-1, -0x1.1a5cd4f184b8p-55,
	0x1.e264614f5a129p-1, -0x1.7b627817a148p-55,
	0x1.e502ee78b3ff6p-1, 0x1.39e8980a9cdp-56,
	0x1.e7a51fbc74c83p-1, 0x1.2d522ca0c8ep-55,
	0x1.ea4afa2a490dap-1, -0x1.e9c23179c288p-55,
	0x1.ecf482d8e67f1p-1, -0x1.c93f3b411ad8p-55,
	0x1.efa1bee615a27p-1, 0x1.dc7f486a4b68p-55,
	0x1.f252b376bba97p-1, 0x1.3a1a5bf0d8e8p-55,
	0x1.f50765b6e454p-1, 0x1.9d3e12dd8a18p-55,
	0x1.f7bfdad9cbe14p-1, -0x1.dbb12d00635p-55,
	0x1.fa7c1819e90d8p-1, 0x1.74853f3a593p-56,
	0x1.fd3c22b8f71f1p-1, 0x1.2eb74966578p-58,
	0x1p+0,    0x0p+0,
	0x1.0163da9fb3335p+0, 0x1.b61299ab8cd8p-54,
	0x1.02c9a3e778061p+0, -0x1.19083535b08p-56,
	0x1.04315e86e7f85p+0, -0x1.0a31c1977c98p-54,
	0x1.059b0d3158574p+0, 0x1.d73e2a475b4p-55,
	0x1.0706b29ddf6dep+0, -0x1.c91dfe2b13cp-55,
	0x1.0874518759bc8p+0, 0x1.186be4bb284p-57,
	0x1.09e3ecac6f383p+0, 0x1.14878183161p-54,
	0x1.0b5586cf9890fp+0, 0x1.8a62e4adc61p-54,
	0x1.0cc922b7247f7p+0, 0x1.01edc16e24f8p-54,
	0x1.0e3ec32d3d1a2p+0, 0x1.03a1727c58p-59,
	0x1.0fb66affed31bp+0, -0x1.b9bedc44ebcp-57,
	0x1.11301d0125b51p+0, -0x1.6c51039449bp-54,
	0x1.12abdc06c31ccp+0, -0x1.1b514b36ca8p-58,
	0x1.1429aaea92dep+0, -0x1.32fbf9af1368p-54,
	0x1.15a98c8a58e51p+0, 0x1.2406ab9eeabp-55,
	0x1.172b83c7d517bp+0, -0x1.19041b9d78ap-55,
	0x1.18af9388c8deap+0, -0x1.11023d1970f8p-54,
	0x1.1a35beb6fcb75p+0, 0x1.e5b4c7b4969p-55,
	0x1.1bbe084045cd4p+0, -0x1.95386352ef6p-54,
	0x1.1d4873168b9aap+0, 0x1.e016e00a264p-54,
	0x1.1ed5022fcd91dp+0, -0x1.1df98027bb78p-54,
	0x1.2063b88628cd6p+0, 0x1.dc775814a85p-55,
	0x1.21f49917ddc96p+0, 0x1.2a97e9494a6p-55,
	0x1.2387a6e756238p+0, 0x1.9b07eb6c7058p-54,
	0x1.251ce4fb2a63fp+0, 0x1.ac155bef4f5p-55,
	0x1.26b4565e27cddp+0, 0x1.2bd339940eap-55,
	0x1.284dfe1f56381p+0, -0x1.a4c3a8c3f0d8p-54,
	0x1.29e9df51fdee1p+0, 0x1.612e8afad12p-55,
	0x1.2b87fd0dad99p+0, -0x1.10adcd6382p-59,
	0x1.2d285a6e4030bp+0, 0x1.0024754db42p-54,
	0x1.2ecafa93e2f56p+0, 0x1.1ca0f45d524p-56,
	0x1.306fe0a31b715p+0, 0x1.6f46ad23183p-55,
	0x1.32170fc4cd831p+0, 0x1.a9ce78e1804p-55,
	0x1.33c08b26416ffp+0, 0x1.327218436598p-54,
	0x1.356c55f929ff1p+0, -0x1.b5cee5c4e46p-55,
	0x1.371a7373aa9cbp+0, -0x1.63aeabf42ebp-54,
	0x1.38cae6d05d866p+0, -0x1.e958d3c99048p-54,
	0x1.3a7db34e59ff7p+0, -0x1.5e436d661f6p-56,
	0x1.3c32dc313a8e5p+0, -0x1.efff8375d2ap-54,
	0x1.3dea64c123422p+0, 0x1.ada0911f09fp-55,
	0x1.3fa4504ac801cp+0, -0x1.7d023f956fap-54,
	0x1.4160a21f72e2ap+0, -0x1.ef3691c309p-58,
	0x1.431f5d950a897p+0, -0x1.1c7dde35f7ap-55,
	0x1.44e086061892dp+0, 0x1.89b7a04ef8p-59,
	0x1.46a41ed1d0057p+0, 0x1.c944bd1648a8p-54,
	0x1.486a2b5c13cdp+0, 0x1.3c1a3b69062p-56,
	0x1.4a32af0d7d3dep+0, 0x1.9cb62f3d1be8p-54,
	0x1.4bfdad5362a27p+0, 0x1.d4397afec42p-56,
	0x1.4dcb299fddd0dp+0, 0x1.8ecdbbc6a78p-54,
	0x1.4f9b2769d2ca7p+0, -0x1.4b309d25958p-54,
	0x1.516daa2cf6642p+0, -0x1.f768569bd94p-55,
	0x1.5342b569d4f82p+0, -0x1.07abe1db13dp-55,
	0x1.551a4ca5d920fp+0, -0x1.d689cefede6p-55,
	0x1.56f4736b527dap+0, 0x1.9bb2c011d938p-54,
	0x1.58d12d497c7fdp+0, 0x1.295e15b9a1ep-55,
	0x1.5ab07dd485429p+0, 0x1.6324c0546478p-54,
	0x1.5c9268a5946b7p+0, 0x1.c4b1b81698p-60,
	0x1.5e76f15ad2148p+0, 0x1.ba6f93080e68p-54,
	0x1.605e1b976dc09p+0, -0x1.3e2429b56de8p-54,
	0x1.6247eb03a5585p+0, -0x1.383c17e40b48p-54,
	0x1.6434634ccc32p+0, -0x1.c483c759d89p-55,
	0x1.6623882552225p+0, -0x1.bb60987591cp-54,
	0x1.68155d44ca973p+0, 0x1.038ae44f74p-57,
};

/************************************************************************
 * Public Functions
 ************************************************************************/

/*
 * exp2l(x): compute the base 2 exponential of x
 *
 * Accuracy: Peak error < 0.511 ulp.
 *
 * Method: (equally-spaced tables)
 *
 *   Reduce x:
 *     x = 2**k + y, for integer k and |y| <= 1/2.
 *     Thus we have exp2l(x) = 2**k * exp2(y).
 *
 *   Reduce y:
 *     y = i/TBLSIZE + z for integer i near y * TBLSIZE.
 *     Thus we have exp2(y) = exp2(i/TBLSIZE) * exp2(z),
 *     with |z| <= 2**-(TBLBITS+1).
 *
 *   We compute exp2(i/TBLSIZE) via table lookup and exp2(z) via a
 *   degree-6 minimax polynomial with maximum error under 2**-69.
 *   The table entries each have 104 bits of accuracy, encoded as
 *   a pair of double precision values.
 */
long double exp2l(long double x)
{
	union ldshape u = { x };
	int e = u.i.se & 0x7fff;
	long double r;
	long double z;
	uint32_t i0;
	union {
		uint32_t u;
		int32_t i;
	} k;

	/* Filter out exceptional cases. */
	if (e >= 0x3fff + 13) {		/* |x| >= 8192 or x is NaN */
		if (u.i.se >= 0x3fff + 14 && u.i.se >> 15 == 0)
			/* overflow */
		{
			return x * 0x1p16383L;
		}
		if (e == 0x7fff) {	/* -inf or -nan */
			return -1 / x;
		}
		if (x < -16382) {
			if (x <= -16446 || x - 0x1p63 + 0x1p63 != x)
				/* underflow */
			{
				FORCE_EVAL((float)(-0x1p-149 / x));
			}
			if (x <= -16446) {
				return 0;
			}
		}
	} else if (e < 0x3fff - 64) {
		return 1 + x;
	}

	/*
	 * Reduce x, computing z, i0, and k. The low bits of x + redux
	 * contain the 16-bit integer part of the exponent (k) followed by
	 * TBLBITS fractional bits (i0). We use bit tricks to extract these
	 * as integers, then set z to the remainder.
	 *
	 * Example: Suppose x is 0xabc.123456p0 and TBLBITS is 8.
	 * Then the low-order word of x + redux is 0x000abc12,
	 * We split this into k = 0xabc and i0 = 0x12 (adjusted to
	 * index into the table), then we compute z = 0x0.003456p0.
	 */
	u.f = x + redux;
	i0 = u.i.m + TBLSIZE / 2;
	k.u = i0 / TBLSIZE * TBLSIZE;
	k.i /= TBLSIZE;
	i0 %= TBLSIZE;
	u.f -= redux;
	z = x - u.f;

	/* Compute r = exp2l(y) = exp2lt[i0] * p(z). */
	long double t_hi = tbl[2 * i0];
	long double t_lo = tbl[2 * i0 + 1];
	/* XXX This gives > 1 ulp errors outside of FE_TONEAREST mode */
	r = t_lo + (t_hi + t_lo) * z * (P1 + z * (P2 + z * (P3 + z * (P4 + z * (P5 + z * P6))))) + t_hi;

	return scalbnl(r, k.i);
}
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
#define TBLBITS 7
#define TBLSIZE (1 << TBLBITS)

/************************************************************************
 * Private Data
 ************************************************************************/

static const long double P1 = 0x1.62e42fefa39ef35793c7673007e6p-1L;
static const long double P2 = 0x1.ebfbdff82c58ea86f16b06ec9736p-3L;
static const long double P3 = 0x1.c6b08d704a0bf8b33a762bad3459p-5L;
static const long double P4 = 0x1.3b2ab6fba4e7729ccbbe0b4f3fc2p-7L;
static const long double P5 = 0x1.5d87fe78a67311071dee13fd11d9p-10L;
static const long double P6 = 0x1.430912f86c7876f4b663b23c5fe5p-13L;

static const double P7 = 0x1.ffcbfc588b041p-17;
static const double P8 = 0x1.62c0223a5c7c7p-20;
static const double P9 = 0x1.b52541ff59713p-24;
static const double P10 = 0x1.e4cf56a391e22p-28;
static const double redux = 0x1.8p112 / TBLSIZE;

static const long double tbl[TBLSIZE] = {
	0x1.6a09e667f3bcc908b2fb1366dfeap-1L,
	0x1.6c012750bdabeed76a99800f4edep-1L,
	0x1.6dfb23c651a2ef220e2cbe1bc0d4p-1L,
	0x1.6ff7df9519483cf87e1b4f3e1e98p-1L,
	0x1.71f75e8ec5f73dd2370f2ef0b148p-1L,
	0x1.73f9a48a58173bd5c9a4e68ab074p-1L,
	0x1.75feb564267c8bf6e9aa33a489a8p-1L,
	0x1.780694fde5d3f619ae02808592a4p-1L,
	0x1.7a11473eb0186d7d51023f6ccb1ap-1L,
	0x1.7c1ed0130c1327c49334459378dep-1L,
	0x1.7e2f336cf4e62105d02ba1579756p-1L,
	0x1.80427543e1a11b60de67649a3842p-1L,
	0x1.82589994cce128acf88afab34928p-1L,
	0x1.8471a4623c7acce52f6b97c6444cp-1L,
	0x1.868d99b4492ec80e41d90ac2556ap-1L,
	0x1.88ac7d98a669966530bcdf2d4cc0p-1L,
	0x1.8ace5422aa0db5ba7c55a192c648p-1L,
	0x1.8cf3216b5448bef2aa1cd161c57ap-1L,
	0x1.8f1ae991577362b982745c72eddap-1L,
	0x1.9145b0b91ffc588a61b469f6b6a0p-1L,
	0x1.93737b0cdc5e4f4501c3f2540ae8p-1L,
	0x1.95a44cbc8520ee9b483695a0e7fep-1L,
	0x1.97d829fde4e4f8b9e920f91e8eb6p-1L,
	0x1.9a0f170ca07b9ba3109b8c467844p-1L,
	0x1.9c49182a3f0901c7c46b071f28dep-1L,
	0x1.9e86319e323231824ca78e64c462p-1L,
	0x1.a0c667b5de564b29ada8b8cabbacp-1L,
	0x1.a309bec4a2d3358c171f770db1f4p-1L,
	0x1.a5503b23e255c8b424491caf88ccp-1L,
	0x1.a799e1330b3586f2dfb2b158f31ep-1L,
	0x1.a9e6b5579fdbf43eb243bdff53a2p-1L,
	0x1.ac36bbfd3f379c0db966a3126988p-1L,
	0x1.ae89f995ad3ad5e8734d17731c80p-1L,
	0x1.b0e07298db66590842acdfc6fb4ep-1L,
	0x1.b33a2b84f15faf6bfd0e7bd941b0p-1L,
	0x1.b59728de559398e3881111648738p-1L,
	0x1.b7f76f2fb5e46eaa7b081ab53ff6p-1L,
	0x1.ba5b030a10649840cb3c6af5b74cp-1L,
	0x1.bcc1e904bc1d2247ba0f45b3d06cp-1L,
	0x1.bf2c25bd71e088408d7025190cd0p-1L,
	0x1.c199bdd85529c2220cb12a0916bap-1L,
	0x1.c40ab5fffd07a6d14df820f17deap-1L,
	0x1.c67f12e57d14b4a2137fd20f2a26p-1L,
	0x1.c8f6d9406e7b511acbc48805c3f6p-1L,
	0x1.cb720dcef90691503cbd1e949d0ap-1L,
	0x1.cdf0b555dc3f9c44f8958fac4f12p-1L,
	0x1.d072d4a07897b8d0f22f21a13792p-1L,
	0x1.d2f87080d89f18ade123989ea50ep-1L,
	0x1.d5818dcfba48725da05aeb66dff8p-1L,
	0x1.d80e316c98397bb84f9d048807a0p-1L,
	0x1.da9e603db3285708c01a5b6d480cp-1L,
	0x1.dd321f301b4604b695de3c0630c0p-1L,
	0x1.dfc97337b9b5eb968cac39ed284cp-1L,
	0x1.e264614f5a128a12761fa17adc74p-1L,
	0x1.e502ee78b3ff6273d130153992d0p-1L,
	0x1.e7a51fbc74c834b548b2832378a4p-1L,
	0x1.ea4afa2a490d9858f73a18f5dab4p-1L,
	0x1.ecf482d8e67f08db0312fb949d50p-1L,
	0x1.efa1bee615a27771fd21a92dabb6p-1L,
	0x1.f252b376bba974e8696fc3638f24p-1L,
	0x1.f50765b6e4540674f84b762861a6p-1L,
	0x1.f7bfdad9cbe138913b4bfe72bd78p-1L,
	0x1.fa7c1819e90d82e90a7e74b26360p-1L,
	0x1.fd3c22b8f71f10975ba4b32bd006p-1L,
	0x1.0000000000000000000000000000p+0L,
	0x1.0163da9fb33356d84a66ae336e98p+0L,
	0x1.02c9a3e778060ee6f7caca4f7a18p+0L,
	0x1.04315e86e7f84bd738f9a20da442p+0L,
	0x1.059b0d31585743ae7c548eb68c6ap+0L,
	0x1.0706b29ddf6ddc6dc403a9d87b1ep+0L,
	0x1.0874518759bc808c35f25d942856p+0L,
	0x1.09e3ecac6f3834521e060c584d5cp+0L,
	0x1.0b5586cf9890f6298b92b7184200p+0L,
	0x1.0cc922b7247f7407b705b893dbdep+0L,
	0x1.0e3ec32d3d1a2020742e4f8af794p+0L,
	0x1.0fb66affed31af232091dd8a169ep+0L,
	0x1.11301d0125b50a4ebbf1aed9321cp+0L,
	0x1.12abdc06c31cbfb92bad324d6f84p+0L,
	0x1.1429aaea92ddfb34101943b2588ep+0L,
	0x1.15a98c8a58e512480d573dd562aep+0L,
	0x1.172b83c7d517adcdf7c8c50eb162p+0L,
	0x1.18af9388c8de9bbbf70b9a3c269cp+0L,
	0x1.1a35beb6fcb753cb698f692d2038p+0L,
	0x1.1bbe084045cd39ab1e72b442810ep+0L,
	0x1.1d4873168b9aa7805b8028990be8p+0L,
	0x1.1ed5022fcd91cb8819ff61121fbep+0L,
	0x1.2063b88628cd63b8eeb0295093f6p+0L,
	0x1.21f49917ddc962552fd29294bc20p+0L,
	0x1.2387a6e75623866c1fadb1c159c0p+0L,
	0x1.251ce4fb2a63f3582ab7de9e9562p+0L,
	0x1.26b4565e27cdd257a673281d3068p+0L,
	0x1.284dfe1f5638096cf15cf03c9fa0p+0L,
	0x1.29e9df51fdee12c25d15f5a25022p+0L,
	0x1.2b87fd0dad98ffddea46538fca24p+0L,
	0x1.2d285a6e4030b40091d536d0733ep+0L,
	0x1.2ecafa93e2f5611ca0f45d5239a4p+0L,
	0x1.306fe0a31b7152de8d5a463063bep+0L,
	0x1.32170fc4cd8313539cf1c3009330p+0L,
	0x1.33c08b26416ff4c9c8610d96680ep+0L,
	0x1.356c55f929ff0c94623476373be4p+0L,
	0x1.371a7373aa9caa7145502f45452ap+0L,
	0x1.38cae6d05d86585a9cb0d9bed530p+0L,
	0x1.3a7db34e59ff6ea1bc9299e0a1fep+0L,
	0x1.3c32dc313a8e484001f228b58cf0p+0L,
	0x1.3dea64c12342235b41223e13d7eep+0L,
	0x1.3fa4504ac801ba0bf701aa417b9cp+0L,
	0x1.4160a21f72e29f84325b8f3dbacap+0L,
	0x1.431f5d950a896dc704439410b628p+0L,
	0x1.44e086061892d03136f409df0724p+0L,
	0x1.46a41ed1d005772512f459229f0ap+0L,
	0x1.486a2b5c13cd013c1a3b69062f26p+0L,
	0x1.4a32af0d7d3de672d8bcf46f99b4p+0L,
	0x1.4bfdad5362a271d4397afec42e36p+0L,
	0x1.4dcb299fddd0d63b36ef1a9e19dep+0L,
	0x1.4f9b2769d2ca6ad33d8b69aa0b8cp+0L,
	0x1.516daa2cf6641c112f52c84d6066p+0L,
	0x1.5342b569d4f81df0a83c49d86bf4p+0L,
	0x1.551a4ca5d920ec52ec620243540cp+0L,
	0x1.56f4736b527da66ecb004764e61ep+0L,
	0x1.58d12d497c7fd252bc2b7343d554p+0L,
	0x1.5ab07dd48542958c93015191e9a8p+0L,
	0x1.5c9268a5946b701c4b1b81697ed4p+0L,
	0x1.5e76f15ad21486e9be4c20399d12p+0L,
	0x1.605e1b976dc08b076f592a487066p+0L,
	0x1.6247eb03a5584b1f0fa06fd2d9eap+0L,
	0x1.6434634ccc31fc76f8714c4ee122p+0L,
	0x1.66238825522249127d9e29b92ea2p+0L,
	0x1.68155d44ca973081c57227b9f69ep+0L,
};

static const float eps[TBLSIZE] = {
	-0x1.5c50p-101,
	-0x1.5d00p-106,
	 0x1.8e90p-102,
	-0x1.5340p-103,
	 0x1.1bd0p-102,
	-0x1.4600p-105,
	-0x1.7a40p-104,
	 0x1.d590p-102,
	-0x1.d590p-101,
	 0x1.b100p-103,
	-0x1.0d80p-105,
	 0x1.6b00p-103,
	-0x1.9f00p-105,
	 0x1.c400p-103,
	 0x1.e120p-103,
	-0x1.c100p-104,
	-0x1.9d20p-103,
	 0x1.a800p-108,
	 0x1.4c00p-106,
	-0x1.9500p-106,
	 0x1.6900p-105,
	-0x1.29d0p-100,
	 0x1.4c60p-103,
	 0x1.13a0p-102,
	-0x1.5b60p-103,
	-0x1.1c40p-103,
	 0x1.db80p-102,
	 0x1.91a0p-102,
	 0x1.dc00p-105,
	 0x1.44c0p-104,
	 0x1.9710p-102,
	 0x1.8760p-103,
	-0x1.a720p-103,
	 0x1.ed20p-103,
	-0x1.49c0p-102,
	-0x1.e000p-111,
	 0x1.86a0p-103,
	 0x1.2b40p-103,
	-0x1.b400p-108,
	 0x1.1280p-99,
	-0x1.02d8p-102,
	-0x1.e3d0p-103,
	-0x1.b080p-105,
	-0x1.f100p-107,
	-0x1.16c0p-105,
	-0x1.1190p-103,
	-0x1.a7d2p-100,
	 0x1.3450p-103,
	-0x1.67c0p-105,
	 0x1.4b80p-104,
	-0x1.c4e0p-103,
	 0x1.6000p-108,
	-0x1.3f60p-105,
	 0x1.93f0p-104,
	 0x1.5fe0p-105,
	 0x1.6f80p-107,
	-0x1.7600p-106,
	 0x1.21e0p-106,
	-0x1.3a40p-106,
	-0x1.40c0p-104,
	-0x1.9860p-105,
	-0x1.5d40p-108,
	-0x1.1d70p-106,
	 0x1.2760p-105,
	 0x0.0000p+0,
	 0x1.21e2p-104,
	-0x1.9520p-108,
	-0x1.5720p-106,
	-0x1.4810p-106,
	-0x1.be00p-109,
	 0x1.0080p-105,
	-0x1.5780p-108,
	-0x1.d460p-105,
	-0x1.6140p-105,
	 0x1.4630p-104,
	 0x1.ad50p-103,
	 0x1.82e0p-105,
	 0x1.1d3cp-101,
	 0x1.6100p-107,
	 0x1.ec30p-104,
	 0x1.f200p-108,
	 0x1.0b40p-103,
	 0x1.3660p-102,
	 0x1.d9d0p-103,
	-0x1.02d0p-102,
	 0x1.b070p-103,
	 0x1.b9c0p-104,
	-0x1.01c0p-103,
	-0x1.dfe0p-103,
	 0x1.1b60p-104,
	-0x1.ae94p-101,
	-0x1.3340p-104,
	 0x1.b3d8p-102,
	-0x1.6e40p-105,
	-0x1.3670p-103,
	 0x1.c140p-104,
	 0x1.1840p-101,
	 0x1.1ab0p-102,
	-0x1.a400p-104,
	 0x1.1f00p-104,
	-0x1.7180p-103,
	 0x1.4ce0p-102,
	 0x1.9200p-107,
	-0x1.54c0p-103,
	 0x1.1b80p-105,
	-0x1.1828p-101,
	 0x1.5720p-102,
	-0x1.a060p-100,
	 0x1.9160p-102,
	 0x1.a280p-104,
	 0x1.3400p-107,
	 0x1.2b20p-102,
	 0x1.7800p-108,
	 0x1.cfd0p-101,
	 0x1.2ef0p-102,
	-0x1.2760p-99,
	 0x1.b380p-104,
	 0x1.0048p-101,
	-0x1.60b0p-102,
	 0x1.a1ccp-100,
	-0x1.a640p-104,
	-0x1.08a0p-101,
	 0x1.7e60p-102,
	 0x1.22c0p-103,
	-0x1.7200p-106,
	 0x1.f0f0p-102,
	 0x1.eb4ep-99,
	 0x1.c6e0p-103,
};

/************************************************************************
 * Public Functions
 ************************************************************************/

/*
 * exp2l(x): compute the base 2 exponential of x
 *
 * Accuracy: Peak error < 0.502 ulp.
 *
 * Method: (accurate tables)
 *
 *   Reduce x:
 *     x = 2**k + y, for integer k and |y| <= 1/2.
 *     Thus we have exp2(x) = 2**k * exp2(y).
 *
 *   Reduce y:
 *     y = i/TBLSIZE + z - eps[i] for integer i near y * TBLSIZE.
 *     Thus we have exp2(y) = exp2(i/TBLSIZE) * exp2(z - eps[i]),
 *     with |z - eps[i]| <= 2**-8 + 2**-98 for the table used.
 *
 *   We compute exp2(i/TBLSIZE) via table lookup and exp2(z - eps[i]) via
 *   a degree-10 minimax polynomial with maximum error under 2**-120.
 *   The values in exp2t[] and eps[] are chosen such that
 *   exp2t[i] = exp2(i/TBLSIZE + eps[i]), and eps[i] is a small offset such
 *   that exp2t[i] is accurate to 2**-122.
 *
 *   Note that the range of i is +-TBLSIZE/2, so we actually index the tables
 *   by i0 = i + TBLSIZE/2.
 *
 *   This method is due to Gal, with many details due to Gal and Bachelis:
 *
 *	Gal, S. and Bachelis, B.  An Accurate Elementary Mathematical Library
 *	for the IEEE Floating Point Standard.  TOMS 17(1), 26-46 (1991).
 */

long double exp2l(long double x)
{
	union ldshape u = { x };
	int e = u.i.se & 0x7fff;
	long double r;
	long double z;
	long double t;
	uint32_t i0;
	union {
		uint32_t u;
		int32_t i;
	} k;

	/* Filter out exceptional cases. */
	if (e >= 0x3fff + 14) {		/* |x| >= 16384 or x is NaN */
		if (u.i.se >= 0x3fff + 15 && u.i.se >> 15 == 0) {
			/* overflow */
			return x * 0x1p16383L;
		}
		if (e == 0x7fff) {		/* -inf or -nan */
			return -1 / x;
		}
		if (x < -16382) {
			if (x <= -16495 || x - 0x1p112 + 0x1p112 != x) {
				/* underflow */
				FORCE_EVAL((float)(-0x1p-149 / x));
			}
			if (x <= -16446) {
				return 0;
			}
		}
	} else if (e < 0x3fff - 114) {
		return 1 + x;
	}

	/*
	 * Reduce x, computing z, i0, and k. The low bits of x + redux
	 * contain the 16-bit integer part of the exponent (k) followed by
	 * TBLBITS fractional bits (i0). We use bit tricks to extract these
	 * as integers, then set z to the remainder.
	 *
	 * Example: Suppose x is 0xabc.123456p0 and TBLBITS is 8.
	 * Then the low-order word of x + redux is 0x000abc12,
	 * We split this into k = 0xabc and i0 = 0x12 (adjusted to
	 * index into the table), then we compute z = 0x0.003456p0.
	 */
	u.f = x + redux;
	i0 = u.i2.lo + TBLSIZE / 2;
	k.u = i0 / TBLSIZE * TBLSIZE;
	k.i /= TBLSIZE;
	i0 %= TBLSIZE;
	u.f -= redux;
	z = x - u.f;

	/* Compute r = exp2(y) = exp2t[i0] * p(z - eps[i]). */
	t = tbl[i0];
	z -= eps[i0];
	r = t + t * z * (P1 + z * (P2 + z * (P3 + z * (P4 + z * (P5 + z * (P6 + z * (P7 + z * (P8 + z * (P9 + z * P10)))))))));

	return scalbnl(r, k.i);
}
#endif
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
 * libc/math/lib_expf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <sys/types.h>
#include <math.h>

#include "lib_internal.h"

/************************************************************************
 * Private Data
 ************************************************************************/

static float _flt_inv_fact[] = {
	1.0 / 1.0,					/* 1/0! */
	1.0 / 1.0,					/* 1/1! */
	1.0 / 2.0,					/* 1/2! */
	1.0 / 6.0,					/* 1/3! */
	1.0 / 24.0,					/* 1/4! */
	1.0 / 120.0,				/* 1/5! */
	1.0 / 720.0,				/* 1/6! */
	1.0 / 5040.0,				/* 1/7! */
	1.0 / 40320.0,				/* 1/8! */
	1.0 / 362880.0,				/* 1/9! */
	1.0 / 3628800.0,			/* 1/10! */
};

/************************************************************************
 * Public Functions
 ************************************************************************/

float expf(float x)
{
	size_t int_part;
	bool invert;
	float value;
	float x0;
	size_t i;

	if (x == 0) {
		return 1;
	} else if (x < 0) {
		invert = true;
		x = -x;
	} else {
		invert = false;
	}

	/* Extract integer component */

	int_part = (size_t)x;

	/* set x to fractional component */

	x -= (float)int_part;

	/* Perform Taylor series approximation with eleven terms */

	value = 0.0;
	x0 = 1.0;
	for (i = 0; i < 10; i++) {
		value += x0 * _flt_inv_fact[i];
		x0 *= x;
	}

	/* Multiply by exp of the integer component */

	value *= lib_expi(int_part);

	if (invert) {
		return (1.0 / value);
	} else {
		return value;
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
/************************************************************************
 * libc/math/lib_expl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <sys/types.h>
#include <math.h>

#include "lib_internal.h"

#ifdef CONFIG_HAVE_LONG_DOUBLE

/************************************************************************
 * Private Data
 ************************************************************************/

static long double _ldbl_inv_fact[] = {
	1.0 / 1.0,					/* 1 / 0! */
	1.0 / 1.0,					/* 1 / 1! */
	1.0 / 2.0,					/* 1 / 2! */
	1.0 / 6.0,					/* 1 / 3! */
	1.0 / 24.0,					/* 1 / 4! */
	1.0 / 120.0,				/* 1 / 5! */
	1.0 / 720.0,				/* 1 / 6! */
	1.0 / 5040.0,				/* 1 / 7! */
	1.0 / 40320.0,				/* 1 / 8! */
	1.0 / 362880.0,				/* 1 / 9! */
	1.0 / 3628800.0,			/* 1 / 10! */
	1.0 / 39916800.0,			/* 1 / 11! */
	1.0 / 479001600.0,			/* 1 / 12! */
	1.0 / 6227020800.0,			/* 1 / 13! */
	1.0 / 87178291200.0,		/* 1 / 14! */
	1.0 / 1307674368000.0,		/* 1 / 15! */
	1.0 / 20922789888000.0,		/* 1 / 16! */
	1.0 / 355687428096000.0,	/* 1 / 17! */
	1.0 / 6402373705728000.0,	/* 1 / 18! */
};

/************************************************************************
 * Public Functions
 ************************************************************************/

long double expl(long double x)
{
	size_t int_part;
	bool invert;
	long double value;
	long double x0;
	size_t i;

	if (x == 0) {
		return 1;
	} else if (x < 0) {
		invert = true;
		x = -x;
	} else {
		invert = false;
	}

	/* Extract integer component */

	int_part = (size_t)x;

	/* Set x to fractional component */

	x -= (long double)int_part;

	/* Perform Taylor series approximation with nineteen terms */

	value = 0.0;
	x0 = 1.0;
	for (i = 0; i < 19; i++) {
		value += x0 * _ldbl_inv_fact[i];
		x0 *= x;
	}

	/* Multiply by exp of the integer component */

	value *= lib_expi(int_part);

	if (invert) {
		return (1.0 / value);
	} else {
		return value;
	}
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
 * libc/math/lib_fabs.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double fabs(double x)
{
	return ((x < 0) ? -x : x);
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
 * libc/math/lib_fabsf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float fabsf(float x)
{
	return ((x < 0) ? -x : x);
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
 * libc/math/lib_fabsl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double fabsl(long double x)
{
	return ((x < 0) ? -x : x);
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double fdim(double x, double y)
{
	if (isnan(x)) {
		return x;
	}
	if (isnan(y)) {
		return y;
	}

	return x > y ? x - y : 0;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float fdimf(float x, float y)
{
	if (isnan(x)) {
		return x;
	}
	if (isnan(y)) {
		return y;
	}

	return x > y ? x - y : 0;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double fdiml(long double x, long double y)
{
	if (isnan(x)) {
		return x;
	}
	if (isnan(y)) {
		return y;
	}

	return x > y ? x - y : 0;
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
 * libc/math/lib_floor.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double floor(double x)
{
	modf(x, &x);
	if (x < 0.0) {
		x -= 1.0;
	}

	return x;
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
 * libc/math/lib_floorf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float floorf(float x)
{
	modff(x, &x);
	if (x < 0.0) {
		x -= 1.0;
	}

	return x;
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
 * libc/math/lib_floorl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double floorl(long double x)
{
	modfl(x, &x);
	if (x < 0.0) {
		x -= 1.0;
	}

	return x;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Public Functions
 ************************************************************************/

double fmax(double x, double y)
{
	if (isnan(x)) {
		return y;
	}
	if (isnan(y)) {
		return x;
	}
	/* handle signed zeros, see C99 Annex F.9.9.2 */
	if (signbit(x) != signbit(y)) {
		return signbit(x) ? y : x;
	}
	return x < y ? y : x;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float fmaxf(float x, float y)
{
	if (isnan(x)) {
		return y;
	}
	if (isnan(y)) {
		return x;
	}
	/* handle signed zeroes, see C99 Annex F.9.9.2 */
	if (signbit(x) != signbit(y)) {
		return signbit(x) ? y : x;
	}
	return x < y ? y : x;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <float.h>

#ifdef CONFIG_HAVE_LONG_DOUBLE

/************************************************************************
 * Public Functions
 ************************************************************************/

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double fmaxl(long double x, long double y)
{
	return fmax(x, y);
}
#else
long double fmaxl(long double x, long double y)
{
	if (isnan(x)) {
		return y;
	}
	if (isnan(y)) {
		return x;
	}
	/* handle signed zeros, see C99 Annex F.9.9.2 */
	if (signbit(x) != signbit(y)) {
		return signbit(x) ? y : x;
	}
	return x < y ? y : x;
}
#endif
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Public Functions
 ************************************************************************/

double fmin(double x, double y)
{
	if (isnan(x)) {
		return y;
	}
	if (isnan(y)) {
		return x;
	}
	/* handle signed zeros, see C99 Annex F.9.9.2 */
	if (signbit(x) != signbit(y)) {
		return signbit(x) ? x : y;
	}
	return x < y ? x : y;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float fminf(float x, float y)
{
	if (isnan(x)) {
		return y;
	}
	if (isnan(y)) {
		return x;
	}
	/* handle signed zeros, see C99 Annex F.9.9.2 */
	if (signbit(x) != signbit(y)) {
		return signbit(x) ? x : y;
	}
	return x < y ? x : y;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <float.h>

#ifdef CONFIG_HAVE_LONG_DOUBLE

/************************************************************************
 * Public Functions
 ************************************************************************/

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double fminl(long double x, long double y)
{
	return fmin(x, y);
}
#else
long double fminl(long double x, long double y)
{
	if (isnan(x)) {
		return y;
	}
	if (isnan(y)) {
		return x;
	}
	/* handle signed zeros, see C99 Annex F.9.9.2 */
	if (signbit(x) != signbit(y)) {
		return signbit(x) ? x : y;
	}
	return x < y ? x : y;
}
#endif
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
 * libc/math/lib_fmod.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double fmod(double x, double div)
{
	double n0;

	x /= div;
	x = modf(x, &n0);
	x *= div;

	return x;
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
 * libc/math/lib_fmodf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float fmodf(float x, float div)
{
	float n0;

	x /= div;
	x = modff(x, &n0);
	x *= div;

	return x;
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
 * libc/math/lib_fmodl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double fmodl(long double x, long double div)
{
	long double n0;

	x /= div;
	x = modfl(x, &n0);
	x *= div;

	return x;
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
 * libc/math/lib_frexp.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double frexp(double x, int *exponent)
{
	*exponent = (int)ceil(log2(x));
	return x / ldexp(1.0, *exponent);
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
 * libc/math/lib_frexpf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float frexpf(float x, int *exponent)
{
	*exponent = (int)ceilf(log2f(x));
	return x / ldexpf(1.0, *exponent);
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
 * libc/math/lib_frexpl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double frexpl(long double x, int *exponent)
{
	*exponent = (int)ceill(log2(x));
	return x / ldexpl(1.0, *exponent);
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
 * libc/math/lib_gamma.c
 *
 * Ported to NuttX from FreeBSD by Alan Carvalho de Assis:
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

/* "A Precision Approximation of the Gamma Function" - Cornelius Lanczos (1964)
 * "Lanczos Implementation of the Gamma Function" - Paul Godfrey (2001)
 * "An Analysis of the Lanczos Gamma Approximation" - Glendon Ralph Pugh (2004)
 *
 * approximation method:
 *
 *                         (x - 0.5)         S(x)
 * Gamma(x) = (x + g - 0.5)         *  ----------------
 *                                     exp(x + g - 0.5)
 *
 * with
 *                  a1      a2      a3            aN
 * S(x) ~= [ a0 + ----- + ----- + ----- + ... + ----- ]
 *                x + 1   x + 2   x + 3         x + N
 *
 * with a0, a1, a2, a3,.. aN constants which depend on g.
 *
 * for x < 0 the following reflection formula is used:
 *
 * Gamma(x)*Gamma(-x) = -pi/(x sin(pi x))
 *
 * most ideas and constants are from boost and python
 */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <sys/types.h>
#include <math.h>

#include "libm.h"

#ifdef CONFIG_HAVE_DOUBLE

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define N 12

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const double pi = 3.141592653589793238462643383279502884;

static const double g_gmhalf = 5.524680040776729583740234375;
static const double g_snum[N + 1] = {
	23531376880.410759688572007674451636754734846804940,
	42919803642.649098768957899047001988850926355848959,
	35711959237.355668049440185451547166705960488635843,
	17921034426.037209699919755754458931112671403265390,
	6039542586.3520280050642916443072979210699388420708,
	1439720407.3117216736632230727949123939715485786772,
	248874557.86205415651146038641322942321632125127801,
	31426415.585400194380614231628318205362874684987640,
	2876370.6289353724412254090516208496135991145378768,
	186056.26539522349504029498971604569928220784236328,
	8071.6720023658162106380029022722506138218516325024,
	210.82427775157934587250973392071336271166969580291,
	2.5066282746310002701649081771338373386264310793408,
};

static const double g_sden[N + 1] = {
	0, 39916800, 120543840, 150917976, 105258076, 45995730, 13339535,
	2637558, 357423, 32670, 1925, 66, 1,
};

/* n! for small integer n */

static const double g_fact[] = {
	1, 1, 2, 6, 24, 120, 720, 5040.0, 40320.0, 362880.0, 3628800.0, 39916800.0,
	479001600.0, 6227020800.0, 87178291200.0, 1307674368000.0, 20922789888000.0,
	355687428096000.0, 6402373705728000.0, 121645100408832000.0,
	2432902008176640000.0, 51090942171709440000.0, 1124000727777607680000.0,
};

/* S(x) rational function for positive x */

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/* sin(pi x) with x > 0x1p-100, if sin(pi*x)==0 the sign is arbitrary */

static double sinpi(double x)
{
	int n;

	/* argument reduction: x = |x| mod 2 */
	/* spurious inexact when x is odd int */

	x = x * 0.5;
	x = 2 * (x - floor(x));

	/* reduce x into [-.25,.25] */

	n = 4 * x;
	n = (n + 1) / 2;
	x -= n * 0.5;

	x *= pi;
	switch (n) {
	default:					/* case 4 */
	case 0:
		return __sin(x, 0, 0);

	case 1:
		return __cos(x, 0);

	case 2:
		return __sin(-x, 0, 0);

	case 3:
		return -__cos(x, 0);
	}
}

static double s(double x)
{
	double num = 0;
	double den = 0;
	int i;

	/* to avoid overflow handle large x differently */

	if (x < 8) {
		for (i = N; i >= 0; i--) {
			num = num * x + g_snum[i];
			den = den * x + g_sden[i];
		}
	} else {
		for (i = 0; i <= N; i++) {
			num = num / x + g_snum[i];
			den = den / x + g_sden[i];
		}
	}

	return num / den;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

double tgamma(double x)
{
	union {
		double f;
		uint64_t i;
	} u;
	u.f = x;

	double absx;
	double y;
	double dy;
	double z;
	double r;
	uint32_t ix = u.i >> 32 & 0x7fffffff;
	int sign = u.i >> 63;

	/* special cases */

	if (ix >= 0x7ff00000) {
		/* tgamma(nan)=nan, tgamma(inf)=inf, tgamma(-inf)=nan with invalid */

		return x + INFINITY;
	}

	if (ix < (0x3ff - 54) << 20) {
		/* |x| < 2^-54: tgamma(x) ~ 1/x, +-0 raises div-by-zero */
		return 1 / x;
	}

	/* integer arguments */
	/* raise inexact when non-integer */

	if (x == floor(x)) {
		if (sign) {
			return 0 / 0.0;
		}

		if (x <= sizeof g_fact / sizeof * g_fact) {
			return g_fact[(int)x - 1];
		}
	}

	/* x >= 172: tgamma(x)=inf with overflow */
	/* x =< -184: tgamma(x)=+-0 with underflow */

	if (ix >= 0x40670000) {
		/* |x| >= 184 */

		if (sign) {
			FORCE_EVAL((float)(0x1p-126 / x));
			if (floor(x) * 0.5 == floor(x * 0.5)) {
				return 0;
			}
			return -0.0;
		}

		x *= 0x1p1023;
		return x;
	}

	absx = sign ? -x : x;

	/* handle the error of x + g - 0.5 */

	y = absx + g_gmhalf;
	if (absx > g_gmhalf) {
		dy = y - absx;
		dy -= g_gmhalf;
	} else {
		dy = y - g_gmhalf;
		dy -= absx;
	}

	z = absx - 0.5;
	r = s(absx) * exp(-y);
	if (x < 0) {
		/* reflection formula for negative x */
		/* sinpi(absx) is not 0, integers are already handled */

		r = -pi / (sinpi(absx) * absx * r);
		dy = -dy;
		z = -z;
	}

	r += dy * (g_gmhalf + 0.5) * r / y;
	z = pow(y, 0.5 * z);
	y = r * z * z;

	return y;
}

double gamma(double x)
{
	return tgamma(x);
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <stdint.h>
#include <tinyara/float.h>

#ifdef CONFIG_HAVE_DOUBLE

#if FLT_EVAL_METHOD > 1U && LDBL_MANT_DIG == 64
#define SPLIT (0x1p32 + 1)
#else
#define SPLIT (0x1p27 + 1)
#endif

/************************************************************************
 * Private Functions
 ************************************************************************/

static void sq(double *hi, double *lo, double x)
{
	double xh;
	double xl;
	double xc;

	xc = (double)x * SPLIT;
	xh = x - xc + xc;
	xl = x - xh;
	*hi = (double)x * x;
	*lo = xh * xh - *hi + 2 * xh * xl + xl * xl;
}

/************************************************************************
 * Public Functions
 ************************************************************************/

double hypot(double x, double y)
{
	union {
		double f;
		uint64_t i;
	} ux = {
		x
	}, uy = {
		y
	}, ut;
	int ex;
	int ey;
	double hx;
	double lx;
	double hy;
	double ly;
	double z;

	/* arrange |x| >= |y| */
	ux.i &= -1ULL >> 1;
	uy.i &= -1ULL >> 1;
	if (ux.i < uy.i) {
		ut = ux;
		ux = uy;
		uy = ut;
	}

	/* special cases */
	ex = ux.i >> 52;
	ey = uy.i >> 52;
	x = ux.f;
	y = uy.f;
	/* note: hypot(inf,nan) == inf */
	if (ey == 0x7ff) {
		return y;
	}
	if (ex == 0x7ff || uy.i == 0) {
		return x;
	}
	/* note: hypot(x,y) ~= x + y*y/x/2 with inexact for small y/x */
	/* 64 difference is enough for ld80 double */
	if (ex - ey > 64) {
		return x + y;
	}

	/* precise sqrt argument in nearest rounding mode without overflow */
	/* xh*xh must not overflow and xl*xl must not underflow in sq */
	z = 1;
	if (ex > 0x3ff + 510) {
		z = 0x1p700;
		x *= 0x1p-700;
		y *= 0x1p-700;
	} else if (ey < 0x3ff - 450) {
		z = 0x1p-700;
		x *= 0x1p700;
		y *= 0x1p700;
	}
	sq(&hx, &lx, x);
	sq(&hy, &ly, y);
	return z * sqrt(ly + lx + hy + hx);
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
 ***************************************************************************/
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>
#include <stdint.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float hypotf(float x, float y)
{
	union {
		float f;
		uint32_t i;
	} ux = { x }, uy = { y }, ut;
	float z;

	ux.i &= -1U >> 1;
	uy.i &= -1U >> 1;
	if (ux.i < uy.i) {
		ut = ux;
		ux = uy;
		uy = ut;
	}

	x = ux.f;
	y = uy.f;
	if (uy.i == 0xff << 23) {
		return y;
	}
	if (ux.i >= 0xff << 23 || uy.i == 0 || ux.i - uy.i >= 25 << 23) {
		return x + y;
	}

	z = 1;
	if (ux.i >= (0x7f + 60) << 23) {
		z = 0x1p90f;
		x *= 0x1p-90f;
		y *= 0x1p-90f;
	} else if (uy.i < (0x7f - 60) << 23) {
		z = 0x1p-90f;
		x *= 0x1p90f;
		y *= 0x1p90f;
	}
	return z * sqrtf((double)x * x + (double)y * y);
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
 ***************************************************************************/
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include "libm.h"

#ifdef CONFIG_HAVE_LONG_DOUBLE

/************************************************************************
 * Public Functions
 ************************************************************************/

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double hypotl(long double x, long double y)
{
	return hypot(x, y);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#if LDBL_MANT_DIG == 64
#define SPLIT (0x1p32L+1)
#elif LDBL_MANT_DIG == 113
#define SPLIT (0x1p57L+1)
#endif

/************************************************************************
 * Private Functions
 ************************************************************************/

static void sq(long double *hi, long double *lo, long double x)
{
	long double xh;
	long double xl;
	long double xc;
	xc = x * SPLIT;
	xh = x - xc + xc;
	xl = x - xh;
	*hi = x * x;
	*lo = xh * xh - *hi + 2 * xh * xl + xl * xl;
}

/************************************************************************
 * Public Functions
 ************************************************************************/

long double hypotl(long double x, long double y)
{
	union ldshape ux = { x }, uy = {
		y
	};
	int ex;
	int ey;
	long double hx;
	long double lx;
	long double hy;
	long double ly;
	long double z;

	ux.i.se &= 0x7fff;
	uy.i.se &= 0x7fff;
	if (ux.i.se < uy.i.se) {
		ex = uy.i.se;
		ey = ux.i.se;
		x = uy.f;
		y = ux.f;
	} else {
		ex = ux.i.se;
		ey = uy.i.se;
		x = ux.f;
		y = uy.f;
	}

	if (ex == 0x7fff && isinf(y)) {
		return y;
	}
	if (ex == 0x7fff || y == 0) {
		return x;
	}
	if (ex - ey > LDBL_MANT_DIG) {
		return x + y;
	}

	z = 1;
	if (ex > 0x3fff + 8000) {
		z = 0x1p10000L;
		x *= 0x1p-10000L;
		y *= 0x1p-10000L;
	} else if (ey < 0x3fff - 8000) {
		z = 0x1p-10000L;
		x *= 0x1p10000L;
		y *= 0x1p10000L;
	}
	sq(&hx, &lx, x);
	sq(&hy, &ly, y);
	return z * sqrtl(ly + lx + hy + hx);
}
#endif
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
 * origin: FreeBSD /usr/src/lib/msun/src/e_j0.c
 *
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 * j0(x), y0(x)
 * Bessel function of the first and second kinds of order zero.
 * Method -- j0(x):
 *      1. For tiny x, we use j0(x) = 1 - x^2/4 + x^4/64 - ...
 *      2. Reduce x to |x| since j0(x)=j0(-x),  and
 *         for x in (0,2)
 *              j0(x) = 1-z/4+ z^2*R0/S0,  where z = x*x;
 *         (precision:  |j0-1+z/4-z^2R0/S0 |<2**-63.67 )
 *         for x in (2,inf)
 *              j0(x) = sqrt(2/(pi*x))*(p0(x)*cos(x0)-q0(x)*sin(x0))
 *         where x0 = x-pi/4. It is better to compute sin(x0),cos(x0)
 *         as follow:
 *              cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
 *                      = 1/sqrt(2) * (cos(x) + sin(x))
 *              sin(x0) = sin(x)cos(pi/4)-cos(x)sin(pi/4)
 *                      = 1/sqrt(2) * (sin(x) - cos(x))
 *         (To avoid cancellation, use
 *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
 *          to compute the worse one.)
 *
 *      3 Special cases
 *              j0(nan)= nan
 *              j0(0) = 1
 *              j0(inf) = 0
 *
 * Method -- y0(x):
 *      1. For x<2.
 *         Since
 *              y0(x) = 2/pi*(j0(x)*(ln(x/2)+Euler) + x^2/4 - ...)
 *         therefore y0(x)-2/pi*j0(x)*ln(x) is an even function.
 *         We use the following function to approximate y0,
 *              y0(x) = U(z)/V(z) + (2/pi)*(j0(x)*ln(x)), z= x^2
 *         where
 *              U(z) = u00 + u01*z + ... + u06*z^6
 *              V(z) = 1  + v01*z + ... + v04*z^4
 *         with absolute approximation error bounded by 2**-72.
 *         Note: For tiny x, U/V = u0 and j0(x)~1, hence
 *              y0(tiny) = u0 + (2/pi)*ln(tiny), (choose tiny<2**-27)
 *      2. For x>=2.
 *              y0(x) = sqrt(2/(pi*x))*(p0(x)*cos(x0)+q0(x)*sin(x0))
 *         where x0 = x-pi/4. It is better to compute sin(x0),cos(x0)
 *         by the method mentioned above.
 *      3. Special cases: y0(0)=-inf, y0(x<0)=NaN, y0(inf)=0.
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>
#include <sys/types.h>

#include "libm.h"

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Private Data
 ************************************************************************/

static double pzero(double);
static double qzero(double);

static const double invsqrtpi = 5.64189583547756279280e-01;	/* 0x3FE20DD7, 0x50429B6D */
static const double	tpi = 6.36619772367581382433e-01;	/* 0x3FE45F30, 0x6DC9C883 */

/************************************************************************
 * Private Function
 ************************************************************************/

/* common method when |x|>=2 */
static double common(uint32_t ix, double x, int y0)
{
	double s;
	double c;
	double ss;
	double cc;
	double z;

	/*
	 * j0(x) = sqrt(2/(pi*x))*(p0(x)*cos(x-pi/4)-q0(x)*sin(x-pi/4))
	 * y0(x) = sqrt(2/(pi*x))*(p0(x)*sin(x-pi/4)+q0(x)*cos(x-pi/4))
	 *
	 * sin(x-pi/4) = (sin(x) - cos(x))/sqrt(2)
	 * cos(x-pi/4) = (sin(x) + cos(x))/sqrt(2)
	 * sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
	 */
	s = sin(x);
	c = cos(x);
	if (y0) {
		c = -c;
	}
	cc = s + c;
	/* avoid overflow in 2*x, big ulp error when x>=0x1p1023 */
	if (ix < 0x7fe00000) {
		ss = s - c;
		z = -cos(2 * x);
		if (s * c < 0) {
			cc = z / ss;
		} else {
			ss = z / cc;
		}
		if (ix < 0x48000000) {
			if (y0) {
				ss = -ss;
			}
			cc = pzero(x) * cc - qzero(x) * ss;
		}
	}
	return invsqrtpi * cc / sqrt(x);
}

/************************************************************************
 * Private Data
 ************************************************************************/

/* R0/S0 on [0, 2.00] */
static const double R02 = 1.56249999999999947958e-02;	/* 0x3F8FFFFF, 0xFFFFFFFD */
static const double R03 = -1.89979294238854721751e-04;	/* 0xBF28E6A5, 0xB61AC6E9 */
static const double R04 = 1.82954049532700665670e-06;	/* 0x3EBEB1D1, 0x0C503919 */
static const double R05 = -4.61832688532103189199e-09;	/* 0xBE33D5E7, 0x73D63FCE */
static const double S01 = 1.56191029464890010492e-02;	/* 0x3F8FFCE8, 0x82C8C2A4 */
static const double S02 = 1.16926784663337450260e-04;	/* 0x3F1EA6D2, 0xDD57DBF4 */
static const double S03 = 5.13546550207318111446e-07;	/* 0x3EA13B54, 0xCE84D5A9 */
static const double S04 = 1.16614003333790000205e-09;	/* 0x3E1408BC, 0xF4745D8F */

/************************************************************************
 * Public Function
 ************************************************************************/

double j0(double x)
{
	double z;
	double r;
	double s;
	uint32_t ix;

	GET_HIGH_WORD(ix, x);
	ix &= 0x7fffffff;

	/* j0(+-inf)=0, j0(nan)=nan */
	if (ix >= 0x7ff00000) {
		return 1 / (x * x);
	}
	x = fabs(x);

	if (ix >= 0x40000000) {		/* |x| >= 2 */
		/* large ulp error near zeros: 2.4, 5.52, 8.6537,.. */
		return common(ix, x, 0);
	}

	/* 1 - x*x/4 + x*x*R(x^2)/S(x^2) */
	if (ix >= 0x3f200000) {		/* |x| >= 2**-13 */
		/* up to 4ulp error close to 2 */
		z = x * x;
		r = z * (R02 + z * (R03 + z * (R04 + z * R05)));
		s = 1 + z * (S01 + z * (S02 + z * (S03 + z * S04)));
		return (1 + x / 2) * (1 - x / 2) + z * (r / s);
	}

	/* 1 - x*x/4 */
	/* prevent underflow */
	/* inexact should be raised when x!=0, this is not done correctly */
	if (ix >= 0x38000000) {		/* |x| >= 2**-127 */
		x = 0.25 * x * x;
	}
	return 1 - x;
}

/************************************************************************
 * Private Data
 ************************************************************************/

static const double u00 = -7.38042951086872317523e-02;	/* 0xBFB2E4D6, 0x99CBD01F */
static const double u01 = 1.76666452509181115538e-01;	/* 0x3FC69D01, 0x9DE9E3FC */
static const double	u02 = -1.38185671945596898896e-02;	/* 0xBF8C4CE8, 0xB16CFA97 */
static const double	u03 = 3.47453432093683650238e-04;	/* 0x3F36C54D, 0x20B29B6B */
static const double	u04 = -3.81407053724364161125e-06;	/* 0xBECFFEA7, 0x73D25CAD */
static const double	u05 = 1.95590137035022920206e-08;	/* 0x3E550057, 0x3B4EABD4 */
static const double	u06 = -3.98205194132103398453e-11;	/* 0xBDC5E43D, 0x693FB3C8 */
static const double	v01 = 1.27304834834123699328e-02;	/* 0x3F8A1270, 0x91C9C71A */
static const double	v02 = 7.60068627350353253702e-05;	/* 0x3F13ECBB, 0xF578C6C1 */
static const double	v03 = 2.59150851840457805467e-07;	/* 0x3E91642D, 0x7FF202FD */
static const double	v04 = 4.41110311332675467403e-10;	/* 0x3DFE5018, 0x3BD6D9EF */

/************************************************************************
 * Public Function
 ************************************************************************/

double y0(double x)
{
	double z;
	double u;
	double v;
	uint32_t ix;
	uint32_t lx;

	EXTRACT_WORDS(ix, lx, x);

	/* y0(nan)=nan, y0(<0)=nan, y0(0)=-inf, y0(inf)=0 */
	if ((ix << 1 | lx) == 0) {
		return -1 / 0.0;
	}
	if (ix >> 31) {
		return 0 / 0.0;
	}
	if (ix >= 0x7ff00000) {
		return 1 / x;
	}

	if (ix >= 0x40000000) {		/* x >= 2 */
		/* large ulp errors near zeros: 3.958, 7.086,.. */
		return common(ix, x, 1);
	}

	/* U(x^2)/V(x^2) + (2/pi)*j0(x)*log(x) */
	if (ix >= 0x3e400000) {		/* x >= 2**-27 */
		/* large ulp error near the first zero, x ~= 0.89 */
		z = x * x;
		u = u00 + z * (u01 + z * (u02 + z * (u03 + z * (u04 + z * (u05 + z * u06)))));
		v = 1.0 + z * (v01 + z * (v02 + z * (v03 + z * v04)));
		return u / v + tpi * (j0(x) * log(x));
	}
	return u00 + tpi * log(x);
}

/************************************************************************
 * Private Data
 ************************************************************************/

/* The asymptotic expansions of pzero is
 *      1 - 9/128 s^2 + 11025/98304 s^4 - ...,  where s = 1/x.
 * For x >= 2, We approximate pzero by
 *      pzero(x) = 1 + (R/S)
 * where  R = pR0 + pR1*s^2 + pR2*s^4 + ... + pR5*s^10
 *        S = 1 + pS0*s^2 + ... + pS4*s^10
 * and
 *      | pzero(x)-1-R/S | <= 2  ** ( -60.26)
 */
static const double pR8[6] = {	/* for x in [inf, 8]=1/[0,0.125] */
	0.00000000000000000000e+00,	/* 0x00000000, 0x00000000 */
	-7.03124999999900357484e-02,	/* 0xBFB1FFFF, 0xFFFFFD32 */
	-8.08167041275349795626e+00,	/* 0xC02029D0, 0xB44FA779 */
	-2.57063105679704847262e+02,	/* 0xC0701102, 0x7B19E863 */
	-2.48521641009428822144e+03,	/* 0xC0A36A6E, 0xCD4DCAFC */
	-5.25304380490729545272e+03,	/* 0xC0B4850B, 0x36CC643D */
};

static const double pS8[5] = {
	1.16534364619668181717e+02,	/* 0x405D2233, 0x07A96751 */
	3.83374475364121826715e+03,	/* 0x40ADF37D, 0x50596938 */
	4.05978572648472545552e+04,	/* 0x40E3D2BB, 0x6EB6B05F */
	1.16752972564375915681e+05,	/* 0x40FC810F, 0x8F9FA9BD */
	4.76277284146730962675e+04,	/* 0x40E74177, 0x4F2C49DC */
};

static const double pR5[6] = {	/* for x in [8,4.5454]=1/[0.125,0.22001] */
	-1.14125464691894502584e-11,	/* 0xBDA918B1, 0x47E495CC */
	-7.03124940873599280078e-02,	/* 0xBFB1FFFF, 0xE69AFBC6 */
	-4.15961064470587782438e+00,	/* 0xC010A370, 0xF90C6BBF */
	-6.76747652265167261021e+01,	/* 0xC050EB2F, 0x5A7D1783 */
	-3.31231299649172967747e+02,	/* 0xC074B3B3, 0x6742CC63 */
	-3.46433388365604912451e+02,	/* 0xC075A6EF, 0x28A38BD7 */
};

static const double pS5[5] = {
	6.07539382692300335975e+01,	/* 0x404E6081, 0x0C98C5DE */
	1.05125230595704579173e+03,	/* 0x40906D02, 0x5C7E2864 */
	5.97897094333855784498e+03,	/* 0x40B75AF8, 0x8FBE1D60 */
	9.62544514357774460223e+03,	/* 0x40C2CCB8, 0xFA76FA38 */
	2.40605815922939109441e+03,	/* 0x40A2CC1D, 0xC70BE864 */
};

static const double pR3[6] = {	/* for x in [4.547,2.8571]=1/[0.2199,0.35001] */
	-2.54704601771951915620e-09,	/* 0xBE25E103, 0x6FE1AA86 */
	-7.03119616381481654654e-02,	/* 0xBFB1FFF6, 0xF7C0E24B */
	-2.40903221549529611423e+00,	/* 0xC00345B2, 0xAEA48074 */
	-2.19659774734883086467e+01,	/* 0xC035F74A, 0x4CB94E14 */
	-5.80791704701737572236e+01,	/* 0xC04D0A22, 0x420A1A45 */
	-3.14479470594888503854e+01,	/* 0xC03F72AC, 0xA892D80F */
};

static const double pS3[5] = {
	3.58560338055209726349e+01,	/* 0x4041ED92, 0x84077DD3 */
	3.61513983050303863820e+02,	/* 0x40769839, 0x464A7C0E */
	1.19360783792111533330e+03,	/* 0x4092A66E, 0x6D1061D6 */
	1.12799679856907414432e+03,	/* 0x40919FFC, 0xB8C39B7E */
	1.73580930813335754692e+02,	/* 0x4065B296, 0xFC379081 */
};

static const double pR2[6] = {	/* for x in [2.8570,2]=1/[0.3499,0.5] */
	-8.87534333032526411254e-08,	/* 0xBE77D316, 0xE927026D */
	-7.03030995483624743247e-02,	/* 0xBFB1FF62, 0x495E1E42 */
	-1.45073846780952986357e+00,	/* 0xBFF73639, 0x8A24A843 */
	-7.63569613823527770791e+00,	/* 0xC01E8AF3, 0xEDAFA7F3 */
	-1.11931668860356747786e+01,	/* 0xC02662E6, 0xC5246303 */
	-3.23364579351335335033e+00,	/* 0xC009DE81, 0xAF8FE70F */
};

static const double pS2[5] = {
	2.22202997532088808441e+01,	/* 0x40363865, 0x908B5959 */
	1.36206794218215208048e+02,	/* 0x4061069E, 0x0EE8878F */
	2.70470278658083486789e+02,	/* 0x4070E786, 0x42EA079B */
	1.53875394208320329881e+02,	/* 0x40633C03, 0x3AB6FAFF */
	1.46576176948256193810e+01,	/* 0x402D50B3, 0x44391809 */
};

/************************************************************************
 * Private Function
 ************************************************************************/

static double pzero(double x)
{
	const double *p;
	const double *q;
	double_t z;
	double_t r;
	double_t s;
	uint32_t ix;

	GET_HIGH_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x40200000) {
		p = pR8;
		q = pS8;
	} else if (ix >= 0x40122E8B) {
		p = pR5;
		q = pS5;
	} else if (ix >= 0x4006DB6D) {
		p = pR3;
		q = pS3;
	} else {					/*ix >= 0x40000000 */
		p = pR2;
		q = pS2;
	}
	z = 1.0 / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0 + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
	return 1.0 + r / s;
}

/************************************************************************
 * Private Data
 ************************************************************************/

/* For x >= 8, the asymptotic expansions of qzero is
 *      -1/8 s + 75/1024 s^3 - ..., where s = 1/x.
 * We approximate pzero by
 *      qzero(x) = s*(-1.25 + (R/S))
 * where  R = qR0 + qR1*s^2 + qR2*s^4 + ... + qR5*s^10
 *        S = 1 + qS0*s^2 + ... + qS5*s^12
 * and
 *      | qzero(x)/s +1.25-R/S | <= 2  ** ( -61.22)
 */
static const double qR8[6] = {	/* for x in [inf, 8]=1/[0,0.125] */
	0.00000000000000000000e+00,	/* 0x00000000, 0x00000000 */
	7.32421874999935051953e-02,	/* 0x3FB2BFFF, 0xFFFFFE2C */
	1.17682064682252693899e+01,	/* 0x40278952, 0x5BB334D6 */
	5.57673380256401856059e+02,	/* 0x40816D63, 0x15301825 */
	8.85919720756468632317e+03,	/* 0x40C14D99, 0x3E18F46D */
	3.70146267776887834771e+04,	/* 0x40E212D4, 0x0E901566 */
};

static const double qS8[6] = {
	1.63776026895689824414e+02,	/* 0x406478D5, 0x365B39BC */
	8.09834494656449805916e+03,	/* 0x40BFA258, 0x4E6B0563 */
	1.42538291419120476348e+05,	/* 0x41016652, 0x54D38C3F */
	8.03309257119514397345e+05,	/* 0x412883DA, 0x83A52B43 */
	8.40501579819060512818e+05,	/* 0x4129A66B, 0x28DE0B3D */
	-3.43899293537866615225e+05,	/* 0xC114FD6D, 0x2C9530C5 */
};

static const double qR5[6] = {	/* for x in [8,4.5454]=1/[0.125,0.22001] */
	1.84085963594515531381e-11,	/* 0x3DB43D8F, 0x29CC8CD9 */
	7.32421766612684765896e-02,	/* 0x3FB2BFFF, 0xD172B04C */
	5.83563508962056953777e+00,	/* 0x401757B0, 0xB9953DD3 */
	1.35111577286449829671e+02,	/* 0x4060E392, 0x0A8788E9 */
	1.02724376596164097464e+03,	/* 0x40900CF9, 0x9DC8C481 */
	1.98997785864605384631e+03,	/* 0x409F17E9, 0x53C6E3A6 */
};

static const double qS5[6] = {
	8.27766102236537761883e+01,	/* 0x4054B1B3, 0xFB5E1543 */
	2.07781416421392987104e+03,	/* 0x40A03BA0, 0xDA21C0CE */
	1.88472887785718085070e+04,	/* 0x40D267D2, 0x7B591E6D */
	5.67511122894947329769e+04,	/* 0x40EBB5E3, 0x97E02372 */
	3.59767538425114471465e+04,	/* 0x40E19118, 0x1F7A54A0 */
	-5.35434275601944773371e+03,	/* 0xC0B4EA57, 0xBEDBC609 */
};

static const double qR3[6] = {	/* for x in [4.547,2.8571]=1/[0.2199,0.35001] */
	4.37741014089738620906e-09,	/* 0x3E32CD03, 0x6ADECB82 */
	7.32411180042911447163e-02,	/* 0x3FB2BFEE, 0x0E8D0842 */
	3.34423137516170720929e+00,	/* 0x400AC0FC, 0x61149CF5 */
	4.26218440745412650017e+01,	/* 0x40454F98, 0x962DAEDD */
	1.70808091340565596283e+02,	/* 0x406559DB, 0xE25EFD1F */
	1.66733948696651168575e+02,	/* 0x4064D77C, 0x81FA21E0 */
};

static const double qS3[6] = {
	4.87588729724587182091e+01,	/* 0x40486122, 0xBFE343A6 */
	7.09689221056606015736e+02,	/* 0x40862D83, 0x86544EB3 */
	3.70414822620111362994e+03,	/* 0x40ACF04B, 0xE44DFC63 */
	6.46042516752568917582e+03,	/* 0x40B93C6C, 0xD7C76A28 */
	2.51633368920368957333e+03,	/* 0x40A3A8AA, 0xD94FB1C0 */
	-1.49247451836156386662e+02,	/* 0xC062A7EB, 0x201CF40F */
};

static const double qR2[6] = {	/* for x in [2.8570,2]=1/[0.3499,0.5] */
	1.50444444886983272379e-07,	/* 0x3E84313B, 0x54F76BDB */
	7.32234265963079278272e-02,	/* 0x3FB2BEC5, 0x3E883E34 */
	1.99819174093815998816e+00,	/* 0x3FFFF897, 0xE727779C */
	1.44956029347885735348e+01,	/* 0x402CFDBF, 0xAAF96FE5 */
	3.16662317504781540833e+01,	/* 0x403FAA8E, 0x29FBDC4A */
	1.62527075710929267416e+01,	/* 0x403040B1, 0x71814BB4 */
};

static const double qS2[6] = {
	3.03655848355219184498e+01,	/* 0x403E5D96, 0xF7C07AED */
	2.69348118608049844624e+02,	/* 0x4070D591, 0xE4D14B40 */
	8.44783757595320139444e+02,	/* 0x408A6645, 0x22B3BF22 */
	8.82935845112488550512e+02,	/* 0x408B977C, 0x9C5CC214 */
	2.12666388511798828631e+02,	/* 0x406A9553, 0x0E001365 */
	-5.31095493882666946917e+00,	/* 0xC0153E6A, 0xF8B32931 */
};

/************************************************************************
 * Private Function
 ************************************************************************/

static double qzero(double x)
{
	const double *p;
	const double *q;
	double_t z;
	double_t r;
	double_t s;
	uint32_t ix;

	GET_HIGH_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x40200000) {
		p = qR8;
		q = qS8;
	} else if (ix >= 0x40122E8B) {
		p = qR5;
		q = qS5;
	} else if (ix >= 0x4006DB6D) {
		p = qR3;
		q = qS3;
	} else {					/*ix >= 0x40000000 */
		p = qR2;
		q = qS2;
	}
	z = 1.0 / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0 + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
	return (-.125 + r / s) / x;
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
 * origin: FreeBSD /usr/src/lib/msun/src/e_j0f.c
 *
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 *
 *
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 ****************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

#include "libm.h"

/************************************************************************
 * Private Data
 ************************************************************************/

static float pzerof(float);
static float qzerof(float);

static const float invsqrtpi = 5.6418961287e-01;	/* 0x3f106ebb */
static const float tpi = 6.3661974669e-01;		/* 0x3f22f983 */

/************************************************************************
 * Private Functions
 ************************************************************************/

static float common(uint32_t ix, float x, int y0)
{
	float z;
	float s;
	float c;
	float ss;
	float cc;
	/*
	 * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
	 * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
	 */
	s = sinf(x);
	c = cosf(x);
	if (y0) {
		c = -c;
	}
	cc = s + c;
	if (ix < 0x7f000000) {
		ss = s - c;
		z = -cosf(2 * x);
		if (s * c < 0) {
			cc = z / ss;
		} else {
			ss = z / cc;
		}
		if (ix < 0x58800000) {
			if (y0) {
				ss = -ss;
			}
			cc = pzerof(x) * cc - qzerof(x) * ss;
		}
	}
	return invsqrtpi * cc / sqrtf(x);
}

/************************************************************************
 * Private Data
 ************************************************************************/

/* R0/S0 on [0, 2.00] */
static const float R02 = 1.5625000000e-02;	/* 0x3c800000 */
static const float R03 = -1.8997929874e-04;	/* 0xb947352e */
static const float R04 = 1.8295404516e-06;		/* 0x35f58e88 */
static const float R05 = -4.6183270541e-09;	/* 0xb19eaf3c */
static const float S01 = 1.5619102865e-02;		/* 0x3c7fe744 */
static const float S02 = 1.1692678527e-04;		/* 0x38f53697 */
static const float S03 = 5.1354652442e-07;		/* 0x3509daa6 */
static const float S04 = 1.1661400734e-09;		/* 0x30a045e8 */

/************************************************************************
 * Public Functions
 ************************************************************************/

float j0f(float x)
{
	float z;
	float r;
	float s;
	uint32_t ix;

	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x7f800000) {
		return 1 / (x * x);
	}
	x = fabsf(x);

	if (ix >= 0x40000000) {		/* |x| >= 2 */
		/* large ulp error near zeros */
		return common(ix, x, 0);
	}
	if (ix >= 0x3a000000) {		/* |x| >= 2**-11 */
		/* up to 4ulp error near 2 */
		z = x * x;
		r = z * (R02 + z * (R03 + z * (R04 + z * R05)));
		s = 1 + z * (S01 + z * (S02 + z * (S03 + z * S04)));
		return (1 + x / 2) * (1 - x / 2) + z * (r / s);
	}
	if (ix >= 0x21800000) {		/* |x| >= 2**-60 */
		x = 0.25f * x * x;
	}
	return 1 - x;
}

/************************************************************************
 * Private Data
 ************************************************************************/

static const float u00 = -7.3804296553e-02;	/* 0xbd9726b5 */
static const float u01 = 1.7666645348e-01;		/* 0x3e34e80d */
static const float u02 = -1.3818567619e-02;	/* 0xbc626746 */
static const float u03 = 3.4745343146e-04;		/* 0x39b62a69 */
static const float u04 = -3.8140706238e-06;	/* 0xb67ff53c */
static const float u05 = 1.9559013964e-08;		/* 0x32a802ba */
static const float u06 = -3.9820518410e-11;	/* 0xae2f21eb */
static const float v01 = 1.2730483897e-02;		/* 0x3c509385 */
static const float v02 = 7.6006865129e-05;		/* 0x389f65e0 */
static const float v03 = 2.5915085189e-07;		/* 0x348b216c */
static const float v04 = 4.4111031494e-10;		/* 0x2ff280c2 */

/************************************************************************
 * Public Functions
 ************************************************************************/

float y0f(float x)
{
	float z;
	float u;
	float v;
	uint32_t ix;

	GET_FLOAT_WORD(ix, x);
	if ((ix & 0x7fffffff) == 0) {
		return -1 / 0.0f;
	}
	if (ix >> 31) {
		return 0 / 0.0f;
	}
	if (ix >= 0x7f800000) {
		return 1 / x;
	}
	if (ix >= 0x40000000) {		/* |x| >= 2.0 */
		/* large ulp error near zeros */
		return common(ix, x, 1);
	}
	if (ix >= 0x39000000) {		/* x >= 2**-13 */
		/* large ulp error at x ~= 0.89 */
		z = x * x;
		u = u00 + z * (u01 + z * (u02 + z * (u03 + z * (u04 + z * (u05 + z * u06)))));
		v = 1 + z * (v01 + z * (v02 + z * (v03 + z * v04)));
		return u / v + tpi * (j0f(x) * logf(x));
	}
	return u00 + tpi * logf(x);
}

/************************************************************************
 * Private Data
 ************************************************************************/

/****************************************************************************
 * The asymptotic expansions of pzero is
 *      1 - 9/128 s^2 + 11025/98304 s^4 - ...,  where s = 1/x.
 * For x >= 2, We approximate pzero by
 *      pzero(x) = 1 + (R/S)
 * where  R = pR0 + pR1*s^2 + pR2*s^4 + ... + pR5*s^10
 *        S = 1 + pS0*s^2 + ... + pS4*s^10
 * and
 *      | pzero(x)-1-R/S | <= 2  ** ( -60.26)
 ***************************************************************************/

static const float pR8[6] = {	/* for x in [inf, 8]=1/[0,0.125] */
	0.0000000000e+00,			/* 0x00000000 */
	-7.0312500000e-02,			/* 0xbd900000 */
	-8.0816707611e+00,			/* 0xc1014e86 */
	-2.5706311035e+02,			/* 0xc3808814 */
	-2.4852163086e+03,			/* 0xc51b5376 */
	-5.2530439453e+03,			/* 0xc5a4285a */
};

static const float pS8[5] = {
	1.1653436279e+02,			/* 0x42e91198 */
	3.8337448730e+03,			/* 0x456f9beb */
	4.0597855469e+04,			/* 0x471e95db */
	1.1675296875e+05,			/* 0x47e4087c */
	4.7627726562e+04,			/* 0x473a0bba */
};

static const float pR5[6] = {	/* for x in [8,4.5454]=1/[0.125,0.22001] */
	-1.1412546255e-11,			/* 0xad48c58a */
	-7.0312492549e-02,			/* 0xbd8fffff */
	-4.1596107483e+00,			/* 0xc0851b88 */
	-6.7674766541e+01,			/* 0xc287597b */
	-3.3123129272e+02,			/* 0xc3a59d9b */
	-3.4643338013e+02,			/* 0xc3ad3779 */
};

static const float pS5[5] = {
	6.0753936768e+01,			/* 0x42730408 */
	1.0512523193e+03,			/* 0x44836813 */
	5.9789707031e+03,			/* 0x45bad7c4 */
	9.6254453125e+03,			/* 0x461665c8 */
	2.4060581055e+03,			/* 0x451660ee */
};

static const float pR3[6] = {	/* for x in [4.547,2.8571]=1/[0.2199,0.35001] */
	-2.5470459075e-09,			/* 0xb12f081b */
	-7.0311963558e-02,			/* 0xbd8fffb8 */
	-2.4090321064e+00,			/* 0xc01a2d95 */
	-2.1965976715e+01,			/* 0xc1afba52 */
	-5.8079170227e+01,			/* 0xc2685112 */
	-3.1447946548e+01,			/* 0xc1fb9565 */
};

static const float pS3[5] = {
	3.5856033325e+01,			/* 0x420f6c94 */
	3.6151397705e+02,			/* 0x43b4c1ca */
	1.1936077881e+03,			/* 0x44953373 */
	1.1279968262e+03,			/* 0x448cffe6 */
	1.7358093262e+02,			/* 0x432d94b8 */
};

static const float pR2[6] = {	/* for x in [2.8570,2]=1/[0.3499,0.5] */
	-8.8753431271e-08,			/* 0xb3be98b7 */
	-7.0303097367e-02,			/* 0xbd8ffb12 */
	-1.4507384300e+00,			/* 0xbfb9b1cc */
	-7.6356959343e+00,			/* 0xc0f4579f */
	-1.1193166733e+01,			/* 0xc1331736 */
	-3.2336456776e+00,			/* 0xc04ef40d */
};

static const float pS2[5] = {
	2.2220300674e+01,			/* 0x41b1c32d */
	1.3620678711e+02,			/* 0x430834f0 */
	2.7047027588e+02,			/* 0x43873c32 */
	1.5387539673e+02,			/* 0x4319e01a */
	1.4657617569e+01,			/* 0x416a859a */
};

/************************************************************************
 * Private Function
 ************************************************************************/

static float pzerof(float x)
{
	const float *p;
	const float *q;
	float z;
	float r;
	float s;
	uint32_t ix;

	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41000000) {
		p = pR8;
		q = pS8;
	} else if (ix >= 0x40f71c58) {
		p = pR5;
		q = pS5;
	} else if (ix >= 0x4036db68) {
		p = pR3;
		q = pS3;
	} else {					/*ix >= 0x40000000 */
		p = pR2;
		q = pS2;
	}
	z = 1.0f / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0f + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
	return 1.0f + r / s;
}

/************************************************************************
 * Private Data
 ************************************************************************/

/****************************************************************************
 * For x >= 8, the asymptotic expansions of qzero is
 *      -1/8 s + 75/1024 s^3 - ..., where s = 1/x.
 * We approximate pzero by
 *      qzero(x) = s*(-1.25 + (R/S))
 * where  R = qR0 + qR1*s^2 + qR2*s^4 + ... + qR5*s^10
 *        S = 1 + qS0*s^2 + ... + qS5*s^12
 * and
 *      | qzero(x)/s +1.25-R/S | <= 2  ** ( -61.22)
 ***************************************************************************/

static const float qR8[6] = {	/* for x in [inf, 8]=1/[0,0.125] */
	0.0000000000e+00,			/* 0x00000000 */
	7.3242187500e-02,			/* 0x3d960000 */
	1.1768206596e+01,			/* 0x413c4a93 */
	5.5767340088e+02,			/* 0x440b6b19 */
	8.8591972656e+03,			/* 0x460a6cca */
	3.7014625000e+04,			/* 0x471096a0 */
};

static const float qS8[6] = {
	1.6377603149e+02,			/* 0x4323c6aa */
	8.0983447266e+03,			/* 0x45fd12c2 */
	1.4253829688e+05,			/* 0x480b3293 */
	8.0330925000e+05,			/* 0x49441ed4 */
	8.4050156250e+05,			/* 0x494d3359 */
	-3.4389928125e+05,			/* 0xc8a7eb69 */
};

static const float qR5[6] = {	/* for x in [8,4.5454]=1/[0.125,0.22001] */
	1.8408595828e-11,			/* 0x2da1ec79 */
	7.3242180049e-02,			/* 0x3d95ffff */
	5.8356351852e+00,			/* 0x40babd86 */
	1.3511157227e+02,			/* 0x43071c90 */
	1.0272437744e+03,			/* 0x448067cd */
	1.9899779053e+03,			/* 0x44f8bf4b */
};

static const float qS5[6] = {
	8.2776611328e+01,			/* 0x42a58da0 */
	2.0778142090e+03,			/* 0x4501dd07 */
	1.8847289062e+04,			/* 0x46933e94 */
	5.6751113281e+04,			/* 0x475daf1d */
	3.5976753906e+04,			/* 0x470c88c1 */
	-5.3543427734e+03,			/* 0xc5a752be */
};

static const float qR3[6] = {	/* for x in [4.547,2.8571]=1/[0.2199,0.35001] */
	4.3774099900e-09,			/* 0x3196681b */
	7.3241114616e-02,			/* 0x3d95ff70 */
	3.3442313671e+00,			/* 0x405607e3 */
	4.2621845245e+01,			/* 0x422a7cc5 */
	1.7080809021e+02,			/* 0x432acedf */
	1.6673394775e+02,			/* 0x4326bbe4 */
};

static const float qS3[6] = {
	4.8758872986e+01,			/* 0x42430916 */
	7.0968920898e+02,			/* 0x44316c1c */
	3.7041481934e+03,			/* 0x4567825f */
	6.4604252930e+03,			/* 0x45c9e367 */
	2.5163337402e+03,			/* 0x451d4557 */
	-1.4924745178e+02,			/* 0xc3153f59 */
};

static const float qR2[6] = {	/* for x in [2.8570,2]=1/[0.3499,0.5] */
	1.5044444979e-07,			/* 0x342189db */
	7.3223426938e-02,			/* 0x3d95f62a */
	1.9981917143e+00,			/* 0x3fffc4bf */
	1.4495602608e+01,			/* 0x4167edfd */
	3.1666231155e+01,			/* 0x41fd5471 */
	1.6252708435e+01,			/* 0x4182058c */
};

static const float qS2[6] = {
	3.0365585327e+01,			/* 0x41f2ecb8 */
	2.6934811401e+02,			/* 0x4386ac8f */
	8.4478375244e+02,			/* 0x44533229 */
	8.8293585205e+02,			/* 0x445cbbe5 */
	2.1266638184e+02,			/* 0x4354aa98 */
	-5.3109550476e+00,			/* 0xc0a9f358 */
};

/************************************************************************
 * Private Function
 ************************************************************************/

static float qzerof(float x)
{
	const float *p;
	const float *q;
	float z;
	float r;
	float s;
	uint32_t ix;

	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41000000) {
		p = qR8;
		q = qS8;
	} else if (ix >= 0x40f71c58) {
		p = qR5;
		q = qS5;
	} else if (ix >= 0x4036db68) {
		p = qR3;
		q = qS3;
	} else {					/*ix >= 0x40000000 */
		p = qR2;
		q = qS2;
	}
	z = 1.0f / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0f + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
	return (-.125f + r / s) / x;
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
 * origin: FreeBSD /usr/src/lib/msun/src/e_j1.c
 *
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 * j1(x), y1(x)
 * Bessel function of the first and second kinds of order zero.
 * Method -- j1(x):
 *      1. For tiny x, we use j1(x) = x/2 - x^3/16 + x^5/384 - ...
 *      2. Reduce x to |x| since j1(x)=-j1(-x),  and
 *         for x in (0,2)
 *              j1(x) = x/2 + x*z*R0/S0,  where z = x*x;
 *         (precision:  |j1/x - 1/2 - R0/S0 |<2**-61.51 )
 *         for x in (2,inf)
 *              j1(x) = sqrt(2/(pi*x))*(p1(x)*cos(x1)-q1(x)*sin(x1))
 *              y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x1)+q1(x)*cos(x1))
 *         where x1 = x-3*pi/4. It is better to compute sin(x1),cos(x1)
 *         as follow:
 *              cos(x1) =  cos(x)cos(3pi/4)+sin(x)sin(3pi/4)
 *                      =  1/sqrt(2) * (sin(x) - cos(x))
 *              sin(x1) =  sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
 *                      = -1/sqrt(2) * (sin(x) + cos(x))
 *         (To avoid cancellation, use
 *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
 *          to compute the worse one.)
 *
 *      3 Special cases
 *              j1(nan)= nan
 *              j1(0) = 0
 *              j1(inf) = 0
 *
 * Method -- y1(x):
 *      1. screen out x<=0 cases: y1(0)=-inf, y1(x<0)=NaN
 *      2. For x<2.
 *         Since
 *              y1(x) = 2/pi*(j1(x)*(ln(x/2)+Euler)-1/x-x/2+5/64*x^3-...)
 *         therefore y1(x)-2/pi*j1(x)*ln(x)-1/x is an odd function.
 *         We use the following function to approximate y1,
 *              y1(x) = x*U(z)/V(z) + (2/pi)*(j1(x)*ln(x)-1/x), z= x^2
 *         where for x in [0,2] (abs err less than 2**-65.89)
 *              U(z) = U0[0] + U0[1]*z + ... + U0[4]*z^4
 *              V(z) = 1  + v0[0]*z + ... + v0[4]*z^5
 *         Note: For tiny x, 1/x dominate y1 and hence
 *              y1(tiny) = -2/pi/tiny, (choose tiny<2**-54)
 *      3. For x>=2.
 *              y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x1)+q1(x)*cos(x1))
 *         where x1 = x-3*pi/4. It is better to compute sin(x1),cos(x1)
 *         by method mentioned above.
 ***************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>
#include <sys/types.h>

#include "libm.h"

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Private Data
 ************************************************************************/
static double pone(double);
static double qone(double);

static const double invsqrtpi = 5.64189583547756279280e-01;	/* 0x3FE20DD7, 0x50429B6D */
static const double	tpi = 6.36619772367581382433e-01;	/* 0x3FE45F30, 0x6DC9C883 */

/************************************************************************
 * Private Function
 ************************************************************************/

static double common(uint32_t ix, double x, int y1, int sign)
{
	double z;
	double s;
	double c;
	double ss;
	double cc;

	/*
	 * j1(x) = sqrt(2/(pi*x))*(p1(x)*cos(x-3pi/4)-q1(x)*sin(x-3pi/4))
	 * y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x-3pi/4)+q1(x)*cos(x-3pi/4))
	 *
	 * sin(x-3pi/4) = -(sin(x) + cos(x))/sqrt(2)
	 * cos(x-3pi/4) = (sin(x) - cos(x))/sqrt(2)
	 * sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
	 */
	s = sin(x);
	if (y1) {
		s = -s;
	}
	c = cos(x);
	cc = s - c;
	if (ix < 0x7fe00000) {
		/* avoid overflow in 2*x */
		ss = -s - c;
		z = cos(2 * x);
		if (s * c > 0) {
			cc = z / ss;
		} else {
			ss = z / cc;
		}
		if (ix < 0x48000000) {
			if (y1) {
				ss = -ss;
			}
			cc = pone(x) * cc - qone(x) * ss;
		}
	}
	if (sign) {
		cc = -cc;
	}
	return invsqrtpi * cc / sqrt(x);
}

/************************************************************************
 * Private Data
 ************************************************************************/

/* R0/S0 on [0,2] */
static const double r00 = -6.25000000000000000000e-02;	/* 0xBFB00000, 0x00000000 */
static const double r01 = 1.40705666955189706048e-03;	/* 0x3F570D9F, 0x98472C61 */
static const double r02 = -1.59955631084035597520e-05;	/* 0xBEF0C5C6, 0xBA169668 */
static const double r03 = 4.96727999609584448412e-08;	/* 0x3E6AAAFA, 0x46CA0BD9 */
static const double s01 = 1.91537599538363460805e-02;	/* 0x3F939D0B, 0x12637E53 */
static const double s02 = 1.85946785588630915560e-04;	/* 0x3F285F56, 0xB9CDF664 */
static const double s03 = 1.17718464042623683263e-06;	/* 0x3EB3BFF8, 0x333F8498 */
static const double s04 = 5.04636257076217042715e-09;	/* 0x3E35AC88, 0xC97DFF2C */
static const double s05 = 1.23542274426137913908e-11;	/* 0x3DAB2ACF, 0xCFB97ED8 */

/************************************************************************
 * Public Function
 ************************************************************************/

double j1(double x)
{
	double z;
	double r;
	double s;
	uint32_t ix;
	int sign;

	GET_HIGH_WORD(ix, x);
	sign = ix >> 31;
	ix &= 0x7fffffff;
	if (ix >= 0x7ff00000) {
		return 1 / (x * x);
	}
	if (ix >= 0x40000000) {		/* |x| >= 2 */
		return common(ix, fabs(x), 0, sign);
	}
	if (ix >= 0x38000000) {		/* |x| >= 2**-127 */
		z = x * x;
		r = z * (r00 + z * (r01 + z * (r02 + z * r03)));
		s = 1 + z * (s01 + z * (s02 + z * (s03 + z * (s04 + z * s05))));
		z = r / s;
	} else
		/* avoid underflow, raise inexact if x!=0 */
	{
		z = x;
	}
	return (0.5 + z) * x;
}

/************************************************************************
 * Private Data
 ************************************************************************/

static const double U0[5] = {
	-1.96057090646238940668e-01,	/* 0xBFC91866, 0x143CBC8A */
	5.04438716639811282616e-02,	/* 0x3FA9D3C7, 0x76292CD1 */
	-1.91256895875763547298e-03,	/* 0xBF5F55E5, 0x4844F50F */
	2.35252600561610495928e-05,	/* 0x3EF8AB03, 0x8FA6B88E */
	-9.19099158039878874504e-08,	/* 0xBE78AC00, 0x569105B8 */
};

static const double V0[5] = {
	1.99167318236649903973e-02,	/* 0x3F94650D, 0x3F4DA9F0 */
	2.02552581025135171496e-04,	/* 0x3F2A8C89, 0x6C257764 */
	1.35608801097516229404e-06,	/* 0x3EB6C05A, 0x894E8CA6 */
	6.22741452364621501295e-09,	/* 0x3E3ABF1D, 0x5BA69A86 */
	1.66559246207992079114e-11,	/* 0x3DB25039, 0xDACA772A */
};

/************************************************************************
 * Public Function
 ************************************************************************/

double y1(double x)
{
	double z;
	double u;
	double v;
	uint32_t ix;
	uint32_t lx;

	EXTRACT_WORDS(ix, lx, x);
	/* y1(nan)=nan, y1(<0)=nan, y1(0)=-inf, y1(inf)=0 */
	if ((ix << 1 | lx) == 0) {
		return -1 / 0.0;
	}
	if (ix >> 31) {
		return 0 / 0.0;
	}
	if (ix >= 0x7ff00000) {
		return 1 / x;
	}

	if (ix >= 0x40000000) {		/* x >= 2 */
		return common(ix, x, 1, 0);
	}
	if (ix < 0x3c900000) {		/* x < 2**-54 */
		return -tpi / x;
	}
	z = x * x;
	u = U0[0] + z * (U0[1] + z * (U0[2] + z * (U0[3] + z * U0[4])));
	v = 1 + z * (V0[0] + z * (V0[1] + z * (V0[2] + z * (V0[3] + z * V0[4]))));
	return x * (u / v) + tpi * (j1(x) * log(x) - 1 / x);
}

/************************************************************************
 * Private Data
 ************************************************************************/

/* For x >= 8, the asymptotic expansions of pone is
 *      1 + 15/128 s^2 - 4725/2^15 s^4 - ...,   where s = 1/x.
 * We approximate pone by
 *      pone(x) = 1 + (R/S)
 * where  R = pr0 + pr1*s^2 + pr2*s^4 + ... + pr5*s^10
 *        S = 1 + ps0*s^2 + ... + ps4*s^10
 * and
 *      | pone(x)-1-R/S | <= 2  ** ( -60.06)
 */

static const double pr8[6] = {	/* for x in [inf, 8]=1/[0,0.125] */
	0.00000000000000000000e+00,	/* 0x00000000, 0x00000000 */
	1.17187499999988647970e-01,	/* 0x3FBDFFFF, 0xFFFFFCCE */
	1.32394806593073575129e+01,	/* 0x402A7A9D, 0x357F7FCE */
	4.12051854307378562225e+02,	/* 0x4079C0D4, 0x652EA590 */
	3.87474538913960532227e+03,	/* 0x40AE457D, 0xA3A532CC */
	7.91447954031891731574e+03,	/* 0x40BEEA7A, 0xC32782DD */
};

static const double ps8[5] = {
	1.14207370375678408436e+02,	/* 0x405C8D45, 0x8E656CAC */
	3.65093083420853463394e+03,	/* 0x40AC85DC, 0x964D274F */
	3.69562060269033463555e+04,	/* 0x40E20B86, 0x97C5BB7F */
	9.76027935934950801311e+04,	/* 0x40F7D42C, 0xB28F17BB */
	3.08042720627888811578e+04,	/* 0x40DE1511, 0x697A0B2D */
};

static const double pr5[6] = {	/* for x in [8,4.5454]=1/[0.125,0.22001] */
	1.31990519556243522749e-11,	/* 0x3DAD0667, 0xDAE1CA7D */
	1.17187493190614097638e-01,	/* 0x3FBDFFFF, 0xE2C10043 */
	6.80275127868432871736e+00,	/* 0x401B3604, 0x6E6315E3 */
	1.08308182990189109773e+02,	/* 0x405B13B9, 0x452602ED */
	5.17636139533199752805e+02,	/* 0x40802D16, 0xD052D649 */
	5.28715201363337541807e+02,	/* 0x408085B8, 0xBB7E0CB7 */
};

static const double ps5[5] = {
	5.92805987221131331921e+01,	/* 0x404DA3EA, 0xA8AF633D */
	9.91401418733614377743e+02,	/* 0x408EFB36, 0x1B066701 */
	5.35326695291487976647e+03,	/* 0x40B4E944, 0x5706B6FB */
	7.84469031749551231769e+03,	/* 0x40BEA4B0, 0xB8A5BB15 */
	1.50404688810361062679e+03,	/* 0x40978030, 0x036F5E51 */
};

static const double pr3[6] = {
	3.02503916137373618024e-09,	/* 0x3E29FC21, 0xA7AD9EDD */
	1.17186865567253592491e-01,	/* 0x3FBDFFF5, 0x5B21D17B */
	3.93297750033315640650e+00,	/* 0x400F76BC, 0xE85EAD8A */
	3.51194035591636932736e+01,	/* 0x40418F48, 0x9DA6D129 */
	9.10550110750781271918e+01,	/* 0x4056C385, 0x4D2C1837 */
	4.85590685197364919645e+01,	/* 0x4048478F, 0x8EA83EE5 */
};

static const double ps3[5] = {
	3.47913095001251519989e+01,	/* 0x40416549, 0xA134069C */
	3.36762458747825746741e+02,	/* 0x40750C33, 0x07F1A75F */
	1.04687139975775130551e+03,	/* 0x40905B7C, 0x5037D523 */
	8.90811346398256432622e+02,	/* 0x408BD67D, 0xA32E31E9 */
	1.03787932439639277504e+02,	/* 0x4059F26D, 0x7C2EED53 */
};

static const double pr2[6] = {	/* for x in [2.8570,2]=1/[0.3499,0.5] */
	1.07710830106873743082e-07,	/* 0x3E7CE9D4, 0xF65544F4 */
	1.17176219462683348094e-01,	/* 0x3FBDFF42, 0xBE760D83 */
	2.36851496667608785174e+00,	/* 0x4002F2B7, 0xF98FAEC0 */
	1.22426109148261232917e+01,	/* 0x40287C37, 0x7F71A964 */
	1.76939711271687727390e+01,	/* 0x4031B1A8, 0x177F8EE2 */
	5.07352312588818499250e+00,	/* 0x40144B49, 0xA574C1FE */
};

static const double ps2[5] = {
	2.14364859363821409488e+01,	/* 0x40356FBD, 0x8AD5ECDC */
	1.25290227168402751090e+02,	/* 0x405F5293, 0x14F92CD5 */
	2.32276469057162813669e+02,	/* 0x406D08D8, 0xD5A2DBD9 */
	1.17679373287147100768e+02,	/* 0x405D6B7A, 0xDA1884A9 */
	8.36463893371618283368e+00,	/* 0x4020BAB1, 0xF44E5192 */
};

/************************************************************************
 * Private Function
 ************************************************************************/

static double pone(double x)
{
	const double *p;
	const double *q;
	double_t z;
	double_t r;
	double_t s;
	uint32_t ix;

	GET_HIGH_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x40200000) {
		p = pr8;
		q = ps8;
	} else if (ix >= 0x40122E8B) {
		p = pr5;
		q = ps5;
	} else if (ix >= 0x4006DB6D) {
		p = pr3;
		q = ps3;
	} else {					/*ix >= 0x40000000 */
		p = pr2;
		q = ps2;
	}
	z = 1.0 / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0 + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
	return 1.0 + r / s;
}

/************************************************************************
 * Private Data
 ************************************************************************/

/* For x >= 8, the asymptotic expansions of qone is
 *      3/8 s - 105/1024 s^3 - ..., where s = 1/x.
 * We approximate pone by
 *      qone(x) = s*(0.375 + (R/S))
 * where  R = qr1*s^2 + qr2*s^4 + ... + qr5*s^10
 *        S = 1 + qs1*s^2 + ... + qs6*s^12
 * and
 *      | qone(x)/s -0.375-R/S | <= 2  ** ( -61.13)
 */

static const double qr8[6] = {	/* for x in [inf, 8]=1/[0,0.125] */
	0.00000000000000000000e+00,	/* 0x00000000, 0x00000000 */
	-1.02539062499992714161e-01,	/* 0xBFBA3FFF, 0xFFFFFDF3 */
	-1.62717534544589987888e+01,	/* 0xC0304591, 0xA26779F7 */
	-7.59601722513950107896e+02,	/* 0xC087BCD0, 0x53E4B576 */
	-1.18498066702429587167e+04,	/* 0xC0C724E7, 0x40F87415 */
	-4.84385124285750353010e+04,	/* 0xC0E7A6D0, 0x65D09C6A */
};

static const double qs8[6] = {
	1.61395369700722909556e+02,	/* 0x40642CA6, 0xDE5BCDE5 */
	7.82538599923348465381e+03,	/* 0x40BE9162, 0xD0D88419 */
	1.33875336287249578163e+05,	/* 0x4100579A, 0xB0B75E98 */
	7.19657723683240939863e+05,	/* 0x4125F653, 0x72869C19 */
	6.66601232617776375264e+05,	/* 0x412457D2, 0x7719AD5C */
	-2.94490264303834643215e+05,	/* 0xC111F969, 0x0EA5AA18 */
};

static const double qr5[6] = {	/* for x in [8,4.5454]=1/[0.125,0.22001] */
	-2.08979931141764104297e-11,	/* 0xBDB6FA43, 0x1AA1A098 */
	-1.02539050241375426231e-01,	/* 0xBFBA3FFF, 0xCB597FEF */
	-8.05644828123936029840e+00,	/* 0xC0201CE6, 0xCA03AD4B */
	-1.83669607474888380239e+02,	/* 0xC066F56D, 0x6CA7B9B0 */
	-1.37319376065508163265e+03,	/* 0xC09574C6, 0x6931734F */
	-2.61244440453215656817e+03,	/* 0xC0A468E3, 0x88FDA79D */
};

static const double qs5[6] = {
	8.12765501384335777857e+01,	/* 0x405451B2, 0xFF5A11B2 */
	1.99179873460485964642e+03,	/* 0x409F1F31, 0xE77BF839 */
	1.74684851924908907677e+04,	/* 0x40D10F1F, 0x0D64CE29 */
	4.98514270910352279316e+04,	/* 0x40E8576D, 0xAABAD197 */
	2.79480751638918118260e+04,	/* 0x40DB4B04, 0xCF7C364B */
	-4.71918354795128470869e+03,	/* 0xC0B26F2E, 0xFCFFA004 */
};

static const double qr3[6] = {
	-5.07831226461766561369e-09,	/* 0xBE35CFA9, 0xD38FC84F */
	-1.02537829820837089745e-01,	/* 0xBFBA3FEB, 0x51AEED54 */
	-4.61011581139473403113e+00,	/* 0xC01270C2, 0x3302D9FF */
	-5.78472216562783643212e+01,	/* 0xC04CEC71, 0xC25D16DA */
	-2.28244540737631695038e+02,	/* 0xC06C87D3, 0x4718D55F */
	-2.19210128478909325622e+02,	/* 0xC06B66B9, 0x5F5C1BF6 */
};

static const double qs3[6] = {
	4.76651550323729509273e+01,	/* 0x4047D523, 0xCCD367E4 */
	6.73865112676699709482e+02,	/* 0x40850EEB, 0xC031EE3E */
	3.38015286679526343505e+03,	/* 0x40AA684E, 0x448E7C9A */
	5.54772909720722782367e+03,	/* 0x40B5ABBA, 0xA61D54A6 */
	1.90311919338810798763e+03,	/* 0x409DBC7A, 0x0DD4DF4B */
	-1.35201191444307340817e+02,	/* 0xC060E670, 0x290A311F */
};

static const double qr2[6] = {	/* for x in [2.8570,2]=1/[0.3499,0.5] */
	-1.78381727510958865572e-07,	/* 0xBE87F126, 0x44C626D2 */
	-1.02517042607985553460e-01,	/* 0xBFBA3E8E, 0x9148B010 */
	-2.75220568278187460720e+00,	/* 0xC0060484, 0x69BB4EDA */
	-1.96636162643703720221e+01,	/* 0xC033A9E2, 0xC168907F */
	-4.23253133372830490089e+01,	/* 0xC04529A3, 0xDE104AAA */
	-2.13719211703704061733e+01,	/* 0xC0355F36, 0x39CF6E52 */
};

static const double qs2[6] = {
	2.95333629060523854548e+01,	/* 0x403D888A, 0x78AE64FF */
	2.52981549982190529136e+02,	/* 0x406F9F68, 0xDB821CBA */
	7.57502834868645436472e+02,	/* 0x4087AC05, 0xCE49A0F7 */
	7.39393205320467245656e+02,	/* 0x40871B25, 0x48D4C029 */
	1.55949003336666123687e+02,	/* 0x40637E5E, 0x3C3ED8D4 */
	-4.95949898822628210127e+00,	/* 0xC013D686, 0xE71BE86B */
};

/************************************************************************
 * Private Function
 ************************************************************************/

static double qone(double x)
{
	const double *p;
	const double *q;
	double_t z;
	double_t r;
	double_t s;
	uint32_t ix;

	GET_HIGH_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x40200000) {
		p = qr8;
		q = qs8;
	} else if (ix >= 0x40122E8B) {
		p = qr5;
		q = qs5;
	} else if (ix >= 0x4006DB6D) {
		p = qr3;
		q = qs3;
	} else {					/*ix >= 0x40000000 */
		p = qr2;
		q = qs2;
	}
	z = 1.0 / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0 + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
	return (.375 + r / s) / x;
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
/* origin: FreeBSD /usr/src/lib/msun/src/e_j1f.c */
/*
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

#include "libm.h"

/************************************************************************
 * Private Data
 ************************************************************************/

static float ponef(float);
static float qonef(float);

static const float invsqrtpi = 5.6418961287e-01;	/* 0x3f106ebb */
static const float tpi = 6.3661974669e-01;		/* 0x3f22f983 */

/************************************************************************
 * Private Functions
 ************************************************************************/

static float common(uint32_t ix, float x, int y1, int sign)
{
	float z;
	float s;
	float c;
	float ss;
	float cc;

	s = sinf(x);
	if (y1) {
		s = -s;
	}
	c = cosf(x);
	cc = s - c;
	if (ix < 0x7f000000) {
		ss = -s - c;
		z = cosf(2 * x);
		if (s * c > 0) {
			cc = z / ss;
		} else {
			ss = z / cc;
		}
		if (ix < 0x58800000) {
			if (y1) {
				ss = -ss;
			}
			cc = ponef(x) * cc - qonef(x) * ss;
		}
	}
	if (sign) {
		cc = -cc;
	}
	return invsqrtpi * cc / sqrtf(x);
}

/************************************************************************
 * Private Data
 ************************************************************************/

/* R0/S0 on [0,2] */
static const float r00 = -6.2500000000e-02;	/* 0xbd800000 */
static const float r01 = 1.4070566976e-03;		/* 0x3ab86cfd */
static const float r02 = -1.5995563444e-05;	/* 0xb7862e36 */
static const float r03 = 4.9672799207e-08;		/* 0x335557d2 */
static const float s01 = 1.9153760746e-02;		/* 0x3c9ce859 */
static const float s02 = 1.8594678841e-04;		/* 0x3942fab6 */
static const float s03 = 1.1771846857e-06;		/* 0x359dffc2 */
static const float s04 = 5.0463624390e-09;		/* 0x31ad6446 */
static const float s05 = 1.2354227016e-11;		/* 0x2d59567e */

/************************************************************************
 * Public Functions
 ************************************************************************/

float j1f(float x)
{
	float z;
	float r;
	float s;
	uint32_t ix;
	int sign;

	GET_FLOAT_WORD(ix, x);
	sign = ix >> 31;
	ix &= 0x7fffffff;
	if (ix >= 0x7f800000) {
		return 1 / (x * x);
	}
	if (ix >= 0x40000000) {		/* |x| >= 2 */
		return common(ix, fabsf(x), 0, sign);
	}
	if (ix >= 0x32000000) {		/* |x| >= 2**-27 */
		z = x * x;
		r = z * (r00 + z * (r01 + z * (r02 + z * r03)));
		s = 1 + z * (s01 + z * (s02 + z * (s03 + z * (s04 + z * s05))));
		z = 0.5f + r / s;
	} else
		/* raise inexact if x!=0 */
	{
		z = 0.5f + x;
	}
	return z * x;
}

/************************************************************************
 * Private Data
 ************************************************************************/

static const float U0[5] = {
	-1.9605709612e-01,			/* 0xbe48c331 */
	5.0443872809e-02,			/* 0x3d4e9e3c */
	-1.9125689287e-03,			/* 0xbafaaf2a */
	2.3525259166e-05,			/* 0x37c5581c */
	-9.1909917899e-08,			/* 0xb3c56003 */
};

static const float V0[5] = {
	1.9916731864e-02,			/* 0x3ca3286a */
	2.0255257550e-04,			/* 0x3954644b */
	1.3560879779e-06,			/* 0x35b602d4 */
	6.2274145840e-09,			/* 0x31d5f8eb */
	1.6655924903e-11,			/* 0x2d9281cf */
};

/************************************************************************
 * Public Function
 ************************************************************************/

float y1f(float x)
{
	float z;
	float u;
	float v;
	uint32_t ix;

	GET_FLOAT_WORD(ix, x);
	if ((ix & 0x7fffffff) == 0) {
		return -1 / 0.0f;
	}
	if (ix >> 31) {
		return 0 / 0.0f;
	}
	if (ix >= 0x7f800000) {
		return 1 / x;
	}
	if (ix >= 0x40000000) {		/* |x| >= 2.0 */
		return common(ix, x, 1, 0);
	}
	if (ix < 0x32000000) {		/* x < 2**-27 */
		return -tpi / x;
	}
	z = x * x;
	u = U0[0] + z * (U0[1] + z * (U0[2] + z * (U0[3] + z * U0[4])));
	v = 1.0f + z * (V0[0] + z * (V0[1] + z * (V0[2] + z * (V0[3] + z * V0[4]))));
	return x * (u / v) + tpi * (j1f(x) * logf(x) - 1.0f / x);
}

/************************************************************************
 * Private Data
 ************************************************************************/

/****************************************************************************
 * For x >= 8, the asymptotic expansions of pone is
 *      1 + 15/128 s^2 - 4725/2^15 s^4 - ...,   where s = 1/x.
 * We approximate pone by
 *      pone(x) = 1 + (R/S)
 * where  R = pr0 + pr1*s^2 + pr2*s^4 + ... + pr5*s^10
 *        S = 1 + ps0*s^2 + ... + ps4*s^10
 * and
 *      | pone(x)-1-R/S | <= 2  ** ( -60.06)
 ***************************************************************************/

static const float pr8[6] = {	/* for x in [inf, 8]=1/[0,0.125] */
	0.0000000000e+00,			/* 0x00000000 */
	1.1718750000e-01,			/* 0x3df00000 */
	1.3239480972e+01,			/* 0x4153d4ea */
	4.1205184937e+02,			/* 0x43ce06a3 */
	3.8747453613e+03,			/* 0x45722bed */
	7.9144794922e+03,			/* 0x45f753d6 */
};

static const float ps8[5] = {
	1.1420736694e+02,			/* 0x42e46a2c */
	3.6509309082e+03,			/* 0x45642ee5 */
	3.6956207031e+04,			/* 0x47105c35 */
	9.7602796875e+04,			/* 0x47bea166 */
	3.0804271484e+04,			/* 0x46f0a88b */
};

static const float pr5[6] = {	/* for x in [8,4.5454]=1/[0.125,0.22001] */
	1.3199052094e-11,			/* 0x2d68333f */
	1.1718749255e-01,			/* 0x3defffff */
	6.8027510643e+00,			/* 0x40d9b023 */
	1.0830818176e+02,			/* 0x42d89dca */
	5.1763616943e+02,			/* 0x440168b7 */
	5.2871520996e+02,			/* 0x44042dc6 */
};

static const float ps5[5] = {
	5.9280597687e+01,			/* 0x426d1f55 */
	9.9140142822e+02,			/* 0x4477d9b1 */
	5.3532670898e+03,			/* 0x45a74a23 */
	7.8446904297e+03,			/* 0x45f52586 */
	1.5040468750e+03,			/* 0x44bc0180 */
};

static const float pr3[6] = {
	3.0250391081e-09,			/* 0x314fe10d */
	1.1718686670e-01,			/* 0x3defffab */
	3.9329774380e+00,			/* 0x407bb5e7 */
	3.5119403839e+01,			/* 0x420c7a45 */
	9.1055007935e+01,			/* 0x42b61c2a */
	4.8559066772e+01,			/* 0x42423c7c */
};

static const float ps3[5] = {
	3.4791309357e+01,			/* 0x420b2a4d */
	3.3676245117e+02,			/* 0x43a86198 */
	1.0468714600e+03,			/* 0x4482dbe3 */
	8.9081134033e+02,			/* 0x445eb3ed */
	1.0378793335e+02,			/* 0x42cf936c */
};

static const float pr2[6] = {	/* for x in [2.8570,2]=1/[0.3499,0.5] */
	1.0771083225e-07,			/* 0x33e74ea8 */
	1.1717621982e-01,			/* 0x3deffa16 */
	2.3685150146e+00,			/* 0x401795c0 */
	1.2242610931e+01,			/* 0x4143e1bc */
	1.7693971634e+01,			/* 0x418d8d41 */
	5.0735230446e+00,			/* 0x40a25a4d */
};

static const float ps2[5] = {
	2.1436485291e+01,			/* 0x41ab7dec */
	1.2529022980e+02,			/* 0x42fa9499 */
	2.3227647400e+02,			/* 0x436846c7 */
	1.1767937469e+02,			/* 0x42eb5bd7 */
	8.3646392822e+00,			/* 0x4105d590 */
};

/************************************************************************
 * Private Function
 ************************************************************************/

static float ponef(float x)
{
	const float *p;
	const float *q;
	float z;
	float r;
	float s;
	uint32_t ix;

	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41000000) {
		p = pr8;
		q = ps8;
	} else if (ix >= 0x40f71c58) {
		p = pr5;
		q = ps5;
	} else if (ix >= 0x4036db68) {
		p = pr3;
		q = ps3;
	} else {					/*ix >= 0x40000000 */
		p = pr2;
		q = ps2;
	}
	z = 1.0f / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0f + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
	return 1.0f + r / s;
}

/************************************************************************
 * Private Data
 ************************************************************************/

/***************************************************************************
 * For x >= 8, the asymptotic expansions of qone is
 *      3/8 s - 105/1024 s^3 - ..., where s = 1/x.
 * We approximate pone by
 *      qone(x) = s*(0.375 + (R/S))
 * where  R = qr1*s^2 + qr2*s^4 + ... + qr5*s^10
 *        S = 1 + qs1*s^2 + ... + qs6*s^12
 * and
 *      | qone(x)/s -0.375-R/S | <= 2  ** ( -61.13)
 ***************************************************************************/

static const float qr8[6] = {	/* for x in [inf, 8]=1/[0,0.125] */
	0.0000000000e+00,			/* 0x00000000 */
	-1.0253906250e-01,			/* 0xbdd20000 */
	-1.6271753311e+01,			/* 0xc1822c8d */
	-7.5960174561e+02,			/* 0xc43de683 */
	-1.1849806641e+04,			/* 0xc639273a */
	-4.8438511719e+04,			/* 0xc73d3683 */
};

static const float qs8[6] = {
	1.6139537048e+02,			/* 0x43216537 */
	7.8253862305e+03,			/* 0x45f48b17 */
	1.3387534375e+05,			/* 0x4802bcd6 */
	7.1965775000e+05,			/* 0x492fb29c */
	6.6660125000e+05,			/* 0x4922be94 */
	-2.9449025000e+05,			/* 0xc88fcb48 */
};

static const float qr5[6] = {	/* for x in [8,4.5454]=1/[0.125,0.22001] */
	-2.0897993405e-11,			/* 0xadb7d219 */
	-1.0253904760e-01,			/* 0xbdd1fffe */
	-8.0564479828e+00,			/* 0xc100e736 */
	-1.8366960144e+02,			/* 0xc337ab6b */
	-1.3731937256e+03,			/* 0xc4aba633 */
	-2.6124443359e+03,			/* 0xc523471c */
};

static const float qs5[6] = {
	8.1276550293e+01,			/* 0x42a28d98 */
	1.9917987061e+03,			/* 0x44f8f98f */
	1.7468484375e+04,			/* 0x468878f8 */
	4.9851425781e+04,			/* 0x4742bb6d */
	2.7948074219e+04,			/* 0x46da5826 */
	-4.7191835938e+03,			/* 0xc5937978 */
};

static const float qr3[6] = {
	-5.0783124372e-09,			/* 0xb1ae7d4f */
	-1.0253783315e-01,			/* 0xbdd1ff5b */
	-4.6101160049e+00,			/* 0xc0938612 */
	-5.7847221375e+01,			/* 0xc267638e */
	-2.2824453735e+02,			/* 0xc3643e9a */
	-2.1921012878e+02,			/* 0xc35b35cb */
};

static const float qs3[6] = {
	4.7665153503e+01,			/* 0x423ea91e */
	6.7386511230e+02,			/* 0x4428775e */
	3.3801528320e+03,			/* 0x45534272 */
	5.5477290039e+03,			/* 0x45ad5dd5 */
	1.9031191406e+03,			/* 0x44ede3d0 */
	-1.3520118713e+02,			/* 0xc3073381 */
};

static const float qr2[6] = {	/* for x in [2.8570,2]=1/[0.3499,0.5] */
	-1.7838172539e-07,			/* 0xb43f8932 */
	-1.0251704603e-01,			/* 0xbdd1f475 */
	-2.7522056103e+00,			/* 0xc0302423 */
	-1.9663616180e+01,			/* 0xc19d4f16 */
	-4.2325313568e+01,			/* 0xc2294d1f */
	-2.1371921539e+01,			/* 0xc1aaf9b2 */
};

static const float qs2[6] = {
	2.9533363342e+01,			/* 0x41ec4454 */
	2.5298155212e+02,			/* 0x437cfb47 */
	7.5750280762e+02,			/* 0x443d602e */
	7.3939318848e+02,			/* 0x4438d92a */
	1.5594900513e+02,			/* 0x431bf2f2 */
	-4.9594988823e+00,			/* 0xc09eb437 */
};

/************************************************************************
 * Private Function
 ************************************************************************/

static float qonef(float x)
{
	const float *p;
	const float *q;
	float z;
	float r;
	float s;
	uint32_t ix;

	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x40200000) {
		p = qr8;
		q = qs8;
	} else if (ix >= 0x40f71c58) {
		p = qr5;
		q = qs5;
	} else if (ix >= 0x4036db68) {
		p = qr3;
		q = qs3;
	} else {					/*ix >= 0x40000000 */
		p = qr2;
		q = qs2;
	}
	z = 1.0f / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0f + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
	return (.375f + r / s) / x;
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
 * origin: FreeBSD /usr/src/lib/msun/src/e_jn.c
 *
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 *
 * jn(n, x), yn(n, x)
 * floating point Bessel's function of the 1st and 2nd kind
 * of order n
 *
 * Special cases:
 *      y0(0)=y1(0)=yn(n,0) = -inf with division by zero signal;
 *      y0(-ve)=y1(-ve)=yn(n,-ve) are NaN with invalid signal.
 * Note 2. About jn(n,x), yn(n,x)
 *      For n=0, j0(x) is called,
 *      for n=1, j1(x) is called,
 *      for n<=x, forward recursion is used starting
 *      from values of j0(x) and j1(x).
 *      for n>x, a continued fraction approximation to
 *      j(n,x)/j(n-1,x) is evaluated and then backward
 *      recursion is used starting from a supposed value
 *      for j(n,x). The resulting value of j(0,x) is
 *      compared with the actual value to correct the
 *      supposed value of j(n,x).
 *
 *      yn(n,x) is similar in all respects, except
 *      that forward recursion is used for all
 *      values of n>1.
 ***************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>

#include "libm.h"

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Private Data
 ************************************************************************/
static const double invsqrtpi = 5.64189583547756279280e-01;	/* 0x3FE20DD7, 0x50429B6D */

/************************************************************************
 * Public Functions
 ************************************************************************/

double jn(int n, double x)
{
	uint32_t ix;
	uint32_t lx;
	int nm1;
	int sign;
	int i;
	float a;
	float b;
	float temp;

	EXTRACT_WORDS(ix, lx, x);
	sign = ix >> 31;
	ix &= 0x7fffffff;

	if ((ix | (lx | -lx) >> 31) > 0x7ff00000) {	/* nan */
		return x;
	}

	/* J(-n,x) = (-1)^n * J(n, x), J(n, -x) = (-1)^n * J(n, x)
	 * Thus, J(-n,x) = J(n,-x)
	 */
	/* nm1 = |n|-1 is used instead of |n| to handle n==INT_MIN */
	if (n == 0) {
		return j0(x);
	}
	if (n < 0) {
		nm1 = -(n + 1);
		x = -x;
		sign ^= 1;
	} else {
		nm1 = n - 1;
	}
	if (nm1 == 0) {
		return j1(x);
	}

	sign &= n;					/* even n: 0, odd n: signbit(x) */
	x = fabs(x);
	if ((ix | lx) == 0 || ix == 0x7ff00000) {	/* if x is 0 or inf */
		b = 0.0;
	} else if (nm1 < x) {
		/* Safe to use J(n+1,x)=2n/x *J(n,x)-J(n-1,x) */
		if (ix >= 0x52d00000) {	/* x > 2**302 */
			/* (x >> n**2)
			 *      Jn(x) = cos(x-(2n+1)*pi/4)*sqrt(2/x*pi)
			 *      Yn(x) = sin(x-(2n+1)*pi/4)*sqrt(2/x*pi)
			 *      Let s=sin(x), c=cos(x),
			 *          xn=x-(2n+1)*pi/4, sqt2 = sqrt(2),then
			 *
			 *             n    sin(xn)*sqt2    cos(xn)*sqt2
			 *          ----------------------------------
			 *             0     s-c             c+s
			 *             1    -s-c            -c+s
			 *             2    -s+c            -c-s
			 *             3     s+c             c-s
			 */
			switch (nm1 & 3) {
			case 0:
				temp = -cos(x) + sin(x);
				break;
			case 1:
				temp = -cos(x) - sin(x);
				break;
			case 2:
				temp = cos(x) - sin(x);
				break;
			default:
			case 3:
				temp = cos(x) + sin(x);
				break;
			}
			b = invsqrtpi * temp / sqrt(x);
		} else {
			a = j0(x);
			b = j1(x);
			for (i = 0; i < nm1;) {
				i++;
				temp = b;
				b = b * (2.0 * i / x) - a;	/* avoid underflow */
				a = temp;
			}
		}
	} else {
		if (ix < 0x3e100000) {	/* x < 2**-29 */
			/* x is tiny, return the first Taylor expansion of J(n,x)
			 * J(n,x) = 1/n!*(x/2)^n  - ...
			 */
			if (nm1 > 32) {		/* underflow */
				b = 0.0;
			} else {
				temp = x * 0.5;
				b = temp;
				a = 1.0;
				for (i = 2; i <= nm1 + 1; i++) {
					a *= (double)i;	/* a = n! */
					b *= temp;	/* b = (x/2)^n */
				}
				b = b / a;
			}
		} else {
			/* use backward recurrence */
			/*                      x      x^2      x^2
			 *  J(n,x)/J(n-1,x) =  ----   ------   ------   .....
			 *                      2n  - 2(n+1) - 2(n+2)
			 *
			 *                      1      1        1
			 *  (for large x)   =  ----  ------   ------   .....
			 *                      2n   2(n+1)   2(n+2)
			 *                      -- - ------ - ------ -
			 *                       x     x         x
			 *
			 * Let w = 2n/x and h=2/x, then the above quotient
			 * is equal to the continued fraction:
			 *                  1
			 *      = -----------------------
			 *                     1
			 *         w - -----------------
			 *                        1
			 *              w+h - ---------
			 *                     w+2h - ...
			 *
			 * To determine how many terms needed, let
			 * Q(0) = w, Q(1) = w(w+h) - 1,
			 * Q(k) = (w+k*h)*Q(k-1) - Q(k-2),
			 * When Q(k) > 1e4      good for single
			 * When Q(k) > 1e9      good for double
			 * When Q(k) > 1e17     good for quadruple
			 */
			/* determine k */
			double t;
			double q0;
			double q1;
			double w;
			double h;
			double z;
			double tmp;
			double nf;
			int k;

			nf = nm1 + 1.0;
			w = 2 * nf / x;
			h = 2 / x;
			z = w + h;
			q0 = w;
			q1 = w * z - 1.0;
			k = 1;
			while (q1 < 1.0e9) {
				k += 1;
				z += h;
				tmp = z * q1 - q0;
				q0 = q1;
				q1 = tmp;
			}
			for (t = 0.0, i = k; i >= 0; i--) {
				t = 1 / (2 * (i + nf) / x - t);
			}
			a = t;
			b = 1.0;
			/*  estimate log((2/x)^n*n!) = n*log(2/x)+n*ln(n)
			 *  Hence, if n*(log(2n/x)) > ...
			 *  single 8.8722839355e+01
			 *  double 7.09782712893383973096e+02
			 *  long double 1.1356523406294143949491931077970765006170e+04
			 *  then recurrent value may overflow and the result is
			 *  likely underflow to zero
			 */
			tmp = nf * log(fabs(w));
			if (tmp < 7.09782712893383973096e+02) {
				for (i = nm1; i > 0; i--) {
					temp = b;
					b = b * (2.0 * i) / x - a;
					a = temp;
				}
			} else {
				for (i = nm1; i > 0; i--) {
					temp = b;
					b = b * (2.0 * i) / x - a;
					a = temp;
					/* scale b to avoid spurious overflow */
					if (b > 0x1p500) {
						a /= b;
						t /= b;
						b = 1.0;
					}
				}
			}
			z = j0(x);
			w = j1(x);
			if (fabs(z) >= fabs(w)) {
				b = t * z / b;
			} else {
				b = t * w / a;
			}
		}
	}
	return sign ? -b : b;
}

double yn(int n, double x)
{
	uint32_t ix;
	uint32_t lx;
	uint32_t ib;
	int nm1;
	int sign;
	int i;
	float a;
	float b;
	float temp;

	EXTRACT_WORDS(ix, lx, x);
	sign = ix >> 31;
	ix &= 0x7fffffff;

	if ((ix | (lx | -lx) >> 31) > 0x7ff00000) {	/* nan */
		return x;
	}
	if (sign && (ix | lx) != 0) {	/* x < 0 */
		return 0 / 0.0;
	}
	if (ix == 0x7ff00000) {
		return 0.0;
	}

	if (n == 0) {
		return y0(x);
	}
	if (n < 0) {
		nm1 = -(n + 1);
		sign = n & 1;
	} else {
		nm1 = n - 1;
		sign = 0;
	}
	if (nm1 == 0) {
		return sign ? -y1(x) : y1(x);
	}

	if (ix >= 0x52d00000) {		/* x > 2**302 */
		/* (x >> n**2)
		 *      Jn(x) = cos(x-(2n+1)*pi/4)*sqrt(2/x*pi)
		 *      Yn(x) = sin(x-(2n+1)*pi/4)*sqrt(2/x*pi)
		 *      Let s=sin(x), c=cos(x),
		 *          xn=x-(2n+1)*pi/4, sqt2 = sqrt(2),then
		 *
		 *             n    sin(xn)*sqt2    cos(xn)*sqt2
		 *          ----------------------------------
		 *             0     s-c             c+s
		 *             1    -s-c            -c+s
		 *             2    -s+c            -c-s
		 *             3     s+c             c-s
		 */
		switch (nm1 & 3) {
		case 0:
			temp = -sin(x) - cos(x);
			break;
		case 1:
			temp = -sin(x) + cos(x);
			break;
		case 2:
			temp = sin(x) + cos(x);
			break;
		default:
		case 3:
			temp = sin(x) - cos(x);
			break;
		}
		b = invsqrtpi * temp / sqrt(x);
	} else {
		a = y0(x);
		b = y1(x);
		/* quit if b is -inf */
		GET_HIGH_WORD(ib, b);
		for (i = 0; i < nm1 && ib != 0xfff00000;) {
			i++;
			temp = b;
			b = (2.0 * i / x) * b - a;
			GET_HIGH_WORD(ib, b);
			a = temp;
		}
	}
	return sign ? -b : b;
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
 * origin: FreeBSD /usr/src/lib/msun/src/e_jnf.c
 *
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 *
 *
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 ***************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

float jnf(int n, float x)
{
	uint32_t ix;
	int nm1;
	int sign;
	int i;
	float a;
	float b;
	float temp;

	GET_FLOAT_WORD(ix, x);
	sign = ix >> 31;
	ix &= 0x7fffffff;
	if (ix > 0x7f800000) {		/* nan */
		return x;
	}

	/* J(-n,x) = J(n,-x), use |n|-1 to avoid overflow in -n */
	if (n == 0) {
		return j0f(x);
	}
	if (n < 0) {
		nm1 = -(n + 1);
		x = -x;
		sign ^= 1;
	} else {
		nm1 = n - 1;
	}
	if (nm1 == 0) {
		return j1f(x);
	}

	sign &= n;					/* even n: 0, odd n: signbit(x) */
	x = fabsf(x);
	if (ix == 0 || ix == 0x7f800000) {	/* if x is 0 or inf */
		b = 0.0f;
	} else if (nm1 < x) {
		/* Safe to use J(n+1,x)=2n/x *J(n,x)-J(n-1,x) */
		a = j0f(x);
		b = j1f(x);
		for (i = 0; i < nm1;) {
			i++;
			temp = b;
			b = b * (2.0f * i / x) - a;
			a = temp;
		}
	} else {
		if (ix < 0x35800000) {	/* x < 2**-20 */
			/* x is tiny, return the first Taylor expansion of J(n,x)
			 * J(n,x) = 1/n!*(x/2)^n  - ...
			 */
			if (nm1 > 8) {		/* underflow */
				nm1 = 8;
			}
			temp = 0.5f * x;
			b = temp;
			a = 1.0f;
			for (i = 2; i <= nm1 + 1; i++) {
				a *= (float)i;	/* a = n! */
				b *= temp;		/* b = (x/2)^n */
			}
			b = b / a;
		} else {
			/* use backward recurrence */
			/*                      x      x^2      x^2
			 *  J(n,x)/J(n-1,x) =  ----   ------   ------   .....
			 *                      2n  - 2(n+1) - 2(n+2)
			 *
			 *                      1      1        1
			 *  (for large x)   =  ----  ------   ------   .....
			 *                      2n   2(n+1)   2(n+2)
			 *                      -- - ------ - ------ -
			 *                       x     x         x
			 *
			 * Let w = 2n/x and h=2/x, then the above quotient
			 * is equal to the continued fraction:
			 *                  1
			 *      = -----------------------
			 *                     1
			 *         w - -----------------
			 *                        1
			 *              w+h - ---------
			 *                     w+2h - ...
			 *
			 * To determine how many terms needed, let
			 * Q(0) = w, Q(1) = w(w+h) - 1,
			 * Q(k) = (w+k*h)*Q(k-1) - Q(k-2),
			 * When Q(k) > 1e4      good for single
			 * When Q(k) > 1e9      good for double
			 * When Q(k) > 1e17     good for quadruple
			 */
			/* determine k */
			float t;
			float q0;
			float q1;
			float w;
			float h;
			float z;
			float tmp;
			float nf;
			int k;

			nf = nm1 + 1.0f;
			w = 2 * nf / x;
			h = 2 / x;
			z = w + h;
			q0 = w;
			q1 = w * z - 1.0f;
			k = 1;
			while (q1 < 1.0e4f) {
				k += 1;
				z += h;
				tmp = z * q1 - q0;
				q0 = q1;
				q1 = tmp;
			}
			for (t = 0.0f, i = k; i >= 0; i--) {
				t = 1.0f / (2 * (i + nf) / x - t);
			}
			a = t;
			b = 1.0f;
			/*  estimate log((2/x)^n*n!) = n*log(2/x)+n*ln(n)
			 *  Hence, if n*(log(2n/x)) > ...
			 *  single 8.8722839355e+01
			 *  double 7.09782712893383973096e+02
			 *  long double 1.1356523406294143949491931077970765006170e+04
			 *  then recurrent value may overflow and the result is
			 *  likely underflow to zero
			 */
			tmp = nf * logf(fabsf(w));
			if (tmp < 88.721679688f) {
				for (i = nm1; i > 0; i--) {
					temp = b;
					b = 2.0f * i * b / x - a;
					a = temp;
				}
			} else {
				for (i = nm1; i > 0; i--) {
					temp = b;
					b = 2.0f * i * b / x - a;
					a = temp;
					/* scale b to avoid spurious overflow */
					if (b > 0x1p60f) {
						a /= b;
						t /= b;
						b = 1.0f;
					}
				}
			}
			z = j0f(x);
			w = j1f(x);
			if (fabsf(z) >= fabsf(w)) {
				b = t * z / b;
			} else {
				b = t * w / a;
			}
		}
	}
	return sign ? -b : b;
}

float ynf(int n, float x)
{
	uint32_t ix;
	uint32_t ib;
	int nm1;
	int sign;
	int i;
	float a;
	float b;
	float temp;

	GET_FLOAT_WORD(ix, x);
	sign = ix >> 31;
	ix &= 0x7fffffff;
	if (ix > 0x7f800000) {		/* nan */
		return x;
	}
	if (sign && ix != 0) {		/* x < 0 */
		return 0 / 0.0f;
	}
	if (ix == 0x7f800000) {
		return 0.0f;
	}

	if (n == 0) {
		return y0f(x);
	}
	if (n < 0) {
		nm1 = -(n + 1);
		sign = n & 1;
	} else {
		nm1 = n - 1;
		sign = 0;
	}
	if (nm1 == 0) {
		return sign ? -y1f(x) : y1f(x);
	}

	a = y0f(x);
	b = y1f(x);
	/* quit if b is -inf */
	GET_FLOAT_WORD(ib, b);
	for (i = 0; i < nm1 && ib != 0xff800000;) {
		i++;
		temp = b;
		b = (2.0f * i / x) * b - a;
		GET_FLOAT_WORD(ib, b);
		a = temp;
	}
	return sign ? -b : b;
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
 * libc/math/lib_ldexp.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double ldexp(double x, int n)
{
	return (x * pow(2.0, (double)n));
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
 * libc/math/lib_ldexpf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float ldexpf(float x, int n)
{
	return (x * powf(2.0, (float)n));
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
 * libc/math/lib_ldexpl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double ldexpl(long double x, int n)
{
	return (x * powl(2.0, (long double)n));
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
 * libc/math/lib_gamma.c
 *
 * Ported to NuttX from FreeBSD by Alan Carvalho de Assis:
 *
 *   Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 *   Developed at SunSoft, a Sun Microsystems, Inc. business.
 *   Permission to use, copy, modify, and distribute this
 *   software is freely granted, provided that this notice
 *   is preserved.
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

/* lgamma_r(x, signgamp)
 *
 * Reentrant version of the logarithm of the Gamma function
 * with user provide pointer for the sign of Gamma(x).
 *
 * Method:
 *   1. Argument Reduction for 0 < x <= 8
 *      Since gamma(1+s)=s*gamma(s), for x in [0,8], we may
 *      reduce x to a number in [1.5,2.5] by
 *              lgamma(1+s) = log(s) + lgamma(s)
 *      for example,
 *              lgamma(7.3) = log(6.3) + lgamma(6.3)
 *                          = log(6.3*5.3) + lgamma(5.3)
 *                          = log(6.3*5.3*4.3*3.3*2.3) + lgamma(2.3)
 *   2. Polynomial approximation of lgamma around its
 *      minimun ymin=1.461632144968362245 to maintain monotonicity.
 *      On [ymin-0.23, ymin+0.27] (i.e., [1.23164,1.73163]), use
 *              Let z = x-ymin;
 *              lgamma(x) = -1.214862905358496078218 + z^2*poly(z)
 *      where
 *              poly(z) is a 14 degree polynomial.
 *   2. Rational approximation in the primary interval [2,3]
 *      We use the following approximation:
 *              s = x-2.0;
 *              lgamma(x) = 0.5*s + s*P(s)/Q(s)
 *      with accuracy
 *              |P/Q - (lgamma(x)-0.5s)| < 2**-61.71
 *      Our algorithms are based on the following observation
 *
 *                             zeta(2)-1    2    zeta(3)-1    3
 * lgamma(2+s) = s*(1-Euler) + --------- * s  -  --------- * s  + ...
 *                                 2                 3
 *
 *      where Euler = 0.5771... is the Euler constant, which is very
 *      close to 0.5.
 *
 *   3. For x>=8, we have
 *      lgamma(x)~(x-0.5)log(x)-x+0.5*log(2pi)+1/(12x)-1/(360x**3)+....
 *      (better formula:
 *         lgamma(x)~(x-0.5)*(log(x)-1)-.5*(log(2pi)-1) + ...)
 *      Let z = 1/x, then we approximation
 *              f(z) = lgamma(x) - (x-0.5)(log(x)-1)
 *      by
 *                                  3       5             11
 *              w = w0 + w1*z + w2*z  + w3*z  + ... + w6*z
 *      where
 *              |w - f(z)| < 2**-58.74
 *
 *   4. For negative x, since (G is gamma function)
 *              -x*G(-x)*G(x) = pi/sin(pi*x),
 *      we have
 *              G(x) = pi/(sin(pi*x)*(-x)*G(-x))
 *      since G(-x) is positive, sign(G(x)) = sign(sin(pi*x)) for x<0
 *      Hence, for x<0, signgam = sign(sin(pi*x)) and
 *              lgamma(x) = log(|Gamma(x)|)
 *                        = log(pi/(|x*sin(pi*x)|)) - lgamma(-x);
 *      Note: one should avoid compute pi*(-x) directly in the
 *            computation of sin(pi*(-x)).
 *
 *   5. Special Cases
 *              lgamma(2+s) ~ s*(1-Euler) for tiny s
 *              lgamma(1) = lgamma(2) = 0
 *              lgamma(x) ~ -log(|x|) for tiny x
 *              lgamma(0) = lgamma(neg.integer) = inf and raise divide-by-zero
 *              lgamma(inf) = inf
 *              lgamma(-inf) = inf (bug for bug compatible with C99!?)
 */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <sys/types.h>
#include <math.h>

#ifdef CONFIG_HAVE_DOUBLE

/****************************************************************************
 * Private Data
 ****************************************************************************/

static int g_signgam = 0;

static const double g_pi = 3.14159265358979311600e+00;	/* 0x400921FB, 0x54442D18 */
static const double g_a0 = 7.72156649015328655494e-02;	/* 0x3FB3C467, 0xE37DB0C8 */
static const double g_a1 = 3.22467033424113591611e-01;	/* 0x3FD4A34C, 0xC4A60FAD */
static const double g_a2 = 6.73523010531292681824e-02;	/* 0x3FB13E00, 0x1A5562A7 */
static const double g_a3 = 2.05808084325167332806e-02;	/* 0x3F951322, 0xAC92547B */
static const double g_a4 = 7.38555086081402883957e-03;	/* 0x3F7E404F, 0xB68FEFE8 */
static const double g_a5 = 2.89051383673415629091e-03;	/* 0x3F67ADD8, 0xCCB7926B */
static const double g_a6 = 1.19270763183362067845e-03;	/* 0x3F538A94, 0x116F3F5D */
static const double g_a7 = 5.10069792153511336608e-04;	/* 0x3F40B6C6, 0x89B99C00 */
static const double g_a8 = 2.20862790713908385557e-04;	/* 0x3F2CF2EC, 0xED10E54D */
static const double g_a9 = 1.08011567247583939954e-04;	/* 0x3F1C5088, 0x987DFB07 */
static const double g_a10 = 2.52144565451257326939e-05;	/* 0x3EFA7074, 0x428CFA52 */
static const double g_a11 = 4.48640949618915160150e-05;	/* 0x3F07858E, 0x90A45837 */
static const double g_tc = 1.46163214496836224576e+00;	/* 0x3FF762D8, 0x6356BE3F */
static const double g_tf = -1.21486290535849611461e-01;	/* 0xBFBF19B9, 0xBCC38A42 */

/* tt = -(tail of tf) */

static const double g_tt = -3.63867699703950536541e-18;	/* 0xBC50C7CA, 0xA48A971F */
static const double g_t0 = 4.83836122723810047042e-01;	/* 0x3FDEF72B, 0xC8EE38A2 */
static const double g_t1 = -1.47587722994593911752e-01;	/* 0xBFC2E427, 0x8DC6C509 */
static const double g_t2 = 6.46249402391333854778e-02;	/* 0x3FB08B42, 0x94D5419B */
static const double g_t3 = -3.27885410759859649565e-02;	/* 0xBFA0C9A8, 0xDF35B713 */
static const double g_t4 = 1.79706750811820387126e-02;	/* 0x3F9266E7, 0x970AF9EC */
static const double g_t5 = -1.03142241298341437450e-02;	/* 0xBF851F9F, 0xBA91EC6A */
static const double g_t6 = 6.10053870246291332635e-03;	/* 0x3F78FCE0, 0xE370E344 */
static const double g_t7 = -3.68452016781138256760e-03;	/* 0xBF6E2EFF, 0xB3E914D7 */
static const double g_t8 = 2.25964780900612472250e-03;	/* 0x3F6282D3, 0x2E15C915 */
static const double g_t9 = -1.40346469989232843813e-03;	/* 0xBF56FE8E, 0xBF2D1AF1 */
static const double g_t10 = 8.81081882437654011382e-04;	/* 0x3F4CDF0C, 0xEF61A8E9 */
static const double g_t11 = -5.38595305356740546715e-04;	/* 0xBF41A610, 0x9C73E0EC */
static const double g_t12 = 3.15632070903625950361e-04;	/* 0x3F34AF6D, 0x6C0EBBF7 */
static const double g_t13 = -3.12754168375120860518e-04;	/* 0xBF347F24, 0xECC38C38 */
static const double g_t14 = 3.35529192635519073543e-04;	/* 0x3F35FD3E, 0xE8C2D3F4 */
static const double g_u0 = -7.72156649015328655494e-02;	/* 0xBFB3C467, 0xE37DB0C8 */
static const double g_u1 = 6.32827064025093366517e-01;	/* 0x3FE4401E, 0x8B005DFF */
static const double g_u2 = 1.45492250137234768737e+00;	/* 0x3FF7475C, 0xD119BD6F */
static const double g_u3 = 9.77717527963372745603e-01;	/* 0x3FEF4976, 0x44EA8450 */
static const double g_u4 = 2.28963728064692451092e-01;	/* 0x3FCD4EAE, 0xF6010924 */
static const double g_u5 = 1.33810918536787660377e-02;	/* 0x3F8B678B, 0xBF2BAB09 */
static const double g_v1 = 2.45597793713041134822e+00;	/* 0x4003A5D7, 0xC2BD619C */
static const double g_v2 = 2.12848976379893395361e+00;	/* 0x40010725, 0xA42B18F5 */
static const double g_v3 = 7.69285150456672783825e-01;	/* 0x3FE89DFB, 0xE45050AF */
static const double g_v4 = 1.04222645593369134254e-01;	/* 0x3FBAAE55, 0xD6537C88 */
static const double g_v5 = 3.21709242282423911810e-03;	/* 0x3F6A5ABB, 0x57D0CF61 */
static const double g_s0 = -7.72156649015328655494e-02;	/* 0xBFB3C467, 0xE37DB0C8 */
static const double g_s1 = 2.14982415960608852501e-01;	/* 0x3FCB848B, 0x36E20878 */
static const double g_s2 = 3.25778796408930981787e-01;	/* 0x3FD4D98F, 0x4F139F59 */
static const double g_s3 = 1.46350472652464452805e-01;	/* 0x3FC2BB9C, 0xBEE5F2F7 */
static const double g_s4 = 2.66422703033638609560e-02;	/* 0x3F9B481C, 0x7E939961 */
static const double g_s5 = 1.84028451407337715652e-03;	/* 0x3F5E26B6, 0x7368F239 */
static const double g_s6 = 3.19475326584100867617e-05;	/* 0x3F00BFEC, 0xDD17E945 */
static const double g_r1 = 1.39200533467621045958e+00;	/* 0x3FF645A7, 0x62C4AB74 */
static const double g_r2 = 7.21935547567138069525e-01;	/* 0x3FE71A18, 0x93D3DCDC */
static const double g_r3 = 1.71933865632803078993e-01;	/* 0x3FC601ED, 0xCCFBDF27 */
static const double g_r4 = 1.86459191715652901344e-02;	/* 0x3F9317EA, 0x742ED475 */
static const double g_r5 = 7.77942496381893596434e-04;	/* 0x3F497DDA, 0xCA41A95B */
static const double g_r6 = 7.32668430744625636189e-06;	/* 0x3EDEBAF7, 0xA5B38140 */
static const double g_w0 = 4.18938533204672725052e-01;	/* 0x3FDACFE3, 0x90C97D69 */
static const double g_w1 = 8.33333333333329678849e-02;	/* 0x3FB55555, 0x5555553B */
static const double g_w2 = -2.77777777728775536470e-03;	/* 0xBF66C16C, 0x16B02E5C */
static const double g_w3 = 7.93650558643019558500e-04;	/* 0x3F4A019F, 0x98CF38B6 */
static const double g_w4 = -5.95187557450339963135e-04;	/* 0xBF4380CB, 0x8C0FE741 */
static const double g_w5 = 8.36339918996282139126e-04;	/* 0x3F4B67BA, 0x4CDAD5D1 */
static const double g_w6 = -1.63092934096575273989e-03;	/* 0xBF5AB89D, 0x0B9E43E4 */

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/* sin(pi*x) assuming x > 2^-100, if sin(pi*x)==0 the sign is arbitrary */

static double sin_pi(double x)
{
	int n;

	/* spurious inexact if odd int */

	x = 2.0 * (x * 0.5 - floor(x * 0.5));	/* x mod 2.0 */

	n = (int)(x * 4.0);
	n = (n + 1) / 2;
	x -= n * 0.5f;
	x *= g_pi;

	switch (n) {
	default:					/* case 4: */
	case 0:
		return __sin(x, 0.0, 0);

	case 1:
		return __cos(x, 0.0);

	case 2:
		return __sin(-x, 0.0, 0);

	case 3:
		return -__cos(x, 0.0);
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

double lgamma_r(double x, int *signgamp)
{
	union {
		double f;
		uint64_t i;
	} u;
	u.f = x;

	double t;
	double y;
	double z;
	double nadj = 0.0;
	double p;
	double p1;
	double p2;
	double p3;
	double q;
	double r;
	double w;
	uint32_t ix;
	int sign;
	int i;

	/* purge off +-inf, NaN, +-0, tiny and negative arguments */

	*signgamp = 1;
	sign = u.i >> 63;

	ix = u.i >> 32 & 0x7fffffff;
	if (ix >= 0x7ff00000) {
		return x * x;
	}

	/* |x|<2**-70, return -log(|x|) */

	if (ix < (0x3ff - 70) << 20) {
		if (sign) {
			x = -x;
			*signgamp = -1;
		}
		return -log(x);
	}

	if (sign) {
		x = -x;
		t = sin_pi(x);

		if (t == 0.0) {
			/* -integer */
			return 1.0 / (x - x);
		}

		if (t > 0.0) {
			*signgamp = -1;
		} else {
			t = -t;
		}

		nadj = log(g_pi / (t * x));
	}

	/* purge off 1 and 2 */

	if ((ix == 0x3ff00000 || ix == 0x40000000) && (uint32_t) u.i == 0) {
		r = 0;
	} else {					/* for x < 2.0 */

		if (ix < 0x40000000) {
			if (ix <= 0x3feccccc) {
				/* lgamma(x) = lgamma(x+1)-log(x) */

				r = -log(x);

				if (ix >= 0x3FE76944) {
					y = 1.0 - x;
					i = 0;
				} else {
					if (ix >= 0x3FCDA661) {
						y = x - (g_tc - 1.0);
						i = 1;
					} else {
						y = x;
						i = 2;
					}
				}
			} else {
				r = 0.0;

				if (ix >= 0x3FFBB4C3) {
					/* [1.7316,2] */
					y = 2.0 - x;
					i = 0;
				} else {
					if (ix >= 0x3FF3B4C4) {
						/* [1.23,1.73] */
						y = x - g_tc;
						i = 1;
					} else {
						y = x - 1.0;
						i = 2;
					}
				}
			}

			switch (i) {
			case 0:
				z = y * y;
				p1 = g_a0 + z * (g_a2 + z * (g_a4 + z * (g_a6 + z * (g_a8 + z * g_a10))));
				p2 = z * (g_a1 + z * (g_a3 + z * (g_a5 + z * (g_a7 + z * (g_a9 + z * g_a11)))));
				p = y * p1 + p2;
				r += (p - 0.5 * y);
				break;

			case 1:
				z = y * y;
				w = z * y;
				p1 = g_t0 + w * (g_t3 + w * (g_t6 + w * (g_t9 + w * g_t12)));	/* parallel comp */
				p2 = g_t1 + w * (g_t4 + w * (g_t7 + w * (g_t10 + w * g_t13)));
				p3 = g_t2 + w * (g_t5 + w * (g_t8 + w * (g_t11 + w * g_t14)));
				p = z * p1 - (g_tt - w * (p2 + y * p3));
				r += g_tf + p;
				break;

			case 2:
				p1 = y * (g_u0 + y * (g_u1 + y * (g_u2 + y * (g_u3 + y * (g_u4 + y * g_u5)))));
				p2 = 1.0 + y * (g_v1 + y * (g_v2 + y * (g_v3 + y * (g_v4 + y * g_v5))));
				r += -0.5 * y + p1 / p2;
			}
		} else {
			if (ix < 0x40200000) {
				/* x < 8.0 */

				i = (int)x;
				y = x - (double)i;
				p = y * (g_s0 + y * (g_s1 + y * (g_s2 + y * (g_s3 + y * (g_s4 + y * (g_s5 + y * g_s6))))));
				q = 1.0 + y * (g_r1 + y * (g_r2 + y * (g_r3 + y * (g_r4 + y * (g_r5 + y * g_r6)))));
				r = 0.5 * y + p / q;
				z = 1.0;

				/* lgamma(1+s) = log(s) + lgamma(s) */

				switch (i) {
				case 7:
					z *= y + 6.0;	/* FALLTHRU */
				case 6:
					z *= y + 5.0;	/* FALLTHRU */
				case 5:
					z *= y + 4.0;	/* FALLTHRU */
				case 4:
					z *= y + 3.0;	/* FALLTHRU */
				case 3:
					z *= y + 2.0;	/* FALLTHRU */
					r += log(z);
					break;
				}
			} else {
				if (ix < 0x43900000) {
					/* 8.0 <= x < 2**58 */

					t = log(x);
					z = 1.0 / x;
					y = z * z;
					w = g_w0 + z * (g_w1 + y * (g_w2 + y * (g_w3 + y * (g_w4 + y * (g_w5 + y * g_w6)))));
					r = (x - 0.5) * (t - 1.0) + w;
				} else {
					/* 2**58 <= x <= inf */

					r = x * (log(x) - 1.0);
				}
			}
		}
	}

	if (sign) {
		r = nadj - r;
	}

	return r;
}

double lgamma(double x)
{
	return lgamma_r(x, &g_signgam);
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
 * libc/math/lib_libexpi.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <sys/types.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

/************************************************************************
 * Pre-processor Definitions
 ************************************************************************/

#define M_E2    (M_E * M_E)
#define M_E4    (M_E2 * M_E2)
#define M_E8    (M_E4 * M_E4)
#define M_E16   (M_E8 * M_E8)
#define M_E32   (M_E16 * M_E16)
#define M_E64   (M_E32 * M_E32)
#define M_E128  (M_E64 * M_E64)
#define M_E256  (M_E128 * M_E128)
#define M_E512  (M_E256 * M_E256)
#define M_E1024 (M_E512 * M_E512)

/************************************************************************
 * Private Data
 ************************************************************************/

static double _expi_square_tbl[11] = {
	M_E,						/* e^1 */
	M_E2,						/* e^2 */
	M_E4,						/* e^4 */
	M_E8,						/* e^8 */
	M_E16,						/* e^16 */
	M_E32,						/* e^32 */
	M_E64,						/* e^64 */
	M_E128,						/* e^128 */
	M_E256,						/* e^256 */
	M_E512,						/* e^512 */
	M_E1024,					/* e^1024 */
};

/************************************************************************
 * Public Functions
 ************************************************************************/

double lib_expi(size_t n)
{
	size_t i;
	double val;

	if (n > 1024) {
		return INFINITY;
	}

	val = 1.0;

	for (i = 0; n; i++) {
		if (n & (1 << i)) {
			n &= ~(1 << i);
			val *= _expi_square_tbl[i];
		}
	}

	return val;
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
 * libc/math/lib_libsqrtapprox.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <stdint.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float lib_sqrtapprox(float x)
{
	int32_t i;

	/* Floats + bit manipulation = +inf fun! */

	i = *((int32_t *)&x);
	i = 0x1fc00000 + (i >> 1);
	x = *((float *)&i);

	return x;
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
 * libc/math/lib_log.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <float.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double log(double x)
{
	double y;
	double y_old;
	double ey;
	double epsilon;

	if (x < 0.0) {
		return NAN;
	}

	y = 0.0;
	y_old = 1.0;
	epsilon = DBL_EPSILON;

	while (y > y_old + epsilon || y < y_old - epsilon) {
		y_old = y;
		ey = exp(y);
		y -= (ey - x) / ey;

		if (y > 700.0) {
			y = 700.0;
		}

		if (y < -700.0) {
			y = -700.0;
		}

		epsilon = (fabs(y) > 1.0) ? fabs(y) * DBL_EPSILON : DBL_EPSILON;
	}

	if (y == 700.0) {
		return INFINITY;
	}

	if (y == -700.0) {
		return -INFINITY;
	}

	return y;
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
 * libc/math/lib_log10.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double log10(double x)
{
	return (log(x) / M_LN10);
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
 * libc/math/lib_log10f.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float log10f(float x)
{
	return (logf(x) / M_LN10);
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
 * libc/math/lib_log10l.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double log10l(long double x)
{
	return (logl(x) / M_LN10);
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
 * libc/math/lib_log2.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double log2(double x)
{
	return (log(x) / M_LN2);
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
 * libc/math/lib_log2f.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float log2f(float x)
{
	return (logf(x) / M_LN2);
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
 * libc/math/lib_log2l.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double log2l(long double x)
{
	return (logl(x) / M_LN2);
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
 * libc/math/lib_logf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>
#include <float.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float logf(float x)
{
	float y;
	float y_old;
	float ey;
	float epsilon;

	y = 0.0;
	y_old = 1.0;
	epsilon = FLT_EPSILON;

	while (y > y_old + epsilon || y < y_old - epsilon) {
		y_old = y;
		ey = expf(y);
		y -= (ey - x) / ey;

		if (y > 700.0) {
			y = 700.0;
		}

		if (y < -700.0) {
			y = -700.0;
		}

		epsilon = (fabsf(y) > 1.0) ? fabsf(y) * FLT_EPSILON : FLT_EPSILON;
	}

	if (y == 700.0) {
		return INFINITY;
	}

	if (y == -700.0) {
		return INFINITY;
	}

	return y;
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
 * libc/math/lib_lol.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <float.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double logl(long double x)
{
	long double y;
	long double y_old;
	long double ey;
	long double epsilon;

	y = 0.0;
	y_old = 1.0;
	epsilon = LDBL_EPSILON;

	while (y > y_old + epsilon || y < y_old - epsilon) {
		y_old = y;
		ey = expl(y);
		y -= (ey - x) / ey;

		if (y > 700.0) {
			y = 700.0;
		}

		if (y < -700.0) {
			y = -700.0;
		}
	}

	if (y == 700.0) {
		return INFINITY;
	}

	if (y == -700.0) {
		return INFINITY;
	}

	return y;
}
#endif
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
/************************************************************************
 * libc/math/lib_modf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <stdint.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double modf(double x, double *iptr)
{
	if (fabs(x) >= 4503599627370496.0) {
		*iptr = x;
		return 0.0;
	} else if (fabs(x) < 1.0) {
		*iptr = (x * 0.0);
		return x;
	} else {
		*iptr = (double)(int64_t)x;
		return (x - *iptr);
	}
}
#endif
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
/************************************************************************
 * libc/math/lib_modff.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float modff(float x, float *iptr)
{
	if (fabsf(x) >= 8388608.0) {
		*iptr = x;
		return 0.0;
	} else if (fabsf(x) < 1.0) {
		*iptr = (x * 0.0);
		return x;
	} else {
		*iptr = (float)(int)x;
		return (x - *iptr);
	}
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
/************************************************************************
 * libc/math/lib_modfl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <stdint.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double modfl(long double x, long double *iptr)
{
	if (fabsl(x) >= 4503599627370496.0) {
		*iptr = x;
		return 0.0;
	} else if (fabsl(x) < 1.0) {
		*iptr = (x * 0.0);
		return x;
	} else {
		*iptr = (long double)(int64_t)x;
		return (x - *iptr);
	}
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>

#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double nextafter(double x, double y)
{
	union {
		double f;
		uint64_t i;
	} ux = { x }, uy = { y };
	uint64_t ax, ay;
	int e;

	if (isnan(x) || isnan(y)) {
		return x + y;
	}
	if (ux.i == uy.i) {
		return y;
	}
	ax = ux.i & -1ULL / 2;
	ay = uy.i & -1ULL / 2;
	if (ax == 0) {
		if (ay == 0) {
			return y;
		}
		ux.i = (uy.i & 1ULL << 63) | 1;
	} else if (ax > ay || ((ux.i ^ uy.i) & 1ULL << 63)) {
		ux.i--;
	} else {
		ux.i++;
	}
	e = ux.i >> 52 & 0x7ff;
	/* raise overflow if ux.f is infinite and x is finite */
	if (e == 0x7ff) {
		FORCE_EVAL(x + x);
	}
	/* raise underflow if ux.f is subnormal or zero */
	if (e == 0) {
		FORCE_EVAL(x * x + ux.f * ux.f);
	}

	return ux.f;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

float nextafterf(float x, float y)
{
	union {
		float f;
		uint32_t i;
	} ux = { x }, uy = { y };
	uint32_t ax, ay, e;

	if (isnan(x) || isnan(y)) {
		return x + y;
	}
	if (ux.i == uy.i) {
		return y;
	}
	ax = ux.i & 0x7fffffff;
	ay = uy.i & 0x7fffffff;
	if (ax == 0) {
		if (ay == 0) {
			return y;
		}
		ux.i = (uy.i & 0x80000000) | 1;
	} else if (ax > ay || ((ux.i ^ uy.i) & 0x80000000)) {
		ux.i--;
	} else {
		ux.i++;
	}
	e = ux.i & 0x7f800000;
	/* raise overflow if ux.f is infinite and x is finite */
	if (e == 0x7f800000) {
		FORCE_EVAL(x + x);
	}
	/* raise underflow if ux.f is subnormal or zero */
	if (e == 0) {
		FORCE_EVAL(x * x + ux.f * ux.f);
	}

	return ux.f;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>

#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double nextafterl(long double x, long double y)
{
	return nextafter(x, y);
}
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
long double nextafterl(long double x, long double y)
{
	union ldshape ux, uy;

	if (isnan(x) || isnan(y)) {
		return x + y;
	}
	if (x == y) {
		return y;
	}
	ux.f = x;
	if (x == 0) {
		uy.f = y;
		ux.i.m = 1;
		ux.i.se = uy.i.se & 0x8000;
	} else if ((x < y) == !(ux.i.se & 0x8000)) {
		ux.i.m++;
		if (ux.i.m << 1 == 0) {
			ux.i.m = 1ULL << 63;
			ux.i.se++;
		}
	} else {
		if (ux.i.m << 1 == 0) {
			ux.i.se--;
			if (ux.i.se) {
				ux.i.m = 0;
			}
		}
		ux.i.m--;
	}
	/* raise overflow if ux is infinite and x is finite */
	if ((ux.i.se & 0x7fff) == 0x7fff) {
		return x + x;
	}
	/* raise underflow if ux is subnormal or zero */
	if ((ux.i.se & 0x7fff) == 0) {
		FORCE_EVAL(x * x + ux.f * ux.f);
	}
	return ux.f;
}
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
long double nextafterl(long double x, long double y)
{
	union ldshape ux, uy;

	if (isnan(x) || isnan(y)) {
		return x + y;
	}
	if (x == y) {
		return y;
	}
	ux.f = x;
	if (x == 0) {
		uy.f = y;
		ux.i.lo = 1;
		ux.i.se = uy.i.se & 0x8000;
	} else if ((x < y) == !(ux.i.se & 0x8000)) {
		ux.i2.lo++;
		if (ux.i2.lo == 0) {
			ux.i2.hi++;
		}
	} else {
		if (ux.i2.lo == 0) {
			ux.i2.hi--;
		}
		ux.i2.lo--;
	}
	/* raise overflow if ux is infinite and x is finite */
	if ((ux.i.se & 0x7fff) == 0x7fff) {
		return x + x;
	}
	/* raise underflow if ux is subnormal or zero */
	if ((ux.i.se & 0x7fff) == 0) {
		FORCE_EVAL(x * x + ux.f * ux.f);
	}
	return ux.f;
}
#endif
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>

#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
double nexttoward(double x, long double y)
{
	return nextafter(x, y);
}
#else
double nexttoward(double x, long double y)
{
	union {
		double f;
		uint64_t i;
	} ux = { x };
	int e;

	if (isnan(x) || isnan(y)) {
		return x + y;
	}
	if (x == y) {
		return y;
	}
	if (x == 0) {
		ux.i = 1;
		if (signbit(y)) {
			ux.i |= 1ULL << 63;
		}
	} else if (x < y) {
		if (signbit(x)) {
			ux.i--;
		} else {
			ux.i++;
		}
	} else {
		if (signbit(x)) {
			ux.i++;
		} else {
			ux.i--;
		}
	}
	e = ux.i >> 52 & 0x7ff;
	/* raise overflow if ux.f is infinite and x is finite */
	if (e == 0x7ff) {
		FORCE_EVAL(x + x);
	}
	/* raise underflow if ux.f is subnormal or zero */
	if (e == 0) {
		FORCE_EVAL(x * x + ux.f * ux.f);
	}

	return ux.f;
}
#endif
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

float nexttowardf(float x, long double y)
{
	union {
		float f;
		uint32_t i;
	} ux = { x };
	uint32_t e;

	if (isnan(x) || isnan(y)) {
		return x + y;
	}
	if (x == y) {
		return y;
	}
	if (x == 0) {
		ux.i = 1;
		if (signbit(y)) {
			ux.i |= 0x80000000;
		}
	} else if (x < y) {
		if (signbit(x)) {
			ux.i--;
		} else {
			ux.i++;
		}
	} else {
		if (signbit(x)) {
			ux.i++;
		} else {
			ux.i--;
		}
	}
	e = ux.i & 0x7f800000;
	/* raise overflow if ux.f is infinite and x is finite */
	if (e == 0x7f800000) {
		FORCE_EVAL(x + x);
	}
	/* raise underflow if ux.f is subnormal or zero */
	if (e == 0) {
		FORCE_EVAL(x * x + ux.f * ux.f);
	}

	return ux.f;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double nexttowardl(long double x, long double y)
{
	return nextafterl(x, y);
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
 * libc/math/lib_pow.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <stdint.h>

static union {
	double dbl;
	uint64_t bit;
} zero;

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
/* since pow get value using exp, result of pow is not a precise value. */
double pow(double b, double e)
{
	double int_part;
	modf(e, &int_part);
	if (b > 0.0) {
		if (b == 1.0) {
			return b;
		}
		return exp(e * log(b));
	} else if (b == 0.0) {
		if (e > 0.0) {
			return b;
		} else if (e == 0.0) {
			return NAN;
		} else {
			if (e == int_part) {
				if ((int64_t)e % 2) {
					zero.dbl = b;
					if (zero.bit != (uint64_t)0x0) {
						return -INFINITY;
					}
				}
				return INFINITY;
			}
		}
	} else {
		if (e == int_part) {
			if ((int64_t)e % 2) {
				return -exp(e * log(-b));
			}
			return exp(e * log(-b));
		}
	}
	return NAN;
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
 * libc/math/lib_powf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float powf(float b, float e)
{
	return expf(e * logf(b));
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
 * libc/math/lib_powl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double powl(long double b, long double e)
{
	return expl(e * logl(b));
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double remainder(double x, double y)
{
	int q;
	return remquo(x, y, &q);
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float remainderf(float x, float y)
{
	int q;
	return remquof(x, y, &q);
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>
#include <float.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double remainderl(long double x, long double y)
{
	return remainder(x, y);
}
#else
long double remainderl(long double x, long double y)
{
	int q;
	return remquol(x, y, &q);
}
#endif
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>
#include <stdint.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
double remquo(double x, double y, int *quo)
{
	union {
		double f;
		uint64_t i;
	} ux = { x }, uy = { y };
	int ex = ux.i >> 52 & 0x7ff;
	int ey = uy.i >> 52 & 0x7ff;
	int sx = ux.i >> 63;
	int sy = uy.i >> 63;
	uint32_t q;
	uint64_t i;
	uint64_t uxi = ux.i;

	*quo = 0;
	if (uy.i << 1 == 0 || isnan(y) || ex == 0x7ff) {
		return (x * y) / (x * y);
	}
	if (ux.i << 1 == 0) {
		return x;
	}

	/* normalize x and y */
	if (!ex) {
		for (i = uxi << 12; i >> 63 == 0; ex--, i <<= 1) ;
		uxi <<= -ex + 1;
	} else {
		uxi &= -1ULL >> 12;
		uxi |= 1ULL << 52;
	}
	if (!ey) {
		for (i = uy.i << 12; i >> 63 == 0; ey--, i <<= 1) ;
		uy.i <<= -ey + 1;
	} else {
		uy.i &= -1ULL >> 12;
		uy.i |= 1ULL << 52;
	}

	q = 0;
	if (ex < ey) {
		if (ex + 1 == ey) {
			goto end;
		}
		return x;
	}

	/* x mod y */
	for (; ex > ey; ex--) {
		i = uxi - uy.i;
		if (i >> 63 == 0) {
			uxi = i;
			q++;
		}
		uxi <<= 1;
		q <<= 1;
	}
	i = uxi - uy.i;
	if (i >> 63 == 0) {
		uxi = i;
		q++;
	}
	if (uxi == 0) {
		ex = -60;
	} else {
		for (; uxi >> 52 == 0; uxi <<= 1, ex--) ;
	}
end:
	/* scale result and decide between |x| and |x|-|y| */
	if (ex > 0) {
		uxi -= 1ULL << 52;
		uxi |= (uint64_t)ex << 52;
	} else {
		uxi >>= -ex + 1;
	}
	ux.i = uxi;
	x = ux.f;
	if (sy) {
		y = -y;
	}
	if (ex == ey || (ex + 1 == ey && (2 * x > y || (2 * x == y && q % 2)))) {
		x -= y;
		q++;
	}
	q &= 0x7fffffff;
	*quo = sx ^ sy ? -(int)q : (int)q;

	return sx ? -x : x;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>
#include <stdint.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float remquof(float x, float y, int *quo)
{
	union {
		float f;
		uint32_t i;
	} ux = { x }, uy = { y };
	int ex = ux.i >> 23 & 0xff;
	int ey = uy.i >> 23 & 0xff;
	int sx = ux.i >> 31;
	int sy = uy.i >> 31;
	uint32_t q;
	uint32_t i;
	uint32_t uxi = ux.i;

	*quo = 0;
	if (uy.i << 1 == 0 || isnan(y) || ex == 0xff) {
		return (x * y) / (x * y);
	}
	if (ux.i << 1 == 0) {
		return x;
	}

	/* normalize x and y */
	if (!ex) {
		for (i = uxi << 9; i >> 31 == 0; ex--, i <<= 1) ;
		uxi <<= -ex + 1;
	} else {
		uxi &= -1U >> 9;
		uxi |= 1U << 23;
	}
	if (!ey) {
		for (i = uy.i << 9; i >> 31 == 0; ey--, i <<= 1) ;
		uy.i <<= -ey + 1;
	} else {
		uy.i &= -1U >> 9;
		uy.i |= 1U << 23;
	}

	q = 0;
	if (ex < ey) {
		if (ex + 1 == ey) {
			goto end;
		}
		return x;
	}

	/* x mod y */
	for (; ex > ey; ex--) {
		i = uxi - uy.i;
		if (i >> 31 == 0) {
			uxi = i;
			q++;
		}
		uxi <<= 1;
		q <<= 1;
	}
	i = uxi - uy.i;
	if (i >> 31 == 0) {
		uxi = i;
		q++;
	}
	if (uxi == 0) {
		ex = -30;
	} else {
		for (; uxi >> 23 == 0; uxi <<= 1, ex--) ;
	}
end:
	/* scale result and decide between |x| and |x|-|y| */
	if (ex > 0) {
		uxi -= 1U << 23;
		uxi |= (uint32_t)ex << 23;
	} else {
		uxi >>= -ex + 1;
	}
	ux.i = uxi;
	x = ux.f;
	if (sy) {
		y = -y;
	}
	if (ex == ey || (ex + 1 == ey && (2 * x > y || (2 * x == y && q % 2)))) {
		x -= y;
		q++;
	}
	q &= 0x7fffffff;
	*quo = sx ^ sy ? -(int)q : (int)q;

	return sx ? -x : x;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>
#include <math.h>
#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double remquol(long double x, long double y, int *quo)
{
	return remquo(x, y, quo);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
long double remquol(long double x, long double y, int *quo)
{
	union ldshape ux = { x }, uy = { y };
	int ex = ux.i.se & 0x7fff;
	int ey = uy.i.se & 0x7fff;
	int sx = ux.i.se >> 15;
	int sy = uy.i.se >> 15;
	uint32_t q;

	*quo = 0;
	if (y == 0 || isnan(y) || ex == 0x7fff) {
		return (x * y) / (x * y);
	}
	if (x == 0) {
		return x;
	}

	/* normalize x and y */
	if (!ex) {
		ux.i.se = ex;
		ux.f *= 0x1p120f;
		ex = ux.i.se - 120;
	}
	if (!ey) {
		uy.i.se = ey;
		uy.f *= 0x1p120f;
		ey = uy.i.se - 120;
	}

	q = 0;
	if (ex >= ey) {
		/* x mod y */
#if LDBL_MANT_DIG == 64
		uint64_t i, mx, my;
		mx = ux.i.m;
		my = uy.i.m;
		for (; ex > ey; ex--) {
			i = mx - my;
			if (mx >= my) {
				mx = 2 * i;
				q++;
				q <<= 1;
			} else if (2 * mx < mx) {
				mx = 2 * mx - my;
				q <<= 1;
				q++;
			} else {
				mx = 2 * mx;
				q <<= 1;
			}
		}
		i = mx - my;
		if (mx >= my) {
			mx = i;
			q++;
		}
		if (mx == 0) {
			ex = -120;
		} else {
			for (; mx >> 63 == 0; mx *= 2, ex--) ;
		}
		ux.i.m = mx;
#elif LDBL_MANT_DIG == 113
		uint64_t hi, lo, xhi, xlo, yhi, ylo;
		xhi = (ux.i2.hi & -1ULL >> 16) | 1ULL << 48;
		yhi = (uy.i2.hi & -1ULL >> 16) | 1ULL << 48;
		xlo = ux.i2.lo;
		ylo = ux.i2.lo;
		for (; ex > ey; ex--) {
			hi = xhi - yhi;
			lo = xlo - ylo;
			if (xlo < ylo) {
				hi -= 1;
			}
			if (hi >> 63 == 0) {
				xhi = 2 * hi + (lo >> 63);
				xlo = 2 * lo;
				q++;
			} else {
				xhi = 2 * xhi + (xlo >> 63);
				xlo = 2 * xlo;
			}
			q <<= 1;
		}
		hi = xhi - yhi;
		lo = xlo - ylo;
		if (xlo < ylo) {
			hi -= 1;
		}
		if (hi >> 63 == 0) {
			xhi = hi;
			xlo = lo;
			q++;
		}
		if ((xhi | xlo) == 0) {
			ex = -120;
		} else {
			for (; xhi >> 48 == 0; xhi = 2 * xhi + (xlo >> 63), xlo = 2 * xlo, ex--) ;
		}
		ux.i2.hi = xhi;
		ux.i2.lo = xlo;
#endif
	}

	/* scale result and decide between |x| and |x|-|y| */
	if (ex <= 0) {
		ux.i.se = ex + 120;
		ux.f *= 0x1p-120f;
	} else {
		ux.i.se = ex;
	}
	x = ux.f;
	if (sy) {
		y = -y;
	}
	if (ex == ey || (ex + 1 == ey && (2 * x > y || (2 * x == y && q % 2)))) {
		x -= y;
		q++;
	}
	q &= 0x7fffffff;
	*quo = sx ^ sy ? -(int)q : (int)q;

	return sx ? -x : x;
}
#endif
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
 * libc/fixedmath/lib_rint.c
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
 * Compilation Switches
 ************************************************************/

/************************************************************
 * Included Files
 ************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdlib.h>
#include <math.h>

/************************************************************
 * Definitions
 ************************************************************/

/************************************************************
 * Private Type Declarations
 ************************************************************/

/************************************************************
 * Private Function Prototypes
 ************************************************************/

/**********************************************************
 * Global Constant Data
 **********************************************************/

/************************************************************
 * Global Variables
 ************************************************************/

/**********************************************************
 * Private Constant Data
 **********************************************************/

/************************************************************
 * Private Variables
 ************************************************************/

double rint(double x)
{
	long linteger;
	double fremainder;
	double ret;

	/* If the current rounding mode rounds toward negative
	 * infinity, rint() is identical to floor().  If the current
	 * rounding mode rounds toward positive infinity, rint() is
	 * identical to ceil().
	 */

#if defined(CONFIG_FP_ROUND_POSITIVE) && CONFIG_FP_ROUNDING_POSITIVE != 0

	ret = ceil(x);

#elif defined(CONFIG_FP_ROUND_NEGATIVE) && CONFIG_FP_ROUNDING_NEGATIVE != 0

	ret = floor(x);

#else

	/* In the default rounding mode (round to nearest), rint(x) is the
	 * integer nearest x with the additional stipulation that if
	 * |rint(x)-x|=1/2, then rint(x) is even.
	 */

	linteger = (long)x;
	fremainder = x - (double)linteger;

	if (x < 0.0) {
		/* fremainder should be in range 0 .. -1 */

		if (fremainder == -0.5) {
			linteger = ((linteger + 1) & ~1);
		} else if (fremainder < -0.5) {
			linteger--;
		}
	} else {
		/* fremainder should be in range 0 .. 1 */

		if (fremainder == 0.5) {
			linteger = ((linteger + 1) & ~1);
		} else if (fremainder > 0.5) {
			linteger++;
		}
	}

	ret = (double)linteger;
#endif

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
/************************************************************
 * libc/fixedmath/lib_rintf.c
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
 ************************************************************/

/************************************************************
 * Compilation Switches
 ************************************************************/

/************************************************************
 * Included Files
 ************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdlib.h>
#include <math.h>

/************************************************************
 * Definitions
 ************************************************************/

/************************************************************
 * Private Type Declarations
 ************************************************************/

/************************************************************
 * Private Function Prototypes
 ************************************************************/

/**********************************************************
 * Global Constant Data
 **********************************************************/

/************************************************************
 * Global Variables
 ************************************************************/

/**********************************************************
 * Private Constant Data
 **********************************************************/

/************************************************************
 * Private Variables
 ************************************************************/

float rintf(float x)
{
	long linteger;
	float fremainder;
	float ret;

	/* If the current rounding mode rounds toward negative
	 * infinity, rintf() is identical to floorf().  If the current
	 * rounding mode rounds toward positive infinity, rintf() is
	 * identical to ceilf().
	 */

#if defined(CONFIG_FP_ROUND_POSITIVE) && CONFIG_FP_ROUNDING_POSITIVE != 0

	ret = ceilf(x);

#elif defined(CONFIG_FP_ROUND_NEGATIVE) && CONFIG_FP_ROUNDING_NEGATIVE != 0

	ret = floorf(x);

#else

	/* In the default rounding mode (round to nearest), rint(x) is the
	 * integer nearest x with the additional stipulation that if
	 * |rint(x)-x|=1/2, then rint(x) is even.
	 */

	linteger = (long)x;
	fremainder = x - (float)linteger;

	if (x < 0.0) {
		/* fremainder should be in range 0 .. -1 */

		if (fremainder == -0.5) {
			linteger = ((linteger + 1) & ~1);
		} else if (fremainder < -0.5) {
			linteger--;
		}
	} else {
		/* fremainder should be in range 0 .. 1 */

		if (fremainder == 0.5) {
			linteger = ((linteger + 1) & ~1);
		} else if (fremainder > 0.5) {
			linteger++;
		}
	}

	ret = (float)linteger;
#endif

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
/************************************************************
 * libc/fixedmath/lib_rint.c
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
 * Compilation Switches
 ************************************************************/

/************************************************************
 * Included Files
 ************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdlib.h>
#include <math.h>

/************************************************************
 * Definitions
 ************************************************************/

/************************************************************
 * Private Type Declarations
 ************************************************************/

/************************************************************
 * Private Function Prototypes
 ************************************************************/

/**********************************************************
 * Global Constant Data
 **********************************************************/

/************************************************************
 * Global Variables
 ************************************************************/

/**********************************************************
 * Private Constant Data
 **********************************************************/

/************************************************************
 * Private Variables
 ************************************************************/

long double rintl(long double x)
{
	int64_t llinteger;
	long double fremainder;
	long double ret;

	/* If the current rounding mode rounds toward negative
	 * infinity, rint() is identical to floor().  If the current
	 * rounding mode rounds toward positive infinity, rint() is
	 * identical to ceil().
	 */

#if defined(CONFIG_FP_ROUND_POSITIVE) && CONFIG_FP_ROUNDING_POSITIVE != 0

	ret = ceil(x);

#elif defined(CONFIG_FP_ROUND_NEGATIVE) && CONFIG_FP_ROUNDING_NEGATIVE != 0

	ret = floor(x);

#else

	/* In the default rounding mode (round to nearest), rint(x) is the
	 * integer nearest x with the additional stipulation that if
	 * |rint(x)-x|=1/2, then rint(x) is even.
	 */

	llinteger = (int64_t)x;
	fremainder = x - (long double)llinteger;

	if (x < 0.0) {
		/* fremainder should be in range 0 .. -1 */

		if (fremainder == -0.5) {
			llinteger = ((llinteger + 1) & ~1);
		} else if (fremainder < -0.5) {
			llinteger--;
		}
	} else {
		/* fremainder should be in range 0 .. 1 */

		if (fremainder == 0.5) {
			llinteger = ((llinteger + 1) & ~1);
		} else if (fremainder > 0.5) {
			llinteger++;
		}
	}

	ret = (long double)llinteger;
#endif

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
/************************************************************************
 * lib/math/lib_round.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *             (C) 2012 Petteri Aimonen <jpa@nx.mail.kapsi.fi>
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double round(double x)
{
	double f = modf(x, &x);
	if (x <= 0.0 && f <= -0.5) {
		x -= 1.0;
	}

	if (x >= 0.0 && f >= 0.5) {
		x += 1.0;
	}

	return x;
}
#endif
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
/************************************************************************
 * lib/math/lib_roundf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *             (C) 2012 Petteri Aimonen <jpa@nx.mail.kapsi.fi>
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float roundf(float x)
{
	float f = modff(x, &x);
	if (x <= 0.0f && f <= -0.5f) {
		x -= 1.0f;
	}

	if (x >= 0.0f && f >= 0.5f) {
		x += 1.0f;
	}

	return x;
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
 * lib/math/lib_round.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *             (C) 2012 Petteri Aimonen <jpa@nx.mail.kapsi.fi>
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double roundl(long double x)
{
	long double f = modfl(x, &x);
	if (x <= 0.0 && f <= -0.5) {
		x -= 1.0;
	}

	if (x >= 0.0 && f >= 0.5) {
		x += 1.0;
	}

	return x;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <stdint.h>

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Public Functions
 ************************************************************************/

double scalbn(double x, int n)
{
	union {
		double f;
		uint64_t i;
	} u;
	double y = x;

	if (n > 1023) {
		y *= 0x1p1023;
		n -= 1023;
		if (n > 1023) {
			y *= 0x1p1023;
			n -= 1023;
			if (n > 1023) {
				n = 1023;
			}
		}
	} else if (n < -1022) {
		y *= 0x1p-1022;
		n += 1022;
		if (n < -1022) {
			y *= 0x1p-1022;
			n += 1022;
			if (n < -1022) {
				n = -1022;
			}
		}
	}

	u.i = (uint64_t)(0x3ff + n) << 52;
	x = y * u.f;

	return x;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>
#include <stdint.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float scalbnf(float x, int n)
{
	union {
		float f;
		uint32_t i;
	} u;
	float y = x;

	if (n > 127) {
		y *= 0x1p127f;
		n -= 127;
		if (n > 127) {
			y *= 0x1p127f;
			n -= 127;
			if (n > 127) {
				n = 127;
			}
		}
	} else if (n < -126) {
		y *= 0x1p-126f;
		n += 126;
		if (n < -126) {
			y *= 0x1p-126f;
			n += 126;
			if (n < -126) {
				n = -126;
			}
		}
	}

	u.i = (uint32_t)(0x7f + n) << 23;
	x = y * u.f;

	return x;
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

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include "libm.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double scalbnl(long double x, int n)
{
	return scalbn(x, n);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
long double scalbnl(long double x, int n)
{
	union ldshape u;

	if (n > 16383) {
		x *= 0x1p16383L;
		n -= 16383;
		if (n > 16383) {
			x *= 0x1p16383L;
			n -= 16383;
			if (n > 16383) {
				n = 16383;
			}
		}
	} else if (n < -16382) {
		x *= 0x1p-16382L;
		n += 16382;
		if (n < -16382) {
			x *= 0x1p-16382L;
			n += 16382;
			if (n < -16382) {
				n = -16382;
			}
		}
	}

	u.f = 1.0;
	u.i.se = 0x3fff + n;

	return x * u.f;
}
#endif
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
 * libc/math/lib_sin.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <sys/types.h>
#include <math.h>

#ifdef CONFIG_HAVE_DOUBLE

/************************************************************************
 * Private Data
 ************************************************************************/

static double _dbl_inv_fact[] = {
	1.0 / 1.0,					/* 1 / 1! */
	1.0 / 6.0,					/* 1 / 3! */
	1.0 / 120.0,				/* 1 / 5! */
	1.0 / 5040.0,				/* 1 / 7! */
	1.0 / 362880.0,				/* 1 / 9! */
	1.0 / 39916800.0,			/* 1 / 11! */
	1.0 / 6227020800.0,			/* 1 / 13! */
	1.0 / 1307674368000.0,		/* 1 / 15! */
	1.0 / 355687428096000.0,	/* 1 / 17! */
	1.0 / 121645100408832000.0,	/* 1 / 19! */
};

/************************************************************************
 * Public Functions
 ************************************************************************/

double sin(double x)
{
	double x_squared;
	double sin_x;
	size_t i;

	/* Move x to [-pi, pi) */

	x = fmod(x, 2 * M_PI);
	if (x >= M_PI) {
		x -= 2 * M_PI;
	}

	if (x < -M_PI) {
		x += 2 * M_PI;
	}

	/* Move x to [-pi/2, pi/2) */

	if (x >= M_PI_2) {
		x = M_PI - x;
	}

	if (x < -M_PI_2) {
		x = -M_PI - x;
	}

	x_squared = x * x;
	sin_x = 0.0;

	/* Perform Taylor series approximation for sin(x) with ten terms */

	for (i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			sin_x += x * _dbl_inv_fact[i];
		} else {
			sin_x -= x * _dbl_inv_fact[i];
		}

		x *= x_squared;
	}

	return sin_x;
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
 * libc/math/lib_sinf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <sys/types.h>
#include <math.h>

/************************************************************************
 * Private Data
 ************************************************************************/

static float _flt_inv_fact[] = {
	1.0 / 1.0,					/* 1 / 1! */
	1.0 / 6.0,					/* 1 / 3! */
	1.0 / 120.0,				/* 1 / 5! */
	1.0 / 5040.0,				/* 1 / 7! */
	1.0 / 362880.0,				/* 1 / 9! */
	1.0 / 39916800.0,			/* 1 / 11! */
};

/************************************************************************
 * Public Functions
 ************************************************************************/

float sinf(float x)
{
	float x_squared;
	float sin_x;
	size_t i;

	/* Move x to [-pi, pi) */

	x = fmodf(x, 2 * M_PI);
	if (x >= M_PI) {
		x -= 2 * M_PI;
	}

	if (x < -M_PI) {
		x += 2 * M_PI;
	}

	/* Move x to [-pi/2, pi/2) */

	if (x >= M_PI_2) {
		x = M_PI - x;
	}

	if (x < -M_PI_2) {
		x = -M_PI - x;
	}

	x_squared = x * x;
	sin_x = 0.0;

	/* Perform Taylor series approximation for sin(x) with six terms */

	for (i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			sin_x += x * _flt_inv_fact[i];
		} else {
			sin_x -= x * _flt_inv_fact[i];
		}

		x *= x_squared;
	}

	return sin_x;
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
 * libc/math/lib_sinh.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double sinh(double x)
{
	x = exp(x);
	return ((x - (1.0 / x)) / 2.0);
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
 * libc/math/lib_sinhf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float sinhf(float x)
{
	x = expf(x);
	return ((x - (1.0 / x)) / 2.0);
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
 * libc/math/lib_sinhl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double sinhl(long double x)
{
	x = expl(x);
	return ((x - (1.0 / x)) / 2.0);
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
 * libc/math/lib_sinl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <sys/types.h>
#include <math.h>

#ifdef CONFIG_HAVE_LONG_DOUBLE

/************************************************************************
 * Private Data
 ************************************************************************/

static long double _ldbl_inv_fact[] = {
	1.0 / 1.0,					/* 1 / 1! */
	1.0 / 6.0,					/* 1 / 3! */
	1.0 / 120.0,				/* 1 / 5! */
	1.0 / 5040.0,				/* 1 / 7! */
	1.0 / 362880.0,				/* 1 / 9! */
	1.0 / 39916800.0,			/* 1 / 11! */
	1.0 / 6227020800.0,			/* 1 / 13! */
	1.0 / 1307674368000.0,		/* 1 / 15! */
	1.0 / 355687428096000.0,	/* 1 / 17! */
	1.0 / 121645100408832000.0,	/* 1 / 19! */
};

/************************************************************************
 * Public Functions
 ************************************************************************/

long double sinl(long double x)
{
	long double x_squared;
	long double sin_x;
	size_t i;

	/* Move x to [-pi, pi) */

	x = fmodl(x, 2 * M_PI);
	if (x >= M_PI) {
		x -= 2 * M_PI;
	}

	if (x < -M_PI) {
		x += 2 * M_PI;
	}

	/* Move x to [-pi/2, pi/2) */

	if (x >= M_PI_2) {
		x = M_PI - x;
	}

	if (x < -M_PI_2) {
		x = -M_PI - x;
	}

	x_squared = x * x;
	sin_x = 0.0;

	/* Perform Taylor series approximation for sin(x) with ten terms */

	for (i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			sin_x += x * _ldbl_inv_fact[i];
		} else {
			sin_x -= x * _ldbl_inv_fact[i];
		}

		x *= x_squared;
	}

	return sin_x;
}
#endif
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
/************************************************************************
 * libc/math/lib_sqrt.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <errno.h>

#include "lib_internal.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double sqrt(double x)
{
	double y;
	double y1;

	/* Filter out invalid/trivial inputs */

	if (x < 0.0) {
		set_errno(EDOM);
		return NAN;
	}

	if (isnan(x)) {
		return NAN;
	}

	if (isinf(x)) {
		return INFINITY;
	}

	if (x == 0.0) {
		return 0.0;
	}

	/* Guess square root (using bit manipulation) */

	y = lib_sqrtapprox(x);

	/* Perform four iterations of approximation.  This number (4) is
	 * definitely optimal
	 */

	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);

	/* If guess was terribe (out of range of float).  Repeat approximation
	 * until convergence.
	 */

	if (y * y < x - 1.0 || y * y > x + 1.0) {
		y1 = -1.0;
		while (y != y1) {
			y1 = y;
			y = 0.5 * (y + x / y);
		}
	}

	return y;
}
#endif
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
/************************************************************************
 * libc/math/lib_sqrtf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>
#include <errno.h>

#include "lib_internal.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

float sqrtf(float x)
{
	float y;
	float y1;

	/* Filter out invalid/trivial inputs */

	if (x < 0.0) {
		set_errno(EDOM);
		return NAN;
	}

	if (isnan(x)) {
		return NAN;
	}

	if (isinf(x)) {
		return INFINITY;
	}

	if (x == 0.0) {
		return 0.0;
	}

	/* Guess square root (using bit manipulation) */

	y = lib_sqrtapprox(x);

	/* Perform four iterations of approximation. This number (4) is
	 * definitely optimal
	 */

	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);

	/* If guess was terribe (out of range of float). Repeat approximation
	 * until convergence.
	 */

	if (y * y < x - 1.0 || y * y > x + 1.0) {
		y1 = -1.0;
		while (y != y1) {
			y1 = y;
			y = 0.5 * (y + x / y);
		}
	}

	return y;
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
 * libc/math/lib_sqrtl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>
#include <errno.h>

#include "lib_internal.h"

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double sqrtl(long double x)
{
	long double y;
	long double y1;

	/* Filter out invalid/trivial inputs */

	if (x < 0.0) {
		set_errno(EDOM);
		return NAN;
	}

	if (isnan(x)) {
		return NAN;
	}

	if (isinf(x)) {
		return INFINITY;
	}

	if (x == 0.0) {
		return 0.0;
	}

	/* Guess square root (using bit manipulation) */

	y = lib_sqrtapprox(x);

	/* Perform four iterations of approximation.  This number (4) is
	 * definitely optimal
	 */

	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);
	y = 0.5 * (y + x / y);

	/* If guess was terribe (out of range of float).  Repeat approximation
	 * until convergence
	 */

	if (y * y < x - 1.0 || y * y > x + 1.0) {
		y1 = -1.0;
		while (y != y1) {
			y1 = y;
			y = 0.5 * (y + x / y);
		}
	}

	return y;
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
 * libc/math/lib_tan.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double tan(double x)
{
	return (sin(x) / cos(x));
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
 * libc/math/lib_tanf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float tanf(float x)
{
	return (sinf(x) / cosf(x));
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
 * libc/math/lib_tanh.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double tanh(double x)
{
	double x0 = exp(x);
	double x1 = 1.0 / x0;

	return ((x0 - x1) / (x0 + x1));
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
 * libc/math/lib_tanhf.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float tanhf(float x)
{
	float x0 = expf(x);
	float x1 = 1.0 / x0;

	return ((x0 - x1) / (x0 + x1));
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
 * libc/math/lib_tanhl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double tanhl(long double x)
{
	long double x0 = exp(x);
	long double x1 = 1.0 / x0;

	return ((x0 - x1) / (x0 + x1));
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
 * libc/math/lib_tanl.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Ported by: Darcy Gong
 *
 * It derives from the Rhombs OS math library by Nick Johnson which has
 * a compatibile, MIT-style license:
 *
 * Copyright (C) 2009, 2010 Nick Johnson <nickbjohnson4224 at gmail.com>
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
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
long double tanl(long double x)
{
	return (sinl(x) / cosl(x));
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
 * libc/math/lib_trunc.c
 *
 * This implementation is derived from the musl library under the MIT License
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
 ****************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <stdint.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_DOUBLE
double trunc(double x)
{
	union {
		double f;
		uint64_t i;
	} u = { x };
	int e = (int)(u.i >> 52 & 0x7ff) - 0x3ff + 12;
	uint64_t m;
	volatile float __x;

	if (e >= 52 + 12) {
		return x;
	}

	if (e < 12) {
		e = 1;
	}

	m = -1ull >> e;
	if ((u.i & m) == 0) {
		return x;
	}

	/* Force Evaluation */

	__x = (x + 0x1p120f);
	(void)__x;

	u.i &= ~m;
	return u.f;
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
 * libc/math/lib_truncf.c
 *
 * This implementation is derived from the musl library under the MIT License
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
 ****************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <stdint.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

float truncf(float x)
{
	union {
		float f;
		uint32_t i;
	} u = { x };
	int e = (int)(u.i >> 23 & 0xff) - 0x7f + 9;
	uint32_t m;
	volatile float __x;

	if (e >= 23 + 9) {
		return x;
	}

	if (e < 9) {
		e = 1;
	}

	m = -1u >> e;
	if ((u.i & m) == 0) {
		return x;
	}

	/* Force Eval */

	__x = (x + 0x1p120f);
	(void)__x;

	u.i &= ~m;
	return u.f;
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
 * libc/math/lib_truncl.c
 *
 * This implementation is derived from the musl library under the MIT License
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
 ****************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/compiler.h>

#include <stdint.h>
#include <float.h>
#include <math.h>

/************************************************************************
 * Public Functions
 ************************************************************************/

#ifdef CONFIG_HAVE_LONG_DOUBLE
static const long double toint = 1 / LDBL_EPSILON;

/* FIXME This will only work if long double is 64 bit and little endian */

union ldshape {
	long double f;
	struct {
		uint64_t m;
		uint16_t se;
	} i;
};

long double truncl(long double x)
{
	union ldshape u = { x };
	int e = u.i.se & 0x7fff;
	int s = u.i.se >> 15;
	long double y;
	volatile long double __x;

	if (e >= 0x3fff + LDBL_MANT_DIG - 1) {
		return x;
	}

	if (e <= 0x3fff - 1) {
		/* Force Eval */

		__x = (x + 0x1p120f);
		(void)__x;
		return x * 0;
	}

	/* y = int(|x|) - |x|, where int(|x|) is an integer neighbor of |x| */

	if (s) {
		x = -x;
	}

	y = x + toint - toint - x;
	if (y > 0) {
		y -= 1;
	}

	x += y;
	return s ? -x : x;
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
 * libc/math/__cos.c
 *
 * Ported to NuttX from FreeBSD by Alan Carvalho de Assis:
 *
 *   Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 *   Developed at SunSoft, a Sun Microsystems, Inc. business.
 *   Permission to use, copy, modify, and distribute this
 *   software is freely granted, provided that this notice
 *   is preserved.
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

/* __cos( x,  y )
 *
 * kernel cos function on [-pi/4, pi/4], pi/4 ~ 0.785398164
 * Input x is assumed to be bounded by ~pi/4 in magnitude.
 * Input y is the tail of x.
 *
 * Algorithm
 *      1. Since cos(-x) = cos(x), we need only to consider positive x.
 *      2. if x < 2^-27 (hx<0x3e400000 0), return 1 with inexact if x!=0.
 *      3. cos(x) is approximated by a polynomial of degree 14 on
 *         [0,pi/4]
 *                                       4            14
 *              cos(x) ~ 1 - x*x/2 + C1*x + ... + C6*x
 *         where the remez error is
 *
 *      |              2     4     6     8     10    12     14 |     -58
 *      |cos(x)-(1-.5*x +C1*x +C2*x +C3*x +C4*x +C5*x  +C6*x  )| <= 2
 *      |                                                      |
 *
 *                     4     6     8     10    12     14
 *      4. let r = C1*x +C2*x +C3*x +C4*x +C5*x  +C6*x  , then
 *             cos(x) ~ 1 - x*x/2 + r
 *         since cos(x+y) ~ cos(x) - sin(x)*y
 *                        ~ cos(x) - x*y,
 *         a correction term is necessary in cos(x) and hence
 *              cos(x+y) = 1 - (x*x/2 - (r - x*y))
 *         For better accuracy, rearrange to
 *              cos(x+y) ~ w + (tmp + (r-x*y))
 *         where w = 1 - x*x/2 and tmp is a tiny correction term
 *         (1 - x*x/2 == w + tmp exactly in infinite precision).
 *         The exactness of w + tmp in infinite precision depends on w
 *         and tmp having the same precision as x.  If they have extra
 *         precision due to compiler bugs, then the extra precision is
 *         only good provided it is retained in all terms of the final
 *         expression for cos().  Retention happens in all cases tested
 *         under FreeBSD, so don't pessimize things by forcibly clipping
 *         any extra precision in w.
 */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <sys/types.h>
#include <math.h>

#ifdef CONFIG_HAVE_DOUBLE

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const double g_c1 = 4.16666666666666019037e-02;	/* 0x3fa55555, 0x5555554c */
static const double g_c2 = -1.38888888888741095749e-03;	/* 0xbf56C16c, 0x16c15177 */
static const double g_c3 = 2.48015872894767294178e-05;	/* 0x3efa01a0, 0x19cb1590 */
static const double g_c4 = -2.75573143513906633035e-07;	/* 0xbe927e4e, 0x809c52ad */
static const double g_c5 = 2.08757232129817482790e-09;	/* 0x3e21ee9E, 0xbdb4b1c4 */
static const double g_c6 = -1.13596475577881948265e-11;	/* 0xbda8fae9, 0xbe8838d4 */

/****************************************************************************
 * Public Functions
 ****************************************************************************/

double __cos(double x, double y)
{
	double hz;
	double z;
	double r;
	double w;

	z = x * x;
	w = z * z;
	r = z * (g_c1 + z * (g_c2 + z * g_c3)) + w * w * (g_c4 + z * (g_c5 + z * g_c6));
	hz = 0.5 * z;
	w = 1.0 - hz;

	return w + (((1.0 - w) - hz) + (z * r - x * y));
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
 * libc/math/__cos.c
 *
 * Ported to NuttX from FreeBSD by Alan Carvalho de Assis:
 *
 *   Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 *   Developed at SunSoft, a Sun Microsystems, Inc. business.
 *   Permission to use, copy, modify, and distribute this
 *   software is freely granted, provided that this notice
 *   is preserved.
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

/* __sin( x, y, iy)
 *
 * kernel sin function on ~[-pi/4, pi/4] (except on -0), pi/4 ~ 0.7854
 * Input x is assumed to be bounded by ~pi/4 in magnitude.
 * Input y is the tail of x.
 * Input iy indicates whether y is 0. (if iy=0, y assume to be 0).
 *
 * Algorithm
 *      1. Since sin(-x) = -sin(x), we need only to consider positive x.
 *      2. Callers must return sin(-0) = -0 without calling here since our
 *         odd polynomial is not evaluated in a way that preserves -0.
 *         Callers may do the optimization sin(x) ~ x for tiny x.
 *      3. sin(x) is approximated by a polynomial of degree 13 on
 *         [0,pi/4]
 *                               3            13
 *              sin(x) ~ x + S1*x + ... + S6*x
 *         where
 *
 *      |sin(x)         2     4     6     8     10     12  |     -58
 *      |----- - (1+S1*x +S2*x +S3*x +S4*x +S5*x  +S6*x   )| <= 2
 *      |  x                                               |
 *
 *      4. sin(x+y) = sin(x) + sin'(x')*y
 *                  ~ sin(x) + (1-x*x/2)*y
 *         For better accuracy, let
 *                   3      2      2      2      2
 *              r = x *(S2+x *(S3+x *(S4+x *(S5+x *S6))))
 *         then                   3    2
 *              sin(x) = x + (S1*x + (x *(r-y/2)+y))
 */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <sys/types.h>
#include <math.h>

#ifdef CONFIG_HAVE_DOUBLE

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const double g_s1 = -1.66666666666666324348e-01;	/* 0xbfc55555, 0x55555549 */
static const double g_s2 = 8.33333333332248946124e-03;	/* 0x3f811111, 0x1110f8a6 */
static const double g_s3 = -1.98412698298579493134e-04;	/* 0xbf2a01a0, 0x19c161d5 */
static const double g_s4 = 2.75573137070700676789e-06;	/* 0x3ec71de3, 0x57b1fe7d */
static const double g_s5 = -2.50507602534068634195e-08;	/* 0xbe5ae5e6, 0x8a2b9ceb */
static const double g_s6 = 1.58969099521155010221e-10;	/* 0x3de5d93a, 0x5acfd57c */

/****************************************************************************
 * Public Functions
 ****************************************************************************/

double __sin(double x, double y, int iy)
{
	double z;
	double r;
	double v;
	double w;

	z = x * x;
	w = z * z;
	r = g_s2 + z * (g_s3 + z * g_s4) + z * w * (g_s5 + z * g_s6);
	v = z * x;

	if (iy == 0) {
		return x + v * (g_s1 + z * r);
	} else {
		return x - ((z * (0.5 * y - v * r) - y) - v * g_s1);
	}
}
#endif
   