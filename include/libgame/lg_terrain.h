/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_TERRAIN_H
#define LG_TERRAIN_H

#define HEIGHTMAP_MAX_W		1024
#define HEIGHTMAP_MAX_H		1024

#define HEIGHTMAP_MIN_W		8
#define HEIGHTMAP_MIN_H		8

/**
 * \enum
 * lg_noise_type
 */
typedef enum {
	RANDOM_NOISE,
	PERLIN_NOISE,
	OPENSIMPLEX2_NOISE,
	CELLULAR_NOISE		/* = VORONOI_NOISE */
	/*
	OPENSIMPLEX2S_NOISE
	VALUE_CUBIC_NOISE
	VALUE_NOISE
	*/
} lg_noise_type;

typedef enum {
	TERRAIN_TYPE1,
	TERRAIN_TYPE2,
	TERRAIN_TYPE3
} lg_terrain_type;

/**
 * \struct
 * LG_Terrain
 */
typedef struct {
	Vertex_uv_n	*vbo_data;	/* VBO (with interleaved vertex data) - sizeof(Vertex_uv_n) = 24 */
	uint32_t	*ibo_data;	/* IBO (indices start at 0) - sizeof(uint32_t) = 4 */
	uint32_t	vbo_size;
	uint32_t	ibo_size;
	uint32_t	n_vertices;
	uint32_t	n_faces;
	uint32_t	n_indices;	/* Needed ? Always = n_faces * 3 */
	LG_Texture	*tex;
	float		w;
	float		h;
	float		min_h;
	float		max_h;
} LG_Terrain;

LG_Terrain		*lg_terrain_new(uint16_t, uint16_t, float, int, int, float, LG_Texture *);

LG_Terrain		*lg_terrain_new_from_heightmap(Vertex_uv_n *, uint16_t, uint16_t, float, LG_Texture *);

void			lg_terrain_free(LG_Terrain *);

float			*lg_generate_heightmap(int, int, int, int, float);

LG_Mesh			*lg_terrain_to_mesh(LG_Terrain *);

Vertex			*lg_horiz_grid(int, int *, float);

// DEPRECATED
const Vertex		*lg_horiz_grid0();

const unsigned short	*lg_horiz_grid0_indices();

size_t			lg_sizeof_horiz_grid0();

size_t			lg_sizeof_horiz_grid0_indices();

#endif /* LG_TERRAIN_H */
