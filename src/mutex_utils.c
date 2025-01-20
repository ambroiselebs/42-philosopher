/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 16:29:12 by aberenge          #+#    #+#             */
/*   Updated: 2025-01-20 16:29:12 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
		exit_error("The value given by mutex is invalid");
	else if (status == EINVAL && opcode == INIT)
		exit_error("The value givem by attr is invalid");
	else if (status == EDEADLK)
		exit_error("EDEADLK");
	else if (status == EPERM)
		exit_error("The current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		exit_error("Can't allocate enough memory to create another mutex");
	else if (status == EBUSY)
		exit_error("Mutex is locked");
}

void	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		exit_error("Wrong code for mutex");
}

void	handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		exit_error("No ressouces to create another thread");
	else if (status == EPERM)
		exit_error("Does not have the permissions needed");
	else if (status == EINVAL && opcode == CREATE)
		exit_error("The given value is invalid");
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		exit_error("The given value is nit joinable");
	else if (status == ESRCH)
		exit_error("ESRCH");
	else if (status == EDEADLK)
		exit_error("EDEADLK");
}

void	safe_thread_handle(pthread_t *thread, void *(*fct)(void *),
							void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		handle_thread_error(pthread_create(thread, NULL, fct, data), opcode);
	else if (opcode == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		exit_error("Wrong code for thread");
}
