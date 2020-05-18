/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** function_effect.c
*/

#include "my_rpg.h"

void attack_comp(void *player)
{
    static int update = 20;
    player_t *this = player;

    this->stats.strength += update;
    update += 15;
}

void def_comp(void *player)
{
    static int update = 50;
    player_t *this = player;

    this->stats.defense += update;
    update += 25;
}

void life_comp(void *player)
{
    static int update = 100;
    player_t *this = player;

    this->stats.defense += update;
    update += 50;
}