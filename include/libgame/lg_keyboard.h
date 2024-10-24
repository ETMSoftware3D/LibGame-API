/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_KEYBOARD_H
#define LG_KEYBOARD_H

#define LG_N_KEYS_MAX	4

typedef enum {
	KAI_LEFT = 0,
	KAI_RIGHT,
	KAI_UP,
	KAI_DOWN
} lg_key_array_indice;

void		lg_get_motion_and_shot_from_keyboard(int *, int *, zboolean *, unsigned long *);

void		lg_wait_for_key_pressed(unsigned long);

unsigned long	lg_wait_for_key_from_set_pressed(int, unsigned long [LG_N_KEYS_MAX]);

unsigned long	lg_wait_for_any_key_pressed();

unsigned long	lg_return_key_pressed();

void		lg_get_arrow_key_state_array(zboolean *);

void		lg_flush_keyb_buf();

#endif /* LG_KEYBOARD_H */
