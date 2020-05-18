/*
** EPITECH PROJECT, 2020
** fps
** File description:
** fps_draw
*/

#include <time.h>

#include "fps.h"

static size_t nblen(size_t nb)
{
    size_t len = 0;

    for (; nb > 0; nb /= 10, len++);
    return (len);
}

static void fps_calc(fps_t *fps, time_t t)
{
    static time_t prev_t = 0;
    int fps_nb = 0;
    int len = 0;

    fps_nb = (int)(1.0f / ((float)(t - prev_t) / 1000000.0f));
    fps->nb = (fps_nb) ? fps_nb : 0.1f;
    prev_t = t;
    len = nblen(fps_nb);
    if (!fps_nb) {
        fps->str[0] = '0';
        len++;
    }
    for (size_t i = 0; fps_nb > 0; i++, fps_nb /= 10)
        fps->str[len - 1 - i] = fps_nb % 10 + '0';
    fps->str[len] = ' ';
    fps->str[len + 1] = 'f';
    fps->str[len + 2] = 'p';
    fps->str[len + 3] = 's';
    fps->str[len + 4] = 0;
}

void fps_draw(sfRenderWindow *window, fps_t *fps)
{
    static time_t prev_t = 0;
    time_t t = sfClock_getElapsedTime(fps->clock).microseconds;

    fps_calc(fps, t);
    if (t - prev_t > 100000) {
        sfText_setString(fps->text, fps->str);
        prev_t = t;
    }
    sfRenderWindow_drawText(window, fps->text, NULL);
}
