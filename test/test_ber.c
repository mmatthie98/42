#include <stdio.h>

size_t ft_strlen(char   *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (0);
}


int ft_strncmp(char   *s1, char  *s2, size_t n)
{
    size_t i;
    unsigned char   str1;
    unsigned char   str2;

    i = 0;
    while (i < n && (s1[i] || s2[i]))
    {
        str1 = (unsigned char)s1[i];
        str2 = (unsigned char)s2[i];
        if (str1 != str2)
            return (1);
        i++;
    }
    return (0);
}

int ft_check_ber(char   *filename)
{
    char    *str;
	int		i;

	i = 0;
	while (filename[i] && filename[i] != '.')
		i++;
	if (filename[i])
		str = filename + i;
	else
        return (0);
    if (ft_strncmp(str, ".ber", ft_strlen(str)))
        return (0);
    else
        return (1);
    return (1);
}

int main(int ac, char   **av)
{
    if (ac == 2 && ft_check_ber(av[1]))
    {
        printf("it's okey.\n");
        return (0);
    }
    else
        printf("it`s not ok.\n");
    return (1);
}