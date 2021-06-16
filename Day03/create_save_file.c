/*
** EPITECH PROJECT, 2020
** rush-1-4.c
** File description:
** rush 1 - 4 copy pasta code from 2
*/

#include "lib/my.h"

void free_str_file(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        free(str[i]);
    }
    free(str);
}

int check_file_err_helper(char current_char, char *nb, int spaces, int ind)
{
    if (spaces == 2 && current_char != '\n') {
        nb[ind] = current_char;
        nb[ind + 1] = '\0';
        ind++;
    }
    return ind;
}

void put_amount_into_array(char *nb, int *amount, int i, int space)
{
    if (space != 2)
        exit(84);
    if (check_if_int(nb) == 1) {
        amount[i] = atoi(nb);
    } else {
        free(nb);
        exit(84);
    }
    if (i == 7)
        free(nb);
}

void check_file_err(char **str, int *amount)
{
    int i = 0;
    int x = 0;
    int spaces = 0;
    int ind = 0;
    char *nb = malloc(sizeof(char) * 1000);

    if (nb == NULL)
        exit(84);
    while (i < 8 && str[i] != NULL) {
        ind = check_file_err_helper(str[i][x], nb, spaces, ind);
        if (str[i][x] == ' ')
            spaces += 1;
        if (str[i][x] == '\n') {
            put_amount_into_array(nb, amount, i, spaces);
            i++;
            x = 0;
            ind = 0;
            spaces = 0;
        } else
            x++;
    }
}

void create_open_file(int *amount)
{
    char **str = malloc(sizeof(char *) * 1000);

    if (str == NULL)
        exit(84);
    if (access(".save", F_OK) == 0) {
        read_from_existing_file(str);
        check_if_right_ingredients(str);
        check_file_err(str, amount);
    } else {
        create_not_existing_file(amount);
    }
    free_str_file(str);
}