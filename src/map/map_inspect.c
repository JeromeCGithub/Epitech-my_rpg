/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** map_inspect
*/

#include "my_rpg.h"

static void tile_reset_type(map_t *map, sfVector2i pos, int mask)
{
    if (mask)
        map->tiles[pos.y][pos.x].type = ROAD_5;
    for (int i = 0; i < sizeof(MASK_TYPE) / sizeof(int); i += 2) {
        if (mask == MASK_TYPE[i]) {
            map->tiles[pos.y][pos.x].type = MASK_TYPE[i + 1];
        }
    }
}

static void tile_reset(map_t *map, sfVector2i pos)
{
    int mask = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (pos.x + j > 0 && pos.x + j < map->size.x
                && pos.y + i > 0 && pos.y + i < map->size.y
                && (map->tiles[pos.y + i][pos.x + j].type == ROAD
                || map->tiles[pos.y + i][pos.x + j].type == ROAD_5)) {
                mask ^= 1 << ((i + 1) * 3 + (j + 1));
            }
        }
    }
    tile_reset_type(map, pos, mask);
}

void map_inspect(map_t *map, sfBool reset)
{
    for (unsigned int i = 0; i < map->size.y; i++) {
        for (unsigned int j = 0; j < map->size.x; j++) {
            if (map->tiles[i][j].type != ROAD_5
                && map->tiles[i][j].type != ROAD
                && map->tiles[i][j].type != BRICK_1
                && map->tiles[i][j].type != BRICK_2
                && map->tiles[i][j].type != HOUSE) {
                tile_reset(map, (sfVector2i){j, i});
            }
            if (reset)
                map_set_tile(&map->tiles[i][j]);
        }
    }
}