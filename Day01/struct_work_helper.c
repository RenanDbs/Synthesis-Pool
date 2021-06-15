/*
** EPITECH PROJECT, 2021
** struct_work_helper.c
** File description:
** .
*/

#include "./include/my.h"

int my_is_nbr(char *str)
{
    printf("STR = %s\n", str);
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < '0' || str[i] > '9'){
            printf("SHEESH");
            return (0);
        }
    }
    return (1);
}

void check_data(char **end_table)
{
    if (end_table[0] == NULL) {
        write(2, "Missing 'Name' Data\n", 20);
        exit(84);
    }
    if (end_table[1] == NULL || my_is_nbr(end_table[1]) == 0) {
        write(2, "Missing 'Attack' Data\n", 20);
        exit(84);
    }
    if (end_table[2] == NULL || my_is_nbr(end_table[2]) == 0) {
        write(2, "Missing 'Defense' Data\n", 23);
        exit(84);
    }
    if (end_table[3] == NULL || my_is_nbr(end_table[3]) == 0) {
        write(2, "Missing 'Speed' Data\n", 21);
        exit(84);
    }
    if (end_table[4] == NULL) {
        write(2, "Missing 'Health' Data\n", 22);
        exit(84);
    }
}
