/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** header for mob entities
*/

#ifndef __MOB_H__
#define __MOB_H__

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "lib/qtree.h"
#include "lib/mynode.h"
#include "object.h"

typedef enum mob_type_s {
    SLIME,
    ZOMBIE,
    SQUELETON,
    NB_OF_MOBS
} mob_type_t;

static const int MAX_STACK_MOB = 100;

typedef enum moving_type_s {
    IDLE,
    SLOW,
    MOVING
} moving_type_t;

typedef struct drop_s {
    size_t nb;
    object_id_t id;
} drop_t;

typedef struct mob_s {
    int damage;
    bool following_player;
    int health;
    int health_max;
    mob_type_t type;
    moving_type_t moving;
    float speed;
    drop_t drop;
    sfFloatRect rect;
    sfVector2i collide;
    hitbox_t *hitbox;
    sfSprite *sprite;
    sfSprite *healthbar[2];
} mob_t;

typedef struct mob_init_s {
    int damage;
    int health;
    int health_max;
    int idle_start_y;
    float speed;
    sfVector2f range;
    sfVector2f sprite_vec;
    sfVector2f box;
    drop_t drop;
    char *name;
} mob_init_t;

static const sfIntRect SPRITE_REC_MOB[NB_OF_MOBS][5] = {
    { //SLIME
        {0, 128, 65, 64},
        {0, 0, 65, 64},
        {0, 64, 65, 64},
        {0, 192, 65, 64},
        {0, 128, 65, 64}
    },
    { //ZOMBIE
        {0, 0, 25, 63},
        {0, 126, 25, 63},
        {0, 63, 25, 63},
        {0, 189, 25, 63},
        {0, 0, 25, 63}
    },
    { //SQUELETON
        {0, 0, 31, 63},
        {0, 126, 31, 63},
        {0, 63, 31, 63},
        {0, 189, 31, 63},
        {0, 0, 31, 63}
    }
};

static const mob_init_t MOB_INIT[] = {
    {
        .name = "slime",
        .damage = 10,
        .health = 1000,
        .health_max = 1000,
        .speed = 50.0f,
        .range = {
            .x = 10.0f,
            .y = 10.0f
        },
        .sprite_vec = {
            .x = 65,
            .y = 64
        },
        .drop = {
            .nb = 10,
            .id = XPORB
        },
        .box = {
            .x = 40.0f,
            .y = 40.0f
        },
        .idle_start_y = 128
    },
    {
        .name = "zombie",
        .damage = 30,
        .health = 300,
        .health_max = 300,
        .speed = 350.0f,
        .range = {
            .x = 7.5f,
            .y = 7.5f
        },
        .sprite_vec = {
            .x = 25,
            .y = 63
        },
        .drop = {
            .nb = 2,
            .id = WATER_MELON
        },
        .box = {
            .x = 30.0f,
            .y = 30.0f
        },
        .idle_start_y = 0
    },
    {
        .name = "skeleton",
        .health = 500,
        .damage = 20,
        .health_max = 500,
        .speed = 200.0f,
        .range = {
            .x = 10.0f,
            .y = 10.0f
        },
        .sprite_vec = {
            .x = 31,
            .y = 63
        },
        .drop = {
            .nb = 2,
            .id = XPORB
        },
        .box = {
            .x = 20.0f,
            .y = 40.0f
        },
        .idle_start_y = 0
    }
};

void mob_position(mob_t *mob, sfVector2u map_size);
void free_mob(mob_t *mob);
bool filter_null_mob(mob_t *mob);

#endif /* __MOB_H__ */
