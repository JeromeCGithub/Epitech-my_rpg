/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_widget_free_widgets_array
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Depening on the widget type this function will free all of the malloc'ed
**   members of the widget structure.
*/
static void free_widget_data(ge_widget_t *widget)
{
    if (widget->pstring)
        free(widget->pstring);
    if (widget->sprite)
        sfSprite_destroy(widget->sprite);
}

/*
** @DESCRIPTION
**   This function will free the entirety of a linked list of widgets.
*/
void ge_widget_free_widgets_array(NODE *widgets)
{
    NODE *to_free;

    if (my_error(err_read, 0))
        return;
    for (; widgets; free(to_free)) {
        to_free = widgets;
        free_widget_data(widgets->data);
        free(widgets->data);
        widgets = widgets->next;
    }
}
