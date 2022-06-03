#include "pipex.h"

void	make_path(t_data	*data)
{
	int		i;
	char	*str;

	i = 0;
	if (data->env && data->env[i])
	{
		while (data->env && data->env[i])
		{
			str = add_char(data->env[i], data);
			if (!str)
				perror("add_char");
			free (data->env[i]);
			data->env[i] = str;
			i++;
		}
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

char	*make_cmd_path(char	*cmd, t_data	*data)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 1;
	s = NULL;
	if (cmd[0] == '/')
	{
		if (!access(cmd, F_OK | X_OK))
			return (cmd);
		return (NULL);
	}
	while (cmd && cmd[i])
	{
		while (data->env[i])
		{
			s = ft_strjoin(data->env[i], cmd);
			if (!s)
				return (NULL);
			j = access(s, F_OK | X_OK);
			if (j == -1)
			{
				free(s);
				i++;
			}
			else
				return (s);
		}
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
	}
	return (NULL);
}

/*char	*make_cmd_path(char	*cmd, t_data	*data)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 1;
	s = NULL;
	if (cmd)
	{
		while (data->env[i])
		{
			s = ft_strjoin(data->env[i], cmd);
			if (!s)
				return (NULL);
			j = access(s, F_OK | X_OK);
			if (j == -1)
			{
				free(s);
				i++;
			}
			else
				return (s);
		}
	}
	if (!data->env && access(s, X_OK | F_OK) == 1)
	{
		if (access(cmd, X_OK | F_OK) == 0)
		{
			free (s);
			return (cmd);
		}
	}
	return (s);
}
*/
