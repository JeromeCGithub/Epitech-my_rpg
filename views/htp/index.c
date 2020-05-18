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
**   Initilaises the htp view exts.
** @REFACTOR
**   Prevent hardcoding path values.
*/
void initialise_htp_view(ge_view_t *view, rpg_t *game)
{
    ge_widget_button_t *widget;

    view->run = &run_htp_view;
    view->exit = &exit_htp_view;
    ge_xml_load_interface(&(view->widgets), "views/htp/interface.xml");
    widget = ge_widget_get_tpexts(view, 1);
    sfText_setColor(widget->text, sfBlack);
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_htp_view(ge_view_t *view, rpg_t *game)
{
    menu_handle_events(view, game);
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_htp_view(ge_view_t *view, rpg_t *game)
{
    return;
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the htp view.
*/
void initialise_htp_functions(void)
{
    return;
}