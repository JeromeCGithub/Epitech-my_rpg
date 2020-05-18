/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_functions
*/

#include "engine.h"

static void ge_functions_add(NODE **head, fptr func, c_char *key)
{
    ge_str_fptr_t *buff;

    buff = malloc(sizeof(*buff));
    if (!buff) {
        my_puts(2, "Abort: Failed malloc call at ge_functions_add.\n");
        my_error(err_write, 84);
        return;
    }
    buff->string = my_strdup(key);
    buff->function = func;
    node_insert(head, buff);
}

static fptr ge_functions_fetch(NODE *head, c_char *key)
{
    ge_str_fptr_t *tmp;
    fptr nullcb = &ge_null_endpoint;

    for (; head; head = head->next) {
        tmp = head->data;
        if (my_strcmp(tmp->string, key) == 0)
            return tmp->function;
    }
    my_dprintf(2, "\033[0;33m-- Note: Missing function '%s' ", key);
    my_puts(2, "was replaced by null endpoint.\n\033[0m");
    return nullcb;
}

static void ge_functions_destroy(NODE **head)
{
    ge_str_fptr_t *tmp;
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
**   This function will either store a function / key pair or fetch a function
**   using a query.
**   Add a function to the stack:
**      ge_functions(function_to_add, key);
**   Retreive a function which you've pushed on the stack:
**      ge_functions(NULL, key);
**   Free all the functions on the stack:
**      ge_functions(NULL, NULL);
*/
fptr ge_functions(fptr func, c_char *key)
{
    static NODE *head;

    if (!head)
        head = NULL;
    if (func && key)
        ge_functions_add(&head, func, key);
    else if (key)
        return ge_functions_fetch(head, key);
    else
        ge_functions_destroy(&head);
    return NULL;
}
