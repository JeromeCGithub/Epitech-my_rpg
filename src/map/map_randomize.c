/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** map_randomize
*/

#include <stdlib.h>
#include "map.h"
#include "lib/qtree.h"

float perlin(sfVector2f pos, float res, unsigned int *perm);

static void permute_table(unsigned int *perm)
{
    int temp = 0;
    int i = 0;

    for (int nb_rands = 0; nb_rands < 10; nb_rands++) {
        for (int j = 0; j < 512; j++) {
            i = rand() % 256;
            temp = perm[j];
            perm[j] = perm[i];
            perm[i] = temp;
        }
    }
}

static void map_randomize_tile(map_t *map, sfVector2i pos, unsigned int *perm)
{
    map->tiles[pos.y][pos.x].type =
        (int)(ABS(perlin((sfVector2f){pos.x, pos.y}, 10.0f, perm)
        * (NB_TILE_TYPES * 2)));
    if (map->tiles[pos.y][pos.x].type >= NB_TILE_TYPES)
        map->tiles[pos.y][pos.x].type = NB_TILE_TYPES - 1;
}

void map_randomize(map_t *map, unsigned int seed)
{
    unsigned int perm[512];

    for (unsigned int i = 0; i < 256; i++)
        perm[i] = i;
    for (unsigned int i = 0; i < 256; i++)
        perm[i + 256] = i;
    srand(seed);
    permute_table(perm);
    for (int i = 0; i < map->size.x; i++) {
        for (int j = 0; j < map->size.x; j++) {
            map_randomize_tile(map, (sfVector2i){j, i}, perm);
        }
    }
}
