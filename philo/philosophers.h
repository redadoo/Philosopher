/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:15:46 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/24 16:25:44 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/time.h>


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H



typedef struct s_philosophers
{
    int  number_of_philosophers;
    int  time_to_die;
    int  time_to_eat;
    int  time_to_sleep;
    int  number_of_times_each_philosopher_must_eat;
}   t_philosophers;

void check(char **argv);
void exit_prog();


#endif