/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:15:01 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/25 12:16:16 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	check_envp(char	**envp, t_data	*data)
{
	init_data(data);
	if (!envp)
		perror("error");
	while (envp[data->i] && ft_strncmp(envp[data->i], "PATH", 4) != 0)
		data->i++;
	data->env = ft_split(envp[data->i], ':');
	if (!data->env)
		perror("error");
	//ft_print_split(data->env);
	//make_cmd(data);
	return (0);
}

/*void	make_cmd(t_data	*data)
{
	
}*/

/*void	ft_pipex(t_data	*data)
{
	int	fd[2];
	int status;
	pid_t child1;
	pid_t child2;

	init_data(data);
	pipe(fd);
	child1 = fork();
	if (child1 < 0)
		return (perror("error"));
	if (child1 == 0)
		child1_prog(data);
	child2 = fork();
	if (child2 < 0)
		return (perror('error'));
	if (child2 == 0)
		child2_prog(data);
	close(fd[0]);
	close(fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}*/