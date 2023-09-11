/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:15:46 by evocatur          #+#    #+#             */
/*   Updated: 2023/09/11 16:49:13 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

enum					e_state
{
	ALIVE = 0,
	DEAD = 1,
	THINK = 2,
	SLEEP = 3,
	EAT = 4,
};

typedef struct s_philosophers_info
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					each_philo_must_eat;
}						t_philosophers_info;

typedef struct s_platone
{
	int					index;
	unsigned long		last_meal;
	unsigned long		time_start;
	int					n_meals;
	bool				fork;
	enum e_state		state;
	pthread_mutex_t		fork_lock;
	pthread_mutex_t		mutex;
	struct s_platone	*next;
	struct s_platone	*prev;
	pthread_t		    newthread;
	t_philosophers_info	info;
}						t_platone;

void					ft_sleep(unsigned long time);
unsigned long			ft_get_time(void);
void					*philo_routine(void *vargp);
t_platone				*init_platones(t_philosophers_info info);
int						ft_atoi(const char *nptr);
t_philosophers_info		init_info(t_philosophers_info p, char **argv);
void					check(char **argv);
void					exit_prog(void);
bool					all_philo_full(t_platone *philo);

/*                                */

bool all_have_eat(t_platone *philo);
bool dead_philo(t_platone *philo);

#endif