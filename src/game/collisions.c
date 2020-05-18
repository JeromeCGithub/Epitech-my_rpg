/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** collisions
*/

#include "my_rpg.h"

void handle_collisions(ge_view_t *view, rpg_t *rpg)
{
    game_exts_t *exts = view->exts;
    sfVector2f pos;
    sfFloatRect bounds;

    if (!exts)
        return;
    pos = (sfVector2f){exts->player->hitbox.left, exts->player->hitbox.top};
    bounds = (sfFloatRect){pos.x - TILE_SIZE.x, pos.y - TILE_SIZE.y,
    (view->window_size.x) / 2 + TILE_SIZE.x * 2,
    (view->window_size.y) / 2 + TILE_SIZE.y * 2};
    qtree_recreate(&exts->qtree[QTREE_COLL]);
    qtree_collision(exts->qtree[QTREE_COLL], bounds);
}
