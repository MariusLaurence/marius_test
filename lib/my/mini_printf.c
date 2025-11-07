/*
** EPITECH PROJECT, 2025
** mini printf
** File description:
** mini printf
*/
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

static int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}

int display_arg(char flag, va_list ap)
{
    switch (flag) {
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 'd':
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case '%':
            my_putchar('%');
            break;
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            display_arg(format[i + 1], ap);
            i++;
            continue;
        }
        my_putchar(format[i]);
    }
    return 0;
}
