/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include "./include/my.h"

void my_commands(list *list, char *str, int nb_movies)
{
    char *tmp = strdup(str);
    char *token = strtok(tmp, " ");
    if (strcmp(token, "get") == 0)
        my_get(list, str, nb_movies);
    if ((strcmp(token, "show")) == 0)
        my_show(list, str, nb_movies);
    if ((strcmp(token, "sort")) == 0)
        my_sort(list, str, nb_movies);
}

void my_free(char **table, list *list, int nb_movies)
{
    free(table);
    for (int i = 0; i < nb_movies; i++){
        free(list[i].director);
        free(list[i].synposis);
        free(list[i].title);
        free(list[i].type);
    }
    free(list);
}

int main(int ac, char **av)
{
    char **table = NULL;
    int nb_movies = 0;
    list *list = NULL;

    if (ac != 3){
        write(2, "Missing parameters (./mydb 'file' 'params')\n",44);
        exit(84);
    }
    table = malloc(sizeof(char *) * 100);
    if (table == NULL)
        exit (84);
    nb_movies = get_info(table, av[1]);
    list = malloc(sizeof(*list) * (nb_movies + 1));
    if (list == NULL)
        exit(84);
    get_struct(table, list, nb_movies);
    my_commands(list, av[2], nb_movies);
    my_free(table, list, nb_movies);
}