/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_tree_event.c
*/

#include "my_rpg.h"

static int is_unlockable(skill_tree_t *tree, int index, player_t *player)
{
    if (index == 0 && tree->skill_point > 0) {
        if (FUNC_SKILL_TREE[0])
            FUNC_SKILL_TREE[0](player);
        tree->skill_point -= 1;
        return (1);
    }
    if (index == 0)
        return (0);
    if (tree->skills[index]->locked && (!tree->skills[index - 1]->locked ||
            (index > 3 && !tree->skills[index - 4]->locked) ||
            (index < 8 && !tree->skills[index + 4]->locked)) &&
            tree->skill_point > 0) {
        if (FUNC_SKILL_TREE[index])
            FUNC_SKILL_TREE[index](player);
        tree->skill_point -= 1;
        return (1);
    }
    return (0);
}

static void check_event(sfVector2i mouse, int index,
        skill_tree_t *tree, player_t *player)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
            tree->skills[index]->case_sprite);

    if (sfFloatRect_contains(&bounds, (float) mouse.x, (float) mouse.y)
            && is_unlockable(tree, index, player)) {
        sfSprite_setTextureRect(
                tree->skills[index]->case_sprite, CASE_SKILL_ENABLE_RECT);
        tree->skills[index]->locked = false;
    }
}

void check_end_game(ge_view_t *view, skill_tree_t *skill_tree)
{
    int nb = 0;
    game_exts_t *exts = view->exts;

    for (int i = 0; i < 12; i++) {
        if (skill_tree->skills[i]->locked)
            nb = 1;
    }
    if (nb == 0 && exts->player->quests[6] == questUnlocked) {
        player_quest_complete(exts->player, 6);
        ge_view_change(view, &initialise_end_view);
    }
}

void skill_tree_event(ge_view_t *view, rpg_t *game, sfVector2i mouse)
{
    game_exts_t *exts = view->exts;

    if (!game->ui->skill_tree || !exts || !exts->player)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        for (int i = 0; i < NB_SKILLS; i++)
            check_event(mouse, i, game->ui->skill_tree, exts->player);
    }
    check_end_game(view, game->ui->skill_tree);
}