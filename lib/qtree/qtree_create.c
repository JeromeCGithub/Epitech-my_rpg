/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_create
*/

#include <stdlib.h>
#include "qtree.h"

qtree_t *qtree_create(sfFloatRect bounds)
{
    qtree_t *new = malloc(sizeof(qtree_t));

    if (!new)
        return (NULL);
    new->is_divided = false;
    new->nb_entity = 0;
    new->bounds = bounds;
    new->rect = qtree_rect_create(bounds);
    new->ne = NULL;
    new->nw = NULL;
    new->se = NULL;
    new->sw = NULL;
    return (new);
}
