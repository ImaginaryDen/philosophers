/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:48:42 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/25 15:52:04 by tjamis           ###   ########.fr       */
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

	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_EAT);
	sem_close(info->eat_sem);
	sem_close(info->forks);
	sem_close(info->write_sem);
	i = 0;
	while (i < info->num_philos)
	{
		kill(info->pids[i], SIGTERM);
		i++;
	}
	if (info->pids)
		free(info->pids);
}

unsigned int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	message(t_info *info, char *msg)
{
	sem_wait(info->write_sem);
	if (info->live != 0)
		printf("%d %d %s\n", get_time() - info->start, info->id + 1, msg);
	sem_post(info->write_sem);
}
