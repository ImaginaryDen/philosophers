#include "philo.h"

int main(int argc, char **argv)
{
	t_info info;
	pthread_t spect;
	int		i;

	if (argc != 5 && argc != 6 && parsing(argc, argv, &info))
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	info.start = get_time();
	init_mutex(&info);
	init_philo(&info);
	pthread_mutex_lock(&info.stop);
	i = 0;
	while (i < info.num_philo)
	{
		pthread_create(info.threads + i, NULL, philo_eat, info.philos + i);
		pthread_detach(info.threads[i]);
		i++;
	}
	pthread_create(&spect, NULL, spectator, &info);
	pthread_mutex_lock(&info.stop);
	free_all(&info);
}