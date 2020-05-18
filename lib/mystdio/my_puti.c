/*
** EPITECH PROJECT, 2020
** mystdio
** File description:
** my_putn
*/

#include "mystdio.h"

/*
** @DESCRIPTION
**   Writes a number of type int in the provided stream.
** @RETURN_VALUE
**   None.
*/
void my_puti(char stream, int nb)
{
    int pot = 1;
    int nb_dup = nb;
    char to_print;

    if (nb < 0) {
        write(stream, "-", 1);
        nb = -nb;
    }
    for (; nb_dup >= 10; pot *= 10)
        nb_dup /= 10;
    while (pot >= 1) {
        to_print = (nb / pot) % 10 + 48;
        write(stream, &to_print, 1);
        pot /= 10;
    }
}
