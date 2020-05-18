/*
** EPITECH PROJECT, 2019
** engine
** File description:
** ge_readf
*/

#include "engine.h"

/*
** @DESCRIPTION
**   Reads a file and returns its contents.
*/
char *ge_read_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *contents = my_strdup("");
    char *temp = NULL;
    char buf[GE_READ_SIZE + 1] = {0};
    unsigned int read_size = GE_READ_SIZE;
    unsigned int read_bytes;

    if (fd == -1) {
        my_dprintf(2, "Error: Cound't access file '%s'\n", filepath);
        return NULL;
    }
    while ((read_bytes = read(fd, buf, read_size)) > 0) {
        buf[read_bytes] = '\0';
        temp = contents;
        contents = my_str_merge(contents, buf);
        free(temp);
    }
    close(fd);
    return contents;
}