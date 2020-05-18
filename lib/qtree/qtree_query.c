/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_query
*/

#include "qtree.h"

void qtree_query(qtree_t *qtree, NODE **query_list, sfFloatRect range)
{
    if (!rect_intersect(range, qtree->bounds))
        return;
    for (size_t i = 0; i < qtree->nb_entity; i++) {
        if (qtree->hitboxes[i]->rect
            && rect_intersect(range, *(qtree->hitboxes[i]->rect)))
            node_insert(query_list, qtree->hitboxes[i]);
    }
    if (qtree->is_divided) {
        qtree_query(qtree->ne, query_list, range);
        qtree_query(qtree->nw, query_list, range);
        qtree_query(qtree->se, query_list, range);
        qtree_query(qtree->sw, query_list, range);
    }
}
