/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** cutscene draw
*/

#include "cutescene.h"

void cutscene_draw(sfRenderWindow *window,
                cutscene_t *scene, ge_view_t *view)
{
    int time = 0;

    if (!window || !scene)
        return;
    time = sfTime_asSeconds(sfClock_getElapsedTime(scene->clock));
    for (int i = 0; i < 2; i++)
        if (scene->elements[i])
            sfRenderWindow_drawSprite(window, scene->elements[i], NULL);
    for (int i = 0; i < 2; i++)
        if (time < scene->txt[i]->max && time >= scene->txt[i]->min
            && scene->txt[i] && scene->txt[i]->text) {
            sfRenderWindow_drawText(window, scene->txt[i]->text, NULL);
        }
    if (time >= 15)
        ge_view_change(view, &initialise_menu_view);
}