/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_btn_atrs
*/

#include "engine.h"

/*
** @DESCRIPTION
**   This funtion handles the default-texture attribute for the button widget.
*/
void ge_attr_btn_default_texture(ge_widget_button_t *this, char const *key)
{
    this->default_texture = ge_textures(NULL, key);
    ge_xml_exit_on_null_attr(this->default_texture, key);
}

/*
** @DESCRIPTION
**   This funtion handles the focus-texture attribute for the button widget.
*/
void ge_attr_btn_focus_texture(ge_widget_button_t *this, char const *key)
{
    this->focus_texture = ge_textures(NULL, key);
    ge_xml_exit_on_null_attr(this->focus_texture, key);
}

/*
** @DESCRIPTION
**   This funtion handles the idle-texture attribute for the button widget.
*/
void ge_attr_btn_idle_texture(ge_widget_button_t *this, char const *key)
{
    this->pressed_texture = ge_textures(NULL, key);
    ge_xml_exit_on_null_attr(this->pressed_texture, key);
}

/*
** @DESCRIPTION
**   This funtion handles the onclick attribute for the button widget.
*/
void ge_attr_btn_onclick(ge_widget_button_t *this, char const *key)
{
    this->onclick = ge_functions(NULL, key);
    ge_xml_exit_on_null_attr(this->onclick, key);
}

/*
** @DESCRIPTION
**   This function handles the onload attribute for the checkbox widget.
*/
void ge_attr_cbox_onload(ge_widget_cbox_t *this, char const *key)
{
    this->onload = ge_functions(NULL, key);
    ge_xml_exit_on_null_attr(this->onload, key);
}
