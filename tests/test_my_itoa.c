/*
** EPITECH PROJECT, 2019
** mystdio
** File description:
** Tests | my_str_merge
*/

#include <criterion/criterion.h>
#include "lib/mystdio.h"

Test(my_itoa, simple_number)
{
    cr_assert_str_eq(my_itoa(10), "10");
    cr_assert_str_eq(my_itoa(-10), "-10");
    cr_assert_str_eq(my_itoa(0), "0");
    cr_assert_str_eq(my_itoa(999), "999");
    cr_assert_str_eq(my_itoa(-999), "-999");
    cr_assert_str_eq(my_itoa(-37879), "-37879");
}
