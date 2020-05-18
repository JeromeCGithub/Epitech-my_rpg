/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** map_set_view
*/

#include "my_rpg.h"

void map_set_view(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;
    sfFloatRect rect;
    sfVector2f position = {exts->player->hitbox.left,
        exts->player->hitbox.top};

    rect.left = view->window_size.x / 2;
    rect.top = view->window_size.y / 2;
    rect.width = (exts->map.size.x - 1) * TILE_SIZE.x - view->window_size.x;
    rect.height = (exts->map.size.y - 1) * TILE_SIZE.y - view->window_size.y;
    set_in_rect(rect, &position);
    sfView_setCenter(exts->views[VIEW_GAME], position);
}