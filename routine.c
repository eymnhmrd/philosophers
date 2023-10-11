/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:26:53 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/11 18:23:03 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->vars_ptr->mt_print);
	printf(str, (get_current_time() - philo->vars_ptr->start_time), philo->id);
	pthread_mutex_unlock(&philo->vars_ptr->mt_print);
}

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, FORK);
		pthread_mutex_lock(&philo->r_fork);
		philo_print(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->r_fork);
		philo_print(philo, FORK);
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, FORK);
	}
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void	routine(t_philo *philo)
{
	while (1)
	{
		lock_forks(philo);
		philo_print(philo, EAT);
		ft_usleep(philo->vars_ptr->time_to_eat);
		if (philo->vars_ptr->num_times_to_eat != -1)
			philo->meals_number++;
		unlock_forks(philo);
		if (philo->vars_ptr->num_times_to_eat == philo->meals_number)
			philo->vars_ptr->satisfaction++;
		philo_print(philo, SLEEP);
		ft_usleep(philo->vars_ptr->time_to_sleep);
		philo_print(philo, THINK);
	}
}
