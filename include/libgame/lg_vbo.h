/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_VBO_H
#define LG_VBO_H

/*
 * === VBO ===
 */
typedef struct {
	unsigned int	id;
	unsigned int	size;
} LG_VBO;

int	LG_VBO_new(LG_VBO *, const void *, unsigned int);

int	LG_VBO_set_data(LG_VBO *, const void *);

void	LG_VBO_free(LG_VBO *);

void	LG_VBO_bind(LG_VBO *);

void	LG_VBO_unbind();

/*
 * === IBO ===
 */
typedef struct {
	unsigned int	id;
	unsigned int	size;
} LG_IBO;

int	LG_IBO_new(LG_IBO *, const void *, unsigned int);

int	LG_IBO_set_data(LG_IBO *, const void *);

void	LG_IBO_free(LG_IBO *);

void	LG_IBO_bind(LG_IBO *);

void	LG_IBO_unbind();

/*
 * === VAO ===
 */
typedef struct {
	unsigned int	id;
} LG_VAO;

int	LG_VAO_new(LG_VAO *);

void	LG_VAO_free(LG_VAO *);

void	LG_VAO_bind(LG_VAO *);

void	LG_VAO_unbind();

#endif /* LG_VBO_H */
