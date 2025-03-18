/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:29:36 by gmoulin           #+#    #+#             */
/*   Updated: 2025/03/18 18:39:13 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Print error message in stderr
void	error(char *str)
{
	write(2, str, ft_strlen(str));
}

