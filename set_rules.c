/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:19:20 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/27 09:34:14 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_rules(t_philo **philos, t_all **glob, char **argv, int argc)
{
	if (check_rules(argc, argv) == 0)
		return (0);
	(*glob) = malloc(sizeof(t_all));
	(*glob)->number_of_philos = ft_atoi(argv[1]);
	(*glob)->time_to_die = ft_atoi(argv[2]);
	(*glob)->time_to_eat = ft_atoi(argv[3]);
	(*glob)->time_to_sleep = ft_atoi(argv[4]);
	(*glob)->forks = malloc(sizeof(pthread_mutex_t) \
			* (*glob)->number_of_philos);
	(*philos) = malloc(sizeof(t_philo) * (*glob)->number_of_philos);
	(*glob)->eat_times = 0;
	return (3);
}
