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

int	init_sem(t_info *info)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_EAT);
	info->forks = sem_open(SEM_FORKS, O_CREAT, 0777, info->num_philos);
	info->write_sem = sem_open(SEM_WRITE, O_CREAT, 0777, 1);
	info->eat_sem = sem_open(SEM_EAT, O_CREAT, 0777, 1);
	if (info->forks == SEM_FAILED || info->write_sem == SEM_FAILED
		|| info->eat_sem == SEM_FAILED)
		return (1);
	return (0);
}