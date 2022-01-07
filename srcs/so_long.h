/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:40:02 by ajearuth          #+#    #+#             */
/*   Updated: 2022/01/07 13:25:03 by ajearuth         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
}	t_data;

typedef struct s_map
{
	int lengh;
	int width;
	char **map;
}	t_map;

int	read_map(t_map map);
int	error_message(int i);
int	check_size(t_map map);
int	check_walls(char *line, t_map map);
int	check_p(t_map map);
int	check_c(t_map map);
int	check_e(t_map map);
int	is_available_entry(t_map map);
int	global_checker(t_map map);

#endif
