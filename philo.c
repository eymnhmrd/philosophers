/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:18:57 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/15 04:25:32 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 199 69 69 69

int	main(int argc, char **argv)
{
	t_vars	var;

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong argument number\n", 22), 1);
	if (ft_check_arguments(argv) == 1)
		return (1);
	if (init_philos(&var, argv) == 1)
		return (1);
	ft_check_death(&var, 0, 0);
	ft_usleep(100);
	free_mutexes(&var);
	return (0);
}
