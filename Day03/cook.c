/*
** EPITECH PROJECT, 2021
** cook.c
** File description:
** .
*/

#include "./lib/my.h"

int *remove_food(int *fridge, int food)
{
    if (food == 1) {
        fridge[0] = fridge[0] - 5;
        fridge[1] = fridge[1] - 1;
        fridge[2] = fridge[2] - 3;
        fridge[4] = fridge[4] - 8;
        fridge[5] = fridge[5] - 8;
        fridge[6] = fridge[6] - 4;
        fridge[7] = fridge[7] - 3;
    }  else {
        fridge[0] = fridge[0] - 5;
        fridge[3] = fridge[3] - 2;
        fridge[4] = fridge[4] - 6;
        fridge[6] = fridge[6] - 4;
        fridge[7] = fridge[7] - 3;
    }
    return (fridge);
}

int my_check_pizza(int *fridge, char **ingredient)
{
    if (fridge[0] < 5) {
        printf("not enough %s\n", ingredient[0]);
        return (84);
    }
    if (fridge[1] < 1) {
        printf("not enough %s\n", ingredient[1]);
        return (84);
    }
    if (fridge[2] < 3) {
        printf("not enough %s\n", ingredient[2]);
        return (84);
    }
    if (fridge[4] < 8) {
        printf("not enough %s\n", ingredient[4]);
        return (84);
    }
    return (0);
}

int *my_make_pizza(int *fridge, char **ingredient)
{
    if (my_check_pizza(fridge, ingredient) == 84)
        return (fridge);
    if (fridge[5] < 8) {
        printf("not enough %s\n", ingredient[5]);
        return (fridge);
    }
    if (fridge[6] < 4) {
        printf("not enough %s\n", ingredient[6]);
        return (fridge);
    }
    if (fridge[7] < 3) {
        printf("not enough %s\n", ingredient[7]);
        return (fridge);
    }
    fridge = remove_food(fridge, 1);
    return (fridge);
}

int my_check_pasta(int *fridge, char **ingredient)
{
    if (fridge[0] < 5) {
        printf("not enough %s\n", ingredient[0]);
        return (84);
    }
    if (fridge[3] < 2) {
        printf("not enough %s\n", ingredient[3]);
        return (84);
    }
    if (fridge[4] < 6) {
        printf("not enough %s\n", ingredient[4]);
        return (84);
    }
    if (fridge[6] < 4) {
        printf("not enough %s\n", ingredient[6]);
        return (84);
    }
    return (0);
}

int *my_make_pasta(int *fridge, char **ingredient)
{
    if (my_check_pizza(fridge, ingredient) == 84)
        return (fridge);
    if (fridge[7] < 3) {
        printf("not enough %s\n", ingredient[7]);
        return (fridge);
    }
    fridge = remove_food(fridge, 2);
    return (fridge);
}