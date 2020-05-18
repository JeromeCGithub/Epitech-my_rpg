/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** node_list_insert
*/

#include "mynode.h"

/*
** @DESCRIPTION
**   Allocates a new node to be freed and puts it at the top of the provided
**   node list.
**   Links the void * data to the node.
** @RETURN_VALUE
**   None.
*/
void node_insert(NODE **head, void *data)
{
    NODE *new = malloc(sizeof(*new));

    if (new != NULL) {
        new->data = data;
        new->next = *head;
        *head = new;
    }
}
