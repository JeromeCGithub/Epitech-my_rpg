/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** cutscene
*/

#include "cutescene.h"

void cutscene_moove(cutscene_t *cutscene)
{
    sfTime time = sfClock_getElapsedTime(cutscene->clock);
    sfTime time_p = sfClock_getElapsedTime(cutscene->player_clock);
    sfIntRect p_rect = sfSprite_getTextureRect(cutscene->elements[player]);

    if (time.microseconds <= 1000000)
        return;
    if (time.microseconds >= 5000) {
        sfSprite_move(cutscene->elements[background], (sfVector2f) {0, -3});
    }
    if (time_p.microseconds >= 50000) {
        p_rect.left += 57;
        if (p_rect.left >= 500)
            p_rect.left = 0;
        sfClock_restart(cutscene->player_clock);
        sfSprite_setTextureRect(cutscene->elements[player], p_rect);
    }
}