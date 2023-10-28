
#include "../inc/philo.h"

int	error_msg(char *s, t_params *params, t_philo *philo, int malloc)
{
	if (malloc)
	{
		if (params->death)
			free(params->death);
		if (params->fork)
			free(params->fork);
		if (philo)
			free(philo);
	}		
	return (printf("%s", s));
}

void	print_routine(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->params->death);
	if (philo->params->over)
	{
		pthread_mutex_unlock(philo->params->death);
		return ;
	}
	printf("%ldms %d %s\n", time_now() - philo->thread_st,
		philo->id, action);
	pthread_mutex_unlock(philo->params->death);
}

void	final_print(int alive)
{
	printf("						\n");
	if (alive)
		printf("We all life to continue thinking\n");
	else
		printf("...\n");
	printf("						\n");
}
