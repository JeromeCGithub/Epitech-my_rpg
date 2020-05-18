/*
** EPITECH PROJECT, 2019
** engine/engine
** File description:
** ge_attrs_two
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Sets the ID variable of the widget.
*/
void ge_attr_id(ge_widget_t *this, char const *key)
{
    this->id = my_atoi(key);
}