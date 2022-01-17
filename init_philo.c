#include "philo.h"

void	init_philo(t_info *info)
{
	int i;

	i = 0;
	while (i < info->num_philo)
	{
		info->philos[i].data = info;
		info->philos[i].eat_time = info->time_to_eat;
		info->philos[i].eat_count = info->max_eat;
		info->philos[i].last_meal = get_time();	
		info->philos[i].num = i;
		info->philos[i].hand_r = i;
		info->philos[i].hand_l = (i + 1) % info->num_philo;
		i++;
	}
}