/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** particles_init
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   Initialises the particles engine.
*/
particles_t *particle_engine_create(ge_view_t *view)
{
    particles_t *this = malloc(sizeof(*this));

    this->window = view->window;
    this->self = NULL;
    return this;
}
