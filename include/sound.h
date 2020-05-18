/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** header for sounds
*/

#ifndef __SOUND_H__
#define __SOUND_H__

#include <stddef.h>

typedef struct sound_s {
    char *filepath;
    int volume;
} sound_t;

static const sound_t SOUND_INIT[] = {
    {"res/sound/player_hurt.ogg", 50},
    {"res/sound/bone_crack.ogg", 50},
    {"res/sound/found_object.ogg", 50},
    {"res/sound/mob_sound.ogg", 50},
    {"res/sound/bipbip.ogg", 100},
    {"res/sound/sword.ogg", 100},
    {"res/sound/walking.ogg", 50},
    {NULL, 20}
};

typedef enum {
    PLAYER_HURT,
    BONE_CRACK,
    FOUND_OBJECT,
    MOB_SOUND,
    BIPBIP,
    ATTACK,
    WALKING
} effect_type_t;

#endif /* __SOUND_H__ */
