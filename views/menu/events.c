/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** events
*/

#include "my_rpg.h"

void menu_handle_events(ge_view_t *view, rpg_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            game->on = false;
            break;
        }
    }
}
