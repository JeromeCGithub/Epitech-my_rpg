/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_destroy.c
*/

#include <stdlib.h>
#include "qtree.h"

void qtree_destroy(qtree_t *qtree, bool is_end)
{
    if (!qtree)
        return;
    qtree_destroy(qtree->ne, is_end);
    qtree_destroy(qtree->nw, is_end);
    qtree_destroy(qtree->se, is_end);
    qtree_destroy(qtree->sw, is_end);
    sfRectangleShape_destroy(qtree->rect);
    if (is_end) {
        for (size_t i = 0; i < qtree->nb_entity; i++)
            free(qtree->hitboxes[i]);
    }
    free(qtree);
}
