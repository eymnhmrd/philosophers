/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:26:53 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/14 05:31:39 by ahamrad          ###   ########.fr       */
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
	pthread_mutex_lock(&philo->r_fork);
	philo_print(philo, FORK);
	pthread_mutex_lock(philo->l_fork);
	philo_print(philo, FORK);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(200);
	while (philo->vars_ptr->stop)
	{
		lock_forks(philo);
		philo_print(philo, EAT);
		ft_usleep(philo->vars_ptr->time_to_eat);
		pthread_mutex_lock(&philo->meal_mt);
		philo->last_meal = get_current_time();
		pthread_mutex_unlock(&philo->meal_mt);
		unlock_forks(philo);
		if (philo->vars_ptr->num_times_to_eat != -1)
			philo->meals_number++;
		pthread_mutex_lock(&philo->vars_ptr->satisfaction_mt);
		if (philo->vars_ptr->num_times_to_eat == philo->meals_number)
			philo->vars_ptr->satisfaction++;
		pthread_mutex_unlock(&philo->vars_ptr->satisfaction_mt);
		philo_print(philo, SLEEP);
		ft_usleep(philo->vars_ptr->time_to_sleep);
		philo_print(philo, THINK);
	}
}
