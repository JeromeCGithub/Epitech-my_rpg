/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_push
*/

#include "qtree.h"

static bool in_node(sfFloatRect bounds, sfFloatRect rect)
{
    return (rect.left <= bounds.left + bounds.width
            && rect.left >= bounds.left - bounds.width
            && rect.top <= bounds.top + bounds.height
            && rect.top >= bounds.top - bounds.height);
}

bool qtree_push(qtree_t *qtree, hitbox_t *data)
{
    if (!in_node(qtree->bounds, *data->rect))
        return (false);
    if (qtree->nb_entity < QT_CAPACITY) {
        qtree->hitboxes[qtree->nb_entity] = data;
        qtree->nb_entity++;
        return (true);
    }
    if (!qtree->is_divided)
        qtree_subdivide(qtree);
    if (qtree_push(qtree->ne, data))
        return (true);
    if (qtree_push(qtree->nw, data))
        return (true);
    if (qtree_push(qtree->se, data))
        return (true);
    if (qtree_push(qtree->sw, data))
        return (true);
    return (false);
}
