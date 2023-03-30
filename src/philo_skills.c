/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_skills.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:07:37 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/03/30 19:56:59 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_tell(char *msg, t_philo *philo, int unlock)
{
	int	time;

	time = get_time() - philo->env->start_time;
	pthread_mutex_lock(&philo->env->writing);
	if (!philo->env->stop_con && !philo->env->max_meals)
		printf("%d philo %d: %s\n", time, philo->pos, msg);
	if (unlock == 1)
		pthread_mutex_unlock(philo->env->writing);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->forks[philo->l_fork]);
	philo_tell("has taken left_fork", philo, 1);
	pthread_mutex_lock(&philo->env->forks[philo->r_fork]);
	philo_tell("has taken right_fork", philo, 1);
	pthread_mutex_lock(&philo->env->meal);
	philo_tell("is eating", philo, 1);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->env->meal);
	philo_sleep(philo->env->tto_eat, philo->env);
	philo->meals++;
	pthread_mutex_unlock(&philo->env->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->env->forks[philo->l_fork]);
}
