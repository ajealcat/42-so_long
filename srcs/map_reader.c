/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:14:13 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/10 15:07:49 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_map	init_struct_map(char *file)
{
	t_map map;
	int fd;
	char *line;
	int i;
	int ret; 

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return(error_message(7));
	while (ret > 0)
	{
		
	}
	map.width = 0;
	map.lengh = 0;
	map.map = NULL;
	return (map);
}

int	read_map(t_map map, char *file)
{
	int fd;
	char *line;
	int ret;
	int i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return(error_message(7));
	ret = 1;
	i = 0;
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			map.map[i] = ft_strdup(line);
			if (map.width == 0)
				map.width = ft_strlen(line);
		}
		free(line);
		++i;
	}
	map.map[i] = NULL;
	map.lengh = i;
	close(fd);
	return (global_checker(map));
}

int	global_checker(t_map map)
{
	if (check_size(map) != 0)
		return (-1);
	if (check_walls(map) != 0)
		return (-1);
	if (is_available_entry(map) != 0)
		return (-1);
	if (check_p(map) != 0)
		return (-1);
	if (check_c(map) != 0)
		return (-1);
	if (check_e(map) != 0)
		return (-1);
	return (0);
}
