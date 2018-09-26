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
 * lib/unistd/lib_access.c
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

#include <unistd.h>

/****************************************************************************
 * Preprocessor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Type Definitions
 ****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: access
 *
 * Description:
 *   The access() function shall check the file named by the pathname pointed
 *   to by the path argument for accessibility according to the bit pattern
 *   contained in amode, using the real user ID in place of the effective user
 *   ID and the real group ID in place of the effective group ID.
 *   As there are no users in NuttX, the function always succeeds.
 *
 * Parameters:
 *   path - a pointer to the path
 *   amode - the access mode
 *
 * Returned Value:
 *   Always OK (zero)
 *
 * Assumptions:
 *
 ****************************************************************************/

int access(FAR const char *path, int amode)
{
	return 0;
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
 * libc/unistd/lib_chdir.c
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

#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "lib_internal.h"

#if CONFIG_NFILE_DESCRIPTORS > 0 && !defined(CONFIG_DISABLE_ENVIRON)

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: _trimdir
 ****************************************************************************/

#if 0
static inline void _trimdir(char *path)
{
	/* Skip any trailing '/' characters (unless it is also the leading '/') */

	int len = strlen(path) - 1;
	while (len > 0 && path[len] == '/') {
		path[len] = '\0';
		len--;
	}
}
#else
#define _trimdir(p)
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: chdir
 *
 * Description:
 *   The chdir() function causes the directory named by the pathname pointed
 *   to by the 'path' argument to become the current working directory; that
 *   is, the starting point for path searches for pathnames not beginning
 *   with '/'.
 *
 * Input Parmeters:
 *   path - A pointer to a directory to use as the new current working
 *     directory
 *
 * Returned Value:
 *   0(OK) on success; -1(ERROR) on failure with errno set appropriately:
 *
 *   EACCES
 *     Search permission is denied for any component of the pathname.
 *   ELOOP
 *     A loop exists in symbolic links encountered during resolution of the
 *     'path' argument OR more that SYMLOOP_MAX symbolic links in the
 *     resolution of the 'path' argument.
 *   ENAMETOOLONG
 *     The length of the path argument exceeds PATH_MAX or a pathname component
 *     is longer than NAME_MAX.
 *   ENOENT
 *     A component of 'path' does not name an existing directory or path is
 *     an empty string.
 *   ENOTDIR
 *     A component of the pathname is not a directory.
 *
 ****************************************************************************/

int chdir(FAR const char *path)
{
	struct stat buf;
	char *oldpwd;
	char *alloc;
	int err;
	int ret;

	/* Verify the input parameters */

	if (!path) {
		err = ENOENT;
		goto errout;
	}

	/* Verify that 'path' refers to a directory */

	ret = stat(path, &buf);
	if (ret != 0) {
		err = ENOENT;
		goto errout;
	}

	/* Something exists here... is it a directory? */

	if (!S_ISDIR(buf.st_mode)) {
		err = ENOTDIR;
		goto errout;
	}

	/* Yes, it is a directory. Remove any trailing '/' characters from the path */

	_trimdir(path);

	/* Replace any preceding OLDPWD with the current PWD (this is to
	 * support 'cd -' in TASH)
	 */

	sched_lock();
	oldpwd = getenv("PWD");
	if (!oldpwd) {
		oldpwd = CONFIG_LIB_HOMEDIR;
	}

	alloc = strdup(oldpwd);		/* kludge needed because environment is realloc'ed */
	setenv("OLDPWD", alloc, TRUE);
	lib_free(alloc);

	/* Set the cwd to the input 'path' */

	setenv("PWD", path, TRUE);
	sched_unlock();
	return OK;

errout:
	set_errno(err);
	return ERROR;
}
#endif							/* CONFIG_NFILE_DESCRIPTORS && !CONFIG_DISABLE_ENVIRON */
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
 * libc/unistd/lib_execl.c
 *
 *   Copyright (C) 2013, 2015 Gregory Nutt. All rights reserved.
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

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#ifdef CONFIG_LIBC_EXECFUNCS

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* This is an artificial limit to detect error conditions where an argv[]
 * list is not properly terminated.
 */

#define MAX_EXECL_ARGS 256

/****************************************************************************
 * Global Variables
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Global Functions
 ****************************************************************************/

/****************************************************************************
 * Name: execl
 *
 * Description:
 *   The standard 'exec' family of functions will replace the current process
 *   image with a new process image. The new image will be constructed from a
 *   regular, executable file called the new process image file. There will
 *   be no return from a successful exec, because the calling process image
 *   is overlaid by the new process image.
 *
 *   Simplified 'execl()' and 'execv()' functions are provided by TinyAra for
 *   compatibility.  TinyAra is a tiny embedded RTOS that does not support
 *   processes and hence the concept of overlaying a tasks process image with
 *   a new process image does not make any sense.  In TinyAra, these functions
 *   are wrapper functions that:
 *
 *     1. Call the non-standard binfmt function 'exec', and then
 *     2. exit(0).
 *
 *   Note the inefficiency when 'exec[l|v]()' is called in the normal, two-
 *   step process:  (1) first call vfork() to create a new thread, then (2)
 *   call 'exec[l|v]()' to replace the new thread with a program from the
 *   file system.  Since the new thread will be terminated by the
 *   'exec[l|v]()' call, it really served no purpose other than to support
 *   Unix compatility.
 *
 *   The non-standard binfmt function 'exec()' needs to have (1) a symbol
 *   table that provides the list of symbols exported by the base code, and
 *   (2) the number of symbols in that table.  This information is currently
 *   provided to 'exec()' from 'exec[l|v]()' via TinyAra configuration settings:
 *
 *     CONFIG_LIBC_EXECFUNCS     : Enable exec[l|v] support
 *     CONFIG_EXECFUNCS_SYMTAB   : Symbol table used by exec[l|v]
 *     CONFIG_EXECFUNCS_NSYMBOLS : Number of symbols in the table
 *
 *   As a result of the above, the current implementations of 'execl()' and
 *   'execv()' suffer from some incompatibilities that may or may not be
 *   addressed in a future version of TinyAra.  Other than just being an
 *   inefficient use of MCU resource, the most serious of these is that
 *   the exec'ed task will not have the same task ID as the vfork'ed
 *   function.  So the parent function cannot know the ID of the exec'ed
 *   task.
 *
 * Input Parameters:
 *   path - The path to the program to be executed.  If CONFIG_BINFMT_EXEPATH
 *     is defined in the configuration, then this may be a relative path
 *     from the current working directory.  Otherwise, path must be the
 *     absolute path to the program.
 *   ... - A list of the string arguments to be recevied by the
 *     program.  Zero indicates the end of the list.
 *
 * Returned Value:
 *   This function does not return on success.  On failure, it will return
 *   -1 (ERROR) and will set the 'errno' value appropriately.
 *
 ****************************************************************************/

int execl(FAR const char *path, ...)
{
	FAR char **argv = (FAR char **)NULL;
	FAR char *arg;
	size_t nargs;
	va_list ap;
	int argc;
	int ret;

	/* Count the number of arguments */

	va_start(ap, path);
	nargs = 0;
	do {
		/* Check if the next argument is present */

		arg = va_arg(ap, FAR char *);
		if (arg) {
			/* Yes.. increment the number of arguments.  Here is a sanity
			 * check to prevent running away with an unterminated argv[] list.
			 * MAX_EXECL_ARGS should be sufficiently large that this never
			 * happens in normal usage.
			 */

			if (++nargs > MAX_EXECL_ARGS) {
				set_errno(E2BIG);
				va_end(ap);
				return ERROR;
			}
		}
	} while (arg);

	va_end(ap);

	/* Allocate a temporary argv[] array */

	if (nargs > 0) {
		argv = (FAR char **)malloc((nargs + 1) * sizeof(FAR char *));
		if (argv == (FAR char **)NULL) {
			set_errno(ENOMEM);
			return ERROR;
		}

		/* Collect the arguments into the argv[] array */

		va_start(ap, path);
		for (argc = 0; argc < nargs; argc++) {
			argv[argc] = va_arg(ap, FAR char *);
		}

		argv[nargs] = NULL;
		va_end(ap);
	}

	/* Then let execv() do the real work */

	ret = execv(path, (FAR char *const *)argv);

	/* Free the allocated argv[] list */

	if (argv) {
		free(argv);
	}

	return ret;
}

#endif							/* CONFIG_LIBC_EXECFUNCS */
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
 * libc/unistd/lib_getcwd.c
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

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "lib_internal.h"

#if CONFIG_NFILE_DESCRIPTORS > 0 && !defined(CONFIG_DISABLE_ENVIRON)

/****************************************************************************
 * Name: getwcd
 *
 * Description:
 *   getcwd() function places the absolute pathname of the current working
 *   directory in the array pointed to by 'buf', and returns 'buf.' The
 *   pathname copied to the array shall contain no components that are
 *   symbolic links. The 'size' argument is the size in bytes of the
 *   character array pointed to by the 'buf' argument.
 *
 * Input Parmeters:
 *   buf - a pointer to the location in which the current working directory
 *     pathaname is returned.
 *   size - The size in bytes avaiable at 'buf'
 *
 * Returned Value:
 *   Upon successful completion, getcwd() returns the 'buf' argument.
 *   Otherwise, getcwd() returns a null pointer and sets errno to indicate
 *   the error:
 *
 *   EINVAL
 *     The 'size' argument is 0 or the 'buf' argument is NULL.
 *   ERANGE
 *     The size argument is greater than 0, but is smaller than the length
 *     of the currrent working directory pathname +1.
 *   EACCES
 *     Read or search permission was denied for a component of the pathname.
 *   ENOMEM
 *  Insufficient storage space is available.
 *
 ****************************************************************************/

FAR char *getcwd(FAR char *buf, size_t size)
{
	char *pwd;

	/* Verify input parameters */

#ifdef CONFIG_DEBUG
	if (!buf || !size) {
		set_errno(EINVAL);
		return NULL;
	}
#endif

	/* If no working directory is defined, then default to the home directory */

	pwd = getenv("PWD");
	if (!pwd) {
		pwd = CONFIG_LIB_HOMEDIR;
	}

	/* Verify that the cwd will fit into the user-provided buffer */

	if (strlen(pwd) + 1 > size) {
		set_errno(ERANGE);
		return NULL;
	}

	/* Copy the cwd to the user buffer */

	strcpy(buf, pwd);
	sched_unlock();
	return buf;
}
#endif							/* CONFIG_NFILE_DESCRIPTORS && !CONFIG_DISABLE_ENVIRON */
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
 * libc/unistd/lib_getopt.c
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

#include <tinyara/config.h>

#include <stdbool.h>
#include <unistd.h>
#include <string.h>

FAR char *optarg;				/* Optional argument following option */
int optind = 1;					/* Index into argv */
int optopt = '?';				/* unrecognized option character */

static FAR char *g_optptr = NULL;
static bool g_binitialized = false;

/****************************************************************************
 * Name: getopt
 *
 * Description: getopt() parses command-line arguments.  Its arguments argc
 *   and argv are the argument count and array as passed to the main()
 *   function on program invocation.  An element of argv that starts with
 *   '-' is an option element. The characters of this element (aside from
 *   the initial '-') are option characters. If getopt() is called repeatedly,
 *   it returns successively each of the option characters from each of the
 *   option elements.
 *
 *   If getopt() finds another option character, it returns that character,
 *   updating the external variable optind and a static variable nextchar so
 *   that the next call to getopt() can resume the scan with the following
 *   option character or argv-element.
 *
 *   If there are no more option characters, getopt() returns -1. Then optind
 *   is the index in argv of the first argv-element that is not an option.
 *
 *   The 'optstring' argument is a string containing the legitimate option
 *   characters. If such a character is followed by a colon, this indicates
 *   that the option requires an argument.  If an argument is required for an
 *   option so getopt() places a pointer to the following text in the same
 *   argv-element, or the text of the following argv-element, in optarg.
 *
 *   NOTES:
 *   1. opterr is not supported and this implementation of getopt() never
 *      printfs error messages.
 *   2. getopt is NOT threadsafe!
 *   3. This version of getopt() does not reset global variables until
 *      -1 is returned.  As a result, your command line parsing loops
 *      must call getopt() repeatedly and continue to parse if other
 *      errors are returned ('?' or ':') until getopt() finally returns -1.
 *     (You can also set optind to -1 to force a reset).
 *
 * Return: If an option was successfully found, then getopt() returns the
 *   option character. If all command-line options have been parsed, then
 *   getopt() returns -1.  If getopt() encounters an option character that
 *   was not in optstring, then '?' is returned. If getopt() encounters an
 *   option with a missing argument, then the return value depends on the
 *   first character in optstring: if it is ':', then ':' is returned;
 *   otherwise '?' is returned.
 *
 ****************************************************************************/

int getopt(int argc, FAR char *const argv[], FAR const char *optstring)
{
	if (argv && optstring && argc > 1) {
		int noarg_ret = '?';
		char *optchar;

		/* The inital value of optind is 1.  If getopt() is called again in the
		 * program, optind must be reset to some value <= 1.
		 */

		if (optind < 1 || !g_binitialized) {
			optind = 1;			/* Skip over the program name */
			g_optptr = NULL;	/* Start at the beginning of the first argument */
			g_binitialized = true;	/* Now we are initialized */
		}

		/* If the first character of opstring s ':', then ':' is in the event of
		 * a missing argument. Otherwise '?' is returned.
		 */

		if (*optstring == ':') {
			noarg_ret = ':';
			optstring++;
		}

		/* Are we resuming in the middle, or at the end of a string of arguments?
		 * g_optptr == NULL means that we are started at the beginning of argv[optind];
		 * *g_optptr == \0 means that we are starting at the beginning of optind+1
		 */

		while (!g_optptr || !*g_optptr) {
			/* We need to start at the beginning of the next argv. Check if we need
			 * to increment optind
			 */

			if (g_optptr) {
				/* Yes.. Increment it and check for the case where where we have
				 * processed everything in the argv[] array.
				 */

				optind++;
			}

			/* Check for the end of the argument list */

			if (optind >= argc) {
				g_binitialized = false;
				return ERROR;
			}

			g_optptr = argv[optind];
			if (!g_optptr) {
				/* There are no more arguments, we are finished */

				g_binitialized = false;
				return ERROR;
			}

			/* We are starting at the beginning of argv[optind].  In this case, the
			 * first character must be '-'
			 */

			if (*g_optptr != '-') {
				/* The argument does not start with '-', we are finished */

				g_binitialized = false;
				return ERROR;
			}

			/* Skip over the '-' */

			g_optptr++;
		}

		/* Special case handling of "-" and "-:" */

		if (!*g_optptr) {
			optopt = '\0';		/* We'll fix up g_optptr the next time we are called */
			return '?';
		}

		/* Handle the case of "-:" */

		if (*g_optptr == ':') {
			optopt = ':';
			g_optptr++;
			return '?';
		}

		/* g_optptr now points at the next option and it is not something crazy.
		 * check if the option is in the list of valid options.
		 */

		optchar = strchr(optstring, *g_optptr);
		if (!optchar) {
			/* No this character is not in the list of valid options */

			optopt = *g_optptr;
			g_optptr++;
			return '?';
		}

		/* Yes, the character is in the list of valid options.  Does it have an
		 * required argument?
		 */

		if (optchar[1] != ':') {
			/* No, no arguments. Just return the character that we found */

			g_optptr++;
			return *optchar;
		}

		/* Yes, it has a required argument.  Is the required argument
		 * immediately after the command in this same argument?
		 */

		if (g_optptr[1] != '\0') {
			/* Yes, return a pointer into the current argument */

			optarg = &g_optptr[1];
			optind++;
			g_optptr = NULL;
			return *optchar;
		}

		/* No.. is the optional argument the next argument in argv[] ? */

		if (argv[optind + 1] && *argv[optind + 1] != '-') {
			/* Yes.. return that */

			optarg = argv[optind + 1];
			optind += 2;
			g_optptr = NULL;
			return *optchar;
		}

		/* No argument was supplied */

		g_optptr = NULL;
		optarg = NULL;
		optopt = *optchar;
		optind++;
		return noarg_ret;
	}

	/* Restore the initial, uninitialized state */

	g_binitialized = false;
	optind = 1;
	optopt = '?';
	return ERROR;
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
 * libc/unistd/lib_getoptargp.c
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

#include <tinyara/config.h>

#include <unistd.h>

/****************************************************************************
 * Name: getoptargp
 *
 * Description:
 *   Returns a pointer to optarg.  This function is only used for external
 *   modules that need to access the base, global variable, optarg.
 *
 ****************************************************************************/

FAR char **getoptargp(void)
{
	return &optarg;
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
 * libc/unistd/lib_getoptindp.c
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

#include <tinyara/config.h>

#include <unistd.h>

/****************************************************************************
 * Name: getoptindp
 *
 * Description:
 *   Returns a pointer to optind.  This function is only used for external
 *   modules that need to access the base, global variable, optind.
 *
 ****************************************************************************/

int *getoptindp(void)
{
	return &optind;
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
 * libc/unistd/lib_getoptoptp.c
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

#include <unistd.h>


/****************************************************************************
 * Name: getoptoptp
 *
 * Description:
 *   Returns a pointer to optopt.  This function is only used for external
 *   modules that need to access the base, global variable, optopt.
 *
 ****************************************************************************/

int *getoptoptp(void)
{
	return &optopt;
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
 * lib/lib_sleep.c
 *
 *   Copyright (C) 2007, 2009, 2012-2013 Gregory Nutt. All rights reserved.
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

#include <tinyara/config.h>

#include <unistd.h>
#include <signal.h>

#include <tinyara/clock.h>
#include <arch/irq.h>

/****************************************************************************
 * Name: sleep
 *
 * Description:
 *   The sleep() function will cause the calling thread to be suspended from
 *   execution until either the number of real-time seconds specified by the
 *   argument 'seconds' has elapsed or a signal is delivered to the calling
 *   thread and its action is to invoke a signal-catching function or to
 *   terminate the process. The suspension time may be longer than requested
 *   due to the scheduling of other activity by the system.
 *
 *   If a SIGALRM signal is generated for the calling process during
 *   execution of sleep() and if the SIGALRM signal is being ignored or
 *   blocked from delivery, it is unspecified whether sleep() returns
 *   when the SIGALRM signal is scheduled. If the signal is being blocked, it
 *   is also unspecified whether it remains pending after sleep() returns or
 *   it is discarded.
 *
 *   If a SIGALRM signal is generated for the calling process during
 *   execution of sleep(), except as a result of a prior call to alarm(),
 *   and if the SIGALRM signal is not being ignored or blocked from delivery,
 *   it is unspecified whether that signal has any effect other than causing
 *   sleep() to return.
 *
 *   If a signal-catching function interrupts sleep() and examines or changes
 *   either the time a SIGALRM is scheduled to be generated, the action
 *   associated with the SIGALRM signal, or whether the SIGALRM signal is
 *   blocked from delivery, the results are unspecified.
 *
 *   If a signal-catching function interrupts sleep() and calls siglongjmp()
 *   or longjmp() to restore an environment saved prior to the sleep() call,
 *   the action associated with the SIGALRM signal and the time at which a
 *   SIGALRM signal is scheduled to be generated are unspecified. It is also
 *   unspecified whether the SIGALRM signal is blocked, unless the process'
 *   signal mask is restored as part of the environment.
 *
 *   Implementations may place limitations on the granularity of timer values.
 *   For each interval timer, if the requested timer value requires a finer
 *   granularity than the implementation supports, the actual timer value will
 *   be rounded up to the next supported value.
 *
 *   Interactions between sleep() and any of setitimer(), ualarm() or sleep()
 *   are unspecified.
 *
 * Parameters:
 *   seconds
 *
 * Returned Value:
 *   If sleep() returns because the requested time has elapsed, the value
 *   returned will be 0. If sleep() returns because of premature arousal due
 *   to delivery of a signal, the return value will be the "unslept" amount
 *   (the requested time minus the time actually slept) in seconds.
 *
 * Assumptions:
 *
 ****************************************************************************/

unsigned int sleep(unsigned int seconds)
{
	struct timespec rqtp;
	struct timespec rmtp;
	unsigned int remaining = 0;
	int ret;

	/* Don't sleep if seconds == 0 */

	if (seconds) {
		/* Let nanosleep() do all of the work. */

		rqtp.tv_sec = seconds;
		rqtp.tv_nsec = 0;

		ret = nanosleep(&rqtp, &rmtp);

		/* nanosleep() should only fail if it was interrupted by a signal,
		 * but we treat all errors the same,
		 */

		if (ret < 0) {
			remaining = rmtp.tv_sec;
			if (remaining < seconds && rmtp.tv_nsec >= 500000000) {
				/* Round up */

				remaining++;
			}
		}

		return remaining;
	}

	return 0;
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
 * lib/libc/unistd/lib_swab.c
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

#include <tinyara/config.h>

#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

/****************************************************************************
 * Name: strncpy
 *
 * Description:
 *   The swab() function will copy nbytes bytes, which are pointed to by
 *   'src', to the object pointed to by 'dest', exchanging adjacent bytes.
 *   The 'nbytes' argument should be even. If 'nbytes' is odd, swab() copies
 *   and exchanges 'nbytes'-1 bytes and the disposition of the last byte is
 *   unspecified. If copying takes place between objects that overlap, the
 *   behavior is undefined. If nbytes is negative, swab() does nothing.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void swab(FAR const void *src, FAR void *dest, ssize_t nbytes)
{
	FAR const uint8_t *src8 = (FAR const uint8_t *)src;
	FAR uint8_t *dest8 = (FAR uint8_t *) dest;
	FAR uint8_t *end8;

	DEBUGASSERT(src != NULL && dest != NULL);

	/* Do nother if nbytes is negative or it there are few then 2 bytes to be
	 * transferred.
	 */

	if (nbytes > 1) {
		/* The end of dest buffer + 1 byte (skipping any odd numbered byte at
		 * the end of the buffer.
		 */

		end8 = dest8 + (nbytes & ~1);

		/* Loop until the destination is equal to the end + 1 address */

		while (dest8 != end8) {
			register uint8_t tmp;

			/* Transfer the bytes, swapping the order */

			tmp = *src8++;
			*dest8++ = *src8++;
			*dest8++ = tmp;
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
 * lib/lib_usleep.c
 *
 *   Copyright (C) 2007, 2009, 2012-2013 Gregory Nutt. All rights reserved.
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

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>

/****************************************************************************
 * Name: usleep
 *
 * Description:
 *   The usleep() function will cause the calling thread to be suspended
 *   from execution until either the number of real-time microseconds
 *   specified by the argument 'usec' has elapsed or a signal is delivered
 *   to the calling thread. The suspension time may be longer than requested
 *   due to the scheduling of other activity by the system.
 *
 *   The 'usec' argument must be less than 1,000,000. If the value of
 *   'usec' is 0, then the call has no effect.
 *
 *   If a SIGALRM signal is generated for the calling process during
 *   execution of usleep() and if the SIGALRM signal is being ignored or
 *   blocked from delivery, it is unspecified whether usleep() returns
 *   when the SIGALRM signal is scheduled. If the signal is being blocked, it
 *   is also unspecified whether it remains pending after usleep() returns or
 *   it is discarded.
 *
 *   If a SIGALRM signal is generated for the calling process during
 *   execution of usleep(), except as a result of a prior call to alarm(),
 *   and if the SIGALRM signal is not being ignored or blocked from delivery,
 *   it is unspecified whether that signal has any effect other than causing
 *   usleep() to return.
 *
 *   If a signal-catching function interrupts usleep() and examines or changes
 *   either the time a SIGALRM is scheduled to be generated, the action
 *   associated with the SIGALRM signal, or whether the SIGALRM signal is
 *   blocked from delivery, the results are unspecified.
 *
 *   If a signal-catching function interrupts usleep() and calls siglongjmp()
 *   or longjmp() to restore an environment saved prior to the usleep() call,
 *   the action associated with the SIGALRM signal and the time at which a
 *   SIGALRM signal is scheduled to be generated are unspecified. It is also
 *   unspecified whether the SIGALRM signal is blocked, unless the process'
 *   signal mask is restored as part of the environment.
 *
 *   Implementations may place limitations on the granularity of timer values.
 *   For each interval timer, if the requested timer value requires a finer
 *   granularity than the implementation supports, the actual timer value will
 *   be rounded up to the next supported value.
 *
 *   Interactions between usleep() and any of the following are unspecified:
 *
 *   nanosleep(), setitimer(), timer_create(), timer_delete(), timer_getoverrun(),
 *   timer_gettime(), timer_settime(), ualarm(), sleep()

 * Parameters:
 *   usec - the number of microseconds to wait.
 *
 * Returned Value:
 *   On successful completion, usleep() returns 0. Otherwise, it returns -1
 *   and sets errno to indicate the error.
 *
 * Assumptions:
 *
 ****************************************************************************/

int usleep(useconds_t usec)
{
	struct timespec rqtp;
	time_t sec;
	int ret = 0;

	if (usec) {
		/* Let nanosleep() do all of the work. */

		sec = usec / 1000000;
		rqtp.tv_sec = sec;
		rqtp.tv_nsec = (usec - (sec * 1000000)) * 1000;

		ret = nanosleep(&rqtp, NULL);
	}

	return ret;
}
   