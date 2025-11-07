/*
** EPITECH PROJECT, 2025
** ls
** File description:
** l
*/

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include "my.h"

static void disp_dir(DIR *open)
{
    struct dirent *dir = NULL;

    dir = readdir(open);
    while (dir != NULL) {
        mini_printf("%s\n ", dir->d_name);
        dir = readdir(open);
    }
}

static void handle_av(const char *av)
{
    DIR *open = NULL;
    struct dirent *dir = NULL;
    struct stat info;

    if (stat(av, &info)) {
        perror(av);
        return;
    }
    if (S_ISREG(info.st_mode)) {
        mini_printf("%s\n ", av);
        return;
    }
    open = opendir(av);
    if (open == NULL) {
        perror(av);
        return;
    }
    disp_dir(open);
    closedir(open);
}

int ls_l(int ac, char **av)
{
    struct stat info;
 
    if (ac < 2) {
        return 84;
    }
    for (int t = 1; t < ac; t++) {
        handle_av(av[f]);
    }
    return 0;
}

stuct stat info

//derneir modification du fichier:
printf("Last status change:       %s", ctime(&sb.st_ctime));
printf("Last file access:         %s", ctime(&sb.st_atime));
printf("Last file modification:   %s", ctime(&sb.st_mtime));
//nbr de lien de physique:
printf("Link count:               %i\n", (int) sb.st_nlink)
//type et permission:
printf("Mode:                     %i (octal)\n",(int) sb.st_mode)
//proprietaire du fichier + du grp :(met en char pas en int)
 printf("Ownership:                UID=%ju   GID=%ju\n",
                  (uintmax_t) sb.st_uid, (uintmax_t) sb.st_gid);
//et affiche le le nom du dossier:
dir ->d_name 

void disp_perms(struct stat disp)
{
    if (S_ISREG(disp.st_mode)) mini_printf("-");
    else if (S_ISDIR(disp.st_mode)) mini_printf("d");
    else if (S_ISLNK(disp.st_mode)) mini_printf("l");
    else if (S_ISCHR(disp.st_mode)) mini_printf("c");
    else if (S_ISBLK(disp.st_mode)) mini_printf("b");
    else if (S_ISFIFO(disp.st_mode)) mini_printf("p");
    else (S_ISSOCK(disp.st_mode)) mini_printf("s");
    
    mini_printf("%c", (disp.st_mode & S_IRUSR) ? 'r' : '-');
    mini_printf("%c", (disp.st_mode & S_IWUSR) ? 'w' : '-');
    mini_printf("%c", (disp.st_mode & S_IXUSR) ? 'x' : '-');
    mini_printf("%c", (disp.st_mode & S_IRGRP) ? 'r' : '-');
    mini_printf("%c", (disp.st_mode & S_IWGRP) ? 'w' : '-');
    mini_printf("%c", (disp.st_mode & S_IXGRP) ? 'x' : '-');
    mini_printf("%c", (disp.st_mode & S_IROTH) ? 'r' : '-');
    mini_printf("%c", (disp.st_mode & S_IWOTH) ? 'w' : '-');
    mini_printf("%c", (disp.st_mode & S_IXOTH) ? 'x' : '-');
}

void disp_link(struct stat disp)
{
    printf("Link count:               %i\n", (int) sb.st_nlink)
}
