/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_VERTEX_H
#define LG_VERTEX_H

/*
 * === Vertex* struct's ===
 */

/* Coords (only) */
typedef struct __attribute__((packed, aligned(4))) {
	float		x;
	float		y;
	float		z;
} Vertex;

/* Coords + (texture) uv coords */
typedef struct __attribute__((packed, aligned(4))) {
	float		x;
	float		y;
	float		z;
	uint16_t	u;
	uint16_t	v;
} Vertex_uv;

/* Coords + normals */
typedef struct __attribute__((packed, aligned(4))) {
	float		x;
	float		y;
	float		z;
	int16_t		n_x;
	int16_t		n_y;
	int16_t		n_z;
	uint16_t	flag1;		/* Explicit padding to align to 4 bytes boundaries */
} Vertex_n;

/*
 * === The most used/useful vertex struct ===
 */
/* Coords + uv coords + normals */
typedef struct __attribute__((packed, aligned(4))) {
	float		x;		/* sizeof(float) = 4 */
	float		y;
	float		z;
	uint16_t	u;		/* sizeof(unsigned short) = 2 */
	uint16_t	v;
	int16_t		n_x;		/* sizeof(short) = 2 */
	int16_t		n_y;
	int16_t		n_z;
	uint16_t	flag1;		/* Explicit padding to align to 4 bytes boundaries */
} Vertex_uv_n;

/* Coords + colors */
typedef struct __attribute__((packed, aligned(4))) {
	float		x;
	float		y;
	float		z;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
} Vertex_rgba;

/*
 * No Vertex_rgba_uv because we don't want/need colors and tex coords at the same time
 * (at least so far).
 */

/* Coords + colors + normals */
typedef struct __attribute__((packed, aligned(4))) {
	float		x;
	float		y;
	float		z;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	int16_t		n_x;
	int16_t		n_y;
	int16_t		n_z;
	uint16_t	flag1;		/* Explicit padding to align to 4 bytes boundaries */
} Vertex_rgba_n;

/* RGBA color as 4 unsigned bytes (ie in range [0, 255]) */
typedef struct {
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
} LG_Color_u;

/* RGBA color as 4 normalized float's (ie in range [0.0, 1.0]) */
typedef struct {
	float		r;
	float		g;
	float		b;
	float		a;
} LG_Color_f;

Vertex		lg_vertex(float, float, float);

Vertex		lg_vertex_from_vec3(vec3_t);

Vertex_uv	lg_vertex_uv(float, float, float, uint16_t, uint16_t);

Vertex_n	lg_vertex_n(float, float, float, int16_t, int16_t, int16_t);

Vertex_uv_n	lg_vertex_uv_n(float, float, float, uint16_t, uint16_t, int16_t, int16_t, int16_t);

Vertex_rgba	lg_vertex_rgba(float, float, float, LG_Color_u);

Vertex_rgba	lg_vertex_rgba_from_vec3(vec3_t, LG_Color_u);

Vertex_rgba_n	lg_vertex_rgba_n(float, float, float, LG_Color_u, int16_t, int16_t, int16_t);

LG_Color_u	lg_color_u(uint8_t, uint8_t, uint8_t, uint8_t);

LG_Color_f	lg_color_f(float, float, float, float);

LG_Color_u	lg_color_u_from_f(LG_Color_f);

LG_Color_f	lg_color_f_from_u(LG_Color_u);

void		lg_vertex_sizes_info();

#endif /* LG_VERTEX_H */
