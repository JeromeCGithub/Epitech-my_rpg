/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_bar_hover.c
*/

#include "my_rpg.h"

static void slot_hover(skill_t *skill, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfIntRect position = sfSprite_getTextureRect(skill->case_sprite);
    sfFloatRect bounds = sfSprite_getGlobalBounds(skill->case_sprite);

    if (sfFloatRect_contains(&bounds, (float) mouse.x, (float) mouse.y) ==
            sfTrue && !sfMouse_isButtonPressed(sfMouseLeft)) {
        position.top = 778;
        sfSprite_setTextureRect(skill->case_sprite, position);
    } else if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        position.top = 907;
        sfSprite_setTextureRect(skill->case_sprite, position);
    }
}

static void reset_skills_upgrade(void *exts)
{
    game_exts_t *game = exts;


    if (game->player->stats.speed_bonus > 0)
        game->player->stats.speed_bonus -= 1;
    game->player->stats.frost = false;
}

static void cd_manager(skill_t *skill, void *exts)
{
    sfIntRect rectpos = sfSprite_getTextureRect(skill->cd_sprite);
    sfTime time = sfClock_getElapsedTime(skill->cd_clock);

    if (time.microseconds >= CD_TIME_MICROSECONDS
        || skill->step > MAX_CD_STEP) {
        skill->in_cd = false;
        reset_skills_upgrade(exts);
        sfSprite_setTextureRect(skill->cd_sprite, CD_INIT_RECT);
        return;
    }
    if (time.microseconds >= skill->step * CD_TIME_MICROSECONDS / MAX_CD_STEP
        && skill->step <= MAX_CD_STEP) {
        skill->step++;
        rectpos.left -= CD_INIT_RECT.width;
        if (rectpos.left <= CD_INIT_RECT.width
            && rectpos.top - CD_INIT_RECT.height >= -50) {
            rectpos.left = CD_INIT_RECT.left;
            rectpos.top -= CD_INIT_RECT.height;
        }
        sfSprite_setTextureRect(skill->cd_sprite, rectpos);
    }
}

void skill_bar_hover(skill_bar_t *skill_bar, sfRenderWindow *window, void *exts)
{
    for (int i = 0; i < 3; i++) {
        slot_hover(skill_bar->slot[i], window);
        cd_manager(skill_bar->slot[i], exts);
    }
}