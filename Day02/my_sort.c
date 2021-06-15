/*
** EPITECH PROJECT, 2021
** my_sort.c
** File description:
** .
*/

#include "./include/my.h"

void sort_director(list *list, int nb_movies, char *field)
{
    char *tmp = NULL;

    if (strcmp(field, "director") != 0)
        return;
    tmp = malloc(sizeof(char) * 100);
    for (int i = 1; i < nb_movies; i++)
        for (int j = 0; j < nb_movies - i; j++) {
            if (strcmp(list[j].director, list[j + 1].director) > 0) {
                swap_data(list, j);
            }
        }
    for (int i = 0; i < nb_movies; i++){
        printf("%d;%s;%s;", list[i].id_movie, list[i].title,
        list[i].synposis);
        printf("%d.%s;%d;%s", list[i].id_director, list[i].director,
        list[i].id_type, list[i].type);
    }
}

void sort_id_movie(list *list, int nb_movies, char *field)
{
    char *tmp = NULL;

    if (strcmp(field, "id_movie") != 0)
        return;
    tmp = malloc(sizeof(char) * 100);
    for (int i = 1; i < nb_movies; i++)
        for (int j = 0; j < nb_movies - i; j++) {
            if (list[j].id_movie > list[j + 1].id_movie) {
                swap_data(list, j);
            }
        }
    for (int i = 0; i < nb_movies; i++){
        printf("%d;%s;%s;", list[i].id_movie, list[i].title,
        list[i].synposis);
        printf("%d.%s;%d;%s", list[i].id_director, list[i].director,
        list[i].id_type, list[i].type);
    }
}

void sort_id_director(list *list, int nb_movies, char *field)
{
    char *tmp = NULL;

    if (strcmp(field, "id_director") != 0)
        return;
    tmp = malloc(sizeof(char) * 100);
    for (int i = 1; i < nb_movies; i++)
        for (int j = 0; j < nb_movies - i; j++) {
            if (list[j].id_director > list[j + 1].id_director) {
                swap_data(list, j);
            }
        }
    for (int i = 0; i < nb_movies; i++){
        printf("%d;%s;%s;", list[i].id_movie, list[i].title,
        list[i].synposis);
        printf("%d.%s;%d;%s", list[i].id_director, list[i].director,
        list[i].id_type, list[i].type);
    }
}

void sort_id_type(list *list, int nb_movies, char *field)
{
    char *tmp = NULL;

    if (strcmp(field, "id_type") != 0)
        return;
    tmp = malloc(sizeof(char) * 100);
    for (int i = 1; i < nb_movies; i++)
        for (int j = 0; j < nb_movies - i; j++) {
            if (list[j].id_type > list[j + 1].id_type) {
                swap_data(list, j);
            }
        }
    for (int i = 0; i < nb_movies; i++){
        printf("%d;%s;%s;", list[i].id_movie, list[i].title,
        list[i].synposis);
        printf("%d.%s;%d;%s", list[i].id_director, list[i].director,
        list[i].id_type, list[i].type);
    }
}

void my_sort(list *list, char *str, int nb_movies)
{
    char *token = strtok(str, " ");
    char *field = strtok(NULL, " ");

    sort_id_movie(list, nb_movies, field);
    sort_title(list, nb_movies, field);
    sort_director(list, nb_movies, field);
    sort_synopsis(list, nb_movies, field);
    sort_id_director(list, nb_movies, field);
    sort_id_type(list, nb_movies, field);
    sort_type(list, nb_movies, field);
}