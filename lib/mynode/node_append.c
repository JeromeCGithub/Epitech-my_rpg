/*
** EPITECH PROJECT, 2019
** lib/mynode
** File description:
** node_append
*/

#include "mynode.h"

/*
** @DESCRIPTION
**   Append a node to the end of a linked list.
*/
void node_append(NODE **head, void *data)
{
    NODE *new = malloc(sizeof(*new));
    NODE *previous = NULL;

    if (new != NULL) {
        new->data = data;
        new->next = NULL;
    }
    for (NODE *curr = *head; curr; curr = curr->next)
        previous = curr;
    if (!previous)
        *head = new;
    else
        previous->next = new;
}