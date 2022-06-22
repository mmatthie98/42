/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:25:33 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/22 00:23:09 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_manage(void	*to_add)
{
	static t_list	*manage;

	ft_lstadd_back(&manage, ft_lstnew(to_add));
}
