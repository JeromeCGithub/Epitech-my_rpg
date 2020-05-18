/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** npc_create
*/

#include "views.h"
#include "npc.h"

static void npc_create_text(npc_t *n, sfVector2f pos)
{
    sfFloatRect rect;

    n->text = sfText_create();
    sfText_setFont(n->text, ge_resources(NULL, "fontface"));
    sfText_setString(n->text,  NPC_MESSAGES[rand() % NB_OF_MESSAGES]);
    sfText_setPosition(n->text, (sfVector2f){pos.x, pos.y - PLAYER_SIZE.y * 2});
    sfText_setCharacterSize(n->text, 20);
    rect = sfText_getGlobalBounds(n->text);
    sfText_setOrigin(n->text, (sfVector2f){rect.width / 2, rect.height / 2});
}

static void npc_set_function(npc_t *n)
{
    static bool is_quest = false;

    if (!is_quest) {
        is_quest = true;
        n->function = &npc_show_quest;
    } else {
        n->function = NPC_FUNC_LIST[rand() % NB_OF_FUNC];
    }
}

void npc_create(qtree_t *qt, sfVector2f pos)
{
    npc_t *n = malloc(sizeof(npc_t));

    if (!n)
        return;
    n->rect = (sfFloatRect){pos.x, pos.y, PLAYER_SIZE.x, PLAYER_SIZE.y};
    n->collisions = (sfVector2i){0, 0};
    n->sprite = sfSprite_create();
    sfSprite_setTexture(n->sprite,
        ge_textures(NULL, "player-spritesheet"), sfTrue);
    sfSprite_setTextureRect(n->sprite, SPRITE_REC_PLAYER[IDLE_S]);
    sfSprite_setOrigin(n->sprite, (sfVector2f){PLAYER_SIZE.x, PLAYER_SIZE.y});
    npc_create_text(n, pos);
    n->hitbox = hitbox_create(&n->rect, &n->collisions, n, NPC_COLLIDER);
    npc_set_function(n);
    qtree_push(qt, n->hitbox);
}