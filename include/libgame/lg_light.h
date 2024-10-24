/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_LIGHT_H
#define LG_LIGHT_H

typedef enum {
	POINT,
	DIRECTIONAL,
	SPOTLIGHT,
	AMBIENT,
	DIFFUSE,
	EMISSIVE,
	SPECULAR
} lg_light_type;

/*
 * Point lighting - vec3_t as a position
 */
typedef struct {
	float	x;
	float	y;
	float	z;
} LG_LightPos;

/*
 * Directional lighting - vec3_t as a direction
 */
typedef struct {
	float	x;
	float	y;
	float	z;
} LG_LightDir;

/* RGBA color as 4 float's */
typedef struct {
	float	r;
	float	g;
	float	b;
	float	a;
} LG_LightColor;

#define WHITE_LIGHT	(LG_LightColor){1.0, 1.0, 1.0, 1.0}

/*
 * LG_Light struct
 *
 * Use an array of LG_Light structs if you want to have several different lights in a scene
 */
typedef struct {
	lg_light_type	type;
	LG_LightPos	pos;
	LG_LightDir	dir;
	LG_LightColor	color;
} LG_Light;

LG_Light	lg_scene_light(lg_light_type, LG_LightPos, LG_LightDir, LG_LightColor);

int		lg_set_scene_light(LG_Light *, lg_light_type, LG_LightPos, LG_LightDir, LG_LightColor);

void		lg_set_light_src(LG_LightPos *, float, float, float);

void		lg_get_light_src(const LG_LightPos *, float *, float *, float *);

void		lg_move_light_src(LG_LightPos *, float, float, float);

void		lg_set_light_dir(LG_LightDir *, float, float, float);

void		lg_get_light_dir(const LG_LightDir *, float *, float *, float *);

void		lg_change_light_dir(LG_LightDir *, LG_EulerAng, const char *);

#endif /* LG_LIGHT_H */
