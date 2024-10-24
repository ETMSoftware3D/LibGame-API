/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_AUDIO_H
#define LG_AUDIO_H

#define LG_AUDIO_MAX_VOL	MIX_MAX_VOLUME

typedef struct {
	char		file_name[FILE_NAME_MAXLEN + 1];
	Mix_Chunk	*sample;
	int		channel;
} LG_Sound;

typedef enum {
	LG_PLAY, LG_REPEAT, LG_WAIT, LG_STOP
} lg_play_mode;

int		lg_init_audio();

void		lg_free_audio();

int		lg_load_play_music(const char *, int);

zboolean	lg_music_is_playing();

void		lg_pause_music();

void		lg_resume_music();

void		lg_stop_music();

void		lg_free_music();

LG_Sound	*lg_sound_new(const char *);

int		lg_sound_play(lg_play_mode, LG_Sound *);

zboolean	lg_sound_is_playing(LG_Sound *);

void		lg_sound_free(LG_Sound *);

void		lg_audio_set_global_volume(float);

void		lg_audio_set_music_volume(float);

void		lg_audio_set_sounds_volume(float);

#endif /* LG_AUDIO_H */
