/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** player_get_item
*/

#include "my_rpg.h"

void player_get_item(game_exts_t *exts, user_interface_t *ui, item_t *item)
{
    if (item->id != XPORB)
        inventory_add_by_id(ui->object_list, ui->inventory, item->id);
    else
        player_add_xp(exts, rand_range(5, 20), ui->skill_tree);
}