/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** my_itoa
*/

#include "mystdio.h"

static char *my_itoa_handle_malloc(int *tmp, int *nb, int len)
{
    char *response;

    if (*nb == 0) {
        response = malloc(sizeof(char) * 2);
        response[0] = '0';
        response[1] = '\0';
        return response;
    }
    if (*nb < 0) {
        response = malloc(sizeof(char) * (len + 1 + (*tmp)++));
        response[0] = '-';
        *nb = *nb * -1;
    } else
        response = malloc(sizeof(char) * (len + 1));
    response[len + *tmp] = '\0';
    return response;
}

char *my_itoa(int nb)
{
    char *response;
    int len = 0;
    int tmp = (nb < 0) ? -nb: nb;

    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    response = my_itoa_handle_malloc(&tmp, &nb, len);
    while (len--) {
        response[len + tmp] = nb % 10  + '0';
        nb /= 10;
    }
    return (response);
}
