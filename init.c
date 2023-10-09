/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:01:20 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/09 05:08:31 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_vars(t_vars *var, char **argv)
{
	var->num_philos = ft_atoi(argv[1]);
	var->time_to_die = ft_atoi(argv[2]);
	var->time_to_eat = ft_atoi(argv[3]);
	var->time_to_die = ft_atoi(argv[4]);
	if (argv[5])
		var->num_times_to_eat = ft_atoi(argv[5]);
}





