/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:49:01 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/04/11 17:59:46 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	load_mutex(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->count)
	{
		if (pthread_mutex_init(&(env->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&env->meal, NULL))
		return (1);
	if (pthread_mutex_init(&env->writing, NULL))
		return (1);
	return (0);
}

int	load_philo(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->count)
	{
		env->philos[i].meals = 0;
		env->philos[i].pos = i + 1;
		env->philos[i].l_fork = i;
		env->philos[i].r_fork = (i + 1) % env->count;
		env->philos[i].env = env;
		i++;
	}
	return (0);
}

int	load_resources(t_env *env)
{
	env->philos = malloc(sizeof(t_philo) * env->count);
	if (!env->philos)
		return (0);
	env->forks = malloc(sizeof(pthread_mutex_t) * env->count);
	if (!env->forks)
	{
		free(env->philos);
		return (0);
	}
	if (load_mutex(env))
	{
		free(env->philos);
		free(env->forks);
		return (0);
	}
	if (load_philo(env))
	{
		free(env->philos);
		free(env->forks);
		return (0);
	}
	return (1);
}
