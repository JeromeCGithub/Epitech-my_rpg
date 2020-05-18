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
**   Initilaises the bestiary view exts.
** @REFACTOR
**   Prevent hardcoding path values.
*/
void initialise_bestiary_view(ge_view_t *view, rpg_t *game)
{
    ge_widget_button_t *widget;

    view->run = &run_bestiary_view;
    view->exit = &exit_bestiary_view;
    ge_xml_load_interface(&(view->widgets), "views/bestiary/interface.xml");
    widget = ge_widget_get_tpexts(view, 20);
    sfText_setColor(widget->text, sfBlack);
    widget = ge_widget_get_tpexts(view, 21);
    sfText_setColor(widget->text, sfBlack);
    widget = ge_widget_get_tpexts(view, 22);
    sfText_setColor(widget->text, sfBlack);
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_bestiary_view(ge_view_t *view, rpg_t *game)
{
    menu_handle_events(view, game);
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_bestiary_view(ge_view_t *view, rpg_t *game)
{
    return;
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the bestiary view.
*/
void initialise_bestiary_functions(void)
{
    ge_functions((fptr)bestiary_next, "bestiary-next");
}