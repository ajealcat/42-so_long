#include "so_long.h"

int	keypressed(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		data->window_ptr = NULL;
		return (-1);
	}
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
	if (data->map->collectibles_nbr == 0)
		if (next_moove_is_door(data->map, key) == 42)
		{
			mlx_destroy_window(data->mlx_ptr, data->window_ptr);
			data->window_ptr = NULL;
			return (-1);
		}
	return (0);
}

