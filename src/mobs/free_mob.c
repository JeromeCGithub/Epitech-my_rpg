/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** free mob
*/

#include "mob.h"

void free_mob(mob_t *mob)
{
    sfSprite_destroy(mob->healthbar[0]);
    sfSprite_destroy(mob->healthbar[1]);
    sfRectangleShape_destroy(mob->hitbox->shape);
    sfSprite_destroy(mob->sprite);
}

bool filter_null_mob(mob_t *mob)
{
    return (!!mob->hitbox->rect);
}