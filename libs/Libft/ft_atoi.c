/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:43:23 by aberenge          #+#    #+#             */
/*   Updated: 2024/10/14 16:38:15 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	skipable(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static void	set_sign(char c, int *sign)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign *= -1;
	}
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (skipable(str[i]))
		i++;
	set_sign(str[i], &sign);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res = res * sign;
	if (res > INT_MAX)
		return (INT_MAX);
	if (res < INT_MIN)
		return (INT_MIN);
	return ((int) res);
}
