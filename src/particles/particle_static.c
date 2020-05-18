/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** particle_static
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   This function initialises all particles of type particleStatic.
*/
void particle_static_init(particle_t *this, particle_buf_t *buf)
{
    sfVector2f vec = {0, 0};

    vec.x = rand_range(-buf->spread, buf->spread) + buf->pos.x;
    vec.y = rand_range(-buf->spread, buf->spread) + buf->pos.y;
    this->vector.x += frand_range(-buf->vecrand, buf->vecrand);
    this->vector.y += frand_range(-buf->vecrand, buf->vecrand);
    sfRectangleShape_setPosition(this->self, vec);
}

/*
** @DESCRIPTION
**   This function updates all particles of type particleStatic.
*/
void particle_static_update(particle_t *this)
{
    this->vector.x *= this->acceleration;
    this->vector.y *= this->acceleration;
    sfRectangleShape_move(this->self, this->vector);
}
