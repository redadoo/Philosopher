/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:57 by evocatur          #+#    #+#             */
/*   Updated: 2023/09/06 13:18:13 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *myThreadFun(void *vargp)
{
    int *ts = (int *)malloc(sizeof(int));
    *ts = 5;
    return ts;
}

int main(int argc, char **argv)
{
    int             i;
    int             *result;
    t_philosophers  p;
    pthread_t       newthread;

    i = 0;
    
    if (argc < 5)
        exit(0);


    p.number_of_philosophers = atoi(argv[1]);
    p.time_to_die = atoi(argv[2]);
    p.time_to_eat = atoi(argv[3]);
    p.time_to_sleep = atoi(argv[4]);
    p.each_philo_must_eat = atoi(argv[5]);
    
    while (i < p.number_of_philosophers)
    {
        pthread_create(&newthread, NULL, myThreadFun, NULL);        
        i++;
    }
    


    pthread_join(newthread, (void *)&result);
    printf("%i\n",*result);
    return 0;
}