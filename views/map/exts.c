/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** exts.c
*/

#include "my_rpg.h"

static qtree_t *map_editor_qtree_create(map_t *map)
{
    hitbox_t *hitbox = NULL;
    qtree_t *qtree = qtree_create((sfFloatRect){
        map->size.x * TILE_SIZE.x / 2,
        map->size.y * TILE_SIZE.y / 2,
        map->size.x * TILE_SIZE.x / 2,
        map->size.y * TILE_SIZE.y / 2});

    if (!qtree)
        return (NULL);
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++) {
            hitbox = hitbox_create(
                &map->tiles[i][j].bounds,
                &map->tiles[i][j].collisions,
                map->tiles[i][j].shape,
                WALL);
            qtree_push(qtree, hitbox);
        }
    }
    return (qtree);
}

map_exts_t *map_initialise_exts(ge_view_t *view, rpg_t *game)
{
    map_exts_t *exts = malloc(sizeof(map_exts_t));

    if (!exts)
        return (NULL);
    exts->brush = (brush_t){.type = -1, .radius = 1};
    if (map_init(MAP_PATH, &exts->map) && map_generate(&exts->map))
        return (NULL);
    if (views_create(exts->views, view->window))
        return (NULL);
    map_save(&exts->map, MAP_PATH);
    exts->qtree = map_editor_qtree_create(&exts->map);
    if (!exts->qtree)
        return (NULL);
    sfView_setCenter(exts->views[VIEW_GAME], (sfVector2f){
        exts->map.size.x * TILE_SIZE.x / 2,
        exts->map.size.y * TILE_SIZE.y / 2});
    return (exts);
}
