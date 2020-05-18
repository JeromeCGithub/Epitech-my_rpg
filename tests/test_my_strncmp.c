/*
** EPITECH PROJECT, 2019
** mystring
** File description:
** Tests | my_strncmp
*/

#include <criterion/criterion.h>
#include "lib/mystring.h"

Test(my_strncmp, equal_strings)
{
    char *s2 = "1";
    char *s1 = "1";
    int got = my_strncmp(s1, s2, 2);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test(my_strncmp, unequal_first_string)
{
    char *s1 = "This string is longer";
    char *s2 = "This string is long";
    int got = my_strncmp(s1, s2, 100);
    int expected = 101;

    cr_assert_eq(got, expected);
}

Test(my_strncmp, unequal_second_string)
{
    char *s2 = "abc";
    char *s1 = "abz";
    int got = my_strncmp(s1, s2, 3);
    int expected = 23;

    cr_assert_eq(got, expected);
}

Test(my_strncmp, line_twenty_three)
{
    char *s2 = "This string is longer";
    char *s1 = "This string is long";
    int got = my_strncmp(s1, s2, 5);
    int expected = 0;

    cr_assert_eq(got, expected);
}
