#include "philo.h"

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->message);
	pthread_mutex_destroy(&info->stop);
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(info->forks + i);
		pthread_mutex_destroy(&info->philos[i].eat);
		i++;
	}
}