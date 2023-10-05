/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:59:16 by mmatthie          #+#    #+#             */
/*   Updated: 2022/06/10 23:21:06 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

char	**make_last_cmd(char	*last_cmd)
{
	char	**cmd;

	cmd = NULL;
	if (last_cmd && last_cmd[0])
		cmd = ft_split(last_cmd, ' ');
	else
	{
		last_cmd = ft_strdup(" /");
		cmd = ft_split(last_cmd, ' ');
		free(last_cmd);
	}
	return (cmd);
}
