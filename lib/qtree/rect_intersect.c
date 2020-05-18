/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** rect_intersect
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>

bool rect_intersect(sfFloatRect rect1, sfFloatRect rect2)
{
    sfFloatRect rec1 = {rect1.left - rect1.width, rect1.top -
        rect1.height, rect1.width * 2, rect1.height * 2};
    sfFloatRect rec2 = {rect2.left - rect2.width, rect2.top -
        rect2.height, rect2.width * 2, rect2.height * 2};
    int max_left = (rec1.left >= rec2.left) ? rec1.left : rec2.left;
    int min_right = (rec1.left + rec1.width >= rec2.left + rec2.width) ?
        rec2.left + rec2.width : rec1.left + rec1.width;
    int max_bottom = (rec1.top >= rec2.top) ? rec1.top : rec2.top;
    int min_up = (rec1.top + rec1.height >= rec2.top + rec2.height) ?
        rec2.top + rec2.height : rec1.top + rec1.height;

    return (max_left < min_right && max_bottom < min_up);
}

bool rect_intersect2(sfFloatRect rect1, sfFloatRect rect2)
{
    sfVector2f p1 = {rect1.left - rect1.width, rect1.top - rect1.height};
    sfVector2f r1 = {rect1.left + rect1.width, rect1.top + rect1.height};
    sfVector2f p2 = {rect2.left - rect2.width, rect2.top - rect2.height};
    sfVector2f r2 = {rect2.left + rect2.width, rect2.top + rect2.height};

    if (p1.x >= r2.x || p2.x >= r1.x)
        return (false);
    if (p1.y <= r2.y || p2.y <= r1.y)
        return (false);
    return (true);
}
