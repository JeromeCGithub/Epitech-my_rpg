/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_btn_atrs
*/

#include "engine.h"

/*
** @DESCRIPTION
**   This funtion handles the text attribute for the button widget.
*/
void ge_attr_btn_text(ge_widget_button_t *this, char const *key)
{
    char *contents = my_strdup(key);
    if (!contents) {
        my_error(err_write, 84);
    }
    sfText_setString(this->text, contents);
}
