/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:29:46 by aberenge          #+#    #+#             */
/*   Updated: 2025/01/14 14:29:46 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include "libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

# define RST "ntm"

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals;
	int			full;
	long		last_meal;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	limit_meals;
	long	start_simu;
	int		end_simu;
	t_fork	*forks;
	t_philo	*philos;
}	t_table;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

void	exit_error(char *err);
int		skippable(char c);
void	*safe_malloc(size_t size);

void	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode);
void	safe_thread_handle(pthread_t *thread, void *(*fct)(void *),
			void *data, t_opcode opcode);

void	parse_input(t_table *table, char **argv);

void	init_data(t_table *table);

#endif
