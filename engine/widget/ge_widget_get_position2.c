/*
** EPITECH PROJECT, 2020
** engine
** File description:
** part 2 of my job
*/

#include "engine.h"

void ge_widget_set_position(ge_widget_t *widget, sfRenderWindow *window)
{
    ge_xml_pos_args_t a;
    sfVector2f position = sfSprite_getScale(widget->sprite);
    sfTexture const *text = sfSprite_getTexture(widget->sprite);
    float tmp = 0;
    sfVector2u size = sfTexture_getSize(text);

    if (!text) {
        my_puts(2, "\033[0;33m└── Error: Sprite has no texture\n\033[0m");
        my_error(err_write, 84);
        return;
    }
    tmp = size.x * position.x;
    a.sprite_size.x = tmp;
    tmp = size.y * position.y;
    a.sprite_size.y = tmp;
    a.window_size = sfRenderWindow_getSize(window);
    position = ge_xml_parse_position(widget->pstring, a);
    sfSprite_setPosition(widget->sprite, position);
}

ge_xml_position_t switch_case_x(ge_xml_position_t pos, ge_xml_pos_args_t args)
{
    if (pos.fmt[0] == '-')
        pos.coeff = -1.0;
    if (pos.fmt[0] == '+')
        pos.coeff = 1.0;
    if (pos.fmt[pos.size] == '%')
        pos.coord += ((float)((float)my_atoi(pos.fmt) / (float)100.0) *
                (float)args.window_size.x) * (float)pos.coeff;
    if (pos.fmt[pos.size] == 'p')
        pos.coord += my_atoi(pos.fmt) * pos.coeff;
    if (pos.fmt[pos.size] == 'M')
        pos.coord += args.window_size.x * pos.coeff;
    if (pos.fmt[pos.size] == 'S')
        pos.coord += args.sprite_size.x * pos.coeff;
    if (pos.fmt[pos.size] == 'C')
        pos.coord += (args.window_size.x / 2.0 - args.sprite_size.x / 2.0)
            * pos.coeff;
    return (pos);
}

ge_xml_position_t switch_case_y(ge_xml_position_t pos, ge_xml_pos_args_t args)
{
    if (pos.fmt[0] == '-')
        pos.coeff = -1.0;
    if (pos.fmt[0] == '+')
        pos.coeff = 1.0;
    if (pos.fmt[pos.size] == '%')
        pos.coord += (((float)my_atoi(pos.fmt) / (float)100) *
                (float)args.window_size.y) * (float)pos.coeff;
    if (pos.fmt[pos.size] == 'p')
        pos.coord += my_atoi(pos.fmt) * pos.coeff;
    if (pos.fmt[pos.size] == 'M')
        pos.coord += args.window_size.y * pos.coeff;
    if (pos.fmt[pos.size] == 'S')
        pos.coord += args.sprite_size.y * pos.coeff;
    if (pos.fmt[pos.size] == 'C')
        pos.coord += (args.window_size.y / 2.0 - args.sprite_size.y / 2.0)
            * pos.coeff;
    return (pos);
}
