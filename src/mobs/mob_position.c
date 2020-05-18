/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** mob_position
*/

#include "mob.h"
#include "map.h"

void mob_position(mob_t *mob, sfVector2u map_size)
{
    sfVector2f pos = {mob->hitbox->rect->left,
    mob->hitbox->rect->top};
    sfFloatRect rect = {
        .left = mob->hitbox->rect->width,
        .top = mob->hitbox->rect->height,
        .width = (map_size.x - 1) * TILE_SIZE.x - rect.left * 2,
        .height = (map_size.y - 1) * TILE_SIZE.y - rect.top * 2
    };

    set_in_rect(rect, &pos);
    mob->hitbox->rect->left = pos.x;
    mob->hitbox->rect->top = pos.y;
    sfSprite_setPosition(mob->sprite, pos);
    pos.y -= rect.top;
    sfSprite_setPosition(mob->healthbar[0], pos);
    sfSprite_setPosition(mob->healthbar[1], pos);
}