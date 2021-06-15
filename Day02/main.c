/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include "./include/my.h"

int get_info(char **table, char *path)
{
    FILE* stream = fopen(path, "r");
    char line[1024];
    int i = 0;

    while (fgets(line, 1024, stream))
    {
        char *tmp = strdup(line);
        if (tmp[0] != '#' && tmp[0] != '\n'){
            table[i] = strdup(line);
            i++;
        }
        free(tmp);
    }
    return (i);
}

void get_struct(char **table, list *list, int nb_movies)
{
    char **end_table = NULL;

    for (int i = 0; i < nb_movies; i++){
        end_table = my_str_to_word_array(table[i], ';');
        list[i].id_movie = atoi(end_table[0]);
        list[i].title = strdup(end_table[1]);
        list[i].synposis = strdup(end_table[2]);
        list[i].id_director = atoi(end_table[3]);
        list[i].director = strdup(end_table[4]);
        list[i].id_type = atoi(end_table[5]);
        list[i].type = strdup(end_table[6]);
        printf("IN STRUC LOOP = %s\n", end_table[1]);
    }
    printf("AFTER STRUC = %s\n", list[0].title);
}

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
    for(i; j < atoi(value); i++){
        printf("%d;%s;%s;",list[i].id_movie,list[i].title,list[i].synposis);
        printf("%d.%s;%d;%s",list[i].id_director,list[i].director,list[i].id_type,list[i].type);
        j++;
    }
}

void swap_data_2(list *list, int j)
{
    char *str = NULL;

    str = strdup(list[j].title);
    list[j].title = strdup(list[j + 1].title);
    list[j + 1].title = strdup(str);

    str = strdup(list[j].synposis);
    list[j].synposis = strdup(list[j + 1].synposis);
    list[j + 1].synposis = strdup(str);

    str = strdup(list[j].director);
    list[j].director = strdup(list[j + 1].director);
    list[j + 1].director = strdup(str);

    str = strdup(list[j].type);
    list[j].type = strdup(list[j + 1].type);
    list[j + 1].type = strdup(str);
}

void swap_data(list *list, int j)
{
    int tmp_nb = 0;

    tmp_nb = list[j].id_director;
    list[j].id_director = list[j + 1].id_director;
    list[j + 1].id_director = tmp_nb;

    tmp_nb = list[j].id_movie;
    list[j].id_movie = list[j + 1].id_movie;
    list[j + 1].id_movie = tmp_nb;

    tmp_nb = list[j].id_type;
    list[j].id_type = list[j + 1].id_type;
    list[j + 1].id_type = tmp_nb;
    swap_data_2(list, j);
}

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
}

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
}

void my_sort(list *list, char *str, int nb_movies)
{
    char *token = strtok(str, " ");
    char *field = strtok(NULL, " ");

    sort_id_movie(list, nb_movies, field);
    sort_title(list, nb_movies, field);
    sort_synopsis(list, nb_movies, field);
    sort_id_director(list, nb_movies, field);
    sort_id_type(list, nb_movies, field);
    sort_type(list, nb_movies, field);
}

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

int main(int ac, char **av)
{
    char **table = malloc(sizeof(char *) * 100);
    int nb_movies = 0;
    list *list = NULL;

    nb_movies = get_info(table, av[1]);
    list = malloc(sizeof(list) * nb_movies + 1);
    get_struct(table, list, nb_movies);
    my_commands(list, av[2], nb_movies);
    for (int i = 0; i < nb_movies; i++) {
        printf("%d;%s;%s;",list[i].id_movie,list[i].title,list[i].synposis);
        printf("%d.%s;%d;%s",list[i].id_director,list[i].director,list[i].id_type,list[i].type);
    }
}