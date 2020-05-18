/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** test_node_size
*/

#include "lib/mynode.h"
#include <criterion/criterion.h>

Test(node_size, simple_insert)
{
    NODE *head = NULL;

    node_insert(&head, "This is my string");
    node_insert(&head, NULL);
    node_insert(&head, (void *)true);
    node_insert(&head, (void *)1);

    cr_assert_eq(node_size(head), 4);
}
