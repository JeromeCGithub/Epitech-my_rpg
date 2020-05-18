/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_widget_update_cbox
*/

#include "engine.h"

static void ge_widget_cbox_center(ge_widget_t *widget)
{
    ge_widget_cbox_t *cbox = widget->type_exts;
    sfFloatRect rect;
    sfVector2f pos;

    pos = sfSprite_getPosition(widget->sprite);
    rect = sfSprite_getGlobalBounds(widget->sprite);
    pos.x += rect.width / 2;
    pos.y += rect.height / 2;
    rect = sfText_getGlobalBounds(cbox->text);
    sfText_setOrigin(cbox->text, (sfVector2f){rect.width / 2,
        (rect.height / 2) + 8});
    sfText_setPosition(cbox->text, pos);
}

void ge_widget_init_cbox(ge_view_t *rst view, ge_widget_t *rst widget)
{
    ge_widget_cbox_t *cbox = widget->type_exts;

    cbox->status = false;
    sfSprite_setTexture(widget->sprite, cbox->default_texture, sfTrue);
    if (!(widget->options & GEW_INIT)) {
        widget->options ^= GEW_INIT;
        ge_widget_set_position(widget, view->window);
    }
    sfText_setCharacterSize(cbox->text, 40);
    sfText_setFont(cbox->text, ge_resources(NULL, "fontface"));
    cbox->status = false;
    cbox->onload(view->dataobject, cbox);
    sfText_setString(cbox->text, cbox->texts[cbox->status]);
    ge_widget_cbox_center(widget);
}

void ge_widget_render_cbox(ge_view_t *rst view, ge_widget_t *rst widget)
{
    ge_widget_cbox_t *cbox = widget->type_exts;

    sfRenderWindow_drawSprite(view->window, widget->sprite, NULL);
    sfRenderWindow_drawText(view->window, cbox->text, NULL);
}

/*
** @DESCRIPTION
**   Function responsible for updating all geWidget_Checkbox widgets.
*/
void ge_widget_update_cbox(ge_view_t *rst view,
ge_widget_t *rst widget, void *rst data)
{
    ge_widget_cbox_t *c = widget->type_exts;

    if (ge_hovers(widget->sprite, view->window)) {
        if (view->click && !view->used_click) {
            view->used_click = true;
            c->status = !(c->status);
            c->onclick(data, view, c->status);
            sfText_setString(c->text, c->texts[c->status]);
            ge_widget_cbox_center(widget);
        }
        sfSprite_setTexture(widget->sprite, c->focus_texture, sfTrue);
    } else {
        sfSprite_setTexture(widget->sprite, c->default_texture, sfTrue);
    }
}
