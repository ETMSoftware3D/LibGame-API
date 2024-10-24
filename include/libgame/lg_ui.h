/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_UI_H
#define LG_UI_H

#ifndef ANDROID_V
#  define FLUSH_KEYB_OR_TOUCHSCREEN_BUF		{lg_flush_keyb_buf();}
#else
#  define FLUSH_KEYB_OR_TOUCHSCREEN_BUF		{lg_flush_touchscreen_buf();}
#endif

#ifndef ANDROID_V
#  define WAIT_FOR_PRESS_OR_TOUCH		{lg_wait_for_any_key_pressed();}
#else
#  define WAIT_FOR_PRESS_OR_TOUCH		{lg_wait_for_finger_down(NULL, NULL);}
#endif

/*
 * Check this out:
 * Android touch screen
 *	typedef enum {
 *		LG_FINGER_DOWN_NO_LOC = 0,
 *		LG_FINGER_DOWN_LEFT = 1,
 *		LG_FINGER_DOWN_H_CENTER = 2,
 *		LG_FINGER_DOWN_RIGHT = 4,
 *		LG_FINGER_DOWN_BOTTOM = 8,
 *		LG_FINGER_DOWN_V_CENTER = 16,
 *		LG_FINGER_DOWN_TOP = 32
 *	} lg_finger_down_loc;
 *
 *\code
 *	      L     C     R
 *	   -------------------
 *	T  |     |     |     |
 *	   -------------------
 *	C  |     |     |     |
 *	   -------------------
 *	B  |     |     |     |
 *	   -------------------
 *
 *	TZ_LEFT
 *	TZ_H_CENTER
 *	TZ_RIGHT
 *	TZ_BOTTOM
 *	TZ_V_CENTER
 *	TZ_TOP
 *\endcode
 */

typedef struct {
	/* Linux */
	zboolean		arrow_key_state[4];	/* LEFT, RIGHT, UP, DOWN */
	zboolean		kmod_ctrl;
	zboolean		kmod_shift;
	zboolean		kmod_alt;
	int			last_pressed_key;
	/* Android */
	lg_finger_down_loc	finger_down_loc;	/* Logical OR of values */
	float			x;
	float			y;
	/* Cam/object motions = -1, 0, 1 (but slow_motion) */
	int			move_forward;
	int			move_up;		/* Not an aircraft motion */
	int			cam_truck;		/* Not an aircraft motion */
	int			slow_motion;
	/* Yaw/Pitch/Roll = -1, 0, 1 */			/* Aircraft/flight simulator standard order */
	int			yaw;
	int			pitch;
	int			roll;
} LG_InputState;

/*
 * TZ/tz means Touch Zone (not Time Zone)
 */
typedef enum {
	TZ_LEFT,
	TZ_H_CENTER,
	TZ_RIGHT,
	TZ_BOTTOM,
	TZ_V_CENTER,
	TZ_TOP
} lg_touch_zone;

typedef struct {
	LG_Window	win;
	LG_Color_u	color;
	Rec2Di		area;
} LG_TouchZoneWindow;

#define TZW_ARROW_POINTS_NUM	7

typedef enum {
	TZW_RECTANGLE,
	TZW_RECT_CORNERS,
	TZW_ARROW_UP,
	TZW_ARROW_DOWN,
	TZW_ARROW_LEFT,
	TZW_ARROW_RIGHT,
	TZW_DOUBLE_ARROW_HORIZ,
	TZW_DOUBLE_ARROW_VERT,
} lg_tzw_type;

typedef enum {
	USER_INPUT_NONE,
	USER_INPUT_QUIT,
	USER_INPUT_BREAK,
	USER_INPUT_F1,
	USER_INPUT_F2,
	USER_INPUT_F3,
	USER_INPUT_F4,
	USER_INPUT_F5,
	USER_INPUT_F6,
	USER_INPUT_F7,
	USER_INPUT_F8,
	USER_INPUT_F9,
	USER_INPUT_F10,
	USER_INPUT_F11,
	USER_INPUT_F12,
	USER_INPUT_WHATEVER
} lg_user_input;

LG_TouchZoneWindow	*lg_tzwin_new(const char *, LG_Color_u, int, int);

void			lg_tzwin_show(LG_TouchZoneWindow *, lg_tzw_type);

void			lg_tzwin_free(LG_TouchZoneWindow *);

Rec2Di			lg_tzwin_get_rect(LG_TouchZoneWindow *);

void			lg_draw_rect_corners(Rec2Di, LG_Color_u, int);

void			lg_draw_arrow(Rec2Di r, LG_Color_u c, lg_tzw_type);

void			lg_rectangle_to_arrow(Rec2Di, lg_tzw_type, Point2Di *[]);

lg_user_input		lg_get_user_input(LG_InputState *, Rec2Di *[]);

#endif /* LG_UI_H */
