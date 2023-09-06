/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:13:57 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/06 17:15:37 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				result;
	char			sign;

	i = 0;
	result = 0;
	sign = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = nptr[i];
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	if (sign == '-')
		result *= -1;
	return (result);
}