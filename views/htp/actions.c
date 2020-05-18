/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** actions
*/

#include "my_rpg.h"

void menu_htp(ge_view_t *view, rpg_t *game)
{
    ge_view_change(view, &initialise_htp_view);
}