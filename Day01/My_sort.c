
#include "./include/my.h"


void sort_stuff(char **str)
{
    char *tmp = NULL;
    int j = 0;
    int i = 0;

    while (j != i) {
        j = 0;
        for (i = 0; str[i] != NULL; i++) {
            if (strcmp(str[i], str[i + 1]) > 0) {
                tmp = strdup(str[i]);
                str[i] = strdup(str[i + 1]);
                str[i + 1] = strdup(tmp);
            } else
                j++;
        }
    }
}