/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_FRAME_H
#define LG_FRAME_H

// === STILL IN PROGRESS ===

#define N_CAMS_MAX		4
#define N_LIGHTS_MAX		8
#define N_UI_WINS_MAX		16

typedef struct {
	LG_Camera	camera[N_CAMS_MAX];
	uint8_t		n_cameras;
	LG_Light	light[N_LIGHTS_MAX];
	uint8_t		n_lights;
	LG_Window	*ui_win[N_UI_WINS_MAX];
	uint8_t		n_ui_wins;
	LG_SceneNode	*root_node;
} LG_Frame;

LG_Frame	lg_frame(LG_Camera, LG_Light, LG_Window *, LG_SceneNode *);

int		lg_frame_add_camera(LG_Frame *, LG_Camera);

int		lg_frame_remove_last_added_camera(LG_Frame *);

int		lg_frame_add_light(LG_Frame *, LG_Light);

int		lg_frame_remove_last_added_light(LG_Frame *);

int		lg_frame_add_ui_win(LG_Frame *, LG_Window *);

int		lg_frame_remove_last_added_ui_win(LG_Frame *);

int		lg_frame_set_root_node(LG_Frame *, LG_SceneNode *);

#endif /* LG_FRAME_H */
