/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:12:57 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/22 14:57:24 by evocatur         ###   ########.fr       */
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

typedef enum e_state
{
	DEAD,
	EAT,
	THINK,
	SLEEP,
	FORK,
	DROP,
}						t_e_state;

typedef struct s_philosophers_info
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					each_philo_must_eat;
	int					all_eat;
	pthread_mutex_t		monitoring_mutex;
	bool				end;
}						t_philosophers_info;

typedef struct s_platone
{
	int					index;
	unsigned long		last_meal;
	unsigned long		time_start;
	int					n_meals;
	pthread_mutex_t		fork_lock;
	struct s_platone	*next;
	pthread_t			newthread;
	t_philosophers_info	*info;
}						t_platone;

void					ft_sleep(size_t milliseconds, t_platone *philo);
unsigned long			ft_get_time(void);
void					*philo_routine(void *vargp);
t_platone				*init_platones(t_philosophers_info *info);
int						ft_atoi(const char *nptr);
t_philosophers_info		*init_info(char **argv);
bool					check_arg(char **argv);
int						all_philo_full(t_platone *philo);
void					print_state(char *str, t_platone *philo);
void					destory_all(t_platone *philo);
bool					_platone(t_platone *philo);
void					ft_eating(t_platone *philo);
void					ft_end(t_platone *philo);
bool					all_have_eat(t_platone *philo);
bool					_philo(t_platone *philo);
void					free_list(t_platone **philo);
void					monitoring(t_platone *philo, t_e_state event_id);
bool					is_nietzsche_lonely(t_platone *nietzsche);
int						ft_isdigit(char *str);
void					take_forks(t_platone *philo);
void					drop_forks(t_platone *philo);
#endif