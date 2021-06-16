/*
** EPITECH PROJECT, 2021
** tool.c
** File description:
** .
*/

#include "./lib/my.h"

char *get_input(char *input)
{
    size_t len = 0;
    ssize_t line_size = 0;
    int loop = 1;
    int nbr = 0;
    int lenght = 0;
    char *good_input = NULL ;

    while (loop == 1) {
        line_size = getline(&input, &len, stdin);
        if (line_size == -1)
            exit (84);
        loop = 0;
    }
    lenght = strlen(input);
    good_input = malloc(sizeof(char) * lenght + 1);
    if (good_input == NULL)
        exit (84);
    strcpy(good_input, input);
    good_input[lenght - 1] = '\0';
    return (good_input);
}

void my_display_fridge(int *fridge)
{
    printf("tomato = %d\n", fridge[0]);
    printf("dough = %d\n", fridge[1]);
    printf("onion = %d\n", fridge[2]);
    printf("pasta = %d\n", fridge[3]);
    printf("olive = %d\n", fridge[4]);
    printf("pepper = %d\n", fridge[5]);
    printf("ham = %d\n", fridge[6]);
    printf("cheese = %d\n", fridge[7]);

}

char **my_ingredient(char **ingredient)
{
    ingredient = malloc(sizeof(char *) * 8);
    if (ingredient == NULL)
        exit (84);
    ingredient[0] = "tomato";
    ingredient[1] = "dough";
    ingredient[2] = "onion";
    ingredient[3] = "pasta";
    ingredient[4] = "olive";
    ingredient[5] = "pepper";
    ingredient[6] = "ham";
    ingredient[7] = "cheese";
    return (ingredient);
}

int *my_add_food(int *fridge, char *input, char **ingredient)
{
    char *food = NULL;
    char *str = NULL;

    str = strdup(input);
    if (check_arg(input, ingredient) == 84) {
        printf("'%s': Invalid operation\n", str);
        return (fridge);
    }
    food = strtok(str, " ");
    food = strtok(NULL, " ");
    my_add_food_helper(ingredient, food, fridge);
    return (fridge);
}

int check_input(char *input, int *fridge, char **ingredient)
{
    if (strcmp(input, "disp fridge") == 0) {
        my_display_fridge(fridge);
        return (1);
    }
    if (strncmp(input, "addToFridge", 11) == 0) {
        my_add_food(fridge, input, ingredient);
        return (1);
    }
    if (strncmp(input, "make", 4) == 0) {
        check_meal(input, fridge, ingredient);
        return (1);
    }
    return (0);
}