/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** my_itoa
*/

#include "mystdio.h"

int my_atoi(char const *str)
{
    unsigned int i = 0;
    int sign = 1;
    int res = 0;

    if (str == NULL)
        return 0;
    for (; str[i] && (str[i] > 57 || str[i] < 48); i++) {
        if (str[i] == '-')
            sign = -1;
        if (str[i] == '+')
            sign = 1;
    }
    for (; str[i] && (str[i] < 58 && str[i] > 47); ++i)
        res = res * 10 + str[i] - '0';
    return res *sign;
}
