/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_bar_draw.c
*/

#include "skill_bar.h"
#include "skill_tree.h"

void skill_bar_draw(sfRenderWindow *window, skill_bar_t *skill_bar,
    skill_tree_t *skill_tree)
{
    int index = 3;

    if (!skill_bar)
        return;
    for (int i = 0; i < 3; i++, index += 4) {
        sfRenderWindow_drawSprite(
                window, skill_bar->slot[i]->case_sprite, NULL);
        if (!skill_tree->skills[index]->locked)
            sfRenderWindow_drawSprite(
                    window, skill_bar->slot[i]->skill_sprite, NULL);
        if (skill_bar->slot[i]->in_cd)
            sfRenderWindow_drawSprite(
                    window, skill_bar->slot[i]->cd_sprite, NULL);
    }
}