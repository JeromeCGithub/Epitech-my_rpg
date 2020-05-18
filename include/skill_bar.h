/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_bar.h
*/

#ifndef SKILL_BAR_H_
#define SKILL_BAR_H_

#include "inventory.h"
#include "skill_tree.h"

static const sfIntRect CASE_SKILLS_RECTS[3] = {
    {378,  907, 177, 131},
    {836,  907, 142, 131},
    {1260, 907, 200, 131}
};

static const sfIntRect SKILLS_RECTS[3] = {
    {540, 275, 34, 34},
    {505, 445, 34, 34},
    {570, 479, 34, 34}
};

static const sfIntRect CD_INIT_RECT = {2068, 563, 188, 188};

static const sfVector2f CASE_SKILLS_POSITION[3] = {
    {740, 880},
    {905, 880},
    {1080, 880}
};

static const sfVector2f SKILLS_POSITION[3] = {
    {760, 880},
    {905, 880},
    {1060, 880}
};

static const int MAX_CD_STEP = 48;
static const int CD_TIME_MICROSECONDS = 2000000;

typedef struct skill_bar_s {
    skill_t *slot[3];
} skill_bar_t;

void skill_bar_draw(
        sfRenderWindow *window, skill_bar_t *skill_bar,
        skill_tree_t *skill_tree);
skill_bar_t *skill_bar_init(sfTexture *ui_texture);
void skill_bar_hover(skill_bar_t *skill_bar,
    sfRenderWindow *window, void *exts);

#endif /* SKILL_BAR_H_ */
