/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_subdivide
*/

#include "qtree.h"

void qtree_subdivide(qtree_t *qt)
{
    sfFloatRect ne = {qt->bounds.left + qt->bounds.width / 2.0f,
        qt->bounds.top - qt->bounds.height / 2.0f,
        qt->bounds.width / 2.0f, qt->bounds.height / 2.0f};
    sfFloatRect nw = {qt->bounds.left - qt->bounds.width / 2.0f,
        qt->bounds.top - qt->bounds.height / 2.0f,
        qt->bounds.width / 2.0f, qt->bounds.height / 2.0f};
    sfFloatRect se = {qt->bounds.left + qt->bounds.width / 2.0f,
        qt->bounds.top + qt->bounds.height / 2.0f,
        qt->bounds.width / 2.0f, qt->bounds.height / 2.0f};
    sfFloatRect sw = {qt->bounds.left - qt->bounds.width / 2.0f,
        qt->bounds.top + qt->bounds.height / 2.0f,
        qt->bounds.width / 2.0f, qt->bounds.height / 2.0f};

    qt->ne = qtree_create(ne);
    qt->nw = qtree_create(nw);
    qt->se = qtree_create(se);
    qt->sw = qtree_create(sw);
    qt->is_divided = true;
}
