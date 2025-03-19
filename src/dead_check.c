/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:52:56 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/19 19:33:00 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_dead_flag(t_philo *philo, t_program *program)
{
	pthread_mutex_lock(&program->dead_mutex);
	program->dead = 1;
	pthread_mutex_lock(philo->write_mutex);
	printf("[%zu] Philo {%d} is dead\n", \
		get_current_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->write_mutex);
	pthread_mutex_unlock(&program->dead_mutex);
}

int	program_dead_check(t_philo *philo, t_program *program)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->number_of_philosophers)
		{
			if (get_current_time() - philo[i].last_meal > philo[i].time_to_die \
				&& !philo[i].eating)
			{
				set_dead_flag(&philo[i], program);
				break;
			}
			i++;
		}
		if (program->dead)
			return (1);
		ft_usleep(1000);
	}
}
