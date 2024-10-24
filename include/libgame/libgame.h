/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 *
 *	LibGame is a SDL2/OpenGL ES 2.0 2D/3D minimalist game engine, which doesn't
 *	attempt to do *everything* but does only certain things and does them *well*,
 *	while not preventing you from doing other things (huh ?)
 *
 *	This version supports both Linux Desktop and Android (with NDK).
 */

#ifndef LIBGAME_H
#define LIBGAME_H

#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif
#ifndef _ISOC11_SOURCE
  #define _ISOC11_SOURCE
#endif

#define LIBGAME_NAME			"LibGame"
#define LIBGAME_V_NUM			"0.4.0"
#define LIBGAME_COPYRIGHT_STR		"Copyright (C) Emmanuel Thomas-Maurin 2012-2024 - All rights reserved"

#define LIBGAME_WEBSITE			"https://www.etmsoftware.com"	/*"https://www.aetm-games.com"*/
#define LIBGAME_DOWNLOAD_WEBSITE	LIBGAME_WEBSITE "/download.php"
#define LIBGAME_SUPPORT_WEBSITE		LIBGAME_WEBSITE "/help.php"
#define LIBGAME_SUPPORT_EMAIL		"support@etmsoftware.com"	/*"manu@manutm.net"*/

#if !defined(ANDROID_V) && !defined(WIN32_V)
  #define LINUX_V
#endif

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <byteswap.h>
#include <stdalign.h>
#ifndef WIN32_V			/* Linux and Android versions */
  #include <grp.h>
  #include <pwd.h>
  #include <signal.h>
#else
  #include <direct.h>
#endif

#ifdef ANDROID_V
  #include <jni.h>
  #include <android/log.h>
#endif

#ifndef WIN32_V			/* Linux and Android versions */
  #include <SDL.h>
  #include <SDL_image.h>
  #include <SDL_mixer.h>
  #include <SDL_ttf.h>
  #include <SDL_syswm.h>
  #ifdef LINUX_V
    #include <SDL_mouse.h>
  #endif
#else				/* Not tested */
  #include <SDL.h>
  #include <SDL2/SDL_image.h>
  #include <SDL2/SDL_mixer.h>
  #include <SDL2/SDL_ttf.h>
  #include <SDL_mouse.h>
  #include <SDL_syswm.h>
#endif

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

/* Logging stuff for libetm - must appear before #include libetm.h */
#define LIBETM_VERBOSE_OUTPUT
/*#define LIBETM_DEBUG_OUTPUT*/

/* LIBETM_DEBUG_OUTPUT implies LIBETM_VERBOSE_OUTPUT */
#ifdef LIBETM_DEBUG_OUTPUT
  #ifndef LIBETM_VERBOSE_OUTPUT
    #define LIBETM_VERBOSE_OUTPUT
  #endif
#endif

#ifdef ANDROID_V
  #include "../extra_libs/libetm-0.5.1/libetm.h"
#else
  #ifndef WIN32_V	/* Linux version */
    #include <libetm/libetm.h>
  #else
    #include "../extra_libs/libetm-0.5.1/libetm.h"
  #endif
#endif

#ifndef ANDROID_V
  #undef INFO_ERR
  #define INFO_ERR INFO_ERR2
#endif

/* Logging stuff for libgame */
#define VERBOSE_OUTPUT
/*#define DEBUG_OUTPUT*/

/* DEBUG_OUTPUT implies VERBOSE_OUTPUT */
#ifdef DEBUG_OUTPUT
  #ifndef VERBOSE_OUTPUT
    #define VERBOSE_OUTPUT
  #endif
#endif

//#define FUNC2(...)		FUNC1(hello, __VA_ARGS__)

#define TMPSTR_SIZE		((4 * 1024) - 1)	/* = 4 KiB - 1 */
#define FILE_NAME_MAXLEN	TMPSTR_SIZE

#ifdef LIBGAME_COMPILE_TIME
  #include "../extra_libs/math_3d.h"
  #include "../extra_libs/stb_image.h"
#else
  #include <libgame/extra_libs/math_3d.h>
  #include <libgame/extra_libs/stb_image.h>
#endif

