/*
** EPITECH PROJECT, 2021
** my_show.c
** File description:
** .
*/

#include "./include/my.h"

void my_show(list *list, char *str, int nb_movies)
{
    char *token = strtok(str, " ");
    char *field = strtok(NULL, " ");
    char *value = strtok(NULL, " ");
    int end = 0;
    int j = 0;
    int i = atoi(field);

    if (i - 1 < 0)
        i = 0;
    else
        i = i -1;
    for (i; j < atoi(value); i++){
        printf("%d;%s;%s;", list[i].id_movie,
        list[i].title, list[i].synposis);
        printf("%d.%s;%d;%s", list[i].id_director, list[i].director,
        list[i].id_type, list[i].type);
        j++;
    }
}