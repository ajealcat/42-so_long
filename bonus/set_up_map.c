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
	image->wall = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/Wall.xpm", &data.x, &data.y);
	image->grass = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/Grass.xpm", &data.x, &data.y);
	image->door = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/Door.xpm", &data.x, &data.y);
	image->cherry = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/Cherries.xpm", &data.x, &data.y);
	image->perso = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/Perso.xpm", &data.x, &data.y);
	image->counter = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/WallWalker.xpm", &data.x, &data.y);
	image->perso_gauche = mlx_xpm_file_to_image(data.mlx_ptr, \
	"textures/Perso_gauche.xpm", &data.x, &data.y);
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
				data.window_ptr, image.wall, j * 48, i * 48);
			}
			else 
			{
				mlx_put_image_to_window(data.mlx_ptr, \
				data.window_ptr, image.grass, j * 48, i * 48);
				if (map.mappy[i][j] == 'E')
				{
					mlx_put_image_to_window(data.mlx_ptr, \
					data.window_ptr, image.door, j * 48, i * 48);
				}
				if (map.mappy[i][j] == 'C')
				{
					mlx_put_image_to_window(data.mlx_ptr, \
					data.window_ptr, image.cherry, j * 48, i * 48);
				}
				if (map.mappy[i][j] == 'P')
				{
					mlx_put_image_to_window(data.mlx_ptr, \
					data.window_ptr, image.perso, j * 48, i * 48);
				}
			}
			++j;
		}
		++i;
	}
}



