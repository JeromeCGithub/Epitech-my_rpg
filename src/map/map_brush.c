/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** map_brush
*/

#include "my_rpg.h"

static sfVector2i get_mouse_pos(sfRenderWindow *window, sfView **views)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f new = sfRenderWindow_mapPixelToCoords(window,
        pos, views[VIEW_GAME]);

    pos = (sfVector2i){(int)new.x / TILE_SIZE.x,
        (int)new.y / TILE_SIZE.y};
    pos = (sfVector2i){pos.x + 1, pos.y + 1};
    return (pos);
}

void map_brush_hover(void *view)
{
    map_exts_t *exts = ((ge_view_t *)view)->exts;
    sfVector2i pos = get_mouse_pos(((ge_view_t *)view)->window, exts->views);

    for (int i = -exts->brush.radius; i < exts->brush.radius + 1; i++) {
        for (int j = -exts->brush.radius; j < exts->brush.radius + 1; j++) {
            if (pos.x + j < 0 || pos.y + i < 0
                || pos.x + j >= exts->map.size.x
                || pos.y + i >= exts->map.size.y)
                continue;
            sfRectangleShape_setFillColor(
                exts->map.tiles[pos.y + i][pos.x + j].shape, HOVER_COLOR);
        }
    }
}

void map_brush_click(void *view)
{
    map_exts_t *exts = ((ge_view_t *)view)->exts;
    sfVector2i pos = get_mouse_pos(((ge_view_t *)view)->window, exts->views);

    for (int i = -exts->brush.radius; i < exts->brush.radius + 1; i++) {
        for (int j = -exts->brush.radius; j < exts->brush.radius + 1; j++) {
            if (pos.x + j < 0 || pos.y + i < 0
            || pos.x + j >= exts->map.size.x
            || pos.y + i >= exts->map.size.y)
                continue;
            exts->map.tiles[pos.y + i][pos.x + j].type = exts->brush.type;
            sfRectangleShape_setTexture(
                exts->map.tiles[pos.y + i][pos.x + j].shape,
                ge_textures(NULL, TILE_TEXTURE[exts->brush.type]), sfTrue);
        }
    }
}