/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:04:12 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/21 19:51:58 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//av[1] = number of philosophers (between 2 and 200 max)
//av[2] = time to die
//av[3] = time to eat
//av[4] = time to sleep
//av[5] = number of meals before stop

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];

	if (check_args(ac, av))
		return (1);
	init(philo, av, &program, forks);
	threads_engage(&program, forks);
	destroy_mutexes(NULL, &program, forks);
	return (0);
}
