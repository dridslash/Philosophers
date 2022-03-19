/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:07:02 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/26 15:30:50 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_rules(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 0)
			return (0);
	}
	if (ft_check_input(argv) == 1)
	{
		write(2, "Error:\nINPUT\n", 13);
		return (0);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
		{
			write(2, "Error:\nNEGATIVE NUMBER\n", 23);
			return (0);
		}
			i++;
	}
	return (3);
}
