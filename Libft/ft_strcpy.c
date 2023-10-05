#include "libft.h"

char    *ft_strcpy(char *a, char *b)
{
    int i;

    i = 0;
    if (!a || !b)
        return(NULL);
    while (b && b[i])
    {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
    return(a);
}