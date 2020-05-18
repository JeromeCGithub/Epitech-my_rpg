/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** ui_event.c
*/

#include "ui_event.h"
#include "inventory.h"
#include "event_inventory.h"

void ui_event(ge_view_t *view, rpg_t *game, sfEvent event)
{
    if (game->ui) {
        inventory_event(view, game, event);
        skill_tree_event(
                view, game, sfMouse_getPositionRenderWindow(view->window));
    }
}