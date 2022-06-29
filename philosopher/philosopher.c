#include "philo.h"

void	init_data(t_data	*data, char	**av)
{
	(void) av;
	data->nb_of_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->nb_of_time_each_eat = 0;
}

void	print_data(t_data	*data)
{
	printf("data->nb of philo : %d\n", data->nb_of_philo);
	printf("data->time 2 die : %d\n", data->time_to_die);
	printf("data->time 2 eat : %d\n", data->time_to_eat);
	printf("data->time 2 sleep : %d\n", data->time_to_sleep);
	printf("data->nb of time each eat : %d\n", data->nb_of_time_each_eat);
}

void	*start_routine(void	*arg)
{
	int	*i;

	(void) arg;
	i = malloc(sizeof(int));
	i[0] = 42;
	printf("let's goooooo !\n");
	return (i);
}

void	init_philo(t_philo	**ph, t_data	*data)
{
	int	i;

	i = 0;
	ph = malloc(sizeof(t_philo) * data->nb_of_philo);
	if (!ph)
		return ;
	while (i < data->nb_of_philo)
	{
		(*ph)->philo_id = i;
		(*ph)->left_fork = i + 1 % data->nb_of_philo;
		(*ph)->right_fork = i;
		(*ph)->last_meal = 0;
		(*ph)->hungry = 0;
		(*ph)->turn_nb = 0;
		i++;
	}
}

void	init_thread(t_data	*data, t_philo	*ph)
{
	int			i;
	pthread_t	th[data->nb_of_philo];

	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_create(&th[i], NULL, &start_routine, ph) != 0)
			printf("error in thread create\n");
		i++;
	}
	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_join(th[i], NULL);
		i++;
	}
}

t_data	*init_struct()
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		printf("problem in malloc\n");
	return (data);
}

t_philo	*init_struct_ph()
{
	t_philo	*ph;

	ph = malloc(sizeof(t_philo));
	if (!ph)
		printf("problem in malloc\n");
	return (ph);
}

t_mu	*init_mu()
{
	t_mu	*mu;

	mu = malloc(sizeof(t_mu));
	if (!mu)
		printf("problem in malloc\n");
	return (mu);
}

int main(int ac, char	**av)
{
	t_data	*data;
	t_philo	*ph;
	t_mu	*mu;

	data = init_struct();
	ph = init_struct_ph();
	mu = init_mu();
	if (ac > 4 && ac < 7)
	{
		init_data(data, av);
		if (check_the_arg(av, data) == 0)
		{
			if (get_the_arg(av, data) == 0)
			{
				/*if (pthread_mutex_init(&lock, NULL))
				{
					printf("mutex init failed\n");
					return (1);
				}*/
				init_thread(data, ph);
				//init_philo(&ph, data);
			}
		}
		//pthread_mutex_destroy(&lock);
	}
	else
		printf("insert at minimum 4 parameters and not more than 6\n");
	return(0);
}
