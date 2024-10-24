/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_FILE_OPS_H
#define LG_FILE_OPS_H

#ifdef ANDROID_V
  #define OPEN_ASSET_FILE	lg_open_android_asset

  #define GET_ASSET_SIZE	lg_get_android_asset_size

  #define READ_ASSET_FILE	lg_read_from_android_asset

  #define CLOSE_ASSET_FILE	lg_close_android_asset
#else
  #define OPEN_ASSET_FILE	lg_open_file

  #define GET_ASSET_SIZE	lg_get_file_size

  #define READ_ASSET_FILE	lg_read_from_bfile

  #define CLOSE_ASSET_FILE	lg_close_file
#endif

void		*lg_open_file(const char *, const char *);

long long	lg_get_file_size(const char *);

int		lg_read_from_bfile(const char *, void *, size_t);

int		lg_write_to_bfile(const char *, void *, size_t);

void		lg_close_file(FILE *);

/* For Android assets */
void		*lg_open_android_asset(const char *, const char *);

long long	lg_get_android_asset_size(const char *);

int		lg_read_from_android_asset(const char *, void *, size_t);

void		lg_close_android_asset(void *);

/* NUA */
char		*lg_getline_from_str(const char *);

#endif /* LG_FILE_OPS_H */
