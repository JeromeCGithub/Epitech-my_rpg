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

#define BOTTOM(rect) (rect->top + rect->height)
#define TOP(rect) (rect->top - rect->height)
#define LEFT(rect) (rect->left - rect->width)
#define RIGHT(rect) (rect->left + rect->width)
#define ABS(nb) ((nb < 0) ? (-nb) : (nb))

enum collisions_directions_e {
    NORTH = -1,
    SOUTH = 1,
    EAST = 1,
    WEST = -1
};

typedef enum hitbox_type_e {
    PLAYER_COLLIDER,
    WALL,
    MOB_COLLIDER,
    KNOCKBACK_COLLIDER,
    ITEM_COLLIDER,
    NPC_COLLIDER,
    NONE
} hitbox_type_t;

typedef struct hitbox_s {
    _Bool is_blocking;
    sfFloatRect *rect;
    sfVector2i *collisions;
    void *data;
    sfRectangleShape *shape;
    hitbox_type_t type;
    hitbox_type_t collide_with;
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
hitbox_t *hitbox_create(sfFloatRect *, sfVector2i *, void *, hitbox_type_t);
qtree_t *qtree_create(sfFloatRect);
sfRectangleShape *qtree_rect_create(sfFloatRect);

#endif /* _QTREE_H_ */
