/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:52:45 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/10/30 15:52:47 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo)
{
	sem_wait(philo->info->forks);
	print_status(philo, "has taken a fork");
	sem_wait(philo->info->forks);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	ft_sleep(philo->info->time_to_eat);
	sem_wait(philo->info->eat_sem);
	philo->eat_cnt += 1;
	philo->last_eat_time = get_time();
	sem_post(philo->info->eat_sem);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	*check_dead(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (42)
	{
		sem_wait(philo->info->eat_sem);
		if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
		{
			sem_post(philo->info->eat_sem);
			print_status(philo, "died");
			sem_wait(philo->info->print_sem);
			philo->info->finish = 1;
			exit(1);
		}
		if (philo->info->num_must_eat > 0 && philo->eat_cnt >= \
				philo->info->num_must_eat)
		{
			sem_post(philo->info->eat_sem);
			exit(1);
			break ;
		}
		sem_post(philo->info->eat_sem);
		usleep(5000);
	}
	return (NULL);
}

void	philo_start(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->finish)
	{
		eat(philo);
		print_status(philo, "is sleeping");
		ft_sleep(philo->info->time_to_sleep);
		print_status(philo, "is thinking");
	}
	exit(0);
}
