/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** node_pop
*/

#include "mynode.h"

/*
** @DESCRIPTION
**   This function removes the first node of a linked list.
*/
void node_pop(NODE **head, fptr_t function)
{
    NODE *to_free = *head;

    if (to_free) {
        *head = to_free->next;
        if (function)
            function(to_free->data);
        free(to_free);
    }
}