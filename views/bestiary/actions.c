/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** actions
*/

#include "my_rpg.h"

void bestiary_next(ge_view_t *view, rpg_t *game)
{
    if (view->state == 1 << 0) {
        view->state = 1 << 1;
    } else if (view->state == 1 << 1) {
        view->state = 1 << 2;
    } else {
        view->state = 1 << 0;
    }
}