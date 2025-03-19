/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:29:36 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/19 01:29:32 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Print error message in stderr
void	error(char *str)
{
	write(2, str, ft_strlen(str));
}

// Check if arguments are numerical and philo max < 200
int	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (error("Error: Only numerical chars allowed.\n"), 1);
			j++;
		}
	}
	if (ft_atoi(av[1]) > 200)
		return (error("Error: Philosophers count exceeds 200.\n"), 1);
	return (0);
}
