/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:14:14 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/03/29 19:23:21 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
