/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_bar_event.c
*/

#include "my_rpg.h"

static void speed_up(void *view_exts)
{
    game_exts_t *view = view_exts;

    if (view->player->quests[5] == questUnlocked)
        player_quest_complete(view->player, 5);
    view->player->stats.speed = 400;
    view->player->stats.speed_bonus = 250;
    if (view->sound[0] && view->sound[BIPBIP])
        sfSound_play(view->sound[BIPBIP]);
}

static void enable_frost(void *view_exts)
{
    game_exts_t *view = view_exts;

    if (view->player->quests[5] == questUnlocked)
        player_quest_complete(view->player, 5);
    view->player->stats.frost = true;
}

void skill_bar_event(rpg_t *game, ge_view_t *view, int keycode)
{
    if (keycode == sfKeyNum1 && !game->ui->skill_bar->slot[0]->in_cd
        && !game->ui->skill_tree->skills[3]->locked) {
        game->ui->skill_bar->slot[0]->step = 1;
        game->ui->skill_bar->slot[0]->in_cd = true;
        sfClock_restart(game->ui->skill_bar->slot[0]->cd_clock);
    } else if (keycode == sfKeyNum2 && !game->ui->skill_bar->slot[1]->in_cd
        && !game->ui->skill_tree->skills[7]->locked) {
        enable_frost(view->exts);
        game->ui->skill_bar->slot[1]->step = 1;
        game->ui->skill_bar->slot[1]->in_cd = true;
        sfClock_restart(game->ui->skill_bar->slot[1]->cd_clock);
    }
    if (keycode == sfKeyNum3 && !game->ui->skill_bar->slot[2]->in_cd
        && !game->ui->skill_tree->skills[11]->locked) {
        game->ui->skill_bar->slot[2]->step = 1;
        game->ui->skill_bar->slot[2]->in_cd = true;
        sfClock_restart(game->ui->skill_bar->slot[2]->cd_clock);
        speed_up(view->exts);
    }
}