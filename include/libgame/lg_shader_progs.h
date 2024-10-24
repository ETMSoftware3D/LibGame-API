/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_SHADER_PROGS_H
#define LG_SHADER_PROGS_H

typedef struct {
	unsigned int	id;
} LG_ShaderProg;

/* Vertex Attrib Pointer params */
typedef struct {
	int32_t		index;
	const char	*name;
	uint32_t	num_components;			/* 1 to 4 */
	int32_t		type;				/* One of GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT, GL_FIXED, GL_FLOAT */
	zboolean	do_normalize;
	size_t		stride;				/* Byte offset between consecutive generic vertex attributes */
	void		*first_component_offset;	/* For instance: offsetof(Vertex_uv_n, u) */
} LG_VAP_params;

#define VAP_END		{-1, NULL, 0, 0, 0, 0, NULL}

#define CHECK_GL_E	lg_check_gl_errors(lg_log_time(), __FILE__ , __LINE__, __func__)

#define CHECK_GL_E_2	{if (lg_check_gl_errors(lg_log_time(), __FILE__, __LINE__, __func__) != LG_OK) exit(-1);}

#define STH_WRONG_HERE \
	{ \
		static int i = 0; \
		if (i == 0) { \
			INFO_OUT("VARO TÄSSÄ\n%s [%s: %d] %s(): jotain pitää korjata\n", UTF8_RW_ROUNDED_ARROW, __FILE__, __LINE__, __func__) \
			i++; \
		} \
	}

int		LG_ShaderProg_create(LG_ShaderProg *, const char **, const char **, LG_VAP_params *);

void		LG_ShaderProg_delete(LG_ShaderProg *);

void		LG_ShaderProg_use(LG_ShaderProg *);

int		LG_ShaderProg_get_attrib_loc(LG_ShaderProg *, const char *);

int		LG_ShaderProg_get_uniform_loc(LG_ShaderProg *, const char *);

uint32_t	lg_load_shader(int, const char **);

int		lg_check_gl_errors(long long, const char *, int, const char *);

void		lg_shader_info_log(uint32_t);

#endif /* LG_SHADER_PROGS_H */
