/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_tree_create.c
*/

#include "skill_tree.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/stat.h"

static skill_t *create_skill(
        sfVector2f position,
        sfIntRect skill_rect, sfTexture *texture)
{
    skill_t *new = malloc(sizeof(skill_t));

    if (!new)
        return (NULL);
    new->case_sprite = sfSprite_create();
    new->skill_sprite = sfSprite_create();
    sfSprite_setTexture(new->case_sprite, texture, sfTrue);
    sfSprite_setTexture(new->skill_sprite, texture, sfTrue);
    sfSprite_setTextureRect(new->case_sprite, CASE_SKILL_RECT);
    sfSprite_setTextureRect(new->skill_sprite, skill_rect);
    sfSprite_setPosition(new->case_sprite, position);
    sfSprite_setPosition(new->skill_sprite, position);
    sfSprite_setScale(new->case_sprite, SCALE_SKILL_CASE);
    sfSprite_setScale(new->skill_sprite, SCALE_SKILL_SPRITE);
    new->locked = true;
    return (new);
}

static void load_from_save(skill_tree_t *my_tree)
{
    int value = 1;
    int fd = open("save/skill_tree.data", O_RDONLY);

    if (!fd)
        return;
    for (int i = 0; i < 12; i++) {
        read(fd, &value, sizeof(int));
        if (value == 0) {
            my_tree->skills[i]->locked = false;
            sfSprite_setTextureRect(
                    my_tree->skills[i]->case_sprite, CASE_SKILL_ENABLE_RECT);
        }
    }
    read(fd, &(my_tree->skill_point), sizeof(int));
    close(fd);
}

skill_tree_t *skill_tree_init(sfTexture *texture)
{
    int n = 0;
    sfVector2f position = {60, 390};
    skill_tree_t *my_tree = malloc(sizeof(skill_tree_t));

    if (!my_tree)
        return (NULL);
    for (int i = 0; i < NB_SKILLS; i++, n++) {
        my_tree->skills[i] = create_skill(position, SKILL_RECT[i], texture);
        position.x += 90;
        if (n == 3) {
            n = -1;
            position.x = 60;
            position.y += 100;
        }
    }
    my_tree->skill_point = 0;
    load_from_save(my_tree);
    return (my_tree);
}