#include "minishell.h"

int	ft_isspace(int c)
{
	if (((c == '\n') || (c == '\v') || (c == '\t')) \
	|| ((c == '\r') || (c == '\f') || (c == ' ')))
		return (1);
	return (0);
}

t_list *ft_get_first_args(char	*buffer, t_data	*data)
{
	int len;
	t_list	*li;

	len = ft_strlen(buffer);
	li = NULL;
	data->count = 0;
	while (data->count < len)
	{
		if (buffer && buffer[data->count])
		{
			while (ft_isspace(buffer[data->count]))
				data->count++;
			if (buffer[data->count] != '\'' && buffer[data->count] != '"' && buffer[data->count] != '\0' && buffer[data->count] != ' ')
			{
				data->count = get_word(buffer, data);
				li = ft_lstnew(data->get_word);
				//free(data->get_word);
				return(li);
			}
			else if ((buffer[data->count] == '\'' || buffer[data->count] == '"'))
			{
				data->count = get_quotes(buffer, data, buffer[data->count]);
				li = ft_lstnew(data->get_word);
				//free(data->get_word);
				return (li);
			}
			data->count++;
		}
	}
	return(li);
}

int	get_quotes(char	*buffer, t_data	*data, int quotes)
{
	int	j;
	int	k;

	data->count++;
	j = data->count;
	k = data->count;
	while (buffer[data->count] != quotes && buffer[data->count] != '\0')
	{
		j++;
		data->count++;
	}
	data->get_word = malloc(sizeof(char) * j);
	if (!data->get_word)
	{
		ft_putstr_fd("error malloc\n", 2);
		return(-1);
	}
	j = 0;
	while (buffer[k] != quotes && buffer[k] != '\0')
	{
		data->get_word[j] = buffer[k];
		j++;
		k++;
	}
	data->get_word[j] = '\0';
	return(k + 1);
}


/*void	add_to_lst(t_list	**lst, char	*buffer, t_data	*data, t_list	*new_arg)
{
	new_arg = ft_get_args(buffer, data);
	ft_lstadd_back(lst, new_arg);
}*/

int	get_word(char	*buffer, t_data	*data)
{
	int	j;
	int	k;

	k = 0;
	j = data->count;
	while (buffer[data->count] != 34 && buffer[data->count] != 39 && buffer[data->count] != '\0' && buffer[data->count] != ' ')
	{
		j++;
		data->count++;
	}
	data->get_word = malloc(sizeof(char) * j + 1);
	if (!data->get_word)
	{
		ft_putstr_fd("error malloc\n", 2);
		return(-1);
	}
	j = 0;
	while (buffer[j] != 34 && buffer[j] != 39 && buffer[j] != '\0' && buffer[j] != ' ')
	{
		data->get_word[k] = buffer[j];
		k++;
		j++;
	}
	data->get_word[j] = '\0';
	return(j);
}