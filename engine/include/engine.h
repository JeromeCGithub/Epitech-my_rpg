/*
** EPITECH PROJECT, 2019
** engine
** File description:
** Header File | main
*/

#ifndef CSFML_ENGINE_H_
#define CSFML_ENGINE_H_

/**/
/* Includes */
/**/

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lib/mynode.h"
#include "lib/myerror.h"
#include "lib/mystdio.h"
#include "lib/mystring.h"

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>

/**/
/* Constant Definitions */
/**/
/*
** @DESCRIPTION
**   SFGELOG: Logs the start and end of important engine actions.
**   SFGE_MOCK_NAME: Name of the mock texture for ge_resources().
**   GE_READ_SIZE: Read size used for syscalls in ge_read_file().
*/
static const bool SFGELOG = true;
static __attribute__((unused))const char *SFGE_MOCK_NAME = "mock";
#define GE_READ_SIZE 4096

/**/
/* Enum / Typedefs Definitions */
/**/

#define u_int unsigned int
#define u_char unsigned char
#define c_char char const
#define rst restrict

typedef void (*fptr)();
typedef void *(*rvfptr)();

/**/
/* Structure Definitions */
/**/

/*
** @PAIR
**   String - Return Value Function
*/
typedef struct ge_str_rvfptr {
    char *string;
    rvfptr function;
} ge_str_rvfptr_t;
/*
** @PAIR
**   String - Function.
*/
typedef struct ge_str_fptr {
    char *string;
    fptr function;
} ge_str_fptr_t;
/*
** @PAIR
**   String - Pointer.
*/
typedef struct ge_str_ptr_fptr {
    char *string;
    void *pointer;
    fptr free;
} ge_str_ptr_fptr_t;
/*
** @PAIR
**   String - Array - Function.
*/
typedef struct ge_str_arr_fptr {
    char *string;
    const void *array;
    fptr function;
} ge_str_arr_fptr_t;
/*
** @PAIR
**   Texture - String.
*/
typedef struct ge_str_texture {
    char *string;
    sfTexture *texture;
} ge_str_texture_t;

typedef struct {
    char *path;
    char *key;
    sfIntRect rect;
    bool has_rect;
} ge_resloader_buf_t;

/**/
/* Modules */
/**/

#include "view.h"
#include "widget.h"
#include "xml.h"

/**/
/* Function Prototypes */
/**/

    /* utils */
char *ge_read_file(c_char *filepath);
char *ge_pget(c_char *string, u_int *i, c_char *delims);
void ge_pskip(c_char *string, u_int *i, c_char *skipped);
void ge_pskip_till(c_char *string, u_int *i, c_char *delims);
bool ge_range(int val, int min, int max);
bool ge_pnot(char c, c_char *delims);
void ge_null_endpoint(void);
float my_atof(c_char *s);
    /* misc */
sfTexture *ge_textures(sfTexture *text, c_char *key);
fptr ge_functions(fptr func, c_char *key);
void *ge_resources(void *ptr, c_char *key);
bool ge_hovers(sfSprite *sprite, sfRenderWindow *window);
void ge_textures_load(c_char *filepath);
unsigned int to_mask_value(unsigned int val);
    /* view */
ge_view_t *ge_view_create(sfRenderWindow *window, void *data);
void ge_view_run(ge_view_t *view, void *data);
void ge_view_set(ge_view_t *view, fptr init_func);
void ge_view_change(ge_view_t *this, fptr init_func);
void ge_view_reset(ge_view_t *view);
void ge_view_destroy(ge_view_t *view, void *data);
    /* widget */
ge_widget_t *ge_widget_create(void);
void ge_widget_destroy(ge_widget_t *this);
void ge_widget_render_view_widgets(ge_view_t *rst view,
void *rst data, bool time);
void ge_widget_free_widgets_array(NODE *widgets);
sfVector2f ge_xml_parse_position(c_char *fstring, ge_xml_pos_args_t args);
ge_xml_position_t switch_case_y(ge_xml_position_t pos, ge_xml_pos_args_t args);
ge_xml_position_t switch_case_x(ge_xml_position_t pos, ge_xml_pos_args_t args);
void ge_widget_set_position(ge_widget_t *widget, sfRenderWindow *window);
void *ge_widget_get_tpexts(ge_view_t *view, unsigned int id);
ge_widget_t *ge_widget_get(ge_view_t *view, unsigned int id);
void ge_widget_initialise_widgets(ge_view_t *view);
void ge_widget_btn_text(ge_view_t *view, ge_widget_t *widget, c_char *text);
    /* xml */
void ge_xml_load_interface(NODE **head, c_char *filepath);
ge_widget_t *ge_xml_parse_tag
(c_char *xs, u_int *i, const ge_str_fptr_t *tb, ge_widget_t *object);
bool ge_xml_parse_attr
(ge_widget_t *w, c_char *attr, c_char *key, const ge_str_fptr_t *tb);
void ge_xml_exit_on_null_attr(void *ptr, c_char *key);
/**/
/* Dependant Statements */
/**/


#endif
