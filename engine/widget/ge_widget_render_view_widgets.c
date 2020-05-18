/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_widget_render_view_widgets
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Calls the appropriate function based on the type of the widget.
*/
static void call_widget_functions(void *rst data,
ge_view_t *rst view, ge_widget_t *rst widget)
{
    if (widget->states & view->state) {
        WIDGET_FUNCTIONS[widget->type].update(view, widget, data);
        WIDGET_FUNCTIONS[widget->type].render(view, widget);
        return;
    }
    if (widget->options & GEW_OFF_STATES_RENDER)
        WIDGET_FUNCTIONS[widget->type].render(view, widget);
}

/*
** @DESCRIPTION
**   Renders all the widgets bound to the given view.
** @TODO: Handle the window resizes.
*/
void ge_widget_render_view_widgets(ge_view_t *rst view,
void *rst data, bool time)
{
    for (NODE *cw = view->widgets; cw; cw = cw->next) {
        if ((((ge_widget_t *)cw->data)->options & GEW_RENDER_AFTER) != time)
            call_widget_functions(data, view, cw->data);
    }
}
