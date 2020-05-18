/*
** EPITECH PROJECT, 2020
** my_rand
** File description:
** perlin
*/

#include <SFML/System/Vector2.h>
#include <math.h>
#include <stddef.h>

static float ponder(sfVector2f pos, sfVector2i grid_pos, sfVector2f gradient)
{
    sfVector2f temp = {pos.x - grid_pos.x, pos.y - grid_pos.y};

    return (gradient.x * temp.x + gradient.y * temp.y);
}

static float smoothing(sfVector2f pos, sfVector2i grid_pos, float *weight)
{
    sfVector2f coeff = {0, 0};
    float smooth[2];
    float temp = 0;

    temp = pos.x - grid_pos.x;
    coeff.x = 3 * temp * temp - 2 * temp * temp * temp;
    smooth[0] = weight[0] + coeff.x * (weight[1] - weight[0]);
    smooth[1] = weight[2] + coeff.x * (weight[3] - weight[2]);
    temp = pos.y - grid_pos.y;
    coeff.y = 3 * temp * temp - 2 * temp * temp * temp;
    return (smooth[0] + coeff.y * (smooth[1] - smooth[0]));
}

float perlin(sfVector2f pos, float res, unsigned int *perm)
{
    sfVector2i grid_pos = {pos.x / res, pos.y / res};
    sfVector2i index = {grid_pos.x & 255, grid_pos.y & 255};
    int grad[4] = {0, 0, 0, 0};
    float unit = 0.707106f;
    float weight[4] = {0, 0, 0, 0};
    sfVector2f gradient[8] = {
        {unit, unit}, {-unit, unit},
        {unit, -unit}, {-unit, -unit},
        {1.f, 0.f}, {-1.f, 0.f},
        {0.f, 1.f}, {0.f, -1.f}
    };

    pos.x /= res;
    pos.y /= res;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            grad[j + i * 2] = perm[index.x + perm[index.y + i] + j] % 8;
            weight[j + i * 2] = ponder(pos, (sfVector2i){j + grid_pos.x,
                i + grid_pos.y}, gradient[grad[j + i * 2]]);
        }
    return (smoothing(pos, grid_pos, weight));
}
