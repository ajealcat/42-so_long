/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:15:04 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/04 14:20:30 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	error_message(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\n Map must be surrounded by walls", 2);
	if (i == 2)
		ft_putstr_fd("Error\n Map must have at least one exit", 2);
	if (i == 3)
		ft_putstr_fd("Error\n Map must have at least one collectible", 2);
	if (i == 4)
		ft_putstr_fd("Error\n Map must have one starting position", 2);
	if (i == 5)
		ft_putstr_fd("Error\n Map must be rectangular", 2);
}


