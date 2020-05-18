/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** index
*/

#include "my_rpg.h"

/*
** @DESCRIPTION
**   Called upon entering view, mainly to malloc / create objects.
**   Initilaises the settings view exts.
** @REFACTOR
**   Prevent hardcoding path values.
*/
void initialise_settings_view(ge_view_t *view, rpg_t *game)
{
    view->run = &run_settings_view;
    view->exit = &exit_settings_view;
    ge_xml_load_interface(&(view->widgets), "views/settings/interface.xml");
}

/*
** @DESCRIPTION
**   Called at each frame.
*/
void run_settings_view(ge_view_t *view, rpg_t *game)
{
    menu_handle_events(view, game);
}

/*
** @DESCRIPTION
**   Called upon exiting, mainly to free used variables.
*/
void exit_settings_view(ge_view_t *view, rpg_t *game)
{
    return;
}

/*
** @DESCRIPTION
**   Initialises the functions bound to the settings view.
*/
void initialise_settings_functions(void)
{
    ge_functions(settings_action_music_load, "settings-music-load");
    ge_functions((fptr)settings_action_music, "settings-music");
    ge_functions(settings_action_sound_load, "settings-sound-load");
    ge_functions((fptr)settings_action_sound, "settings-sound");
}