/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** events
*/

#include "my_rpg.h"

static void map_handle_zoom(ge_view_t *view, rpg_t *game, int delta)
{
    map_exts_t *exts = view->exts;
    float zoom = 0;

    if (!exts)
        return;
    if (delta == 1)
        zoom = 1.1f;
    else
        zoom = 0.9f;
    view->window_size.x *= zoom;
    view->window_size.y *= zoom;
    sfView_zoom(exts->views[VIEW_GAME], zoom);
}

static void map_handle_keyboard_events(ge_view_t *view,
                                    rpg_t *game, sfKeyEvent key)
{
    map_exts_t *exts = view->exts;

    if (!exts)
        return;
    switch (key.code) {
    case sfKeyM:
        exts->brush.radius -= (exts->brush.radius <= 0) ? 0 : 1;
        break;
    case sfKeyP:
        exts->brush.radius++;
        break;
    }
}

static void map_handle_keyboard_pressed(ge_view_t *view, rpg_t *game)
{
    map_exts_t *exts = view->exts;
    float move = BASE_SPEED * 2 / ((game->fps->nb == 0) ? 0.1f : game->fps->nb);

    if (!exts)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        move *= 2;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        sfView_move(exts->views[VIEW_GAME], (sfVector2f){0, -move});
    if (sfKeyboard_isKeyPressed(sfKeyS))
        sfView_move(exts->views[VIEW_GAME], (sfVector2f){0, move});
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        sfView_move(exts->views[VIEW_GAME], (sfVector2f){-move, 0});
    if (sfKeyboard_isKeyPressed(sfKeyD))
        sfView_move(exts->views[VIEW_GAME], (sfVector2f){move, 0});
}

static void map_handle_mouse_pressed(ge_view_t *view)
{
    map_exts_t *exts = view->exts;
    sfVector2i pos;
    sfVector2f new;

    map_brush_hover(view);
    if (!exts || !sfMouse_isButtonPressed(sfMouseLeft) || view->used_click
        || (int)exts->brush.type == NB_TILE_TYPES
        || (int)exts->brush.type == -1) {
        return;
    }
    map_brush_click(view);
}

void map_handle_events(ge_view_t *view, rpg_t *game)
{
    sfEvent event;

    map_handle_keyboard_pressed(view, game);
    map_handle_mouse_pressed(view);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            game->on = false;
            break;
        case sfEvtMouseWheelScrolled:
            map_handle_zoom(view, game, event.mouseWheelScroll.delta);
            break;
        case sfEvtKeyPressed:
            map_handle_keyboard_events(view, game, event.key);
        }
    }
}
