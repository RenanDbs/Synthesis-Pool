/*
** EPITECH PROJECT, 2021
** gameloop_helper.c
** File description:
** .
*/

#include "./include/my.h"

void check_end(pokedex *pokedex, info *info)
{
    if (pokedex[info->pos2].health == 0){
        printf("%s is KO\n", pokedex[info->pos2].name);
        printf("%s wins the fight !\n", pokedex[info->pos1].name );
        exit (0);
    }
    if (pokedex[info->pos1].health == 0){
        printf("%s is KO\n", pokedex[info->pos1].name);
        printf("%s wins the fight !\n", pokedex[info->pos2].name );
        exit (0);
    }
}