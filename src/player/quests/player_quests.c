/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_quests
*/

#include "my_rpg.h"
#include "quests.h"

/*
** @DESCRIPTION
**   Calling this function will mark the quest refered by qindex complete.
**   It will also add the bonus stats to the player.
*/
int player_quest_complete(player_t *p, unsigned int qindex)
{
    if (p->quests[qindex] != questUnlocked)
        return (-1);
    p->quests[qindex] = questCompleted;
    p->stats.food[psMax] += QUESTS_REWARD[QUESTS[qindex].rew_index].food;
    p->stats.mana[psMax] += QUESTS_REWARD[QUESTS[qindex].rew_index].mana;
    p->stats.health[psMax] += QUESTS_REWARD[QUESTS[qindex].rew_index].health;
    p->stats.strength += QUESTS_REWARD[QUESTS[qindex].rew_index].strength;
    p->stats.defense += QUESTS_REWARD[QUESTS[qindex].rew_index].defense;
    p->stats.xp += QUESTS_REWARD[QUESTS[qindex].rew_index].xp;
    for (unsigned int i = 0; i < p->qnumber; i++) {
        if (QUESTS[i].unlock_index == qindex) {
            p->quests[i] = questUnlocked;
        }
    }
    return (3);
}

char *player_quest_generate_string(player_t *this)
{
    char *string = my_strdup("Active quests:\n\n");
    char *temp;
    char *temp2;

    for (unsigned int i = 0; i < this->qnumber; i++) {
        if (this->quests[i] == questUnlocked) {
            temp2 = my_sprintf("Quest: %s\nDescription: %s\n",
                QUESTS[i].title, QUESTS[i].description);
            temp = my_str_merge(string, temp2);
            free(string);
            free(temp2);
            string = temp;
        }
    }
    return string;
}