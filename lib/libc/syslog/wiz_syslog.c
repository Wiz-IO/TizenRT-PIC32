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
 * lib/syslog/lib_lowsyslog.c
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
#include <syslog.h>

#include <tinyara/streams.h>
#if defined(CONFIG_LOGM) && defined(CONFIG_SYSLOG2LOGM)
#include <tinyara/logm.h>
#endif
#include "syslog/syslog.h"

#if defined(CONFIG_ARCH_LOWPUTC) || defined(CONFIG_SYSLOG)

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
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lowvsyslog_internal
 *
 * Description:
 *   This is the internal implementation of lowvsyslog (see the description
 *   of lowsyslog and lowvsyslog below)
 *
 ****************************************************************************/

static inline int lowvsyslog_internal(FAR const char *fmt, va_list ap)
{
	struct lib_outstream_s stream;

	/* Wrap the stdout in a stream object and let lib_vsprintf do the work. */
#if defined(CONFIG_SYSLOG)
	lib_syslogstream((FAR struct lib_outstream_s *)&stream);
#else
	lib_lowoutstream((FAR struct lib_outstream_s *)&stream);
#endif
	return lib_vsprintf((FAR struct lib_outstream_s *)&stream, fmt, ap);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lowvsyslog
 *
 * Description:
 *   The function lowvsyslog() performs the same task as lowsyslog() with
 *   the difference that it takes a set of arguments which have been
 *   obtained using the stdarg variable argument list macros.
 *
 ****************************************************************************/

int lowvsyslog(int priority, FAR const char *fmt, va_list ap)
{
	int ret = 0;

	/* Check if this priority is enabled */

	if ((g_syslog_mask & LOG_MASK(priority)) != 0) {
		/* Yes.. let vsylog_internal to the deed */
#if defined(CONFIG_LOGM) && defined(CONFIG_SYSLOG2LOGM)
		ret = logm_internal(LOGM_LOWPUT, LOGM_UNKNOWN, priority, fmt, ap);
#else
		ret = lowvsyslog_internal(fmt, ap);
#endif
	}
	return ret;
}

/****************************************************************************
 * Name: lowsyslog
 *
 * Description:
 *   syslog() generates a log message. The priority argument is formed by
 *   ORing the facility and the level values (see include/syslog.h). The
 *   remaining arguments are a format, as in printf and any arguments to the
 *   format.
 *
 *   This is a non-standard, low-level system logging interface.  The
 *   difference between syslog() and lowsyslog() is that the syslog()
 *   interface writes to the syslog device (usually fd=1, stdout) whereas
 *   lowsyslog() uses a lower level interface that works even from interrupt
 *   handlers.
 *
 ****************************************************************************/

int lowsyslog(int priority, FAR const char *fmt, ...)
{
	va_list ap;
	int ret;
	va_start(ap, fmt);

	/* Let lowvsyslog do the work */
	ret = lowvsyslog(priority, fmt, ap);

	va_end(ap);

	return ret;
}

#endif							/* CONFIG_ARCH_LOWPUTC || CONFIG_SYSLOG */
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
 * lib/syslog/lib_setlogmask.c
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

#include <stdint.h>
#include <syslog.h>

#include <arch/irq.h>

#include "syslog/syslog.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* The currently enabled set of syslog priorities */

uint8_t g_syslog_mask = LOG_ALL;

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: setlogmask
 *
 * Description:
 *   The setlogmask() function sets the logmask and returns the previous
 *   mask. If the mask argument is 0, the current logmask is not modified.
 *
 *   The SYSLOG priorities are: LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR,
 *   LOG_WARNING, LOG_NOTICE, LOG_INFO, and LOG_DEBUG.  The bit corresponding
 *   to a priority p is LOG_MASK(p); LOG_UPTO(p) provides the mask of all
 *   priorities in the above list up to and including p.
 *
 *   REVISIT: Per POSIX the syslog mask should be a per-process value but in
 *   TinyAra, the scope of the mask is dependent on the nature of the build.
 *
 *   Flat Build:  There is one, global SYSLOG mask that controls all output.
 *   Protected Build:  There are two SYSLOG masks.  One within the kernel
 *     that controls only kernel output.  And one in user-space that controls
 *     only user SYSLOG output.
 *   Kernel Build:  The kernel build is compliant with the POSIX requirement:
 *     There will be one mask for for each user process, controlling the
 *     SYSLOG output only form that process.  There will be a separate mask
 *     accessable only in the kernel code to control kernel SYSLOG output.
 *
 ****************************************************************************/

int setlogmask(int mask)
{
	uint8_t oldmask;
	irqstate_t flags;

	/* These operations must be exclusive with respect to other threads as well
	 * as interrupts.
	 */

	flags = irqsave();

	oldmask = g_syslog_mask;
	g_syslog_mask = (uint8_t)mask;

	irqrestore(flags);
	return oldmask;
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
 * libc/syslog/lib_syslog.c
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

#include <stdio.h>
#include <syslog.h>

#include <tinyara/clock.h>
#include <tinyara/streams.h>
#if defined(CONFIG_LOGM) && defined(CONFIG_SYSLOG2LOGM)
#include <tinyara/logm.h>
#endif
#include "syslog/syslog.h"

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
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: vsyslog_internal
 *
 * Description:
 *   This is the internal implementation of vsyslog (see the description of
 *   syslog and vsyslog below)
 *
 ****************************************************************************/

static inline int vsyslog_internal(FAR const char *fmt, va_list ap)
{
#if defined(CONFIG_SYSLOG)
	struct lib_outstream_s stream;
#elif CONFIG_NFILE_DESCRIPTORS > 0
	struct lib_rawoutstream_s stream;
#elif defined(CONFIG_ARCH_LOWPUTC)
	struct lib_outstream_s stream;
#endif

#if defined(CONFIG_SYSLOG_TIMESTAMP)
	struct timespec ts;
	int ret;

	/* Get the current time */

	ret = clock_systimespec(&ts);
#endif

#if defined(CONFIG_SYSLOG)
	/* Wrap the low-level output in a stream object and let lib_vsprintf
	 * do the work.
	 */

	lib_syslogstream((FAR struct lib_outstream_s *)&stream);

#if defined(CONFIG_SYSLOG_TIMESTAMP)
	/* Pre-pend the message with the current time */

	if (ret == OK) {
		(void)lib_sprintf((FAR struct lib_outstream_s *)&stream, "[%6d.%06d]", ts.tv_sec, ts.tv_nsec / 1000);
	}
#endif

	return lib_vsprintf((FAR struct lib_outstream_s *)&stream, fmt, ap);

#elif CONFIG_NFILE_DESCRIPTORS > 0
	/* Wrap the stdout in a stream object and let lib_vsprintf
	 * do the work.
	 */

	lib_rawoutstream(&stream, 1);

#if defined(CONFIG_SYSLOG_TIMESTAMP)
	/* Pre-pend the message with the current time */

	if (ret == OK) {
		(void)lib_sprintf((FAR struct lib_outstream_s *)&stream, "[%6d.%06d]", ts.tv_sec, ts.tv_nsec / 1000);
	}
#endif

	return lib_vsprintf(&stream.public, fmt, ap);

#elif defined(CONFIG_ARCH_LOWPUTC)
	/* Wrap the low-level output in a stream object and let lib_vsprintf
	 * do the work.
	 */

	lib_lowoutstream((FAR struct lib_outstream_s *)&stream);

#if defined(CONFIG_SYSLOG_TIMESTAMP)
	/* Pre-pend the message with the current time */

	if (ret == OK) {
		(void)lib_sprintf((FAR struct lib_outstream_s *)&stream, "[%6d.%06d]", ts.tv_sec, ts.tv_nsec / 1000);
	}
#endif

	return lib_vsprintf((FAR struct lib_outstream_s *)&stream, fmt, ap);

#else							/* CONFIG_SYSLOG */
	return 0;
#endif							/* CONFIG_SYSLOG */
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: vsyslog
 *
 * Description:
 *   The function vsyslog() performs the same task as syslog() with the
 *   difference that it takes a set of arguments which have been obtained
 *   using the stdarg variable argument list macros.
 *
 ****************************************************************************/

int vsyslog(int priority, FAR const char *fmt, va_list ap)
{
	int ret = 0;

	/* Check if this priority is enabled */

	if ((g_syslog_mask & LOG_MASK(priority)) != 0) {
		/* Yes.. let vsylog_internal do the deed */
#if defined(CONFIG_LOGM) && defined(CONFIG_SYSLOG2LOGM)
		ret = logm_internal(LOGM_NORMAL, LOGM_UNKNOWN, priority, fmt, ap);
#else
		ret = vsyslog_internal(fmt, ap);
#endif
	}

	return ret;
}

/****************************************************************************
 * Name: syslog
 *
 * Description:
 *   syslog() generates a log message. The priority argument is formed by
 *   ORing the facility and the level values (see include/syslog.h). The
 *   remaining arguments are a format, as in printf and any arguments to the
 *   format.
 *
 *   The TinyAra implementation does not support any special formatting
 *   characters beyond those supported by printf.
 *
 ****************************************************************************/

int syslog(int priority, FAR const char *fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap, fmt);
	ret = vsyslog(priority, fmt, ap);
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
 * libc/syslog/lib_syslogstream.c
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
#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/syslog/syslog.h>
#include <tinyara/streams.h>

#include "syslog/syslog.h"

#ifdef CONFIG_SYSLOG

/****************************************************************************
 * Pre-processor definition
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslogstream_putc
 ****************************************************************************/

static void syslogstream_putc(FAR struct lib_outstream_s *this, int ch)
{
	int ret;

	/* Try writing until the write was successful or until an irrecoverable
	 * error occurs.
	 */

	do {
		/* Write the character to the supported logging device.  On failure,
		 * syslog_putc returns EOF with the errno value set;
		 */

		ret = syslog_putc(ch);
		if (ret != EOF) {
			this->nput++;
			return;
		}

		/* The special errno value -EINTR means that syslog_putc() was
		 * awakened by a signal.  This is not a real error and must be
		 * ignored in this context.
		 */
	} while (errno == -EINTR);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_syslogstream
 *
 * Description:
 *   Initializes a stream for use with the configured syslog interface.
 *
 * Input parameters:
 *   lowoutstream - User allocated, uninitialized instance of struct
 *                  lib_lowoutstream_s to be initialized.
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void lib_syslogstream(FAR struct lib_outstream_s *stream)
{
	stream->put = syslogstream_putc;
#ifdef CONFIG_STDIO_LINEBUFFER
	stream->flush = lib_noflush;
#endif
	stream->nput = 0;
}

#endif							/* CONFIG_SYSLOG */
   