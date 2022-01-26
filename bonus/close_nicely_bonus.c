/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_nicely_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:29:04 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/26 15:28:24 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	free_mappy(t_map *map)
{
	int	i;

	i = 0;
	while (map->mappy[i])
	{
		free(map->mappy[i]);
		++i;
	}
	if (map->mappy)
		free(map->mappy);
	return (-1);
}

int	destroy_and_quit(t_data *data)
{
	destroy_image(data);
	if (data->window_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		data->window_ptr = NULL;
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_mappy(data->map);
	exit(0);
}

void	destroy_image(t_data *data)
{
	if (data->image->wall)
		mlx_destroy_image(data->mlx_ptr, data->image->wall);
	if (data->image->door)
		mlx_destroy_image(data->mlx_ptr, data->image->door);
	if (data->image->cherry)
		mlx_destroy_image(data->mlx_ptr, data->image->cherry);
	if (data->image->grass)
		mlx_destroy_image(data->mlx_ptr, data->image->grass);
	if (data->image->perso)
		mlx_destroy_image(data->mlx_ptr, data->image->perso);
	if (data->image->wallwalker)
		mlx_destroy_image(data->mlx_ptr, data->image->wallwalker);
	if (data->image->perso_gauche)
		mlx_destroy_image(data->mlx_ptr, data->image->perso_gauche);
	if (data->image->ghost)
		mlx_destroy_image(data->mlx_ptr, data->image->ghost);
	if (data->image->slime1)
		mlx_destroy_image(data->mlx_ptr, data->image->slime1);
	if (data->image->slime2)
		mlx_destroy_image(data->mlx_ptr, data->image->slime2);
}

int	red_cross(t_data *data)
{
	destroy_and_quit(data);
	return (-1);
}
