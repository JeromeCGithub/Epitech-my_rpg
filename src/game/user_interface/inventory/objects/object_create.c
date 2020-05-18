/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** object_add.c
*/

#include "object.h"
#include "lib/mystring.h"

object_t *object_create(sfTexture const *ui_texture, sfIntRect rect,
    char const *name_desc[2], int id)
{
    object_t *new = malloc(sizeof(object_t));
    sfVector2f origin = {rect.width / 2, rect.height / 2};

    if (!new)
        return (NULL);
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, ui_texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, rect);
    sfSprite_setOrigin(new->sprite, origin);
    new->name = my_strdup(name_desc[0]);
    new->description = my_strdup(name_desc[1]);
    new->func_id = id;
    new->list_id = 0;
    new->stat = malloc(sizeof(float) * 6);
    for (int i = 0; new->stat && i < 5; i++)
        new->stat[i] = 0;
    return (new);
}