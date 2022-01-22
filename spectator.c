/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:52 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 21:32:05 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_all(t_info *info)
{
	int i;

	i = 0;
	while (i < info->num_philo)
	{
		if (info->philos[i].eat_count)
			return (0);
		i++;
	}
	usleep(info->time_to_sleep * 1100);
	pthread_mutex_lock(&info->message);
	printf("all done\n");
	pthread_mutex_unlock(&info->stop);
	return (1);
}

void	*spectator(void *info_v)
{
	int	i;
	t_info *info;

	info = info_v;
	i = 0;
	while (1)
	{
		if (i == info->num_philo)
		{
			if (info->max_eat != -1 && check_all(info))
				return (0);
			usleep(100);
			i = 0;
		}
		pthread_mutex_lock(&info->philos[i].eat);
		//printf("%d check %d\n", get_time() - info->start, i + 1);
		if (info->time_to_die <= get_time() - info->philos[i].last_meal && info->philos[i].eat_count)
		{
			pthread_mutex_lock(&info->message);
			printf("%d %d is died\n", get_time() - info->start, info->philos[i].num + 1);
			pthread_mutex_unlock(&info->stop);
			return(0);
		}
		pthread_mutex_unlock(&info->philos[i].eat);
		i++;
	}
}