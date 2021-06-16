/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int my_getnbr(char const *str);
int my_diff(char letter, int key);
char *my_decrypter(char *file, int key);
char my_small_letter(char letter, int key);
char my_capital_letter(char letter, int key);
char *read_file(char *filepath);
void file_creating(char *str);
int err_handling(int ac, char *av[]);
char *get_input(char *input);
int check_input(char *input, int *fridge, char **ingredient);
void my_display_fridge(int *fridge);
char **my_ingredient(char **ingredient);
int *my_make_pizza(int *fridge, char **ingredient);
int *my_make_pasta(int *fridge, char **ingredient);
int check_arg(char *input, char **ingredient);
void create_not_existing_file(int *amount);
void read_from_existing_file(char **str);
int check_if_file_correct(char **str);
int check_if_file_helper(char **str, int i, int spaces);
void check_if_right_ingredients(char **str);
int check_if_int(char *str);
void create_open_file(int *amount);
void save_file(int *amount);
void free_str_file(char **str);
void my_add_food_helper(char **ingredient, char *food, int *fridge);
int check_meal(char *input, int *fridge, char **ingredient);