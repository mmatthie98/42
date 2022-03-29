#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int *ft_map(int *tab, int lenght, int(*f)(int))
{
    int i;
    int *tab2;

    i = 0;
    tab2 = malloc(sizeof(char) * lenght);
    if (!tab2)
        return (NULL);
    while (i < lenght)
    {
        tab2[i] = f(tab[i]);
        i++;
    }
    return (tab2);
}

static int    ft_putnb(int nb)
{
    int     i;

    i = 0;
    while (i < 100 && nb)
    {
        printf("%d", i);
        i++;
    }
    return (0);
}

size_t  ft_strlen(char  *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main()
{
    int tab[100];
    int *tab2;
    int len;
    char    *str;
    int i;

str = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    len = ft_strlen(str);
    i = 0;
    while (i < 100)
    {
        tab[i] = 0;
        i++;
    }
    i = 0;
    tab2 = ft_map(tab, 100, &ft_putnb);
    printf("\n");
    while (i < 100)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    printf("%d", len);
    return (0);
}