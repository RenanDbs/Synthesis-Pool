/*
** EPITECH PROJECT, 2021
** my_sort_helper.c
** File description:
** .
*/

#include "./include/my.h"

void sort_title(list *list, int nb_movies, char *field)
{
    char *tmp = NULL;

    if (strcmp(field, "title") != 0)
        return;
    tmp = malloc(sizeof(char) * 100);
    for (int i = 1; i < nb_movies; i++) {
        for (int j = 0; j < nb_movies - i; j++) {
            if (strcmp(list[j].title, list[j + 1].title) > 0) {
                swap_data(list, j);
            }
        }
    }
    for (int i = 0; i < nb_movies; i++){
        printf("%d;%s;%s;", list[i].id_movie, list[i].title,
        list[i].synposis);
        printf("%d.%s;%d;%s", list[i].id_director, list[i].director,
        list[i].id_type, list[i].type);
    }
}

void sort_type(list *list, int nb_movies, char *field)
{
    char *tmp = NULL;

    if (strcmp(field, "type") != 0)
        return;
    tmp = malloc(sizeof(char) * 100);
    for (int i = 1; i < nb_movies; i++)
        for (int j = 0; j < nb_movies - i; j++) {
            if (strcmp(list[j].type, list[j + 1].type) > 0) {
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

void sort_synopsis(list *list, int nb_movies, char *field)
{
    char *tmp = NULL;

    if (strcmp(field, "synopsis") != 0)
        return;
    tmp = malloc(sizeof(char) * 100);
    for (int i = 1; i < nb_movies; i++){
        for (int j = 0; j < nb_movies - i; j++) {
            if (strcmp(list[j].synposis, list[j + 1].synposis) > 0) {
                swap_data(list, j);
            }
        }
    }
    for (int i = 0; i < nb_movies; i++){
        printf("%d;%s;%s;", list[i].id_movie, list[i].title,
        list[i].synposis);
        printf("%d.%s;%d;%s", list[i].id_director, list[i].director,
        list[i].id_type, list[i].type);
    }
}