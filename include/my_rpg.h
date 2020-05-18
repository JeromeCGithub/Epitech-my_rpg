/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Header File | my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

/**/
/* Includes */
/**/

#include "lib/myerror.h"
#include "lib/mystring.h"
#include "lib/mystdio.h"
#include "lib/mynode.h"
#include "lib/fps.h"
#include "lib/qtree.h"
#include "user_interface.h"
#include "engine/engine.h"
#include "user_interface.h"
#include "map.h"
#include "mob.h"
#include "sound.h"
#include "item.h"
#include "npc.h"

/**/
/* Constant Definitions */
/**/

static const char *GAME_NAME = "My RPG";
static const char *SAVE_DIR = "save/";

static const char *SAVE_PLAYER_STATS = "save/player.data";
static const char *SAVE_PLAYER_QUESTS = "save/quests.data";

/**/
/* Enum Definitions */
/**/

/**/
/* Structure Definitions */
/**/
/*
** @DESCRIPTION
**   bool on: Set to false when game must be exited.
*/

typedef struct rpg_s {
    user_interface_t *ui;
    sfRenderWindow *window;
    u_int max_fps;
    bool on;
    fps_t *fps;
    bool sound;
    bool music;
    char *map_filepath;
} rpg_t;

/**/
/* Function Prototypes */
/**/
    /* src/game */
void start_game(rpg_t *game);
void game_loop(rpg_t *game, ge_view_t *view);
void game_frame(rpg_t *game, ge_view_t *view);
    /* src/game/setup */
sfRenderWindow *game_initialise_window(u_int limit);
rpg_t *game_initialise(int argc, c_char *argv[]);
void game_initialise_fps(rpg_t *game);
void handle_collisions(ge_view_t *view, rpg_t *rpg);
void handle_events(ge_view_t *view, rpg_t *game);
void map_set_view(ge_view_t *view, rpg_t *game);
void map_draw(ge_view_t *view, qtree_t *qtree, sfView **views);
void mob_draw(ge_view_t *view, mob_t *mob);
void update_mobs(ge_view_t *view, rpg_t *game);
void mob_delete(ge_view_t *view, rpg_t *game, mob_t **mob);
void item_draw(ge_view_t *view, item_t *item);
void npc_draw(ge_view_t *view, npc_t *item);
void item_create(ge_view_t *view, rpg_t *game, object_id_t id, sfVector2f pos);
bool views_create(sfView *views[2], sfRenderWindow *window);
void views_destroy(sfView **views);
    /* src/map/ */
void update_weather(ge_view_t *view, rpg_t *game);
void check_end_game(ge_view_t *view, skill_tree_t *skill_tree);
/**/
/* Dependant Statements */
/**/

#define PLAYERI_OFFSET 255
#define PLAYERI_EOFFSET 515
#define PLAYERI_TWIDTH 26
#define PLAYERI_THEIGHT 54

#include "user_interface.h"
#include "player.h"
#include "particles.h"
#include "views.h"

#endif
