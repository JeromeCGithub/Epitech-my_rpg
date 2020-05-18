/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** item_h
*/

#ifndef _ITEM_H_
#define _ITEM_H_

#include "object.h"
#include "lib/qtree.h"

typedef struct item_s {
    object_id_t id;
    sfVector2i collisions;
    sfFloatRect rect;
    sfSprite *sprite;
} item_t;

static const sfVector2f ITEM_SIZE = {20.0f, 20.0f};

#endif /* !_ITEM_H_ */
