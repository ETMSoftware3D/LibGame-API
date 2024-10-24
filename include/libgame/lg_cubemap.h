/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_CUBEMAP_H
#define LG_CUBEMAP_H

typedef LG_Texture LG_CubeMap;

LG_CubeMap	*lg_cubemap_new(const char **);

void		lg_cubemap_free(LG_CubeMap *);

const Vertex	*lg_skybox();

size_t		lg_sizeof_skybox();

#endif /* LG_CUBEMAP_H */
