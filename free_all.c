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
		pthread_join(info->threads[i], NULL);
		pthread_mutex_destroy(info->forks + i);
		pthread_mutex_destroy(&info->philos[i].eat);
		i++;
	}
	free(info->forks);
	free(info->philos);
	free(info->threads);
}