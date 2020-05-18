/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_tree.h
*/

#ifndef SKILL_TREE_H_
#define SKILL_TREE_H_

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

void life_comp(void *player);
void def_comp(void *player);
void attack_comp(void *player);

static const int NB_SKILLS = 12;
static const sfVector2f SCALE_SKILL_CASE = {3, 3};
static const sfVector2f SCALE_SKILL_SPRITE = {2, 2};
static const sfIntRect CASE_SKILL_RECT = {26, 238, 25, 25};
static const sfIntRect CASE_SKILL_ENABLE_RECT = {52, 238, 25, 25};
static const sfIntRect SKILL_RECT[12] = {
        {980, 170, 34, 34},
        {470, 0, 34, 34},
        {945, 105, 34, 34},
        {540, 275, 34, 34},
        {1386, 340, 34, 34},
        {780, 4, 34, 34},
        {1190, 69, 34, 34},
        {505, 445, 34, 34},
        {1284, 340, 34, 34},
        {608, 2, 34, 35},
        {1292, 104, 34, 34},
        {570, 479, 34, 34}
};
static const void (*FUNC_SKILL_TREE[12])(void *player) = {
        &attack_comp,
        &def_comp,
        &life_comp,
        NULL,
        &attack_comp,
        &def_comp,
        &life_comp,
        NULL,
        &attack_comp,
        &def_comp,
        &life_comp,
        NULL
};

typedef struct skill_s {
    sfSprite *case_sprite;
    sfSprite *skill_sprite;
    sfSprite *cd_sprite;
    sfTexture *case_texture[2];
    sfClock *cd_clock;
    int step;
    int cd;
    bool in_cd;
    bool locked;
} skill_t;

typedef struct skill_tree_s {
    skill_t *skills[12];
    int skill_point;
} skill_tree_t;

void skill_tree_draw(sfRenderWindow *window, skill_tree_t *skill_tree);
skill_tree_t *skill_tree_init(sfTexture *texture);

#endif /* SKILL_TREE_H_*/