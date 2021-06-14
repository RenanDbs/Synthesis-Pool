/*
** EPITECH PROJECT, 2021
** open_folder.c
** File description:
** .
*/

#include "./include/my.h"

int cont_files()
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;

    folder = opendir("./pokecfg");
    while ( (entry=readdir(folder)) )
    {
        files++;
    }
    closedir(folder);
    return(files);
}

void get_info(info *info, char **table, char *path, int i)
{
    FILE* stream = fopen(path, "r");
    char line[1024];

    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        if (tmp[0] != '#' && tmp[0] != '\n'){
            table[i] = strdup(line);
            info->nb_pokemon = info->nb_pokemon + 1;
            i++;
        }
        free(tmp);
    }
}

char *get_path(int size)
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    int i = 0;
    char *path = malloc(sizeof(char) * 50);

    strcat(path, "./pokecfg/");    
    folder = opendir("./pokecfg");
    while ( (entry=readdir(folder)) )
    {
        files++;
        if (files == size + 1){
            strcat(path, entry->d_name);
        }
    }
    closedir(folder);
    return (path);
}