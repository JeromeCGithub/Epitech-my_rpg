/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** Tests | my_str_merge
*/

#include <criterion/criterion.h>
#include "lib/mystdio.h"

Test(my_atoi, simple_number)
{
    cr_assert_eq(my_atoi("10"), 10);
    cr_assert_eq(my_atoi("-10"), -10);
    cr_assert_eq(my_atoi("-0"), 0);
    cr_assert_eq(my_atoi("999"), 999);
    cr_assert_eq(my_atoi("-999"), -999);
}

Test(my_atoi, errors)
{
    cr_assert_eq(my_atoi(NULL), 0);
    cr_assert_eq(my_atoi("-"), 0);
    cr_assert_eq(my_atoi("+"), 0);
    cr_assert_eq(my_atoi("Ese cristalito roto\n"), 0);
}

Test(my_atoi, complicated_test)
{
    cr_assert_eq(my_atoi("NULL-2781ad72"), -2781);
    cr_assert_eq(my_atoi("NULL---++1--21ad72"), 1);
    cr_assert_eq(my_atoi("-16-1111NULL-2781ad72"), -16);
    cr_assert_eq(my_atoi("   a-16  "), -16);
}
