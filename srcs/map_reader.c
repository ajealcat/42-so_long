/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:14:13 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/06 22:58:15 by ajearuth         ###   ########.fr       */
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
	if (i == 6)
		ft_putstr_fd("Error\n Invalid instructions", 2);
	return (-1);
}

t_map	init_struct_map(void)
{
	t_map map;

	map.width = 0;
	map.lengh = 0;
	map.map = NULL;
	return (map);
}

int	read_map(t_map map)
{
	int fd;
	char *line;
	int ret;
	int i;

	fd = open("littlemap.ber", O_RDONLY);
	ret = 1;
	i = 0;
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			map.map[i] = line;
		if (map.width == 0)
			map.width = ft_strlen(line);
		}
		free(line);
		++i;
	}
	map.map[i] = NULL;
	map.lengh = i;
	close(fd);
	return(0);
}

