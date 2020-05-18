/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_delete_object.c
*/

#include "inventory.h"

void inventory_delete_object(object_t **obj)
{
    if (!(*obj))
        return;
    sfSprite_destroy((*obj)->sprite);
    free((*obj)->name);
    free((*obj)->description);
    free((*obj));
    (*obj) = NULL;
}