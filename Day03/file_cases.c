/*
** EPITECH PROJECT, 2020
** rush-1-4.c
** File description:
** rush 1 - 4 copy pasta code from 2
*/

#include "lib/my.h"

int check_if_file_correct(char **str)
{
    int spaces = 0;

    for (int i = 0; i < 8; i++) {
        spaces = check_if_file_helper(str, i, spaces);
        if (spaces != 2)
            return 1;
        spaces = 0;
    }
    return 0;
}

void read_from_existing_file(char **str)
{
    size_t buf_size = 0;
    ssize_t width = 0;
    FILE *f = fopen(".save", "r");
    int i = 0;

    str[i] = malloc(sizeof(char) * 100);
    str[i + 1] = NULL;
    if (f == NULL || str == NULL)
        exit(84);
    width = getline(&str[i], &buf_size, f);
    while (width >= 0 && i <= 9) {
        i++;
        str[i] = malloc(sizeof(char) * 100);
        str[i + 1] = NULL;
        if (str[i] == NULL)
            exit(84);
        width = getline(&str[i], &buf_size, f);
    }
    fclose(f);
    if (i != 8 || check_if_file_correct(str) == 1)
        exit(84);
}

void create_not_existing_file(int *amount)
{
    FILE *f = fopen(".save", "w");

    if (f == NULL) {
        exit(84);
    }
    fprintf(f, "tomato = 50\n");
    fprintf(f, "dough = 50\n");
    fprintf(f, "onion = 50\n");
    fprintf(f, "pasta = 50\n");
    fprintf(f, "olive = 50\n");
    fprintf(f, "pepper = 50\n");
    fprintf(f, "ham = 50\n");
    fprintf(f, "cheese = 50\n");
    for (int i = 0; i < 8; i++)
        amount[i] = 50;
    fclose(f);
}

void save_file(int *amount)
{
    FILE *f = fopen(".save", "w");

    if (f == NULL) {
        exit(84);
    }
    fprintf(f, "tomato = %d\n", amount[0]);
    fprintf(f, "dough = %d\n", amount[1]);
    fprintf(f, "onion = %d\n", amount[2]);
    fprintf(f, "pasta = %d\n", amount[3]);
    fprintf(f, "olive = %d\n", amount[4]);
    fprintf(f, "pepper = %d\n", amount[5]);
    fprintf(f, "ham = %d\n", amount[6]);
    fprintf(f, "cheese = %d\n", amount[7]);
    for (int i = 0; i < 8; i++)
        amount[i] = 50;
    fclose(f);
}