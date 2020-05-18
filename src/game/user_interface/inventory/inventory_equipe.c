/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_equipe.c
*/

#include "event_inventory.h"
#include <lib/mystring.h>
#include "my_rpg.h"

static int equipe_helmet(rpg_t *game, object_t *obj, ge_view_t *view,
    game_exts_t *view_ext)
{
    object_t **stuff = &(game->ui->inventory->stuff[HELMET]);
    int ret = 0;

    if (!my_strcmp(obj->type, "Helmet")) {
        revert_stat(game, view, HELMET);
        if (*stuff)
            ret = inventory_add(game->ui->inventory, (*stuff));
        if (ret == -1)
            return 0;
        (*stuff) = object_duplicate(obj);
        sfSprite_setPosition(
                (*stuff)->sprite, HELMET_POSITION);
        sfSprite_setScale((*stuff)->sprite, (sfVector2f) {2.5, 2.5});
    }
    if (view_ext->player->quests[0] == questUnlocked) {
        player_quest_complete(view_ext->player, 0);
        inventory_add_by_id(game->ui->object_list,
        game->ui->inventory, GOLD_HELMET);
    }
    return 1;
}

static int equipe_armour(rpg_t *game, object_t *obj, ge_view_t *view,
    game_exts_t *view_ext)
{
    object_t **stuff = &(game->ui->inventory->stuff[ARMOURS]);
    int ret = 0;

    if (!my_strcmp(obj->type, "Armours")) {
        revert_stat(game, view, ARMOURS);
        if (*stuff)
            ret = inventory_add(game->ui->inventory, (*stuff));
        if (ret == -1)
            return 0;
        (*stuff) = object_duplicate(obj);
        sfSprite_setPosition((*stuff)->sprite, ARMOURS_POSITION);
        sfSprite_setScale((*stuff)->sprite, (sfVector2f) {2.5, 2.5});
    }
    if (view_ext->player->quests[0] == questUnlocked) {
        player_quest_complete(view_ext->player, 0);
        inventory_add_by_id(game->ui->object_list,
        game->ui->inventory, GOLD_CHESTPLATE);
    }
    return 1;
}

static int equipe_boots(rpg_t *game, object_t *obj, ge_view_t *view,
    game_exts_t *view_ext)
{
    object_t **stuff = &(game->ui->inventory->stuff[BOOTS]);
    int ret = 0;

    if (!my_strcmp(obj->type, "boots")) {
        revert_stat(game, view, BOOTS);
        if (*stuff)
            ret = inventory_add(game->ui->inventory, (*stuff));
        if (ret == -1)
            return 0;
        (*stuff) = object_duplicate(obj);
        sfSprite_setPosition((*stuff)->sprite, BOOTS_POSITION);
        sfSprite_setScale((*stuff)->sprite, (sfVector2f) {2.5, 2.5});
    }
    if (view_ext->player->quests[0] == questUnlocked) {
        player_quest_complete(view_ext->player, 0);
        inventory_add_by_id(game->ui->object_list,
        game->ui->inventory, GOLD_BOOTS);
    }
    return 1;
}

static int equipe_shield(rpg_t *game, object_t *obj, ge_view_t *view,
    game_exts_t *view_ext)
{
    object_t **stuff = &(game->ui->inventory->stuff[SHIELD]);
    int ret = 0;

    if (!my_strcmp(obj->type, "shield")) {
        revert_stat(game, view, SHIELD);
        if (*stuff)
            ret = inventory_add(game->ui->inventory, (*stuff));
        if (ret == -1)
            return 0;
        (*stuff) = object_duplicate(obj);
        sfSprite_setPosition((*stuff)->sprite, SHIELD_POSITION);
        sfSprite_setScale((*stuff)->sprite, (sfVector2f) {2.5, 2.5});
    }
    if (view_ext->player->quests[0] == questUnlocked) {
        player_quest_complete(view_ext->player, 0);
        inventory_add_by_id(game->ui->object_list,
        game->ui->inventory, 3);
    }
    return 1;
}

int inventory_equipe(rpg_t *game, object_t *obj, ge_view_t *view)
{
    int ret = 0;
    game_exts_t *view_ext = view->exts;

    if (!obj || !game || !view)
        return 0;
    if (!my_strcmp(obj->type, "consommable")) {
        if (view_ext->player->quests[1] == questUnlocked)
            return (player_quest_complete(view_ext->player, 1));
        return 1;
    }
    ret = equipe_helmet(game, obj, view, view_ext);
    if (!ret)
        return ret;
    ret = equipe_boots(game, obj, view, view_ext);
    if (!ret)
        return ret;
    ret = equipe_armour(game, obj, view, view_ext);
    if (!ret)
        return ret;
    return (equipe_shield(game, obj, view, view_ext));
}