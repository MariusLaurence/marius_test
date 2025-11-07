/*
** EPITECH PROJECT, 2025
** ls
** File description:
** d
*/

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include "my.h"

int ls_d(int ac, char **av)
{
    DIR *open = NULL;
    struct dirent *dir = NULL;
    struct stat info;

    if (ac < 2) {
        mini_printf(".");
        return 84;
    }
    for (int f = 1; f < ac; f++) {
        if (stat(av[f], &info)) {
            perror(av[f]);
            continue;
        }
        if (S_ISREG(info.st_mode) || S_ISDIR(info.st_mode)) {
            mini_printf("%s ", av[f]);
        }
    }
    return 0;
}
