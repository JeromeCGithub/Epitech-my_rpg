/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_add_by_id.c
*/

#include "inventory.h"

void inventory_add_by_id(object_list_t *list, inventory_t *inventory, int id)
{
    sfVector2f position;
    int i = 0;
    object_list_t *my_list = list;

    for (; my_list && my_list->id != id; my_list = my_list->next);
    if (!my_list)
        return;
    for (i = 0; i < NB_SLOT_INV && inventory->slots[i]->object; i++);
    if (i >= NB_SLOT_INV || !my_list)
        return;
    position = sfSprite_getPosition(inventory->slots[i]->sprite);
    inventory->slots[i]->object = object_duplicate(my_list->object);
    sfSprite_setPosition(inventory->slots[i]->object->sprite, position);
}