/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_rect_create
*/

#include <SFML/Graphics/RectangleShape.h>

sfRectangleShape *qtree_rect_create(sfFloatRect bounds)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    if (!rect)
        return (NULL);
    sfRectangleShape_setOrigin(rect, (sfVector2f){bounds.width, bounds.height});
    sfRectangleShape_setPosition(rect, (sfVector2f){bounds.left, bounds.top});
    sfRectangleShape_setSize(rect,
        (sfVector2f){bounds.width * 2, bounds.height * 2});
    sfRectangleShape_setOutlineColor(rect, sfGreen);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    return (rect);
}
