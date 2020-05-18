/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** my_fprintf
*/

#include "mystdio.h"

/*
** @DESCRIPTION
**   Prints the provided string to the provided file descriptor.
**   Allows concatenation of variables such as strings, ints and chars.
*/
void my_dprintf(int fd, char const *fstring, ...)
{
    va_list args;
    char *result;

    va_start(args, fstring);
    result = my_private_sprintf(fstring, args);
    va_end(args);
    write(fd, result, stdio_my_strlen(result));
    free(result);
}
