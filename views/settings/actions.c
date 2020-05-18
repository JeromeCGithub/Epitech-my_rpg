/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** actions
*/

#include "my_rpg.h"

void settings_action_music(rpg_t *game, ge_view_t *view, bool status)
{
    game->music = status;
}

void settings_action_music_load(rpg_t *game, ge_widget_cbox_t *cbox)
{
    cbox->status = game->music;
}

void settings_action_sound(rpg_t *game, ge_view_t *view, bool status)
{
    game->sound = status;
}

void settings_action_sound_load(rpg_t *game, ge_widget_cbox_t *cbox)
{
    cbox->status = game->sound;
}
