/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_resources_load_from_file
*/

#include "engine.h"

void ge_resources_handle_rect
(sfIntRect *rect, char const *fstring, u_int *i)
{
    char *tmp;

    (*i)++;
    tmp = ge_pget(fstring, i, ":");
    (*i)++;
    rect->left = my_atoi(tmp);
    free(tmp);
    tmp = ge_pget(fstring, i, ":");
    (*i)++;
    rect->top = my_atoi(tmp);
    free(tmp);
    tmp = ge_pget(fstring, i, ":");
    (*i)++;
    rect->width = my_atoi(tmp);
    free(tmp);
    tmp = ge_pget(fstring, i, "\n");
    rect->height = my_atoi(tmp);
    free(tmp);
}

/*
** @DESCRIPTION
**   Handles a single texture.
*/
void ge_resources_handle_texture
(ge_resloader_buf_t *buf, char const *fstring, u_int *i)
{
    buf->key = ge_pget(fstring, i, ":");
    (*i)++;
    buf->path = ge_pget(fstring, i, ":\n");
    buf->has_rect = false;
    if (fstring[*i] == ':') {
        buf->has_rect = true;
        ge_resources_handle_rect(&(buf->rect), fstring, i);
    }
}

void ge_resources_load_from_file_sequel(char const *fstring)
{
    ge_resloader_buf_t buf;
    sfTexture *texture = NULL;
    sfIntRect *rectptr = NULL;

    for (u_int i = 0; fstring[i]; i++) {
        if (!ge_pnot(fstring[i], "\n \t#")) {
            ge_pskip_till(fstring, &i, "\n");
            continue;
        }
        ge_resources_handle_texture(&buf, fstring, &i);
        rectptr = (buf.has_rect) ? &(buf.rect): NULL;
        texture = sfTexture_createFromFile(buf.path, rectptr);
        if (!texture) {
            my_puts(2, "\033[0;33m-- Error: Couldn't load texture\n\033[0m");
            return (void)my_error(err_write, 84);
        }
        ge_resources(texture, buf.key);
        free(buf.key);
        free(buf.path);
    }
}

/*
** @DESCRIPTION
**   Adds textures to the resource stack through a .config file.
** @TODO: Possible segfault around line 28 with i++. (Check if != '\0')
*/
void ge_resources_load_from_file(char const *filepath)
{
    char *fstring = ge_read_file(filepath);

    if (SFGELOG)
        my_dprintf(1, "\033[40;32mLoading resources '%s'\033[0m\n", filepath);
    if (!fstring) {
        my_puts(2, "\033[0;33m-- Error: Couldn't open file\n\033[0m");
        my_error(err_write, 84);
        return;
    }
    ge_resources_load_from_file_sequel(fstring);
    if (SFGELOG && !my_error(err_read, 0))
        my_puts(1, "\033[0;32m-- Done\033[0m\n");
    free(fstring);
}
