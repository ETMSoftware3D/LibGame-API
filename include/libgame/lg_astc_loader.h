/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_ASTC_LOADER_H
#define LG_ASTC_LOADER_H

typedef struct __attribute__((packed)) {
	uint8_t		magic[4];
	uint8_t		block_x;
	uint8_t		block_y;
	uint8_t		block_z;	/* 1 for 2D images */
	uint8_t		dim_x[3];	/* (24-bit unsigned value) decoded_dim = dim[0] + (dim[1] << 8) + (dim[2] << 16) */
	uint8_t		dim_y[3];
	uint8_t		dim_z[3];	/* 1 for 2D images */
} ASTC_Header;

typedef struct __attribute__((packed)) {
	char		sig[4];		/* "PKM " */
	char		version[2];	/* "10" or "20" */
	uint16_t	data_type;	/* 0 = ETC1_RGB_NO_MIPMAPS */
	uint16_t	width;		/* uint16_t big-endian */
	uint16_t	height;
	uint16_t	orig_width;
	uint16_t	orig_height;
} PKM_Header;

void	*lg_load_astc(const char *, lg_tc_format *, size_t *, int *, int *, int *);

void	*lg_load_etc1(const char *, lg_tc_format *, size_t *, int *, int *, int *);

#endif /* LG_ASTC_LOADER_H */
