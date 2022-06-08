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
	int		lentab;
	char	**env;
	char	**path;
	char	*str;
	int		file1;
	int		file2;
	char	*cmd1;
	char	*cmd2;
	char	*cmd_to_rotate;
	char	**split_arg1;
	char	**split_arg2;
	int		env_len;
	char	*cmd_path1;
	char	*cmd_path2;
	char	**envp;
} 	t_data;


void	quit_with_message(char	*str);
int		check_file(char	*str, char	**envp, t_data	*data);
int		check_cmd(char	*str, t_data	*data);
void	init_data(t_data	*data, char	**envp);
char	*make_cmd(t_data	*data);
void	init_arg(t_data	*data);

int		check_envp(char	**envp, t_data	*data);
int		ft_pipex(t_data	*data, int	in, char	**envp);
char	*set_env(char *s, t_data	*data);
char	*ft_strjoin_pipex(char const *s1, char const *s2);

void	make_path(t_data	*data);
char	*add_char(char	*s, t_data	*data);
void	ft_free_split(char	**to_free);
void	run(t_data	*data, char	**envp);
void	dupnclose(int	*fd, int in, t_data	*data);
void	dupnclose2(int	*fd, t_data	*data);
#endif
