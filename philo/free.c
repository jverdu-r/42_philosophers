/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:50:44 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/10/30 15:50:45 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_info(t_info *info)
{
	free(info->philos);
	free(info->forks);
	return (0);
}

int	free_destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&info->forks[i]);
	free_info(info);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->finish_mutex);
	return (0);
}

void	join_free_destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_join(info->philos[i].thread, NULL);
	free_destroy(info);
}

void	destroy(t_info *info)
{
	int	i;
	int	yes;

	yes = 1;
	while (yes)
	{
		i = -1;
		info->num_full_philo = 0;
		while (++i < info->num_philo)
		{
			if (yes && check_dead(&info->philos[i]))
				yes = 0;
		}
		usleep(10);
	}
	join_free_destroy(info);
}
