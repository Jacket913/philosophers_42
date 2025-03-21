/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:34:29 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/21 20:54:03 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//destroy mutexes while printing an error message
void	destroy_mutexes(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		write(2, str, ft_strlen(str));
	while (i < program->philos[0].number_of_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->write_mutex);
	pthread_mutex_destroy(&program->eat_mutex);
	pthread_mutex_destroy(&program->dead_mutex);
}

//strlen for char *
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//ATOI for argv
int	ft_atoi(const char *nptr)
{
	size_t	nb;
	int		neg;

	nb = 0;
	neg = 1;
	while (*nptr == ' ' || *nptr == '\t'
		|| *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
		neg = -1;
	if (neg == -1 || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (nb * neg);
}

//checks if the philo is dead
int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (*philo->dead)
	{
		pthread_mutex_unlock(philo->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}

//Prints the timestamp, id and string with a mutex lock
void	print_mutex(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_mutex);
	time = get_current_time() - philo->start_time;
	if (id == 0)
		printf("[%zu] %s\n", time, str);
	else if (!is_dead(philo))
		printf("[%zu] %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_mutex);
}
//Prints philo struct and initiated values
/*void	print_philo(t_philo *philo, t_program *program, char *str)
{
	pthread_mutex_lock(philo->write_mutex);
	printf("%s[%zu] Philo {%d}\n", str, \
		get_current_time() - philo->start_time, philo->id);
	printf("	nb_philos: %d\n", philo->number_of_philosophers);
	printf("	time_to_die: %ld\n", philo->time_to_die);
	printf("	time_to_eat: %ld\n", philo->time_to_eat);
	printf("	time_to_sleep: %ld\n", philo->time_to_sleep);
	printf("	max_meals: %d\n",
		philo->number_of_times_each_philosopher_must_eat);
	printf("	eating: %d\n", philo->eating);
	printf("	meals_eaten: %d\n", philo->meals_eaten);
	printf("	last_meal: %zu\n", get_current_time() - philo->last_meal);
	printf("	dead pointer: %p\n", philo->dead);
	printf("	left_fork: %p\n", philo->left_fork);
	printf("	right_fork: %p\n", philo->right_fork);
	printf("	write_mutex: %p\n", philo->write_mutex);
	printf("	eat_mutex: %p\n", philo->eat_mutex);
	printf("	dead_mutex: %p\n", philo->dead_mutex);
	pthread_mutex_unlock(philo->write_mutex);
}*/
