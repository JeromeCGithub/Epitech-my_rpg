/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_xml_form_widget
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Allocates the type_exts of a ge_widget_t
*/
void ge_xml_form_btn(ge_widget_t *this)
{
    ge_widget_button_t *btn = malloc(sizeof(ge_widget_button_t));
    sfTexture *mock = ge_textures(NULL, "mock");
    sfFont *font = ge_resources(NULL, "fontface");

    this->type_exts = btn;
    this->type = geWidget_Button;
    btn->default_texture = mock;
    btn->focus_texture = mock;
    btn->pressed_texture = mock;
    btn->onclick = ge_null_endpoint;
    btn->text = sfText_create();
    if (!btn->text) {
        my_error(err_write, 84);
        return;
    }

    if (font)
        sfText_setFont(btn->text, font);
}

/*
** @DESCRIPTION
**   Allocates the types_exts of a ge_widget_t
*/
void ge_xml_form_pane(ge_widget_t *this)
{
    ge_widget_pane_t *pane = malloc(sizeof(ge_widget_pane_t));

    this->type_exts = pane;
    this->type = geWidget_Pane;
    pane->texture = ge_textures(NULL, "mock");
}

/*
** @DESCRIPTION
**   Allocates the types_exts of a ge_widget_t
*/
void ge_xml_form_cbox(ge_widget_t *this)
{
    ge_widget_cbox_t *cbox = malloc(sizeof(ge_widget_cbox_t));
    sfTexture *mock = ge_textures(NULL, "mock");

    this->type = geWidget_Checkbox;
    this->type_exts = cbox;
    cbox->text = sfText_create();
    cbox->status = false;
    cbox->default_texture = mock;
    cbox->focus_texture = mock;
    cbox->texts[false] = NULL;
    cbox->texts[true] = NULL;
    cbox->onclick = ge_null_endpoint;
    cbox->onload = ge_null_endpoint;
}
