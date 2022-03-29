#include <stdio.h>

int ft_sort_it(int i, int   j)
{
    return (i - j);
}

int ft_is_sort(int  *tab, int lenght, int(*f)(int, int))
{
    int     i;
    int     tmp;
    
    tmp = 0;
    i = 0;
    while (i + 1 < lenght && (i < lenght))
    {
        if (f(tab[i], tab[i + 1] == 0))
            i++;
        else if (tmp == 0 && f(tab[i], tab[i + 1]) < 0)
        {
            tmp = -1;
            i++;
        }
        if (((i + 1 < lenght) && ((f)(tab[i], tab[i + 1]) < 0 && tmp > 0))\
        ||  (f(tab[i], tab[i + 1]) > 0 && tmp < 0))
            return (0);
        i++;
    }
    return (1);
}