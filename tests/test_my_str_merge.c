/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** Tests | my_str_merge
*/

#include <criterion/criterion.h>
#include "lib/mystring.h"

Test(my_str_merge, simple_strings)
{
    char *s1 = "1";
    char *s2 = "2";
    char *got = my_str_merge(s1, s2);
    char *expected = "12";

    cr_assert_str_eq(got, expected);
    free(got);
}

Test(my_str_merge, long_strings)
{
    char *s1 = "This is the start of the sentence ";
    char *s2 = "and its sequel";
    char *got = my_str_merge(s1, s2);
    char *expected = "This is the start of the sentence and its sequel";

    cr_assert_str_eq(got, expected);
    free(got);
}

Test(my_str_merge, null_strings)
{
    char *s1 = NULL;
    char *s2 = NULL;
    char *got = my_str_merge(s1, s2);
    char *expected = "";

    cr_assert_str_eq(got, expected);
    free(got);
}
