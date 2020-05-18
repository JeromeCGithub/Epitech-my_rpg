/*
** EPITECH PROJECT, 2019
** myerror
** File description:
** Tests | my_error
*/

#include <criterion/criterion.h>
#include "lib/myerror.h"

Test(my_error, simple_tests)
{
    cr_assert_eq(my_error(err_read, 0), 0);
    cr_assert_eq(my_error(err_write, 84), 0);
    cr_assert_eq(my_error(err_read, 0), 84);
    cr_assert_eq(my_error(err_write, -84), 0);
    cr_assert_eq(my_error(err_read, 0), -84);
}
