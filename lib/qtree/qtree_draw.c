/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_draw
*/

#include "qtree.h"

void qtree_draw(sfRenderWindow *window, qtree_t *qtree)
{
    if (!qtree)
        return;
    sfRenderWindow_drawRectangleShape(window, qtree->rect, NULL);
    for (size_t i = 0; i < qtree->nb_entity; i++) {
        sfRectangleShape_setPosition(qtree->hitboxes[i]->shape,
            (sfVector2f){qtree->hitboxes[i]->rect->left,
            qtree->hitboxes[i]->rect->top});
        sfRenderWindow_drawRectangleShape(window,
            qtree->hitboxes[i]->shape, NULL);
    }
    qtree_draw(window, qtree->ne);
    qtree_draw(window, qtree->nw);
    qtree_draw(window, qtree->se);
    qtree_draw(window, qtree->sw);
}
