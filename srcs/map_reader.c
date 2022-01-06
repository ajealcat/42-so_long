/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:14:13 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/06 12:36:42 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		map.map[i] = line;
		if (map.width == 0)
			map.width = ft_strlen(line);
		free(line);
		++i;
	}
	map.lengh = i;
	close(fd);
	return(0);
}

