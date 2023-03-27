/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:46:40 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/03/27 18:47:21 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || str[i] == '\f' || str[i] = '\n'
			|| str[i] = '\r' || str[i] = '\t' || str[i] == '\v')
		i++;
	if (str[i] == 45)
		neg = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		if ((res >= 2147483649 && neg == -1) || (res >= 2147483648 && neg == 1))
			return (-1);
		i++;
	}
	res *= neg;
	return ((int)res);
}

int	error_msg(void)
{
	printf("\nWrong arguments\n");
	printf("Example : ./philo <num of philosophers> <time to die>
			 <time to eat> [number of meals]");
   return (-1);	
}
