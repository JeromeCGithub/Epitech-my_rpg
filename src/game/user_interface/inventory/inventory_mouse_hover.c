/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_mouse_hover.c
*/

#include "inventory.h"

static void slot_mouse_hover(case_t *slot, sfVector2i mouse, int rang)
{
    sfIntRect position = sfSprite_getTextureRect(slot->sprite);
    sfFloatRect bounds = sfSprite_getGlobalBounds(slot->sprite);

    if (sfFloatRect_contains(&bounds, (float) mouse.x, (float) mouse.y) ==
            sfTrue && !sfMouse_isButtonPressed(sfMouseLeft)) {
        position.top =
                INIT_POS_TEXTURE_RECT_INVENTORY_CASE.top + SIZE_SLOT_GROUP +
                        rang * SIZE_SLOT;
        sfSprite_setTextureRect(slot->sprite, position);
    } else if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        position.top =
                INIT_POS_TEXTURE_RECT_INVENTORY_CASE.top + rang * SIZE_SLOT;
        sfSprite_setTextureRect(slot->sprite, position);
    }
}

static void rc_menu_mouse_hover(rc_menu_t *rc_menu, sfVector2i mouse)
{
    sfFloatRect bounds1 = sfRectangleShape_getGlobalBounds(rc_menu->button[0]);
    sfFloatRect bounds2 = sfRectangleShape_getGlobalBounds(rc_menu->button[1]);

    if (sfFloatRect_contains(&bounds1, (float) mouse.x, (float) mouse.y) ==
            sfTrue && !sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRectangleShape_setFillColor(
                rc_menu->button[0], (sfColor) {100, 100, 100, 255});
    } else
        sfRectangleShape_setFillColor(
                rc_menu->button[0], (sfColor) {50, 50, 50, 255});
    if (sfFloatRect_contains(&bounds2, (float) mouse.x, (float) mouse.y) ==
            sfTrue && !sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRectangleShape_setFillColor(
                rc_menu->button[1], (sfColor) {100, 100, 100, 255});
    } else
        sfRectangleShape_setFillColor(
                rc_menu->button[1], (sfColor) {50, 50, 50, 255});
}

void inventory_mouse_hover(sfRenderWindow *window, inventory_t *inventory)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int rang = 0;
    int j = 0;

    if (!window || !inventory)
        return;
    for (int i = 0; i < NB_SLOT_INV; i++, j++) {
        slot_mouse_hover(inventory->slots[i], mouse, rang);
        if (inventory->slots[i]->rc_menu_on)
            rc_menu_mouse_hover(inventory->slots[i]->rc_menu, mouse);
        if (j == NB_SLOT_BY_LINE) {
            rang++;
            j = 0;
        }
    }
}