/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocobongo <cocobongo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:28:03 by mmatthie          #+#    #+#             */
/*   Updated: 2023/10/06 11:45:05 by cocobongo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	<stdio.h>
# include	<stdlib.h>
# include	"../../Libft/libft.h"
# include	<unistd.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	<fcntl.h>

typedef struct s_data
{
	int		pipe_fd[2];
	char	**arg;
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
	int		cmd_pos;
}			t_data;

//parsing2.c
int			check_envp(char	**envp, t_data	*data);
int			exec_last_cmd(char *last_cmd, int in, t_data	*data);
void		child_process(t_data *data, int in, int	*fd, char **cmd_splited);
int			ft_pipex(t_data	*data, int in, char **cmd, char	**envp);

//parsing.c
void		init_data(t_data	*data, char	**envp);
int			check_file(char	*str, t_data *data);
char		**get_cmd_split(char	*str, int c, int i, t_data	*data);
int			check_file2(char	*str, t_data	*data);
void		ft_manage(void *toadd);

// utils.c

char		*add_char(char	*s, t_data	*data, char	**envp);
void		make_path(t_data	*data, char	**envp);
char		*make_cmd_path(char	*cmd_split, t_data	*data);
char		*get_it(char	**env, char	*cmd, t_data	*data);
void		last_cmd_child(t_data *data, char *path_cmd, int in, char **cmd);

// utils2.c

void		post_pipex(char	**av, t_data	*data);
int			check_access(char	*path);
void		ft_free_split(char	**to_free);
void		make_cmd(char	**cmd, t_data	*data);

// utils3.c
char		**make_last_cmd(char	*last_cmd);
char		*add_it(char	*s, char	*str, t_data *data, char	**envp);
#endif
