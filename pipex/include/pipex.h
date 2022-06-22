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
	char	**split_arg1;
	char	**split_arg2;
	int		env_len;
	char	*cmd_path1;
	char	*cmd_path2;
	char	**envp;
} 	t_data;

//dupnclose
void	dupnclose(int	*fd, int infile, t_data	*data);
void	dupnclose2(int *fd, t_data	*data);
void	run2(t_data	*data, char	**envp);
void	run(t_data	*data, char	**envp);

//utils.c
void	init_len(t_data	*data);
char	*ft_strjoin_pipex(char const *s1, char const *s2);
void	ft_free_split(char	**to_free);

//parsing.c
void	init_data(t_data	*data, char **envp);
void	init_arg(t_data	*data);
int		check_file(char	*str, char	**envp, t_data	*data);
int		check_file2(char	*str, char	**envp, t_data	*data);

//parsing2.c
int		check_envp(char	**envp, t_data	*data);
char	*make_cmd_path(char	*cmd, t_data	*data);
char	*get_good_path(char	*cmd, t_data	*data);
void	get_cmd_path(t_data	*data);
int		ft_pipex(t_data	*data, int	in, char	**envp);



#endif
