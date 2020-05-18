/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** node_list_reverse
*/

#include "mynode.h"

/*
** @DESCRIPTION
**   Reverses the order of the provided linked list.
** @RETURN_VALUE
**   None.
*/
void node_reverse(NODE **head)
{
    NODE *curr = *head;
    NODE *next = NULL;
    NODE *prev = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
