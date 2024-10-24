/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_QUATERNIONS_H
#define LG_QUATERNIONS_H

#define POW2(x)		(x * x)
#define POW3(x)		(x * x * x)

#define RAD_TO_DEG	57.295779513	/* or (180.0 / (float)M_PI) */
#define DEG_TO_RAD	0.017453293	/* or ((float)M_PI / 180.0) */

/* Euler angles */
typedef struct {
	double		x_rot;	/* Rotation around X axis in radians - Use DEG_TO_RAD macro when necessary */
	double		y_rot;
	double		z_rot;
} LG_EulerAng;

/* Axis and angle */
typedef struct {
	vec3_t		axis;	/* Unit vector - should/must always be normalized ? */
	double		angle;	/* In radians */
} LG_AxAng;

/* Quaternion */
typedef struct {
	double		x;	/* Vector part */
	double		y;
	double		z;
	double		w;	/* Scalar part */
} LG_Quat;

/* 3 x 3, column-major order matrix -> move that to math_3d.h ? */
typedef union {
	float m[3][3];
	struct {
		float m00, m01, m02;
		float m10, m11, m12;
		float m20, m21, m22;
	};
} mat3_t;

LG_Quat		lg_quat(double, double, double, double);

void		lg_quat_normalize(LG_Quat *);

LG_Quat		lg_quat_get_normalized(LG_Quat);

LG_Quat 	lg_quats_multiply(LG_Quat, LG_Quat);

LG_Quat		lg_quat_from_euler_ang(LG_EulerAng, const char *);

LG_Quat		lg_quat_from_axis_angle(LG_AxAng);

void		lg_quat_to_axis_angle(LG_Quat q, LG_AxAng *);

LG_Quat		lg_quat_from_3x3_rot_matrix(mat3_t);

mat4_t		lg_quat_to_rot_matrix(LG_Quat);

vec3_t		lg_quat_rotate_vec3(LG_Quat, vec3_t);

int		lg_quat_copy(LG_Quat *, const LG_Quat *);

zboolean	lg_quats_are_equal(LG_Quat *, LG_Quat *);

void		lg_quat_conjugate(LG_Quat *);

LG_Quat		lg_quat_get_conjugate(LG_Quat);

void		lg_quat_invert(LG_Quat *);

LG_Quat		lg_quat_get_invert(LG_Quat);

double		lg_quat_magnitude(LG_Quat);

double		lg_quats_dot(LG_Quat *, LG_Quat *);

void		lg_quat_set_identity(LG_Quat *);

LG_Quat		lg_quat_get_identity();

LG_Quat		lg_quat_slerp(LG_Quat *, LG_Quat *, float);

LG_EulerAng	lg_euler_ang(double, double, double);

LG_AxAng	lg_ax_ang(vec3_t, double);

mat3_t		mat3(float, float, float, float, float, float, float, float, float);

mat3_t		m3_transpose(mat3_t);

#endif /* LG_QUATERNIONS_H */
