/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_xml_parse_attr
*/

#include "engine.h"

/*
** @DESCRIPTION
**   This function takes the widget buffer, the xml attribute, its value,
**   and the static array of attributes specific to the widget and for each
**   attribute sends the widget buffer to the right handler.
*/
bool ge_xml_parse_attr
(ge_widget_t *w, char const *attr, char const *key, const ge_str_fptr_t *tb)
{
    for (u_int i = 0; XML_ATTRS[i].string; i++) {
        if (my_strcmp(attr, XML_ATTRS[i].string) == 0) {
            XML_ATTRS[i].function(w, key);
            return true;
        }
    }
    for (u_int i = 0; tb[i].string; i++) {
        if (my_strcmp(attr, tb[i].string) == 0) {
            tb[i].function(w->type_exts, key);
            return true;
        }
    }
    my_dprintf(2, "Unknow attribute '%s'\n", attr);
    return false;
}
