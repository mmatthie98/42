#include "pipex.h"

void	make_path(t_data	*data, char	**envp)
{
	int		i;
	char	*str;

	i = 0;
	if (data->env && data->env[i])
	{
		while (data->env && data->env[i])
		{
			str = add_char(data->env[i], data, envp);
			if (!str)
				perror("add_char");
			free (data->env[i]);
			data->env[i] = str;
			i++;
		}
	}
}

char	*add_char(char	*s, t_data	*data, char	**envp)
{
	init_data(data, envp);
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
		else
			return (NULL);
	}
	else if (data->env && data->env[i])
	{
		s = get_it(data->env, cmd, data);
		return (s);
	}
	else
		return (s);
}

char	*get_it(char	**env, char	*cmd, t_data	*data)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	while (env && env[i])
	{
		s = ft_strjoin(data->env[i], cmd);
		if (!s)
			return (NULL);
		if (!access(s, F_OK | X_OK))
			return (s);
		free(s);
		i++;
	}
	return (NULL);
}

//void	bad_command(s)
