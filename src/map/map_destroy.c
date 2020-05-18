/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** map_destroy
*/

#include <stdlib.h>
#include "map.h"

void tiles_destroy(tile_t **tiles, sfVector2u size)
{
    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++) {
            sfRectangleShape_destroy(tiles[i][j].shape);
        }
        free(tiles[i]);
    }
    free(tiles);
}

void map_destroy(map_t *map)
{
    map_save(map, MAP_PATH);
    tiles_destroy(map->tiles, map->size);
}