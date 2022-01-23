#include "philo.h"

void	ft_usleep(int ms)
{
	long	time;

	time = get_time();
	usleep(ms * 920);
	while (get_time() < time + (long)ms)
		usleep(ms * 3);
}