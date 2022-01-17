/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:40:02 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/17 17:05:13 by ajearuth         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	int		win_height;
	int		win_width;
	int		x;
	int		y;
}	t_data;

typedef struct s_map
{
	int lengh;
	int width;
	char **mappy;
}	t_map;

typedef struct s_image
{
	void *wall_up;
	void *wall_side;
	void *wall_down;
	void *grass;
	void *door;
	void *cherry;
	void *perso;
}	t_image;

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
void	get_image(t_image *image, t_data data);
void	put_on_screen(t_data data, t_map map, t_image image);

#endif
