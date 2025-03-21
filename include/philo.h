/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:04:30 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/21 20:58:46 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// includes
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

// structs
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

// messages
# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"died"
# define FULL	"All philosophers are full, shutting down simulation"
# define ERR_PTHREAD_CREATE	"Error: pthread_create() failed.\n"
# define ERR_PTHREAD_JOIN	"Error: pthread_join() failed.\n"
# define ERR_ARGS_NUM	"Error: Wrong number of arguments.\n"
# define ERR_ARGS_DIGIT	"Error: Only digits allowed.\n"
# define ERR_PHILO_NUM	"Error: Should have from 2 to 200 philos max.\n"

// error_checks.c
int		check_args(int ac, char **av);

// ft_usleep.c
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);

//init.c
void	init(t_philo *philo, char **av, t_program *program,
			pthread_mutex_t *forks);

// monitor.c
void	*monitor_logic(void *arg);

// philo_logic.c
void	*philo_logic(void *philo);

// thread_join.c
void	threads_engage(t_program *program, pthread_mutex_t *forks);

// utils.c
void	destroy_mutexes(char *str, t_program *program, pthread_mutex_t *forks);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *nptr);
int		is_dead(t_philo *philo);
void	print_mutex(char *str, t_philo *philo, int id);

#endif
