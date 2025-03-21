/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:11:50 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/21 20:54:33 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create a monitor thread
// create a thread for each philosopher
// join the monitor thread
// join each philosopher thread
void	threads_engage(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	monitor_thread;
	int			i;

	if (pthread_create(&monitor_thread, NULL, monitor_logic, program->philos))
		return (destroy_mutexes(ERR_PTHREAD_CREATE, program, forks));
	i = 0;
	while (i < program->philos->number_of_philosophers)
	{
		if (pthread_create(&program->philos[i].thread, NULL,
				philo_logic, &program->philos[i]))
			return (destroy_mutexes(ERR_PTHREAD_CREATE, program, forks));
		i++;
	}
	if (pthread_join(monitor_thread, NULL))
		return (destroy_mutexes(ERR_PTHREAD_JOIN, program, forks));
	i = 0;
	while (i < program->philos->number_of_philosophers)
	{
		if (pthread_join(program->philos[i].thread, NULL))
			return (destroy_mutexes(ERR_PTHREAD_JOIN, program, forks));
		i++;
	}
}
