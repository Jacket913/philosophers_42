/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoulin <kmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:37:49 by kmoulin           #+#    #+#             */
/*   Updated: 2025/03/24 22:39:52 by kmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//helper to avoid deadlocks in eating()
static void	deadlock_forks(t_philo *philo, pthread_mutex_t **first_fork,
	pthread_mutex_t **second_fork)
{
	if (philo->id % 2 == 0)
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
	else
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
}

//update philo meal in eating()
static void	update_philo_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_mutex);
	philo->eating = 1;
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->eat_mutex);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(philo->eat_mutex);
	philo->eating = 0;
	pthread_mutex_unlock(philo->eat_mutex);
}

//philosopher is eating
void	eating(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	deadlock_forks(philo, &first_fork, &second_fork);
	pthread_mutex_lock(first_fork);
	print_mutex(FORK, philo, philo->id);
	ft_usleep(2);
	if (philo->number_of_philosophers == 1)
	{
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(philo->eat_mutex);
		ft_usleep(philo->time_to_die);
		return ;
	}
	pthread_mutex_lock(second_fork);
	print_mutex(FORK, philo, philo->id);
	print_mutex(EAT, philo, philo->id);
	update_philo_meal(philo);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}
