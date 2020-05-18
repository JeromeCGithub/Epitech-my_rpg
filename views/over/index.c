/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** index
*/

#include "my_rpg.h"
#include "cutescene.h"

/*
** @DESCRIPTION
**   Called upon entering view, mainly to malloc / create objects.
**   Initilaises the over view exts.
** @REFACTOR
**   Prevent hardcoding path values.
*/
void initialise_over_view(ge_view_t *view, rpg_t *game)
{
    view->run = &run_over_view;
    view->exit = &exit_over_view;
    ge_xml_load_interface(&(view->widgets), "views/over/interface.xml");
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_over_view(ge_view_t *view, rpg_t *game)
{
    return;
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_over_view(ge_view_t *view, rpg_t *game)
{
    return;
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the over view.
*/
void initialise_over_functions(void)
{
    return;
}
