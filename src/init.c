/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoulin <kmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:48:20 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/22 16:00:59 by kmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//initialize av values to philo struct
static void	init_settings(t_philo *philo, char **av)
{
	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = -1;
	philo->eating = 0;
	philo->last_meal = 0;
}

//initialize forks
static void	init_forks(pthread_mutex_t *forks, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

//initialize philo struct with settings
static void	init_philo(t_philo *philo, char **av,
	t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		init_settings(&philo[i], av);
		philo[i].id = i + 1;
		philo[i].start_time = get_current_time();
		philo[i].last_meal = philo[i].start_time;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].dead = &program->dead;
		philo[i].right_fork = &forks[i];
		philo[i].left_fork = &forks[(i + 1) % philo->number_of_philosophers];
		philo[i].write_mutex = &program->write_mutex;
		philo[i].eat_mutex = &program->eat_mutex;
		philo[i].dead_mutex = &program->dead_mutex;
		i++;
	}
}

//initialize program struct
static void	init_program(t_program *program, t_philo *philos)
{
	program->dead = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_mutex, NULL);
	pthread_mutex_init(&program->eat_mutex, NULL);
	pthread_mutex_init(&program->dead_mutex, NULL);
}

//initialize philo struct, forks and program struct
void	init(t_philo *philo, char **av, t_program *program,
	pthread_mutex_t *forks)
{
	init_program(program, philo);
	init_forks(forks, ft_atoi(av[1]));
	init_philo(philo, av, program, forks);
}
