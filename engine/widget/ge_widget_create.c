/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_widget_create
*/

#include "engine.h"

void ge_widget_initialise_widgets(ge_view_t *view)
{
    ge_widget_t *widget;

    for (NODE *curr = view->widgets; curr; curr = curr->next) {
        widget = curr->data;
        WIDGET_FUNCTIONS[widget->type].init(view, widget);
    }
}

/*
** @DESCRIPTION
**   Returns the pointer to a new malloc'ed ge_widget_t structure.
**   Initialises all the members to default values.
*/
ge_widget_t *ge_widget_create(void)
{
    ge_widget_t *this = malloc(sizeof(*this));

    if (!this)
        return NULL;
    this->sprite = sfSprite_create();
    if (!this->sprite) {
        free(this);
        return NULL;
    }
    this->options = GEW_RENDER_AFTER;
    this->states = 1;
    this->pstring = NULL;
    this->id = 0;
    this->type = geWidget_undefined;
    return this;
}

/*
** @DESCRIPTION
**   Returns the pointer to a new malloc'ed ge_widget_t structure.
**   Initialises all the members to default values.
*/
void ge_widget_destroy(ge_widget_t *this)
{
    sfSprite_destroy(this->sprite);
    if (this->pstring)
        free(this->pstring);
}
