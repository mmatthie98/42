/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:12:52 by mmatthie          #+#    #+#             */
/*   Updated: 2022/03/12 13:10:03 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_max_or_min(char	**map)
{
	int			i;
	long long	j;

	j = 0;
	i = 0;
	if (!map[i])
	{
		printf("map error.\n");
		exit(2);
	}
	while (map[i])
	{
		j = ft_atoll(map[i]);
		if (j < -2147483648 || j > 2147483647)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_get_high(t_list	**a, t_data	*data)
{
	init_struct_2(a, data);
	init_struct_3(a, data);
	init_struct_4(a, data);
	if (data->first > data->second && data->first > data->third\
	&& data->first > data->fourth)
	 	data->pos = 1;
	if (data->second > data->first && data->second > data->third\
	&& data->second > data->fourth)
		data->pos = 2;
	if (data->third > data->first && data->third > data->second\
	&& data->third > data->fourth)
		data->pos = 3;
	if (data->fourth > data->first && data->fourth > data->second\
	&& data->fourth > data->third)
		data->pos = 4;
}

void	ft_get_high_5(t_list	**a, t_data	*data)
{
	init_struct_2(a, data);
	init_struct_3(a, data);
	init_struct_4(a, data);
	init_struct_5(a, data);
	if (data->first > data->second && data->first > data->third\
	&& data->first > data->fourth\
	&& data->first > data->five)
	 	data->pos = 1;
	if (data->second > data->first && data->second > data->third\
	&& data->second > data->fourth\
	&& data->second > data->five)
		data->pos = 2;
	if (data->third > data->first && data->third > data->second\
	&& data->third > data->fourth\
	&& data->third > data->five)
		data->pos = 3;
	if (data->fourth > data->first && data->fourth > data->second\
	&& data->fourth > data->third\
	&& data->fourth > data->third)
		data->pos = 4;
	if (data->five > data->first && data->five > data->second\
	&& data->five > data->third\
	&& data->five > data->fourth)
		data->pos = 5;
}

int ft_isvalid(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}