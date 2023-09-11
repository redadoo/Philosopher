/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:12:01 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/11 16:22:44 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(size_t milliseconds)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < milliseconds)
		usleep(500);
}

t_philosophers_info init_info(t_philosophers_info philo, char **argv)
{
    philo.number_of_philosophers = ft_atoi(argv[1]);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != 0)
		philo.each_philo_must_eat = ft_atoi(argv[5]);
	else
		philo.each_philo_must_eat = -1;
	return (philo);
}

static t_platone *platone_friends(t_platone *friends, int i)
{
	friends->index = i;
	pthread_mutex_init(&friends->fork_lock, NULL);
	pthread_mutex_init(&friends->mutex, NULL);
	friends->state = ALIVE;
	friends->last_meal = ft_get_time();
	friends->fork = true;
	friends->n_meals = 0;
	friends->time_start = ft_get_time();
	return (friends);
}

t_platone *init_platones(t_philosophers_info info)
{
	int			i;
	t_platone	*friends;
	t_platone	*tmp2;
	t_platone	*tmp;
	
	i = -1;
	friends = (t_platone *)malloc(sizeof(t_platone));
	if (!friends)
		return (NULL);
	tmp2 = friends;
	while (++i < info.number_of_philosophers)
	{
		friends = platone_friends(friends, i);
		friends->info = info;
		if (i == info.number_of_philosophers - 1)
			break ;
		tmp = (t_platone *)malloc(sizeof(t_platone));
		friends->next = tmp;
		tmp->prev = friends;
		friends = tmp;
	}
	friends->next = tmp2;
	tmp2->prev = friends;
	return	(tmp2);
}


unsigned long	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

bool all_philo_full(t_platone *philo)
{
	int i;

	i = 0;
	while (i != philo->info.number_of_philosophers)
	{
		if (philo->n_meals != philo->info.each_philo_must_eat)
			return false;
		i++;
	}
	return true;
}