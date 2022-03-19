/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:56:48 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/28 14:03:17 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char	*str, t_philo philos)
{
	printf("%ld %d %s \n",
		(get_time_in_miliseconds() - philos.data->start_time),
		(philos.philo_id + 1), str);
}
