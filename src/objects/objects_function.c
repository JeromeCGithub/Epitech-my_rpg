/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** objects_function
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   This function uses the stats contained in the the parameter this
**   to impact the player's statistics.
*/
void object_use_consumable(ge_view_t *view, rpg_t *rpg, object_t *this)
{
    game_exts_t *exts = view->exts;
    player_t *player = exts->player;

    player_food(player, this->stat[FOOD_IMPACT]);
    player_health(player, this->stat[HEALTH_IMPACT]);
    player_mana(player, this->stat[MANA_IMPACT]);
}

/*
** @DESCRIPTION
**   This function uses the stats contained in the the parameter this
**   to impact the player's statistics.
*/
void object_use_equipable(ge_view_t *view, rpg_t *rpg, object_t *this)
{
    game_exts_t *exts = view->exts;
    player_t *player = exts->player;

    player->stats.food[psMax] += this->stat[FOOD_IMPACT];
    player->stats.health[psMax] += this->stat[HEALTH_IMPACT];
    player->stats.mana[psMax] += this->stat[MANA_IMPACT];
    player->stats.strength += this->stat[STRENGTH_IMPACT];
    player->stats.defense += this->stat[DEFENSE_IMPACT];
}
