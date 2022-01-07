/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:39:49 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/07 16:10:08 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_data data;
	
	if (ac == 2)
	{
		if (read_map(init_struct_map(), av[1]) != 0)
			return (-1);
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
