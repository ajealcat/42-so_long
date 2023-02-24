#include "so_long_bonus.h"

void	image_error_message(t_data *data)
{
	ft_putstr_fd("\e[0;31mError\nImage file corrupted\n", 2);
	destroy_and_quit(data);
}

void	get_image(t_image *image, t_data *data)
{
	image->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Wall.xpm", &data->x, &data->y);
	image->grass = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Grass.xpm", &data->x, &data->y);
	image->door = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Door.xpm", &data->x, &data->y);
	image->cherry = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Cherries.xpm", &data->x, &data->y);
	image->perso = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Perso.xpm", &data->x, &data->y);
	image->wallwalker = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/WallWalker.xpm", &data->x, &data->y);
	image->perso_gauche = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Perso_gauche.xpm", &data->x, &data->y);
	image->slime1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Slime1.xpm", &data->x, &data->y);
	image->slime2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Slime2.xpm", &data->x, &data->y);
	image->ghost = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Ghost.xpm", &data->x, &data->y);
	secure_image(data, image);
}

void	secure_image(t_data *data, t_image *image)
{
	if (image->wall == NULL)
		image_error_message(data);
	if (image->grass == NULL)
		image_error_message(data);
	if (image->door == NULL)
		image_error_message(data);
	if (image->cherry == NULL)
		image_error_message(data);
	if (image->perso == NULL)
		image_error_message(data);
	if (image->wallwalker == NULL)
		image_error_message(data);
	if (image->perso_gauche == NULL)
		image_error_message(data);
	if (image->ghost == NULL)
		image_error_message(data);
	if (image->slime1 == NULL)
		image_error_message(data);
	if (image->slime2 == NULL)
		image_error_message(data);
}

void	put_on_screen(t_data *data, t_map *map, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (map->mappy[i])
	{
		j = 0;
		while (map->mappy[i][j])
		{
			if (map->mappy[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, \
				data->window_ptr, image->wall, j * 48, i * 48);
			}
			else
				put_ecp(data, image, i, j);
			++j;
		}
		++i;
	}
}

void	put_ecp(t_data *data, t_image *image, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, \
	data->window_ptr, image->grass, j * 48, i * 48);
	if (data->map->mappy[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, \
		data->window_ptr, image->door, j * 48, i * 48);
	}
	if (data->map->mappy[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, \
		data->window_ptr, image->cherry, j * 48, i * 48);
	}
	if (data->map->mappy[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, \
		data->window_ptr, image->perso, j * 48, i * 48);
	}
	if (data->map->mappy[i][j] == 'S')
	{
		mlx_put_image_to_window(data->mlx_ptr, \
		data->window_ptr, data->image->slime1, j * 48, i * 48);
	}
}
