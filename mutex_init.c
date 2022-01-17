#include "philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->message, NULL);
	pthread_mutex_init(&info->stop, NULL);
	while (i < info->num_philo)
	{
		pthread_mutex_init(info->forks + i, NULL);
		i++;
	}
}