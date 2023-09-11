/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:57 by evocatur          #+#    #+#             */
/*   Updated: 2023/09/11 16:51:25 by edoardo          ###   ########.fr       */
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

void monitoring(void *vargp)
{
	t_platone		*philo;

	philo = (t_platone *)vargp;

	while (1)
	{
		if (all_have_eat(philo) || dead_philo(philo))
			break ;
	}
	
}


void	*philo_routine(void *vargp)
{
 	t_platone		*philo;

	philo = (t_platone *)vargp;
	
	if (philo->index % 2 != 0)
	{
		ft_sleep(1);
	}
	
/*	if (philo->info.number_of_philosophers == 1)
	{
		ft_sleep(philo->info.time_to_die);
		printf("%lu %i is dead\n", ft_get_time() - philo->time_start, philo->index);
		philo->state = DEAD;
	}
	if (philo->index % 2 != 0)
	{
		ft_sleep(1);
	}
	while (philo->state != DEAD)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo->info.each_philo_must_eat == -1 && all_philo_full(philo) == true)
		{
			exit(0);
		}
		if (ft_get_time() - philo->last_meal >= philo->info.time_to_die)
		{
 			printf("test %lu\n", ft_get_time() - philo->time_start - philo->last_meal);
 			printf("%lu %i died\n", ft_get_time() - philo->time_start, philo->index);
			philo->state = DEAD;
			if (philo->info.each_philo_must_eat == -1)
			{
				printf("capiamo\n");
				exit(0);
			}
		}
		if (philo->state != DEAD && philo->fork && philo->next->fork)
		{
			pthread_mutex_lock(&philo->fork_lock);
			pthread_mutex_lock(&philo->next->fork_lock);
			philo->fork = false;
			philo->next->fork = false;
			philo->state = EAT;
		}
		if (philo->state == EAT)
		{
			philo->n_meals++;
			printf("%lu %i is eating\n", ft_get_time() -  philo->time_start,
				philo->index);
			ft_sleep(philo->info.time_to_eat);
			philo->last_meal = ft_get_time();
			philo->fork = true;
			philo->next->fork = true;
			pthread_mutex_unlock(&philo->fork_lock);
			pthread_mutex_unlock(&philo->next->fork_lock);
			usleep(100);
			philo->state = SLEEP;
			printf("%lu %i is sleeping\n", ft_get_time() -  philo->time_start,
				philo->index);
			ft_sleep(philo->info.time_to_sleep);
			philo->state = ALIVE;
		}
		if (philo->state == ALIVE)
		{
			printf("%lu %i is thinking\n", ft_get_time() -  philo->time_start,
				philo->index);
			philo->state = THINK;
		}
		pthread_mutex_unlock(&philo->mutex); 
	}*/
}

int	main(int argc, char **argv)
{
	int					i;
	pthread_t			observer;
	t_platone			*platone;
	t_philosophers_info info;

	i = 0;
	if (argc < 5 || argc > 6)
		exit(0);
	
	info = init_info(info, argv);
	platone = init_platones(info);

	pthread_create(&observer, NULL, &monitoring, platone);
	while (i < info.number_of_philosophers)
	{
		pthread_create(&platone->newthread, NULL, philo_routine, platone);
		platone = platone->next;
		i++;
	}
	i = 0;
	pthread_join(observer, NULL);
	while (i < info.number_of_philosophers)
	{
		pthread_join(platone->newthread, NULL);
		platone = platone->next;
		i++;
	}
	pthread_exit(&platone->newthread);
	i = 0;
	while (i < info.number_of_philosophers)
	{
		pthread_mutex_destroy(&platone->fork_lock);
		pthread_mutex_destroy(&platone->mutex);
		platone = platone->next;
		i++;
	}
	return (0);
}