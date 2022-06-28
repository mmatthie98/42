#include "philo.h"

void	*routine()
{
	int *i;

	i = 0;
	i = malloc(sizeof(4));
	i[0] = 4;
	printf("Test from threads.\n");
	usleep(1000);
	printf("Ending thread.\n");
	return (i);
}

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

void	init_thread(t_data	*data)
{
	int			i;
	pthread_t	th;

	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_create(&th, NULL, &start_routine, NULL) != 0)
		{
			printf("error in thread create\n");
			return ;
		}
		i++;
	}
}

int main(int ac, char	**av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac > 4 && ac < 7)
	{
		init_data(data, av);
		if (check_the_arg(av, data) == 0)
		{
			if (get_the_arg(av, data) == 0)
			{
				init_thread(data);
				print_data(data);
			}
		}
		//system("leaks philo");
	}
	else
		printf("insert at minimum 4 parameters and not more than 6\n");
	return(0);
}
