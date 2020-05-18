/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** object_load_list.c
*/

#include <stdio.h>
#include <lib/mystdio.h>

#include "object.h"
#include "lib/mystring.h"

static char *get_the_line(FILE *fd)
{
    char *new = NULL;
    size_t n = 0;

    getline(&new, &n, fd);
    return (new);
}

static object_t *fill_object(FILE *fd, sfTexture *ui_texture)
{
    size_t n = 0;
    sfIntRect rect;
    char *name = get_the_line(fd);
    char *desc = get_the_line(fd);
    char *rectc = get_the_line(fd);
    char *id = NULL;
    char *name_desc[2];

    rect.left = my_atoi(rectc);
    for (; rectc && rectc[0] != ':'; rectc++);
    rect.top = my_atoi(rectc);
    for (rectc = rectc + 1; rectc && rectc[0] != ':'; rectc++);
    rect.width = my_atoi(rectc);
    for (rectc = rectc + 1; rectc && rectc[0] != ':'; rectc++);
    rect.height = my_atoi(rectc);
    getline(&id, &n, fd);
    name_desc[0] = name;
    name_desc[1] = desc;
    return (object_create(ui_texture, rect,
        (char const **)name_desc, my_atoi(id)));
}

static void fill_stat(FILE *fd, object_t **obj, int id)
{
    char *buff = NULL;
    size_t n = 0;
    int nb = 0;

    (*obj)->stat = malloc(sizeof(float) * 6);
    (*obj)->list_id = id;
    if (!(*obj)->stat)
        return;
    for (int i = 0; i < 5; i++) {
        nb = getline(&buff, &n, fd);
        buff[nb] = '\0';
        (*obj)->stat[i] = my_atoi(buff);
    }
    nb = getline(&buff, &n, fd);
    buff[nb] = '\0';
    (*obj)->is_equipable = my_atoi(buff);
    nb = getline(&buff, &n, fd);
    buff[nb] = '\0';
    (*obj)->type = my_strndup(buff, my_strlen(buff) - 1);
}

static void object_list_add(FILE *fd, object_list_t **list,
    sfTexture *ui_texture)
{
    char *buffer = NULL;
    size_t n = 0;
    object_list_t *new = malloc(sizeof(object_list_t));

    if (!new)
        return;
    getline(&buffer, &n, fd);
    new->id = my_atoi(buffer);
    new->object = fill_object(fd, ui_texture);
    fill_stat(fd, &new->object, new->id);
    if (!(*list)) {
        new->next = NULL;
        *list = new;
        return;
    }
    new->next = *list;
    *list = new;
}

object_list_t *object_load_list(sfTexture *ui_texture)
{
    FILE *fd = fopen("assets/object.config", "rw");
    object_list_t *my_list = NULL;
    char *buffer = NULL;
    size_t nb = 0;

    while (getline(&buffer, &nb, fd) > 0) {
        if (buffer && buffer[0] == '{')
            object_list_add(fd, &my_list, ui_texture);
    }
    fclose(fd);
    return (my_list);
}