/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** mobs_draw
*/

#include "views.h"
#include "mob.h"

void mob_draw(ge_view_t *view, mob_t *mob)
{
    game_exts_t *exts = view->exts;

    if (!exts || !mob)
        return;
    if (mob->sprite) {
        mob_position(mob, exts->map.size);
        sfRenderWindow_drawSprite(view->window, mob->sprite, NULL);
    }
    if (mob->healthbar[0] && mob->healthbar[1]) {
        sfRenderWindow_drawSprite(view->window, mob->healthbar[1], NULL);
        sfRenderWindow_drawSprite(view->window, mob->healthbar[0], NULL);
    }
}