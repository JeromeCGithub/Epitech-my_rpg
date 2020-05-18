/*
** EPITECH PROJECT, 2019
** engine/engine
** File description:
** ge_hovers
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Given a sprite and the window this function will tell if the sprite is
**   being hovered on.
*/
bool ge_hovers(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    return sfFloatRect_contains(&bounds, (float)mouse.x, (float)mouse.y);
}
