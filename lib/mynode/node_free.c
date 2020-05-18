/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** node_free
*/

#include "mynode.h"

/*
** @DESCRIPTION
**   Frees an entire list of nodes.
** @RETURN_VALUE
**   None.
*/
void node_free(NODE **head, fptr_t function)
{
    NODE *current = *head;
    NODE *temp;

    while (current != NULL) {
        if (function)
            function(temp->data);
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
