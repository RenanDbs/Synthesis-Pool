/*
** EPITECH PROJECT, 2021
** my.
** File description:
** .
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>

typedef struct list
{
    int id_movie;
    char *title;
    char *synposis;
    int id_director;
    char *director;
    int id_type;
    char *type;
} list;

char **my_str_to_word_array(char *str, char sep);
void get_id_movie(list *list, int nb_movies, char *field, char *value);
void get_title(list *list, int nb_movies, char *field, char *value);
void get_synopsis(list *list, int nb_movies, char *field, char *value);
void get_id_director(list *list, int nb_movies, char *field, char *value);
void get_id_type(list *list, int nb_movies, char *field, char *value);
void get_type(list *list, int nb_movies, char *field, char *value);
void my_get(list *list, char *str, int nb_movies);