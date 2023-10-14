/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:18:55 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/13 03:44:03 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check_number(char *number)
{
	int		i;

	i = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_arguments(char **argv)
{
	if (ft_atoi(argv[1]) >= 200 || ft_atoi(argv[1]) <= 0 
		|| ft_check_number(argv[1]) == 1)
		return (write(2, "Invalid number of philosophers\n", 28), 1);
	if (ft_atoi(argv[2]) < 60 || ft_check_number(argv[2]) == 1)
		return (write(2, "Invalid number of time to die\n", 30), 1);
	if (ft_atoi(argv[3]) < 60 || ft_check_number(argv[3]) == 1)
		return (write(2, "Invalid number of time to eat\n", 30), 1);
	if (ft_atoi(argv[4]) < 60 || ft_check_number(argv[4]) == 1)
		return (write(2, "Invalid number of time to sleep\n", 32), 1);
	if (argv[5] && (ft_atoi(argv[5]) <= 0 || ft_check_number(argv[5]) == 1))
		return (write(2, MSG_ERROR, 50), 1);
	return (0);
}
