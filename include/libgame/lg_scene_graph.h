/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_SCENE_GRAPH_H
#define LG_SCENE_GRAPH_H

#define SCENENODE_NAME_MAX_LEN		(256 - 1)
#define SCENENODE_CHILD_MAX_NUM		1024
#define SCENENODE_SIG			"scene_node_bla_bla"	/* Is this useful or necessary ? */
#define SCENENODE_SIG_LEN		18			/* Make sure SCENENODE_SIG_LEN = strlen(SCENENODE_SIG) - See below */

#define IS_SCENENODE(node)		((node != NULL) && strcmp(node->sig, SCENENODE_SIG) == 0)
#define CHECK_SCENENODE(node)		{if (! IS_SCENENODE(node)) {INFO_ERR("Invalide node\n") return;}}

#define N_UNIFORMS_MAX			64
#define N_ATTRIBS_MAX			64

#define SCENE_GRAPH_MIN_DEPTH		4

// === STILL IN PROGRESS ===

typedef enum {
	ROOT,
	MESH,
	LINES3D,
	GRID,
	SKYBOX,
	LIGHT,
	SHADER_ONLY,
	UNDEFINED
} lg_scenenode_type;

typedef struct LG_SceneNode LG_SceneNode;

struct LG_SceneNode {
	int			id;			/* User-defined */
	char			name[SCENENODE_NAME_MAX_LEN + 1];
	lg_scenenode_type	type;			/* Mesh or grid or whatever */
	LG_SceneNode		*parent;
	LG_SceneNode		*child[SCENENODE_CHILD_MAX_NUM];
	unsigned int		n_child;
	char			sig[SCENENODE_SIG_LEN + 1];
	LG_Mesh			*mesh;
	Lines3D_VB		lines3d_vb;		/* Line set vertex buffer and num of vertices */
	mat4_t			local_matrix0;		/* "Private' member */
	mat4_t			world_matrix0;		/* "Private' member */
	mat4_t			*local_matrix;		/* Adjust (S-T-R) the mesh/lines3d_vb in its local space */
	mat4_t			*world_matrix;		/* Put (S-T-R) the mesh/lines3d_vb in world space */
	LG_Camera		*cam;			/* Current cam */
	LG_Light		*lights;		/* Current lights */
	LG_ShaderProg 		shader_prog;
	LG_VAO			vao;
	int			attrib[N_ATTRIBS_MAX];
	int			uniform[N_UNIFORMS_MAX];
	/* This is a mess */
	int			u_matrix;
	int			u_light_type;
	int			u_light_pos;
	int			u_light_dir;
	int			u_light_color;
	int			u_mat_color;
	int			u_texcoords;
	int			u_luminosity_k;
	float			mesh_color[4];		/* Only color so far */
	LG_Texture		*tex_1;			/* For textures other than thoses from mesh mtl file */
	void			*data;			/* Some generic data - NEVER USED so far */
	size_t			data_size;		/* NEVER USED so far */
};

LG_SceneNode	*lg_scenenode_new(int, const char *, lg_scenenode_type, LG_Camera *, LG_Light *, void *, size_t);

void		lg_scenenode_add_child(LG_SceneNode *, LG_SceneNode *);

void		lg_scenenode_remove_child(LG_SceneNode *, LG_SceneNode *);

void		lg_scenenode_free(LG_SceneNode *);

LG_SceneNode	*lg_scenenode_get_root(LG_SceneNode *);

void		lg_scenenode_remove_and_free_all(LG_SceneNode *);

void		lg_traverse_scene_graph(LG_SceneNode *, int, int (*)());

void		lg_traverse_printout_scene_graph(LG_SceneNode *, int);

void		lg_scenenode_reset_local_matrix(LG_SceneNode *);

void		lg_scenenode_set_local_matrix(LG_SceneNode *, vec3_t, vec3_t, LG_Quat);

void		lg_scenenode_update_local_matrix(LG_SceneNode *, vec3_t, vec3_t, LG_Quat);

void		lg_scenenode_update_world_matrix_tree(LG_SceneNode *, mat4_t *);

void		lg_scenenode_set_world_matrix(LG_SceneNode *, vec3_t, vec3_t, LG_Quat);

void		lg_scenenode_link_cam(LG_SceneNode *, LG_Camera *);

void		lg_scenenode_link_lights(LG_SceneNode *, LG_Light *);

void		lg_scenenode_attach_to_cam(LG_SceneNode *, const LG_Camera *, vec3_t);

void		lg_scenenode_clone_mat_l3dvb(LG_SceneNode *, LG_SceneNode *);

void		lg_scenenode_info(LG_SceneNode *);

int		lg_scenenode_check_consistency();	/* Only for init-time checking */

#endif /* LG_SCENE_GRAPH_H */
