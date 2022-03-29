#ifndef C12_H
#define C12_H

typedef struct	s_list
{
	void	*content;
	struct s_list	*next;
}t_list;

# include <stdlib.h>
# include <stdio.h>

void	ft_push_front(t_list	**begin, void	*content);
t_list	*ft_create_element(void	*content);
int	ft_lst_size(t_list	*lst);
t_list	*ft_lstlast(t_list	*lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_print_list(t_list	*lst);
t_list	*ft_list_push_strs(int	size, char	**str);
char	**ft_split(char const	*s, char c);
int	ft_strlentab(char	**tab);
void	ft_print_split(char	**map);
#endif