#include <unistd.h>

int     ft_for_any(char **tab, int (*f)(char*))
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (f(tab[i]) != '0')
            return (1);
        i++;
    }
    return (0);
}

int main()