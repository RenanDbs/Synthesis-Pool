/*
** EPITECH PROJECT, 2021
** utilities.c
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
        for (int j = 0; j < 7; j++)
            if (end_table[j] == NULL)
                exit(84);
        if (end_table == NULL)
            exit (84);
        list[i].id_movie = atoi(end_table[0]);
        list[i].title = strdup(end_table[1]);
        list[i].synposis = strdup(end_table[2]);
        list[i].id_director = atoi(end_table[3]);
        list[i].director = strdup(end_table[4]);
        list[i].id_type = atoi(end_table[5]);
        list[i].type = strdup(end_table[6]);
    }
    free(end_table);
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