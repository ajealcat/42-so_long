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

void	is_moove_possible(t_map *map, char instruction)
{
	if (instruction == 'a')
		if (map->player_pos_x - 1 == '1')
			return (-1);
	if (instruction == 'd')
		if (map->player_pos_x + 1 == '1')
			return (-1);
	if (instruction == 'w')
		if (map->player_pos_y + 1 == '1')
			return (-1);
	if (instruction == 's')
		if (map->player_pos_y - 1 == '1')
			return (-1);
}

void	moove_player(t_data data, t_map map, int key)
{
	
}
