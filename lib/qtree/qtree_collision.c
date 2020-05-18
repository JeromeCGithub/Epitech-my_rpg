/*
** EPITECH PROJECT, 2020
** qtree
** File description:
** qtree_collision
*/

#include <math.h>
#include <iso646.h>
#include "qtree.h"

static void set_box_position(hitbox_t *box1, hitbox_t *box2)
{
    sfVector2f movement = {0, 0};

    if (box1->collisions->y == SOUTH)
        movement.y = (TOP(box2->rect) - BOTTOM(box1->rect));
    if (box1->collisions->y == NORTH)
        movement.y = (BOTTOM(box2->rect) - TOP(box1->rect));
    if (box1->collisions->x == EAST)
        movement.x = (LEFT(box2->rect) - RIGHT(box1->rect));
    if (box1->collisions->x == WEST)
        movement.x = (RIGHT(box2->rect) - LEFT(box1->rect));
    if (!movement.x or ABS(movement.y) < ABS(movement.x))
        box1->rect->top += movement.y;
    if (!movement.y or ABS(movement.x) < ABS(movement.y))
        box1->rect->left += movement.x;
}

static bool is_blocking(hitbox_t *b1, hitbox_t *b2)
{
    if (b1->type == WALL or b1->type == ITEM_COLLIDER
        or b2->type == ITEM_COLLIDER
        or b1->type == NPC_COLLIDER
        or !rect_intersect(*(b1->rect), *(b2->rect)))
        return (true);
    if (b1->type == b2->type)
        return (true);
    if (b1->type == PLAYER_COLLIDER and b2->type == MOB_COLLIDER)
        b1->collide_with = b2->type;
    return (false);
}

static void check_collision(hitbox_t *b1, hitbox_t *b2)
{
    if (is_blocking(b1, b2))
        return;
    if (TOP(b2->rect) < BOTTOM(b1->rect)
        and TOP(b1->rect) < TOP(b2->rect))
        b1->collisions->y = SOUTH;
    if (BOTTOM(b2->rect) > TOP(b1->rect)
        and BOTTOM(b1->rect) > BOTTOM(b2->rect))
        b1->collisions->y = NORTH;
    if (RIGHT(b1->rect) > LEFT(b2->rect)
        and LEFT(b1->rect) < LEFT(b2->rect))
        b1->collisions->x = EAST;
    if (LEFT(b1->rect) < RIGHT(b2->rect)
        and RIGHT(b1->rect) > RIGHT(b2->rect))
        b1->collisions->x = WEST;
    set_box_position(b1, b2);
}

void qtree_collision(qtree_t *qtree, sfFloatRect range)
{
    sfFloatRect temp;
    NODE *query = NULL;
    NODE *other = NULL;

    qtree_query(qtree, &query, range);
    for (NODE *curr = query; curr; curr = curr->next) {
        temp = *((hitbox_t *)curr->data)->rect;
        temp.left -= temp.width;
        temp.top -= temp.height;
        temp.width *= 2;
        temp.height *= 2;
        sfRectangleShape_setOutlineColor(((hitbox_t *)curr->data)->shape,
            sfRed);
        qtree_query(qtree, &other, temp);
        for (NODE *this = other; this; this = this->next)
            if (this->data != curr->data)
                check_collision(curr->data, this->data);
        node_free(&other, NULL);
    }
    node_free(&query, NULL);
}
