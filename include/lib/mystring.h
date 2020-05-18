/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** Header File | mystring
*/

#ifndef LIB_MY_STRING_H_
#define LIB_MY_STRING_H_

/* Includes */

#include <stdlib.h>

/* Constant Definitions */

/* Enum Definitions */

/* Structure Definitions */

/* Function Prototypes */

unsigned int my_strlen(char const *string);
void my_strcat(char *dest, char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, unsigned int n);
char *my_str_merge(char const *s1, char const *s2);
char *my_strdup(char const *string);
char *my_strndup(char const *string, unsigned int n);
char **string_split(char const *str, char const *index);
long int string_chr(char const *str, char c);

/* Dependant Statements */

#endif
