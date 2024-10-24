/*
 *	libetm / libetm.h - Copyright (C) Emmanuel Thomas-Maurin 2008-2024
 *	<manutm007@gmail.com>
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#ifndef INC_LIBETM_H
#define INC_LIBETM_H

#define LIBETM_NAME		"Libetm"
#define LIBETM_VERSION_NUM	"0.5.1"

#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif
#ifndef _ISOC11_SOURCE
  #define _ISOC11_SOURCE
#endif

/* TODO: Check/fix/spec this, quite confusing at the moment */
/*#if !defined(ANDROID_V) && !defined(LINUX_V) && !defined(WIN32_V)
#  error No platform is defined
#endif*/

/*
 * We should eventually define these in Makefile(s) or wherever
 * (when compiling libetm and/or when linking against libetm)
 * but definitely not here.
 * Then only use INFO_OUT/ERR, VERBOSE_INFO_OUT/ERR, DEBUG_INFO_OUT
 * in app code.
 */
/*#define LIBETM_VERBOSE_OUTPUT*/
/*#define LIBETM_DEBUG_OUTPUT*/

/* Is this one still relevant ? */
/*#define LIBETM_EXPERIMENTAL_STUFF*/

/*
 * stdout and stderr on Linux and Android / text files on win32
 * (see win32_specific.c)
 */
#ifdef WIN32_V
  #define STD_OUT	std_out
  #define STD_ERR	std_err
#else
  #define STD_OUT	stdout
  #define STD_ERR	stderr
#endif
/*
 * === WARNING: Don't put a ';' at the end of theses INFO_whatever, or it will be a mess ===
 */
#if defined(LIBETM_VERBOSE_OUTPUT) || defined(LIBETM_DEBUG_OUTPUT)
  #ifdef ANDROID_V
    #define FILE_LINE_FUNC_STR	"[%s: %d] %s(): ", basename(__FILE__) , __LINE__, __func__
  #else
    #define FILE_LINE_FUNC_STR	"[%s: %d] %s(): ", __FILE__ , __LINE__, __func__
  #endif
#else
  #define FILE_LINE_FUNC_STR	""
#endif

#ifndef ANDROID_V
  #define INFO_OUT(...) \
	{\
		fprintf(STD_OUT, __VA_ARGS__);\
		fflush(STD_OUT);\
	}
  #define INFO_ERR(...) \
	{\
		fprintf(STD_ERR, FILE_LINE_FUNC_STR);\
		fprintf(STD_ERR, __VA_ARGS__);\
		fflush(STD_ERR);\
	}
#else
  #ifndef ANDROID_NO_LOGGING
    #include <android/log.h>
    #define INFO_OUT(...) \
		__android_log_print(ANDROID_LOG_INFO, "_android_out_", __VA_ARGS__);
    #define INFO_ERR(...) \
		__android_log_print(ANDROID_LOG_ERROR, "_android_err_", FILE_LINE_FUNC_STR); \
		__android_log_print(ANDROID_LOG_ERROR, "_android_err_", __VA_ARGS__);
  #else
    #define INFO_OUT(...)	{}
    #define INFO_ERR(...)	{}
  #endif
#endif

/* TODO: Check this is still working with newly added Android stuff */
#ifdef LIBETM_VERBOSE_OUTPUT
  #define VERBOSE_INFO_OUT(...)	INFO_OUT(__VA_ARGS__)
  #define VERBOSE_INFO_ERR(...)	INFO_ERR(__VA_ARGS__)
#else
  #define VERBOSE_INFO_OUT(...)	{}
  #define VERBOSE_INFO_ERR(...)	{}
#endif

#ifdef LIBETM_DEBUG_OUTPUT
  #define DEBUG_INFO_OUT(...) \
{\
	fprintf(STD_OUT, FILE_LINE_FUNC_STR);\
	INFO_OUT(__VA_ARGS__)\
}
#else
  #define DEBUG_INFO_OUT(...)	{}
#endif

/* === TODO: Should we use mutex locks instead ? ===*/
#define N_SIMULTANEOUS_CALLS		64
#define N_SIMULTANEOUS_CALLS_MASK	63

/* Should zboolean type be sig_atomic_t ???? */
#undef TRUE
#undef FALSE
#define TRUE	(1)
#define FALSE	(0)
typedef int32_t zboolean;	/* Couldn't find anything fancier at the moment */

/* (Previously)
typedef enum {
	FALSE = (0), TRUE = (!FALSE)
} zboolean;
* Buggy because, if TRUE and FALSE are enum constants, the preprocessor
* will always replace them with zeros.
* See https://gcc.gnu.org/onlinedocs/cpp/If.html#If
*/

#define YES	(1)
#define NO	(0)

#include "str_mem.h"
#include "tcp_socket.h"
#include "error.h"
#include "misc.h"
/*#include "dllist.h"*/
#ifdef WIN32_V
#include "win32_specific.h"
#endif
#ifdef ANDROID_V
#include "android_specific.h"
#endif

#ifndef MAX
  #define MAX(x,y)	((x) > (y) ? (x) : (y))
#endif

#ifndef MIN
  #define MIN(x,y)	((x) < (y) ? (x) : (y))
#endif

#ifndef ABS
  #define ABS(x)	((x) > 0 ? (x) : -(x))
#endif

/* Do more testing for the 2 following ones */
#ifndef SIGN
  #define SIGN(x)	((x) != 0 ? ((x) > 0 ? 1 : -1) : 0)
#endif

/* Only if f > 0 */
#ifndef APPROX
  #define APPROX(f)	(ABS(((f) - (int)(f)) > 0.5) ? (int)(f) + SIGN((f)) : (int)(f))
#endif
#endif /* INC_LIBETM_H */
