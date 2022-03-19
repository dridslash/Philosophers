/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:09:11 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/28 13:54:14 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold_routine_one(t_philo *pl)
{
	pthread_mutex_lock(pl->right_fork);
	pthread_mutex_lock(pl->msg);
	printf("%ld %d has taken a fork\n",
		(get_time_in_miliseconds() - pl->data->start_time), (pl->philo_id + 1));
	pthread_mutex_unlock(pl->msg);
	pthread_mutex_lock(pl->left_fork);
	pthread_mutex_lock(pl->msg);
	printf("%ld %d has taken a fork\n",
		(get_time_in_miliseconds() - pl->data->start_time), (pl->philo_id + 1));
	pthread_mutex_unlock(pl->msg);
	pthread_mutex_lock(pl->msg);
	printf("%ld %d is eating \n",
		(get_time_in_miliseconds() - pl->data->start_time), (pl->philo_id + 1));
	pthread_mutex_unlock(pl->msg);
		pl->number_of_times_eaten++;
		pl->last_time_eat = get_time_in_miliseconds();
	imp_usleep((pl->data->time_to_eat));
	pthread_mutex_unlock(pl->left_fork);
	pthread_mutex_unlock(pl->right_fork);
}

void	hold_routine_two(t_philo *pl)
{
	pthread_mutex_lock(pl->msg);
	printf("%ld %d is sleeping \n",
		(get_time_in_miliseconds() - pl->data->start_time), (pl->philo_id + 1));
	pthread_mutex_unlock(pl->msg);
	imp_usleep((pl->data->time_to_sleep));
	pthread_mutex_lock(pl->msg);
	printf("%ld %d is thinking \n",
		(get_time_in_miliseconds() - pl->data->start_time), (pl->philo_id + 1));
	pthread_mutex_unlock(pl->msg);
}

void	*routine(void *arg)
{
	t_philo	*pl;

	pl = (t_philo *)arg;
	pl->data->start_time = get_time_in_miliseconds();
	while (1)
	{
		hold_routine_one(pl);
		hold_routine_two(pl);
	}
	return (NULL);
}

int	create_threads(t_philo *philos, t_all *glob)
{
	int	i;

	if (pthread_mutex_init(&glob->msg, NULL) != 0)
		return (0);
	i = 0;
	while (i < glob->number_of_philos)
	{
		philos[i].data = glob;
		philos[i].right_fork = &glob->forks[i];
		philos[i].left_fork = &glob->forks[(i + 1) % glob->number_of_philos];
		philos[i].philo_id = i;
		philos[i].msg = &glob->msg;
		philos[i].data->state = ALIVE;
		philos[i].last_time_eat = get_time_in_miliseconds();
		if (pthread_create(&philos[i].philosopher,
				NULL, routine, &philos[i]) != 0)
			return (0);
		usleep(30);
		i++;
	}
	return (3);
}

int	main(int argc, char **argv)
{
	t_all	*glob;
	t_philo	*philos;

	glob = NULL;
	philos = NULL;
	if (main_helper(argc, argv, philos, glob) == 0)
		return (0);
	return (0);
}
