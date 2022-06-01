#include "pipex.h"

void	make_path(t_data	*data)
{
	int		i;
	char	*str;

	i = 0;
	while (data->env[i])
	{
		str = add_char(data->env[i], data);
		if (!str)
			perror("add_char");
		free (data->env[i]);
		data->env[i] = str;
		i++;
	}
}

char	*add_char(char	*s, t_data	*data)
{
	init_data(data);
	int		k;
	char	*str;

	while (s[data->j])
		data->j++;
	data->j += 1;
	str = malloc(sizeof(char) * data->j + 1);
	if (!str)
		perror("malloc error\n");
	data->j = 0;
	k = 0;
	while (s[data->j])
	{
		if (s[data->j + 1] == '\0')
		{
			str[k] = s[data->j];
			str[k + 1] = '/';
			str[k + 2] = '\0';
			data->j++;
		}
		else
		{
			str[k] = s[data->j];
			data->j++;
			k++;
		}
	}
	return(str);
}

void	init_len(t_data	*data)
{
	data->lentab = ft_strlentab(data->arg);
	data->env_len = ft_strlentab(data->env);
}
/*
char	**make_cmd_path(t_data	*data)
{

}*/
