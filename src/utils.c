/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:08 by aberenge          #+#    #+#             */
/*   Updated: 2025/01/14 21:39:33 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	exit_error(char *err)
{
	ft_printf("%s\n", err);
	exit(EXIT_FAILURE);
}

int	skippable(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	*safe_malloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		exit_error("Malloc error");
	return (res);
}
