/*
** EPITECH PROJECT, 2019
** engine
** File description:
** Header File | xml
*/

#ifndef GE_XML_STRUCTS_H_
#define GE_XML_STRUCTS_H_

/**/
/* Includes */
/**/

/**/
/* Enum Definitions */
/**/

/**/
/* Structure Definitions */
/**/
/*
** @DESCRIPTION
**   Structure for parsing the xml "position" attribute.
*/
typedef struct {
    sfVector2u window_size;
    sfVector2u sprite_size;
} ge_xml_pos_args_t;

/**/
/* Constant Definitions */
/**/

void ge_attr_btn_onclick(ge_widget_button_t *this, char const *key);
void ge_attr_btn_default_texture(ge_widget_button_t *this, char const *key);
void ge_attr_btn_focus_texture(ge_widget_button_t *this, char const *key);
void ge_attr_btn_idle_texture(ge_widget_button_t *this, char const *key);
void ge_attr_btn_text(ge_widget_button_t *this, char const *key);

static const ge_str_fptr_t XML_BTN_ATTRS[] = { \
    {"default-texture", ge_attr_btn_default_texture}, \
    {"focus-texture", ge_attr_btn_focus_texture}, \
    {"idle-texture", ge_attr_btn_idle_texture}, \
    {"onclick", ge_attr_btn_onclick}, \
    {"text", ge_attr_btn_text}, \
    {NULL, NULL} \
};

void ge_attr_cbox_default_texture(ge_widget_cbox_t *this, char const *key);
void ge_attr_cbox_focus_texture(ge_widget_cbox_t *this, char const *key);
void ge_attr_cbox_text_on(ge_widget_cbox_t *this, char const *key);
void ge_attr_cbox_text_off(ge_widget_cbox_t *this, char const *key);
void ge_attr_cbox_onclick(ge_widget_cbox_t *this, char const *key);
void ge_attr_cbox_onload(ge_widget_cbox_t *this, char const *key);

static const ge_str_fptr_t XML_CBOX_ATTRS[] = { \
    {"default-texture", ge_attr_cbox_default_texture}, \
    {"focus-texture", ge_attr_cbox_focus_texture}, \
    {"text-on", ge_attr_cbox_text_on}, \
    {"text-off", ge_attr_cbox_text_off}, \
    {"onclick", ge_attr_cbox_onclick}, \
    {"onload", ge_attr_cbox_onload}, \
    {NULL, NULL} \
};

void ge_attr_pane_default_texture(ge_widget_pane_t *this, char const *key);

static const ge_str_fptr_t XML_PANE_ATTRS[] = { \
    {"default-texture", ge_attr_pane_default_texture}, \
    {NULL, NULL} \
};

void ge_xml_form_btn(ge_widget_t *this);
void ge_xml_form_pane(ge_widget_t *this);
void ge_xml_form_cbox(ge_widget_t *this);

static const ge_str_arr_fptr_t XML_TAGS_ARRAY[] = { \
    {"button", XML_BTN_ATTRS, &ge_xml_form_btn}, \
    {"pane", XML_PANE_ATTRS, &ge_xml_form_pane}, \
    {"checkbox", XML_CBOX_ATTRS, &ge_xml_form_cbox}, \
    {NULL, NULL, NULL} \
};

void ge_attr_render_after(ge_widget_t *this, char const *key);
void ge_attr_position(ge_widget_t *this, char const *key);
void ge_attr_states(ge_widget_t *this, char const *key);
void ge_attr_scale(ge_widget_t *this, char const *key);
void ge_attr_off_states_render(ge_widget_t *this, char const *key);
void ge_attr_id(ge_widget_t *this, char const *key);

static const ge_str_fptr_t XML_ATTRS[] = { \
    {"render-after", ge_attr_render_after}, \
    {"position", ge_attr_position}, \
    {"states", ge_attr_states}, \
    {"scale", ge_attr_scale}, \
    {"off-states-render", ge_attr_off_states_render}, \
    {"id", ge_attr_id}, \
    {NULL, NULL} \
};

/**/
/* Function Prototypes */
/**/

/**/
/* Dependant Statements */
/**/

#endif
