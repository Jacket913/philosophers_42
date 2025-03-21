/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:35:01 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/21 20:56:32 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// checks if all philosophers are full
static int	philos_all_fed_check(t_philo *philo)
{
	int	i;
	int	full_of_yummy;
	int	max_soup;

	i = 0;
	full_of_yummy = 0;
	max_soup = philo->number_of_times_each_philosopher_must_eat;
	if (philo[0].number_of_times_each_philosopher_must_eat == -1)
		return (0);
	while (i < philo[0].number_of_philosophers && \
		philo[i].meals_eaten >= max_soup)
	{
		full_of_yummy++;
		i++;
	}
	if (full_of_yummy == philo[0].number_of_philosophers)
	{
		print_mutex(FULL, philo, 0);
		pthread_mutex_lock(philo[0].dead_mutex);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_mutex);
		return (1);
	}
	return (0);
}

// checks if one philosopher is dead from starvation
static int	philo_dead_check(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_mutex);
	if (get_current_time() - philo->last_meal >= philo->time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->eat_mutex), 1);
	pthread_mutex_unlock(philo->eat_mutex);
	return (0);
}

// checks if one of all philosophers is dead
static int	program_dead_check(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		if (philo_dead_check(&philo[i]))
		{
			print_mutex(DEAD, &philo[i], philo[i].id);
			pthread_mutex_lock(philo->dead_mutex);
			*philo->dead = 1;
			pthread_mutex_unlock(philo->dead_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

// monitor logic to check if the philosophers are dead or full
void	*monitor_logic(void *arg)
{
	t_philo		*philos;

	philos = (t_philo *)arg;
	while (1)
		if (program_dead_check(philos) || philos_all_fed_check(philos))
			break ;
	return (arg);
}
