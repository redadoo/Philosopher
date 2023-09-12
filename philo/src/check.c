/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:13:24 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/12 17:04:30 by edoardo          ###   ########.fr       */
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

void ft_end(t_platone *philo)
{
	int i;

	i = -1;
	pthread_mutex_lock(&philo->info.check_lock);
	while (1)
	{

		while (++i < philo->info.number_of_philosophers)
		{
			if (philo->state == DEAD)
			{
				pthread_mutex_unlock(&philo->info.check_lock);
				usleep(100);
				break ;
			}
		}
		i = -1;
		usleep(200);
	}
	pthread_mutex_unlock(&philo->info.check_lock);
}

void free_list(t_platone *philo)
{
	int			i;
	int			d;
	t_platone	*tmp;

	i = 0;
	d = philo->info.number_of_philosophers;
	while (philo->index != 0)
		philo = philo->next;
	while (i < d)
	{
		tmp = philo;
		pthread_mutex_destroy(&philo->dead_lock);
		pthread_mutex_destroy(&philo->meal_lock);
		pthread_mutex_destroy(&philo->time_lock);
		pthread_mutex_destroy(&philo->fork_lock);
		philo = philo->next;
		free(tmp);
		i++;
	}
}