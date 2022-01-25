/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:29:21 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/20 17:34:02 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypressed(int key, t_data *data)
{
	if (key == XK_Escape)
		destroy_and_quit(data);
	else if (ft_strchr("wasd", key))
		moove_player(data, key);
	return (0);
}

int	is_moove_possible(t_map *map, int instruction)
{
	if (instruction == XK_a)
		if (map->mappy[map->player_pos_y][map->player_pos_x - 1] == '1')
			return (-1);
	if (instruction == XK_d)
		if (map->mappy[map->player_pos_y][map->player_pos_x + 1] == '1')
			return (-1);
	if (instruction == XK_s)
		if (map->mappy[map->player_pos_y + 1][map->player_pos_x] == '1')
			return (-1);
	if (instruction == XK_w)
		if (map->mappy[map->player_pos_y - 1][map->player_pos_x] == '1')
			return (-1);
	return (0);
}

int	next_moove_collectible(t_map *map, int instruction)
{
	if (instruction == XK_a)
		if (map->mappy[map->player_pos_y][map->player_pos_x - 1] == 'C')
			map->collectibles_nbr--;
	if (instruction == XK_d)
		if (map->mappy[map->player_pos_y][map->player_pos_x + 1] == 'C')
			map->collectibles_nbr--;
	if (instruction == XK_s)
		if (map->mappy[map->player_pos_y + 1][map->player_pos_x] == 'C')
			map->collectibles_nbr--;
	if (instruction == XK_w)
		if (map->mappy[map->player_pos_y - 1][map->player_pos_x] == 'C')
			map->collectibles_nbr--;
	return (0);
}

int	next_moove_is_door(t_map *map, int instruction)
{
	if (instruction == XK_a)
		if (map->mappy[map->player_pos_y][map->player_pos_x - 1] == 'E')
			return (42);
	if (instruction == XK_d)
		if (map->mappy[map->player_pos_y][map->player_pos_x + 1] == 'E')
			return (42);
	if (instruction == XK_s)
		if (map->mappy[map->player_pos_y + 1][map->player_pos_x] == 'E')
			return (42);
	if (instruction == XK_w)
		if (map->mappy[map->player_pos_y - 1][map->player_pos_x] == 'E')
			return (42);
	return (0);
}

int	moove_player(t_data *data, int key)
{
	if (is_moove_possible(data->map, key) == -1)
		return (-1);
	if (next_moove_is_door(data->map, key) == 42)
	{
		if (data->map->collectibles_nbr != 0)
			return (-1);
		else
			destroy_and_quit(data);
	}
	next_moove_collectible(data->map, key);
	data->map->mappy[data->map->player_pos_y][data->map->player_pos_x] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->image->grass, \
	data->map->player_pos_x * 48, data->map->player_pos_y * 48);
	if (key == 'a')
		data->map->player_pos_x--;
	else if (key == 'd')
		data->map->player_pos_x++;
	else if (key == 'w')
		data->map->player_pos_y--;
	else if (key == 's')
		data->map->player_pos_y++;
	data->map->mappy[data->map->player_pos_y][data->map->player_pos_x] = 'P';
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->image->perso, \
	data->map->player_pos_x * 48, data->map->player_pos_y * 48);
	++data->map->count;
	printf("Player movements : %d\n", data->map->count);
	return (0);
}

