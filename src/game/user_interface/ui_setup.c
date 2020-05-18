/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** setup ui
*/

#include "my_rpg.h"
#include "event_inventory.h"

static sfTexture *load_ui_texture(void)
{
    return (sfTexture_createFromFile(UI_TEXTURE_FILEPATH, NULL));
}

static void set_good_place_inv(object_t *stuff, int nb)
{
    sfSprite_setPosition(stuff->sprite, STUFF_POSITION[nb]);
    sfSprite_setScale(stuff->sprite, (sfVector2f) {2.5, 2.5});
}

static void ui_load_from_save(user_interface_t *ui,
                                rpg_t *game, ge_view_t *view)
{
    int nb = 0;
    int fd_inv = open("save/inventory.data", O_RDONLY);
    int fd_stuff = open("save/stuff.data", O_RDONLY);

    if (fd_inv <= 0)
        return;
    while (read(fd_inv, &nb, sizeof(int)) > 0)
        inventory_add_by_id(ui->object_list, ui->inventory, nb);
    if (fd_stuff <= 0)
        return;
    for (int i = 0; read(fd_stuff, &nb, sizeof(int)) > 0; i++) {
        if (nb != -1) {
            ui->inventory->stuff[i] = obj_find_by_id(ui->object_list, nb);
            set_good_place_inv(ui->inventory->stuff[i], i);
        }
    }
}

user_interface_t *ui_setup(rpg_t *game, ge_view_t *view)
{
    user_interface_t *ui = malloc(sizeof(user_interface_t));

    if (!ui)
        return (NULL);
    ui->ui_texture = load_ui_texture();
    ui->object_list = object_load_list(ui->ui_texture);
    ui->inventory = inventory_setup(ui->ui_texture);
    ui->skill_tree = skill_tree_init(ui->ui_texture);
    ui->skill_bar = skill_bar_init(ui->ui_texture);
    ui_load_from_save(ui, game, view);
    return (ui);
}
