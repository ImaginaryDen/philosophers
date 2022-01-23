/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:40 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 16:47:31 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_info info;
	pthread_t spect;
	int		i;

	if (parsing(argc, argv, &info))
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	info.start = get_time();
	if(init_mutex(&info) && init_philo(&info))
	{
		printf("Error alloc\n");
		return (1);
	}
	i = 0;
	while (i < info.num_philo)
	{
		pthread_create(info.threads + i, NULL, philo_eat, info.philos + i);
		i++;
	}
	return(1);
	pthread_create(&spect, NULL, spectator, &info);
	pthread_join(spect, NULL);
	free_all(&info);
}