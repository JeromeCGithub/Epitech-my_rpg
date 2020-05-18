/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** my_strncmp
*/

#include "mystring.h"

/*
** @DESCRIPTION
**   Compares two strings up to n.
** @RETURN_VALUE
**   0 => The two strings are equal.
**   Positive value => First string is greater
**   Negative value => Second string is greater
*/
int my_strncmp(const char *s1, const char *s2, unsigned int n)
{
    unsigned int i = 0;

    if (!s1 && !s2)
        return 0;
    if (!s1)
        return s2[0];
    if (!s2)
        return s1[0];
    do {
        if (s1[i] == '\0' || i + 1 >= n)
            return s1[i] - s2[i];
        i++;
    } while (s1[i] == s2[i]);
    return s1[i] - s2[i];
}
