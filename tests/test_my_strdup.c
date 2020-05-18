/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** Tests | my_strdup
*/

#include <criterion/criterion.h>
#include "lib/mystring.h"

Test(my_strdup, simple_strings)
{
    char *original = "Hello world!";
    char *duplicate = my_strdup(original);

    cr_assert_str_eq(duplicate, original);
    free(duplicate);
    original = "!";
    duplicate = my_strdup(original);
    cr_assert_str_eq(duplicate, original);
}

Test(my_strdup, error_handling)
{
    char *original = NULL;
    char *duplicate = my_strdup(original);

    cr_assert_eq(original, duplicate);
}
