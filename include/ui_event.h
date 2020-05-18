/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** ui_event.h
*/

#ifndef UI_EVENT_H_
#define UI_EVENT_H_

#include "my_rpg.h"

user_interface_t *ui_setup(rpg_t *game, ge_view_t *view);
void ui_event(ge_view_t *view, rpg_t *game, sfEvent event);
void skill_tree_event(ge_view_t *view, rpg_t *game, sfVector2i mouse);

#endif