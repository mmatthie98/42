/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:11:24 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/08 17:15:46 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	init_data(t_data	*data, char **envp)
{
	if (envp)
		data->envp = envp;
	data->i = 0;
	data->j = 0;
	data->in = 0;
	data->indicate = 0;
}

void	init_arg(t_data	*data)
{
	int	i;
	printf("test\n");
	printf("data->arg : %s\n", data->arg[2]);
	i = 0;
	data->split_arg1 = ft_split(data->arg[2], ' ');
	if (!data->split_arg1)
		perror("split");
	printf("%s",data->split_arg1[0]);
	//ft_print_split(data->split_arg2);
	data->split_arg2 = ft_split(data->arg[3], ' ');
	//ft_print_split(data->split_arg2);
	if (!data->split_arg2)
		perror("split");
}

int		check_file(char	*str, char	**envp, t_data	*data)
{
	init_data(data, envp);
	if (str && str[data->i])
	{
		data->file1 = open(str, O_RDONLY);
		if (!data->file1)
			perror ("error :");
		return(data->file1);
	}
	else
		printf("please use a valide infile\n");
	return (1);
}

int		check_file2(char	*str, char	**envp, t_data	*data)
{
	int		i;

	i = 0;
	init_data(data, envp);
	if (str && str[i])
	{
		data->file2 = open(str, O_RDWR | O_CREAT | O_NOCTTY | \
		O_TRUNC, 0677);
		return (data->file2);
	}
	return (1);
}

int	main(int ac, char	**av, char	**envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_data(data, envp);
	data->arg = av;
	if (ac == 5)
	{
		if (check_envp(envp, data) == 0)
		{
			if (check_file(av[1], envp, data))
			{
				//printf("filename : %s\n fd : %d\n", av[1], data->file1);
				if (check_file2(av[4], envp, data))
				{
					//printf("filename : %s\n fd : %d\n", av[4], data->file2);
					init_arg(data);
					ft_pipex(data, data->file1, envp);
				}
			}
		}
	}
	else
		printf("use 4 parameter pls\n");
	//system("lsof -w -c pipex");
	return (0);
}
