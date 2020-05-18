/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_xml_interface_from_file
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Checks if fetched tag is supported and calls ge_xml_parse_tag with the
**   adequate attribute array.
*/
static ge_widget_t *pre_parse_xml_tag(c_char *xstring, u_int *i)
{
    char *type = ge_pget(xstring, i, "\n\t <>");
    void *w = ge_widget_create();

    if (!type || !w)
        return NULL;
    for (u_int j = 0; XML_TAGS_ARRAY[j].string; j++) {
        if (my_strcmp(XML_TAGS_ARRAY[j].string, type) == 0) {
            XML_TAGS_ARRAY[j].function(w);
            w = ge_xml_parse_tag(xstring, i, XML_TAGS_ARRAY[j].array, w);
            free(type);
            return w;
        }
    }
    free(type);
    return NULL;
}

/*
** @DESCRIPTION
**   Handles all errors from pre_parse_xml_tag and appends the widget to head.
*/
static void form_widget(c_char *xs, u_int *i, NODE **head, u_int *nb)
{
    ge_widget_t *widget = NULL;

    (*i)++;
    (*nb)++;
    widget = pre_parse_xml_tag(xs, i);
    if (widget) {
        node_insert(head, widget);
    } else {
        my_puts(2, "\033[0;33m-- Error: Couldn't create widget n°");
        my_puti(2, *nb);
        my_puts(2, "\033[0m\n");
        my_error(err_write, 84);
    }
}

/*
** @DESCRIPTION
**   XML Parser.
**   Appends widgets to a linked list from a xml file passed as parameter.
*/
void ge_xml_load_interface(NODE **head, c_char *filepath)
{
    char *xstring = ge_read_file(filepath);
    u_int nb = 0;

    if (SFGELOG)
        my_dprintf(1, "\033[40;36mLoading interface '%s'\033[0m\n", filepath);
    if (!xstring) {
        my_puts(2, "Abort: Interface failed to load\n");
        my_error(err_write, 84);
        return;
    }
    for (u_int i = 0; xstring[i]; i++) {
        if (xstring[i] != '<')
            continue;
        form_widget(xstring, &i, head, &nb);
        if (my_error(err_read, 0))
            break;
    }
    if (SFGELOG && !my_error(err_read, 0))
        my_puts(1, "\033[0;32m-- Done\033[0m\n");
    node_reverse(head);
    free(xstring);
}
