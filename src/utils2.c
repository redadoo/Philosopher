/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:02:50 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/13 13:36:40 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_platone *philo)
{
	if (philo->info->number_of_philosophers % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork_lock);
		monitoring(philo, FORK);
		pthread_mutex_lock(&philo->next->fork_lock);
		monitoring(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork_lock);
		monitoring(philo, FORK);
		pthread_mutex_lock(&philo->fork_lock);
		monitoring(philo, FORK);
	}
}

void	drop_forks(t_platone *philo)
{
	if (philo->info->number_of_philosophers % 2 == 0)
	{
		pthread_mutex_unlock(&philo->fork_lock);
		monitoring(philo, DROP);
		pthread_mutex_unlock(&philo->next->fork_lock);
		monitoring(philo, DROP);
	}
	else
	{
		pthread_mutex_unlock(&philo->next->fork_lock);
		monitoring(philo, DROP);
		pthread_mutex_unlock(&philo->fork_lock);
		monitoring(philo, DROP);
	}
}
