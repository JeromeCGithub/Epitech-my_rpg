/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** npc_functions
*/

#include "views.h"
#include "npc.h"

void npc_show_quest(npc_t *npc, void *view)
{
    ge_view_t *ge_view = view;
    sfFloatRect rect;

    sfText_setString(npc->text, NPC_MESSAGES[rand() % NB_OF_MESSAGES]);
    rect = sfText_getGlobalBounds(npc->text);
    sfText_setOrigin(npc->text, (sfVector2f){rect.width / 2, rect.height / 2});
    action_view_quests(ge_view, ge_view->dataobject);
}

void npc_default(npc_t *npc, void *view)
{
    sfFloatRect rect;

    sfText_setString(npc->text, NPC_MESSAGES[rand() % NB_OF_MESSAGES]);
    rect = sfText_getGlobalBounds(npc->text);
    sfText_setOrigin(npc->text, (sfVector2f){rect.width / 2, rect.height / 2});
}