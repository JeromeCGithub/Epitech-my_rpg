/*
** EPITECH PROJECT, 2019
** lib/mynode
** File description:
** node_insert_sorted
*/

#include "mynode.h"

void node_insert_sorted(NODE **head, void *data, boolfptr_t compare)
{
    NODE *new = malloc(sizeof(*new));
    NODE *previous = NULL;
    NODE *curr;

    if (!new)
        return;
    new->data = data;
    for (curr = *head; curr; curr = curr->next) {
        if (compare(data, curr->data))
            break;
        previous = curr;
    }
    if (previous) {
        previous->next = new;
        new->next = curr;
    } else {
        *head = new;
        new->next = curr;
    }
}