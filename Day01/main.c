/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include "./include/my.h"

int my_rand(int upper)
{
    int num = (rand() % (upper - 0 + 1)) + 0;

    return (num);
}

char **get_first_table(info *info ,char ** table, char *path, int file_nb, int steps)
{
    int end = 0;

    while (end != file_nb){
        path = get_path(steps);
        get_info(info, table, path, end);
        steps ++;
        end++;
    }
}

void free_used_data(char *path, char **table)
{
    free(path);
    free(table);
}

int main(int ac, char **av)
{
    int file_nb = cont_files() - 2;
    int steps = 2;
    char *path = NULL;
    char *final_path = "./pokecfg";
    char **table = malloc(sizeof(char *) * 100);
    pokedex *pokedex = malloc(sizeof(pokedex) * 100);
    info *info = malloc(sizeof(info));

    info->nb_pokemon = 0;
    if (ac != 3) {
        write(2, "Missing argument (./pokemon 'Pokemon1' 'Pokemon2')", 50);
        exit (84);
    }
    get_first_table(info, table, path, file_nb, steps);
    get_struct(info, table, pokedex);
    for (int i = 0; i < info->nb_pokemon; i++)
        my_lowerstr(pokedex[i].name);
    free_used_data(path, table);
    sort_struct(info, pokedex);
    game_loop(pokedex, info, av[1], av[2]);
}