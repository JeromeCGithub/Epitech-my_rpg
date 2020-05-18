/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_textures
*/

#include "engine.h"

static void ge_textures_add(NODE **head, sfTexture *text, c_char *key)
{
    ge_str_texture_t *buf;

    buf = malloc(sizeof(*buf));
    if (!buf) {
        my_puts(2, "Abort: Failed malloc call at ge_textures_add.\n");
        my_error(err_write, 84);
        return;
    }
    buf->texture = text;
    buf->string = my_strdup(key);
    node_insert(head, buf);
}

static sfTexture *ge_textures_fetch(NODE *head, c_char *key)
{
    ge_str_texture_t *tmp;
    sfTexture *mock;

    for (; head; head = head->next) {
        tmp = head->data;
        if (my_strcmp(tmp->string, key) == 0)
            return tmp->texture;
    }
    if (my_strcmp(key, SFGE_MOCK_NAME) != 0) {
        mock = ge_textures(NULL, SFGE_MOCK_NAME);
        if (mock) {
            my_dprintf(2, "\033[0;33m-- Note: Missing texture '%s' ", key);
            my_puts(2, "was replaced by mock.\n\033[0m");
            return mock;
        } else {
            my_dprintf(2, "\033[0;33m-- Error: Texture '%s' is missing", key);
            my_puts(2, " and no mock could be found.\n\033[0m");
        }
    }
    return NULL;
}

static void ge_textures_destroy(NODE **head)
{
    ge_str_texture_t *tmp;
    NODE *to_free;

    for (NODE *curr = *head; curr; free(to_free)) {
        tmp = curr->data;
        to_free = curr;
        sfTexture_destroy(tmp->texture);
        free(tmp->string);
        free(tmp);
        curr = curr->next;
    }
    *head = NULL;
}

/*
** @DESCRIPTION
**   This function will either store a texture / key pair or fetch a texture
**   using a query.
**   Add a texture to the stack:
**      ge_textures(texture_to_add, key);
**   Retreive a texture which you've pushed on the stack:
**      ge_textures(NULL, key);
**   Free all the textures on the stack:
**      ge_textures(NULL, NULL);
*/
sfTexture *ge_textures(sfTexture *text, c_char *key)
{
    static NODE *head;

    if (!head)
        head = NULL;
    if (text && key)
        ge_textures_add(&head, text, key);
    else if (key)
        return ge_textures_fetch(head, key);
    else
        ge_textures_destroy(&head);
    return NULL;
}
