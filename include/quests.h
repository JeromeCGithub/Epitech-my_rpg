/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** quests header file.
*/

#ifndef MY_RPG_QUESTS_H_
#define MY_RPG_QUESTS_H_

/**/
/* Includes */
/**/

#include <stdlib.h>

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/

typedef enum quest_state_e {
    questLocked,
    questUnlocked,
    questCompleted
} quest_state_t;

typedef struct quest_reward_s {
    float health;
    float mana;
    float food;
    float strength;
    float defense;
    float xp;
} quest_reward_t;

typedef struct quest_s {
    char *title;
    char *description;
    unsigned int rew_index;
    unsigned int unlock_index;
} quest_t;

static const struct quest_reward_s QUESTS_REWARD[] = {
    {.health = 20, .mana = 20, .food = 20, .strength = 25,
    .defense = 25, .xp = 100},
    {.health = 50, .mana = 50, .food = 50, .strength = 60,
    .defense = 60, .xp = 200},
    {.health = 100, .mana = 100, .food = 100, .strength = 125,
    .defense = 125, .xp = 300}
};

static const struct quest_s QUESTS[] = {
    {"Bling Bling", "Equipe a piece of equipment.", 0, -1},
    {"Seems rotten", "Find a piece of food and eat it.", 0, -1},
    {"First Blood", "Find an enemy and kill it.", 0, -1},
    {"On a diet", "Reach maximal hunger.", 0, 1},
    {"Technically dead", "Have your health be less than 25.", 1, 3},
    {"Watch out", "Cast a spell.", 1, 1},
    {"The end", "Complete the skill tree.", 2, 5},
    {NULL, NULL}};

/**/
/* Function prototypes */
/**/

#endif
