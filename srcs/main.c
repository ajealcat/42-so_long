/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:39:49 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/16 22:21:52 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_data data;
	t_map	map;
	t_image image;
	int i;
	
	i = 0;
	if (ac == 2)
	{
		if (open_fd(av[1]) == -1)
			return (-1);
		map = init_struct_map(av[1]);
		if (global_checker(map) == -1)
			return (-1);
		data.win_height = map.lengh * 48;
		data.win_width = map.width * 48;
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			return (1);
		data.window_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_height, "my first window");
		if (data.window_ptr == NULL)
		{
			free(data.window_ptr);
			return (1);
		}
		get_image(&image, data);
		put_on_screen(data, map, image);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_window(data.mlx_ptr, data.window_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (0);
	}
	return (error_message(6));
}
