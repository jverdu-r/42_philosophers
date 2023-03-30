/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:14:14 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/03/30 19:04:54 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	*routine(void *params)
{
	int		i;
	t_philo	*philo;
	t_env	*env;

	i = 0;
	philo = (t_philo *)params;
	env = philo->env;
	if (philo->pos % 2 && env->count > 1)
		philo_sleep(env->tto_eat / 50, env);
	while (!env->stop_con && !env->max_meals)
	{
		philo_eat(philo);
		philo_tell("is sleeping", philo, UNLOCK);
		philo_sleep(env->tto_sleep, env);
		philo_tell("is thinking", philo, UNLOCK);
	}
	return (NULL);
}

static void	thread_exit(t_env *env)
{
	int	i;

	if (env->count == 1)
		pthread_detach(env->philos[0].philo_id);
	else
	{
		i = -1;
		while (++i < env->count)
			pthread_join(env->philos[i].philo_id, NULL);
	}
	i = -1;
	while (++i < env->count)
		pthread_mutex_destroy(&env->forks[i]);
	pthread_mutex_destroy(&env->meal);
	pthread_mutex_destroy(&env->writing);
	free(env->philos);
	free(env->forks);	
}

int	thread_start(t_env *env)
{
	int	i;

	i = 0;
	env->start_time = get_time(); /*funcion para obtener el tiempo del ordenador*/
	while (i < env->count)
	{
		env->philos[i].last_meal = get_time();
		if (pthread_create(&env->philos[i].philo_id,
					NULL, routine, &(env->philos[i]))) /* routine es la funcion de la rutina de los filosofos*/
			return (0);
	}
	philo_dead(env, env->philos); /*matamos los filosofos*/
	pthread_mutex_unlock(&env->writing);
	exit_threads(env);
	return (1);
}
