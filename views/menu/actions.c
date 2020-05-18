/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** actions
*/

#include "my_rpg.h"

void menu_play_game(ge_view_t *view, rpg_t *game)
{
    ge_view_change(view, &initialise_game_view);
}

void menu_settings(ge_view_t *view, rpg_t *game)
{
    ge_view_change(view, &initialise_settings_view);
}

void menu_map(ge_view_t *view, rpg_t *game)
{
    ge_view_change(view, &initialise_map_view);
}

void menu_bestiary(ge_view_t *view, rpg_t *game)
{
    ge_view_change(view, &initialise_bestiary_view);
}

void views_quit_game(ge_view_t *view, rpg_t *game)
{
    game->on = false;
}