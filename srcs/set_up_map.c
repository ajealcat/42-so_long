/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:22:29 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/15 15:22:29 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image(t_image *image, t_data data)
{
	image->wall_up = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/Wall.xpm", &data.x, &data.y);
	image->wall_down = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/TX-down-Wall.xpm", &data.x, &data.y);
	image->wall_side = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/TX-Side-Wall.xpm", &data.x, &data.y);
	image->grass = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/Grass.xpm", &data.x, &data.y);
	image->door = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/TX-.xpm", &data.x, &data.y);
}

void	put_on_screen(t_data data, t_map map, t_image image)
{
	int i;
	int j;

	i = 0;
	while(map.mappy[i])
	{
		j = 0;
		while(map.mappy[i][j])
		{
			if (map.mappy[i][j] == '1')
			{
				mlx_put_image_to_window(data.mlx_ptr, \
				data.window_ptr, image.wall_up, j * 48, i * 48);
			}
			else 
			{
				mlx_put_image_to_window(data.mlx_ptr, \
				data.window_ptr, image.grass, j * 48, i * 48);
			}
			++j;
		}
		++i;
	}
}
