/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:12:52 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/08 10:06:31 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_max_or_min(char	**map)
{
	int			i;
	long long	j;

	j = 0;
	i = 0;
	while (map && map[i])
	{
		j = ft_atoll(map[i]);
		if (j < -2147483648 || j > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

void	ft_get_low(t_data	*data)
{
	if (data->first < data->second && data->first < data->third\
	&& data->first < data->fourth)
	 	data->pos_small = 1;
	if (data->second < data->first && data->second < data->third\
	&& data->second < data->fourth)
		data->pos_small = 2;
	if (data->third < data->first && data->third < data->second\
	&& data->third < data->fourth)
		data->pos_small = 3;
	if (data->fourth < data->first && data->fourth < data->second\
	&& data->fourth < data->third)
		data->pos_small = 4;
}

void	ft_get_low_5(t_data	*data)
{
	if (data->first < data->second && data->first < data->third\
	&& data->first < data->fourth\
	&& data->first < data->five)
	 	data->pos = 1;
	if (data->second < data->first && data->second < data->third\
	&& data->second < data->fourth\
	&& data->second < data->five)
		data->pos = 2;
	if (data->third < data->first && data->third < data->second\
	&& data->third < data->fourth\
	&& data->third < data->five)
		data->pos = 3;
	if (data->fourth < data->first && data->fourth < data->second\
	&& data->fourth < data->third\
	&& data->fourth < data->third)
		data->pos = 4;
	if (data->five < data->first && data->five < data->second\
	&& data->five < data->third\
	&& data->five < data->fourth)
		data->pos = 5;
}

/*void	ft_get_low_5(t_list	**a, t_data	*data)
{
	t_list *pt;
	int *tmp;

	pt = *a;
	data->index = 0;
	if (pt && pt->next != NULL)
	{
		tmp = (int *)pt->content;
		data->max_value = *tmp;
		data->pos = data->index;
		while (pt->next)
		{
			data->index++;
			pt = pt->next;
			if (*tmp > *(int *)pt->content)
			{
				tmp = pt->content;
				data->max_value = *tmp;
				printf("data max value in get low %d\n", data->max_value);
				data->pos = data->index;
			}
		}
		data->index = 0;
	}
}*/

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

void	quit_with_message(int	n)
{
	if (n == 1)
	{
		write(2, "Error.\nonly used allowed int.\n", 30);
		exit(2);
	}
	if (n == 2)
	{
		write(2, "Error.\nonly used valid int.\n", 29);
		exit(2);
	}
	if (n == 3)
	{
		write(2, "Error.\ndon't use int in double.\n", 32);
		exit(2);
	}
}
