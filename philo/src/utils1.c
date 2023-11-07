/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:48:38 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/07 16:27:42 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(size_t milliseconds, t_platone *philo)
{
	unsigned long	start;

	start = ft_get_time();
	pthread_mutex_lock(&philo->dead_lock);
	while (philo->info->died == 0 && (ft_get_time() - start) < milliseconds)
	{	
		usleep(500);
	}
	pthread_mutex_unlock(&philo->dead_lock);
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

void	ft_eating(t_platone *philo)
{
	pthread_mutex_lock(&philo->fork_lock);
	pthread_mutex_lock(&philo->next->fork_lock);
	
	print_state("has taken a fork\n", philo);
	print_state("has taken a fork\n", philo);
	print_state("is eating\n", philo);

	ft_sleep(philo->info->time_to_eat, philo);
	
	pthread_mutex_lock(&philo->meal_lock);
	
	philo->n_meals++;
	philo->last_meal = ft_get_time();
	
/* 	printf("\n Address of philo->last_meal : %p\n", &philo->last_meal);
	printf("\n Address of philo->n_meals : %p\n", &philo->n_meals);
	printf("\n Address of philo->info->time_to_eat : %p\n", &philo->info->time_to_eat);
	printf("\n Address of philo->meal_lock : %p\n", &philo->meal_lock);
	printf("\n Address of philo->fork_lock : %p\n", &philo->fork_lock);
	printf("\n Address of philo->meal_lock->next->fork_lock : %p\n", &philo->next->fork_lock); */

	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(&philo->next->fork_lock);
	pthread_mutex_unlock(&philo->fork_lock);
}
