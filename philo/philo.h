/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:14:26 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/11 23:55:04 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

enum	e_philo_status
{
	WAITING,
	EATING,
	SLEEPING,
	THINKING,
};

enum	e_fork_status
{
	READY_TO_EAT = 2,
};

typedef struct s_philos
{
	pthread_t		philo;
	int				left;
	int				right;
	int				status;
	int				fork_cnt;
	int				must_eat;
	struct s_table	*table;
}	t_philos;

typedef struct s_forks
{
	pthread_mutex_t	fork;
}	t_forks;

typedef struct s_table
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	struct s_forks	*forks;
}	t_table;

void	err_msg(char *str);
void	args_init(t_table *table, int ac, char **av);
void	table_init(t_table *table);
void	philos_init(t_table *table, t_philos *philos);
void	congression(t_table *table, t_philos *philos);
void	start_eating(t_philos *philos, int left, int right);
void	start_sleeping(t_philos *philos, int left);
void	start_thinking(t_philos *philos, int left);
int		philo_is_alive(void);
//philo_utils
void	set_fork_cursor(int	*left, int *right, int i, int num_of_philos);
int		philo_is_full(t_philos *philos);
void	milliseconds(int nanoseconds);
//utils
int		ft_atoi(const char *str);

#endif