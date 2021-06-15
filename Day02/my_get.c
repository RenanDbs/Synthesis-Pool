/*
** EPITECH PROJECT, 2021
** my_get.c
** File description:
** .
*/

#include "./include/my.h"

void get_id_movie(list *list, int nb_movies, char *field, char *value)
{
    if (strcmp(field, "id_movie") != 0)
        return;
    for (int i = 0; i < nb_movies; i++)
        if(list[i].id_movie == atoi(value)){
            printf("%d;%s;%s;",list[i].id_movie,list[i].title,list[i].synposis);
            printf("%d.%s;%d;%s",list[i].id_director,list[i].director,list[i].id_type,list[i].type);
        }
}

void get_title(list *list, int nb_movies, char *field, char *value)
{
    if (strcmp(field, "title") != 0)
        return;
    for (int i = 0; i < nb_movies; i++)
        if(strstr(list[i].title , value) != NULL){
            printf("%d;%s;%s;",list[i].id_movie,list[i].title,list[i].synposis);
            printf("%d.%s;%d;%s",list[i].id_director,list[i].director,list[i].id_type,list[i].type);
        }
}

void get_synopsis(list *list, int nb_movies, char *field, char *value)
{
    if (strcmp(field, "synopsis") != 0)
        return;
    for (int i = 0; i < nb_movies; i++)
        if(strstr(list[i].synposis, value) != NULL){
            printf("%d;%s;%s;",list[i].id_movie,list[i].title,list[i].synposis);
            printf("%d.%s;%d;%s",list[i].id_director,list[i].director,list[i].id_type,list[i].type);
        }
}

void get_id_director(list *list, int nb_movies, char *field, char *value)
{
    if (strcmp(field, "id_director") != 0)
        return;
    for (int i = 0; i < nb_movies; i++)
        if(list[i].id_director == atoi(value)){
            printf("%d;%s;%s;",list[i].id_movie,list[i].title,list[i].synposis);
            printf("%d.%s;%d;%s",list[i].id_director,list[i].director,list[i].id_type,list[i].type);
        }
}

void get_id_type(list *list, int nb_movies, char *field, char *value)
{
    if (strcmp(field, "id_type") != 0)
        return;
    for (int i = 0; i < nb_movies; i++)
        if(list[i].id_type == atoi(value)){
            printf("%d;%s;%s;",list[i].id_movie,list[i].title,list[i].synposis);
            printf("%d.%s;%d;%s",list[i].id_director,list[i].director,list[i].id_type,list[i].type);
        }
}