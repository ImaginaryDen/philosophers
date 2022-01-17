#include "philo.h"

void	*spectator(void *info_v)
{
	int	i;
	const t_info *info = info_v;

	i = 0;
	while (1)
	{
		if (i == info->num_philo)
			i = 0;
		if (info->time_to_die >= get_time() - info->philos[i].last_meal)
		{
			pthread_mutex_unlock(&((t_info *)info)->stop);
			return(0);
		}
		i++;
	}
}