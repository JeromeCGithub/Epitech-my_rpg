/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Header File | particles
*/

#ifndef MY_RPG_PARTICLES_STATIC_H_
#define MY_RPG_PARTICLES_STATIC_H_

/**/
/* Includes */
/**/

/**/
/* Constant Definitions */
/**/

void particle_destroy(particle_t *this);

void particle_static_update(particle_t *this);
void particle_stray_update(particle_t *this);

void particle_static_init(particle_t *this, particle_buf_t *buf);
void particle_stray_init(particle_t *this, particle_buf_t *buf);

typedef struct {
    fptr init;
    fptr update;
} fptr_wrapper_t;

static const unsigned int PARTICLE_LIFESPAN = 100;
static const fptr_wrapper_t PARTICLES_FUNC[] = {
    {.init = particle_static_init, .update = particle_static_update},
    {.init = particle_stray_init, .update = particle_stray_update}
};

/**/
/* Enum Definitions */
/**/

/**/
/* Structure Definitions */
/**/

/**/
/* Function Prototypes */
/**/

/**/
/* Dependant Statements */
/**/

#endif
