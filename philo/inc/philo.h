
#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/time.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "just die, pray for him"
# define LEFT 0
# define RIGHT 1

typedef struct	s_params
{
	int		num;
	int		ready;
	int		ttd;
	int		tte;
	int		tts;
	int		max_meals;
	int		meal;
	int		over;
	long int	start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}	t_params;

typedef struct	s_philo
{
	int		id;
	int		dead;
	int		meals_num;
	long int	thread_st;
	long int	meal;
	pthread_t	life;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	t_params	*params;
}	t_philo;

int		philosophers(t_params *params);
int		init_philo(t_params *params, t_philo *philo);
int		check_death(t_philo *philo);
int		ft_atoi(const char *str);
int		ft_usleep(long int time);
int		error_msg(char *s, t_params *params, t_philo *philo, int malloc);
void		*thread_routine(void *job);
void		final_print(int alive);
void		print_routine(t_philo *philo, char *action);
long int	time_now(void);

#endif
