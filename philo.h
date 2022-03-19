/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:06:50 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/28 13:58:56 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ALIVE 1
# define TRUE 1
# define DEAD 0

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct ALL
{
	long			start_time;
	int				number_of_philos;
	pthread_mutex_t	*forks;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	int				eat_times;
	pthread_mutex_t	msg;
	int				state;
}t_all;

typedef struct philos
{
	pthread_t		philosopher;
	pthread_mutex_t	*msg;
	pthread_mutex_t	meal_eat;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				philo_id;
	long			last_time_eat;
	long			last_time_sleep;
	long			pick_fork;
	int				number_of_times_eaten;
	t_all			*data;
}t_philo;

long long	ft_atoi(const char *nptr);
int			ft_isdigit(int arg);
char		*ft_strdup(const char *src);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);
long		get_time_in_miliseconds(void);
void		imp_usleep(long long time);
void		pick_forks(t_philo *pl);
void		eating(t_philo *pl);
void		go_sleep(t_philo *pl);
void		put_forks(t_philo *pl);
int			creat_mutex(t_philo *philos, t_all *glob);
int			destroy_mutex(t_philo *philos, t_all *glob);
int			observer(t_philo *philos, t_all *glob, int loop);
int			set_rules(t_philo **philos, t_all **glob, char **argv, int argc);
int			ft_check_input(char **argv);
int			ft_isdigit_imp(char *arg);
int			ft_isalpha(char *chr);
int			ft_is_empty(char *arg);
int			check_rules(int argc, char **argv);
int			main_helper(int argc, char **argv, t_philo *philos, t_all *glob);
int			create_threads(t_philo *philos, t_all *glob);
void		print(char	*str, t_philo philos);

#endif