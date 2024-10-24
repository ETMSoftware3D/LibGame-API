/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_ERROR_H
#define LG_ERROR_H

long long lg_log_time();

/* Adding timestamps to error logs on Linux */
/*
 * TODO: it would be actually more correct to change:
 * - TIME_FILE_LINE_FUNC_STR to TIME_FILE_LINE_FUNC
 * and
 * - TIME_FILE_LINE_FUNC_STR2 to TIME_FILE_LINE_FUNC_STR
 * but:
 * - There is already (uncorrectly) FILE_LINE_FUNC_STR in libetm.h
 * which should be also changed
 * - It's not working so far
 */
#ifndef ANDROID_V
  #define TIME_FILE_LINE_FUNC_STR	"%lld [%s: %d] %s(): ", lg_log_time(), __FILE__ , __LINE__, __func__
  // STH WRONG HERE - #define TIME_FILE_LINE_FUNC_STR2	"[%lld %s: %d] %s(): %s", lg_log_time(), __FILE__ , __LINE__, __func__
  #define INFO_ERR2(...) \
	{\
		fprintf(STD_ERR, TIME_FILE_LINE_FUNC_STR);\
		fprintf(STD_ERR, __VA_ARGS__);\
		fflush(STD_ERR);\
	}
#endif

#define LG_ERR_CTX_FILE_MAXLEN	63
#define LG_ERR_CTX_FUNC_MAXLEN	63
#define LG_ERR_CTX_TXT_MAXLEN	1023
#define LG_ERR_CTX_CODE_NA	-100000		/* Really not sure what to pick */
#define LG_ERR_CTX_STR_MAXLEN	2048		/* Must contain all of the above - for snprintf() */
#define LG_ERR_CTX_FORMAT	"[%s: %d] %s(): %s (code = %d)"

typedef struct {
	char		file[LG_ERR_CTX_FILE_MAXLEN + 1];	/* Not the full path */
	unsigned int	line;
	char		func[LG_ERR_CTX_FUNC_MAXLEN + 1];
	char		txt[LG_ERR_CTX_TXT_MAXLEN + 1];
	int		code;
} LG_ErrorContext;

enum {OOM_MALLOC2_TEST, OOM_MALLOC3_TEST, INVPTR_FREE2_TEST, INVPTR_FREE3_TEST, SEGFAULT_TEST, DIVBYZERO_TEST};

void		lg_set_error_context(const char *, unsigned int, const char *, const char *, int);

int		lg_get_error_context_code();

const char	*lg_get_full_error_context();

void		lg_clear_error_context();

void		lg_save_error_context(LG_ErrorContext *);

void		lg_restore_error_context(LG_ErrorContext *);

/*
 * Wrappers for these mem alloc funcs
 */
void		*malloc2_plus(size_t, const char *, unsigned int, const char *);	/* size , __FILE__, __LINE__, __func__ */
#define		malloc3(...) malloc2_plus(__VA_ARGS__, __FILE__, __LINE__, __func__)

void		free2_plus(void *, const char *, unsigned int, const char *);		/* mem , __FILE__, __LINE__, __func__ */
#define		free3(...) free2_plus(__VA_ARGS__, __FILE__, __LINE__, __func__)

/*
 * Wrappers for these file ops funcs
 */
/* === BUGGY SO NOT USED SO FAR === */
int		mkdir_plus(const char *, mode_t, const char *, unsigned int, const char *);	/* path, mode, __FILE__, __LINE__, __func__ */
//#define		mkdir_2(...) mkdir_plus(__VA_ARGS__, __FILE__, __LINE__, __func__)
#define		mkdir_2(...) mkdir(__VA_ARGS__)

/* === BUGGY SO NOT USED SO FAR === */
FILE		*fopen_plus(const char *, const char *, const char *, unsigned int, const char *);	/* path, mode, __FILE__, __LINE__, __func__ */
//#define		fopen_2(...) fopen_plus(__VA_ARGS__, __FILE__, __LINE__, __func__)
#define		fopen_2(...) fopen(__VA_ARGS__)
/*
void		*SDL_LoadFile_2(pathname, &size);
size_t 		SDL_RWread_2(SDL_RWops *, void *, size_t, size_t);
size_t		SDL_RWwrite_2(SDL_RWops *, void *, size_t, size_t);
int		SDL_RWclose_2(SDL_RWops *);
SDL_RWops* 	SDL_RWFromFile_2(const char *, const char *);
*/

#ifndef WIN32_V
void		sig_handler(int, siginfo_t *, void *);

void		set_sig_handler();
#endif

void		test_big_error(int);

#endif /* LG_ERROR_H */
