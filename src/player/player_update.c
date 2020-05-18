/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_update
*/

#include "my_rpg.h"

static void player_update_stats(player_t *this)
{
    int tm = sfTime_asMilliseconds(sfClock_getElapsedTime(this->stats_clock));
    float modifier = 0;

    if (tm > 2000) {
        sfClock_restart(this->stats_clock);
        if (this->stats.food[psValue] < 10) {
            modifier = 50;
        }
        player_health(this, 10 - modifier);
        player_mana(this, 60);
        player_food(this, -10);
        if (this->stats.food[psValue] < 10)
            player_quest_complete(this, 3);
        if (this->stats.health[psValue] < 25)
            player_quest_complete(this, 4);
    }
}

static void move_sprite_rec(player_t *p, sfIntRect *old_rec,
    sfIntRect *old_sword)
{
    if (p->sword_status != IDLE_S)
        old_sword->left += SWORD_REC_VEC.x;
    old_rec->left += SPRITE_REC_VEC.x;
    if (old_rec->left >= SPRITE_REC_VEC.y)
        old_rec->left = 0;
    if (old_sword->left >= SWORD_REC_VEC.y) {
        p->sword_status = IDLE_S;
        old_sword->left = 0;
    }
}

void move_sprite_from_tab(player_t *p)
{
    static sprite_status_t old_move = IDLE_S;
    sfIntRect old_rec = sfSprite_getTextureRect(p->sprite);
    sfIntRect old_sword = sfSprite_getTextureRect(p->sword);

    if (p->sprite_status != old_move || p->sprite_status == IDLE_S) {
        sfSprite_setTextureRect(p->sprite, SPRITE_REC_PLAYER[p->sprite_status]);
        sfSprite_setTextureRect(p->sword, SWORD_REC_PLAYER[p->sprite_status]);
    } else {
        move_sprite_rec(p, &old_rec, &old_sword);
        sfSprite_setTextureRect(p->sprite, old_rec);
        sfSprite_setTextureRect(p->sword, old_sword);
    }
    old_move = p->sprite_status;
}

void player_sprite_update(player_t *p)
{
    sfTime tm = sfClock_getElapsedTime(p->update_clock);
    sfVector2f pos = {p->hitbox.left, p->hitbox.top};

    sfSprite_setPosition(p->sprite, pos);
    pos.x -= 100;
    pos.y -= 100 + PLAYER_SIZE.y;
    sfSprite_setPosition(p->sword, pos);
    if (sfTime_asMilliseconds(tm) < 50)
        return;
    sfClock_restart(p->update_clock);
    move_sprite_from_tab(p);
}

/*
** @DESCRIPTION
**   Update function for the player.
*/
void player_update(ge_view_t *rst view, rpg_t *rst game)
{
    game_exts_t *exts = view->exts;
    player_t *player = exts->player;
    sfVector2f pos = {player->hitbox.left, player->hitbox.top};

    player_update_stats(player);
    sfRenderWindow_drawSprite(view->window, player->interface->status_e, NULL);
    sfRenderWindow_drawSprite(view->window, player->interface->status_s, NULL);
    player_interface_update(view, game);
    sfSprite_setPosition(player->sprite, pos);
    if (player->stats.health[psValue] < 1) {
        ge_view_change(view, &initialise_over_view);
        player->stats.health[psValue] = player->stats.health[psMax];
    }
}
