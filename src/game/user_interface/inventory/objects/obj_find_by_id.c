/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** obj_find_by_id.c
*/

#include "object.h"

object_t *obj_find_by_id(object_list_t *list, int id)
{
    object_list_t *ptr = list;

    for (; ptr; ptr = ptr->next) {
        if (ptr->id == id)
            return (object_duplicate(ptr->object));
    }
    return (NULL);
}