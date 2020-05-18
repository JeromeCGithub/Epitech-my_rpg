/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** player_movement
*/

#include "my_rpg.h"

static void player_orientation(player_t *player, sfVector2f movement)
{
    player->sprite_status = IDLE_S;
    if (movement.x < 0)
        player->sprite_status = LEFT_S;
    if (movement.x > 0)
        player->sprite_status = RIGHT_S;
    if (movement.y < 0)
        player->sprite_status = TOP_S;
    if (movement.y > 0)
        player->sprite_status = BOTTOM_S;
}

void player_movement(player_t *player, rpg_t *game, sfVector2u map_size)
{
    sfVector2f movement = {0, 0};
    float move = (player->stats.speed + player->stats.speed_bonus)
        / ((game->fps->nb != 0) ? game->fps->nb : 0.1f);

    if (sfKeyboard_isKeyPressed(sfKeyQ))
        movement.x -= move;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        movement.x += move;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        movement.y += move;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        movement.y -= move;
    player_orientation(player, movement);
    player_handle_position(player, movement, map_size);
}
