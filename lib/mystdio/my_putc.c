/*
** EPITECH PROJECT, 2020
** mystdio
** File description:
** my_putc
*/

#include "mystdio.h"

/*
** @DESCRIPTION
**   Writes one char in the provided stream.
** @RETURN_VALUE
**   None.
*/
void my_putc(char stream, char c)
{
    write(stream, &c, 1);
}
