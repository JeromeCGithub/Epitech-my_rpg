/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** map_draw
*/

#include "my_rpg.h"

void map_draw(ge_view_t *view, qtree_t *qtree, sfView **views)
{
    hitbox_t *hitbox = NULL;
    sfVector2f pos = sfView_getCenter(views[VIEW_GAME]);
    sfFloatRect bounds = {pos.x - TILE_SIZE.x, pos.y - TILE_SIZE.y,
    (view->window_size.x) / 2 + TILE_SIZE.x * 2,
    (view->window_size.y) / 2 + TILE_SIZE.y * 2};
    NODE *list = NULL;

    qtree_query(qtree, &list, bounds);
    sfRenderWindow_setView(view->window, views[VIEW_GAME]);
    for (NODE *curr = list; curr; curr = curr->next) {
        hitbox = curr->data;
        if (hitbox && hitbox->type == WALL && hitbox->data) {
            sfRenderWindow_drawRectangleShape(view->window, hitbox->data, NULL);
            sfRectangleShape_setFillColor(hitbox->data, sfWhite);
        }
    }
    node_free(&list, NULL);
}
