/*
** EPITECH PROJECT, 2021
** my.h
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

typedef struct pokedex
{
    char *name;
    int attack;
    int defense;
    int speed;
    int health;
} pokedex;

typedef struct info
{
    int nb_files;
    int nb_pokemon;
    int turn;
    int pos1;
    int pos2;
} info ;

int cont_files(void);
void get_info(info *info, char **table, char *path, int i);
char *get_path(int size);
char **my_str_to_word_array(char *str, char sep);
void get_struct(info *info ,char **table, pokedex *pokedex);
char *my_lowerstr(char *str);
char *my_upperstr(char *str);
void sort_struct(info *info, pokedex *pokedex);
int my_rand(int upper);
void print_start(pokedex *pokedex, char *player1, char *player2);
void check_first(pokedex *pokedex, info *info, char *player1, char *player2);
void attack_player1(pokedex *pokedex, info *info);
void attack_player2(pokedex *pokedex, info *info);
int game_loop(pokedex *pokedex, info *info, char *player1, char *player2);
void swap_stuff(pokedex *pokedex, int j);
void check_end(pokedex *pokedex, info *info);