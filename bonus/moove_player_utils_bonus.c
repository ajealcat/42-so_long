#include "so_long_bonus.h"

int	check_moove(t_data *data, int key)
{
	if (is_moove_possible(data->map, key) == -1)
		return (-1);
	if (next_moove_slime(data->map, key) == 666)
		return (-1);
	if (next_moove_is_door(data->map, key) == 42)
	{
		if (data->map->collectibles_nbr != 0)
		{
			ft_putstr_fd("\e[0;35mPlease collect all the cherries !\n\e[0;37m", 2);
			return (-1);
		}
		else
		{
			ft_putstr_fd("\e[0;32mYaaaaay ! You win !\n", 1);
			destroy_and_quit(data);
		}
	}
	return (0);
}

int	moove_left(t_data *data, int key)
{
	t_map	*tmp;

	tmp = data->map;
	if (key == 'a')
	{
		tmp->mappy[tmp->player_pos_y][tmp->player_pos_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image->grass, tmp->player_pos_x * 48, tmp->player_pos_y * 48);
		tmp->player_pos_x--;
		tmp->mappy[tmp->player_pos_y][tmp->player_pos_x] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image->perso_gauche, tmp->player_pos_x * 48,
			tmp->player_pos_y * 48);
		return (1);
	}
	return (0);
}

int	moove_right(t_data *data, int key)
{
	t_map	*tmp;

	tmp = data->map;
	if (key == 'd')
	{
		tmp->mappy[tmp->player_pos_y][tmp->player_pos_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image->grass, tmp->player_pos_x * 48, tmp->player_pos_y * 48);
		tmp->player_pos_x++;
		tmp->mappy[tmp->player_pos_y][tmp->player_pos_x] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image->perso, tmp->player_pos_x * 48, tmp->player_pos_y * 48);
		return (1);
	}
	return (0);
}

int	moove_up(t_data *data, int key)
{
	t_map	*tmp;

	tmp = data->map;
	if (key == 'w')
	{
		tmp->mappy[tmp->player_pos_y][tmp->player_pos_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image->grass, tmp->player_pos_x * 48, tmp->player_pos_y * 48);
		tmp->player_pos_y--;
		tmp->mappy[tmp->player_pos_y][tmp->player_pos_x] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image->perso_gauche, tmp->player_pos_x * 48,
			tmp->player_pos_y * 48);
		return (1);
	}
	return (0);
}

int	moove_down(t_data *data, int key)
{
	t_map	*tmp;

	tmp = data->map;
	if (key == 's')
	{
		tmp->mappy[tmp->player_pos_y][tmp->player_pos_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image->grass, tmp->player_pos_x * 48, tmp->player_pos_y * 48);
		tmp->player_pos_y++;
		tmp->mappy[tmp->player_pos_y][tmp->player_pos_x] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image->perso, tmp->player_pos_x * 48, tmp->player_pos_y * 48);
		return (1);
	}
	return (0);
}
