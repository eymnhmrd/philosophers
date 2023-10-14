/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:15:18 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/14 03:29:31 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define MSG_ERROR "Invalid number of times each philosopher must eat\n"

# define FORK "%lld ms %d has taken a fork\n"
# define EAT "%lld ms %d is eating\n"
# define SLEEP "%lld ms %d is sleeping\n"
# define THINK "%lld ms %d is thinking\n"
# define DIE  "%lld ms %d died\n"

typedef struct s_vars
{
	int					num_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_times_to_eat;
	pthread_mutex_t		satisfaction_mt;
	int					satisfaction;
	pthread_mutex_t		mt_print;
	long long			start_time;
	struct s_philo		*philo_ptr;
	int 				stop;
}t_vars;
typedef struct s_philo
{
	int				id;
	pthread_t		t_id;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	meal_mt;
	pthread_mutex_t	*l_fork;
	long long			last_meal;
	int				meals_number;
	t_vars			*vars_ptr;
}t_philo;

int			init_philos(t_vars *var, char **argv);
int			init_vars(t_vars *var, char **argv);

int			ft_check_arguments(char **argv);
int			ft_check_death(t_vars *var);

void		routine(t_philo *philo);
long long	get_current_time(void);
void		ft_usleep(long long ms);
void		free_mutexes(t_vars *var);

long		ft_atoi(char *str);

#endif 