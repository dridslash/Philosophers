/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:32:01 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/26 14:34:58 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isalpha(argv[i])
			|| ((ft_isdigit_imp(argv[i])) == 0)
			|| (ft_is_empty(argv[i]) == 0))
		{
			return (1);
		}	
		else
		{
			ft_atoi(argv[i]);
		}
		i++;
	}
	return (0);
}
