/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_RENDER_H
#define LG_RENDER_H

#define LG_N_MAX_DRAWS	N_MAX_USEMTL_PER_OBJ

typedef struct {
	unsigned int	n_draws;
	int		u_tex;
	unsigned int	tex_id[LG_N_MAX_DRAWS];
	int		tex_unit[LG_N_MAX_DRAWS];
	unsigned long	size[LG_N_MAX_DRAWS];		/* In VBO */
	unsigned long	shift[LG_N_MAX_DRAWS];		/* In IBO */
} LG_DrawElements_Cmd;

int	lg_mesh_to_drawelements_cmd(LG_Mesh *, int, LG_DrawElements_Cmd *);

void	lg_draw_elements(LG_DrawElements_Cmd *);

void	lg_drawelements_info(LG_DrawElements_Cmd *);

#endif /* LG_RENDER_H */
