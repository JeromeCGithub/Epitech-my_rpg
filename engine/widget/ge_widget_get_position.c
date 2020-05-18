/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_attr_position
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Processe la position d'un sprite en fonction de la valeur "position" xml.
** @RETURN_VALUE
**   La position en tant que sfVector2f.
*/
static u_int nb_length(int nb, char *fmt)
{
    u_int len = 0;
    bool strnum = false;

    while (nb / 10) {
        nb /= 10;
        len++;
    }
    for (int i = 0; fmt[i] && fmt[i] != ',' &&
            fmt[i] != '+' && fmt[i] != '-'; i++)
        if (fmt[i] >= '0' && fmt[i] <= '9')
            strnum = true;
    if (!strnum || !len)
        return (0);
    return (len + 1);
}

static char *advance_ptr(char *ptr, int advance_times)
{
    if (advance_times != 1)
        advance_times = 0;
    while (ptr[0] && ptr[0] != '-' && ptr[0] != '+' && ptr[0] != ',')
        ptr = &ptr[1];
    if (ptr[0] == ',' || !ptr[0])
        return (ptr);
    for (; ptr[advance_times] && ptr[advance_times] == ' '; advance_times++);
    ptr = &ptr[advance_times];
    return (ptr);
}

static float get_coord(ge_xml_position_t pos, ge_xml_pos_args_t args, char c)
{
    while (pos.fmt[0] && pos.fmt[0] != ',') {
        pos.size = nb_length(my_atoi(pos.fmt), pos.fmt);
        if (c == 'x')
            pos = switch_case_x(pos, args);
        if (c == 'y')
            pos = switch_case_y(pos, args);
        if (pos.fmt[pos.size] != 'M' && pos.fmt[pos.size] != 'C' &&
            pos.fmt[pos.size] != 'S' && pos.fmt[pos.size] != 'p' &&
            pos.fmt[pos.size] != '%')
            pos.size = 1;
        pos.fmt = advance_ptr(pos.fmt, pos.size);
    }
    return (pos.coord);
}

static ge_xml_position_t reset_struct(ge_xml_position_t pos)
{
    pos.size = 0;
    pos.coord = 0.0;
    pos.coeff = 1.0;
    return (pos);
}

sfVector2f ge_xml_parse_position(char const *f, ge_xml_pos_args_t args)
{
    sfVector2f new = {0, 0};
    ge_xml_position_t pos;

    if (!f)
        return (new);
    pos.fmt = my_strdup(f);
    pos = reset_struct(pos);
    new.x = get_coord(pos, args, 'x');
    while (pos.fmt[0] != ',')
        pos.fmt = &pos.fmt[1];
    pos.fmt = &pos.fmt[1];
    while (pos.fmt[0] == ' ')
        pos.fmt = &pos.fmt[1];
    pos = reset_struct(pos);
    new.y = get_coord(pos, args, 'y');
    return (new);
}
