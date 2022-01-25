/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:40:02 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/24 19:01:14 by ajearuth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include "get_next_line.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>

typedef struct s_image
{
	void *wall;
	void *grass;
	void *door;
	void *cherry;
	void *perso;
	void *counter;
	void *perso_gauche;
}	t_image;

typedef struct s_map
{
	int lengh;
	int width;
	int player_pos_x;
	int player_pos_y;
	int collectibles_nbr;
	int count;
	char **mappy;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	int		win_height;
	int		win_width;
	int		x;
	int		y;
	t_map	*map;
	t_image	*image;
}	t_data;

int	error_message(int i);
int	check_size(t_map map);
int	check_walls(t_map map);
int	check_p(t_map map);
int	check_c(t_map *map);
int	check_e(t_map map);
int	is_available_entry(t_map map);
int	global_checker(t_map map);
int	open_fd(char *file);
int	get_param(t_map *map, char *file);
int init_mapmap(t_map *map, char *file);
t_map	init_struct_map(char *file);
void	get_image(t_image *image, t_data data);
void	put_on_screen(t_data data, t_map map, t_image image);
void	put_ecp(t_data data, t_image image, int i, int j);
int	keypressed(int key, t_data *data);
void	get_player_pos(t_map *map);
int	is_moove_possible(t_map *map, int instruction);
int	moove_player(t_data *data, int key);
int	next_moove_collectible(t_map *map, int instruction);
int	next_moove_is_door(t_map *map, int instruction);
int	free_mappy(t_map *map);
int	destroy_and_quit(t_data *data);
int	red_cross(t_data *data);


#endif
