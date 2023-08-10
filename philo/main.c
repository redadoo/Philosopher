/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:57 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/10 17:55:30 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *myThreadFun(void *vargp)
{
    
    
}

int main(int argc, char **argv)
{
    int             i;
    t_philosophers  p;
    pthread_t       tid;

    if (argc < 5)
        exit(0);
    check(argv);
    p.number_of_philosophers = argv[1];
    p.time_to_die = argv[2];
    p.time_to_eat = argv[3];
    p.time_to_sleep = argv[4];
    p.number_of_times_each_philosopher_must_eat = argv[5];
    for (i = 0; i <p.number_of_philosophers; i++)
    {
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
    }
    pthread_exit(NULL);
    return 0;
}