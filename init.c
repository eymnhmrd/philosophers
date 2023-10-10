/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:01:20 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/10 06:35:58 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_vars(t_vars *var, char **argv)
{
	var->num_philos = ft_atoi(argv[1]);
	var->time_to_die = ft_atoi(argv[2]);
	var->time_to_eat = ft_atoi(argv[3]);
	var->time_to_sleep = ft_atoi(argv[4]);
	var->satisfaction = 0;
	if (argv[5])
		var->num_times_to_eat = ft_atoi(argv[5]);
	else 
		var->num_times_to_eat = -1;
}

int		init_philos(t_vars *var, char **argv)
{
	int		i;

	i = 0;
	init_vars(var, argv);
	var->start_time = get_current_time();
	if (pthread_mutex_init(&var->mt_print, NULL) != 0)
		return (1);
	var->philo_ptr = malloc(sizeof(t_philo) * var->num_philos);
	if (!var->philo_ptr)
		return (1);
	while (i < var->num_philos)
	{
		var->philo_ptr[i].id = i + 1;
		var->philo_ptr[i].l_fork = NULL;
		var->philo_ptr[i].meals_number = 0;
		if (pthread_mutex_init(&var->philo_ptr[i].r_fork, NULL) != 0)
			return (1);
		var->philo_ptr[i].vars_ptr = var;
		if (var->philo_ptr[i].id % var->num_philos == var->philo_ptr[i].id)
			var->philo_ptr[i].l_fork = &var->philo_ptr[i + 1].r_fork;
		else
			var->philo_ptr[i].l_fork = &var->philo_ptr[0].r_fork;
		if (pthread_create(&var->philo_ptr[i].t_id, NULL, (void *)routine, &var->philo_ptr[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}





