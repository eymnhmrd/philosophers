/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:15:18 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/09 05:28:50 by ahamrad          ###   ########.fr       */
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

typedef struct s_philo
{
	int			id;
	pthread_t	t_id;
	pthread_mutex_t	fork;
	size_t		last_meal;
	t_vars		*vars_ptr;
}t_philo;

typedef struct s_vars
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_to_eat;
	size_t		start_time;
	t_philo	*philo_ptr;	
}t_vars;

void	init_vars(t_vars *var, char **argv);

int		ft_check_arguments(char **argv);

int	    ft_strlen(char *s);
long	ft_atoi(char *str);

#endif 