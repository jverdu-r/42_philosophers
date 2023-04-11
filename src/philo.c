/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:41:10 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/04/11 18:15:50 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	checker(t_env *env, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	env->count = ft_atoi(argv[1]);
	env->tto_die = ft_atoi(argv[2]);
	env->tto_eat = ft_atoi(argv[3]);
	env->tto_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		env->meals_count = ft_atoi(argv[5]);
	else
		env->meals_count = 0;
	if (env->count < 1 || env->tto_die < 0 || env->tto_eat < 0 \
			|| env->tto_sleep < 0 || env->max_meals < 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_env	env;

	env.max_meals = 0;
	env.stop_con = 0;
	if (argc < 5 || argc > 6)
		return (error_msg("Wrong number of arguments.\n"));
	if (!checker(&env, argc, argv))
		return (error_msg("Wrong parameters.\n"));
	else
	{
		if (!load_resources(&env))
			return (error_msg("Load error.\n"));
		if (!thread_start(&env))
			return (error_msg("Could not start the threads.\n"));
	}
	return (0);
}
