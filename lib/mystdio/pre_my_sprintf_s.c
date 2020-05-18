/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** __pre_my_sprintf_s
*/

#include "mystdio.h"

char *pre_my_sprintf_s(char *response, va_list const argp)
{
    char *export = va_arg(argp, char *);
    char *return_value = stdio_my_str_merge(response, export);

    return return_value;
}
