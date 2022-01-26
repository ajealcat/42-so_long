/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_slime_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:02:55 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/26 19:50:52 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		map->slime = count;
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
		ft_putstr_fd("\e[0;31mYou loose\n", 2);
		destroy_and_quit(data);
	}
}
