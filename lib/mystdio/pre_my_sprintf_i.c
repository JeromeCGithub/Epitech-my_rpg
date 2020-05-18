/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** __pre_my_sprintf_i
*/

#include "mystdio.h"

char *pre_my_sprintf_i(char *response, va_list const argp)
{
    int export = va_arg(argp, int);
    char *itoa_result = my_itoa(export);
    char *return_value = stdio_my_str_merge(response, itoa_result);

    free(itoa_result);
    return return_value;
}
