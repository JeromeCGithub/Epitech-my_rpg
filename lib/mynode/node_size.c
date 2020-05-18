/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** node_list_size
*/

#include "mynode.h"

/*
** @DESCRIPTION
**   Counts the number of nodes in a linked list.
** @RETURN_VALUE
**   The number of nodes as an unsigned int.
*/
unsigned int node_size(NODE *head)
{
    unsigned int size = 0;

    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}
