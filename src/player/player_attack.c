/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Function that permit the player to attack
*/

#include "my_rpg.h"
#include "sound.h"

static sfFloatRect get_attack_range(player_t *p)
{
    sfFloatRect range = *p->hitrange->rect;

    if (p->sprite_status == LEFT_S) {
        range.width *= 2.5;
        range.left -= range.width;
    }
    if (p->sprite_status == RIGHT_S) {
        range.width *= 2.5;
        range.left += range.width;
    }
    if (p->sprite_status == TOP_S) {
        range.height *= 2.5;
        range.top -= range.height;
    }
    if (p->sprite_status == BOTTOM_S || p->sprite_status == IDLE_S) {
        range.height *= 2.5;
        range.top += range.height;
    }
    return (range);
}

void attack_query(ge_view_t *view, user_interface_t *ui, game_exts_t *exts)
{
    sfFloatRect range = get_attack_range(exts->player);
    hitbox_t *retrieved;
    NODE *query = NULL;

    qtree_query(exts->qtree[QTREE_COLL], &query, range);
    for (NODE *curr = query; curr; curr = curr->next) {
        retrieved = curr->data;
        player_attack_redirect(retrieved, view, ui);
    }
}

void player_attack(ge_view_t *view, user_interface_t *ui)
{
    sfTime tm;
    game_exts_t *exts = view->exts;

    if (!exts)
        return;
    tm = sfClock_getElapsedTime(exts->player->attack_clock);
    if (sfTime_asMilliseconds(tm) < ATTACK_COOLDOWN)
        return;
    sfClock_restart(exts->player->attack_clock);
    if (exts->sound[0] && exts->sound[ATTACK])
        sfSound_play(exts->sound[ATTACK]);
    exts->player->sword_status = exts->player->sprite_status;
    attack_query(view, ui, exts);
    exts->player->sprite_status = ATTACKING_S;
}
