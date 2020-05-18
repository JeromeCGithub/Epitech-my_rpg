/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** index
*/

#include "my_rpg.h"
#include "ui_event.h"

/*
** @DESCRIPTION
**   Called upon entering view, mainly to malloc / create objects.
**   Initilaises the game view exts.
** @REFACTOR: Prevent hardcoding path values.
*/
void initialise_game_view(ge_view_t *view, rpg_t *game)
{
    int x = rand() % MAP_SIZE.x * TILE_SIZE.x;
    int y = rand() % MAP_SIZE.y * TILE_SIZE.y;

    view->run = &run_game_view;
    view->exit = &exit_game_view;
    view->exts = game_view_initialise_exts(view, game);
    ge_xml_load_interface(&(view->widgets), "views/game/interface.xml");
    game->ui = ui_setup(game, view);
    for (int i = 0; i < 70; i++) {
        x = rand() % MAP_SIZE.x * TILE_SIZE.x;
        y = rand() % MAP_SIZE.y * TILE_SIZE.y;
        item_create(view, game, rand() % 12,
        (sfVector2f) {(float) x, (float) y});
    }
}

static void run_game_view2(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;

    particle_engine_render(exts->particles);
    entity_draw(view);
    sfRenderWindow_setView(view->window, exts->views[VIEW_UI]);
    update_mobs(view, game);
    player_update(view, game);
    inventory_mouse_hover(view->window, game->ui->inventory);
    skill_bar_hover(game->ui->skill_bar, view->window, view->exts);
    ui_draw(view->window, view, game->ui);
    update_weather(view, game);
    check_end_game(view, game->ui->skill_tree);
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_game_view(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;

    game_handle_events(view, game);
    if (!exts || view->state & 10)
        return;
    repopulate_mob_stack(exts);
    handle_collisions(view, game);
    map_draw(view, exts->qtree[QTREE_DRAW], exts->views);
    map_set_view(view, game);
    player_sprite_update(exts->player);
    sfRenderWindow_drawSprite(view->window, exts->player->sprite, NULL);
    sfRenderWindow_drawSprite(view->window, exts->player->sword, NULL);
    if (view->state & 1 << 12)
        qtree_draw(view->window, exts->qtree[QTREE_COLL]);
    run_game_view2(view, game);
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_game_view(ge_view_t *view, rpg_t *game)
{
    game_exts_t *exts = view->exts;

    if (!exts)
        return;
    player_save(exts->player);
    ui_save(game->ui);
    for (int i = 0; game->sound && SOUND_INIT[i].filepath; i++) {
        sfSound_destroy(exts->sound[i]);
        sfSoundBuffer_destroy(exts->sound_buffer[i]);
    }
    if (game->music)
        sfMusic_destroy(exts->music);
    views_destroy(exts->views);
    map_destroy(&exts->map);
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the game view.
*/
void initialise_game_functions(void)
{
    ge_functions((fptr)action_btm, "back-to-menu");
    ge_functions((fptr)action_resume, "resume");
    ge_functions((fptr)action_view_quests, "view-quests");
}
