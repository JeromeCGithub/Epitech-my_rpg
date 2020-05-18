/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** cutscene.h
*/

#ifndef CUTSCENE_H_
#define CUTSCENE_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my_rpg.h"

enum element {background, player, nb_elements};

static int TXT_TIME[4] = {0, 8, 9, 15};
static const char *TXT_CS[2] = {"Notre hero Tom, revenant tranquillou\n\
bilou de ses vacances s'est fait attaquer\nson territoire.",
"Il va falloir\nque Tom se defende..."};

typedef struct txt_s {
    sfText *text;
    int min;
    int max;
} txt_t;

typedef struct cutscene_s {
    sfClock *clock;
    sfClock *player_clock;
    sfSprite *elements[nb_elements];
    txt_t *txt[2];
} cutscene_t;

cutscene_t *cutscene_init(void);
void cutscene_moove(cutscene_t *cutscene);
void cutscene_draw(sfRenderWindow *window,
                cutscene_t *scene, ge_view_t *view);

#endif /* !CUTSCENE_H_ */