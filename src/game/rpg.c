/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** game_loop
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   Initialises the window, the clock and the view.
**   Calls the game loop till game is over.
**   Frees the window, the clock and the view.
*/
void start_game(rpg_t *game)
{
    sfRenderWindow *window = game_initialise_window(game->max_fps);
    ge_view_t *view = ge_view_create(window, game);
    int status = 0;

    if (!window || !view) {
        my_dprintf(2, "Error: Failed malloc at start_game.\n");
        my_error(err_write, 84);
        return;
    }
    game->window = window;
    game_loop(game, view);
}

/*
** @DESCRIPTION
**   This function runs the loop itself while the window is open and the
**   variable game->on is set to true.
*/
void game_loop(rpg_t *game, ge_view_t *view)
{
    ge_view_set(view, &initialise_cinematic_view);
    while (sfRenderWindow_isOpen(game->window)) {
        game_frame(game, view);
        if (!game->on)
            break;
    }
    ge_view_destroy(view, game);
    sfRenderWindow_destroy(game->window);
}

/*
** @DESCRIPTION
**   This function handles the game loop.
*/
void game_frame(rpg_t *game, ge_view_t *view)
{
    ge_view_run(view, game);
    fps_draw(view->window, game->fps);
    sfRenderWindow_display(game->window);
}
