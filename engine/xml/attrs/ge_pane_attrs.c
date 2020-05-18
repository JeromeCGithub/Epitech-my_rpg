/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_pane_atrs
*/

#include "engine.h"

/*
** @DESCRIPTION
**   This funtion handles the default-texture attribute for the button widget.
*/
void ge_attr_pane_default_texture(ge_widget_pane_t *this, char const *key)
{
    this->texture = ge_textures(NULL, key);
    ge_xml_exit_on_null_attr(this->texture, key);
}

/*
** @DESCRIPTION
**   Checks the parsed argument to see if it matches an in game resource
**   Exits otherwise.
*/
void ge_xml_exit_on_null_attr(void *ptr, char const *key)
{
    if (!ptr) {
        my_dprintf(2, "\033[0;33m└── Error: Resource '%s' ", key);
        my_puts(2, "couldn't be found\n\033[0m");
        my_error(err_write, 84);
    }
}
