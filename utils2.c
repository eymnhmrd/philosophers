/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:13:25 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/14 05:31:25 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (write(2, "gettimeofday error\n", 19), 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long long ms)
{
	long long	t;

	t = get_current_time();
	while (get_current_time() - t < ms)
		usleep(50);
}

void	free_mutexes(t_vars *var)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&var->mt_print);
	while (i < var->num_philos)
	{
		pthread_mutex_destroy(&var->philo_ptr[i].r_fork);
		i++;
	}
	// free(var->philo_ptr);
}

int		ft_check_death(t_vars *var)
{
	int			i;
	long long	diff;

	i = 0;
	ft_usleep(100);
	while (1)
	{
		pthread_mutex_lock(&var->philo_ptr[i].meal_mt);
		diff = (get_current_time() - var->start_time) - var->philo_ptr[i].last_meal;
		if (diff >= var->time_to_die)
		{
			pthread_mutex_lock(&var->mt_print);
			var->stop = 0;
			printf("%lld ms %d died\n", get_current_time() - var->start_time, var->philo_ptr[i].id);
			return (1);
		}
		pthread_mutex_unlock(&var->philo_ptr[i].meal_mt);
		pthread_mutex_lock(&var->satisfaction_mt);
		if (var->satisfaction == var->num_philos)
		{
			pthread_mutex_lock(&var->mt_print);
			var->stop = 0;
			return (2);
		}
		pthread_mutex_unlock(&var->satisfaction_mt);
		i++;
		if (i == var->num_philos)
			i = 0;
		// usleep(100);
	}
	return (0);
}

