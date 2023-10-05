#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int  ft_strlentab(char  **tab)
{
    int  i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

int ft_count_if(char    **tab, int lenght, int(*f)(char*))
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < lenght)
    {
        if (f(tab[i]) != 0)
            j++;
        i++;
    }
    return (j);
}

int     ft_putstr(char *str)
{
    int i;
    
    i = -1;
    if (str[++i] == 0)
    {
        return (1);
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

char    *ft_strcpy(char *src, char  *dest)
{
    int     j;
    int     i;

    j = 0;
    dest = malloc(sizeof(char) * ft_strlen(src) + 1);
    if (!dest)
        return (NULL);
    i = -1;
    while (src[++i])
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int main()
{
    char    *tab[100];
    char    *src;
    int i;

    src = "allo";
    i = 0;
    while (i < 100)
    {
        tab[i] = 0;
        i++;
    }
    i = 0;
    ft_count_if(tab, 100, &ft_putstr);
    while (tab[i] == NULL)
    {

        printf("%s\n", tab[i]);
        i++;
    }
    printf("voici le nombre de d'éléments qui sont différents de 0 = %d\n", ft_count_if(tab, 100, &ft_putstr));
    return (0);
}