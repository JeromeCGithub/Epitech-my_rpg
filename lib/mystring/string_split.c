/*
** EPITECH PROJECT, 2020
** my_strings
** File description:
** split_string
*/

#include <stdlib.h>
#include "mystring.h"

static size_t count_nb_words(char const *str, char const *index)
{
    size_t counter = 0;

    for (size_t i = 0; str[i];) {
        for (; str[i] && string_chr(index, str[i]) == -1; i++);
        for (; str[i] && string_chr(index, str[i]) != -1; i++);
        counter++;
    }
    return (counter);
}

static char **word_array_alloc(char const *str, char const *index, size_t len)
{
    char **word_array = NULL;
    size_t lines = 0;

    word_array = malloc(sizeof(char *) * (len + 1));
    if (!word_array)
        return (NULL);
    for (size_t i = 0; str[i]; lines++, len = i) {
        for (; str[len] && string_chr(index, str[len]) == -1; len++);
        word_array[lines] = malloc(sizeof(char) * (len - i + 1));
        if (!word_array[lines])
            return (NULL);
        for (len = 0; str[i] && string_chr(index, str[i]) == -1; i++)
            word_array[lines][len++] = str[i];
        word_array[lines][len] = 0;
        for (; str[i] && string_chr(index, str[i]) != -1; i++);
    }
    word_array[lines] = NULL;
    return (word_array);
}

char **string_split(char const *str, char const *index)
{
    size_t len = 0;

    if (!str)
        return (NULL);
    while (string_chr(index, *str) != -1)
        str = &str[1];
    len = count_nb_words(str, index);
    return (word_array_alloc(str, index, len));
}
