/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_MISC_H
#define LG_MISC_H

typedef enum {LG_LITTLE_ENDIAN, LG_BIG_ENDIAN} lg_endianness;

int		check_datatype_sizes();

float		lg_tv_diff(struct timeval *, struct timeval *, struct timeval *);

int		lg_show_pixel_format_info_from_sdl_display_mode(SDL_DisplayMode *);

lg_endianness	lg_get_arch_endianness();

float		lg_swap_float_values(float *, float *);

double		lg_swap_double_values(double *x, double *y);

int32_t		lg_swap_int32_values(int32_t *x, int32_t *y);

uint32_t	lg_swap_uint32_values(uint32_t *x, uint32_t *y);

int16_t		lg_swap_int16_values(int16_t *x, int16_t *y);

uint16_t	lg_swap_uint16_values(uint16_t *x, uint16_t *y);

int8_t		lg_swap_int8_values(int8_t *x, int8_t *y);

uint8_t		lg_swap_uint8_values(uint8_t *x, uint8_t *y);

void		lg_print_out_error_codes();

int		lg_check_gl_context();

char		*lg_basename(const char *);

void		debug_start_max_int_in_loop();

void		debug_max_int_in_loop(unsigned long, const char *, int);

void		debug_end_max_int_in_loop();

void		debug_start_max_float_in_loop();

void		debug_max_float_in_loop(float, const char *, int);

void		debug_end_max_float_in_loop();

#endif /* LG_MISC_H */
