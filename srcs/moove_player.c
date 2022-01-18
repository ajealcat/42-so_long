#include "so_long.h"

void	keypresed(t_data data, int key)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		data->window_ptr = NULL;
	}
	else if (ft_strchr("wasd", key)
		moove_player(data, key);
}

int	is_moove_possible(t_map *map, char instruction)
{
	if (instruction == 'a')
		if (map->mappy[map->player_pos_y][map->player_pos_x - 1] == '1')
			return (-1);
	if (instruction == 'd')
		if (map->mappy[map->player_pos_y][map->player_pos_x + 1] == '1')
			return (-1);
	if (instruction == 'w')
		if (map->mappy[map->player_pos_y + 1][map->player_pos_x] == '1')
			return (-1);
	if (instruction == 's')
		if (map->mappy[map->player_pos_y - 1][map->player_pos_x] == '1')
			return (-1);
	return (0);
}

void	moove_player(t_data data, int key)
{
	if (is_moove_possible(&data.map, key) == 0)
	{
		
	}	
}
