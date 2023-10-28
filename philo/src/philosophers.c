#include "../inc/philo.h"

#include "../inc/philo.h"

static int	check_meals(t_philo philo, int last)
{
	if (philo.params->meal
		&& last == philo.params->num - 1
		&& philo.meals_num == philo.params->max_meals)
		return (ft_usleep(300));
	return (0);
}

static void	check_thread(t_params *params, t_philo *philo)
{
	int	i;

	while (!params->ready)
		continue ;
	while (!params->over)
	{
		i = -1;
		while (++i < params->num)
			if (check_death(&philo[i]) || check_meals(philo[i], i))
				params->over = 1;
	}
	if (params->meal && philo[params->num - 1].meals_num == params->max_meals)
	{
		ft_usleep(5 * params->num);
		printf("						\n");
		printf("  All philosophers have eaten %d times\n", params->max_meals);
		return (final_print(1));
	}
	return (final_print(0));
}

static int	init_thread(t_params *params, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < params->num)
	{
		philo[i].rfork = philo[(i + 1) % params->num].lfork;
		if (pthread_create(&philo[i].life, NULL,
				&thread_routine, &philo[i]) == -1)
			return (error_msg("Error\nFailed to create thread\n", params, philo, 2));
	}
	i = -1;
	params->start = time_now();
	while (++i < params->num)
	{
		philo[i].thread_st = params->start;
		philo[i].meal = params->start;
	}
	params->ready = 1;
	return (0);
}

static void	end_thread(t_params *params, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < params->num)
		pthread_join(philo[i].life, (void *)&philo[i]);
	pthread_mutex_destroy(params->death);
	pthread_mutex_destroy(params->fork);
	free(params->death);
	free(params->fork);
	free(philo);
}

int	philosophers(t_params *params)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * params->num);
	if (!philo || init_philo(params, philo))
		return (EXIT_FAILURE);
	if (init_thread(params, philo))
		return (EXIT_FAILURE);
	check_thread(params, philo);
	end_thread(params, philo);
	return (0);
}
