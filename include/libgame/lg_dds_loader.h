/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_DDS_LOADER_H
#define LG_DDS_LOADER_H

#define DDS_MAGIC_SIZE			((size_t)4)
#define DDS_MAGIC_AND_HEADER_SIZE	((size_t)128)

/* (From dds.h) */
#define DDS_HEADER_FLAGS_TEXTURE	0x00001007	/* DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT | DDSD_CAPS */
#define DDS_HEADER_FLAGS_LINEARSIZE	0x00080000	/* DDSD_LINEARSIZE */
#define DDS_HEADER_FLAGS_MIPMAP		0x00020000	/* DDSD_MIPMAPCOUNT */

/* (From DDSTextureLoader9.cpp) */
#define MAKEFOURCC(ch0, ch1, ch2, ch3) \
	((uint32_t)(uint8_t)(ch0) | ((uint32_t)(uint8_t)(ch1) << 8) | \
	((uint32_t)(uint8_t)(ch2) << 16) | ((uint32_t)(uint8_t)(ch3) << 24 ))

typedef struct __attribute__((packed)) {
	uint32_t	size;
	uint32_t	flags;
	uint32_t	sig_4cc;	/* "DXT1" or "DXT3" */
	uint32_t	rgb_bitcount;
	uint32_t	r_mask;
	uint32_t	g_mask;
	uint32_t	b_mask;
	uint32_t	a_mask;
} DDS_PixelFormat;

typedef struct __attribute__((packed)) {
	uint32_t	size;		/* 124 */
	uint32_t	flags;		/* Always include DDSD_CAPS, DDSD_PIXELFORMAT, DDSD_WIDTH, DDSD_HEIGHT and either DDSD_PITCH or DDSD_LINEARSIZE */
	uint32_t	h;		/* h first - duh! */
	uint32_t	w;
	uint32_t	pitch_or_linear_size;
	uint32_t	depth;
	uint32_t	mipmap_count;
	uint32_t	reserved1[11];
	DDS_PixelFormat	pixel_format;
	uint32_t	caps;
	uint32_t	caps2;
	uint32_t	caps3;
	uint32_t	caps4;
	uint32_t	reserved2;
} DDS_Header;

void	*lg_load_dds(const char *, lg_tc_format *, size_t *, int *, int *, int *);

#endif /* LG_DDS_LOADER_H */
