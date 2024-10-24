/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_LANDSCAPE_H
#define LG_LANDSCAPE_H

#define QUADTREE_MAX_DEPTH	8

/* NOT SHOWING ENUMS IN DOC, DAMNIT! */

typedef enum {LG_NW = 0, LG_NE, LG_SW, LG_SE} lg_quadtree_quadrant;

/* QT = QuadTree */
typedef struct LG_QTNode LG_QTNode;

struct LG_QTNode {
	Rec2Df		bounds;		/* Or bounding_r */
	LG_QTNode	*child[4];	/* NW, NE, SW, SE */
	zboolean	is_leaf;
	void		*data;		/* Terrain, tile, mesh, object, ... */
};

LG_QTNode	lg_landscape(Rec2Df, void *);

void		lg_landscape_add_child(LG_QTNode *, LG_QTNode *, lg_quadtree_quadrant);

void		lg_traverse_landscape(LG_QTNode *, int, int (*)(), int (*)(), void *);

#endif /* LG_LANDSCAPE_H */
