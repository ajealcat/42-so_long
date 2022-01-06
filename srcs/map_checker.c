/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:15:04 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/06 18:15:48 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	error_message(int i)
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
	return (-1);
}

int	check_size(t_map map)
{
	int i;

	i = 0;
	while(map.map[i])
	{
		if(ft_strlen(map.map[i]) != map.width)
			return (error_message(5));
		++i;
	}	
	if (i != map.lengh)
		return (error_message(5));
	return (0);
}

int	check_walls(char *line, t_map map)
{
	int i;
	
	i = 0;
	while (i < map.width)
	{
		if(map.map[0][i] != '1') 
			return (error_message(1));
		if (map.map[map.lengh][i] != '1')
			return (error_message(1));
		++i;
	}
	i = 0;
	while (i < map.lengh)
	{
		if (map.map[i][0] != '1')
			return(error_message(1));
		if (map.map[i][map.width] != '1')
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
	while (map.map[i])
	{
		j = 0;
		while(map.map[i][j])
		{
			if (map.map[i][j] == 'P')
				++count;
			++j;
		}
		++i;
	}
	if (count != 1)
		return(error_message(4));
	return(0);
}

int	check_c(t_map map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map.map[i])
	{
		j = 0;
		while(map.map[i][j])
		{
			if (map.map[i][j] == 'C')
				++count;
			++j;
		}
		++i;
	}
	if (count < 1)
		return(error_message(3));
	return(0);
}

int	check_e(t_map map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map.map[i])
	{
		j = 0;
		while(map.map[i][j])
		{
			if (map.map[i][j] == 'E')
				++count;
			++j;
		}
		++i;
	}
	if (count < 1)
		return(error_message(2));
	return(0);
}
