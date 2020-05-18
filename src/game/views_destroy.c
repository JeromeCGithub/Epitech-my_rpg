/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** views_destroy
*/

#include "my_rpg.h"

void views_destroy(sfView **views)
{
    sfView_destroy(views[VIEW_GAME]);
    sfView_destroy(views[VIEW_UI]);
}