/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:45:03 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/25 15:45:05 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int ms)
{
	long	time;

	time = get_time();
	usleep(ms * 920);
	while (get_time() < time + (long)ms)
		usleep(ms * 3);
}

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->message);
	while (i < info->num_philo)
	{
		if (info->threads)
			pthread_join(info->threads[i], NULL);
		if (info->forks)
			pthread_mutex_destroy(info->forks + i);
		if (info->philos)
			pthread_mutex_destroy(&info->philos[i].eat);
		i++;
	}
	if (info->forks)
		free(info->forks);
	if (info->philos)
		free(info->philos);
	if (info->threads)
		free(info->threads);
}

unsigned int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->message);
	if (philo->data->live == 0)
	{
		pthread_mutex_unlock(&philo->data->message);
		return ;
	}
	printf("%d %d %s\n", get_time() - philo->data->start, philo->num + 1, msg);
	pthread_mutex_unlock(&philo->data->message);
}
