/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:12:13 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/07 13:08:45 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *t_arg)
{
	t_platone	*philo;

	philo = (t_platone *)t_arg;
	if (is_nietzsche_lonely(philo))
		return (NULL);
	if (philo->index % 2 != 0)
		usleep(15000);
	while (philo->info->died == 0)
	{
		ft_eating(philo);
		
		if(philo->info->all_eat == 1)
			break ;
		print_state("is sleeping\n", philo);
		ft_sleep(philo->info->time_to_sleep, philo);
		print_state("is thinking\n", philo);
	}
	return (NULL);
}

static void	create_threads(t_philosophers_info *info, t_platone *philo)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_create(&philo->newthread, NULL, philo_routine, philo);
		philo = philo->next;
		i++;
	}
}

static void	join_threads(t_philosophers_info *info, t_platone *philo)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_join(philo->newthread, NULL);
		philo = philo->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philosophers_info	*info;
	t_platone			*philo;

	if (argc != 5 && argc != 6)
		return (0);
	if (!check_arg(argv))
		return (0);
	info = init_info(argv);
	philo = init_platones(info);
	create_threads(info, philo);
	ft_end(philo);
	join_threads(philo->info, philo);
	free_list(&philo);
	free(info);
}
