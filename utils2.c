/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:13:25 by ahamrad           #+#    #+#             */
/*   Updated: 2023/10/09 05:18:14 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (write(2, "gettimeofday error\n", 19), 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

