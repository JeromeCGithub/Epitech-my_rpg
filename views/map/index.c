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
**   Initilaises the map view exts.
** @REFACTOR
**   Prevent hardcoding path values.
*/
void initialise_map_view(ge_view_t *view, rpg_t *game)
{
    view->run = &run_map_view;
    view->exit = &exit_map_view;
    view->exts = map_initialise_exts(view, game);
    ge_xml_load_interface(&(view->widgets), "views/map/interface.xml");
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_map_view(ge_view_t *view, rpg_t *game)
{
    map_exts_t *exts = view->exts;

    if (!exts)
        return;
    map_handle_events(view, game);
    map_draw(view, exts->qtree, exts->views);
    sfRenderWindow_setView(view->window, exts->views[VIEW_UI]);
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_map_view(ge_view_t *view, rpg_t *game)
{
    map_exts_t *exts = view->exts;

    if (!exts)
        return;
    map_destroy(&exts->map);
    views_destroy(exts->views);
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the map view.
*/
void initialise_map_functions(void)
{
    ge_functions((fptr)map_view_randomize, "map-randomize");
    ge_functions((fptr)map_change_brush, "change-brush");
    ge_functions((fptr)map_view_save, "map-save");
    ge_functions((fptr)map_reset_borders, "reset-borders");
}