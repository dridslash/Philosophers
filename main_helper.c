/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:53:39 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/28 13:53:05 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_helper(int argc, char **argv, t_philo *philos, t_all *glob)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (set_rules(&philos, &glob, argv, argc) == 0)
			return (0);
		if (argc == 6)
		glob->eat_times = ft_atoi(argv[5]);
		if (creat_mutex(philos, glob) == 0)
			return (0);
		if (create_threads(philos, glob) == 0)
			return (0);
		while (philos->data->state)
		{
			i = 0;
			if (observer(philos, glob, i) == 0)
				return (0);
		}
		if (destroy_mutex(philos, glob) == 0)
			return (0);
	}
	else
		printf("Error :\n number of arguments is not valid\n");
	return (3);
}
