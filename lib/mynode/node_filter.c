/*
** EPITECH PROJECT, 2019
** lib/mynode
** File description:
** node_remove
*/

#include "mynode.h"

static void node_cut(NODE **head, NODE *previous, NODE *curr, fptr_t free_func)
{
    NODE *to_free = curr;

    if (!previous)
        *head = curr->next;
    else
        previous->next = curr->next;
    if (free_func)
        free_func(to_free->data);
    free(to_free);
}

/*
** @DESCRIPTION
**   This function filters the list by removing the nodes for which the
**   function returns false.
*/
void node_filter(NODE **head, bool (*filter)(), fptr_t free_func)
{
    NODE *previous = NULL;
    NODE *to_free = NULL;

    for (NODE *curr = *head; curr;) {
        if (!filter(curr->data)) {
            to_free = curr;
            curr = curr->next;
            node_cut(head, previous, to_free, free_func);
        } else {
            previous = curr;
            curr = curr->next;
        }
    }
}