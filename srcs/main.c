/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:39:49 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/11 13:09:38 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_data data;
	t_map	map;
	
	if (ac == 2)
	{
		if (open_fd(av[1]) == -1)
			return (-1);
		map = init_struct_map(av[1]);
		global_checker(&map);
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			return (1);
		data.window_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGH, "my first window");
		if (data.window_ptr == NULL)
		{
			free(data.window_ptr);
			return (1);
		}
		mlx_destroy_window(data.mlx_ptr, data.window_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (0);
	}
	return(error_message(6));
}
