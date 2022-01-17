#include "philo.h"

int	parsing(int argc, char **argv, t_info *info)
{
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[1]) > 256)
			return (1);
	info->num_philo = ft_atoi(argv[1]);
	if (ft_atoi(argv[2]) < 60)
			return (1);
	info->time_to_die = ft_atoi(argv[2]);
	if (ft_atoi(argv[3]) < 60)
			return (1);
	info->time_to_eat = ft_atoi(argv[3]);
	if (ft_atoi(argv[4]) < 60)
			return (1);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->max_eat = -1;
	if (argc == 5 && ft_atoi(argv[5]) != 0)
		info->max_eat = ft_atoi(argv[5]) != 0;
}