/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** File to init sound
*/

#include "sound.h"
#include "views.h"

void create_sound_effects(game_exts_t *exts, bool sound)
{
    for (int i = 0; SOUND_INIT[i].filepath; i++) {
        exts->sound[i] = NULL;
        exts->sound_buffer[i] = NULL;
    }
    if (!sound)
        return;
    for (int i = 0; SOUND_INIT[i].filepath; i++) {
        exts->sound_buffer[i] =
            sfSoundBuffer_createFromFile(SOUND_INIT[i].filepath);
        exts->sound[i] = sfSound_create();
        if (!exts->sound[i] || !exts->sound_buffer[i]) {
            my_error(err_write, 84);
            return;
        }
        sfSound_setBuffer(exts->sound[i], exts->sound_buffer[i]);
        sfSound_setVolume(exts->sound[i], SOUND_INIT[i].volume);
    }
}

void create_music(game_exts_t *exts, bool music)
{
    exts->music = NULL;
    if (!music)
        return;
    exts->music = sfMusic_createFromFile("res/sound/sweden.ogg");
    if (!exts->music)
        return;
    sfMusic_setVolume(exts->music, 50);
    sfMusic_play(exts->music);
    sfMusic_setLoop(exts->music, sfTrue);
}
