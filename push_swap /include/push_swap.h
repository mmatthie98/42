/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:09:15 by mmatthie          #+#    #+#             */
/*   Updated: 2022/04/22 19:05:39 by mmatthie         ###   ########.fr       */
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
	int				i;
	int				j;
	size_t			maplen;
	int				**tab;
	int				**tab_copy;
	int				max_value;
	int				binary_size;
}	t_data;

//rotate.c

void	ft_PA(t_list	**a, t_list	**b);
void	ft_reverse_rotate(t_list	**a);
void	ft_rotate(t_list	**a);
void	ft_PB(t_list	**a, t_list	**b);
void	SA(t_list	**a);

//rotate2.c

void	ft_sort_5(t_list	**a, t_list	**b, t_data	*data);
int		ft_is_negative(char	**map);
int		ft_number(char	str);

// init.c
void	init_struct_3(t_list	**a, t_data	*data);
void	init_struct_4(t_list	**a, t_data	*data);
void	init_struct_5(t_list	**a, t_data	*data);
void	init_struct_2(t_list	**a, t_data	*data);
void	init_data(t_data	*data);

// low_sort.c
int		ft_map_is_sort(t_data	*data);
void	ft_sort_4(t_list	**a, t_list	**b, t_data	*data);
void	small_sort(t_list	**a, t_data	*data);
void	ft_low_sort(t_list	**a,t_list	**b, t_data	*data);

// low_sort2.c
void	ft_sort_2(t_list	**a, t_data	*data);
void	ft_sort_3(t_list	**a, t_data	*data);
void	ft_sort_for_4(t_list	**a, t_list	**b, t_data	*data);
void	sort_for_5(t_list	**a, t_list	**b, t_data	*data);

// parsing.c
int		parse(char	**map);
char	**split_multiple_param(char **tab, t_data	*data);
t_list	*make_a(char	**map);
void	ft_post_radix(t_data *data,t_list **lst, t_list	**stack_b);

//parsing2.c
void	quit_with_message(int n);
int		ft_isvalid(char *str);
void	ft_get_low_5(t_data	*data);
void	ft_get_low(t_data	*data);
int		is_max_or_min(char  **map);

// make_int_tab.c

void	make_int_tab(t_data	*data);
void	make_copy_int_tab(t_data	*data);
void	ft_get_binary_size(t_data	*data, int	nb);
void	ft_binary_move(t_data	*data, t_list	**a, t_list	**stack_b);
void	ft_make_it(t_list	*a, t_list	*stack_b);
int		ft_check_sort(t_list	*lst);

#endif
