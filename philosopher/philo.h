#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_data
{
	int		nb_of_philo;
	int		time_to_die; // limit before philo die of starving
	int		time_to_eat; // eating duration
	int		time_to_sleep; // sleeping duration
	int		nb_of_time_each_eat; //optionnal nb on time each philo need to eat
	int		indicate; // 0 without optionnal arg | 1 with optionnal arg
}			t_data;

typedef struct s_philo
{
	int	philo;
	int	last_meal;
	int	hungry;
}

// parsing.c
int		check_the_arg(char	**av, t_data	*data);
int		ft_isdigit(int arg);
int		check_the_arg(char	**av, t_data	*data);
int		get_the_arg(char	**av, t_data	*data);
int		ft_atoi(const char *str);
//philosopher.c

//parsing2.c
long long	ft_atoll(const char	*str);
size_t		ft_strlentab(char	**tab);



#endif
