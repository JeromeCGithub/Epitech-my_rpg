/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_create_from_save
*/

#include "my_rpg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static bool missing_directory(char const *directory)
{
    struct stat statbuf;

    if (stat(directory, &statbuf) == 1)
        return true;
    if (S_ISDIR(statbuf.st_mode))
        return false;
}

static void player_create_set_quests(player_t *this)
{
    unsigned int qnumber = 0;

    for (; QUESTS[qnumber].title; qnumber++);
    this->qnumber = qnumber;
    this->quests = malloc(sizeof(quest_state_t) * (qnumber + 1));
    for (unsigned int i = 0; i < this->qnumber; i++)
        this->quests[i] = (QUESTS[i].unlock_index == -1) ?
        questUnlocked : questLocked;
}

void player_load_stats(player_t *this)
{
    int fd = open(SAVE_PLAYER_STATS, O_RDONLY);

    this->loaded = false;
    if (fd == -1)
        return;
    read(fd, this, sizeof(player_t));
    this->loaded = true;
    close(fd);
}

void player_load_quests(player_t *this)
{
    int fd = open(SAVE_PLAYER_QUESTS, O_RDONLY);

    if (fd == -1)
        return;
    for (unsigned int i = 0; i < this->qnumber; i++)
        read(fd, &this->quests[i], sizeof(quest_state_t));
}

/*
** @DESCRIPTION
**   This function loads the previous player data if it was provided.
*/
void player_create_from_save(player_t *this)
{
    player_load_stats(this);
    player_create_set_quests(this);
    player_load_quests(this);
}