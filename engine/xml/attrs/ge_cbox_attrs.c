/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_cbox_atrs
*/

#include "engine.h"

/*
** @DESCRIPTION
**   This funtion handles the default-texture attribute for the cbox widget.
*/
void ge_attr_cbox_default_texture(ge_widget_cbox_t *this, char const *key)
{
    this->default_texture = ge_textures(NULL, key);
    ge_xml_exit_on_null_attr(this->default_texture, key);
}

/*
** @DESCRIPTION
**   This funtion handles the default-texture attribute for the cbox widget
*/
void ge_attr_cbox_focus_texture(ge_widget_cbox_t *this, char const *key)
{
    this->focus_texture = ge_textures(NULL, key);
    ge_xml_exit_on_null_attr(this->focus_texture, key);
}

/*
** @DESCRIPTION
**   This funtion handles the text-on attribute for the cbox widget.
*/
void ge_attr_cbox_text_on(ge_widget_cbox_t *this, char const *key)
{
    this->texts[true] = my_strdup(key);
    ge_xml_exit_on_null_attr(this->texts[true], key);
}

/*
** @DESCRIPTION
**   This funtion handles the text-off attribute for the cbox widget.
*/
void ge_attr_cbox_text_off(ge_widget_cbox_t *this, char const *key)
{
    this->texts[false] = my_strdup(key);
    ge_xml_exit_on_null_attr(this->texts[false], key);
}

/*
** @DESCRIPTION
**   This funtion handles the onclick attribute for the cbox widget.
*/
void ge_attr_cbox_onclick(ge_widget_cbox_t *this, char const *key)
{
    this->onclick = ge_functions(NULL, key);
    ge_xml_exit_on_null_attr(this->onclick, key);
}
