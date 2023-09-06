/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:57 by evocatur          #+#    #+#             */
/*   Updated: 2023/09/06 20:23:37 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *vargp)
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
    t_platone *philo = (t_platone *)vargp;
	philo->state = SLEEP;
    if (philo->state == DEAD)
        return NULL;
    if (philo->state == SLEEP)
	{
		usleep(philo->info.time_to_sleep * 1000);
		gettimeofday(&current_time, NULL);
 	 	printf("seconds : %ld\n micro seconds : %ld\n",
    		current_time.tv_sec, current_time.tv_usec);
	}
}

int	main(int argc, char **argv)
{
	int				    i;
	pthread_t		    newthread;
	t_platone		    *platone;
	t_philosophers_info info;
    
	if (argc < 5)
		exit(0);
    
    info = init_info(info, argv);
    platone = init_platones(info);
    i = 0;
	while (i < info.number_of_philosophers)
	{
		pthread_create(&newthread, NULL, philo_routine, platone);
		pthread_join(newthread, NULL);
        platone = platone->next;
		i++;
	}
	pthread_exit(&newthread);
	return (0);
}
