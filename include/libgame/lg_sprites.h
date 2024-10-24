/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_SPRITES_H
#define LG_SPRITES_H

#define LG_SPRITE_MIN_SIZE	4
#define SPRITE_N_DRAWS_MAX	1024

typedef struct {
	int		id;			/* (So far) 0 -> OK, -1 -> invalid sprite */
	/* === Setup at init - all images must be square and have same dims === */
	/* === Private - don't modify === */
	LG_Texture	*atlas_texture;		/* Texture atlas */
	int		atlas_side;		/* = width = height (square) */
	int		image_side;		/* = width = height (square) */
	int		atlas_side_for_n_images;
	zboolean	overflow;
	/* === Public but don't modify === */
	int		n_frames;
	int		w;
	int		h;
	zboolean	was_cloned;		/* Cloned objects_2d use same texture atlas as the original object */
	/* === Modifiable members === */
	int		current_frame;
	int		x;
	int		y;
	int		motion_x;
	int		motion_y;
	/* === Use but don't modify, set by lg_sprite_draw(LG_ON) */
	int		previous_frame;
	int		prev_x;			/* Set to x after draw(LG_ON), to be used by draw(LG_OFF) */
	int		prev_y;			/* Set to y after draw(LG_ON), to be used by draw(LG_OFF) */
	int		last_motion_x;
	int		last_motion_y;
	/* Used only by lg_save/restore_sprite_position() */
	int		x_bak;
	int		y_bak;
	/*
	 * To test ***objects collision*** if one object real size and position is
	 * very different from the object squared image
	 * Default value should be 0
	 */
	int		real_obj_diff_x;
	int		real_obj_diff_y;
	int		real_obj_diff_w;
	int		real_obj_diff_h;
	/* === Used only in BASP === */
	int		life_counter;
	int		down_counter;
	int		teleport_counter;
	int		random_motion_counter;
	int		timer[4];
} LG_Sprite;

/*
 * Rq_SDraw_Array stands for Requested Sprite Draw Array
 * Array of sprites to be drawed in batch - use linked list instead ?
 */
typedef struct {
	LG_Sprite	*sprite[SPRITE_N_DRAWS_MAX];
} Rq_SDraw_Array;

/* SDL coord sys */
#define LG_UP		(-1)
#define LG_DOWN		(1)
#define LG_LEFT		(-1)
#define LG_RIGHT	(1)

LG_Sprite	lg_sprite(const char *[], LG_Color_u, int, int);

int		lg_sprite_draw(LG_Sprite *);

void		lg_sprite_free_tex(LG_Sprite *);

void		lg_sprite_set_cur_frame(LG_Sprite *, int);

int		lg_sprite_get_cur_frame(LG_Sprite *);

LG_Sprite	lg_clone_sprite(LG_Sprite *);

int		lg_sprite_is_inside_rectangle(LG_Sprite *, Rec2Di *);

int		lg_sprite_is_inside_rectangle_set(LG_Sprite *, Rec2Di **);

int		lg_sprite_is_outside_rectangle(LG_Sprite *, Rec2Di *);

int		lg_sprite_is_outside_rectangle_set(LG_Sprite *, Rec2Di **);

int		lg_sprites_collide(LG_Sprite *, LG_Sprite *);

int		lg_sprite_centers_collide_by_x_y(LG_Sprite *, LG_Sprite *, int, int);

int		lg_sprite_centers_collide_by_k(LG_Sprite *, LG_Sprite *, int);

/*void		lg_move_sprite_inside_rectangle(LG_Sprite *, int, int, Rec2Di *);*/

void		lg_save_sprite_position(LG_Sprite *);

void		lg_restore_sprite_position(LG_Sprite *);

void		lg_sprite_info(LG_Sprite *);

void		lg_rqdraw_init(Rq_SDraw_Array *);

int		lg_rqdraw_add_sprite(LG_Sprite *, Rq_SDraw_Array *);

#endif /* LG_SPRITES_H */
