#include "c12.h"

t_list	*ft_list_push_strs(int	size, char	**str)
{
	t_list	*lst;
	t_list	*last_maillon;
	int		i;

	i = 0;
	lst = ft_create_element(str[0]);
	while (++i < size)
	{
		last_maillon = ft_create_element(str[i]);
		last_maillon->next = lst;
		lst = last_maillon;
		i++;
	}
	return (lst);
}

int	ft_strlentab(char	**tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

void	ft_print_split(char	**map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return ;
}
