/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:52 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/25 15:53:59 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*spectator(void *info_v)
{
	t_info	*info;
	int		time;

	info = info_v;
	while (info->live)
	{
		time = info->time_to_die - (get_time() - info->last_meal);
		if (time > 0)
			ft_usleep(time);
		if (info->eat_count == 0)
			return (NULL);
		sem_wait(info->eat_sem);
		if (info->time_to_die + 5 <= get_time() - info->last_meal
			&& info->eat_count)
		{
			sem_wait(info->write_sem);
			info->live = 0;
			printf("%d %d is died\n", get_time() - info->start, info->id + 1);
			exit(1);
		}
		sem_post(info->eat_sem);
	}
	return (NULL);
}
