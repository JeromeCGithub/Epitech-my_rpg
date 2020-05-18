/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_h
*/

#ifndef _QTREE_H_
#define _QTREE_H_

#include <stdbool.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>

#include "lib/mynode.h"

#ifndef QT_CAPACITY
#define QT_CAPACITY 4
#endif

typedef struct hitbox_s {
    sfFloatRect *rect;
    unsigned int *mask;
} hitbox_t;

typedef struct qtree_s {
    bool is_divided;
    size_t nb_entity;
    sfFloatRect bounds;
    sfRectangleShape *rect;
    hitbox_t *hitboxes[QT_CAPACITY];
    struct qtree_s *ne;
    struct qtree_s *nw;
    struct qtree_s *se;
    struct qtree_s *sw;
} qtree_t;

void qtree_draw(sfRenderWindow *, qtree_t *);
void qtree_query(qtree_t *, NODE **, sfFloatRect);
void qtree_destroy(qtree_t *, bool);
void qtree_recreate(qtree_t **);
void qtree_subdivide(qtree_t *);
bool qtree_push(qtree_t *, hitbox_t *);
bool rect_intersect(sfFloatRect, sfFloatRect);
bool rect_intersect2(sfFloatRect, sfFloatRect);
void qtree_collision(qtree_t *, sfFloatRect);
hitbox_t *hitbox_create(sfFloatRect *, unsigned int *);
qtree_t *qtree_create(sfFloatRect);
sfRectangleShape *qtree_rect_create(sfFloatRect);

#endif /* _QTREE_H_ */
