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
	char	**all_av;
	int		i;
	int		j;
	int		in;
	int		pipex;
	int		lentab;
	int		lentab2;
	int		nel;
	int		indicate;
	char	**env;
	char	**envp;
	char	**path;
	char	*str;
	int		file1;
	int		file2;
	int		env_len;
	char	*cmd_path;
	char	**cmd_splited;
}	t_data;

//parsing2.c
void	ft_free_split(char	**to_free);
int		check_envp(char	**envp, t_data	*data);
int		exec_last_cmd(char *last_cmd, int in, t_data	*data);
void	child_process(t_data	*data, int in, int	*fd, char	**cmd_splited);
int		ft_pipex(t_data	*data, int	in, char **cmd, char	**envp);


//parsing.c
void	init_data(t_data	*data, char	**envp);
int		check_file(char	*str, t_data	*data);
char	**get_cmd_split(char	*str, int c, int i,t_data	*data);
void	last_cmd_child(t_data	*data, char	*path_cmd, int in,char	**cmd);

// utils.c

char	*add_char(char	*s, t_data	*data, char	**envp);
void	make_path(t_data	*data, char	**envp);
char	*make_cmd_path(char	*cmd_split, t_data	*data);
int		check_file2(char	*str, t_data	*data);
char	*get_it(char	**env, char	*cmd, t_data	*data);
int		check_access(char	*path);
void	here_doc_mod(char	*str, char	**av,char **envp,t_data	*data);
int		heredoc(char	*str);

#endif
