/*
** EPITECH PROJECT, 2020
** mystdio
** File description:
** my_puts
*/

#include "mystdio.h"

/*
** @DESCRIPTION
**   Writes each character of a char * up to '\0' to the provided stream.
** @RETURN_VALUE
**   None.
*/
void my_puts(char stream, char const *string)
{
    unsigned int len = 0;

    if (string == NULL) {
        write(stream, "(null)", 6);
        return;
    }
    for (; string[len] != '\0'; len++);
    write(stream, string, len);
}
