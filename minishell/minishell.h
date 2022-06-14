#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data
{
	char	*first;
	char	*second;
	char	*join;
	char	*get_word;
	int		count;
	int		indicate;
}				t_data;



int	    check_space(char *buffer);
t_list  *create_list(char **buffer_splited);
void	ft_print_list(t_list	*lst);
t_list	*ft_get_first_args(char	*buffer, t_data	*data);
int		get_quotes(char	*buffer, t_data	*data, int quotes);
int		get_word(char	*buffer, t_data	*data);
t_list	*ft_get_all_args(char	*buffer, t_data	*data);
void	add_to_lst(t_list	**lst, char	*buffer, t_data	*data, t_list	*new_arg);
#endif
