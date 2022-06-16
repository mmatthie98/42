#include "libft.h"

static	make_it(char	*str, char	*str2)
{
	int	i;

	i = -1;
	while (str2[++i])
		str[i] = str2[i];
	str[i] = '\0';
}


char	**ft_lst2dpt(t_list	*lst)
{
	int	len;
	int	len_node;
	char	**tab;
	int	i;

	len = ft_lstsize(lst);
	tab = malloc(sizeof(char *) * len + 1);
	i = 0;
	if (!tab)
	{
		ft_putstr_fd("lst2dpt error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (lst)
	{
		len_node = ft_strlen((char *)lst->content);
		tab[i] = malloc(sizeof(char) * len_node + 1);
		make_it(tab[i], lst->content);
		lst = lst->next;
		i++;
	}
}
