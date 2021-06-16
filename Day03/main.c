/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main.c
*/

#include "./lib/my.h"

int my_fridge_loop(int *fridge, char **ingredient)
{
    int loop = 1;
    char *input = NULL;

    while (loop == 1) {
        input = get_input(input);
        if (strcmp(input, "exit") == 0)
            loop = 0;
        else if (check_input(input, fridge, ingredient) == 0)
            printf("'%s': Invalid operation\n", input);
    }
    free(input);
    return (0);
}

int main(int ac, char **av)
{
    int *fridge = NULL;
    char **ingredient = NULL;

    ingredient = my_ingredient(ingredient);
    if (ac != 1)
        return (84);
    fridge = malloc(sizeof(int) * 8);
    if (fridge == NULL)
        exit (84);
    create_open_file(fridge);
    my_fridge_loop(fridge, ingredient);
    save_file(fridge);
    free(fridge);
    return (0);
}