/*
** EPITECH PROJECT, 2020
** my_rand
** File description:
** my_rand
*/

#include <stdlib.h>

int rand_range(int min, int max)
{
    if (!max && min)
        return (rand() % min);
    if (!min && max)
        return (rand() % max);
    if (!min && !max)
        return 0;
    if (!(max - min))
        return (rand() % max);
    return (rand() % (max - min) + min);
}

float frand_range(int min, int max)
{
    float result = 0;

    min *= 100000;
    max *= 100000;
    result = rand_range(min, max);
    result /= 100000.0f;
    return (result);
}

int rand_choose(int nb1, int nb2)
{
    if ((rand() % 2) & 1)
        return (nb1);
    return (nb2);
}
