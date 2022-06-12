/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:07:48 by tbrandt           #+#    #+#             */
/*   Updated: 2022/06/12 18:51:19 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char *buffer = NULL;
	char **buffer_splited;
	t_list *cmd;
	int	i;

	i = 0;

	while(1)
	{
		buffer = readline(">$ ");
		
		add_history(buffer);
	}
	free(buffer);
	return (0);
}
