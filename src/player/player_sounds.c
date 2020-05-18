/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** player_sounds
*/

#include "my_rpg.h"

void player_sounds(player_t *player, game_exts_t *exts)
{
    sfTime tm = sfClock_getElapsedTime(player->footstep_clock);
    sfSound **sounds = exts->sound;

    if (!sounds[0])
        return;
    if (player->sprite_status != IDLE_S && sounds[WALKING]
        && sfTime_asMilliseconds(tm) > 333) {
        sfSound_play(sounds[WALKING]);
        sfClock_restart(player->footstep_clock);
    }
}