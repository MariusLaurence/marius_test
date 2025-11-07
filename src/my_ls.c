/*
** EPITECH PROJECT, 2025
** ls 7
** File description:
** nrml
*/

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include "../include/my.h"

static void disp_dir(DIR *open)
{
    struct dirent *dir = NULL;

    dir = readdir(open);
    while (dir != NULL) {
        if (dir->d_name[0] != '.')
            mini_printf("%s\n", dir->d_name);
        dir = readdir(open);
    }
}

void check_flag(char *str, int flag)
{
    char *executable;
    int ac;
    char **av;

    executable = ac > 1 ? av[1] : ".";
    if (str[0] != '-')
        return;
    mini_printf("%s", executable);
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == 'a')
            my_ls_a(0, NULL);
        if (str[i] == 'd')
            ls_d(0, NULL);
        //if (str[i] == 'l')
        //  ls_l(0, NULL);
    }
}

static void handle_av(char *av)
{
    DIR *open = NULL;
    struct dirent *dir = NULL;
    struct stat info;

    if (stat(av, &info)) {
        perror(av);
        return;
    }
    if (S_ISREG(info.st_mode)) {
        mini_printf("%s ", av);
        return;
    }
    open = opendir(av);
    if (open == NULL) {
        perror(av);
        return;
    }
    disp_dir(open);
    path_exect(av);
    closedir(open);
}

void path_exect(char *str)
{
    int flag = 1;

    if (str == NULL || str[0] != '-')
        return;
    for (flag = 1; str[flag] != '\0'; flag++) {
        check_flag(str, flag);
    }
}

int main(int ac, char **av)
{
    if (ac == 1) {
        disp_dir(opendir("./"));
        return 0;
    }
    if (ac == 2) {
        check_flag(av[1], 1);
    }
    for (int f = 1; f < ac; f++) {
        handle_av(av[f]);
    }
    if (ac < 2) {
        return 84;
    }
}
