/*
** EPITECH PROJECT, 2019
** engine/engine
** File description:
** ge_widget_get
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Returns the type_exts of a widget through an XML id.
*/
void *ge_widget_get_tpexts(ge_view_t *view, unsigned int id)
{
    ge_widget_t *widget;

    for (NODE *curr = view->widgets; curr; curr = curr->next) {
        widget = curr->data;
        if (widget->id == id)
            return widget->type_exts;
    }
    return NULL;
}

/*
** @DESCRIPTION
**   Returns a widget through an XML id.
*/
ge_widget_t *ge_widget_get(ge_view_t *view, unsigned int id)
{
    ge_widget_t *widget;

    for (NODE *curr = view->widgets; curr; curr = curr->next) {
        widget = curr->data;
        if (widget->id == id)
            return widget;
    }
    return NULL;
}