/* What order for header files ? */
/* "lg_env_instance.h" is included after typedef of LG_Env */
#include "lg_vbo.h"
#include "lg_shader_progs.h"
#include "lg_vertex.h"
#include "lg_gr_func.h"
#include "lg_textures.h"
#include "lg_dds_loader.h"
#include "lg_astc_loader.h"
#include "lg_linked_list.h"
#include "lg_sprites.h"
#include "lg_background.h"
#include "lg_wins.h"
#include "lg_keyboard.h"
#include "lg_mouse.h"
#include "lg_touchscreen.h"
#include "lg_audio.h"
#include "lg_dirs_stuff.h"
#include "lg_misc.h"
#include "lg_quaternions.h"
#include "lg_ui.h"
#include "lg_camera.h"
#include "lg_3d_primitives.h"
#include "lg_opengl_2d.h"
#include "lg_mesh.h"
#include "lg_light.h"
#include "lg_scene_graph.h"
#include "lg_collision_detect.h"
#include "lg_obj_parser.h"
#include "lg_admob.h"
#include "lg_vao_gl_ext.h"
#include "lg_cubemap.h"
#include "lg_error.h"
#include "lg_file_ops.h"
#include "lg_android_assets.h"
#include "lg_render.h"
#include "lg_terrain.h"
#include "lg_perlin_noise.h"
#include "lg_frame.h"
#include "lg_landscape.h"

typedef enum {
	LG_OK = LIBETM_LASTERRORCODE + 1,
	LG_ERROR,
	LG_INIT_ERROR,
	LG_EXTRA_LIB_INIT_ERROR,
	LG_OPENGL_ERROR,
	LG_GLSL_ERROR,
	LG_CREATE_FILE_ERROR,
	LG_OPEN_FILE_ERROR,
	LG_SAVE_FILE_ERROR,
	LG_READ_FROM_FILE_ERROR,
	LG_WRITE_TO_FILE_ERROR,
	LG_FILE_ACCESS_ERROR,
	LG_READ_FROM_FILE_EOF,
	LG_EOF,
	LG_OOM,
	LG_INVALID_PTR,
	/* Unix signals */
	LG_BUSERR,		/* SIGBUS	Bus error (bad memory access) */
	LG_FPE,			/* SIGFPE	Floating-point exception */
	LG_ILL,			/* SIGILL	Illegal Instruction */
	LG_SEGFAULT,		/* SIGSEGV	Invalid memory reference */
	/* Must really be the last one */
	LG_LASTERRORCODE
} lg_error_code;

typedef enum {
	LG_CONTINUE = LG_LASTERRORCODE + 1,
	LG_CANCEL,
	LG_QUIT,
	LG_WON,
	LG_LOST,
	LG_LASTRETURNCODE
} lg_return_code;

/*
 * WIN_LOGICAL_W and WIN_LOGICAL_H must be defined in app
 *	16/9 or (on new mobiles) 18/9 ?
 *	#define WIN_LOGICAL_W		1000
 *	#define WIN_LOGICAL_H		500
 * On Android, we *always* want/use landscape orientation
 */
#define LG_WIN_WIDTH_MIN		800
#define LG_WIN_HEIGHT_MIN		400

#define LG_WIN_D_HEIGHT_HACK		2	/* DIRTY HACK: We want the whole win to be visible */

/* Requested bit-depth */
#define LG_REQUESTED_RED_SIZE		5
#define LG_REQUESTED_GREEN_SIZE		6
#define LG_REQUESTED_BLUE_SIZE		5
#define LG_REQUESTED_ALPHA_SIZE		0
#define LG_REQUESTED_DEPTH_SIZE		16
#define LG_REQUESTED_STENCIL_SIZE	8

/*
 * === LibGame environnement struct ===
 * This is also a spec that the code is supposed to implement
 * (should be like that for all comments.)
 *
 * === Libgame coord sys = SDL coord sys (y axis goes down) != OpenGL coord sys (y axis goes up) ===
 * - SDL uses int's in [0 - win_w] x [0 - win_h] with origin at top left corner
 * - OpenGL uses float's in [-1.0f, 1.0f] x [-1.0f, 1.0f] with origin at center
 * - OpenGL win uses int's in [0 - gl_win w] x [0 - gl_win h] with origin at bottom left corner
 * (-> glViewport() and glScissor() coord sys is (0, 0) = bottom-left, in pixels)
 *
 * ==============================================================================================
 * Anyways, to avoid endless confusion, make sure to always mention coord sys in func definition
 * ==============================================================================================
 */
