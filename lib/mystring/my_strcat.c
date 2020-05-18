/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** File name
*/

#include "mystring.h"

/*
** @DESCRIPTION
**   Appends str to the end of dest. Assumes dest has enough space.
** @RETURN_VALUE
**   None.
*/
void my_strcat(char *dest, char const *str)
{
    unsigned int size = my_strlen(dest);

    if (!dest || !str)
        return;
    for (unsigned int i = 0; str[i]; i++)
        dest[size + i] = str[i];
}
