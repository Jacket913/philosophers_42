/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoulin <kmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:48:20 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/24 22:09:51 by kmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	//grab fork left
		//print "[timestamp in ms] Philo [id] has taken a fork"
	//grab fork right
		//print "[timestamp in ms] Philo [id] has taken a fork"
	//philo is eating
		//print "[timestamp in ms] Philo [id] is eating"
		//sleep for (av[3]) time
	//release left fork
	//release right fork
	//philo is sleeping
		//print "[timestamp in ms] Philo [id] is sleeping"
		//sleep for (av[4]) time
	//philo is thinking
		//print "[timestamp in ms] Philo [id] is thinking"
	//repeat

//philosopher is sleeping
static void	sleeping(t_philo *philo)
{
	print_mutex(SLEEP, philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

//philosopher is thinking
static void	thinking(t_philo *philo)
{
	print_mutex(THINK, philo, philo->id);
}

//philosopher logic/routine
void	*philo_logic(void *philo)
{
	t_philo	*philo_ptr;

	philo_ptr = (t_philo *)philo;
	if (philo_ptr->id % 2 == 0)
		ft_usleep(1);
	while (!is_dead(philo_ptr))
	{
		if (is_dead(philo_ptr))
			break ;
		eating(philo_ptr);
		if (is_dead(philo_ptr))
			break ;
		sleeping(philo_ptr);
		if (is_dead(philo_ptr))
			break ;
		thinking(philo_ptr);
	}
	return (NULL);
}
