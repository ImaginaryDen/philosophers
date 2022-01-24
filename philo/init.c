/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:38 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 16:19:39 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_info *info)
{
	int i;

	i = 0;
	info->philos = malloc(sizeof(t_philo) * info->num_philo);
	if (info->philos == NULL)
		return (1);
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->philos[i].eat, NULL);
		info->philos[i].data = info;
		info->philos[i].eat_time = info->time_to_eat;
		info->philos[i].eat_count = info->max_eat;
		info->philos[i].last_meal = get_time();	
		info->philos[i].num = i;
		info->philos[i].hand_r = i;
		info->philos[i].hand_l = (i + 1) % info->num_philo;
		i++;
	}
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->message, NULL);
	info->threads = NULL;
	info->philos = NULL;
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_philo);
	info->threads = (pthread_t *)malloc(sizeof(pthread_t) * info->num_philo);
	if (info->threads == NULL || info->forks == NULL)
		return (1);
	while (i < info->num_philo)
	{
		pthread_mutex_init(info->forks + i, NULL);
		info->threads[i];
		i++;
	}
	return(0);
}