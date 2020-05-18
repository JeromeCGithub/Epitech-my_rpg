/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** setup inventory
*/

#include "inventory.h"

static case_t *create_slot(sfTexture const *ui_texture,
    sfIntRect texture_rect, sfVector2f position)
{
    case_t *slot = malloc(sizeof(case_t));
    sfVector2f origin = {texture_rect.width / 2, texture_rect.height / 2};

    if (!slot)
        return (NULL);
    slot->object = NULL;
    slot->rc_menu_on = false;
    slot->sprite = sfSprite_create();
    sfSprite_setTexture(slot->sprite, ui_texture, sfTrue);
    sfSprite_setTextureRect(slot->sprite, texture_rect);
    sfSprite_setPosition(slot->sprite, position);
    sfSprite_setOrigin(slot->sprite, origin);
    slot->rc_menu = inventory_rc_menu_setup(slot);
    return (slot);
}

static void create_slots(inventory_t *inventory, sfTexture const *ui_texture)
{
    sfIntRect texturerect = INIT_POS_TEXTURE_RECT_INVENTORY_CASE;
    sfVector2f position = INIT_POSITION_INVENTORY_CASE;
    int j = 0;

    for (int i = 0; i < NB_SLOT_INV; i++, j++) {
        inventory->slots[i] = create_slot(ui_texture, texturerect, position);
        position.x += 40;
        if (j == NB_SLOT_BY_LINE - 1) {
            j = -1;
            position.x = INIT_POSITION_INVENTORY_CASE.x;
            position.y += 40;
            texturerect.left = 1494;
            texturerect.top += 39;
        }
    }
    for (int i = 0; i < MAX_STUFF; i++)
        inventory->stuff[i] = NULL;
}

inventory_t *inventory_setup(sfTexture const *ui_texture)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory)
        return (NULL);
    inventory->is_on = false;
    inventory->object_on_click = NULL;
    create_slots(inventory, ui_texture);
    return (inventory);
}
