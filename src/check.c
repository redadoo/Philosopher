/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:12:43 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/14 12:10:24 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char *str)
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

static inline bool	starved(t_platone *philo)
{
	return (((ft_get_time() - philo->last_meal)
			>= philo->info->time_to_die));
}

static bool	is_philo_dead(t_platone *philo, int *satisfied_philos)
{
	if (philo->info->each_philo_must_eat > 0 && philo->n_meals
		>= philo->info->each_philo_must_eat)
		*satisfied_philos += 1;
	if (starved(philo))
	{
		pthread_mutex_unlock(&philo->info->monitoring_mutex);
		monitoring(philo, DEAD);
		pthread_mutex_lock(&philo->info->monitoring_mutex);
		philo->info->end = true;
		pthread_mutex_unlock(&philo->info->monitoring_mutex);
		return (true);
	}
	return (false);
}

static inline void	all_have_eaten(t_platone *philo)
{
	philo->info->end = true;
	pthread_mutex_unlock(&philo->info->monitoring_mutex);
}

void	ft_end(t_platone *philo)
{
	int	i;
	int	satisfied_philos;

	while (true)
	{
		i = -1;
		satisfied_philos = 0;
		pthread_mutex_lock(&philo->info->monitoring_mutex);
		while (++i < philo->info->number_of_philosophers)
		{
			if (is_philo_dead(philo, &satisfied_philos))
				return ;
			philo = philo->next;
		}
		if (satisfied_philos == philo->info->number_of_philosophers)
			return (all_have_eaten(philo));
		pthread_mutex_unlock(&philo->info->monitoring_mutex);
	}
}
