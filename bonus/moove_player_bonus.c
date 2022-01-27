/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:29:21 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/27 14:44:24 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	char	*steps;

	if (check_moove(data, key) == -1)
		return (-1);
	next_moove_collectible(data->map, key);
	moove_left(data, key);
	moove_right(data, key);
	moove_up(data, key);
	moove_down(data, key);
	++data->map->count;
	mlx_put_image_to_window(data->mlx_ptr,
		data->window_ptr, data->image->wallwalker, 0, 0);
	steps = ft_itoa(data->map->count);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 35, 35, 0xffffff, steps);
	free(steps);
	printf("Player movements : %d\n", data->map->count);
	put_ghost(data);
	return (0);
}
