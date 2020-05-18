/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** actions
*/

#include "my_rpg.h"

static tile_type_t find_type_by_id(unsigned int id)
{
    tile_type_t type = NB_TILE_TYPES + id - 50;

    if (type == NB_TILE_TYPES || type < 0 || type > ROAD_13)
        return (-1);
    return (type);
}

void map_change_brush(ge_view_t *view, rpg_t *game, ge_widget_t *widget)
{
    map_exts_t *exts = view->exts;

    if (!exts)
        return;
    exts->brush.type = find_type_by_id(widget->id);
}

void map_reset_borders(ge_view_t *view, rpg_t *game)
{
    map_exts_t *exts = view->exts;

    if (!exts)
        return;
    map_inspect(&exts->map, sfFalse);
    for (unsigned int i = 0; i < exts->map.size.y; i++) {
        for (unsigned int j = 0; j < exts->map.size.x; j++) {
            sfRectangleShape_setTexture(exts->map.tiles[i][j].shape,
            ge_textures(NULL, TILE_TEXTURE[exts->map.tiles[i][j].type]),
            sfTrue);
        }
    }
}

void map_view_save(ge_view_t *view, rpg_t *game)
{
    map_exts_t *exts = view->exts;

    if (!exts)
        return;
    my_dprintf(STDOUT_FILENO, "my_rpg: saving the map...\n");
    map_save(&exts->map, MAP_PATH);
}

void map_view_randomize(ge_view_t *view, rpg_t *game)
{
    map_exts_t *exts = view->exts;

    if (!exts)
        return;
    map_randomize(&(exts->map),
        sfClock_getElapsedTime(game->fps->clock).microseconds);
    for (unsigned int i = 0; i < exts->map.size.y; i++) {
        for (unsigned int j = 0; j < exts->map.size.x; j++) {
            sfRectangleShape_setTexture(exts->map.tiles[i][j].shape,
            ge_textures(NULL,
            TILE_TEXTURE[exts->map.tiles[i][j].type]), sfTrue);
        }
    }
}
