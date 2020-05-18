/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_rpg.h"

static _Bool tiles_init(map_t *map, int fd)
{
    map->tiles = malloc(sizeof(tile_t *) * map->size.y);
    if (!map->tiles)
        return (1);
    for (unsigned int i = 0; i < map->size.y; i++) {
        map->tiles[i] = malloc(sizeof(tile_t) * map->size.x);
        if (!map->tiles[i])
            return (1);
        for (unsigned int j = 0; j < map->size.x; j++) {
            if (read(fd, &(map->tiles[i][j].type), sizeof(tile_type_t)) == -1)
                return (1);
            if (read(fd, &(map->tiles[i][j].bounds), sizeof(sfFloatRect)) == -1)
                return (1);
            map_set_tile(&map->tiles[i][j]);
        }
    }
    return (0);
}

_Bool map_init(char const *filepath, map_t *map)
{
    int fd = -1;
    struct stat sb;
    sfVector2u size = {0, 0};

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_dprintf(2, "my_rpg: Failed to load map.\n");
        return (1);
    }
    if (read(fd, &size, sizeof(sfVector2u)) == -1)
        return (1);
    map->size = size;
    if (tiles_init(map, fd))
        return (1);
    close(fd);
    return (0);
}
