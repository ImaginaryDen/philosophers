/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:45 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/25 15:35:03 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
		return (1);
	info->num_philo = 0;
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		return (1);
	info->num_philo = ft_atoi(argv[1]);
	if (ft_atoi(argv[2]) < 60)
		return (1);
	info->time_to_die = ft_atoi(argv[2]);
	if (ft_atoi(argv[3]) < 60)
		return (1);
	info->time_to_eat = ft_atoi(argv[3]);
	if (ft_atoi(argv[4]) < 60)
		return (1);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->max_eat = -1;
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0)
			return (1);
		info->max_eat = ft_atoi(argv[5]);
	}
	info->live = 1;
	return (0);
}
