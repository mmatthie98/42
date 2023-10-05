/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:56:34 by mmatthie          #+#    #+#             */
/*   Updated: 2022/09/25 14:40:38 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char	**av)
{
	t_data	data;
	t_mu	mu;
	t_philo	*ph;

	if (ac >= 5 && ac <= 6)
	{
		if (get_the_arg(av, &data) == 0)
		{
			if (check_the_arg(av) == 0)
			{
				ph = malloc(sizeof(t_philo) * ft_atoi(av[1]));
				if (!ph)
					return (my_error("ph issue's\n", 1));
				init_philo(ph, &data, &mu);
				init_mu(ph, &mu);
				init_thread(ph);
				destroy_mu(ph);
			}
		}
	}
	else
		printf("insert at minimum 4 parameters and not more than 5\n");
	return (0);
}
