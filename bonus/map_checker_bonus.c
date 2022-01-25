/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:15:04 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/20 14:57:51 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int	check_size(t_map map)
{
	int i;

	i = 0;
	while (map.mappy[i])
	{
		if (ft_strlen(map.mappy[i]) != (size_t)map.width)
			return (error_message(5));
		++i;
	}
	if (i != map.lengh)
		return (error_message(5));
	return (0);
}

int	check_walls(t_map map)
{
	int i;
	
	i = 0;
	while (i < map.width)
	{
		if(map.mappy[0][i] != '1') 
			return (error_message(1));
		if (map.mappy[map.lengh - 1][i] != '1')
			return (error_message(1));
		++i;
	}
	i = 0;
	while (i < map.lengh)
	{
		if (map.mappy[i][0] != '1')
			return(error_message(1));
		if (map.mappy[i][map.width - 1] != '1')
			return(error_message(1));
		++i;
	}
	return (0);
}

int	check_p(t_map map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map.mappy[i])
	{
		j = 0;
		while (map.mappy[i][j])
		{
			if (map.mappy[i][j] == 'P')
				++count;
			++j;
		}
		++i;
	}
	if (count != 1)
		return (error_message(4));
	return (0);
}

int	check_c(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map->mappy[i])
	{
		j = 0;
		while (map->mappy[i][j])
		{
			if (map->mappy[i][j] == 'C')
				++count;
			++j;
		}
		++i;
	}
	map->collectibles_nbr = count;
	if (count < 1)
		return (error_message(3));
	return (0);
}

int	check_e(t_map map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map.mappy[i])
	{
		j = 0;
		while (map.mappy[i][j])
		{
			if (map.mappy[i][j] == 'E')
				++count;
			++j;
		}
		++i;
	}
	if (count < 1)
		return (error_message(2));
	return (0);
}

int	is_available_entry(t_map map)
{
	int i;
	int j;

	i = 0;
	while (map.mappy[i])
	{
		j = 0;
		while (map.mappy[i][j])
		{
			if (map.mappy[i][j] != '1' && map.mappy[i][j] != '0' && map.mappy[i][j] != 'P' 
			&& map.mappy[i][j] != 'C' && map.mappy[i][j] != 'E')
				return (error_message(6));
			++j;
		}
		++i;
	}
	return (0);
}
