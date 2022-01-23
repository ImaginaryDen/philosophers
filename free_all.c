/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:32 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 16:19:33 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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