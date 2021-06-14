/*
** EPITECH PROJECT, 2021
** struct_work.c
** File description:
** .
*/

#include "./include/my.h"

void get_struct(info *info, char **table, pokedex *pokedex)
{
    char **end_table = NULL;

    for (int i = 0; i < info->nb_pokemon ; i++){
        end_table = my_str_to_word_array(table[i], ';');
        pokedex[i].name = end_table[0];
        pokedex[i].attack = atoi(end_table[1]);
        pokedex[i].defense = atoi(end_table[2]);
        pokedex[i].speed = atoi(end_table[3]);
        pokedex[i].health = atoi(end_table[4]);
    }
    free(end_table);
}

char *my_lowerstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] < 'Z')
            str[i] = str[i] + 32;
    }
}

char *my_upperstr(char *str)
{
    if (str[0] >= 'a' && str[0] < 'z')
        str[0] = str[0] - 32;
}

void swap_data(pokedex *pokedex, int j)
{
    int tmp_nb = 0;

    tmp_nb = pokedex[j].attack;
    pokedex[j].attack = pokedex[j + 1].attack;
    pokedex[j + 1].attack = tmp_nb;

    tmp_nb = pokedex[j].defense;
    pokedex[j].defense = pokedex[j + 1].defense;
    pokedex[j + 1].defense = tmp_nb;

    tmp_nb = pokedex[j].speed;
    pokedex[j].speed = pokedex[j + 1].speed;
    pokedex[j + 1].speed = tmp_nb;

    tmp_nb = pokedex[j].health;
    pokedex[j].health = pokedex[j + 1].health;
    pokedex[j + 1].health = tmp_nb;
}

void sort_struct(info *info, pokedex *pokedex)
{
    char *tmp = malloc(sizeof(char) * 100);

    for (int i = 1; i < info->nb_pokemon; i++)
        for (int j = 0; j < info->nb_pokemon - i; j++) {
            if (strcmp(pokedex[j].name, pokedex[j + 1].name) > 0) {
                tmp = pokedex[j].name;
                pokedex[j].name = pokedex[j + 1].name;
                pokedex[j + 1].name = tmp;
                swap_data(pokedex, j);
            }
        }
    for (int i = 0; i < info->nb_pokemon; i++)
        my_upperstr(pokedex[i].name);
}