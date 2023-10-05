/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:46:09 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/22 00:02:05 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	post_pipex(char	**av, t_data	*data)
{
	if (check_file(av[1], data))
	{
		if (check_envp(data->envp, data) == 0)
		{
			data->cmd_pos = 0;
			ft_pipex(data, data->file1, data->arg, data->envp);
		}
	}
}

int	check_access(char	*path)
{
	return (access(path, F_OK | X_OK));
}

void	ft_free_split(char	**to_free)
{
	size_t	i;

	i = 0;
	if (!to_free)
		return ;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

void	make_cmd(char	**cmd, t_data	*data)
{
	data->cmd_path = NULL;
	if (cmd[0])
		data->cmd_splited = ft_split(cmd[0], ' ');
	if (data->cmd_splited && data->cmd_splited[0])
		data->cmd_path = make_cmd_path(data->cmd_splited[0], data);
	else
		data->cmd_path = ft_strdup(" /");
}

char	*add_it(char	*s, char	*str, t_data *data, char	**envp)
{
	int	k;

	k = 0;
	init_data(data, envp);
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
	return (str);
}
