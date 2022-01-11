/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:15:04 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/11 13:11:55 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	check_size(t_map *map)
{
	int i;

	i = 0;
	printf("OK\n");
	while(map->map[i])
	{
		printf("OK SIZE : %d\n", i);
		if(ft_strlen(map->map[i]) != (size_t)map->width)
			return (error_message(5));
		++i;
	}	
	if (i != map->lengh)
		return (error_message(5));
	return (0);
}

int	check_walls(t_map *map)
{
	int i;
	
	i = 0;
	while (i < map->width)
	{
		if(map->map[0][i] != '1') 
			return (error_message(1));
		if (map->map[map->lengh][i] != '1')
			return (error_message(1));
		++i;
	}
	i = 0;
	while (i < map->lengh)
	{
		if (map->map[i][0] != '1')
			return(error_message(1));
		if (map->map[i][map->width] != '1')
			return(error_message(1));
		++i;
	}
	return (0);
}

int	check_p(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				++count;
			++j;
		}
		++i;
	}
	if (count != 1)
		return(error_message(4));
	return(0);
}

int	check_c(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				++count;
			++j;
		}
		++i;
	}
	if (count < 1)
		return(error_message(3));
	return(0);
}

int	check_e(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == 'E')
				++count;
			++j;
		}
		++i;
	}
	if (count < 1)
		return(error_message(2));
	return(0);
}

int	is_available_entry(t_map *map)
{
	int i;
	int j;

	i = 0;
	while(map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if(map->map[i][j] != '1' || map->map[i][j] != '0' || map->map[i][j] != 'P' 
			|| map->map[i][j] != 'C' || map->map[i][j] != 'E')
				return (error_message(6));
			++j;
		}
		++i;
	}
	return (0);
}
