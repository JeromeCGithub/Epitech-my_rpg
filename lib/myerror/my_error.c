/*
** EPITECH PROJECT, 2019
** myerror
** File description:
** my_error
*/

#include "myerror.h"

/*
** @DESCRIPTION
**   Stores a program wide error variable to ensure processes ran errorlessly
**   Makes use of the my_error_mode_t enum (err_write, err_read).
** @USAGE
**   my_error(err_write, 84); => Sets the error variable to 84.
**   my_error(err_read, 0); => Returns the value of the error variable.
** @RETURN_VALUE
**   Returns an int.
**   'error' if err_read is set.
**   0 if err_write is set.
*/
int my_error(my_error_mode_t mode, int new_code)
{
    static int error;

    if (!error)
        error = 0;
    if (mode == err_write)
        error = new_code;
    else
        return error;
    return 0;
}
