/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** mystring_export
*/

#include "mystdio.h"

/*
** @DESCRIPTION
**   Counts the number of characters of a string.
** @RETURN_VALUE
**   The length of the string as an unsigned int.
*/
unsigned int stdio_my_strlen(char const *string)
{
    unsigned int response;

    if (string == NULL)
        return 0;
    for (response = 0; string[response]; response++);
    return response;
}

/*
** @DESCRIPTION
**   Merges two strings together.
** @RETURN_VALUE
**   The merged string to be freed.
*/
char *stdio_my_str_merge(char *s1, char const *s2)
{
    unsigned int len1 = stdio_my_strlen(s1);
    unsigned int len2 = stdio_my_strlen(s2);
    unsigned int k = 0;
    char *response = malloc(sizeof(char) * (len1 + len2 + 1));

    for (; k < len1; k++)
        response[k] = s1[k];
    for (; k < len1 + len2; k++)
        response[k] = s2[k - len1];
    response[k] = '\0';
    if (s1 != NULL)
        free(s1);
    return response;
}
