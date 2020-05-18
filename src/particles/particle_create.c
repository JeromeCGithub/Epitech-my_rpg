/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** particles
*/

#include "my_rpg.h"
#include "static/particles.h"

void particle_destroy(particle_t *this)
{
    sfClock_destroy(this->clock);
    free(this);
}

particle_t *particle_create_from_buf(particle_buf_t *buf)
{
    particle_t *this = malloc(sizeof(*this));

    this->clock = sfClock_create();
    this->type = buf->type;
    this->vector = buf->vector;
    this->acceleration = buf->acceleration;
    this->rotation = buf->rotation;
    this->initial_rotation = buf->initial_rotation;
    this->lifespan = buf->lifespan;
    this->self = sfRectangleShape_create();
    sfRectangleShape_setSize(this->self, buf->size);
    if (buf->centered)
        sfRectangleShape_setOrigin(this->self, (sfVector2f){buf->size.x / 2,
            buf->size.y / 2});
    sfRectangleShape_setFillColor(this->self, buf->color);
    sfRectangleShape_rotate(this->self, this->initial_rotation);
    PARTICLES_FUNC[this->type].init(this, buf);
    return this;
}

void particle_create(particles_t *this, particle_buf_t buf,
unsigned int amount)
{
    for (; 0 < amount; amount--) {
        node_insert(&(this->self), particle_create_from_buf(&buf));
    }
}
