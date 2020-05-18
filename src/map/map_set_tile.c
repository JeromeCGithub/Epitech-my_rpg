/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** map_set_tile
*/

#include "my_rpg.h"

void map_set_tile(tile_t *tile)
{
    if (!tile)
        return;
    tile->shape = qtree_rect_create(tile->bounds);
    sfRectangleShape_setTexture(tile->shape,
    ge_textures(NULL, TILE_TEXTURE[tile->type]), sfTrue);
    sfRectangleShape_setOutlineColor(tile->shape, sfTransparent);
    sfRectangleShape_setFillColor(tile->shape, sfWhite);
}