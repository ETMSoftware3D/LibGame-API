/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_BACKGROUND_H
#define LG_BACKGROUND_H

typedef enum {
	TEX_BG,
	ONE_COLOR_BG,
	UNKNOWN_STATE_BG
} lg_bg_flag;

enum {
	LG_NEW, LG_ON, LG_OFF, LG_FREE
};

int	lg_draw_bg(int, int, int, const char *);

void	lg_clear_bg(uint8_t, uint8_t, uint8_t);

/* FIXME: Still issues: only glClearColor() is used here */
void	lg_clear_bg_full(uint8_t, uint8_t, uint8_t, uint8_t, GLbitfield);

int	surf_depth(SDL_Surface *);

void	lg_bg_info();

/* WARNING: Doesn't swap framebuffer */
int	lg_read_and_render_screen_back();
#endif /* LG_BACKGROUND_H */
