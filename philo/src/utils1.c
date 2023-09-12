/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:48:38 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/12 17:49:43 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(size_t milliseconds, t_platone *philo)
{
	size_t	start;

	start = ft_get_time();
	while (dead_platone(philo) && (ft_get_time() - start) < milliseconds)
		usleep(500);
}

unsigned long	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	print_state(char *str, t_platone *philo)
{
	pthread_mutex_lock(&philo->time_lock);
	printf("%zu %i %s", ft_get_time() - philo->time_start, philo->index, str);
	pthread_mutex_unlock(&philo->time_lock);
}

bool	dead_platone(t_platone *philo)
{
	pthread_mutex_lock(&philo->dead_lock);
	if (ft_get_time() - philo->last_meal > philo->info.time_to_die)
	{
		print_state("adied\n", philo);
		philo->info.died = DEAD;
		pthread_mutex_unlock(&philo->dead_lock);
		return (false);
	}
	pthread_mutex_unlock(&philo->dead_lock);
	return (true);
}

void	ft_eating(t_platone *philo)
{
	dead_platone(philo);
	pthread_mutex_lock(&philo->fork_lock);
	pthread_mutex_lock(&philo->next->fork_lock);
	print_state("has taken a fork\n", philo);
	print_state("has taken a fork\n", philo);
	philo->state = EAT;
	print_state("is eating\n", philo);
	ft_sleep(philo->info.time_to_eat, philo);
	philo->n_meals++;
	philo->last_meal = ft_get_time();
	all_philo_full(philo);
	pthread_mutex_unlock(&philo->fork_lock);
	pthread_mutex_unlock(&philo->next->fork_lock);
	print_state("is sleeping\n", philo);
	ft_sleep(philo->info.time_to_sleep, philo);
	dead_platone(philo);
}
