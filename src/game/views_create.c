/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** views_create
*/

#include "my_rpg.h"

bool views_create(sfView *views[2], sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);

    views[VIEW_GAME] = sfView_create();
    views[VIEW_UI] = sfView_create();
    if (!views[VIEW_GAME] || !views[VIEW_UI])
        return (true);
    sfView_setSize(views[VIEW_GAME], (sfVector2f){size.x, size.y});
    sfView_setSize(views[VIEW_UI], (sfVector2f){size.x, size.y});
    sfView_setCenter(views[VIEW_GAME], (sfVector2f){size.x / 2, size.y / 2});
    sfView_setCenter(views[VIEW_UI], (sfVector2f){size.x / 2, size.y / 2});
    return (false);
}