/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:33:38 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/26 15:23:56 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_range(const char *chr, int sign)
{
	int				index;
	long long		ret;

	ret = 0;
	index = 0;
	while (ft_isdigit(chr[index]))
	{
		ret = (ret * 10) + (chr[index] - '0');
		index++;
	}
	if ((ret > 9223372036854775807 || ret > 2147483647) && sign > 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (ret);
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	result = ft_range(&nptr[i], sign);
	return (result * sign);
}
