/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:28:32 by evocatur          #+#    #+#             */
/*   Updated: 2023/09/11 16:48:48 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool dead_philo(t_platone *philo)
{
    int i;

    i = 0;

    while (i < philo->info.number_of_philosophers)
    {
        if (philo->state == DEAD)
            return true;
        i++;   
    }
    return false;
}

bool all_have_eat(t_platone *philo)
{
    int i;

    i = 0;

    while (i < philo->info.number_of_philosophers)
    {
        if (philo->info.each_philo_must_eat != philo->n_meals)
            return false;
        i++;   
    }
    return true;
}
