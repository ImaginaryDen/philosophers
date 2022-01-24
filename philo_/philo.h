/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:50 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/19 16:40:10 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>

struct s_info;

typedef struct s_philo
{
	struct s_info	*data;
	pthread_mutex_t	eat;
	int				eat_time;
	int				eat_count;
	int				last_meal;
	int				num;
	int				hand_r;
	int				hand_l;
}				t_philo;

typedef struct s_info
{
	struct s_philo	*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	int				live;
	int				start;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
}				t_info;

char			*ft_itoa(int n);
int				ft_atoi(const char *str);
int				parsing(int argc, char **argv, t_info *info);
unsigned int	get_time(void);
int				init_mutex(t_info *info);
void			*spectator(void *info_v);
void			free_all(t_info *info);
void			*philo_eat(void *philo_v);
int				init_philo(t_info *info);
void			message(t_philo *philo, char *msg);
void			ft_usleep(int ms);

#endif
