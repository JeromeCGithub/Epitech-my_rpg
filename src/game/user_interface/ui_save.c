/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** ui_save.c
*/

#include "my_rpg.h"

static void stuff_save(inventory_t *inventory)
{
    int default_nb = -1;
    int fd = open("save/stuff.data", O_CREAT | O_WRONLY | O_TRUNC,
            S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);

    for (int i = 0; i < 6; i++) {
        if (inventory->stuff[i])
            write(fd, &(inventory->stuff[i]->list_id), sizeof(int));
        else
            write(fd, &default_nb, sizeof(int));
    }
    close(fd);
}

static void skill_tree_save(skill_tree_t *skill_tree)
{
    int nb = 1;
    int fd = open("save/skill_tree.data", O_CREAT | O_WRONLY | O_TRUNC,
            S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);

    if (!fd)
        return;
    for (int i = 0; i < 12; i++) {
        nb = skill_tree->skills[i]->locked;
        write(fd, &nb, sizeof(int));
    }
    nb = skill_tree->skill_point;
    write(fd, &nb, sizeof(int));
    close(fd);
}

void ui_save(user_interface_t *ui)
{
    int fd = open("save/inventory.data", O_CREAT | O_WRONLY | O_TRUNC,
            S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);

    for (int i = 0; i < NB_SLOT_INV; i++) {
        if (ui->inventory->slots[i]->object)
            write(fd, &(ui->inventory->slots[i]->object->list_id),
            sizeof(int));
    }
    stuff_save(ui->inventory);
    skill_tree_save(ui->skill_tree);
    close(fd);
}