/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** mob_delete
*/

#include "my_rpg.h"

void mob_delete(ge_view_t *view, rpg_t *game, mob_t **mob)
{
    game_exts_t *exts = view->exts;
    sfVector2f pos = {
        (*mob)->hitbox->rect->left,
        (*mob)->hitbox->rect->top
    };

    for (size_t i = 0; i < (*mob)->drop.nb; i++) {
        item_create(view, game, (*mob)->drop.id,
        (sfVector2f){pos.x + rand_range(-100, 100),
        pos.y + rand_range(-100, 100)});
    }
    (*mob)->hitbox->rect = NULL;
    node_remove(&exts->mobs, *mob);
    *mob = NULL;
}
