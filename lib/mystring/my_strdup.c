/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** my_strdup
*/

#include "mystring.h"

/*
** @DESCRIPTION
**   Duplicates a string.
** @RETURN_VALUE
**   The adress of the first byte of the string.
**   Handles NULL string by returning NULL.
**   Returns NULL on failed malloc call.
**   /!\ Needs to be freed /!\
*/
char *my_strdup(char const *string)
{
    unsigned int i;
    char *duplicate;

    if (!string)
        return NULL;
    duplicate = malloc(sizeof(char) * (my_strlen(string) + 1));
    if (!duplicate)
        return NULL;
    for (i = 0; string[i]; i++)
        duplicate[i] = string[i];
    duplicate[i] = '\0';
    return duplicate;
}
