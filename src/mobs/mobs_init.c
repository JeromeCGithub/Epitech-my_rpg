/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** init mob stack into a linked list
*/

#include "mob.h"
#include "views.h"
#include <string.h>

static sfFloatRect get_random_position(player_t *p, sfVector2u m_size, int type)
{
    sfVector2f pp = sfSprite_getPosition(p->sprite);
    sfFloatRect not_in = {pp.x, pp.y, PLAYER_SIZE.x, PLAYER_SIZE.y};
    sfFloatRect new_pos = {0, 0, MOB_INIT[type].box.x, MOB_INIT[type].box.y};

    new_pos.left = rand() % ((m_size.x * TILE_SIZE.x) ?
        m_size.x * TILE_SIZE.x : 1);
    new_pos.top = rand() % ((m_size.y * TILE_SIZE.y) ?
        m_size.y * TILE_SIZE.y : 1);
    return (rect_intersect(new_pos, not_in) ?
    get_random_position(p, m_size, type) : new_pos);
}

static void sprite_init_mob(sfSprite *sprite, sfFloatRect rec,
    mob_type_t type, int *damage)
{
    sfIntRect idle_rec = {0, MOB_INIT[type].idle_start_y,
    MOB_INIT[type].sprite_vec.x, MOB_INIT[type].sprite_vec.y};

    *damage = MOB_INIT[type].damage;
    sfSprite_setTexture(sprite, ge_textures(NULL, MOB_INIT[type].name), sfTrue);
    sfSprite_setTextureRect(sprite, idle_rec);
    sfSprite_setPosition(sprite, (sfVector2f){rec.left, rec.top});
    sfSprite_setOrigin(sprite, (sfVector2f){MOB_INIT[type].sprite_vec.x / 2,
    MOB_INIT[type].sprite_vec.y / 2});
}

static void setup_healthbar(sfSprite *hb[2], sfFloatRect mob_pos)
{
    sfVector2f scale = {5, 5};
    sfVector2f origin = {0, 0};
    sfVector2u origin_u = sfTexture_getSize(ge_textures(NULL, "hbar"));

    origin.x = (origin_u.x / 2) ? origin_u.x / 2 : 1;
    origin.y = (origin_u.x / 2) ? origin_u.x / 2 : 1;
    for (int i = 0; i != 2; i++) {
        hb[i] = NULL;
        hb[i] = sfSprite_create();
        sfSprite_setScale(hb[i], scale);
        sfSprite_setOrigin(hb[i], origin);
    }
    sfSprite_setTexture(hb[0], ge_textures(NULL, "hbar"), sfTrue);
    sfSprite_setTexture(hb[1], ge_textures(NULL, "hbar-red"), sfTrue);
    sfSprite_setPosition(hb[0], (sfVector2f){mob_pos.left, mob_pos.top});
    sfSprite_setPosition(hb[1], (sfVector2f){mob_pos.left, mob_pos.top});
}

static mob_t *init_new_mob(mob_type_t type, player_t *p, map_t m)
{
    sfFloatRect rec = get_random_position(p, m.size, type);
    mob_t *n = malloc(sizeof(mob_t));

    if (!n)
        return (NULL);
    memset(n, 0, sizeof(mob_t));
    n->following_player = false;
    n->collide = (sfVector2i){0, 0};
    n->rect = rec;
    n->health = MOB_INIT[type].health;
    n->moving = IDLE;
    n->sprite = sfSprite_create();
    setup_healthbar(n->healthbar, rec);
    n->speed = MOB_INIT[type].speed;
    sprite_init_mob(n->sprite, rec, type, &n->damage);
    n->drop = MOB_INIT[type].drop;
    n->type = type;
    n->health_max = MOB_INIT[type].health_max;
    n->hitbox = hitbox_create(&n->rect, &n->collide, n, MOB_COLLIDER);
    return (n);
}

void repopulate_mob_stack(game_exts_t *exts)
{
    int len = 0;
    mob_t *new = NULL;

    if (!exts || exts->map.size.x < 10 || exts->map.size.y < 10)
        return;
    len = node_size(exts->mobs);
    while (len < MAX_STACK_MOB) {
        new = init_new_mob(rand() % NB_OF_MOBS, exts->player, exts->map);
        if (!new)
            return;
        qtree_push(exts->qtree[QTREE_COLL], new->hitbox);
        node_append(&exts->mobs, new);
        len++;
    }
}
