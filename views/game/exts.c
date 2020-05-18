/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** exts
*/

#include "my_rpg.h"

static void qtree_fill_tile(qtree_t *qtree[NB_QTREES], map_t *map,
    size_t i, size_t j)
{
    hitbox_t *hitbox = hitbox_create(
        &map->tiles[i][j].bounds,
        &map->tiles[i][j].collisions,
        map->tiles[i][j].shape,
        WALL);

    qtree_push(qtree[QTREE_DRAW], hitbox);
    if (map->tiles[i][j].type == BRICK_1
        || map->tiles[i][j].type == BRICK_2)
        qtree_push(qtree[QTREE_COLL], hitbox);
    if (map->tiles[i][j].type == HOUSE) {
        qtree_push(qtree[QTREE_COLL], hitbox);
        npc_create(qtree[QTREE_COLL],
        (sfVector2f){hitbox->rect->left - 10, hitbox->rect->top + 20});
    }
}

static void qtree_fill(qtree_t *qtree[NB_QTREES], map_t *map, player_t *player)
{
    hitbox_t *hitbox = hitbox_create(&player->hitbox,
    &player->collisions, player, PLAYER_COLLIDER);

    player->hitrange = hitbox;
    qtree_push(qtree[QTREE_COLL], hitbox);
    for (size_t i = 0; i < map->size.y; i++)
        for (size_t j = 0; j < map->size.x; j++) {
            qtree_fill_tile(qtree, map, i, j);
        }
}

static bool qtrees_create(qtree_t *qtrees[NB_QTREES], sfVector2u size)
{
    sfFloatRect bounds = {
        size.x * TILE_SIZE.x / 2,
        size.y * TILE_SIZE.y / 2,
        size.x * TILE_SIZE.x / 2,
        size.y * TILE_SIZE.y / 2
    };

    qtrees[QTREE_DRAW] = qtree_create(bounds);
    qtrees[QTREE_COLL] = qtree_create(bounds);
    if (!qtrees[QTREE_DRAW] || !qtrees[QTREE_COLL])
        return (true);
    return (false);
}

game_exts_t *game_view_initialise_exts(ge_view_t *view, rpg_t *game)
{
    game_exts_t *this = malloc(sizeof(game_exts_t));

    if (!this)
        return (NULL);
    if (map_init(MAP_PATH, &this->map) && map_generate(&this->map))
        return (NULL);
    map_save(&this->map, MAP_PATH);
    this->player = player_create();
    if (qtrees_create(this->qtree, this->map.size)
        || views_create(this->views, view->window))
        return (NULL);
    this->mobs = NULL;
    this->particles = particle_engine_create(view);
    create_sound_effects(this, game->sound);
    create_music(this, game->music);
    qtree_fill(this->qtree, &this->map, this->player);
    this->weather.inevent = false;
    repopulate_mob_stack(this);
    return (this);
}
