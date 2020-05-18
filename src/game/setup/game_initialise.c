/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** initialise_game
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   Returns a malloc'ed sfRenderWindow.
** @TODO: Prevent hardcoding the window's height and width.
*/
sfRenderWindow *game_initialise_window(u_int limit)
{
    sfRenderWindow *this;
    sfVideoMode mode;

    mode.width = 1920;
    mode.height = 1080;
    mode.bitsPerPixel = 32;
    this = sfRenderWindow_create(mode,
        GAME_NAME,
        sfDefaultStyle,
        NULL);
    sfRenderWindow_setFramerateLimit(this, limit);
    return this;
}

/*
** @DESCRIPTION
**   Initialises a malloc'ed rpg_t structure using the command line
**   arguments.
** @TODO: Load FPS dynamically.
*/
static rpg_t *game_init_struct(int argc, c_char *argv[])
{
    rpg_t *this = malloc(sizeof(*this));

    if (!this) {
        my_dprintf(2, "Error: Failed malloc at init_game_struct.\n");
        return NULL;
    }
    this->map_filepath = "save/map.data";
    this->ui = NULL;
    this->on = true;
    this->max_fps = 60;
    this->sound = true;
    this->music = true;
    return this;
}

static void game_initialise_resources(void)
{
    sfFont *font = sfFont_createFromFile("res/fonts/pixellari.ttf");

    if (!font) {
        my_error(err_write, 84);
        return my_dprintf(2, "Error: Failed to load font.\n");
    }
    ge_resources(font, "fontface");
}

static void game_initialise_functions(void)
{
    initialise_menu_functions();
    initialise_map_functions();
    initialise_game_functions();
    initialise_settings_functions();
    initialise_bestiary_functions();
    initialise_end_functions();
}

rpg_t *game_initialise(int argc, c_char *argv[])
{
    rpg_t *this = game_init_struct(argc, argv);

    if (!this)
        return (NULL);
    game_initialise_functions();
    game_initialise_resources();
    game_initialise_fps(this);
    ge_textures_load("assets/textures.config");
    return this;
}
