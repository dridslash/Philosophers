/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe_manage_thread.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:25:30 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/28 13:59:51 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	observer(t_philo *philos, t_all *glob, int loop)
{
	while (loop < glob->number_of_philos)
	{
		pthread_mutex_lock(philos[loop].msg);
		if ((get_time_in_miliseconds() - philos[loop].last_time_eat) \
				>= glob->time_to_die)
		{
			philos[loop].data->state = DEAD;
			print("died", philos[loop]);
			return (0);
		}
		if (glob->eat_times > 0)
		{
			if (philos[loop].number_of_times_eaten > glob->eat_times)
			{
				philos[loop].data->state = DEAD;
				print("you have eaten enough", philos[loop]);
				return (0);
			}
		}
		pthread_mutex_unlock(philos[loop].msg);
		loop++;
	}
	usleep(130);
	return (3);
}
