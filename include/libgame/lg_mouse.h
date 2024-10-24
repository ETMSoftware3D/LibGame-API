/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_MOUSE_H
#define LG_MOUSE_H

uint32_t	lg_get_mouse_motions(int *, int *);

zboolean	lg_get_mouse_wheel_motions(int *);

zboolean	lg_get_mouse_everything(int *, int *, int *);

void		lg_flush_mouse_buf();

#endif /* LG_MOUSE_H */
