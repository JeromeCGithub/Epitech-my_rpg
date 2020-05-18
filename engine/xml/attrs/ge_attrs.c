/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_attrs
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Function responsible for assigning the render-after to the widget.
*/
void ge_attr_render_after(ge_widget_t *this, char const *key)
{
    if (my_strcmp(key, "false") == 0) {
        this->options ^= GEW_RENDER_AFTER;
    }
}

/*
** @DESCRIPTION
**   Function responsible for assigning the pstring to the widget.
*/
void ge_attr_position(ge_widget_t *this, char const *key)
{
    this->pstring = my_strdup(key);
}

/*
** @DESCRIPTION
**   Function responsible for assigning the pstring to the widget.
*/
void ge_attr_states(ge_widget_t *this, char const *key)
{
    this->states = 0;
    for (u_int i = 0; key[i]; i++) {
        this->states ^= 1 << my_atoi(key + i);
        ge_pskip_till(key, &i, " ");
    }
}

/*
** @DESCRIPTION
**   Function responsible for assigning the sstring to the widget.
*/
void ge_attr_scale(ge_widget_t *this, char const *key)
{
    sfVector2f scale = {0, 0};
    u_int i = 0;

    scale.x = my_atof(key);
    ge_pskip_till(key, &i, ":");
    scale.y = my_atof(key + i);
    sfSprite_setScale(this->sprite, scale);
}

/*
** @DESCRIPTION
**   Function responsible for assigning the off_states_render of the widget.
*/
void ge_attr_off_states_render(ge_widget_t *this, char const *key)
{
    if (my_strcmp(key, "true") == 0) {
        this->options ^= GEW_OFF_STATES_RENDER;
    }
}