typedef struct {
	/*
	 * SDL display mode stuff
	 */
	int		sdl_display;
	SDL_DisplayMode	sdl_display_mode;
	int		sdl_convert_surf_format;		/* For all SDL_ConvertSurfaceFormat() ops */
	int		sdl_create_rgb_surf_bitdepth;		/* For all SDL_CreateRGBSurface() ops */
	int		r_size, g_size, b_size, a_size;
	uint32_t	r_mask, g_mask, b_mask, a_mask;		/* SDL interprets each pixel as a 32-bit integer */
	/*
	 * Screen dims
	 */
	int		screen_w;
	int		screen_h;
	/*
	 * OpenGL ES 2.0 stuff
	 */
	SDL_Window	*gl_win;				/* Top SDL/GL win */
	SDL_GLContext	gl_context;
	/*
	 * Top win dims are virtual/logical dims in fullscreen mode.
	 * In fullscreen mode, we compute an optimal viewport_rect (with letterboxing)
	 * and use scaling, keeping the same aspect ratio (like SDL2 with render logical size set).
	 * In windowed mode, viewport_rect and gl_win rect have the same size.
	 */
	int		top_win_logical_w;	/* In fullscreen mode, logical w */
	int		top_win_logical_h;	/* In fullscreen mode, logical h */
	Rec2Di		viewport_rect;		/* THE DEFAULT VIEWPORT, COMPUTED DURING INIT, MUST *NOT* BE MODIFIED AFTERWARDS */
	zboolean	fullscreen;		/* Should always be set to TRUE on Android ? Seems it's expected from SDL */
	float		fullscreen_scale;	/* MIN(scale_x, scale_y), to keep aspect ratio */
	/*
	 * Texture max values
	 */
	int		max_combined_texture_image_units;
	int		max_texture_size;
	int		max_cubemap_texture_size;
	/*
	 * Background
	 */
	GLuint		lg_backgroud_tex_id;
	LG_Color_u	bg_color;		/* Always set after a call to lg_clear_bg() */
	int		bg_shift_x;		/* Not sure what the purpose was exactly */
	int		bg_shift_y;		/* Not sure what the purpose was exactly */
	/*
	 * App stuff
	 */
	char 		*app_name;
	char 		*app_cmd;
	char		*org_name_android;	/* Android-specific */
	char		*app_name_android;	/* Android-specific */
	char		*assets_dir;		/* App data dir on Linux, app assets on Android */
	char		*app_wr_dir;		/* App home dir on Linux, app-specific writable persistent dir on Android */
	char		*vbo_cache;
	char		*obj_cache;
	/*
	 * OpenGL ES extensions support
	 */
	zboolean	oes_vao_extension;
	void		(*glGenVertexArraysOES)(GLsizei, GLuint *);
	void		(*glBindVertexArrayOES)(GLuint);
	void		(*glDeleteVertexArraysOES)(GLsizei, const GLuint *);
	zboolean	(*glIsVertexArrayOES)(GLuint);
	zboolean	oes_element_index_uint_extension;
	zboolean	ext_texcompr_s3tc_extension;
	zboolean	oes_texcompr_etc1_rgb8_extension;
	zboolean	khr_texcompr_astc_ldr_extension;
	//zboolean	khr_texcompr_astc_hdr_extension;
	//zboolean	ext_texcompr_astc_decode_mode_extension;
	// NEW: any good ?
	LG_ErrorContext	last_error_context;
	// NEW: any good ?
	LG_Sound	**sounds;		/* Unused so far */
	//
	zboolean	fonts_loaded;
} LG_Env;

#include "lg_env_instance.h"

#define GAME_FONT1	"DejaVuSans-Bold.ttf"
#define GAME_FONT2	"PAPYRUS.ttf"
#define GAME_FONT3	"intelone-mono-font-family-bold.ttf"

/* (From: https://cloford.com/resources/charcodes/utf-8_arrows.htm) */
#define UTF8_LW_LIGHT_ARROW	"\u2190"	/* Light leftwards arrow */
#define UTF8_RW_LIGHT_ARROW	"\u2192"	/* Light rightwards arrow */
#define UTF8_UW_LIGHT_ARROW	"\u2191"	/* Light upwards arrow */
#define UTF8_DW_LIGHT_ARROW	"\u2193"	/* Light downwards arrow */

/* (From: https://cloford.com/resources/charcodes/utf-8_dingbats.htm) */
#define UTF8_RW_ROUNDED_ARROW	"\u279c"	/* Rounded rightwards arrow */

int		lg_init(int, int, const char *, const char *, const char *, const char *, const char *, const char *, const char *);

Rec2Di		lg_get_default_viewport();

void		lg_set_new_viewport(Rec2Di);

void		lg_reset_viewport();

void		lg_list_opengl_extensions();

int		lg_load_fonts();

void		lg_quit(int);

void		lg_swap_fb();

void		lg_show_lib_info();

void		lg_show_sys_info();

void		lg_show_extra_sys_info(SDL_Window *);

zboolean	sdl2_is_installed();

/* Must be freed afterwards with l_str_free() */
char		*lg_get_sdl_win_flags(SDL_Window *);

#endif /* LIBGAME_H */
