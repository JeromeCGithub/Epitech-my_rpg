/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player_interface_create
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   Positions the interface correctly.
*/
void player_interface_setup(playeri_t *this)
{
    sfText_setColor(this->hovertext, sfWhite);
    sfText_setFont(this->hovertext, ge_resources(NULL, "fontface"));
    sfText_setCharacterSize(this->hovertext, 32);
    sfSprite_setTexture(this->status_s, ge_textures(0, "player-status-s"), 1);
    sfSprite_setTexture(this->status_e, ge_textures(0, "player-status-e"), 1);
    sfSprite_setPosition(this->status_e, (sfVector2f){PLAYERI_EOFFSET, 0});
}

/*
** @DESCRIPTION
**   Positions and sets the textures of the player interface's points.
*/
void player_interface_tile_setup(sfSprite *sprite, u_int i, u_int j)
{
    sfVector2f pos = {0, 0};

    pos.y += 13 + (i * (PLAYERI_THEIGHT + 5));
    pos.x += 255 + (j * PLAYERI_TWIDTH);
    sfSprite_setTexture(sprite, ge_textures(0, "player-pempty"), 1);
    sfSprite_setPosition(sprite, pos);
}

/*
** @DESCRIPTION
**   This function initialises the player's interface aka the display
**   of its life points, mana and hunger.
*/
playeri_t *player_interface_create(void)
{
    playeri_t *this = malloc(sizeof(*this));

    this->status_s = sfSprite_create();
    this->status_e = sfSprite_create();
    this->hovertext = sfText_create();
    this->hoverstring = NULL;
    this->hovering = false;
    player_interface_setup(this);
    this->tiles = malloc(sizeof(sfSprite *) * 3);
    for (unsigned int i = 0; i < 3; i++) {
        this->tiles[i] = malloc(sizeof(sfSprite *) * PLAYERI_TILES);
        for (unsigned int j = 0; j < PLAYERI_TILES; j++) {
            this->tiles[i][j] = sfSprite_create();
            player_interface_tile_setup(this->tiles[i][j], i, j);
        }
    }
    return this;
}
