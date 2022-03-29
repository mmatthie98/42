/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:27 by mmatthie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/29 15:50:35 by mmatthie         ###   ########.fr       */
=======
/*   Updated: 2022/03/12 13:09:56 by mmatthie         ###   ########.fr       */
>>>>>>> e5039f02b7fb641a9c8f999ed8518ce1eef8a494
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int     check_double(char   **map)
{
    int     i;
    int     j;

    i = 0;
    j = i + 1;
    while (map[i])
    {
        j = i + 1;
        while (map[j])
        {
            if (ft_atoi(map[i]) == ft_atoi(map[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int parse(char    **map)
{
	int	i;
    int     j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!is_max_or_min(map))
            {
                printf("do not excess int min and max please.\n");
                return (1);
            }
            if (!ft_isvalid(map[i]))
            {
                printf("error, please ONLY put int to param's.\n");
                return (2);
            }
            if (check_double(map))
            {
                printf("please, do not enter a duplicate.\n");
                return (3);
            }
            j++;;
        }
        i++;
    }
    return (0);
}

char    **split_multiple_param(char  **tab)
{
    char    str[100000];
    char    **map;
    int     i;
    int     y;
    int     z;

    i = 0;
    y = -1;
    z = -1;
    map = NULL;
    while (tab[++i])
    {
        while (tab[i][++y])
            str[++z] = tab[i][y];
        str[++z] = ' ';
        y = -1;

    }
    map = ft_split(str, ' ');
    if (!map)
        return (NULL);
    return (map);
}

t_list  *make_a(char   **map)
{
	int	i;
    t_list *a;

    i = 0;
	a = ft_lstnew(map[i]);
    while (map[++i])
        ft_lstadd_back(&a, ft_lstnew(map[i]));
	return (a);
}

int main(int ac, char   **av)
{
	t_list	*lst;
	t_list	*stack_b;
	t_data	*data;

	stack_b = NULL;
	data = malloc(sizeof(t_data));
	if (ac > 1)
	{
		data->map = split_multiple_param(av);
        if (!data->map)
            return (1);
		if (!parse(data->map))
		{
			lst = make_a(data->map);
            data->size = ft_lstsize(lst);
            if (data->size < 6 && ft_is_sort(&lst))
            {
                ft_low_sort(&lst, &stack_b, data);
                ft_print_list(lst);
<<<<<<< HEAD
				system("leaks push_swap");
=======
>>>>>>> e5039f02b7fb641a9c8f999ed8518ce1eef8a494
            }
            if (data->size > 5)
            {
                ft_sort_it(&lst);
            }
        }
    }
	return (0);
}
