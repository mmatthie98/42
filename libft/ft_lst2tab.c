/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:33:09 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/31 18:01:15 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	**ft_lst2tab(t_list	*lst, t_list	*data)
{
	char	**tab;
	int		i;

	i = -1;
	while (data->size > 0)
	{
		tab = malloc(sizeof(t_list));
		if (!tab)
			return (NULL);
		while (++i)
			tab[i] = lst->content;
		data->size--;
	}
	return (tab);
}

/*int main()
{
	t_list	*lst;
	void	*content;
	char	**map;

	content = "42";
	lst = ft_lstnew(content);
	printf("avant.\n");
	printf("lst : %s\n", lst->content);
	//printf("tab : %s\n", map[0]);
	printf("après.\n");
	map = ft_lst2tab(lst, lst);
	printf("lst : %s\n", lst->content);
	//printf("tab : %s", map[1]);
	return (0);
}*/
