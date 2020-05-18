/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_view_create
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Sets all members of a ge_view_t to 0 / NULL given its pointer.
*/
void ge_view_reset(ge_view_t *this)
{
    this->state = 1;
    this->run = NULL;
    this->exit = NULL;
    this->exts = NULL;
    this->window_size = sfRenderWindow_getSize(this->window);
    this->widgets = NULL;
    this->click = false;
    this->used_click = true;
}

/*
** @DESCRIPTION
**   Calls the current view exit function and destroys the view
*/
void ge_view_destroy(ge_view_t *view, void *data)
{
    if (view->exit)
        view->exit(view, data);
    ge_widget_free_widgets_array(view->widgets);
    free(view);
}

/*
** @DESCRIPTION
**   Returns a malloc'ed ge_view_t * with all members set to 0 / NULL.
** @FREE
*/
ge_view_t *ge_view_create(sfRenderWindow *window, void *data)
{
    ge_view_t *this = malloc(sizeof(*this));

    if (!this) {
        my_puts(2, "Abort: Failed malloc call at ge_view_create.\n");
        my_error(err_write, 84);
        return NULL;
    }
    this->dataobject = data;
    this->next = NULL;
    this->window = window;
    this->window_size = sfRenderWindow_getSize(this->window);
    ge_view_reset(this);
    return this;
}

/*
** @DESCRIPTION
**   Used to set a view for the first time.
*/
void ge_view_set(ge_view_t *view, fptr init_func)
{
    init_func(view);
    ge_widget_initialise_widgets(view);
}