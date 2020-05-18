/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_interact
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   Modify the player's health by passing a positive / negative value to
**   player_health().
*/
void player_health(player_t *this, float health)
{
    this->stats.health[psValue] += health;
    if (this->stats.health[psValue] > this->stats.health[psMax]) {
        this->stats.health[psValue] = this->stats.health[psMax];
    } else if (this->stats.health[psValue] < 0) {
        this->stats.health[psValue] = 0;
    }
    player_interface_update_bar(this->interface->tiles[0], this->stats.health,
        "player-pred");
}

/*
** @DESCRIPTION
**   Modify the player's mana by passing a positive / negative value to
**   player_mana().
*/
void player_mana(player_t *this, float mana)
{
    this->stats.mana[psValue] += mana;
    if (this->stats.mana[psValue] > this->stats.mana[psMax]) {
        this->stats.mana[psValue] = this->stats.mana[psMax];
    } else if (this->stats.mana[psValue] < 0) {
        this->stats.mana[psValue] = 0;
    }
    player_interface_update_bar(this->interface->tiles[1], this->stats.mana,
        "player-pblue");
}

/*
** @DESCRIPTION
**   Modify the player's mana by passing a positive / negative value to
**   player_mana().
*/
void player_food(player_t *this, float food)
{
    this->stats.food[psValue] += food;
    if (this->stats.food[psValue] > this->stats.food[psMax]) {
        this->stats.food[psValue] = this->stats.food[psMax];
    }
    else if (this->stats.food[psValue] < 0) {
        this->stats.food[psValue] = 0;
    }
    player_interface_update_bar(this->interface->tiles[2], this->stats.food,
        "player-pgreen");
}
