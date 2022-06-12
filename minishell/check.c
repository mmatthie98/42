#include "minishell.h"

int check_space(char *buffer)
{
	int	i;

	i = 0;
	while(buffer[i])
	{
		if (buffer[i] == ' ' || buffer[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join_arg(char	*first, char	*str, t_data	*data)
{

}

char	*is_simbol(char	*str, int i, t_data	*data)
{
	int	k;
	int	j;
	int	l;

	k = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			k = str[i];
			l = i + 1;
			while (str[++i] != k)
				j++;
			if (str[i] == k)
				data->first = malloc(sizeof(char) * j + 1);
			j = 0;
			while (str[l] && str[l] != k)
			{
				data->first[j] = str[l];
				j++;
				l++;
			}
		}
		if (str[l + 1] == 34 || str[l + 1] == 39)
			data->join = ft_join_arg(data->first, str, data);
	}
	return ();
}

char	**tab_simbol(char	*str)
