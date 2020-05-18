/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_interface_update
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   Updates one of the player interface's bars depending on the provided
**   fraction.
*/
void player_interface_update_bar(sfSprite **row, float value[],
_cstring textstring)
{
    sfTexture *texture_on = ge_textures(NULL, textstring);
    sfTexture *texture_off = ge_textures(NULL, "player-pempty");
    unsigned int res = (value[psValue] / value[psMax]) * 10;

    for (unsigned int i = 0; i < 10; i++) {
        if (i + 1 > res) {
            sfSprite_setTexture(row[i], texture_off, 1);
        } else {
            sfSprite_setTexture(row[i], texture_on, 1);
        }
    }
}

void player_interface_set_tooltip(player_t *p)
{
    playeri_t *this = p->interface;

    if (this->hoverstring)
        free(this->hoverstring);
    this->hoverstring = my_sprintf(
        "Health: %d/%d\n"
        "Mana: %d/%d\n"
        "Food: %d/%d\n"
        "Defense: %d\n"
        "Strength: %d\n"
        "Experience: %d\n"
        "Level: %d\n",
        (int)p->stats.health[psValue], (int)p->stats.health[psMax],
        (int)p->stats.mana[psValue], (int)p->stats.mana[psMax],
        (int)p->stats.food[psValue], (int)p->stats.food[psMax],
        (int)p->stats.defense, (int)p->stats.strength,
        (int)p->stats.xp, (int)p->stats.level);
    sfText_setString(this->hovertext, this->hoverstring);
}

void player_interface_tooltip(player_t *p, sfRenderWindow *window)
{
    playeri_t *this = p->interface;
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (ge_hovers(this->status_s, window)) {
        if (this->hovering == false) {
            player_interface_set_tooltip(p);
        }
        this->hovering = true;
        sfText_setPosition(this->hovertext,
            (sfVector2f){pos.x + 20, pos.y + 20});
        sfRenderWindow_drawText(window, this->hovertext, 0);
    } else {
        this->hovering = false;
    }
}

/*
** @DESCRIPTION
**   Renders the interface and each tile.
*/
void player_interface_update(ge_view_t *rst view, rpg_t *rst game)
{
    game_exts_t *exts = view->exts;
    playeri_t *this = exts->player->interface;

    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < PLAYERI_TILES; j++) {
            sfRenderWindow_drawSprite(view->window, this->tiles[i][j], 0);
        }
    }
    player_interface_tooltip(exts->player, view->window);
}
