/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** my_private_sprintf
*/

#include "mystdio.h"

/*
** @DESCRIPTION
**   Looks for the character following the '%' in the FPRINTF_FLAGS array
**   and calls the associated function on success.
** @RETURN_VALUE
**   None.
*/
static void my_private_sprintf_parse(char **res, char const *fstring,
    unsigned int *i, va_list const argp)
{
    char flag_exists = 0;

    for (unsigned int j = 0; SPRINTF_FLAGS[j].function != NULL; j++) {
        if (SPRINTF_FLAGS[j].letter == fstring[*i]) {
            *res = SPRINTF_FLAGS[j].function(*res, argp);
            flag_exists = 1;
        }
    }
    if (!flag_exists) {
        *res = stdio_my_str_merge(*res, "%");
        *res = stdio_my_str_merge(*res, &(fstring[*i]));
    }
}

/*
** @DESCRIPTION
**   Prints the provided string to the provided stream.
**   Allows concatenation of variables such as strings, ints and chars.
** @USAGE
**   Provide a stream (0, 1 or 2) through the first parameter.
**   Provide a format string as second parameter.
**   Provide an undefined amount of variables to be concatenated in the str.
** @EXAMPLE
**   my_private_sprintf(2, "Error: Couldn't parse '%s': file not found.",
**   filename);
** @RETURN_VALUE
**   None.
*/
char *my_private_sprintf(char const *fstring, va_list argp)
{
    char *response = NULL;
    char *tmp = malloc(2 * sizeof(char));

    tmp[1] = '\0';
    if (fstring == NULL) {
        response = stdio_my_str_merge(response, "(null)");
        return response;
    }
    for (unsigned int i = 0; fstring[i] != '\0'; i++) {
        if (fstring[i] == '%' && fstring[i + 1] != '\0') {
            i++;
            my_private_sprintf_parse(&response, fstring, &i, argp);
        } else {
            tmp[0] = fstring[i];
            response = stdio_my_str_merge(response, tmp);
        }
    }
    free(tmp);
    return response;
}
