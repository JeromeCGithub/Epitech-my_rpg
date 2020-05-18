/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_rc_menu_event.c
*/

#include "inventory.h"
#include "event_inventory.h"

static void use_event(case_t **slot, sfVector2i mouse,
                        ge_view_t *view, rpg_t *game)
{
    int ret = 0;

    (*slot)->rc_menu_on = false;
    ret = inventory_equipe(game, (*slot)->object, view);
    if (ret == 3) {
        inventory_add_by_id(game->ui->object_list,
        game->ui->inventory, LEATHER_CHESTPLATE);
        inventory_add_by_id(game->ui->object_list,
        game->ui->inventory, WATER_MELON);
        inventory_add_by_id(game->ui->object_list,
        game->ui->inventory, WATER_MELON);
    }
    if (ret > 0 && (*slot)->object->func_id < NB_FUNCTION &&
            USE_ITEM_FUNCTIONS[(*slot)->object->func_id]) {
        USE_ITEM_FUNCTIONS[(*slot)->object->func_id](
                view, game, (*slot)->object);
        inventory_delete_object(&(*slot)->object);
    }
}

int rc_menu_event_click(
        case_t **slot, sfVector2i mouse, ge_view_t *view, rpg_t *game)
{
    sfFloatRect bounds1 = sfRectangleShape_getGlobalBounds(
            (*slot)->rc_menu->button[0]);
    sfFloatRect bounds2 = sfRectangleShape_getGlobalBounds(
            (*slot)->rc_menu->button[1]);

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
            sfFloatRect_contains(&bounds1, (float) mouse.x, (float) mouse.y)) {
        use_event(slot, mouse, view, game);
        return (1);
    } else if (sfMouse_isButtonPressed(sfMouseLeft) &&
            sfFloatRect_contains(&bounds2, (float) mouse.x, (float) mouse.y)) {
        (*slot)->rc_menu_on = false;
        inventory_delete_object(&(*slot)->object);
        return (1);
    }
    return (0);
}

void rc_menu_event(
        case_t **slots, case_t **the_slot, sfVector2i mouse)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds((*the_slot)->sprite);

    if (sfFloatRect_contains(&bounds, (float) mouse.x, (float) mouse.y)
            && sfMouse_isButtonPressed(sfMouseRight) && (*the_slot)->object) {
        for (int i = 0; i < NB_SLOT_INV; i++)
            slots[i]->rc_menu_on = false;
        (*the_slot)->rc_menu_on = true;
    }
}
