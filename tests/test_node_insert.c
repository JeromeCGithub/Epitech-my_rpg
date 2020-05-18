/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** test_node_insert
*/

#include "lib/mynode.h"
#include <criterion/criterion.h>

Test(node_insert, simple_insert)
{
    NODE *head = NULL;

    node_insert(&head, "This is my string");
    cr_assert_eq(node_size(head), 1);
}
