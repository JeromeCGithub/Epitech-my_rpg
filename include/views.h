/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** views header file.
*/

#ifndef MY_RPG_VIEWS_H_
#define MY_RPG_VIEWS_H_

/**/
/* Includes */
/**/

#include "my_rpg.h"
#include "weather.h"

/**/
/* Constants */
/**/

#define VIEW_PAUSE 2

/**/
/* Structures / Typedef / Enums declarations */
/**/

enum view_type_e {
    VIEW_GAME,
    VIEW_UI,
    NB_VIEWS
};

enum qtree_type_e {
    QTREE_DRAW,
    QTREE_COLL,
    NB_QTREES
};

typedef struct brush_s {
    int radius;
    tile_type_t type;
} brush_t;

typedef struct map_exts_s {
    brush_t brush;
    map_t map;
    sfView *views[NB_VIEWS];
    qtree_t *qtree;
} map_exts_t;

typedef struct game_exts_s {
    sfMusic *music;
    map_t map;
    player_t *player;
    particles_t *particles;
    sfView *views[NB_VIEWS];
    qtree_t *qtree[NB_QTREES];
    sfSound *sound[WALKING + 1];
    sfSoundBuffer *sound_buffer[WALKING + 1];
    NODE *mobs;
    weather_t weather;
} game_exts_t;

/**/
/* Function prototypes */
/**/

    /* menu view */
void initialise_menu_view(ge_view_t *view, rpg_t *game);
void run_menu_view(ge_view_t *view, rpg_t *game);
void exit_menu_view(ge_view_t *view, rpg_t *game);
void menu_handle_events(ge_view_t *view, rpg_t *game);
void initialise_menu_functions(void);

    /* map view */
void menu_play_game(ge_view_t *view, rpg_t *game);
void views_quit_game(ge_view_t *view, rpg_t *game);
void menu_settings(ge_view_t *view, rpg_t *game);
void menu_map(ge_view_t *view, rpg_t *game);
void map_view_save(ge_view_t *view, rpg_t *game);
void map_change_brush(ge_view_t *view, rpg_t *game, ge_widget_t *widget);
void map_reset_borders(ge_view_t *view, rpg_t *game);
void map_view_randomize(ge_view_t *view, rpg_t *game);
void entity_draw(ge_view_t *view);
map_exts_t *map_initialise_exts(ge_view_t *view, rpg_t *game);

    /* game view */
void initialise_game_view(ge_view_t *view, rpg_t *game);
void run_game_view(ge_view_t *view, rpg_t *game);
void exit_game_view(ge_view_t *view, rpg_t *game);
void initialise_game_functions(void);
void action_btm(ge_view_t *view, rpg_t *game);
void action_view_quests(ge_view_t *view, rpg_t *game);
void action_resume(ge_view_t *view, rpg_t *game);
void game_handle_events(ge_view_t *view, rpg_t *game);
void player_attack(ge_view_t *view, user_interface_t *ui);
void player_attack_redirect(hitbox_t *retrieved, ge_view_t *view,
    user_interface_t *ui);
void player_add_xp(game_exts_t *exts, float xp, skill_tree_t *my_tree);
void player_get_item(game_exts_t *exts, user_interface_t *ui, item_t *item);
game_exts_t *game_view_initialise_exts(ge_view_t *view, rpg_t *game);
void menu_bestiary(ge_view_t *view, rpg_t *game);

/* settings view */
void run_settings_view(ge_view_t *view, rpg_t *game);
void exit_settings_view(ge_view_t *view, rpg_t *game);
void initialise_settings_view(ge_view_t *view, rpg_t *game);
void initialise_settings_functions(void);

void settings_action_music(rpg_t *game, ge_view_t *view, bool status);
void settings_action_music_load(rpg_t *game, ge_widget_cbox_t *cbox);
void settings_action_sound(rpg_t *game, ge_view_t *view, bool status);
void settings_action_sound_load(rpg_t *game, ge_widget_cbox_t *cbox);
void create_sound_effects(game_exts_t *exts, bool sound);
void create_music(game_exts_t *exts, bool music);
void player_sounds(player_t *player, game_exts_t *exts);
void repopulate_mob_stack(game_exts_t *exts);

void initialise_map_view(ge_view_t *view, rpg_t *game);
void run_map_view(ge_view_t *view, rpg_t *game);
void exit_map_view(ge_view_t *view, rpg_t *game);
void initialise_map_functions(void);
void map_handle_events(ge_view_t *view, rpg_t *game);

void run_bestiary_view(ge_view_t *view, rpg_t *game);
void exit_bestiary_view(ge_view_t *view, rpg_t *game);
void initialise_bestiary_view(ge_view_t *view, rpg_t *game);
void initialise_bestiary_functions(void);
void bestiary_next(ge_view_t *view, rpg_t *game);

void initialise_end_view(ge_view_t *view, rpg_t *game);
void run_end_view(ge_view_t *view, rpg_t *game);
void exit_end_view(ge_view_t *view, rpg_t *game);
void initialise_end_functions(void);

void initialise_htp_view(ge_view_t *view, rpg_t *game);
void run_htp_view(ge_view_t *view, rpg_t *game);
void exit_htp_view(ge_view_t *view, rpg_t *game);
void menu_htp(ge_view_t *view, rpg_t *game);

void initialise_cinematic_view(ge_view_t *view, rpg_t *game);
void run_cinematic_view(ge_view_t *view, rpg_t *game);
void exit_cinematic_view(ge_view_t *view, rpg_t *game);
void initialise_cinematic_functions(void);

void initialise_over_view(ge_view_t *view, rpg_t *game);
void run_over_view(ge_view_t *view, rpg_t *game);
void exit_over_view(ge_view_t *view, rpg_t *game);
void initialise_over_functions(void);

#endif
