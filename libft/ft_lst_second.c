/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:33:01 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/31 18:01:15 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lst_second(t_list	**a)
{
	t_list	*tmp;

	tmp = *a;
	if ((*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = NULL;
		*a = tmp;
	}
	return (tmp);
}
/*
int main()
{
	void	*content;
	void	*content2;
	void	*content3;
	t_list	*lst;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*new_list;

	content = "42";
	content2 = "442";
	content3 = "4442";
	lst = ft_lstnew(content);
	lst2 = ft_lstnew(content2);
	lst3 = ft_lstnew(content3);
	ft_lstadd_back(&lst, lst2);
	ft_lstadd_back(&lst, lst3);
	printf("list entiere :\n");
	ft_print_list(lst);
	printf("lst a partir du 2eme maillon\n");
	new_list = ft_lst_second(&lst);
	ft_print_list(new_list);
	return (0);
}*/
