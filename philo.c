/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:18:57 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/09 05:16:32 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_vars	var;
	
	if (argc != 5 && argc != 6)
		return (write(2, "Wrong argument number\n", 22), 1);
	if (ft_check_arguments(argv) == 1)
		return (1);
	init_vars(&var, argv);
	return 0;
}


