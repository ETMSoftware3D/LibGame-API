/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_GR_FUNC_H
#define LG_GR_FUNC_H

/*
 *  === A few 2D structs and graphical funcs ===
 */

typedef struct {
	int32_t		x;
	int32_t		y;
} Point2Di;

typedef struct {
	float		x;
	float		y;
} Point2Df;

typedef struct {
	int32_t		x1;
	int32_t		y1;
	int32_t		x2;
	int32_t		y2;
} Line2Di;

typedef struct {
	float		x1;
	float		y1;
	float		x2;
	float		y2;
} Line2Df;

/*
 * Rec = rectangle (floats) with OpenGL coord sys orientation
 *	  ^
 *	  |
 *  x,y+h |--------
 *	  |       |
 *	  |       |
 *	  ------------->
 *	 x,y	  x+w,y
 */
typedef struct {
	int32_t		x;
	int32_t		y;
	int32_t		w;
	int32_t		h;
} Rec2Di;

typedef struct {
	float		x;
	float		y;
	float		w;
	float		h;
} Rec2Df;

void		lg_draw_line(int32_t, int32_t, int32_t, int32_t, LG_Color_u);

void		lg_draw_rect(Rec2Di, LG_Color_u);

void		lg_fill_rect(Rec2Di r, LG_Color_u c);

void		lg_clear_rect(Rec2Di r, LG_Color_u c);

zboolean	lg_clip_rect(Rec2Di, Rec2Di, Rec2Di *);

zboolean	lg_recs_overlap(Rec2Df *, Rec2Df *);

void		lg_copy_rect(Rec2Di, Rec2Di *);

void		lg_rec_i_copy(Rec2Di *, Rec2Di);

void		lg_rec_f_copy(Rec2Df *, Rec2Df);

Rec2Di		lg_rec_i(int, int, int, int);

Rec2Df		lg_rec_f(float, float, float, float);

Rec2Df		lg_rec_f_from_rec_i(Rec2Di);

Rec2Di		lg_rec_i_from_rec_f(Rec2Df);

int32_t		sdl_to_gl_int_x(int32_t);

int32_t		sdl_to_gl_int_y(int32_t);

float		sdl_to_gl_float_x(int32_t);

float		sdl_to_gl_float_y(int32_t);

LG_Color_u	lg_color_u_from_sdl_color(SDL_Color);

SDL_Color	lg_sdl_color_from_lg_color_u(LG_Color_u);

SDL_Color	*lg_set_sdl_color_from_str(SDL_Color *, const char *);

SDL_Color	lg_get_sdl_color_from_str(const char *);

LG_Color_u	*lg_set_lg_color_u_from_str(LG_Color_u *, const char *);

LG_Color_u	lg_get_lg_color_u_from_str(const char *);

int		lg_get_n_color_str();

const char	*lg_get_color_str_from_color_index();

void		v_flip_sdl_surf(SDL_Surface *);

#endif /* LG_GR_FUNC_H */
