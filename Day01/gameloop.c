/*
** EPITECH PROJECT, 2021
** gameloop.c
** File description:
** .
*/

#include "./include/my.h"

void print_start(pokedex *pokedex, char *player1, char *player2)
{
    int i = 0;

    while (pokedex[i].name != NULL)
    {
        printf("Pokemon %s has %d attack, %d defense,%d speed and %d health\n"
        , pokedex[i].name,
        pokedex[i].attack,pokedex[i].defense,
        pokedex[i].speed, pokedex[i].health);
        i++;
    }
}

void check_first(pokedex *pokedex, info *info, char *player1, char *player2)
{
    int found = 0;

    for (int i = 0; pokedex[i].name != NULL; i++){
        if (strcmp(pokedex[i].name, player1) == 0) {
            found++;
            info->pos1 = i;
        } else if (strcmp(pokedex[i].name, player2) == 0) {
            info->pos2 = i;
            found++;
        }
    }
    if (found != 2) {
        write(2, "Player's Pokemon not found in the Pokedex", 42);
        exit(84);
    }
    if (pokedex[info->pos1].speed > pokedex[info->pos2].speed)
        info->turn = 1;
    else
        info->turn = 2;
}

void attack_player1(pokedex *pokedex, info *info)
{
    int attack = my_rand(pokedex[info->pos1].attack);
    int res = 0;

    printf("%s attacks for %d damage\n", pokedex[info->pos1].name, attack);
    printf("%s blocks %d damage\n", pokedex[info->pos2].name,
    pokedex[info->pos2].defense);
    if (pokedex[info->pos2].health - (attack -
        pokedex[info->pos2].defense) < 0) {
        pokedex[info->pos2].health = 0;
        printf("%s loses %d health (%d left)\n", pokedex[info->pos2].name,
        attack - pokedex[info->pos2].defense, pokedex[info->pos2].health);
    } else if (attack > pokedex[info->pos2].defense) {
        pokedex[info->pos2].health = pokedex[info->pos2].health -
        (attack - pokedex[info->pos2].defense);
        printf("%s loses %d health (%d left)\n", pokedex[info->pos2].name,
        attack - pokedex[info->pos2].defense, pokedex[info->pos2].health);
    } else {
        printf("%s loses %d health (%d left)\n", pokedex[info->pos2].name,
    0, pokedex[info->pos2].health);
    }
    info->turn = 2;
}

void attack_player2(pokedex *pokedex, info *info)
{
    int attack = my_rand(pokedex[info->pos2].attack);
    int res = 0;

    printf("%s attacks for %d damage\n", pokedex[info->pos2].name, attack);
    printf("%s blocks %d damage\n", pokedex[info->pos1].name,
    pokedex[info->pos1].defense);
    if (pokedex[info->pos1].health -
    (attack - pokedex[info->pos1].defense) < 0) {
        pokedex[info->pos1].health = 0;
        printf("%s loses %d health (%d left)\n", pokedex[info->pos1].name,
        attack - pokedex[info->pos1].defense, pokedex[info->pos1].health);
    } else if (attack > pokedex[info->pos1].defense) {
        pokedex[info->pos1].health = pokedex[info->pos1].health
        - (attack - pokedex[info->pos1].defense);
        printf("%s loses %d health (%d left)\n", pokedex[info->pos1].name,
        attack - pokedex[info->pos1].defense, pokedex[info->pos1].health);
    } else {
        printf("%s loses %d health (%d left)\n", pokedex[info->pos1].name,
    0, pokedex[info->pos1].health);
    }
    info->turn = 1;
}

int game_loop(pokedex *pokedex, info *info, char *player1, char *player2)
{
    print_start(pokedex, player1, player2);
    check_first(pokedex, info, player1, player2);
    while (1)
    {
        if (info->turn == 1) {
            attack_player1(pokedex, info);
            check_end(pokedex, info);
        } else {
            attack_player2(pokedex, info);
            check_end(pokedex, info);
        }
    }
}