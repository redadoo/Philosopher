/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:13:10 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/22 14:57:00 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_eating(t_platone *philo)
{
	take_forks(philo);
	monitoring(philo, EAT);
	pthread_mutex_lock(&philo->info->monitoring_mutex);
	philo->last_meal = ft_get_time();
	philo->n_meals++;
	pthread_mutex_unlock(&philo->info->monitoring_mutex);
	usleep(philo->info->time_to_eat * 1000);
	monitoring(philo, DROP);
	drop_forks(philo);
}

void	free_list(t_platone **philo)
{
	int			i;
	int			d;
	t_platone	*tmp;

	i = 0;
	d = (*philo)->info->number_of_philosophers;
	pthread_mutex_destroy(&(*philo)->info->monitoring_mutex);
	while (i < d)
	{
		tmp = (*philo);
		pthread_mutex_destroy(&(*philo)->fork_lock);
		(*philo) = (*philo)->next;
		free(tmp);
		i++;
	}
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
