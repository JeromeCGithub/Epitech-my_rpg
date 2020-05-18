/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** user interface header
*/

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

#include "inventory.h"
#include "engine/engine.h"
#include "skill_tree.h"
#include "skill_bar.h"

typedef struct user_interface_s {
    inventory_t *inventory;
    sfTexture *ui_texture;
    object_list_t *object_list;
    skill_tree_t *skill_tree;
    skill_bar_t *skill_bar;
} user_interface_t;

void ui_save(user_interface_t *ui);
void ui_draw(sfRenderWindow *window, ge_view_t *view, user_interface_t *ui);

static const char UI_TEXTURE_FILEPATH[] = "res/spritesheets/sprite_ui.png";

#endif /* USER_INTERFACE_H_ */
