/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:23 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 16:54:06 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->message);
	if (philo->data->live == 0)
	{
		pthread_mutex_unlock(&philo->data->message);
		return ;
	}
	printf("%d %d %s\n", get_time() - philo->data->start, philo->num + 1, msg);
	pthread_mutex_unlock(&philo->data->message);
}