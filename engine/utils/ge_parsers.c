/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ps_parsers
*/

#include "engine.h"

/*
** @DESCRIPTION
**   parser_string_get will return a string starting at string[i] up to the
**   first occurence of a delimiter or '\0'.
*/
char *ge_pget(c_char *string, u_int *i, c_char *delims)
{
    u_int start = *i;

    for (; string[*i]; (*i)++) {
        for (u_int j = 0; delims[j]; j++) {
            if (string[*i] == delims[j])
                return my_strndup(string + start, *i - start);
        }
    }
    *i -= 1;
    return my_strdup(string + start);
}

/*
** @DESCRIPTION
**   Returns a boolean value based on if val is in range min - max.
*/
bool ge_range(int val, int min, int max)
{
    return (val >= min && max >= val);
}

/*
** @DESCRIPTION
**   Checks all the cars from delims with c and returns false on occurence.
*/
bool ge_pnot(char c, char const *delims)
{
    for (u_int i = 0; delims[i]; i++) {
        if (c == delims[i])
            return false;
    }
    return true;
}

/*
** @DESCRIPTION
**   Runs through the string till string[i] is not contained in skipped.
*/
void ge_pskip(char const *string, u_int *i, char const *skipped)
{
    bool found = false;

    for (; string[*i]; (*i)++) {
        for (u_int j = 0; skipped[j]; j++) {
            found = (!found && string[*i] == skipped[j]) ? true: found;
        }
        if (!found)
            return;
        found = false;
    }
    *i -= 1;
}

/*
** @DESCRIPTION
**   Runs through the string till the occurence of a delimiter contained
**   in delims.
*/
void ge_pskip_till(char const *string, u_int *i, char const *delims)
{
    for (; string[*i]; (*i)++) {
        for (u_int j = 0; delims[j]; j++) {
            if (string[*i] == delims[j])
                return;
        }
    }
    *i -= 1;
}
