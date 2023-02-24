#include "so_long_bonus.h"

int	check_s(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->mappy[i])
	{
		j = 0;
		while (map->mappy[i][j])
		{
			if (map->mappy[i][j] == 'S')
				++count;
			++j;
		}
		++i;
	}
	map->slime = count;
	if (map->slime > 0 && map->slime % 2 == 0)
	{
		ft_putstr_fd("\e[0;31mEnemies patrol in odd numbers\n\e[0;37m", 2);
		free_mappy(map);
		exit(0);
	}
	return (0);
}

int	next_moove_slime(t_map *map, int instruction)
{
	if (instruction == XK_a)
		if (map->mappy[map->player_pos_y][map->player_pos_x - 1] == 'S')
			return (666);
	if (instruction == XK_d)
		if (map->mappy[map->player_pos_y][map->player_pos_x + 1] == 'S')
			return (666);
	if (instruction == XK_s)
		if (map->mappy[map->player_pos_y + 1][map->player_pos_x] == 'S')
			return (666);
	if (instruction == XK_w)
		if (map->mappy[map->player_pos_y - 1][map->player_pos_x] == 'S')
			return (666);
	return (0);
}

int	touch_slime(t_map *map)
{
	if (map->mappy[map->player_pos_y][map->player_pos_x - 1] == 'S')
		return (666);
	if (map->mappy[map->player_pos_y][map->player_pos_x + 1] == 'S')
		return (666);
	if (map->mappy[map->player_pos_y + 1][map->player_pos_x] == 'S')
		return (666);
	if (map->mappy[map->player_pos_y - 1][map->player_pos_x] == 'S')
		return (666);
	return (0);
}

void	put_ghost(t_data *data)
{
	int		i;

	i = 0;
	if (touch_slime(data->map) == 666)
	{
		while (i++ < 25000)
			mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
				data->image->ghost, data->map->player_pos_x * 48,
				data->map->player_pos_y * 48);
		ft_putstr_fd("\e[0;31mBouuuuh ! You loose !\n", 2);
		destroy_and_quit(data);
	}
}

int	s_sprite(t_data *data)
{
	int				i;
	int				j;

	i = 0;
	usleep(150000);
	while (data->map->mappy[i])
	{
		j = 0;
		while (data->map->mappy[i][j])
		{
			if (data->map->mappy[i][j] == 'S')
				mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
					moove_s(data), j * 48, i * 48);
			++j;
		}
		++i;
	}
	return (0);
}
