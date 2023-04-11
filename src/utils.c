/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:46:40 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/04/11 18:22:52 by jverdu-r         ###   ########.fr       */
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
	while (str[i] == 32 || str[i] == '\f' || str[i] == '\n' \
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == 45)
		neg = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		if ((res >= 2147483649 && neg == -1) || (res >= 2147483648 && neg == 1))
			return (-1);
		i++;
	}
	res *= neg;
	return ((int)res);
}

int	ft_isint(const char *str)
{
	int		i;
	int		neg;
	long	val;

	i = 0;
	val = 0;
	neg = 0;
	while (str[i] == 32 || str[i] == '\f' || str[i] == '\n' \
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < 47 || str[i] > 58)
			return (0);
		i++;
	}
	return (1);
}

int	error_msg(char *str)
{
	printf("\nERROR: %s", str);
	return (1);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}
