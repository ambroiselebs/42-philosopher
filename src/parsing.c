/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:36:50 by aberenge          #+#    #+#             */
/*   Updated: 2025/01/14 21:37:21 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	valid_input(char *str)
{
	int		len;
	char	*num;

	len = 0;
	while (skippable(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		exit_error("Only positive value are accepted");
	if (!ft_isdigit(*str))
		exit_error("Values must be numbers");
	num = str;
	while (ft_isdigit(*str++))
		len++;
	if (len > 10)
		exit_error("Numbers must be under INT_MAX");
	return (num);
}

long	parse_arg(char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (ft_isdigit(*str))
		num = (num * 10) + (*str++ - 48);
	if (num > INT_MAX)
		exit_error("Numbers must be under INT_MAX");
	return (num);
}

void	parse_input(t_table *table, char **argv)
{
	table->philo_nbr = parse_arg(argv[1]);
	table->time_to_die = parse_arg(argv[2]) * 1000;
	table->time_to_eat = parse_arg(argv[3]) * 1000;
	table->time_to_sleep = parse_arg(argv[4]) * 1000;
	if (table->time_to_die < 60000
		|| table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		exit_error("Timestamps needs to be over 60ms");
	if (argv[5])
		table->limit_meals = parse_arg(argv[5]);
	else
		table->limit_meals = -1;
}
