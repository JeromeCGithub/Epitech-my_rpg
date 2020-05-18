/*
** EPITECH PROJECT, 2020
** fps
** File description:
** fps_set_position
*/

#include "fps.h"

void fps_set_position(fps_t *fps, sfVector2f position)
{
    sfText_setPosition(fps->text, position);
}
