#ifndef	PIPEX_H
#define PIPEX_H

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
	int		pipe_fd[2];
	char	**arg;
	int		i;
	int		j;
	int		in;
	int		pipex;
	int		lentab;
	char	buf;
	int		indicate;
	char	**env;
	char	**path;
	char	*str_env;
	char	*clean_env;
	char	*str;
	int		file1;
	int		file2;
	char	*cmd1;
	char	*cmd2;
	char	*cmd_to_rotate;
	char	**split_arg1;
	char	**split_arg2;
	int		env_len;
	char	*cmd_path;
} 	t_data;


void	quit_with_message(char	*str);
int		check_file(char	*str, t_data	*data, int n);
int		check_cmd(char	*str, t_data	*data);
void	init_data(t_data	*data);
char	*make_cmd(t_data	*data);

int		check_envp(char	**envp, t_data	*data);
//void	ft_pipex(t_data	*data, char	**envp);
int	ft_pipex(t_data	*data, int	in, char **cmd, char	**envp);
char	*set_env(char *s, t_data	*data);
void	child1_prog(t_data	*data, char	**envp);
void	child2_prog(t_data	*data, char	**envp);

void	make_path(t_data	*data);
char	*add_char(char	*s, t_data	*data);
void	ft_free_split(char	**to_free);
char	*make_cmd_path(char	*str, char	*cmd);
#endif
