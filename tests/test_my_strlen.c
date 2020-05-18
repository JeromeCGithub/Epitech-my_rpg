/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** Tests | my_strlen
*/

#include <criterion/criterion.h>
#include "lib/mystring.h"

Test(my_strlen, strings_of_size_one)
{
    char *string = "1";
    unsigned int got = my_strlen(string);
    unsigned int expected = 1;

    cr_assert_eq(got, expected);
}

Test(my_strlen, empty_strings)
{
    char *string = "";
    unsigned int got = my_strlen(string);
    unsigned int expected = 0;

    cr_assert_eq(got, expected);
}

Test(my_strlen, null_strings)
{
    char *string = NULL;
    unsigned int got = my_strlen(string);
    unsigned int expected = 0;

    cr_assert_eq(got, expected);
}

Test(my_strlen, simple_string_tests)
{
    char *string = "This string is 33 characters long";
    unsigned int got = my_strlen(string);
    unsigned int expected = 33;

    cr_assert_eq(got, expected);
}
