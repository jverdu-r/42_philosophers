/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:51:02 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/10/30 15:51:04 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (init_info(&info, ac, av))
		return (0);
	if (init_philos(&info))
		return (free_info(&info));
	if (init_mutex(&info))
		return (free_destroy(&info));
	if (create_philos(&info))
		return (0);
	destroy(&info);
}
