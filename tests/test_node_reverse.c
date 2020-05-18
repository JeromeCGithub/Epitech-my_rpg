/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** test_node_reverse
*/

#include "lib/mynode.h"
#include <criterion/criterion.h>

Test(node_reverse, simple_reverse)
{
    NODE *head = NULL;
    char *buff[] = {"1", "2", "3", "4", NULL};
    size_t i = 0;
    NODE *curr;

    node_insert(&head, "1");
    node_insert(&head, "2");
    node_insert(&head, "3");
    node_insert(&head, "4");
    node_reverse(&head);
    curr = head;
    while (head && buff[i]) {
        cr_assert_str_eq(buff[i], curr->data);
        curr = curr->next;
        i++;
    }
}
