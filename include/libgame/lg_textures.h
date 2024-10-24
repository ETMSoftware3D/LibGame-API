/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_TEXTURES_H
#define LG_TEXTURES_H

#define LG_TEX_PATH_MAX_LEN		(1024 - 1)

#define LG_FIRST_NODE_ID		500001
#define LG_INVALID_TEXTURE_ID		500002

#define LG_TEX_TYPE_UNKNOWN		-1

#define LG_MAX_TEX_UNITS		256

#define LG_CUBEMAP_FACES_NUM		6

typedef struct __attribute__((packed)) {
	uint8_t		sig[8];		/* {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a} */
	uint8_t		padding1[8];
	uint32_t	width;		/* Big-endian */
	uint32_t	height;		/* Big-endian */
} PNG_Header;

/* TODO: specify if mipmaps were generated ? */
typedef enum {
	LG_TC_UNCOMPRESSED,	/* Never with mipmaps */
	LG_TC_DXT1,
	LG_TC_DXT3,
	LG_TC_ASTC,		/* TODO: specify block size ? */
	LG_TC_ETC1,
	LG_TC_UNKNOWN
} lg_tc_format;

/*
 * Actually a texture node in textures doubly-linked list
 */
typedef struct LG_Texture LG_Texture;

struct LG_Texture {
	GLuint		id;		/* Texture 'handle', set to LG_INVALID_TEXTURE_ID if not valid */
	GLenum		unit;		/* GL_TEXTURE0 -> GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1 */
	int		type;		/* GL_TEXTURE_2D or GL_TEXTURE_CUBE_MAP (so far ...) */
	int		w;
	int		h;
	int		tc_format;	/* lg_tc_format enum */
	char		path[LG_TEX_PATH_MAX_LEN + 1];
	LG_Texture	*prev;
	LG_Texture	*next;
	LG_Texture	*this;		/* Copy of node mem block addr */
};

void		lg_init_textures_module();

LG_Texture	*lg_texture_new_from_data(lg_tc_format, int, const char *, void *, void **, size_t, int, int, int);

LG_Texture	*lg_texture_new_from_file(int, const char *);

SDL_Surface	*lg_sdl_surf_from_file(const char *, int, int);

void		*lg_compressed_texdata_from_file(const char *, lg_tc_format *, size_t *, int *, int *, int *);

zboolean	lg_test_file_extension(const char *, const char*);

int		lg_get_png_dims(const char *, int *, int *);
/*
 * === Doubly-linked list ops ===
 */
void		lg_texture_remove(LG_Texture *);

void		lg_texture_remove_all();

LG_Texture	*lg_texture_first(LG_Texture *);

LG_Texture	*lg_texture_last(LG_Texture *);

LG_Texture	*lg_texture_find_by_id(GLuint id);

int		lg_texture_count_nodes();

void		lg_texture_info(const LG_Texture *);

void		lg_texture_info_all();
/*
 * Other stuff
 */
zboolean	lg_read_pixels_from_screen(void *, Rec2Di);

zboolean	lg_write_pixels_to_screen(void *, const Rec2Di *);

void		lg_texture_unbind();

void		lg_tex_units_info();

unsigned int	lg_get_active_tex();

void		lg_active_tex_info();

void		lg_free_sdl_surf(SDL_Surface *);

int		lg_surf_depth(SDL_Surface *);

void		lg_info_out_read_framebuffer();

#endif /* LG_TEXTURES_H */
