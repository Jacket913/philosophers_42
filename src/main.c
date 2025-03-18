/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:04:12 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/19 00:09:07 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	//check for wrong number of arguments
	if (ac < 5 || ac > 6)
		return (error("Error: Wrong number of arguments.\n"), 1);

	//check for numerical values
		return (1);

	//av[1] = number of philosophers (200 max)
	//av[2] = time to die
	//av[3] = time to eat
	//av[4] = time to sleep
	//av[5] = number of meals before stop

	//init program

	//init forks

	//init philos

	//join threads

		//while no dead philosophers and no max meals eaten (av[5])
			//tick down time to die
			//if dead or max meals eaten (av[5]), break
			//if fork available and not sleeping
				//grab fork left
				//print "[timestamp in ms] Philo [id] has taken a fork"
				//grab fork right
				//print "[timestamp in ms] Philo [id] has taken a fork"
				//philo is eating
				//print "[timestamp in ms] Philo [id] is eating"
				//sleep for (av[3]) time
				//release forks
			//if fork not available
				//if didn't sleep since last meal
					//sleep once for (av[4]) time
					//print "[timestamp in ms] Philo [id] is sleeping"
				//if slept since last meal
					//thinking
					//print "[timestamp in ms] Philo [id] is thinking"
	//destroy mutexes
	return (0);
}
