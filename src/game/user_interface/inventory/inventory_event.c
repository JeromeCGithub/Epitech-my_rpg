/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_event.c
*/

#include <stdio.h>
#include "inventory.h"
#include "event_inventory.h"

static void inventory_object_move(object_t *obj, sfVector2i mouse)
{
    if (obj) {
        sfSprite_setPosition(obj->sprite, (sfVector2f) {mouse.x, mouse.y});
    }
}

static void swap_item(case_t **slot, inventory_t **inventory)
{
    sfVector2f position = sfSprite_getPosition((*slot)->sprite);

    if ((*slot)->object && !(*inventory)->object_on_click) {
        (*inventory)->object_on_click = (*slot)->object;
        (*slot)->object = NULL;
    } else if ((*inventory)->object_on_click && !(*slot)->object) {
        (*slot)->object = (*inventory)->object_on_click;
        sfSprite_setPosition((*slot)->object->sprite, position);
        (*inventory)->object_on_click = NULL;
    }
}

static void slot_click(
        case_t **slot, sfVector2i mouse,
        int rang, inventory_t **inventory)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds((*slot)->sprite);
    sfIntRect position = sfSprite_getTextureRect((*slot)->sprite);

    if (sfFloatRect_contains(&bounds, (float) mouse.x, (float) mouse.y) ==
            sfTrue && sfMouse_isButtonPressed(sfMouseLeft)) {
        for (int i = 0; i < NB_SLOT_INV; i++)
            (*inventory)->slots[i]->rc_menu_on = false;
        position.top =
                INIT_POS_TEXTURE_RECT_INVENTORY_CASE.top +
                        SIZE_SLOT_GROUP * 2 +
                        rang * SIZE_SLOT;
        sfSprite_setTextureRect((*slot)->sprite, position);
        swap_item(slot, inventory);
    }
}

static void slots_click(
        sfVector2i mouse, sfEvent event, ge_view_t *view, rpg_t *game)
{
    int rang = 0;
    int j = 0;

    for (int i = 0; i < NB_SLOT_INV; i++, j++)
        if (game->ui->inventory->slots[i]->rc_menu_on && rc_menu_event_click(
                &game->ui->inventory->slots[i], mouse, view, game))
            return;
    for (int i = 0; i < NB_SLOT_INV; i++, j++) {
        if (game->ui->inventory->slots[i]->rc_menu_on && rc_menu_event_click(
                        &game->ui->inventory->slots[i], mouse, view, game))
            return;
        rc_menu_event(game->ui->inventory->slots,
                &game->ui->inventory->slots[i], mouse);
        slot_click(&game->ui->inventory->slots[i], mouse,
                rang, &game->ui->inventory);
        if (j == NB_SLOT_BY_LINE) {
            rang++;
            j = 0;
        }
    }
}

void inventory_event(ge_view_t *view, rpg_t *game, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(view->window);

    if (!(view->state & 1 << 10))
        return;
    slots_click(mouse, event, view, game);
    inventory_object_move(game->ui->inventory->object_on_click, mouse);
}
