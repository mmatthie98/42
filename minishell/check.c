#include "minishell.h"

int	ft_isspace(int c)
{
	if (((c == '\n') || (c == '\v') || (c == '\t')) \
	|| ((c == '\r') || (c == '\f') || (c == ' ')))
		return (1);
	return (0);
}

void	make_join(t_data	*data)
{
	data->join = ft_strjoin(data->first, data->second);
	if (!data->join)
	{
		ft_putstr_fd("error in make_join\n", 2);
		exit(EXIT_FAILURE);
	}
	data->first = ft_calloc(1, ft_strlen(data->join));
	data->first = ft_strncpy(data->first, data->join, ft_strlen(data->join));
}

int	pre_join(char	*str,t_data	*data, int count)
{
	int	tmp;
	int	lenfirst;
	int	j;

	j = 0;
	lenfirst = count;
	if (str[lenfirst] == '"' || str[lenfirst] == '\'')
	{
		tmp = str[lenfirst];
		lenfirst += 1;
		while (str[lenfirst] != tmp && str[lenfirst] != '\0')
		{
			lenfirst++;
			j++;
		}
		data->second = ft_calloc(1, j);
		j = -1;
		while (str[++count] != tmp && str[count] != '\0')
			data->second[++j] = str[count];
		data->second[count] = '\0';
		make_join(data);
	}
	return(count + 1);
}

int	get_word(char	*str, t_data *data , int count)
{
	int	i;
	int	j;

	i = 0;
	j = count;
	while (str[j] != '"' && str[j] != '\'' && str[j] != '\0' && str[j] != ' ')
	{
		j++;
		i++;
	}
	data->first = ft_calloc(1, i);
	data->first = ft_strncpy(data->first, &str[count], i);
	data->first[i + 1] = '\0';
	if (str[j] == '"' || str[j] == '\'')
		j = pre_join(str, data, j);
	count = j;
	data->get_word = ft_calloc(1, i);
	data->get_word = ft_strncpy(data->get_word, data->first, ft_strlen(data->first));
	data->get_word[ft_strlen(data->first)] = '\0';
	free(data->first);
	return (count);
}
