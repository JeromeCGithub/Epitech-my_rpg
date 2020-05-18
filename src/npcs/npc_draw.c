/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** npc_draw
*/

#include "views.h"
#include "npc.h"

void npc_draw(ge_view_t *view, npc_t *npc)
{
    if (!npc || !view)
        return;
    sfRenderWindow_drawSprite(view->window, npc->sprite, NULL);
    sfSprite_setPosition(npc->sprite,
        (sfVector2f){npc->rect.left, npc->rect.top});
    sfRenderWindow_drawText(view->window, npc->text, NULL);
}