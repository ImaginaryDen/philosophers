/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:44 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 16:40:41 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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