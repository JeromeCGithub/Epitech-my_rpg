/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** my_str_merge
*/

#include "mystring.h"

/*
** @DESCRIPTION
**   Merges two strings together.
** @RETURN_VALUE
**   The merged string to be freed.
*/
char *my_str_merge(char const *s1, char const *s2)
{
    unsigned int len1 = my_strlen(s1);
    unsigned int len2 = my_strlen(s2);
    unsigned int k = 0;
    char *response = malloc(sizeof(char) * (len1 + len2 + 1));

    for (; k < len1; k++)
        response[k] = s1[k];
    for (; k < len1 + len2; k++)
        response[k] = s2[k - len1];
    response[k] = '\0';
    return response;
}
