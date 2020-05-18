/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_widget_update_pane
*/

#include "engine.h"

void ge_widget_init_pane(ge_view_t *rst view, ge_widget_t *rst widget)
{
    ge_widget_pane_t *pane = widget->type_exts;

    if (!(widget->options & GEW_INIT)) {
        sfSprite_setTexture(widget->sprite, pane->texture, sfFalse);
        ge_widget_set_position(widget, view->window);
        widget->options ^= GEW_INIT;
    }
}

void ge_widget_render_pane(ge_view_t *rst view, ge_widget_t *rst widget)
{
    sfRenderWindow_drawSprite(view->window, widget->sprite, NULL);
}

/*
** @DESCRIPTION
**   Function responsible for updating all geWidget_Button widgets.
** @TODO: Find a way around the redudant calls of this function. aka find a
**   way to initialise the widgets.
*/
void ge_widget_update_pane(ge_view_t *rst view,
ge_widget_t *rst widget, void *rst data)
{
    (void)view;
    (void)widget;
    (void)data;
}
