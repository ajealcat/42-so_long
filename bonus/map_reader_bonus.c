/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:14:13 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/26 19:30:24 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_message(int i)
{
	if (i == 1)
		ft_putstr_fd("\e[0;31mError\nMap must be surrounded by walls\n", 2);
	if (i == 2)
		ft_putstr_fd("\e[0;31mError\nMap must have at least one exit\n", 2);
	if (i == 3)
		ft_putstr_fd("\e[0;31mError\nMap must have at least one collectible\n", 2);
	if (i == 4)
		ft_putstr_fd("\e[0;31mError\nMap must have one starting position\n", 2);
	if (i == 5)
		ft_putstr_fd("\e[0;31mError\nMap must be rectangular\n", 2);
	if (i == 6)
		ft_putstr_fd("\e[0;31mError\nInvalid instructions\n", 2);
	if (i == 7)
		ft_putstr_fd("\e[0;31mError\nInvalid file\n", 2);
	return (-1);
}

int	is_available_entry(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->mappy[i])
	{
		j = 0;
		while (map->mappy[i][j])
		{
			if (map->mappy[i][j] != '1' && map->mappy[i][j] != '0' &&
				map->mappy[i][j] != 'P' && map->mappy[i][j] != 'C'
				&& map->mappy[i][j] != 'E' && map->mappy[i][j] != 'S')
				return (error_message(6));
			++j;
		}
		++i;
	}
	return (0);
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
