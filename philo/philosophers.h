/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:15:46 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/09 12:58:13 by evocatur         ###   ########.fr       */
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
    size_t  number_of_philosophers;
    size_t  time_to_die;
    size_t  time_to_eat;
    size_t  time_to_sleep;
}   t_philosophers;

void check(char **argv);
void exit_prog();


#endif