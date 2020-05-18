/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_rc_menu_setup.c
*/

#include "inventory.h"
#include "lib/mystdio.h"
#include "lib/mystring.h"

static sfText *rc_menu_create_text(sfVector2f position, int i)
{
    sfText *txt = sfText_create();
    char *str = i ? my_strdup("Jeter") : my_strdup("Utiliser");
    sfFont *font = sfFont_createFromFile("res/fonts/pixellari.ttf");

    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, 25);
    sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
    sfText_setString(txt, str);
    sfText_setOrigin(
            txt,
            (sfVector2f) {my_strlen(str) * 10 / 2, my_strlen(str) * 5 / 2});
    sfText_setPosition(txt, position);
    return (txt);
}

rc_menu_t *inventory_rc_menu_setup(case_t *slot)
{
    sfVector2f position = sfSprite_getPosition(slot->sprite);
    rc_menu_t *new = malloc(sizeof(rc_menu_t));

    if (!new)
        return (NULL);
    position.x -= 50;
    for (int i = 0; i < 2; i++) {
        new->button[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(new->button[i], (sfVector2f) {100, 50});
        sfRectangleShape_setFillColor(
                new->button[i], (sfColor)
                        {50, 50, 50, 255});
        sfRectangleShape_setPosition(new->button[i], position);
        sfRectangleShape_setOrigin(new->button[i], (sfVector2f) {50, 25});
        new->text[i] = rc_menu_create_text(position, i);
        position.y += 55;
    }
    return (new);
}