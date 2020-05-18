/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** ui draw
*/

#include "my_rpg.h"

void ui_draw(sfRenderWindow *window, ge_view_t *view, user_interface_t *ui)
{
    if (!ui)
        return;
    draw_inventory_pane(view);
    draw_skill_tree_pane(view);
    if (ui->inventory && (view->state & 1 << 10))
        inventory_draw(window, ui->inventory);
    if (ui->skill_tree && (view->state & 1 << 11))
        skill_tree_draw(window, ui->skill_tree);
    skill_bar_draw(window, ui->skill_bar, ui->skill_tree);
}
