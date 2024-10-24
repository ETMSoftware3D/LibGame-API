/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_3D_PRIMITIVES_H
#define LG_3D_PRIMITIVES_H

/*
 * All vertices are Vertex_rgba
 * Could/should we implemenet the same with other vertex formats ?
 */

/* Num of vertices of vertex buffer for all lines to draw */
#define LG_QUAD_N_VERTICES		4
#define LG_QUAD_SIZE			LG_QUAD_N_VERTICES * sizeof(Vertex_rgba)
#define LG_QUAD_LINES_N_VERTICES	8

#define LG_CUBOID_N_VERTICES		8
#define LG_CUBOID_SIZE			LG_CUBOID_N_VERTICES * sizeof(Vertex_rgba)
#define LG_CUBOID_LINES_N_VERTICES	24

#define LG_XYZ_AXIS_N_VERTICES		18
#define LG_XYZ_AXIS_SIZE		LG_XYZ_AXIS_N_VERTICES * sizeof(Vertex_rgba)
#define LG_XYZ_AXIS_LINES_N_VERTICES	LG_XYZ_AXIS_N_VERTICES		/* CHECKME: is this correct */

#define LG_LINES_N_VERTICES_MAX		64	/* === Must be big enough, adjust as necessary === */

#if LG_QUAD_LINES_N_VERTICES > LG_LINES_N_VERTICES_MAX
  #error Sth is wrong with STH_LINES_N_VERTICES stuff
#elif LG_CUBOID_LINES_N_VERTICES > LG_LINES_N_VERTICES_MAX
  #error Sth is wrong with STH_LINES_N_VERTICES stuff
#elif LG_XYZ_AXIS_LINES_N_VERTICES > LG_LINES_N_VERTICES_MAX
  #error Sth is wrong with STH_LINES_N_VERTICES stuff
#endif

/*
 * Generic 3D line set vertex buffer (Vertex_rgba)
 *
 * Useful for generating VBO from shapes
 *
 *	Draw with glDrawArrays(GL_LINE, 0, n_vertices)
 *
 * Max num of lines = LG_LINES_N_VERTICES_MAX / 2
 *
 */
typedef struct {
	Vertex_rgba	vb[LG_LINES_N_VERTICES_MAX];
	uint32_t	n_vertices;
} Lines3D_VB;

typedef struct {
	Vertex_rgba	vertex[LG_QUAD_N_VERTICES];
} LG_Quad;

typedef struct {
	Vertex_rgba	vertex[LG_CUBOID_N_VERTICES];
} LG_Cuboid;

typedef struct {
	Vertex_rgba	vertex[LG_XYZ_AXIS_N_VERTICES];
} LG_XYZ_Axis;

LG_Quad			lg_quad(vec3_t, vec3_t, vec3_t, vec3_t, LG_Color_u);

LG_Quad			lg_centered_unit_quad(LG_Color_u);

LG_Quad			lg_quad_transform(LG_Quad, mat4_t);

LG_Cuboid		lg_cuboid(vec3_t, vec3_t, vec3_t, vec3_t, vec3_t, vec3_t, vec3_t, vec3_t, LG_Color_u);

LG_Cuboid		lg_centered_unit_cube(LG_Color_u);

LG_Cuboid		lg_cuboid_transform(LG_Cuboid, mat4_t);

LG_XYZ_Axis		lg_xyz_axis(float, LG_Color_u, LG_Color_u, LG_Color_u);

Lines3D_VB		lg_l3d_vb_from_quad(LG_Quad);

Lines3D_VB		lg_l3d_vb_from_cuboid(LG_Cuboid);

Lines3D_VB		lg_l3d_vb_from_axis(LG_XYZ_Axis);

/* (all Vertex_rgba until here) */

/* MOSTLY DEPRECATED - should cleanup/reorganize/rewrite some of following stuff, which is a bit of a mess */

const Vertex_uv		*lg_cube_normalized_vertices_uv();

const unsigned short	*lg_cube_vertex_uv_indices();

size_t			lg_sizeof_cube_normalized_vertices_uv();

size_t			lg_sizeof_cube_vertex_uv_indices();

const Vertex_rgba	*lg_cube_normalized_vertices_rgba();

const unsigned short	*lg_wired_cube_vertex_rgba_indices();

size_t			lg_sizeof_cube_normalized_vertices_rgba();

size_t			lg_sizeof_wired_cube_vertex_rgba_indices();

#endif /* LG_3D_PRIMITIVES_H */
