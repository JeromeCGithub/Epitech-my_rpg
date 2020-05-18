/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_create
*/

#include "my_rpg.h"
#include "string.h"

static const float BASE_STAT_VALUE = 1000;

static void init_clock(player_t *this)
{
    this->update_clock = sfClock_create();
    this->stats_clock = sfClock_create();
    this->attack_clock = sfClock_create();
    this->footstep_clock = sfClock_create();
    this->hit_clock = sfClock_create();
}

static void player_create_set_stats(player_t *this)
{
    init_clock(this);
    if (this->loaded)
        return;
    this->sword_status = IDLE_S;
    this->stats.xp = 0;
    this->stats.level = 1;
    this->stats.frost = false;
    this->stats.speed_bonus = 0;
    this->stats.health[0] = BASE_STAT_VALUE;
    this->stats.mana[0] = 0;
    this->stats.food[0] = BASE_STAT_VALUE / 2;
    this->stats.health[1] = BASE_STAT_VALUE;
    this->stats.mana[1] = BASE_STAT_VALUE;
    this->stats.food[1] = BASE_STAT_VALUE;
    this->stats.defense = BASE_STAT_VALUE;
    this->stats.strength = 20.0f;
    this->stats.speed = BASE_SPEED;
}

static void player_create_set_interface(player_t *this)
{
    this->sprite_status = IDLE_S;
    this->sword = sfSprite_create();
    this->sprite = sfSprite_create();
    sfSprite_setTexture(this->sprite,
    ge_textures(NULL, "player-spritesheet"), sfTrue);
    sfSprite_setTexture(this->sword,
    ge_textures(NULL, "sword"), sfTrue);
    sfSprite_setOrigin(this->sprite,
    (sfVector2f){PLAYER_SIZE.x, PLAYER_SIZE.y});
    this->interface = player_interface_create();
    sfSprite_setTextureRect(this->sprite, SPRITE_REC_PLAYER[IDLE_S]);
    player_interface_setup(this->interface);
    player_interface_update_bar(this->interface->tiles[0], this->stats.health,
        "player-pred");
    player_interface_update_bar(this->interface->tiles[1], this->stats.mana,
        "player-pblue");
    player_interface_update_bar(this->interface->tiles[2], this->stats.food,
        "player-pgreen");
}

static void player_create_set_quests(player_t *this)
{
    unsigned int qnumber = 0;

    for (; QUESTS[qnumber].title; qnumber++);
    this->qnumber = qnumber;
    this->quests = malloc(sizeof(quest_state_t) * (qnumber + 1));
    for (unsigned int i = 0; i < this->qnumber; i++) {
        this->quests[i] = (QUESTS[i].unlock_index == -1) ?
            questUnlocked: questLocked;
    }
}

/*
** @DESCRIPTION
**   Creates and returns a player object.
*/
player_t *player_create(void)
{
    player_t *this = malloc(sizeof(*this));

    if (!this) {
        my_error(err_write, 84);
        return NULL;
    }
    this->loaded = false;
    this->sprite_status = IDLE_S;
    player_create_set_quests(this);
    player_create_from_save(this);
    player_create_set_stats(this);
    player_create_set_interface(this);
    if (!this->loaded)
        this->hitbox = (sfFloatRect){100, 100, PLAYER_SIZE.x, PLAYER_SIZE.y};
    this->collisions = (sfVector2i){0, 0};
    return (this);
}
