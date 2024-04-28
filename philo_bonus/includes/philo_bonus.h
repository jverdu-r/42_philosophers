/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:42:18 by jorge             #+#    #+#             */
/*   Updated: 2024/04/28 16:45:50 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>

# define I_TOOK_FORK "%lld %d has taken a fork.\n"
# define IM_SLEEPING "%lld %d is sleeping.\n"
# define IM_THINKING "%lld %d is thinking.\n"
# define IM_EATING "%lld %d is eating.\n"
# define I_DIED "%lld %d has died\n"

typedef struct s_data
{
	int			number_to_eat;
	int			total_philos;
	long long	t_to_sleep;
	long long	t_to_eat;
	long long	t_to_die;
	sem_t		*filedes_sem;
}	t_data;

typedef struct s_philo
{
	pid_t		process_id;
	pthread_t	thread_id;
	int			num_ate;
	long long	t_ate;
	long long	st_time;
	t_data		*data;
	sem_t		*num_ate_sem;
	sem_t		*forks_sem;
	int			id;
}	t_philo;

int			validate_arguments(int total_args, char **arguments, t_data **data);
int			init_philo(t_data *data, t_philo **philo);
int			clear_philo(t_philo **philo);

void		ft_say(const char *expression, t_philo *philo);
int			ft_strlen(const char *str);
void		ft_usleep(long long time);
long long	ft_atoi(const char *num);
long long	ft_get_time(void);

#endif