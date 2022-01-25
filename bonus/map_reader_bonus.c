/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:14:13 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/15 20:11:58 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_message(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nMap must be surrounded by walls", 2);
	if (i == 2)
		ft_putstr_fd("Error\nMap must have at least one exit", 2);
	if (i == 3)
		ft_putstr_fd("Error\nMap must have at least one collectible", 2);
	if (i == 4)
		ft_putstr_fd("Error\nMap must have one starting position", 2);
	if (i == 5)
		ft_putstr_fd("Error\nMap must be rectangular", 2);
	if (i == 6)
		ft_putstr_fd("Error\nInvalid instructions", 2);
	if (i == 7)
		ft_putstr_fd("Error\nInvalid file", 2);
	return (-1);
}

int	global_checker(t_map *map)
{
	if (map->mappy == NULL)
		return (-1);
	if (check_size(map) == -1)
		return (-1);
	if (check_walls(map) == -1)
		return (-1);
	if (is_available_entry(map) == -1)
		return (-1);
	if (check_p(map) == -1)
		return (-1);
	if (check_c(map) == -1)
		return (-1);
	if (check_e(map) == -1)
		return (-1);
	return (0);
}
