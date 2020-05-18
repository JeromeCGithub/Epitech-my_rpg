/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** header
*/

#ifndef MY_STDIO_LIB_H_
#define MY_STDIO_LIB_H_

/* Includes */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/* Structure definitions */
/*
** @DESCRIPTION
**   Function pointer typedef for pre_ functions.
*/
typedef char *(*stdio_fpt)(char *, va_list const);

/*
** @DESCRIPTION
**   Format specifier to function pointer struct.
*/
typedef struct {
    char letter;
    stdio_fpt function;
} stdio_format_t;

/* Function prototypes */
/*
** @DESCRIPTION
**   Int to string and string to int conversions.
*/
int my_atoi(char const *str);
char *my_itoa(int nb);

/*
** @DESCRIPTION
**   Function prototypes for the my_fprintf calls.
**   These functions are callable outside of my_fprintf.
*/
void my_putc(char const stream, char c);
void my_puts(char const stream, char const *s);
void my_puti(char const stream, int nb);

/*
** @DESCRIPTION
**   Calls preceding original function
**   Each 'pre' function casts the va_list variable from void * to the
**   demanded type.
*/
char *pre_my_sprintf_c(char *response, va_list const argp);
char *pre_my_sprintf_s(char *response, va_list const argp);
char *pre_my_sprintf_i(char *response, va_list const argp);

char *stdio_my_str_merge(char *s1, char const *s2);
unsigned int stdio_my_strlen(char const *string);

void my_dprintf(int fd, char const *fstring, ...);
char *my_sprintf(char const *fstring, ...);
char *my_private_sprintf(char const *fstring, va_list argp);

/* Variable definitions */
/*
** @DESCRIPTION
**   Static array which matches a function to each format specifier.
*/
static const stdio_format_t SPRINTF_FLAGS[] = {
    {'c', &pre_my_sprintf_c},
    {'d', &pre_my_sprintf_i},
    {'i', &pre_my_sprintf_i},
    {'s', &pre_my_sprintf_s},
    {'\0', NULL}
};

#endif
