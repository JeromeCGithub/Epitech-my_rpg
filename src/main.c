/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main
*/

#include "my_rpg.h"

static bool is_display_in_env(char const **ae)
{
    if (!ae) {
        my_dprintf(2, "No environnement, aborting\n");
        return (false);
    }
    for (int i = 0; ae[i]; i++)
        if (!my_strncmp(ae[i], "DISPLAY=X11", 8)) {
            return (ae[i][8] ? true : false);
        }
    my_dprintf(2, "Display not found, aborting\n");
    return (false);
}

int main(int argc, char const *argv[], char const **env)
{
    rpg_t *game = NULL;

    if (!is_display_in_env(env))
        return (84);
    game = game_initialise(argc, argv);
    if (!game || my_error(err_read, 0))
        return my_error(err_read, 0);
    start_game(game);
    return my_error(err_read, 0);
}
