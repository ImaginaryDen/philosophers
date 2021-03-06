/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:47 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/25 15:45:46 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->hand_r]);
	message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->hand_l]);
	message(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->eat);
	message(philo, "is eating");
	ft_usleep(philo->eat_time);
	pthread_mutex_unlock(&philo->data->forks[philo->hand_l]);
	pthread_mutex_unlock(&philo->data->forks[philo->hand_r]);
	if (philo->eat_count != -1)
		philo->eat_count--;
}

void	sleeping(t_philo *philo)
{
	message(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	message(philo, "is thinking");
}

void	*philo_eat(void *philo_v)
{
	t_philo		*philo;

	philo = philo_v;
	if (philo->num % 2)
		ft_usleep(1);
	if (philo->data->num_philo == 1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->hand_r]);
		message(philo, "taken a fork");
		while (philo->data->live)
			;
	}
	while (philo->data->live)
	{
		if (philo->eat_count == 0)
		{
			message(philo, "is done");
			return (0);
		}
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
