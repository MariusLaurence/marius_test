/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** a
*/

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include "../include/my.h"

int my_ls_a(int ac, char **av)
{
    struct dirent *dir = NULL;
    DIR *open = opendir(".");

    if (open != NULL)
        return 84;
    dir = readdir(open);
    while (dir != NULL) {
        mini_printf("%s  ", dir->d_name);
        dir = readdir(open);
    }
    closedir(open);
    return 0;
}
