/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:39:52 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/11 20:36:17 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				result;
	char			sign;

	i = 0;
	result = 0;
	sign = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = nptr[i];
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	if (sign == '-')
		result *= -1;
	return (result);
}

t_philosophers_info	init_info(t_philosophers_info philo, char **argv)
{
	philo.number_of_philosophers = ft_atoi(argv[1]);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != 0)
	{
		philo.each_philo_must_eat = ft_atoi(argv[5]);
	}
	else
	{
		philo.each_philo_must_eat = -1;
	}
	return (philo);
}

void	destory_all(t_philosophers_info info, t_platone *philo)
{
	int	i;

	i = 0;
	while (i < info.number_of_philosophers)
	{
		i++;
	}
	exit(0);
}

static t_platone	*platone_friends(t_platone *friends, int i)
{
	friends->index = i;
	pthread_mutex_init(&friends->time_lock, NULL);
	pthread_mutex_init(&friends->dead_lock, NULL);
	pthread_mutex_init(&friends->fork_lock, NULL);
	friends->state = ALIVE;
	friends->last_meal = ft_get_time();
	friends->n_meals = 0;
	friends->time_start = ft_get_time();
	return (friends);
}

t_platone	*init_platones(t_philosophers_info info)
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
		friends = tmp;
	}
	friends->next = tmp2;
	return (tmp2);
}
