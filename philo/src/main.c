/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:57 by evocatur          #+#    #+#             */
/*   Updated: 2023/09/09 15:37:50 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <string.h>

static bool	is_all_dead(t_platone *st)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < st->info.number_of_philosophers)
	{
		st = st->next;
		if (st->state == DEAD)
			count++;
		i++;
	}
	if (count == st->info.number_of_philosophers)
		return (true);
	return (false);
}

void	*philo_routine(void *vargp)
{
	t_platone	*philo;

	philo = (t_platone *)vargp;
	/* 	if (philo->index % 2 != 0)
				usleep(50); */
	while (philo->state != DEAD)
	{
		if (pthread_mutex_lock(&philo->fork) == 0)
		{
			pthread_mutex_lock(&philo->next->fork);
			philo->state = EAT;
		}
		if (philo->state == EAT)
		{
			printf("%lu %i is eating\n", ft_get_time() - philo->time_start,
				philo->index);
			usleep(philo->info.time_to_eat * 1000);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->next->fork);
			philo->state = SLEEP;
			printf("%lu %i is sleeping\n", ft_get_time() - philo->time_start,
				philo->index);
			usleep(philo->info.time_to_sleep * 1000);
			philo->state = ALIVE;
		}
		if (philo->state != EAT)
		{
			printf("%lu %i is thinking\n", ft_get_time() - philo->time_start,
				philo->index);
			philo->state = THINK;
		}
		
	}
}

int	main(int argc, char **argv)
{
	int i;
	t_platone *platone;
	t_philosophers_info info;

	if (argc < 5 || argc > 6)
		exit(0);

	info = init_info(info, argv);
	platone = init_platones(info);
	i = 0;
	while (i < info.number_of_philosophers)
	{
		pthread_create(&platone->newthread, NULL, philo_routine, platone);
		platone = platone->next;
		i++;
	}
	i = 0;
	while (i < info.number_of_philosophers)
	{
		pthread_join(platone->newthread, NULL);
		platone = platone->next;
		i++;
	}
	pthread_exit(&platone->newthread);
	return (0);
}