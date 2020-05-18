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
**   Initilaises the cinematic view exts.
** @REFACTOR
**   Prevent hardcoding path values.
*/
void initialise_cinematic_view(ge_view_t *view, rpg_t *game)
{
    view->run = &run_cinematic_view;
    view->exit = &exit_cinematic_view;
    ge_xml_load_interface(&(view->widgets), "views/cinematic/interface.xml");
    view->exts = cutscene_init();
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_cinematic_view(ge_view_t *view, rpg_t *game)
{
    menu_handle_events(view, game);
    cutscene_moove(view->exts);
    cutscene_draw(view->window, view->exts, view);
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_cinematic_view(ge_view_t *view, rpg_t *game)
{
    return;
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the cinematic view.
*/
void initialise_cinematic_functions(void)
{
    return;
}
