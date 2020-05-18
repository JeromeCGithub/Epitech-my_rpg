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
**   Initilaises the end view exts.
** @REFACTOR
**   Prevent hardcoding path values.
*/
void initialise_end_view(ge_view_t *view, rpg_t *game)
{
    view->run = &run_end_view;
    view->exit = &exit_end_view;
    ge_xml_load_interface(&(view->widgets), "views/end/interface.xml");
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_end_view(ge_view_t *view, rpg_t *game)
{
    menu_handle_events(view, game);
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_end_view(ge_view_t *view, rpg_t *game)
{
    return;
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the end view.
*/
void initialise_end_functions(void)
{
    return;
}
