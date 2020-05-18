/*
** EPITECH PROJECT, 2020
** my_strings
** File description:
** string_chr
*/

long int string_chr(char const *str, char c)
{
    if (!str)
        return (-1);
    for (long int i = 0; str[i]; i++) {
        if (str[i] == c) {
            return (i);
        }
    }
    return (-1);
}
