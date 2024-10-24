/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_COLLISION_DETECT_H
#define LG_COLLISION_DETECT_H

/* Axis-aligned bounding box */
typedef struct {
	float		min_x;
	float		max_x;
	float		min_y;
	float		max_y;
	float		min_z;
	float		max_z;
} LG_BBox;

/* Bounding sphere */
typedef struct {
	vec3_t	center;
	float	radius;
} LG_BSphere;

LG_BBox		lg_bbox(float, float, float, float, float, float);

LG_BBox		lg_bbox_from_cuboid(LG_Cuboid *);

LG_Cuboid	lg_cuboid_from_bbox(LG_BBox, LG_Color_u);

LG_BBox		lg_bbox_from_mesh(LG_Mesh *);

LG_BBox		lg_bbox_transform(LG_BBox, mat4_t);

/* Not sure about that so discarded for now
zboolean	lg_bbox_is_AA(LG_BBox *);*/

vec3_t		lg_bbox_get_center(LG_BBox *);

zboolean 	lg_bboxes_collide(LG_BBox *, LG_BBox *);

zboolean	lg_bbox_sets_collide(LG_BBox **, LG_BBox **);

Lines3D_VB	lg_l3d_vb_from_bbox(LG_BBox, LG_Color_u);

void		lg_bbox_info(LG_BBox *);

LG_BSphere	lg_bsphere(float, float, float, float);

LG_BSphere	lg_bsphere_from_bbox(LG_BBox);

LG_BSphere	lg_bsphere_from_mesh(LG_Mesh *);

zboolean 	lg_bspheres_collide(LG_BSphere *, LG_BSphere *);

zboolean	lg_bsphere_sets_collide(LG_BSphere **, LG_BSphere **);

void		lg_bsphere_info(LG_BSphere);

#endif /* LG_COLLISION_DETECT_H */
