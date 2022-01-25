/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_nicely.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:29:04 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/20 17:28:37 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	free_mappy(t_map *map)
{
	int i;

	i = 0;
	while(map->mappy[i])
	{
		free(map->mappy[i]);
		++i;
	}
	free(map->mappy);
	return (-1);
}

int	destroy_and_quit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->window_ptr = NULL;
	free(data->mlx_ptr);
	if(data->map)
		free_mappy(data->map);
	exit(0);
	return (-1);
}

int	red_cross(t_data *data)
{
	destroy_and_quit(data);
	return (-1);
}
