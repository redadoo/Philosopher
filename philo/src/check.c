/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 01:40:20 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/09 00:58:09 by edoardo          ###   ########.fr       */
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
	int	i;
	int	x;

	while (1)
	{
		pthread_mutex_lock(&philo->test_lock);
		if(philo->info->all_eat != 0)
		{
			pthread_mutex_unlock(&philo->test_lock);
			break;
		}
		pthread_mutex_unlock(&philo->test_lock);
		
		i = 0;
		x = 0;
		while (i < philo->info->number_of_philosophers)
		{
			pthread_mutex_lock(&philo->meal_lock);
			if (philo->info->time_to_die < ft_get_time() - philo->last_meal)
			{
				pthread_mutex_unlock(&philo->meal_lock);
				print_state("died\n", philo);
				pthread_mutex_lock(&philo->dead_lock);
				philo->info->died = DEAD;
				pthread_mutex_unlock(&philo->dead_lock);
				return ;
			}
			if (philo->info->each_philo_must_eat != -1 && philo->n_meals >= philo->info->each_philo_must_eat)
				x++;
			pthread_mutex_lock(&philo->test_lock);
			if (x == philo->info->number_of_philosophers)
			{
				philo->info->all_eat = 1;
			}
			pthread_mutex_unlock(&philo->test_lock);
			pthread_mutex_unlock(&philo->meal_lock);
			philo = philo->next;
			i++;
		}
		usleep(200);
	}
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
