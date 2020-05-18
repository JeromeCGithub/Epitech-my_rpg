/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_bar_init.c
*/

#include "user_interface.h"

static void set_texture_skills(sfTexture *ui_texture, skill_t *new, int index)
{
    sfSprite_setTexture(new->skill_sprite, ui_texture, sfTrue);
    sfSprite_setTexture(new->case_sprite, ui_texture, sfTrue);
    sfSprite_setTextureRect(new->case_sprite, CASE_SKILLS_RECTS[index]);
    sfSprite_setOrigin(
            new->case_sprite,
            (sfVector2f) {CASE_SKILLS_RECTS[index].width / 2,
                    CASE_SKILLS_RECTS[index].height / 2});
    sfSprite_setTextureRect(new->skill_sprite, SKILLS_RECTS[index]);
    sfSprite_setOrigin(
            new->skill_sprite, (sfVector2f) {SKILLS_RECTS[index].width / 2,
                    SKILLS_RECTS[index].height / 2});
}

static void init_cd_sprite(skill_t *new, sfVector2f origin)
{
    sfTexture *texture = sfTexture_createFromFile(
            "res/spritesheets/cd_spritesheet.png", NULL);

    new->cd_sprite = sfSprite_create();
    sfSprite_setTexture(new->cd_sprite, texture, sfTrue);
    sfSprite_setTextureRect(new->cd_sprite, CD_INIT_RECT);
    sfSprite_setOrigin(
            new->cd_sprite,
            (sfVector2f) {CD_INIT_RECT.width / 2, CD_INIT_RECT.height / 2});
    sfSprite_setPosition(new->cd_sprite, origin);
    sfSprite_setScale(new->cd_sprite, (sfVector2f) {0.5, 0.5});
    new->step = MAX_CD_STEP;
    new->cd_clock = sfClock_create();
}

static skill_t *create_skill_bar_slot(sfTexture *ui_texture)
{
    skill_t *new = malloc(sizeof(skill_t));
    static int index = 0;

    if (!new)
        return (NULL);
    new->case_sprite = sfSprite_create();
    new->skill_sprite = sfSprite_create();
    set_texture_skills(ui_texture, new, index);
    sfSprite_setPosition(new->case_sprite, CASE_SKILLS_POSITION[index]);
    sfSprite_setPosition(new->skill_sprite, SKILLS_POSITION[index]);
    sfSprite_setScale(new->skill_sprite, (sfVector2f) {3, 3});
    init_cd_sprite(new, SKILLS_POSITION[index]);
    new->cd = 5000;
    new->in_cd = false;
    index++;
    if (index == 3)
        index = 0;
    return (new);
}

skill_bar_t *skill_bar_init(sfTexture *ui_texture)
{
    skill_bar_t *new = malloc(sizeof(skill_bar_t));

    if (!new)
        return (NULL);
    for (int i = 0; i < 3; i++)
        new->slot[i] = create_skill_bar_slot(ui_texture);
    return (new);
}