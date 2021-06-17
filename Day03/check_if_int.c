/*
** EPITECH PROJECT, 2020
** check_if_int.c
** File description:
** .
*/

#include "lib/my.h"

int check_if_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
    }
    return 1;
}

void check_if_right_ingredients(char **str)
{
    if (strncmp("tomato", str[0], 6) != 0 || \
    strncmp("dough", str[1], 5) != 0 || \
    strncmp("onion", str[2], 5) != 0 || \
    strncmp("pasta", str[3], 5) != 0 || \
    strncmp("olive", str[4], 5) != 0 || \
    strncmp("pepper", str[5], 6) != 0 || \
    strncmp("ham", str[6], 3) != 0 || \
    strncmp("cheese", str[7], 6) != 0)
        exit(84);
}

int check_if_file_helper(char **str, int i, int spaces)
{
    for (int x = 0; str[i][x] != '\0'; x++) {
        if (str[i][x] == ' ')
            spaces += 1;
    }
    return spaces;
}