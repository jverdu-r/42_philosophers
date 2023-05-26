/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:35:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/05/11 14:37:32 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	writing;
}t_env;

int				ft_atoi(const char *str);
int				ft_isint(const char *str);
int				error_msg(char *str);
int				load_resources(t_env *env);
int				thread_start(t_env *env);
void			philo_tell(char *msg, t_philo *philo, int unlock);
void			philo_eat(t_philo *philo);
void			philo_dead(t_env *env, t_philo *philo);
void			philo_sleep(unsigned long time, t_env *env);
unsigned long	get_time(void);

#endif
