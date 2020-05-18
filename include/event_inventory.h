/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_inventory.h
*/

#ifndef EVENT_INVENTORY_H_
#define EVENT_INVENTORY_H_

#include "my_rpg.h"

void revert_stat(rpg_t *game, ge_view_t *view, int position);
int inventory_equipe(rpg_t *game, object_t *obj, ge_view_t *view);
void object_use_consumable(ge_view_t *view, rpg_t *rpg, object_t *this);
void object_use_equipable(ge_view_t *view, rpg_t *rpg, object_t *this);

static const void (*USE_ITEM_FUNCTIONS[])(ge_view_t *, rpg_t *, object_t *) = {
    object_use_consumable,
    object_use_equipable,
    NULL,
    NULL};

int rc_menu_event_click(
        case_t **slot, sfVector2i mouse, ge_view_t *view, rpg_t *game);
void inventory_event(ge_view_t *view, rpg_t *game, sfEvent event);

#endif
