/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:29:36 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/21 19:30:04 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Print error message in stderr
static void	error(char *str)
{
	write(2, str, ft_strlen(str));
}

// Check if arguments are numerical and philo max < 200
int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5 || ac > 6)
		return (error(ERR_ARGS_NUM), 1);
	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (error(ERR_ARGS_DIGIT), 1);
			j++;
		}
	}
	if (ft_atoi(av[1]) == 1 || ft_atoi(av[1]) > 200)
		return (error(ERR_PHILO_NUM), 1);
	return (0);
}
