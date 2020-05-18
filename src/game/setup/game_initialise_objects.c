/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intialise_font
*/

#include "my_rpg.h"

void game_initialise_fps(rpg_t *game)
{
    game->fps = fps_create();
    if (!game->fps)
        return;
    fps_set_font(game->fps, ge_resources(NULL, "fontface"));
    fps_set_position(game->fps, (sfVector2f){0, 0});
}
