/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:34:29 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/19 01:28:09 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	print_philo(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->write_mutex);
	printf("%s[%zu] Philo {%d}\n", str, \
		get_current_time() - philo->start_time, philo->id);
	printf("	nb_philos: %d\n", philo->number_of_philosophers);
	printf("	time_to_die: %ld\n", philo->time_to_die);
	printf("	time_to_eat: %ld\n", philo->time_to_eat);
	printf("	time_to_sleep: %ld\n", philo->time_to_sleep);
	printf("	max_meals: %d\n", philo->number_of_times_each_philosopher_must_eat);
	printf("	eating: %d\n", philo->eating);
	printf("	meals_eaten: %d\n", philo->meals_eaten);
	printf("	last_meal: %zu\n", get_current_time() - philo->last_meal);
	printf("	dead pointer: %p\n", philo->dead);
	printf("	left_fork: %p\n", philo->left_fork);
	printf("	right_fork: %p\n", philo->right_fork);
	pthread_mutex_unlock(philo->write_mutex);
}
