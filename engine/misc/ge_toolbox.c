/*
** EPITECH PROJECT, 2019
** engine/engine
** File description:
** toolbox
*/

#include "engine.h"

/*
** @DESCRIPTION
**   This function takes in the byte index to modify and returns
**   the power of two value
**   3 => 4.
**   4 => 8.
**   5 => 16.
*/
unsigned int to_mask_value(unsigned int val)
{
    unsigned int ret = 1;

    for (unsigned int i = 0; i < val; i++)
        ret *= 2;
    return ret;
}