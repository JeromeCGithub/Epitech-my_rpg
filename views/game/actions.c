/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** actions
*/

#include "my_rpg.h"

void action_btm(ge_view_t *view, rpg_t *game)
{
    ge_view_change(view, &initialise_menu_view);
}

void action_view_quests(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;
    ge_widget_button_t *widget = ge_widget_get_tpexts(view, 23);

    if (!exts)
        return;
    sfText_setString(widget->text, player_quest_generate_string(exts->player));
    sfText_setPosition(widget->text, (sfVector2f){300, 200});
    view->state = 0;
    view->state = 1 << 3;
}

void action_resume(ge_view_t *view, rpg_t *game)
{
    view->state = 1;
}
