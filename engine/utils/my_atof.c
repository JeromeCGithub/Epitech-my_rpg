/*
** EPITECH PROJECT, 2020
** engine
** File description:
** my_atof
*/

#include "engine.h"

static float after_comma(char const *str)
{
    float nb = 0;
    int len = my_strlen(str);

    if (!str || !len)
        return (0);
    for (int i = 1; len - i; i++) {
        nb += str[len - i] - '0';
        nb /= 10;
    }
    return (nb);
}

float my_atof(char const *str)
{
    float nb = my_atoi(str);
    int i = 0;

    if (!str)
        return (0);
    for (; str[i] && !(str[i] <= '9' && str[i] >= '0'); i++);
    for (; str[i] && str[i] != '.'; i++);
    nb += after_comma(&str[i]);
    return (nb);
}
