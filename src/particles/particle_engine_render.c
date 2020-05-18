/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** particle_engine_render
*/

#include "my_rpg.h"
#include "static/particles.h"

bool particle_filter_dead(particle_t *this)
{
    unsigned int el;

    el = sfTime_asMilliseconds(sfClock_getElapsedTime(this->clock));
    if (el > this->lifespan) {
        return false;
    }
    return true;
}

void particle_engine_render(particles_t *this)
{
    particle_t *particle;
    u_int el = 0;

    for (NODE *curr = this->self; curr; curr = curr->next) {
        particle = curr->data;
        PARTICLES_FUNC[particle->type].update(particle);
        sfRectangleShape_rotate(particle->self, particle->rotation);
        sfRenderWindow_drawRectangleShape(this->window, particle->self, 0);
    }
    node_filter(&(this->self), particle_filter_dead, particle_destroy);
}
