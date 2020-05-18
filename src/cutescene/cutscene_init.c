/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** cutscene
*/

#include "cutescene.h"

static void init_elements(cutscene_t *scene)
{
    sfTexture *texture = sfTexture_createFromFile(
        "res/images/map_scene.png", NULL);
    sfTexture *text_player = sfTexture_createFromFile(
        "res/spritesheets/player.png", NULL);
    sfIntRect text_rect = {0, 0, 400, 300};
    sfIntRect player_rect = {0, 114, 57, 57};

    scene->clock = sfClock_create();
    scene->elements[0] = sfSprite_create();
    scene->elements[1] = sfSprite_create();
    sfSprite_setTexture(scene->elements[0], texture, sfTrue);
    sfSprite_setTexture(scene->elements[1], text_player, sfTrue);
    sfSprite_setTextureRect(scene->elements[1], player_rect);
    sfSprite_setPosition(scene->elements[1], (sfVector2f) {(1920 / 2) - 57,
    (1080 / 2) - 57});
    sfSprite_setScale(scene->elements[0], (sfVector2f) {10, 8});
    sfSprite_setScale(scene->elements[1], (sfVector2f) {3, 3});
}

static void set_txt(sfText *text, sfFont *font, int i)
{
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfText_setString(text, TXT_CS[i]);
    sfText_setOrigin(text,
    (sfVector2f) {my_strlen(TXT_CS[i]) * 10, 50});
    sfText_setPosition(text,
    (sfVector2f) {1920 / 2, 1080 / 2 - 200});
    sfText_setFillColor(text,
    (sfColor) {255, 255, 255, 255});
}

static void init_text(cutscene_t *scene)
{
    sfFont *font = sfFont_createFromFile("res/fonts/pixellari.ttf");
    sfVector2f size;
    int nb = 0;

    for (int i = 0; i < 2; i++, nb += 2) {
        scene->txt[i] = malloc(sizeof(txt_t));
        if (!scene->txt[i])
            return;
        scene->txt[i]->text = sfText_create();
        set_txt(scene->txt[i]->text, font, i);
        scene->txt[i]->min = TXT_TIME[nb];
        scene->txt[i]->max = TXT_TIME[nb + 1];
    }
}

cutscene_t *cutscene_init(void)
{
    cutscene_t *scene = malloc(sizeof(cutscene_t));

    if (!scene)
        return (NULL);
    init_elements(scene);
    init_text(scene);
    scene->player_clock = sfClock_create();
    return (scene);
}
