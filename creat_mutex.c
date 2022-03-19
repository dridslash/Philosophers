/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:06:24 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/28 10:38:13 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creat_mutex(t_philo *philos, t_all *glob)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&philos->meal_eat, NULL) != 0)
		return (0);
	while (i < glob->number_of_philos)
	{
		pthread_mutex_init(&glob->forks[i], NULL);
		i++;
	}
	return (3);
}
