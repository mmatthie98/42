#include <unistd.h>
#include <stdio.h>

static void    ft_foreach(int  *tab, int   lenght, void    (*f)(int))
{
    int i;

    i = 0;
    while (i < lenght)
    {
        (*f)(tab[i]);
        i++;
    }
}

static void ft_putc(char c)
{
    write(1, &c, 1);
}

static void    ft_putnb(int nb)
{
    if (nb < 0)
    {
        ft_putc('-');
        nb *=-1;
    }
    if (nb >= 0 && nb <= 9)
    {
        ft_putc(nb + 48);
        return ;
    }
    else
        ft_putc(nb % 10 + 48);
    ft_putnb(nb / 10);
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
    int i;
    char   *str;
    size_t     len;

    i = 0;
    str = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    len = ft_strlen(str);
    while (i < 100)
    {
        tab[i] = 0;
        i++;
    }
    i = 0;
    ft_foreach(tab, 100, &ft_putnb);
    write(1, "\n", 1);
    printf("%zu\n", len);
    return (0);
}