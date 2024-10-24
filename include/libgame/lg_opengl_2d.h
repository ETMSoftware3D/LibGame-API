/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_OPENGL_2D_H
#define LG_OPENGL_2D_H

typedef struct {
	LG_ShaderProg 	line_shader;
	LG_VAO		line_vao;
	LG_VBO		line_vbo;
	int		u_line_color;

	LG_ShaderProg 	rect_shader;
	LG_VAO		rect_vao;
	LG_VBO		rect_vbo;
	int		u_rect_color;

	LG_ShaderProg 	tex_shader;
	LG_VAO		tex_vao;
	LG_VBO		tex_vbo;
	int		u_tex;
} LG_Renderer2D;

int		lg_init_renderer_2d();

void		lg_free_renderer_2d();

int		lg_render_line_2d(int, int, int, int, LG_Color_u);

int		lg_render_rect_2d(Rec2Di, LG_Color_u);

int		lg_render_tex_2d(const LG_Texture *, const Rec2Di *, const Rec2Di *);

#endif /* LG_OPENGL_2D_H */
