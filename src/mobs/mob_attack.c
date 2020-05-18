/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** function to attack player if near
*/

#include "my_rpg.h"
#include "mob.h"
#include "player.h"
#include "lib/qtree.h"

static void set_query(sfFloatRect *rec, mob_t *actual)
{
    rec->left = actual->rect.left;
    rec->top = actual->rect.top;
    rec->width = actual->rect.width;
    rec->height = actual->rect.height;
}

static void player_hit(player_t *p, mob_t *actual, sfSound **sound)
{
    p->stats.health[psValue] -= actual->damage;
    player_health(p, actual->damage * -1);
    sfClock_restart(p->hit_clock);
    if (sound[0] && sound[PLAYER_HURT]) {
        sfSound_play(sound[PLAYER_HURT]);
    }
}

void mob_attack(NODE *mobs, qtree_t *qt, player_t *p, sfSound **sound)
{
    mob_t *actual = NULL;
    sfFloatRect query_rec = {0, 0, 0, 0};
    NODE *query = NULL;
    bool found = false;
    sfTime tm = sfClock_getElapsedTime(p->hit_clock);

    for (NODE *curr = mobs; curr; curr = curr->next) {
        actual = curr->data;
        set_query(&query_rec, actual);
        qtree_query(qt, &query, query_rec);
        found = is_in_query(PLAYER_COLLIDER, query);
        if (found && sfTime_asMilliseconds(tm) > 500)
            player_hit(p, actual, sound);
        node_free(&query, NULL);
        found = false;
    }
}
