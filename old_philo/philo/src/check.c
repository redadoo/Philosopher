/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 01:40:20 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/12 17:03:10 by edoardo          ###   ########.fr       */
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

void	ft_end(t_platone *philo)
{
	int				i;
	int				philo_who_eat;
	pthread_mutex_t	check_dead_lock;

	pthread_mutex_init(&check_dead_lock,NULL);
	while (1)
	{
		i = -1;
		philo_who_eat = 0;
		pthread_mutex_lock(&check_dead_lock);
		while (++i < philo->info->number_of_philosophers)
		{
			if (philo->info->time_to_die < ft_get_time() - philo->last_meal)
			{
				philo->info->program_end = true;
				pthread_mutex_unlock(&check_dead_lock);		
				print_state("is died\n",philo);
				return ;
			}
			if (philo->info->each_philo_must_eat != -1)
			{
				if (philo->n_meals >= philo->info->each_philo_must_eat)
					philo_who_eat++;
				if (philo_who_eat >= philo->info->number_of_philosophers)
				{
					philo->info->program_end = true;
					pthread_mutex_unlock(&check_dead_lock);
					return ;
				}
			}
			philo = philo->next;
		}
		pthread_mutex_unlock(&check_dead_lock);		
	}
	pthread_mutex_destroy(&check_dead_lock);
}

void	free_list(t_platone **philo)
{
	int			i;
	int			d;
	t_platone	*tmp;

	i = 0;
	d = (*philo)->info->number_of_philosophers;
	while (i < d)
	{
		tmp = (*philo);
		pthread_mutex_destroy(&(*philo)->dead_lock);
		pthread_mutex_destroy(&(*philo)->meal_lock);
		pthread_mutex_destroy(&(*philo)->time_lock);
		pthread_mutex_destroy(&(*philo)->fork_lock);
		pthread_mutex_destroy(&(*philo)->test_lock);
		(*philo) = (*philo)->next;
		free(tmp);
		i++;
	}
}
