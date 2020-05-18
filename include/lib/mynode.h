/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** Header File | mynode
*/

#ifndef LIB_MY_NODE_H_
#define LIB_MY_NODE_H_

/* Includes */

#include <stdlib.h>
#include <stdbool.h>

/* Constant Definitions */

typedef bool (*boolfptr_t)();
typedef void (*fptr_t)();

/* Enum Definitions */

/* Structure Definitions */
/*
** @DESCRIPTION
**   Holds the global node data for linked lists.
*/
typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

#define NODE struct node_s

/* Function Prototypes */

void node_insert(NODE **head, void *data);
void node_free(NODE **head, fptr_t function);
void node_reverse(NODE **head);
unsigned int node_size(NODE *head);
void node_append(NODE **head, void *data);
void node_filter(NODE **head, bool (*filter)(), fptr_t free_func);
void node_pop(NODE **head, fptr_t function);
void node_remove(NODE **head, void *ptr);
void node_apply(NODE *head, fptr_t function);
void node_insert_sorted(NODE **head, void *data, boolfptr_t compare);

/* Dependant Statements */

#endif
