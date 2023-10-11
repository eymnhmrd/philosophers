/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:13:25 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/11 18:22:12 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (write(2, "gettimeofday error\n", 19), 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_usleep(size_t ms)
{
	size_t	t;

	t = get_current_time();
	while (get_current_time() - t < ms)
		usleep(400);
	return (0);
}
