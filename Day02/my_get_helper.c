/*
** EPITECH PROJECT, 2021
** my_get_helper.c
** File description:
** .
*/

#include "./include/my.h"

void get_type(list *list, int nb_movies, char *field, char *value)
{
    if (strcmp(field, "type") != 0)
        return;
    for (int i = 0; i < nb_movies; i++)
        if(strstr(list[i].type , value) != NULL){
            printf("%d;%s;%s;",list[i].id_movie,list[i].title,list[i].synposis);
            printf("%d.%s;%d;%s",list[i].id_director,list[i].director,list[i].id_type,list[i].type);
        }
}


void my_get(list *list, char *str, int nb_movies)
{   
    char *token = strtok(str, " ");
    char *field = strtok(NULL, " ");
    char *value = strtok(NULL, " ");
    get_id_movie(list, nb_movies, field, value);
    get_title(list, nb_movies, field, value);
    get_synopsis(list, nb_movies, field, value);
    get_id_director(list, nb_movies, field, value);
    get_id_type(list, nb_movies, field, value);
    get_type(list, nb_movies, field, value);
}