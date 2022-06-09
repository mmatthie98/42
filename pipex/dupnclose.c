/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupnclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:32:51 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/09 16:43:01 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dupnclose(int	*fd, int infile, t_data	*data)
{
	init_data(data, data->envp);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close (infile);
	close (fd[1]);
	close (fd[0]);
	//close (data->file2);
}

void	dupnclose2(int *fd, t_data	*data)
{
	dup2(fd[0], 0);
	//dup2(data->file2, 1);
	close (fd[0]);
	close (data->file2);
}

void	run2(t_data	*data, char	**envp)
{
	if (execve(data->cmd_path1, data->split_arg1, envp) == -1)
	{
		ft_putstr_fd("zsh : command not found\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	run(t_data	*data, char	**envp)
{
	if (execve(data->cmd_path2, data->split_arg2, envp) == -1)
	{
		ft_putstr_fd("zsh : command not found\n", 2);
		exit(EXIT_FAILURE);
	}
}
