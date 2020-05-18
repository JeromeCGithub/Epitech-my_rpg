/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_recreate
*/

#include "qtree.h"

static void qtree_find_data(qtree_t *qtree, NODE **qt_data)
{
    if (!qtree)
        return;
    for (size_t i = 0; i < qtree->nb_entity; i++) {
        if (qtree->hitboxes[i]->rect)
            node_insert(qt_data, qtree->hitboxes[i]);
    }
    qtree_find_data(qtree->ne, qt_data);
    qtree_find_data(qtree->nw, qt_data);
    qtree_find_data(qtree->se, qt_data);
    qtree_find_data(qtree->sw, qt_data);
}

void qtree_recreate(qtree_t **qtree)
{
    sfFloatRect bounds = (*qtree)->bounds;
    qtree_t *new = NULL;
    NODE *qt_data = NULL;

    qtree_find_data(*qtree, &qt_data);
    qtree_destroy(*qtree, false);
    new = qtree_create(bounds);
    for (NODE *this = qt_data; this; this = this->next) {
        qtree_push(new, this->data);
    }
    *qtree = new;
    node_free(&qt_data, NULL);
}
