/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_CAMERA_H
#define LG_CAMERA_H

/* Global default camera values */

#define LG_CAMERA_ORIGIN	0.0, 0.0, 0.0		/* Initial camera or "eye" position */
#define LG_CAMERA_TARGET	0.0, 0.0, -1.0
#define LG_CAMERA_UP		0.0, 1.0, 0.0

#define	LG_V_FOV		45
#define LG_Z_NEAR		0.1			/* Usually in range [0.1, 1.0] */
#define LG_Z_FAR		1000.0			/* Usually >= 100.0 */

typedef struct {
	vec3_t		position;	/* Or "eye" position in world coords */
	LG_Quat		orientation;	/* Must update target after setting/changing orientation */
	vec3_t		target;		/* Target position in world coords - SHOULD ALWAYS ONLY BE UPDATED FROM ORIENTATION QUAT */
	vec3_t		up;		/* Must be normalized */
	float		v_fov;		/* Vertical field of view in deg */
	float		z_near;		/* Clipping plane along the Z axis, always > 0 */
	float		z_far;		/* Clipping plane along the Z axis, always > 0 */
	mat4_t		view_m;		/* View/proj matrices - must be updated when position or orientation changes */
	mat4_t		proj_m;
	mat4_t		view_proj_m;
	zboolean	new_view;	/* Dirty flag */
	zboolean	new_proj;
	LG_InputState	input_state;	/* To capture user input */
} LG_Camera;

typedef struct {
	float	a, b, c, d;
} LG_Plane;

typedef struct {
	LG_Plane	left;
	LG_Plane	right;
	LG_Plane	bottom;
	LG_Plane	top;
	LG_Plane	near;
	LG_Plane	far;
} LG_Frustum;

LG_Camera	lg_camera();

int		lg_camera_init(LG_Camera *);

int		lg_camera_set_all(LG_Camera *, vec3_t, vec3_t, vec3_t, float, float, float);

int		lg_camera_reset(LG_Camera *);

mat4_t		lg_camera_compute_view_matrix(LG_Camera *);

mat4_t		lg_camera_compute_proj_matrix(LG_Camera *);

mat4_t		lg_camera_compute_view_proj_matrix(LG_Camera *);

void		lg_update_all_cam_m(LG_Camera *);

int		lg_camera_move_to(LG_Camera *, vec3_t);

int		lg_camera_rotate_by_eu(LG_Camera *, LG_EulerAng, const char *);

int		lg_camera_rotate_by_quat(LG_Camera *, LG_Quat);

int		lg_camera_set_rot_by_eu(LG_Camera *, LG_EulerAng, const char *);

int		lg_camera_set_rot_by_quat(LG_Camera *, LG_Quat);

void		lg_camera_get_frustum(LG_Camera *, LG_Frustum *);

zboolean	is_in_frustum(LG_Frustum *, vec3_t *);

void		lg_camera_override_zfar(LG_Camera *, float);

void		lg_camera_orbit_around(LG_Camera *, vec3_t, float, float);

int		lg_plane_normalize(LG_Plane *);

float		lg_point_to_plane_distance(vec3_t *, LG_Plane *);

float		lg_point_to_norm_plane_distance(vec3_t *, LG_Plane *);

void		lg_camera_info(LG_Camera *);

void		lg_frustum_info(LG_Frustum *);

#endif /* LG_CAMERA_H */
