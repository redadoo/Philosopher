/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:15:46 by evocatur          #+#    #+#             */
/*   Updated: 2023/09/06 13:10:26 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <sys/time.h>

typedef struct s_philosophers
{
    int  number_of_philosophers;
    int  time_to_die;
    int  time_to_eat;
    int  time_to_sleep;
    int  each_philo_must_eat;
}   t_philosophers;

void check(char **argv);
void exit_prog();


#endif