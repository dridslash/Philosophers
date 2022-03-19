/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:23:56 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/26 12:36:03 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_miliseconds(void)
{
	struct timeval	now;
	long			mili;

	gettimeofday(&now, NULL);
	mili = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (mili);
}

long	get_time_in_micro(long mili)
{
	long	micro;

	micro = mili * 1000;
	return (micro);
}
