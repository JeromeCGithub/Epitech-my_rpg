/*
** EPITECH PROJECT, 2019
** engine
** File description:
** Header File | widget
*/

#ifndef GE_WIDGET_H_
#define GE_WIDGET_H_

/**/
/* Includes */
/**/

/**/
/* Constant Definitions */
/**/

#define GEW_INIT 1
#define GEW_RENDER_AFTER 2
#define GEW_OFF_STATES_RENDER 4

/**/
/* Enum Definitions */
/**/
/*
** @DESCRIPTION
**   Renseigne sur les differents types de Widgets disponnibles
*/
typedef enum {
    geWidget_undefined,
    geWidget_Button,
    geWidget_Pane,
    geWidget_Checkbox
} ge_widget_type_t;

/**/
/* Structure Definitions */
/**/
/*
** @DESCRIPTION
**   Structure generique pour un widget de type cbox.
*/
typedef struct {
    sfText *text;
    char *texts[2];
    bool status;
    fptr onclick;
    fptr onload;
    sfTexture *default_texture;
    sfTexture *focus_texture;
} ge_widget_cbox_t;

/*
** @DESCRIPTION
**   Structure generique pour un widget de type textarea.
** @MEMBRES
**   (default, focus)_texture: textures de la textarea.
**   text: String malloc de 100 * sizeof(char) a l'initialisation.
*/
typedef struct {
    sfTexture *default_texture;
    sfTexture *focus_texture;
    char *text;
} ge_widget_textarea_t;

/*
** @DESCRIPTION
**   Structure generique pour un widget de type pane.
** @MEMBRES
**   default_texture: textures de la textarea.
*/
typedef struct {
    sfTexture *texture;
} ge_widget_pane_t;

/*
** @DESCRIPTION
**   Structure generique pour un widget de type bouton.
** @MEMBRES
**   (default, focus, idle )_texture: textures du boutton.
*/
typedef struct {
    sfTexture *default_texture;
    sfTexture *focus_texture;
    sfTexture *pressed_texture;
    sfText *text;
    fptr onclick;
} ge_widget_button_t;

/*
** @DESCRIPTION
**   Structure generique pour un widget.
** @MEMBRES
**   type: Le type de widget (e.g. button, textarea, cbox)
**   toggle_states: Liste chainée de viewstates ou le widget doit etre display.
**   tabindex: Ordre de l'objet dans le tab index.
**   type_exts: Structure anonyme vers les données propre aux TYPE de widget
**              comme ge_widget_button_t etc.
**   exts: Structure anonyme vers les données propre aux widget.
**   pstring: format string for the position of the widget.
*/
typedef struct {
    unsigned char options;
    unsigned int states;
    unsigned int id;
    ge_widget_type_t type;
    char *pstring;
    sfSprite *sprite;
    void *type_exts;
    void *exts;
} ge_widget_t;

typedef struct ge_xml_position {
    char *fmt;
    int size;
    float coord;
    float coeff;
} ge_xml_position_t;

typedef struct ge_widget_fptr {
    ge_widget_type_t type;
    fptr update;
    fptr init;
    fptr render;
} ge_widget_fptr_t;


void ge_widget_update_button(ge_view_t *rst view,
ge_widget_t *rst widget, void *rst data);
void ge_widget_update_pane(ge_view_t *rst view,
ge_widget_t *rst widget, void *rst data);
void ge_widget_update_cbox(ge_view_t *rst view,
ge_widget_t *rst widget, void *rst data);

void ge_widget_init_button(ge_view_t *rst view,
ge_widget_t *rst widget);
void ge_widget_init_pane(ge_view_t *rst view,
ge_widget_t *rst widget);
void ge_widget_init_cbox(ge_view_t *rst view,
ge_widget_t *rst widget);

void ge_widget_render_button(ge_view_t *rst view,
ge_widget_t *rst widget);
void ge_widget_render_pane(ge_view_t *rst view,
ge_widget_t *rst widget);
void ge_widget_render_cbox(ge_view_t *rst view,
ge_widget_t *rst widget);

static const ge_widget_fptr_t WIDGET_FUNCTIONS[] = {
    {geWidget_undefined,
    NULL, NULL, NULL},
    {geWidget_Button,
    ge_widget_update_button, ge_widget_init_button, ge_widget_render_button},
    {geWidget_Pane,
    ge_widget_update_pane, ge_widget_init_pane, ge_widget_render_pane},
    {geWidget_Checkbox,
    ge_widget_update_cbox, ge_widget_init_cbox, ge_widget_render_cbox}
};

/**/
/* Function Prototypes */
/**/

/**/
/* Dependant Statements */
/**/

#endif
