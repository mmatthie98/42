/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:46:09 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/10 14:57:28 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

void	post_pipex(char	**av, t_data	*data)
{
	if (check_file2(av[data->lentab + 1], data))
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

void	make
