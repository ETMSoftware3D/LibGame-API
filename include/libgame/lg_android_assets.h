/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_ANDROID_ASSETS_H
#define LG_ANDROID_ASSETS_H

void	*jni_get_android_asset(const char *, size_t *);

int	jni_free_android_asset();

int	jni_free_all();

#endif /* LG_ANDROID_ASSETS_H */
