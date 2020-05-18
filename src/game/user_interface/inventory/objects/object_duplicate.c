/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** object_duplicate.c
*/

#include "object.h"
#include "lib/mystring.h"

object_t *object_duplicate(object_t *obj)
{
    sfTexture const *texture = sfSprite_getTexture(obj->sprite);
    sfIntRect rect = sfSprite_getTextureRect(obj->sprite);
    sfVector2f origin = {rect.width / 2, rect.height / 2};
    object_t *new_obj = malloc(sizeof(object_t));

    if (!new_obj)
        return (NULL);
    new_obj->name = my_strdup(obj->name);
    new_obj->description = my_strdup(obj->description);
    new_obj->func_id = obj->func_id;
    new_obj->stat = obj->stat;
    new_obj->type = obj->type;
    new_obj->list_id = obj->list_id;
    new_obj->sprite = sfSprite_create();
    sfSprite_setTexture(new_obj->sprite, texture, sfTrue);
    sfSprite_setTextureRect(new_obj->sprite, rect);
    sfSprite_setOrigin(new_obj->sprite, origin);
    return (new_obj);
}