/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:38:59 by mmatthie          #+#    #+#             */
/*   Updated: 2022/09/24 21:55:29 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo	*ph)
{
	if (ph->data->die == 0)
	{
		if (ph->philo_id % 2)
		{
			pthread_mutex_lock(&ph->mu->forks[ph->right_fork]);
			print_log(ph, 1);
			pthread_mutex_lock(&ph->mu->forks[ph->left_fork]);
		}
		else
		{
			pthread_mutex_lock(&ph->mu->forks[ph->left_fork]);
			print_log(ph, 1);
			pthread_mutex_lock(&ph->mu->forks[ph->right_fork]);
		}
		print_log (ph, 1);
	}
}

void	drop_fork(t_philo	*ph)
{
	pthread_mutex_unlock(&ph->mu->forks[ph->left_fork]);
	pthread_mutex_unlock(&ph->mu->forks[ph->right_fork]);
}

void	eat(t_philo	*ph)
{
	if (ph->data->die == 0)
	{
		ph->last_meal = take_the_time();
		print_log(ph, 2);
		ph->nb_of_lunch++;
		if (ph->nb_of_lunch == ph->data->nb_of_time_each_eat)
		{
			pthread_mutex_lock(&ph->mu->fed_ph);
			ph->data->nb_ph_fed++;
			pthread_mutex_unlock(&ph->mu->fed_ph);
		}
		time_to_wait(ph->data->time_to_eat);
	}
}

void	sleeping(void	*args)
{
	t_philo	*ph;

	ph = (t_philo *)args;
	if (ph->data->die == 0)
	{
		print_log(ph, 3);
		time_to_wait(ph->data->time_to_sleep);
	}
}

void	thinking(void	*args)
{
	t_philo	*ph;

	ph = (t_philo *)args;
	if (ph->data->die == 0)
		print_log(ph, 4);
}
