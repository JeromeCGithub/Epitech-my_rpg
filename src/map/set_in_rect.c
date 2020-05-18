/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** set_in_rect
*/

#include <SFML/Graphics.h>

void set_in_rect(sfFloatRect rect, sfVector2f *pos)
{
    if (pos->x < rect.left)
        pos->x = rect.left;
    if (pos->y < rect.top)
        pos->y = rect.top;
    if (pos->x > rect.left + rect.width)
        pos->x = rect.left + rect.width;
    if (pos->y > rect.top + rect.height)
        pos->y = rect.top + rect.height;
}