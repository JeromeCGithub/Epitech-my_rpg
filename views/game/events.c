/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** events
*/

#include "my_rpg.h"
#include "event_inventory.h"
#include "ui_event.h"
#include "skill_bar_event.h"

void game_handle_view_pauses(ge_view_t *view, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape) {
        if (view->state & VIEW_PAUSE) {
            view->state = 1;
        } else {
            view->state = 0;
            view->state ^= VIEW_PAUSE;
        }
    }
}

/*
** @DESCRIPTION
**   This function calls the pollEvent and sets the game's and
**   views's variables accordingly.
*/
static void game_handle_keyboard_events(ge_view_t *view,
    rpg_t *game, int keycode)
{
    switch (keycode) {
    case sfKeyI:
        view->state ^= 1 << 10;
        game->ui->inventory->is_on ^= 1;
        break;
    case sfKeyC:
        view->state ^= 1 << 11;
        break;
    case sfKeyF3:
        view->state ^= 1 << 12;
        break;
    case sfKeySpace:
        player_attack(view, game->ui);
        break;
    }
}

static void game_handle_keyboard_pressed(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;

    if (!exts || view->state & 10)
        return;
    player_movement(exts->player, game, exts->map.size);
    player_sounds(exts->player, exts);
}

void game_handle_events(ge_view_t *view, rpg_t *game)
{
    sfEvent event;

    game_handle_keyboard_pressed(view, game);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game_handle_view_pauses(view, event);
        ui_event(view, game, event);
        switch (event.type) {
        case sfEvtKeyPressed:
            game_handle_keyboard_events(view, game, event.key.code);
            skill_bar_event(game, view, event.key.code);
            break;
        case sfEvtClosed:
            game->on = false;
            break;
        case sfEvtMouseWheelScrolled:
            sfView_zoom(((game_exts_t *)view->exts)->views[VIEW_GAME],
                event.mouseWheelScroll.delta == 1 ? 1.1f : 0.9f);
            break;
        }
    }
}
