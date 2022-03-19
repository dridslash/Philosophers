/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp_usleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:27:07 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/28 10:26:06 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	imp_usleep(long long time)
{
	long	start;

	start = get_time_in_miliseconds();
	while (get_time_in_miliseconds() < start + time)
		usleep(200);
}
