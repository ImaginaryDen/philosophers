/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:50 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/25 15:48:29 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <unistd.h>

# define SEM_FORKS		"/forks"
# define SEM_WRITE		"/write"
# define SEM_EAT		"/eat"

typedef struct s_info
{
	int				id;
	pid_t			*pids;
	int				num_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				eat_count;
	int				last_meal;
	int				start;
	int				live;
	sem_t			*forks;
	sem_t			*write_sem;
	sem_t			*eat_sem;

}				t_info;

int				parsing(int argc, char **argv, t_info *info);
int				init_sem(t_info *info);
int				philo_eat(t_info *philo);
void			message(t_info *info, char *msg);
void			free_all(t_info *info);
unsigned int	get_time(void);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			ft_usleep(int ms);
void			*spectator(void *info_v);
#endif
