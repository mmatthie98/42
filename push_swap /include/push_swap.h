/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:15 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/08 10:06:47 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "../../libft/libft.h"

typedef struct s_data
{
	char			**map;
	int				first;
	int				second;
	int				third;
	int				fourth;
	int				five;
	int				pos;
	int				size;
	int				index;
	int				pos_small;
}	t_data;

//rotate.c

void	ft_PA(t_list	**a, t_list	**b);
void	ft_reverse_rotate(t_list	**a);
void	ft_rotate(t_list	**a);
void	ft_PB(t_list	**a, t_list	**b);
void	SA(t_list	**a);

//rotate2.c

void	ft_sort_5(t_list	**a, t_list	**b, t_data	*data);

// init.c
void	init_struct_3(t_list	**a, t_data	*data);
void	init_struct_4(t_list	**a, t_data	*data);
void	init_struct_5(t_list	**a, t_data	*data);
void	init_struct_2(t_list	**a, t_data	*data);

// low_sort.c
int		ft_is_sort(t_list	**a, t_data	*data);
void	ft_sort_4(t_list	**a, t_list	**b, t_data	*data);
void	small_sort(t_list	**a, t_data	*data);
void	ft_low_sort(t_list	**a,t_list	**b, t_data	*data);
void	ft_sort_it(t_list	**a, t_data	*data);

// low_sort2.c
void	ft_sort_2(t_list	**a, t_data	*data);
void	ft_sort_3(t_list	**a, t_data	*data);
void	ft_sort_for_4(t_list	**a, t_list	**b, t_data	*data);
void	sort_for_5(t_list	**a, t_list	**b, t_data	*data);

// parsing.c
int		parse(char	**map);
char	**split_multiple_param(char  **tab);
t_list	*make_a(char	**map);

//parsing2.c
void	quit_with_message(int n);
int		ft_isvalid(char *str);
void	ft_get_low_5(t_data	*data);
void	ft_get_low(t_data	*data);
int		is_max_or_min(char  **map);

#endif
