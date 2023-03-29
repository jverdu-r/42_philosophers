/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:35:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/03/29 18:17:34 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_philo
{
	int				meals;
	int				pos;
	int				l_fork;
	int				r_fork;
	unsigned long	last_meal;
	struct s_env	*env;
	pthread_t		philo_id;
}t_philo;

typedef struct s_env
{
	int				count;
	int				tto_die;
	int				tto_eat;
	int				tto_sleep;
	int				max_meals;
	int				meals_count;
	int				stop_con;
	unsigned long	start_time;
	t_philo			*philos;
	pthread_mutex_t *forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	writing;
}t_env;

int	ft_atoi(const char *str);
int	ft_isint(const char *str);
int error_msg(char *str);
int	load_resources(t_env *env);

# endif
