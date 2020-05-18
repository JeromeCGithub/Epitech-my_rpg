/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** player_attack_redirect
*/

#include "views.h"

static void healthbar_update(mob_t *mob)
{
    sfIntRect rect = {0, 0, 20, 2};

    if (mob->health < 1)
        return;
    rect.width = rect.width * mob->health / mob->health_max;
    sfSprite_setTextureRect(mob->healthbar[0], rect);
}

static void play_sound_dead_mob(game_exts_t *exts, mob_t *retrieved)
{
    int sound_type = 0;
    particle_buf_t buf = PARTICLE_BLOOD;

    if (retrieved->type == SQUELETON)
        sound_type = BONE_CRACK;
    if (retrieved->type == ZOMBIE)
        sound_type = MOB_SOUND;
    if (retrieved->type == SLIME)
        sound_type = MOB_SOUND;
    if (exts->sound[0] && exts->sound[sound_type]) {
        sfSound_play(exts->sound[sound_type]);
        buf.pos = (sfVector2f){retrieved->hitbox->rect->left,
        retrieved->hitbox->rect->top};
        particle_create(exts->particles, buf, 100);
    }
}

void player_attack_redirect(hitbox_t *retrieved, ge_view_t *view,
    user_interface_t *ui)
{
    game_exts_t *exts = view->exts;

    if (!exts)
        return;
    if (retrieved->type == MOB_COLLIDER) {
        play_sound_dead_mob(exts, (mob_t *)retrieved->data);
        ((mob_t *)retrieved->data)->health -= exts->player->stats.strength;
        healthbar_update(retrieved->data);
    }
    if (retrieved->type == ITEM_COLLIDER) {
        if (exts->sound[0] && exts->sound[FOUND_OBJECT])
            sfSound_play(exts->sound[FOUND_OBJECT]);
        player_get_item(exts, ui, retrieved->data);
        retrieved->rect = NULL;
    }
    if (retrieved->type == NPC_COLLIDER) {
        ((npc_t *)retrieved->data)->function(retrieved->data, view);
    }
}