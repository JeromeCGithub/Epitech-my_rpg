/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** update_weather
*/

#include "my_rpg.h"

void render_weather(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;
    weather_t *this = &exts->weather;
    particle_buf_t buffer;
    sfVector2f position;

    if (this->type == 0) {
        buffer = PARTICLE_SNOW;
    } else {
        buffer = PARTICLE_RAIN;
    }
    buffer.pos.y = exts->player->hitbox.top;
    buffer.pos.x = exts->player->hitbox.left;
    particle_create(exts->particles, buffer, 1);
    if (rand_range(0, 1000) == 1) {
        this->inevent = false;
    }
}

void update_weather(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;
    weather_t *this = &exts->weather;

    if (!this->inevent) {
        int value = rand_range(0, 1000);
        if (value == 1) {
            this->inevent = true;
            this->type = rand_range(0, 2);
        }
    } else {
        render_weather(view, game);
    }
}