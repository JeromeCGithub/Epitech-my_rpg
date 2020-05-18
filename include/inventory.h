/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory header
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "engine/engine.h"
#include "object.h"
#include "lib/mynode.h"

typedef struct rc_menu_s {
    sfRectangleShape *button[2];
    sfText *text[2];
} rc_menu_t;

typedef struct case_s {
    object_t *object;
    sfSprite *sprite;
    rc_menu_t *rc_menu;
    sfBool rc_menu_on;
} case_t;

typedef struct inventory_s {
    case_t *slots[36];
    object_t *stuff[7];
    object_t *object_on_click;
    sfTexture *ui_texture;
    sfBool is_on;
} inventory_t;

enum stuff_slot {
    HELMET, ARMOURS, SWORD, BOOTS, COLLIER, SHIELD, MAX_STUFF
};

static const int NB_SLOT_BY_LINE = 9;

static const int NB_SLOT_INV = 36;

static const int SIZE_SLOT_GROUP = 152;

static const int SIZE_SLOT = 38;

static const sfIntRect INIT_POS_TEXTURE_RECT_INVENTORY_CASE = {1494, 589, 38,
        38};

static const sfVector2f INIT_POSITION_INVENTORY_CASE = {1560, 309};

static const int NB_FUNCTION = 3;

static const sfVector2f HELMET_POSITION = {1740, 70};

static const sfVector2f BOOTS_POSITION = {1740, 250};

static const sfVector2f ARMOURS_POSITION = {1740, 150};

static const sfVector2f SHIELD_POSITION = {1600, 70};

static const sfVector2f STUFF_POSITION[7] = {{1740, 70},
                                            {1740, 150},
                                            {0,    0},
                                            {1740, 250},
                                            {1600, 70}};

void inventory_delete_object(object_t **obj);
void rc_menu_event(
        case_t **slots, case_t **the_slot, sfVector2i mouse);
rc_menu_t *inventory_rc_menu_setup(case_t *slot);
void inventory_add_by_id(object_list_t *list, inventory_t *inventory, int id);
int inventory_add(inventory_t *inventory, object_t *object);
void inventory_mouse_hover(sfRenderWindow *window, inventory_t *inventory);
inventory_t *inventory_setup(sfTexture const *ui_texture);
void inventory_draw(sfRenderWindow *window, inventory_t *inventory);
void draw_inventory_pane(ge_view_t *view);
void draw_skill_tree_pane(ge_view_t *view);

#endif /* INVENTORY_H_ */
