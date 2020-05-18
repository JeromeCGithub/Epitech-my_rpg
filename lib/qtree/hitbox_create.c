/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** hitbox
*/

#include <stdlib.h>
#include "qtree.h"

hitbox_t *hitbox_create(sfFloatRect *rect, sfVector2i *collisions,
    void *data, hitbox_type_t type)
{
    hitbox_t *hitbox = malloc(sizeof(hitbox_t));

    if (!hitbox)
        return (NULL);
    hitbox->collide_with = NONE;
    hitbox->rect = rect;
    hitbox->collisions = collisions;
    hitbox->data = data;
    hitbox->shape = qtree_rect_create(*rect);
    hitbox->type = type;
    return (hitbox);
}
