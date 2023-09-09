/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:12:01 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/09 14:15:29 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosophers_info init_info(t_philosophers_info philo, char **argv)
{
    philo.number_of_philosophers = ft_atoi(argv[1]);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	philo.each_philo_must_eat = ft_atoi(argv[5]);
	return (philo);
}

static t_platone *platone_friends(t_platone *friends, int i)
{
	friends->index = i;
	pthread_mutex_init(&friends->fork, NULL);
	friends->state = ALIVE;
	friends->last_meal = 0;
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
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
