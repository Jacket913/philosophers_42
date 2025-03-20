/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:04:12 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/20 03:24:50 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];

	//check for wrong number of arguments
	if (ac < 5 || ac > 6)
		return (error("Error: Wrong number of arguments.\n"), 1);

	//check for numerical values
	if (check_args(av))
		return (1);

	//av[1] = number of philosophers (200 max)
	//av[2] = time to die
	//av[3] = time to eat
	//av[4] = time to sleep
	//av[5] = number of meals before stop

	//init program, forks, philo
	init(philo, av, &program, forks);

	//join threads

		while (1)
		{
			//checks for death every 1ms and break if there is one
			if (program_dead_check(philo, &program))
				break;

			//if thinking and not max meals eaten
				//if left fork available
					//grab fork left
					//print "[timestamp in ms] Philo [id] has taken a fork"
					//if right fork available
						//grab fork right
						//print "[timestamp in ms] Philo [id] has taken a fork"
					//else if right fork not available
						//release left fork

				//if holding both forks
					//philo is eating
					//print "[timestamp in ms] Philo [id] is eating"
					//sleep for (av[3]) time
					//release left fork
					//release right fork
					//philo is sleeping
					//print "[timestamp in ms] Philo [id] is sleeping"
					//sleep for (av[4]) time

			//else
				//philo is thinking
				//print "[timestamp in ms] Philo [id] is thinking"
		}
	//destroy mutexes
	return (0);
}
