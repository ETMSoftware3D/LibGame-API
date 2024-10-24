/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_WIN_H
#define LG_WIN_H

/* A few helpers for wins funcs: */
#define BLOCK		TRUE
#define NO_BLOCK	(! BLOCK)

#define WITH_FRAME	TRUE
#define FRAMELESS	(! WITH_FRAME)

#define SWAP_FB		TRUE
#define NO_SWAP		(! SWAP_FB)

#if defined(LINUX_V) || defined(WIN32_V)
  #define PRESS_OR_TAP_ANYTHING		"Press any key ..."
#elif defined(ANDROID_V)
  #define PRESS_OR_TAP_ANYTHING		"Tap anywhere to continue ..."
#endif

#define WARNING_TIMEOUT			3000

#define UNUSED_SDL_COLOR		((SDL_Color){0, 0, 0, 0})
#define UNUSED_LG_COLOR_U		((LG_Color_u){0, 0, 0, 0})

#define TMP_STR_MAXLEN			1023

#define H_PADDING			12
#define V_PADDING			8
#define BORDER_WIDTH			2

#define LG_WIN_TXT_NBSP		'~'

/* TODO: what if win text is over 24 lines ? */
#define LG_WIN_N_LINES_MAX		24

#define LG_LEFT_MARGIN			5
#define LG_BOTTOM_MARGIN		5

#define LG_WIN_TIMESTAMP_MAXLEN		(64 - 1)

typedef struct {
	int		id;		/* (So far) 0 -> OK, -1 -> invalid sprite */
	LG_Texture	*tex;		/* Used inside new/open/close/free_win(), don't modify elsewhere */
	Rec2Di		text_rect;
	int		x;
	int		y;
	/* === Don't modify === */
	int		w;
	int		h;
	int		last_open_x;
	int		last_open_y;
	char		timestamp[LG_WIN_TIMESTAMP_MAXLEN + 1];
} LG_Window;

/* Wins colors */
#define ALL_WINS_BG_COLOR		"dark-grey2"
#define ALL_WINS_BORDER_COLOR		"dark-grey2"

#define INFO_WIN_TEXT_COLOR		"white"
#define INFO_WIN_BG_COLOR		ALL_WINS_BG_COLOR
#define INFO_WIN_BORDER_COLOR		ALL_WINS_BORDER_COLOR
#define INFO_WIN_FONT
#define INFO_WIN_STYLE

#define QUESTION_WIN_TEXT_COLOR		"white"	//"orange"
#define QUESTION_WIN_BG_COLOR		ALL_WINS_BG_COLOR
#define QUESTION_WIN_BORDER_COLOR	ALL_WINS_BORDER_COLOR
#define QUESTION_WIN_FONT
#define QUESTION_WIN_STYLE

#define WARNING_WIN_TEXT_COLOR		"orange"
#define WARNING_WIN_BG_COLOR		ALL_WINS_BG_COLOR
#define WARNING_WIN_BORDER_COLOR	ALL_WINS_BORDER_COLOR
#define WARNING_WIN_FONT
#define WARNING_WIN_STYLE

#define ERROR_WIN_TEXT_COLOR		"red"
#define ERROR_WIN_BG_COLOR		ALL_WINS_BG_COLOR
#define ERROR_WIN_BORDER_COLOR		ALL_WINS_BORDER_COLOR
#define ERROR_WIN_FONT
#define ERROR_WIN_STYLE

/* Default, modifiable colors */
typedef struct {
	LG_Color_u	info[3];	/* Text, bg and border */
	LG_Color_u	question[3];
	LG_Color_u	warning[3];
	LG_Color_u	error[3];
} LG_WinColors;

/* and for each their indexes */
enum {TEXT_I, BG_I, BORDER_I};

void		lg_info_win_no_block(const char *, zboolean, zboolean);

void		lg_info_win(const char *, zboolean, zboolean);

int		lg_question_win(const char *);				/* swap_fb */

void		lg_warning_win(const char *);				/* swap_fb */

void		lg_error_win(const char *);				/* swap_fb */

char		*lg_entry_win(const char *, int, int);			/* swap_fb */

int		lg_win_open_centered(LG_Window *);

LG_Window	lg_win(const char *, LG_Color_u, zboolean, LG_Color_u, LG_Color_u, TTF_Font *);

int		lg_win_open(LG_Window *, int, int);

int		lg_win_close(LG_Window *);

void		lg_win_free_tex(LG_Window *);

int		lg_get_win_w(LG_Window *);

int		lg_get_win_h(LG_Window *);

void		lg_set_fonts(TTF_Font *, TTF_Font *, TTF_Font *, TTF_Font *, TTF_Font *, TTF_Font *, TTF_Font *);

TTF_Font	*lg_get_small_font();

TTF_Font	*lg_get_medium_font();

TTF_Font	*lg_get_large_font();

TTF_Font	*lg_get_big_font();

TTF_Font	*lg_get_big_papyrus_font();

TTF_Font	*lg_get_very_big_papyrus_font();

TTF_Font	*lg_get_large_intelone_mono_font();

LG_WinColors	*lg_get_win_colors();

void		lg_set_default_win_colors();

char		*lg_wrap_lines(const char *, TTF_Font *);

#endif /* LG_WIN_H */
