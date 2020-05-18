/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw inventory
*/

#include "inventory.h"

void draw_inventory_pane(ge_view_t *view)
{
    ge_widget_t *widget;

    if (!view)
        return;
    if (view->state & 1 << 10) {
        widget = ge_widget_get(view, 500);
        sfRenderWindow_drawSprite(view->window, widget->sprite, 0);
    }
}

static void draw_rc_menu(sfRenderWindow *window, inventory_t *inventory)
{
    for (int i = 0; i < NB_SLOT_INV; i++)
        if (inventory->slots[i]->rc_menu_on) {
            sfRenderWindow_drawRectangleShape(
                window, inventory->slots[i]->rc_menu->button[0], NULL);
            sfRenderWindow_drawRectangleShape(
                window, inventory->slots[i]->rc_menu->button[1], NULL);
            sfRenderWindow_drawText(
                window, inventory->slots[i]->rc_menu->text[0], NULL);
            sfRenderWindow_drawText(
                window, inventory->slots[i]->rc_menu->text[1], NULL);
        }
}

void inventory_draw(sfRenderWindow *window, inventory_t *inventory)
{
    if (!inventory || !window)
        return;
    for (int i = 0; i < NB_SLOT_INV; i++) {
        sfRenderWindow_drawSprite(window, inventory->slots[i]->sprite, NULL);
        if (inventory->slots[i]->object)
            sfRenderWindow_drawSprite(
                window, inventory->slots[i]->object->sprite, NULL);
    }
    draw_rc_menu(window, inventory);
    if (inventory->object_on_click) {
        sfRenderWindow_drawSprite(
            window, inventory->object_on_click->sprite, NULL);
    }
    for (int i = 0; i < MAX_STUFF; i++)
        if (inventory->stuff[i]) {
            sfRenderWindow_drawSprite(
                window, inventory->stuff[i]->sprite, NULL);
        }
}
