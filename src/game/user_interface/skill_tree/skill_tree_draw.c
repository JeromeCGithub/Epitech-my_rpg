/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_tree_draw.c
*/

#include "my_rpg.h"
#include "skill_tree.h"

void draw_skill_tree_pane(ge_view_t *view)
{
    ge_widget_t *widget;

    if (view->state & 1 << 11) {
        widget = ge_widget_get(view, 501);
        sfRenderWindow_drawSprite(view->window, widget->sprite, 0);
    }
}

void skill_tree_draw(sfRenderWindow *window, skill_tree_t *skill_tree)
{
    for (int i = 0; i < NB_SKILLS; i++) {
        sfRenderWindow_drawSprite(
                window, skill_tree->skills[i]->case_sprite, NULL);
        sfRenderWindow_drawSprite(
                window, skill_tree->skills[i]->skill_sprite, NULL);
    }
}