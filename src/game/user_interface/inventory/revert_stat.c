/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** revert_stat.c
*/

#include "event_inventory.h"

void revert_stat(rpg_t *game, ge_view_t *view, int position)
{
    if (!game || !view || !game->ui || !game->ui->inventory)
        return;
    if (game->ui->inventory->stuff[position]) {
        for (int i = 0; i < 5; i++)
            game->ui->inventory->stuff[position]->stat[i] *= -1;
        if (game->ui->inventory->stuff[position]->func_id < NB_FUNCTION &&
        USE_ITEM_FUNCTIONS[game->ui->inventory->stuff[position]->func_id])
            USE_ITEM_FUNCTIONS[game->ui->inventory->stuff[position]->func_id](
                    view, game, game->ui->inventory->stuff[position]);
        for (int i = 0; i < 5; i++)
            game->ui->inventory->stuff[position]->stat[i] *= -1;
    }
}