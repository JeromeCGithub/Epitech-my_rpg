/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_view_run
*/

#include "engine.h"

static void ge_view_handle_events(ge_view_t *view)
{
    view->click = sfMouse_isButtonPressed(sfMouseLeft);
    if (view->used_click && !(view->click))
        view->used_click = false;
}

/*
** @DESCRIPTION
**   Runs the view provided view.
**   Data will be passed to the views's main function.
*/
void ge_view_run(ge_view_t *view, void *data)
{
    sfRenderWindow_clear(view->window, sfBlack);
    ge_view_handle_events(view);
    ge_widget_render_view_widgets(view, data, true);
    view->run(view, data);
    ge_widget_render_view_widgets(view, data, false);
    if (view->next) {
        view->exit(view, data);
        ge_widget_free_widgets_array(view->widgets);
        ge_view_reset(view);
        view->next(view, data);
        ge_widget_initialise_widgets(view);
        view->next = NULL;
    }
}

/*
** @DESCRIPTION
**   Used to go from one view to another.
**   Provide the view object as well as the function pointer to the next
**   view's init function.
*/
void ge_view_change(ge_view_t *this, fptr init_func)
{
    this->next = init_func;
}