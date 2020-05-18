/*
** EPITECH PROJECT, 2020
** fps
** File description:
** fps_destroy
*/

#include <stdlib.h>

#include "fps.h"

void fps_destroy(fps_t *fps)
{
    sfText_destroy(fps->text);
    free(fps->str);
    free(fps);
}
