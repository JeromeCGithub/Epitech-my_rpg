/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** item_draw
*/

#include "views.h"

void item_draw(ge_view_t *view, item_t *item)
{
    game_exts_t *exts = view->exts;

    if (!exts || !item)
        return;
    sfRenderWindow_drawSprite(view->window, item->sprite, NULL);
    sfSprite_setPosition(item->sprite,
        (sfVector2f){item->rect.left, item->rect.top});
}
