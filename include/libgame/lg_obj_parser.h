/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_OBJ_PARSER_H
#define LG_OBJ_PARSER_H

#define LG_SPATIAL_COORD_HUGE_VALUE	10e9	/* = 1 000 000 000.0 - OK ? */

#define OBJPARSER_BBOX_COLOR		"purple"

typedef enum {
	WITH_COORDS_ONLY,
	WITH_TEXCOORDS,
	WITH_NORMALS,
	WITH_TEXCOORDS_AND_NORMALS
} lg_vertex_type;

LG_Mesh		*lg_obj2vbo(const char *, FILE *, zboolean);

int		lg_mtl_parser(const char *, LG_Material *[]);

int		lg_vertex_cmp(Vertex_uv_n *, Vertex_uv_n *, zboolean, zboolean);

void		lg_vbo_and_ibo_info(Vertex_uv_n *, uint32_t *, uint32_t, uint32_t, lg_vertex_type, int);

void		lg_vb_info(Vertex *, uint32_t, int, const char *, zboolean);

void		lg_vb_rgba_info(Vertex_rgba *, uint32_t, int, const char *, zboolean);

zboolean	lg_objparser_check_consistency();

#endif /* LG_OBJ_PARSER_H */
