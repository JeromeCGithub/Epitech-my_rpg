/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_xml_parse_button_tag
*/

#include "engine.h"

/*
** @DESCRIPTION
**   This function parses each attribute in the xml tag and sends it to
**   ge_xml_parse_attr with the attr and value.
*/
ge_widget_t *ge_xml_parse_tag
(char const *xs, u_int *i, const ge_str_fptr_t *tb, ge_widget_t *object)
{
    bool response = false;
    char *attr;
    char *val;

    ge_pskip(xs, i, " \n\t");
    while (ge_pnot(xs[*i], "<>")) {
        attr = ge_pget(xs, i, "\n\t =");
        ge_pskip(xs, i, "\n\t\" =");
        val = ge_pget(xs, i, "\"");
        ge_pskip(xs, i, "\n\t\" ");
        response = ge_xml_parse_attr(object, attr, val, tb);
        free(val);
        free(attr);
        if (!response) {
            ge_widget_destroy(object);
            return NULL;
        }
    }
    return object;
}
