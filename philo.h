/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:15:18 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/10 06:35:14 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

#define FORK "%ld ms %d has taken a fork\n"
#define EAT "%ld ms %d is eating\n"
#define SLEEP "%ld ms %d is sleeping\n"
#define THINK "%ld ms %d is thinking\n"
#define DIE  "%ld ms %d died\n"



typedef struct s_vars
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_to_eat;
	int		satisfaction;
	pthread_mutex_t	mt_print;
	size_t		start_time;
	struct s_philo		*philo_ptr;	
}t_vars;
typedef struct s_philo
{
	int			id;
	pthread_t	t_id;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	size_t		last_meal;
	int			meals_number;
	t_vars		*vars_ptr;
}t_philo;

void	init_vars(t_vars *var, char **argv);
int		init_philos(t_vars *var, char **argv);

void	routine(t_philo *philo);

int		ft_check_arguments(char **argv);

size_t	get_current_time(void);
int		ft_usleep(size_t ms);

int	    ft_strlen(char *s);
long	ft_atoi(char *str);

#endif 