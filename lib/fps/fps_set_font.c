/*
** EPITECH PROJECT, 2020
** fps
** File description:
** fps_set_font
*/

#include "fps.h"

void fps_set_font(fps_t *fps, sfFont *font)
{
    if (!font)
        return;
    fps->font = font;
    sfText_setFont(fps->text, fps->font);
}
