/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** index
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   Called upon entering view, mainly to malloc / create objects.
**   Initilaises the menu view exts.
** @REFACTOR: Prevent hardcoding path values.
*/
void initialise_menu_view(ge_view_t *view, rpg_t *game)
{
    view->run = &run_menu_view;
    view->exit = &exit_menu_view;
    ge_xml_load_interface(&(view->widgets), "views/menu/interface.xml");
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_menu_view(ge_view_t *view, rpg_t *game)
{
    menu_handle_events(view, game);
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_menu_view(ge_view_t *view, rpg_t *game)
{
    return;
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the menu view.
*/
void initialise_menu_functions(void)
{
    ge_functions((fptr)menu_play_game, "menu-play-game");
    ge_functions((fptr)menu_settings, "menu-settings");
    ge_functions((fptr)menu_map, "menu-map");
    ge_functions((fptr)views_quit_game, "quit-game");
    ge_functions((fptr)menu_bestiary, "menu-bestiary");
    ge_functions((fptr)menu_htp, "menu-htp");
}