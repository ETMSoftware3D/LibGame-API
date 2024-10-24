/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_DIRS_STUFF_H
#define LG_DIRS_STUFF_H

#define IMAGES_DIR	"images"
#define SOUNDS_DIR	"sounds"
#define MUSIC_DIR	"music"
#define FONTS_DIR	"fonts"
#define MESHES_DIR	"meshes"

const char	*lg_img(const char *);

const char	*lg_snd(const char *);

const char	*lg_mus(const char *);

const char	*lg_fnt(const char *);

const char	*lg_mesh(const char *);

const char	*lg_assets_file(const char *, const char *);

const char	*lg_app_wr_file(const char *);

#endif /* LG_DIRS_STUFF_H */
