/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:57 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/24 16:27:09 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *myThreadFun(void *vargp)
{
    printf("asdasdasd\n");
    return 0;
}

int main(int argc, char **argv)
{
    int             i;
    t_philosophers  p;
    pthread_t       tid;

    if (argc < 5)
        exit(0);
    p.number_of_philosophers = atoi(argv[1]);
    p.time_to_die = atoi(argv[2]);
    p.time_to_eat = atoi(argv[3]);
    p.time_to_sleep = atoi(argv[4]);
    p.number_of_times_each_philosopher_must_eat = atoi(argv[5]);
    for (i = 0; i < p.number_of_philosophers; i++)
    {
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
    }
    pthread_exit(NULL);
    return 0;
}