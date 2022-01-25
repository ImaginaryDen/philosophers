/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:40 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/25 15:56:58 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_fork(t_info *info)
{
	int	i;

	info->pids = (pid_t *)malloc(sizeof(pid_t) * info->num_philos);
	info->start = get_time();
	i = 0;
	info->last_meal = info->start;
	info->live = 1;
	while (i < info->num_philos)
	{
		info->pids[i] = fork();
		if (info->pids[i] < 0)
			return (0);
		else if (info->pids[i] == 0)
		{
			info->id = i;
			exit(philo_eat(info));
		}
		usleep(500);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_info		info;
	int			i;
	int			result;

	if (parsing(argc, argv, &info))
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	if (init_sem(&info))
		return (1);
	i = run_fork(&info);
	while (i)
	{
		waitpid(-1, &result, 0);
		if (result)
			break ;
		i--;
	}
	free_all(&info);
}
