/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** object header
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdlib.h>
#include <SFML/Graphics.h>

typedef enum object_id_e {
    WOOD_SHIELD = 1,
    IRON_SHIELD,
    BATTLE_SHIELD,
    LEATHER_CHESTPLATE,
    IRON_CHESTPLATE,
    GOLD_CHESTPLATE,
    LEATHER_BOOTS,
    IRON_BOOTS,
    GOLD_BOOTS,
    LEATHER_HELMET,
    IRON_HELMET,
    GOLD_HELMET,
    WATER_MELON = 100,
    XPORB = 101
} object_id_t;

typedef struct object_s {
    sfSprite *sprite;
    char *name;
    char *description;
    char *type;
    sfText *stack_text;
    sfBool is_inv_item;
    sfBool is_equipable;
    float *stat;
    int stack_number;
    int func_id;
    int list_id;
} object_t;

typedef struct object_list_s {
    object_t *object;
    struct object_list_s *next;
    int id;
} object_list_t;

object_t *obj_find_by_id(object_list_t *list, int id);
object_list_t *object_load_list(sfTexture *ui_texture);
object_t *object_duplicate(object_t *obj);
object_t *object_create(
        sfTexture const *ui_texture, sfIntRect rect, char const *name_desc[2],
        int id);

enum stat_player {
    HEALTH_IMPACT,
    FOOD_IMPACT,
    MANA_IMPACT,
    STRENGTH_IMPACT,
    DEFENSE_IMPACT
};

#endif /* OBJECT_H_ */
