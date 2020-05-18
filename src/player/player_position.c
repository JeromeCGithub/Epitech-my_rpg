/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** player_position
*/

#include "my_rpg.h"

void player_handle_position(player_t *player, sfVector2f movement,
    sfVector2u map_size)
{
    sfVector2f move = {player->hitbox.left + movement.x,
        player->hitbox.top + movement.y};
    sfFloatRect rect = {PLAYER_SIZE.x, PLAYER_SIZE.y,
        (map_size.x - 1) * TILE_SIZE.x - PLAYER_SIZE.x * 2,
        (map_size.y - 1) * TILE_SIZE.y - PLAYER_SIZE.y * 2};

    set_in_rect(rect, &move);
    player->hitbox.left = move.x;
    player->hitbox.top = move.y;
    player->collisions = (sfVector2i){0, 0};
}
