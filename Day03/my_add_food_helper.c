/*
** EPITECH PROJECT, 2021
** tool.c
** File description:
** .
*/

#include "./lib/my.h"

void my_add_food_helper(char **ingredient, char *food, int *fridge)
{
    for (int i = 0; i < 8; i++) {
        if (strcmp(food, ingredient[i]) == 0) {
            food = strtok(NULL, " ");
            if (atoi(food) > 0)
                fridge[i] = fridge[i] + atoi(food);
            else
                write(2, "You can't add 'negative food'\n", 30);
        }
    }
}