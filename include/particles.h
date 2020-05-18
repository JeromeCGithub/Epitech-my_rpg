/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Header File | particles
*/

#ifndef MY_RPG_PARTICLES_H_
#define MY_RPG_PARTICLES_H_

/**/
/* Includes */
/**/

/**/
/* Constant Definitions */
/**/

/**/
/* Enum Definitions */
/**/

typedef enum {
    particle_static,
    particle_stray
} particle_type_t;

/**/
/* Structure Definitions */
/**/

typedef struct {
    particle_type_t type;
    float acceleration;
    float spread;
    float vecrand;
    int rotation;
    int initial_rotation;
    unsigned int lifespan;
    bool centered;
    sfColor color;
    sfVector2f size;
    sfVector2f vector;
    sfVector2f pos;
} particle_buf_t;

static const particle_buf_t PARTICLE = {
    .type = particle_static,
    .spread = 0,
    .vecrand = 0,
    .color = {255, 255, 255, 255},
    .size = {5, 5},
    .pos = {0, 0},
    .vector = {0, 0},
    .lifespan = 2000,
    .rotation = 1,
    .centered = false,
    .initial_rotation = 0,
    .acceleration = 0.99f
};

static const particle_buf_t PARTICLE_LVL = {
    .type = particle_static,
    .spread = 7,
    .vecrand = 10,
    .color = {20, 255, 20, 255},
    .size = {5, 5},
    .pos = {0, 0},
    .vector = {0, 0},
    .lifespan = 1000,
    .rotation = 0,
    .centered = true,
    .initial_rotation = 45,
    .acceleration = 0.90f
};

static const particle_buf_t PARTICLE_BLOOD = {
    .type = particle_static,
    .spread = 5,
    .vecrand = 3,
    .color = {255, 20, 20, 255},
    .size = {5, 5},
    .pos = {0, 0},
    .vector = {0, 0},
    .lifespan = 500,
    .rotation = 3,
    .centered = true,
    .initial_rotation = 0,
    .acceleration = 0.90f
};

static const particle_buf_t PARTICLE_RAIN = {
    .type = particle_static,
    .spread = 1000,
    .vecrand = 0,
    .color = {100, 100, 255, 190},
    .size = {6, 18},
    .pos = {0, 0},
    .vector = {4, 16},
    .lifespan = 2000,
    .rotation = 0,
    .centered = false,
    .initial_rotation = -20,
    .acceleration = 1.0f
};

static const particle_buf_t PARTICLE_SNOW = {
    .type = particle_static,
    .spread = 1000,
    .vecrand = 1,
    .color = {255, 255, 255, 180},
    .size = {6, 6},
    .pos = {0, 0},
    .vector = {0, 2},
    .lifespan = 8000,
    .rotation = 1,
    .centered = true,
    .initial_rotation = -20,
    .acceleration = 1.0f
};

static const particle_buf_t PARTICLE_WIND = {
    .type = particle_static,
    .spread = 1000,
    .vecrand = 0,
    .color = {255, 255, 255, 100},
    .size = {3, 200},
    .pos = {0, 0},
    .vector = {9, 16},
    .lifespan = 1000,
    .rotation = 0,
    .centered = false,
    .initial_rotation = -35,
    .acceleration = 1.01f
};

typedef struct {
    sfClock *clock;
    float acceleration;
    unsigned int lifespan;
    float vecrand;
    int rotation;
    int initial_rotation;
    particle_type_t type;
    sfVector2f origin;
    sfVector2f vector;
    sfRectangleShape *self;
} particle_t;

typedef struct {
    sfClock *clock;
    sfRenderWindow *window;
    NODE *self;
} particles_t;

/**/
/* Function Prototypes */
/**/

particles_t *particle_engine_create(ge_view_t *view);
void particle_engine_render(particles_t *this);

int rand_range(int min, int max);
float frand_range(int min, int max);
int rand_choose(int nb1, int nb2);

void particle_static_update(particle_t *this);
void particle_stray_update(particle_t *this);
void particle_create(particles_t *this, particle_buf_t buf,
unsigned int amount);

/**/
/* Dependant Statements */
/**/


#endif
