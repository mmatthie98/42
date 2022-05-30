/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:11:24 by mmatthie          #+#    #+#             */
/*   Updated: 2022/05/29 16:01:32 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	init_data(t_data	*data)
{
	data->i = 0;
	data->j = 0;
	data->in = 0;
	data->indicate = 0;
}

/*void	init_cmd(char	**av, t_data	*data)
{
	int	i;
	int	j;
	char	**cmd;

	cmd = NULL;
	i = 2;
	j = 0;
	printf("init_test\n");
	printf("av[i + 1] = %s\n",av[i + 1]);
	while(av[i + 1])
	{
		cmd[j] = data->arg[i]; 
		j++;
		i++;
		printf("data->arg[i] : %s\n", data->arg[i]);
	}
	// need to make a tab of cmd without infile and outfile.
}*/

int		check_file(char	*str, t_data	*data, int n)
{
	init_data(data);
	if (str && str[data->i])
	{
		//check_access(str);
		if (n > 0)
		{
			data->j = open(str, O_RDONLY);
			if (data->j < 0)
				perror("error");
			else
			{
				data->file1 = open(str, O_RDONLY);
				return(data->file1);
			}
		}
		if (n == 0)
		{
			data->file2 = open(str, O_CLOEXEC, O_CREAT, O_DIRECTORY,\
			O_EXCL, O_NOCTTY, O_NOFOLLOW, O_TRUNC);
			return (data->file2);
		}
	}
	return (1);
}

int	main(int ac, char	**av, char	**envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_data(data);
	data->arg = &av[2];
	if (ac == 5)
	{
		if (check_envp(envp, data) == 0)
		{
			if (check_file(av[1], data, 1))
			{
				if (check_file(av[4], data, 0))
				{
					ft_print_split(data->env);
					data->pipex = ft_pipex(data, data->file1, data->arg, envp);
				}
			}
		}
	}
	else
		printf("use 4 parameter pls\n");
	return (0);
}
