/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:11:08 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/28 10:38:27 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutex(t_philo *philos, t_all *glob)
{
	int	i;

	i = 0;
	while (i < glob->number_of_philos)
	{
		if (pthread_mutex_destroy(&glob->forks[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_destroy(&glob->msg) != 0)
		return (0);
	if (pthread_mutex_destroy(&philos->meal_eat) != 0)
		return (0);
	return (3);
}
