/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:43:44 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/19 20:10:09 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	full_of_soup_check(t_philo *philo)
{
	int	max_soup;

	max_soup = philo->number_of_times_each_philosopher_must_eat;
	if (philo->number_of_times_each_philosopher_must_eat != -1)
	{
		if (philo->meals_eaten >= max_soup)
			return (1);
	}
	return (0);
}

int	philos_all_fed_check(t_philo *philo, t_program *program)
{
	int	i;
	int	full_of_yummy;

	i = 0;
	full_of_yummy = 0;
	while (i < philo->number_of_philosophers && full_of_soup_check(&philo[i]))
	{
		full_of_yummy++;
		i++;
	}
	if (full_of_yummy == philo->number_of_philosophers)
	{
		pthread_mutex_lock(&program->dead_mutex);
		program->dead = 1;
		pthread_mutex_unlock(&program->dead_mutex);
		return (1);
	}
	return (0);
}
