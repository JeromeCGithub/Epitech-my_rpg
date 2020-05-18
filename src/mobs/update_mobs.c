/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Update mob each frame
*/

#include "my_rpg.h"
#include "player.h"
#include <math.h>

bool is_in_query(hitbox_type_t to_find, NODE *query)
{
    hitbox_t *found = NULL;

    for (NODE *in_query = query; in_query; in_query = in_query->next) {
        found = in_query->data;
        if (found && found->type == to_find)
            return (true);
    }
    return (false);
}

static void follow_player(NODE *mobs, qtree_t *qt)
{
    mob_t *actual;
    hitbox_t *found;
    sfFloatRect rec = {0, 0, 0, 0};
    NODE *query = NULL;

    for (NODE *curr = mobs; curr; curr = curr->next) {
        actual = curr->data;
        rec = actual->rect;
        rec.width *= MOB_INIT[actual->type].range.x;
        rec.height *= MOB_INIT[actual->type].range.y;
        qtree_query(qt, &query, rec);
        actual->following_player = is_in_query(PLAYER_COLLIDER, query);
        if (!actual->following_player)
            sfSprite_setTextureRect(actual->sprite,
            SPRITE_REC_MOB[actual->type][IDLE_S]);
        node_free(&query, NULL);
    }
}

static void move_mob_to_player(mob_t *mob,
            sfVector2f p_pos, float mob_speed)
{
    sfVector2f vector = {p_pos.x - mob->rect.left,
    p_pos.y - mob->rect.top};
    float angle = atan2(vector.y, vector.x);
    sfVector2f to_add = {mob_speed * cosf(angle), mob_speed * sinf(angle)};

    mob->rect.left += to_add.x;
    mob->rect.top += to_add.y;
    if (to_add.x > 0 && to_add.x > to_add.y)
        sfSprite_setTextureRect(mob->sprite,
        SPRITE_REC_MOB[mob->type][RIGHT_S]);
    if (to_add.x < 0 && to_add.y > to_add.x)
        sfSprite_setTextureRect(mob->sprite,
        SPRITE_REC_MOB[mob->type][LEFT_S]);
    if (to_add.y > 0 && to_add.y > to_add.x)
        sfSprite_setTextureRect(mob->sprite,
        SPRITE_REC_MOB[mob->type][BOTTOM_S]);
    if (to_add.y < 0 && to_add.y > to_add.x)
        sfSprite_setTextureRect(mob->sprite,
        SPRITE_REC_MOB[mob->type][TOP_S]);
}

static void target_player(ge_view_t *view, rpg_t *game, game_exts_t *exts)
{
    NODE *curr = exts->mobs;
    mob_t *mob = NULL;

    while (curr) {
        mob = curr->data;
        if (mob && mob->health <= 0) {
            if (exts->player->quests[2] == questUnlocked)
                player_quest_complete(exts->player, 2);
            mob_delete(view, game, &mob);
            curr = exts->mobs;
            continue;
        }
        if (mob && mob->following_player)
            move_mob_to_player(mob, (sfVector2f){
                    exts->player->hitbox.left + exts->player->hitbox.width,
                    exts->player->hitbox.top + exts->player->hitbox.height
                },
                mob->speed / game->fps->nb
            );
        curr = curr->next;
    }
}

void update_mobs(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;

    if (!exts)
        return;
    follow_player(exts->mobs, exts->qtree[QTREE_COLL]);
    target_player(view, game, exts);
    mob_attack(exts->mobs, exts->qtree[QTREE_COLL], exts->player, exts->sound);
}
