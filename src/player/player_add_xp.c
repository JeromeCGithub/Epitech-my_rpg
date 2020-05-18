/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_add_xp.c
*/

#include "my_rpg.h"

static void check_and_apply_level_up(game_exts_t *exts, float xp,
    skill_tree_t *my_tree)
{
    particle_buf_t buf = PARTICLE_LVL;

    if (exts->player->stats.xp >= exts->player->stats.level * XP_PER_LEVEL) {
        buf.pos = (sfVector2f){
            exts->player->hitbox.left,
            exts->player->hitbox.top
        };
        exts->player->stats.level += 1;
        exts->player->stats.xp = 0;
        my_tree->skill_point += 1;
        particle_create(exts->particles, buf, 200);
    }
}

void player_add_xp(game_exts_t *exts, float xp, skill_tree_t *my_tree)
{
    exts->player->stats.xp += xp;
    check_and_apply_level_up(exts, xp, my_tree);
}