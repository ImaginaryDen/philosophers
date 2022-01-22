/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:47 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 21:28:21 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->hand_r]);
	message(philo, "taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->hand_l]);
	message(philo, "taken a fork");

	pthread_mutex_lock(&philo->eat);
}

void eating(t_philo *philo)
{
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

void *check_death(void *philo_v)
{
	t_philo *philo;
	int time_sleep;
	int time;

	philo = philo_v;
	while (philo->eat_count && philo->data->live)
	{
		time_sleep = philo->eat_time - (get_time() - philo->last_meal);
		if (time_sleep > 0)
			ft_usleep(time_sleep);
		pthread_mutex_lock(&philo->eat);
		time = philo->last_meal;
		pthread_mutex_unlock(&philo->eat);
		if((philo->data->time_to_die + 2 <= get_time() - time) && philo->eat_count)
		{
			philo->data->live = 0;
			printf("%d %d %d %d %d\n", philo->num + 1, philo->data->time_to_die , get_time() - philo->last_meal, philo->eat_count, philo->last_meal - philo->data->start);
			pthread_mutex_lock(&philo->data->message);
			printf("%d %d is died\n", get_time() - philo->data->start, philo->num + 1);
			pthread_mutex_unlock(&philo->data->stop);
			return (NULL);
		}
	}
	return (NULL);
}

void	*philo_eat(void *philo_v)
{
	t_philo *philo;
	pthread_t spectr;

	philo = philo_v;
	if (philo->num % 2)
		ft_usleep(10);
	//pthread_create(&spectr, NULL, check_death, philo);
	//pthread_detach(spectr);
	while (philo->data->live)
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