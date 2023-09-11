/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:12:13 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/11 19:41:07 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	all_philo_full(t_platone *philo)
{
	int	i;
	int	count;
	int	each_philo_must_eat;

	pthread_mutex_lock(&philo->meal_lock);
	each_philo_must_eat = philo->info.each_philo_must_eat;
	count = 0;
	i = 0;
	if (philo->info.each_philo_must_eat != -1)
	{
		while (i < philo->info.number_of_philosophers)
		{
			if (philo->n_meals == philo->info.each_philo_must_eat)
				count++;
			i++;
			philo = philo->next;
		}
		printf("teset . %i\n",count);
		if (count == philo->info.number_of_philosophers)
		{
			pthread_mutex_unlock(&philo->meal_lock);
			exit(0);
		}
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (1);
}

void	*philo_routine(void *t_arg)
{
	t_platone	*philo;

	philo = (t_platone *)t_arg;
	if (philo->info.number_of_philosophers == 1)
	{
		ft_sleep(philo->info.time_to_die, philo);
		print_state("died\n", philo);
		destory_all(philo->info, philo);
	}
	if (philo->index % 2 != 0)
	{
		usleep(15000);
	}
	while (dead_platone(philo))
	{
		ft_eating(philo);
		print_state("is thinking\n", philo);
		all_philo_full(philo);
	}
}

static void	create_threads(t_philosophers_info info, t_platone *philo)
{
	int	i;

	i = 0;
	while (i < info.number_of_philosophers)
	{
		pthread_create(&philo->newthread, NULL, philo_routine, philo);
		philo = philo->next;
		i++;
	}
}

static void	join_threads(t_philosophers_info info, t_platone *philo)
{
	int	i;

	i = 0;
	while (i < info.number_of_philosophers)
	{
		pthread_join(philo->newthread, NULL);
		philo = philo->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;
	t_philosophers_info info;
	t_platone *philo;
	i = 0;
	if (argc != 5 && argc != 6)
		return (0);
	if (!check_arg(argv))
		return (0);

	info = init_info(info, argv);
	philo = init_platones(info);

	create_threads(info, philo);
	join_threads(info, philo);
	destory_all(info, philo);

	printf("inc\n");
}