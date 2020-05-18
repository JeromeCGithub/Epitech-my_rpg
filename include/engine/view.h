/*
** EPITECH PROJECT, 2019
** engine
** File description:
** Header File | view
*/

#ifndef GE_VIEW_H_
#define GE_VIEW_H_

/**/
/* Enum Definitions */
/**/

/**/
/* Structure Definitions */
/**/
/*
** @DESCRIPTION
**   View object structure.
** @MEMBERS
**   init: Pointeur sur la fonction appelee lors de l'initialisation de la view
**   exit: Pointeur sur la fonction appelee lors de la fin de la view.
**   run: Pointeur sur la fonction appelee quand each game frame to update
**        the view.
**   state: variable for defining the state of the view (e.g. paused).
**   exts: pointer to an anonymous structure which holds the view data.
**   widgets: Liste chainee de tout les widgets.
*/
typedef struct {
    sfBool click;
    sfBool used_click;
    fptr exit;
    fptr run;
    fptr next;
    int state;
    sfVector2u window_size;
    void *exts;
    void *dataobject;
    NODE *widgets;
    sfRenderWindow *window;
} ge_view_t;

/**/
/* Function Prototypes */
/**/

/**/
/* Dependant Statements */
/**/

#endif
