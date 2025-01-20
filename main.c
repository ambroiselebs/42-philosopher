/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:25:41 by aberenge          #+#    #+#             */
/*   Updated: 2025/01/14 14:25:41 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_table table;

	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argv);
		init_data(&table);
	}
	else
		exit_error("Error : Wrong input");

}
