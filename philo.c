/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:18:57 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/10 06:10:51 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_forks(t_vars *vars)
{
	int i = 0;

	while (i < vars->num_philos)
	{
		printf ("%p || %p || id : %d\n", &vars->philo_ptr[i].r_fork, vars->philo_ptr[i].l_fork, vars->philo_ptr[i].id);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	var;
	// t_philo	philo;
	
	if (argc != 5 && argc != 6)
		return (write(2, "Wrong argument number\n", 22), 1);
	if (ft_check_arguments(argv) == 1)
		return (1);
	init_philos(&var, argv);
	print_forks(&var);
	while (1);
	return 0;
}


