/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_save
*/

#include "my_rpg.h"

static bool missing_directory(char const *directory)
{
    struct stat statbuf;

    if (stat(directory, &statbuf) == 1)
        return true;
    if (S_ISDIR(statbuf.st_mode))
        return false;
}

/*
** @DESCRIPTION
**   This function saves the quests data into the file pointed to by
**   SAVE_PLAYER_QUESTS
*/
void player_quests_save(player_t *this)
{
    int fd = open(SAVE_PLAYER_QUESTS, O_WRONLY | O_CREAT,
        S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);

    if (fd == -1)
        return;
    for (unsigned int i = 0; i < this->qnumber; i++) {
        write(fd, &(this->quests[i]), sizeof(quest_state_t));
    }
}

void player_save(player_t *this)
{
    int fd = open(SAVE_PLAYER_STATS, O_CREAT | O_WRONLY,
        S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);

    if (fd == -1)
        return;
    write(fd, this, sizeof(player_t));
    close(fd);
    fd = open(SAVE_PLAYER_QUESTS, O_WRONLY | O_CREAT,
        S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);
    if (fd == -1)
        return;
    for (unsigned int i = 0; i < this->qnumber; i++)
        write(fd, &(this->quests[i]), sizeof(quest_state_t));
    close(fd);
}