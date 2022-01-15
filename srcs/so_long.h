/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:40:02 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/15 20:11:12 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include "get_next_line.h"

# define WINDOW_HEIGH 1800
# define WINDOW_WIDTH 1920

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*image_ptr;
	int		x;
	int		y;
}	t_data;

typedef struct s_map
{
	int lengh;
	int width;
	char **mappy;
}	t_map;

int	error_message(int i);
int	check_size(t_map map);
int	check_walls(t_map map);
int	check_p(t_map map);
int	check_c(t_map map);
int	check_e(t_map map);
int	is_available_entry(t_map map);
int	global_checker(t_map map);
int	open_fd(char *file);
int	get_param(t_map *map, char *file);
int init_mapmap(t_map *map, char *file);
t_map	init_struct_map(char *file);

#endif
