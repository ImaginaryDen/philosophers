/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:47 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 21:28:21 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_info *info)
{
	sem_wait(info->forks);
	message(info, "has taken a fork");
	sem_wait(info->forks);
	message(info, "has taken a fork");
}

void	eating(t_info *info)
{
	sem_wait(info->eat_sem);
	info->last_meal = get_time();
	message(info, "is eating");
	sem_post(info->eat_sem);
	ft_usleep(info->time_to_eat);
	sem_post(info->forks);
	sem_post(info->forks);
	if (info->eat_count != -1)
		info->eat_count--;
}

void	sleeping(t_info *info)
{
	message(info, "is sleeping");
	ft_usleep(info->time_to_sleep);
}

void	thinking(t_info *info)
{
	message(info, "is thinking");
}

int	philo_eat(t_info *info)
{
	pthread_t	spectr;

	pthread_create(&spectr, NULL, spectator, info);
	pthread_detach(spectr);
	if (info->num_philos == 1)
	{
		sem_wait(info->forks);
		message(info, "has taken a fork");
		while (info->live)
			;
	}
	while (info->live)
	{
		if (info->eat_count == 0)
		{
			message(info, "is done");
			return (0);
		}	
		take_fork(info);
		eating(info);
		sleeping(info);
		thinking(info);
	}
	return (1);
}
