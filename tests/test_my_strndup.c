/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** Tests | my_strndup
*/

#include <criterion/criterion.h>
#include "lib/mystring.h"

Test(my_strndup, simple_strings)
{
    char *original = "Hello world!";
    char *duplicate = my_strndup(original, 3);

    cr_assert_str_eq(duplicate, "Hel");
    free(duplicate);
    original = "!";
    duplicate = my_strndup(original, 10);
    cr_assert_str_eq(duplicate, original);
}

Test(my_strndup, error_handling)
{
    char *original = NULL;
    char *duplicate = my_strndup(original, 10);

    cr_assert_eq(original, duplicate);
}
