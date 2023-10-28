
#include "../inc/philo.h"

int	init_philo(t_params *params, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < params->num)
	{
		philo[i].id = i;
		philo[i].dead = 0;
		philo[i].meals_num = 0;
		philo[i].thread_st = 0;
		philo[i].meal = 0;
		philo[i].params = params;
		philo[i].lfork = &params->fork[i];
		philo[i].rfork = 0;
	}
	return (0);
}

static int	init_params_mutex(t_params *params)
{
	int i;

	i = -1;
	params->death = 0;
	params->fork = 0;
	params->death = malloc(sizeof(pthread_mutex_t));
	if (!params->death)
		return (error_msg("ERROR\nMutex death: memory allocation failed\n", params, 0, 1));
	params->fork = malloc(sizeof(pthread_mutex_t));
	if (!params->fork)
		return (error_msg("ERRPR\nMutex fork: memory allocation failed\n", params, 0, 1));
	if (pthread_mutex_init(params->death, NULL) == - 1)
		return (error_msg("ERROR\nMutex init failed\n", params, 0, 1));
	while (++i < params->num)
		if (pthread_mutex_init(&params->fork[i], NULL) == -1)
			return (error_msg("ERROR\nMutex init failed\n", params, 0, 1));
	return (0);
}

static int	init_params(t_params *params, char **args)
{
	int	mutex;

	mutex = -1;
	params->num = ft_atoi(args[1]);
	params->ttd = ft_atoi(args[2]);
	params->tte = ft_atoi(args[3]);
	params->tts = ft_atoi(args[4]);
	params->max_meals = -2;
	params->meal = 0;
	params->start = 0;
	params->ready = 0;
	if (args[5])
	{
		params->max_meals = ft_atoi(args[5]);
		params->meal = 1;
	}
	params->over = 0;
	if (params->num > 0)
		mutex = init_params_mutex(params);
	return (mutex || params->num <= 0 || params->ttd <= 0 || params->tte <= 0
			|| params->tts <= 0 || params-> max_meals == 0);
}

int	main(int argn, char **args)
{
	t_params	params;

	if ((argn != 5 && argn != 6) || init_params(&params, args))
		return (error_msg("ERROR: invalid arguments\n", &params, 0, 1));
	if (philosophers(&params))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
