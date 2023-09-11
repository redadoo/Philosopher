/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:13:24 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/11 20:36:03 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

bool	check_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
		{
			return (false);
		}
		i++;
	}
	return (true);
}
