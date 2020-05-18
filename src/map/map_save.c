/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** map_save
*/

#include <fcntl.h>
#include <unistd.h>
#include "lib/mystdio.h"
#include "map.h"

static _Bool map_save_line(int fd, map_t *map, int i)
{
    for (unsigned int j = 0; j < map->size.x; j++) {
        if (write(fd, &(map->tiles[i][j].type), sizeof(tile_type_t)) == -1)
            return (1);
        if (write(fd, &(map->tiles[i][j].bounds), sizeof(sfFloatRect)) == -1)
            return (1);
    }
    return (0);
}

void map_save(map_t *map, char const *filepath)
{
    int fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd == -1) {
        my_dprintf(STDERR_FILENO,
            "my_rpg: unexpected error when saving the map.\n");
        return;
    }
    map->filepath = filepath;
    write(fd, &(map->size), sizeof(map->size));
    for (unsigned int i = 0; i < map->size.y; i++) {
        if (map_save_line(fd, map, i)) {
            my_dprintf(STDERR_FILENO,
                "my_rpg: unexpected error when saving the map.\n");
            close(fd);
            return;
        }
    }
    close(fd);
    my_dprintf(STDOUT_FILENO,
        "my_rpg: map successfully saved in %s.\n", filepath);
}