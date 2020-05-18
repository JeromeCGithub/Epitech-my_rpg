/*
** EPITECH PROJECT, 2020
** fps
** File description:
** fps_h
*/

#ifndef _FPS_H_
#define _FPS_H_

#include <SFML/Graphics.h>

typedef struct fps_s {
    float nb;
    char *str;
    sfText *text;
    sfFont *font;
    sfClock *clock;
} fps_t;

fps_t *fps_create(void);
void fps_set_font(fps_t *, sfFont *);
void fps_set_position(fps_t *, sfVector2f);
void fps_draw(sfRenderWindow *, fps_t *);
size_t fps_get(fps_t *);

#endif /* _FPS_H_ */
