/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:04:30 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/19 19:29:36 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	int				*dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*dead_mutex;
}	t_philo;

typedef struct s_program
{
	int				dead;
	t_philo			*philos;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	dead_mutex;
}	t_program;

// error_checks.c
void	error(char *str);
int		check_args(char **av);

// ft_usleep.c
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);

//init.c
void	init_forks(pthread_mutex_t *forks, int nb_philos);
void	init_philo(t_philo *philo, char **av, t_program *program, \
		pthread_mutex_t *forks);
void	init_program(t_program *program, t_philo *philo);

// utils.c
size_t	ft_strlen(char *str);
int		ft_atoi(const char *nptr);
void	print_philo(t_philo *philo, char *str);

#endif
