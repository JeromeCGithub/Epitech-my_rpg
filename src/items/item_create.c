/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** item_create
*/

#include "item.h"
#include "views.h"

void item_create(ge_view_t *view, rpg_t *game, object_id_t id, sfVector2f pos)
{
    game_exts_t *exts = view->exts;
    item_t *item = malloc(sizeof(item_t));
    hitbox_t *hitbox = NULL;
    sfFloatRect rect;
    object_t *object = obj_find_by_id(game->ui->object_list, id);

    if (!exts || !object || !item)
        return;
    item->sprite = sfSprite_copy(object->sprite);
    item->collisions = (sfVector2i){0, 0};
    item->rect = (sfFloatRect){pos.x, pos.y, ITEM_SIZE.x, ITEM_SIZE.y};
    item->id = id;
    hitbox = hitbox_create(
        &item->rect,
        &item->collisions,
        item,
        ITEM_COLLIDER
    );
    sfSprite_setPosition(item->sprite, pos);
    qtree_push(exts->qtree[QTREE_COLL], hitbox);
}