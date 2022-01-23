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
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	info->threads = malloc(sizeof(pthread_t) * info->num_philo);
	if (info->forks == NULL)
		return (1);
	// memset(info->forks, 0, 256 * sizeof(pthread_mutex_t));
	while (i < info->num_philo)
	{
		pthread_mutex_init(info->forks + i, NULL);
		i++;
	}
	return(0);
}