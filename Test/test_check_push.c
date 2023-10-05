#include <stdio.h>
#include <stdlib.h>

int     check_double(int   **map)
{
    int     i;
    int     j;

    i = 0;
    j = 1;
    while (map[i])
    {
        j = 0;
        while (map[j])
        {
            if (map[i] == map[j])
            {
                printf("it's not ok.\n");
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int main (int ac, char  **av)
{
    int     i;

    i = 0;
    if (ac > 0)
    {
        if (!check_double())
        {
            printf("it's not ok.\n");
        }
    }
    else
        printf("pls enter some int.\n");
    return (0);
}