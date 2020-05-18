/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** generate_map
*/

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib/mystdio.h"
#include "lib/qtree.h"
#include "map.h"

static tile_t tile_create(sfVector2i pos)
{
    tile_t tile;

    tile.bounds = (sfFloatRect) {
        .left = pos.x * TILE_SIZE.x - TILE_SIZE.x / 2,
        .top = pos.y * TILE_SIZE.y - TILE_SIZE.y / 2,
        .width = TILE_SIZE.x / 2,
        .height = TILE_SIZE.y / 2};
    tile.collisions = (sfVector2i){0, 0};
    return (tile);
}

static tile_t **tiles_init(sfVector2u size)
{
    tile_t **tiles = malloc(sizeof(tile_t *) * (size.y));

    if (!tiles)
        return (NULL);
    for (int i = 0; tiles && i < size.y; i++) {
        tiles[i] = malloc(sizeof(tile_t) * (size.x));
        if (!tiles[i])
            return (NULL);
        for (int j = 0; j < size.x; j++) {
            tiles[i][j] = tile_create((sfVector2i){j, i});
        }
    }
    return (tiles);
}

_Bool map_generate(map_t *map)
{

    map->size = MAP_SIZE;
    map->tiles = tiles_init(map->size);
    if (!map->tiles) {
        my_dprintf(2, "my_rpg: Failed to malloc.\n");
        return (1);
    }
    map_randomize(map, 5435123);
    map_inspect(map, sfTrue);
    return (0);
}
