/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:34:29 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/19 00:44:14 by gmoulin          ###   ########.fr       */
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
