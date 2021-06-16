/*
** EPITECH PROJECT, 2021
** error_management.c
** File description:
** .
*/

#include "./lib/my.h"

int check_arg(char *input, char **ingredient)
{
    char *food = NULL;
    int count  = 0;

    food = strtok(input, " ");
    food = strtok(NULL, " ");
    for (int i = 0; i < 8; i++){
        if (strcmp(food, ingredient[i]) == 0)
            count ++;
        }
    if (count == 1){
        food = strtok(NULL, " ");
        if (food == NULL)
            return (84);
    } else {
        return (84);
    }
    return (0);
}

int check_meal(char *input, int *fridge, char **ingredient)
{
    if (strcmp(input, "make pizza") == 0) {
        my_make_pizza(fridge, ingredient);
        return (1);
    }
    if (strcmp(input, "make pasta") == 0) {
        my_make_pasta(fridge, ingredient);
        return (1);
    }
    printf("'%s': meal unknown\n", input);
    return (1);
}