/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player header file.
*/

#ifndef MRPG_PLAYER_H_
#define MRPG_PLAYER_H_

#include <SFML/Graphics.h>
#include "lib/qtree.h"

/**/
/* Includes */
/**/

#include "quests.h"

/**/
/* Constants */
/**/

#define PLAYERI_TILES 10
#define _cstring char const *const restrict

/**/
/* Structures / Typedef / Enums declarations */
/**/

typedef struct playeri_s {
    sfSprite *status_s;
    sfSprite *status_e;
    sfText *hovertext;
    sfSprite ***tiles;
    char *hoverstring;
    bool hovering;
} playeri_t;

enum player_val_max_s {
    psValue,
    psMax
};

typedef enum sprite_status_s {
    IDLE_S,
    RIGHT_S,
    LEFT_S,
    TOP_S,
    BOTTOM_S,
    ATTACKING_S
} sprite_status_t;

static const int ATTACK_COOLDOWN = 500;
static const sfVector2f PLAYER_SIZE = {30, 30};
static const sfVector2f SPRITE_REC_VEC = {57, 512};
static const sfVector2f SWORD_REC_VEC = {220, 668};

static const sfIntRect SPRITE_REC_PLAYER[] = {
    {0, 114, 64, 57},
    {0, 171, 64, 57},
    {0, 57, 64, 57},
    {0, 0, 64, 57},
    {0, 114, 64, 57},
    {0, 114, 64, 57}
};

static const sfIntRect SWORD_REC_PLAYER[] = {
    {0, 0, 170, 194},
    {0, 501, 190, 194},
    {0, 334, 170, 194},
    {0, 167, 170, 194},
    {0, 0, 170, 194},
    {0, 0, 170, 194}
};

#define NB_SPRITE 8
#define PS_SIZE 64

typedef struct stats_s {
    float strength;
    float defense;
    float xp;
    float level;
    float speed;
    float speed_bonus;
    float health[2];
    float food[2];
    float mana[2];
    bool frost;
} stats_t;

typedef struct player_s {
    bool loaded;
    unsigned int qnumber;
    sfVector2i collisions;
    sfFloatRect hitbox;
    hitbox_t *hitrange;
    stats_t stats;
    enum quest_state_e *quests;
    sfClock *stats_clock;
    sfClock *update_clock;
    sfClock *attack_clock;
    sfClock *hit_clock;
    sfClock *footstep_clock;
    sprite_status_t sprite_status;
    sprite_status_t sword_status;
    sfSprite *sprite;
    sfSprite *sword;
    playeri_t *interface;
} player_t;

static const float BASE_SPEED = 400.0f;
static const size_t XP_PER_LEVEL = 100;
/**/
/* Function prototypes */
/**/
    /* src/player */
player_t *player_create(void);
void mob_attack(NODE *mobs, qtree_t *qt, player_t *p, sfSound **sound);
void player_update(ge_view_t *rst view, rpg_t *rst game);
void player_movement(player_t *player, rpg_t *gamee, sfVector2u map_size);
void player_health(player_t *this, float health);
void player_mana(player_t *this, float mana);
void player_food(player_t *this, float food);
playeri_t *player_interface_create(void);
void player_interface_setup(playeri_t *this);
void player_interface_update_bar(sfSprite **row, float value[],
_cstring textstring);
void player_interface_update(ge_view_t *rst view, rpg_t *rst game);
void player_sprite_update(player_t *player);
char *player_quest_generate_string(player_t *this);
int player_quest_complete(player_t *this, unsigned int qindex);
void player_save(player_t *this);
void player_create_from_save(player_t *this);
void player_handle_position(player_t *player, sfVector2f movement,
    sfVector2u map_size);

#endif
