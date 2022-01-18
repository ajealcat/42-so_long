/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:07:02 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/11 12:07:02 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_struct_map(char *file)
{
	t_map map;

	map.width = 0;
	map.lengh = 0;
	get_param(&map, file);
	init_mapmap(&map, file);
	get_player_pos(&map);
	return (map);
}

int	open_fd(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_message(7));
	close(fd);
	return (0);
}

int	get_param(t_map *map, char *file)
{
	char *line;
	int i;
	int ret;
	int fd;

	ret = 1;
	i = 0;
	fd = open(file, O_RDONLY);
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			if (map->width == 0)
				map->width = ft_strlen(line);
		}
		++i;
		free(line);
	}
	map->lengh = i - 1;
	close(fd);
	return (0);
}

void	get_player_pos(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->mappy[i])
	{
		j = 0;
		while (map->mappy[i][j])
		{
			if (map->mappy[i][j] == 'P')
			{
				map->player_pos_x = j;
				map->player_pos_y = i;
			}
			++j;
		}
		++i;
	}	
}

int init_mapmap(t_map *map, char *file)
{
	int fd;
	int ret;
	int i;
	char *line;

	i = 0;
	fd = open(file, O_RDONLY);
	map->mappy = malloc(sizeof(char*) * map->lengh + 1);
	if (map->mappy == NULL)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		if (ret == 1)	
		{
			map->mappy[i] = ft_strdup(line);
		}
		free(line);
		++i;
	}
	map->mappy[i] = NULL;
	close(fd);
	return (0);
}
