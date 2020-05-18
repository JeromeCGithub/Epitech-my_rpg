/*
** EPITECH PROJECT, 2019
** myerror
** File description:
** myerror header
*/

#ifndef LIB_MY_ERROR_H_
#define LIB_MY_ERROR_H_

/* Structure Definitions */
typedef enum {
    err_write,
    err_read
} my_error_mode_t;

/* Function Prototypes */
int my_error(my_error_mode_t mode, int new_code);

#endif
