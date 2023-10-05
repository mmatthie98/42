

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr || !str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
