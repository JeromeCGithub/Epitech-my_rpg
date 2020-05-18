/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** __pre_my_sprintf_c
*/

#include "mystdio.h"

char *pre_my_sprintf_c(char *response, va_list const argp)
{
    char export = va_arg(argp, int);
    char temp[2] = {export, '\0'};
    char *return_value;

    return_value = stdio_my_str_merge(response, temp);
    return return_value;
}
