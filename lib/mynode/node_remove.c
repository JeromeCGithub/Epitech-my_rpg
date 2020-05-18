/*
** EPITECH PROJECT, 2019
** lib/mynode
** File description:
** node_remove
*/

#include "mynode.h"

/*
** @DESCRIPTION
**   This function removes the NODE pointed by the ptr.
*/
void node_remove(NODE **head, void *ptr)
{
    NODE *previous = NULL;
    NODE *curr = *head;
    bool found = false;

    for (; curr; curr = curr->next) {
        if (curr->data == ptr) {
            found = true;
            break;
        }
        previous = curr;
    }
    if (found) {
        if (previous)
            previous->next = curr->next;
        else
            *head = curr->next;
        free(curr);
    }
}
