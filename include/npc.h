/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** npc
*/

#ifndef _NPC_H_
#define _NPC_H_

#include "lib/qtree.h"

enum nb_of_e {
    NB_OF_MESSAGES = 14,
    NB_OF_FUNC = 2
};

typedef struct npc_s {
    sfVector2i collisions;
    sfFloatRect rect;
    void (*function)(struct npc_s *, void *);
    sfSprite *sprite;
    sfText *text;
    hitbox_t *hitbox;
} npc_t;

void npc_create(qtree_t *qt, sfVector2f pos);
void npc_default(npc_t *npc, void *view);
void npc_show_quest(npc_t *npc, void *view);

static const void (*NPC_FUNC_LIST[])(npc_t *, void *) = {
    &npc_default,
    &npc_show_quest
};

static const char *NPC_MESSAGES[] = {
    "Hi !",
    "How are you ?",
    "You may not rest now,\nthere are monsters nearby",
    "Never dig down",
    "The cake is a lie",
    "Epitech > Epita",
    "Stay at home",
    "Joffrey je t'aime <3",
    "Tony il est bg en vrai",
    "L'engin de diego...",
    "Did someone just fart?",
    "Je suis Pamela",
    "Unit Tested"
};

#endif /* !_NPC_H_ */
