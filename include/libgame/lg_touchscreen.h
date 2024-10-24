/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_TOUCHSCREEN_H
#define LG_TOUCHSCREEN_H

typedef enum {
	LG_FINGER_DOWN_NO_LOC = 0,
	LG_FINGER_DOWN_LEFT = 1,
	LG_FINGER_DOWN_H_CENTER = 2,
	LG_FINGER_DOWN_RIGHT = 4,
	LG_FINGER_DOWN_BOTTOM = 8,
	LG_FINGER_DOWN_V_CENTER = 16,
	LG_FINGER_DOWN_TOP = 32
} lg_finger_down_loc;

void			lg_get_motion_and_shot_from_touchscreen(int, int, int *, int *, int, zboolean *);

void			lg_wait_for_finger_down(float *, float *);

void			lg_wait_for_finger_motion(float *, float *);

zboolean		lg_get_finger_position(zboolean, float *, float *);

zboolean		lg_get_finger_state_and_pos(float *, float *);

zboolean		lg_get_finger_motion(float *, float *);

lg_finger_down_loc	lg_get_finger_down_loc();

lg_finger_down_loc	lg_finger_loc_from_pos(float, float);

unsigned long		lg_return_finger_down_code_push_back_event();

void			lg_flush_touchscreen_buf();

#endif /* LG_TOUCHSCREEN_H */
