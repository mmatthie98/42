#include "libft.h"

size_t  ft_strlentab(char   **tab)
{
    int i;

    i = 0;
    if (!tab)
        return(i);
    while (tab && tab[i])
        i++;
    return(i);
}