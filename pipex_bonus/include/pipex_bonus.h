#ifndef	PIPEX_BONUS_H
#define PIPEX_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include "../../libft/libft.h"
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_data
{
	char	**arg;
	int		i;
	int		j;
	int		lentab;
	char	buf;
	char	**map;
	int		indicate;
	char	**env;
	char	*str;
} 	t_data;


void	quit_with_message(char	*str);
int		open_fail(int	i, t_data	*data);
void	quit_with_message(char	*str);
int		check_file(char	*str, t_data	*data, int n);
int		check_cmd(char	*str, t_data	*data);
void	init_data(t_data	*data);

int		check_envp(char	**envp, t_data	*data);
#endif