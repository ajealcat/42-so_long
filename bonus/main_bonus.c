/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:39:49 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/27 15:01:53 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_image	init_image(t_image *image)
{
	image->wall = NULL;
	image->grass = NULL;
	image->door = NULL;
	image->cherry = NULL;
	image->perso = NULL;
	image->wallwalker = NULL;
	image->perso_gauche = NULL;
	image->ghost = NULL;
	image->slime1 = NULL;
	image->slime2 = NULL;
	return (*image);
}

static t_data	init_data(t_data *data, t_map *map, t_image *image)
{
	data->win_height = map->lengh * 48;
	data->win_width = map->width * 48;
	data->window_ptr = NULL;
	data->mlx_ptr = NULL;
	data->mlx_ptr = mlx_init();
	data->map = map;
	data->image = image;
	get_image(image, data);
	data->window_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "so_long");
	return (*data);
}

static int	security_first(t_data *data)
{		
	if (data->mlx_ptr == NULL)
		return (1);
	if (global_checker(data->map) == -1)
	{
		printf("OK2\n");
		destroy_and_quit(data);
		return (-1);
	}
	if (data->window_ptr == NULL)
	{
		destroy_and_quit(data);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;
	t_image	image;
	int		i;

	i = 0;
	if (ac == 2)
	{
		if (open_fd(av[1]) == -1)
			return (-1);
		image = init_image(&image);
		map = init_struct_map(av[1]);
		data = init_data(&data, &map, &image);
		security_first(&data);
		put_on_screen(&data, &map, &image);
		mlx_key_hook(data.window_ptr, &keypressed, &data);
		mlx_hook(data.window_ptr, DestroyNotify,
			StructureNotifyMask, &red_cross, &data);
		mlx_loop_hook(data.mlx_ptr, &s_sprite, &data);
		mlx_loop(data.mlx_ptr);
		free_mappy(&map);
		return (0);
	}
	return (error_message(6));
}
