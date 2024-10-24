/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_MESH_H
#define LG_MESH_H

#define MESH_NAME_MAX_LEN	(512 - 1)
#define MAT_NAME_MAX_LEN	(64 - 1)
#define N_MAX_MAT_PER_OBJ	64		/* Or N_MAX_MAT_PER_MTL ? */
#define N_MAX_USEMTL_PER_OBJ	256		/* 4096 ? */

#define LG_FLOAT_EPSILON	1e-8		/* OK ? */

#define	LG_VBO_CACHE		"vbo_cache"
#define MAX_FILE_EXT_LEN	64		/* Extension length must not exceed that */
#define LG_MESH_INFO_EXT	".info"
#define LG_MESH_VBO_EXT		".vbo"
#define LG_MESH_IBO_EXT		".ibo"

#define	LG_OBJ_CACHE		"obj_cache"	/* Only used on Android so far */

#define LG_OBJ_FILE_MAXSIZE	((size_t)50 * (size_t)(1024 * 1024))	/* 50 MiB */

#define CHECK_PATH(_z_)		INFO_OUT("DEBUG: [%s %d]: %s() -> %s\n", lg_basename(__FILE__), __LINE__, __func__, _z_)

/* NEW - not really used so far */
typedef enum {
	LG_MESH_OBJ,
	LG_MESH_TERRAIN,
	LG_MESH_SKYBOX,
	LG_MESH_OTHER
} lg_mesh_type;

typedef struct {
	char		name[MAT_NAME_MAX_LEN + 1];
	uint32_t	indice;				/* Material face indice in VBO (uint32_t with GL_OES_element_index_uint extension) */
	LG_Texture	*texture;
} LG_Material;

/*
 * === Triangle mesh ===
 *
 * We want the same type sizes in binary files on all suppored platforms
 * (ie Linux and Android so far) to avoid portability issues, so we now
 * use fixed-size types (uint32_t, int32_t, ...) a lot for vertices structs
 * and buffer objects.
 *
 * In OBJ file:
 *	- 'mtllib'	-> obj_file.mtl
 *	- 'usemtl'	-> material name
 *
 * In MTL file:
 *	- 'newmtl'	-> material name
 *	- 'map_K*'	-> texture path
 */
typedef struct {
	lg_mesh_type	type;					/* NEW - not really used so far */
	char		name[MESH_NAME_MAX_LEN + 1];		/* Originally the OBJ file pathname */
	/* Generated VBO and IBO */
	Vertex_uv_n	*vbo_data;				/* VBO (with interleaved vertex data) - sizeof(Vertex_uv_n) = 24 */
	uint32_t	*ibo_data;				/* IBO (indices start at 0) - sizeof(uint32_t) = 4 */
	uint32_t	vbo_size;				/* previously size_t */
	uint32_t	ibo_size;				/* previously size_t */
	/* Read from obj file */
	int32_t		n_v;					/* Num of coords vertices */
	int32_t		n_vt;					/* Num of texture coords */
	int32_t		n_vn;					/* Num of normals */
	int32_t		n_f;					/* Num of faces */
	/* Materials */
	char		mtl_file[MESH_NAME_MAX_LEN + 1];	/* The MTL file path */
	int32_t		n_mat;					/* Num of materials (with textures) in MTL file */
	int32_t		n_usemtl;				/* Num of usemtl tags in OBJ file */
	LG_Material	materials[N_MAX_USEMTL_PER_OBJ];	/* Materials referenced by usemtl tags */
	/* Bounding box */
	float		min_x;
	float		max_x;
	float		min_y;
	float		max_y;
	float		min_z;
	float		max_z;
	/* Bounding cuboid */
	LG_Cuboid	bounding_cuboid;
	/* Lines3D_VB from bounding box cuboid */
	Lines3D_VB	lines3d_vb;
	/* Optionnal xyz normalizing */
	zboolean	xyz_normalized;
	GLdouble	normalize_k;
} LG_Mesh;

LG_Mesh	*lg_load_vbo(const char *, zboolean, zboolean);

LG_Mesh	*lg_mesh_new_from_objfile(const char *, zboolean);

void	lg_mesh_free(LG_Mesh *);

void	lg_mesh_info(LG_Mesh *);

int	lg_obj_file_save_to_cache(void *, const char *, size_t, size_t *);

void	*lg_obj_file_open_from_cache(const char *);

int	lg_vbo_save_to_file(const char *, LG_Mesh *);

int	lg_vbo_load_from_file(const char *, LG_Mesh **);

#if 0
int	lg_rebuild_vbo_and_ibo(LG_Mesh *);
#endif

#endif /* LG_MESH_H */
