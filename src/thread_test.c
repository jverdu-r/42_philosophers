#include "../inc/philo.h"

void	*my_thread_fun(void *vargp)
{
	usleep(1000000);
	printf("%s", "Printing thread\n");
	return (NULL);
}

int	main(void)
{
	pthread_t	thread_id;

	printf("%s", "Before thread\n");
	pthread_create(&thread_id, NULL, my_thread_fun, NULL);
	pthread_join(thread_id, NULL);
	printf("%s", "After thread\n");
	return (0);
}
