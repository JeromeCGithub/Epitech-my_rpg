/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** entity_draw
*/

#include "views.h"

void entity_draw(ge_view_t *view)
{
    game_exts_t *exts = view->exts;
    hitbox_t *hitbox = NULL;
    sfVector2f pos = sfView_getCenter(exts->views[VIEW_GAME]);
    NODE *list = NULL;
    sfFloatRect bounds = {
        pos.x - TILE_SIZE.x,
        pos.y - TILE_SIZE.y,
        (view->window_size.x) / 2 + TILE_SIZE.x * 2,
        (view->window_size.y) / 2 + TILE_SIZE.y * 2
    };

    qtree_query(exts->qtree[QTREE_COLL], &list, bounds);
    for (NODE *curr = list; curr; curr = curr->next) {
        hitbox = curr->data;
        if (hitbox && hitbox->type == MOB_COLLIDER)
            mob_draw(view, hitbox->data);
        if (hitbox && hitbox->type == ITEM_COLLIDER)
            item_draw(view, hitbox->data);
        if (hitbox && hitbox->type == NPC_COLLIDER)
            npc_draw(view, hitbox->data);
    }
}