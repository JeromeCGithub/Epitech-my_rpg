/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_widget_update_button
*/

#include "engine.h"

void ge_widget_btn_text(ge_view_t *view, ge_widget_t *widget, c_char *text)
{
    ge_widget_button_t *btn = widget->type_exts;

    sfText_setString(btn->text, text);
    ge_widget_init_button(view, widget);
}

void ge_widget_init_button(ge_view_t *rst view, ge_widget_t *rst widget)
{
    ge_widget_button_t *btn = widget->type_exts;
    sfVector2f pos;
    sfFloatRect rect;

    sfSprite_setTexture(widget->sprite, btn->default_texture, sfFalse);
    ge_widget_set_position(widget, view->window);
    sfText_setCharacterSize(btn->text, 40);
    pos = sfSprite_getPosition(widget->sprite);
    rect = sfSprite_getGlobalBounds(widget->sprite);
    pos.x += rect.width / 2;
    pos.y += rect.height / 2;
    rect = sfText_getGlobalBounds(btn->text);
    sfText_setOrigin(btn->text, (sfVector2f){rect.width / 2,
        (rect.height / 2) + 8});
    sfText_setPosition(btn->text, pos);

}

void ge_widget_render_button(ge_view_t *rst view, ge_widget_t *rst widget)
{
    ge_widget_button_t *rst button = widget->type_exts;

    sfRenderWindow_drawSprite(view->window, widget->sprite, NULL);
    sfRenderWindow_drawText(view->window, button->text, NULL);
}

/*
** @DESCRIPTION
**   Function responsible for updating all geWidget_Button widgets.
** @TODO: Clean out the code in the init section.
*/
void ge_widget_update_button(ge_view_t *rst view,
    ge_widget_t *rst widget, void *rst data)
{
    ge_widget_button_t *rst btn = widget->type_exts;

    if (ge_hovers(widget->sprite, view->window)) {
        sfSprite_setTexture(widget->sprite, btn->focus_texture, sfFalse);
        if (view->click && !view->used_click) {
            view->used_click = true;
            btn->onclick(view, data, widget);
        }
    } else {
        sfSprite_setTexture(widget->sprite, btn->default_texture, sfFalse);
    }
}
