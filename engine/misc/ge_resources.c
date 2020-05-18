/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_resources
*/

#include "engine.h"

static void ge_resources_add(NODE **head, void *ptr, c_char *key)
{
    ge_str_ptr_fptr_t *buf;

    buf = malloc(sizeof(*buf));
    if (!buf) {
        my_puts(2, "Abort: Failed malloc call at ge_resources_add.\n");
        my_error(err_write, 84);
        return;
    }
    buf->pointer = ptr;
    buf->string = my_strdup(key);
    node_insert(head, buf);
}

static void *ge_resources_fetch(NODE *head, c_char *key)
{
    ge_str_ptr_fptr_t *tmp;

    for (; head; head = head->next) {
        tmp = head->data;
        if (my_strcmp(tmp->string, key) == 0)
            return tmp->pointer;
    }
    return NULL;
}

/*
** @DESCRIPTION
** Todo: Free the assets.
*/
static void ge_resources_destroy(NODE **head)
{
    ge_str_ptr_fptr_t *tmp;
    NODE *to_free;

    for (NODE *curr = *head; curr; free(to_free)) {
        tmp = curr->data;
        to_free = curr;
        free(tmp->string);
        free(tmp);
        curr = curr->next;
    }
    *head = NULL;
}

/*
** @DESCRIPTION
**   This function will either store a pointer / key pair or fetch a pointer
**   using a query.
**   Add a pointer to the stack:
**      ge_resources(pointer_to_add, key);
**   Retreive a pointer which you've pushed on the stack:
**      ge_resources(NULL, key);
**   Free all the pointers on the stack:
**      ge_resources(NULL, NULL);
*/
void *ge_resources(void *ptr, c_char *key)
{
    static NODE *head;

    if (!head)
        head = NULL;
    if (ptr && key)
        ge_resources_add(&head, ptr, key);
    else if (key)
        return ge_resources_fetch(head, key);
    else
        ge_resources_destroy(&head);
    return NULL;
}
