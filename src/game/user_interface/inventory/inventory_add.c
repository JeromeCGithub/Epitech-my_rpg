/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_add.c
*/

#include "inventory.h"

int inventory_add(inventory_t *inventory, object_t *object)
{
    int i = 0;
    sfVector2f position;

    if (!object || !inventory)
        return (-1);
    for (i = 0; i < NB_SLOT_INV && inventory->slots[i]->object; i++);
    if (i >= NB_SLOT_INV)
        return (-1);
    sfSprite_setScale(object->sprite, (sfVector2f) {1, 1});
    position = sfSprite_getPosition(inventory->slots[i]->sprite);
    sfSprite_setPosition(object->sprite, position);
    inventory->slots[i]->object = object;
    return (1);
}