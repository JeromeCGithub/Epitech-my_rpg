/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** fps_create
*/

#include <stdlib.h>

#include "fps.h"

fps_t *fps_create(void)
{
    fps_t *fps = malloc(sizeof(fps_t));

    if (!fps)
        return (NULL);
    fps->str = malloc(sizeof(char) * (10 + 1));
    if (!fps->str)
        return (NULL);
    for (size_t i = 0; i <= 10; i++)
        fps->str[i] = 0;
    fps->text = sfText_create();
    fps->clock = sfClock_create();
    return (fps);
}
