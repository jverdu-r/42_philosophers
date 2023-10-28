
#include "../inc/philo.h"

int	someone_died(t_philo *philo)
{
	print_routine(philo, DIE);
	philo->params->over = 1;
	philo->dead = 1;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (1);
}

int	check_death(t_philo *philo)
{
	long int	now;

	pthread_mutex_lock(philo->params->death);
	now = time_now() - philo->meal;
	if (now >= philo->params->ttd)
	{
		pthread_mutex_unlock(philo->params->death);
		return (someone_died(philo));
	}
	pthread_mutex_unlock(philo->params->death);
	return (0);
}

void	ft_sleep_and_think(t_philo *philo)
{
	ft_usleep(philo->params->tts);
	print_routine(philo, SLEEP);
	print_routine(philo, THINK);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_routine(philo, FORK);
	pthread_mutex_lock(philo->rfork);
	print_routine(philo, FORK);
	philo->meal = time_now();
	ft_usleep(philo->params->tte);
	print_routine(philo, EAT);
	philo->meals_num++;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	*thread_routine(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	while (!philo->params->ready)
		continue ;
	if (philo->id & 1)
		ft_usleep(philo->params->tte * 0.9 + 1);
	while (!philo->params->over)
	{
		ft_eat(philo);
		ft_sleep_and_think(philo);
	}
	return (NULL);
}
