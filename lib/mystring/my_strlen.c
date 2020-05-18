/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** my_strlen
*/

#include "mystring.h"

/*
** @DESCRIPTION
**   Counts the number of characters of a string.
** @RETURN_VALUE
**   The length of the string as an unsigned int.
*/
unsigned int my_strlen(char const *string)
{
    unsigned int response;

    if (!string)
        return 0;
    for (response = 0; string[response]; response++);
    return response;
}
