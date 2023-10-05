/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:39:46 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/24 23:34:10 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	make_path(t_data	*data, char	**envp)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (data->env && data->env[i])
	{
		while (data->env && data->env[i])
		{
			str = add_char(data->env[i], data, envp);
			ft_manage(str);
			if (!str)
				str = NULL;
			free (data->env[i]);
			data->env[i] = str;
			i++;
		}
	}
}

char	*add_char(char	*s, t_data	*data, char	**envp)
{
	char	*str;

	init_data(data, envp);
	while (s[data->j])
		data->j++;
	data->j += 1;
	str = malloc(sizeof(char) * data->j + 1);
	if (!str)
		str = NULL;
	str = add_it(s, str, data, envp);
	return (str);
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
			return (ft_strdup(cmd));
		else
			return (ft_strdup("/"));
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
		if (access(s, F_OK | X_OK) == -1)
		{
			free(s);
			i++;
		}
		else
			return (s);
	}
	return (NULL);
}

void	last_cmd_child(t_data	*data, char	*path_cmd, int in, char	**cmd)
{
	dup2(in, 0);
	dup2(data->file2, 1);
	close(data->file2);
	close(in);
	if (execve(path_cmd, cmd, data->envp) == -1)
		ft_putstr_fd("zsh : command not found\n", 2);
	exit(EXIT_FAILURE);
}
