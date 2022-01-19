/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:47 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 18:34:28 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_fork(t_philo *philo)
{
	if (philo->hand_l < philo->hand_r)
	{
		pthread_mutex_lock(&philo->data->forks[philo->hand_l]);
		message(philo, "taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->hand_r]);
		message(philo, "taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->hand_r]);
		message(philo, "taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->hand_l]);
		message(philo, "taken a fork");
	}
}

void eating(t_philo *philo)
{
	philo->last_meal = get_time();
	pthread_mutex_lock(&philo->eat);
	message(philo, "is eating");
	usleep(philo->eat_time * 1000);
	pthread_mutex_unlock(&philo->eat);
	pthread_mutex_unlock(&philo->data->forks[philo->hand_l]);
	pthread_mutex_unlock(&philo->data->forks[philo->hand_r]);
	if (philo->eat_count != -1)
		philo->eat_count--;
}

void	sleeping(t_philo *philo)
{
	message(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	message(philo, "is thinking");
}

void	*philo_eat(void *philo_v)
{
	t_philo *philo;

	philo = philo_v;
	while (1)
	{
		if (philo->eat_count == 0)
		{
			message(philo, "is done");
			return (0);
		}
		take_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}