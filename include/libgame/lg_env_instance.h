/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_ENV_INSTANCE_H
#define LG_ENV_INSTANCE_H

LG_Env		*lg_get_game_env();

LG_Renderer2D	*lg_get_renderer_2d();

LG_Camera	*lg_get_camera_one();

/*LG_Scene	*lg_get_scene_one();*/

LG_Texture	*lg_get_texture_list();

#endif /* LG_ENV_INSTANCE_H */
