/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** ls
*/


#ifndef MY_H_
    #define MY_H_
    #include <stdbool.h>
    #include <stddef.h>

int ls_d(int ac, char **av);
int ls_l(int ac, char **av);
int my_ls_a(int ac, char **av);
int mini_printf(const char *format, ...);
void path_exect(char *str);
#endif
